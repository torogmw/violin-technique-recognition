//
//  ViolinClassification.cpp
//  PitchTail_1
//
//  Created by annie zhang on 11/15/13.
//
//

#include "ViolinClassification.h"

ViolinClassification::ViolinClassification()
{
    numblocks = floor((float)(SAMPLESIZE-env_blockSize)*1.0/env_hopSize);
    numdownSamples = ceil((float)SAMPLESIZE*FS/F);
    resampleddata = new float[numdownSamples];
    cf = new ChromaFeat(blockSize);
    chromahist = new float[NUMCHROMAGRAM];
    memset(chromahist, 0, NUMCHROMAGRAM*sizeof(float));
    
    shift1.push_back(0.6488);
    shift1.push_back(-17.0798);
    scalefactor1.push_back(0.4923);
    scalefactor1.push_back(0.0356);
    
    shift2.push_back(-0.1057);
    shift2.push_back(1.6045);
    shift2.push_back(-37.4127);
    shift2.push_back(-0.1128);
    scalefactor2.push_back(29.6910);
    scalefactor2.push_back(0.3434);
    scalefactor2.push_back(0.0278);
    scalefactor2.push_back(20.0546);
    
    shift3.push_back(-0.1662);
    shift3.push_back(-192.0167);
    scalefactor3.push_back(20.3897);
    scalefactor3.push_back(0.0055);
    
    ifstream infile;
    infile.open("sv1.txt");
    string line;
    while(std::getline(infile, line)) {
        stringstream s(line);
        float d1;                                   // skewness
        float d2;                                   // kurtosis
        float d3;
        if(s >> d1 >> d2 >> d3) {
            vector<float> row;
            row.push_back(d1);
            row.push_back(d2);
            sv1.push_back(row);
            alpha1.push_back(d3);
        }
    }
    infile.close();
    
    infile.open("sv2.txt");
    while(std::getline(infile, line)) {
        stringstream s(line);
        float d1;                                   // std
        float d2;                                   // skewness
        float d3;                                   // kurtosis
        float d4;                                   // envelope
        float d5;                                   
        if(s >> d1 >> d2 >> d3 >> d4 >> d5) {
            vector<float> row;
            row.push_back(d1);
            row.push_back(d2);
            row.push_back(d3);
            row.push_back(d4);
            sv2.push_back(row);
            alpha2.push_back(d5);
        }
    }
    infile.close();

    infile.open("sv3.txt");
    while(std::getline(infile, line)) {
        stringstream s(line);
        float d1;                                   // envelope mean
        float d2;                                   // special feature
        float d3;                                   
        if(s >> d1 >> d2 >> d3) {
            vector<float> row;
            row.push_back(d1);
            row.push_back(d2);
            sv3.push_back(row);
            alpha3.push_back(d3);
        }
    }
    infile.close();
    
}

ViolinClassification::~ViolinClassification()
{
    delete cf;
    delete resampleddata;
    delete chromahist;
}
        

void ViolinClassification::getReady(float* gWavDataIn)
{    
    inputData.clear();
    for (int i=0; i<SAMPLESIZE; i++)
        inputData.push_back(gWavDataIn[i]);
    
    if (valid()){
        normalize(inputData);
        chroma();
        getFeatures();
        doClassify();
    }
    else
        classLabel = " ";    
}


bool ViolinClassification::valid()
{
    float sum = getSum(inputData);
    float mean = sum / inputData.size();
    
    float sq_sum = 0;
    for (int i=0; i<inputData.size(); i++)
        sq_sum += (inputData[i] - mean)*(inputData[i] - mean);
    float var = 1000*sq_sum / (inputData.size()-1);
    if (var > threshold)
        return true;
    return false;
}


void ViolinClassification::doClassify()
{
    if (toggleState.size()==1){
        if (toggleState[0] == 0)
            svmClassifyPizz();
        else if (toggleState[0] == 1)
            svmClassifyStaccato();
        else if (toggleState[0] == 2)
            svmClassifyTremolo();
        else if (toggleState[0] == 3)
            svmClassifyTrill();
        else if (toggleState[0] == 4)
            svmClassifyVibrato();
    }
    else if (toggleState.size() > 1){
        svmClassifyAll();
    }
}


void ViolinClassification::normalize(vector<float> &data)
{
    float maximum = absmax(data, 0, SAMPLESIZE);
    for (int i=0; i<SAMPLESIZE; i++){
        data[i] /= maximum;
        data[i] *= 0.99;
    }
}


void ViolinClassification::normalize(float* v, int size)
{
    float sum = 0;
    for (int i=0; i<size; i++)
        sum += v[i]*v[i];
    sum = pow(sum, float(0.5));
    for (int i=0; i<size; i++)
        v[i] /= sum;
}


void ViolinClassification::getFeatures()
{
    featurelist.clear();
    timeDomainFeat();
    envelope();
}


void ViolinClassification::timeDomainFeat()
{
    float sum = getSum(inputData);
    float mean = sum / inputData.size();
    
    float sq_sum = 0;
    for (int i=0; i<inputData.size(); i++)
        sq_sum += (inputData[i] - mean)*(inputData[i] - mean);
    float stdev = sqrt(sq_sum / (inputData.size()-1));
    
    float skewness = 0;
    for (int i = 0; i < SAMPLESIZE; i++)
        skewness += (inputData[i] - mean)*(inputData[i] - mean)*(inputData[i] - mean);
    skewness = skewness/(SAMPLESIZE * stdev * stdev * stdev);
    
    float kurtosis = 0;
    for (int i = 0; i < SAMPLESIZE; i++)
        kurtosis += (inputData[i] - mean)*(inputData[i] - mean)*(inputData[i] - mean)*(inputData[i] - mean);
    kurtosis = kurtosis/(SAMPLESIZE*stdev*stdev*stdev*stdev);
    
    featurelist.push_back(stdev);
    featurelist.push_back(skewness);
    featurelist.push_back(kurtosis);
}


float ViolinClassification::getSum(vector<float> &v)
{
    float sum = 0;
    for (int i=0; i<v.size(); i++)
        sum += v[i];
    return sum;
}


float ViolinClassification::inProduct(vector<float> &v1, vector<float> &v2)
{
    float innerp = 0;
    for (int i=0; i<v1.size(); i++)
        innerp += v1[i]*v2[i];
    return innerp;
}


void ViolinClassification::envelope()
{
    env.clear();
    for (int i=0; i<numblocks; i++)
        env.push_back(max(inputData, i*env_hopSize, i*env_hopSize+env_blockSize));
    
    float env_mean = getSum(env) / numblocks;
    float sq_sum = 0;
    for (int i=0; i<env.size(); i++)
        sq_sum += (env[i] - env_mean)*(env[i] - env_mean);
    float env_std = sqrt(sq_sum / (numblocks-1));
    
    int lastIdx = 0;
    for (int i=env.size()-1; i>=0; i--){
        if (env[i] < 0.2){
            lastIdx = i;
            break;
        }
    }
    featurelist.push_back(env_mean);
    featurelist.push_back(env_std);
    featurelist.push_back(lastIdx*1.0);
}


void ViolinClassification::smooth(vector<int> &c)
{
    for (int i=1; i<c.size()-1; i++)
        if(c[i-1] == c[i+1])
            c[i] = c[i-1];
}

void ViolinClassification::chroma()
{
    resample(inputData, resampleddata, F, FS, SAMPLESIZE);
    for (int i=0; i<NUMCHROMAGRAM; i++)
        chromaFreq.push_back(0);
    int numChunks = floor((float)(numdownSamples-blockSize)*1.0/hopSize);
    targetEnergyPeaks.clear();
    for (int i=0; i<numChunks; i++){
        memset(cf->chromagram, 0, NUMCHROMAGRAM*sizeof(float));
        cf->Chroma(&resampleddata[i*hopSize]);
        for (int j=0; j<NUMCHROMAGRAM; j++)
            chromahist[j] = cf->chromagram[j];
        normalize(chromahist, NUMCHROMAGRAM);
        int peakBin = maxIdx(chromahist, NUMCHROMAGRAM);;
        chromaFreq[peakBin] += 1;
        targetEnergyPeaks.push_back(maxIdx(cf->energysum, NUMNOTES));
    }
    smooth(targetEnergyPeaks);
    for (int i=0; i<numChunks; i++)
        pitch = targetEnergyPeaks[i]+STARTNOTE;

}


void ViolinClassification::chromaPeakPair(float *data, vector<int> &v)
{
    int first = maxIdx(data, NUMCHROMAGRAM);
    data[first] = 0;
    int second = maxIdx(data, NUMCHROMAGRAM);
    v.push_back(first);
    v.push_back(second);
}

float ViolinClassification::max(vector<float> &v, int start, int end)
{
    if (start < v.size()){
        float max = v[start];
        for (int i=start+1; i<end; i++)
            if (v[i] > max)
                max = v[i];
        return max;
    }
    return 0;
}


float ViolinClassification::absmax(vector<float> &v, int start, int end)
{
    if (start < v.size()){
        float absmax = abs(v[start]);
        for (int i=start+1; i<end; i++)
            if (abs(v[i]) > absmax)
                absmax = abs(v[i]);
        return absmax;
    }
    return 0;
}


int ViolinClassification::maxIdx(float *data, int size)
{
    float max = data[0];
    int idx = 0;
    for (int i=1; i<size; i++){
        if (data[i] > max){
            max = data[i];
            idx = i;
        }
    }
    return idx;
}


int ViolinClassification::maxIdx(vector<int> &data)
{
    float max = data[0];
    int idx = 0;
    for (int i=1; i<data.size(); i++){
        if (data[i] > max){
            max = data[i];
            idx = i;
        }
    }
    return idx;
}

int ViolinClassification::svmfun(vector<vector<float>> &sv, vector<float> &alpha, vector<float> &shift, vector<float> &scalefactor, float bias, vector<float> &feat)
{
    for (int i=0; i<feat.size(); i++)
        feat[i] = (feat[i] + shift[i])*scalefactor[i];
    
    float value = 0;
    for (int i=0; i<sv.size(); i++)
        value += inProduct(sv[i], feat)*alpha[i];
    value += bias;
    if (value >= 0)
        return 1;
    return 2;
}


void ViolinClassification::svmClassifyAll()
{
    featToCompare.clear();
    featToCompare.push_back(featurelist[1]);
    featToCompare.push_back(featurelist[2]);
    int level1res = svmfun(sv1, alpha1, shift1, scalefactor1, bias1, featToCompare);
    int level2res;
    if (level1res == 1){
        level2res = svmfun(sv2, alpha2, shift2, scalefactor2, bias2, featurelist);
        if (level2res == 1){
            if (contain(toggleState, 0))
                classLabel = "pizzicato";
            else
                classLabel = " ";
        }
        else{
            if (contain(toggleState, 1))
                classLabel = "staccato";
            else
                classLabel = " ";
        }
    }
    else{
        featToCompare.clear();
        featToCompare.push_back(featurelist[4]);
        featToCompare.push_back(featurelist[5]);
        level2res = svmfun(sv3, alpha3, shift3, scalefactor3, bias3, featToCompare);
        if (level2res == 1){
            if (contain(toggleState, 2))
                classLabel = "tremolo";
            else
                classLabel = " ";
        }
        else{
            int level3res = chromaCompare();
            if (level3res == 1){
                if (contain(toggleState, 3))
                    classLabel = "trill";
                else
                    classLabel = " ";
            }
            else{
                if (contain(toggleState, 4))
                    classLabel = "vibrato";
                else
                    classLabel = " ";
            }
        }
    }
}


bool ViolinClassification::contain(vector<int> &t, int q)
{
    for (int i=0; i<t.size(); i++)
        if (t[i] == q)
            return true;
    return false;
}

void ViolinClassification::svmClassifyPizz()
{
    featToCompare.clear();
    featToCompare.push_back(featurelist[1]);
    featToCompare.push_back(featurelist[2]);
    int level1res = svmfun(sv1, alpha1, shift1, scalefactor1, bias1, featToCompare);
    if (level1res == 1){
        int level2res = svmfun(sv2, alpha2, shift2, scalefactor2, bias2, featurelist);
        if (level2res == 1)
            classLabel = "pizzicato";
        else
            classLabel = " ";
    }
    else
        classLabel = " ";
}


void ViolinClassification::svmClassifyStaccato()
{
    featToCompare.clear();
    featToCompare.push_back(featurelist[1]);
    featToCompare.push_back(featurelist[2]);
    int level1res = svmfun(sv1, alpha1, shift1, scalefactor1, bias1, featToCompare);
    if (level1res == 1){
        int level2res = svmfun(sv2, alpha2, shift2, scalefactor2, bias2, featurelist);
        if (level2res == 2)
            classLabel = "staccato";
        else
            classLabel = " ";
    }
    else
        classLabel = " ";
}


void ViolinClassification::svmClassifyTremolo()
{
    featToCompare.clear();
    featToCompare.push_back(featurelist[1]);
    featToCompare.push_back(featurelist[2]);
    int level1res = svmfun(sv1, alpha1, shift1, scalefactor1, bias1, featToCompare);
    if (level1res == 2){
        featToCompare.clear();
        featToCompare.push_back(featurelist[4]);
        featToCompare.push_back(featurelist[5]);
        int level2res = svmfun(sv3, alpha3, shift3, scalefactor3, bias3, featToCompare);
        if (level2res == 1)
            classLabel = "tremolo";
        else
            classLabel = " ";
    }
    else
        classLabel = " ";
}


void ViolinClassification::svmClassifyTrill()
{
    int level3res = chromaCompare();
    if (level3res == 1)
        classLabel = "trill";
    else
        classLabel = " ";
}


void ViolinClassification::svmClassifyVibrato()
{
    int level3res = chromaCompare();
    if (level3res == 2)
        classLabel = "vibrato";
    else
        classLabel = " ";
}


int ViolinClassification::chromaCompare()
{
    chroma();
    int first = maxIdx(chromaFreq);
    int aa = chromaFreq[first];
    chromaFreq[first] = 0;
    int second = maxIdx(chromaFreq);
    int diff = abs(first - second);
    if (diff > 6)
        diff = NUMCHROMAGRAM - diff;
    if (diff == 2)
        return 1;
    else if (diff == 1 && aa*1.0/chromaFreq[second]<9)
        return 1;
    return 2;
}


void ViolinClassification::resample(vector<float> &input, float* output, unsigned in_rate, unsigned out_rate, long in_length)
{
    double ratio         = in_rate / (double)out_rate;
    unsigned out_length  = std::ceil(in_length / ratio);
    const double support = 4.0;
    
    for(unsigned i=0; i<out_length; ++i)
    {
        double center = i * ratio;
        double min    = center-support;
        double max    = center+support;
        
        unsigned min_in = std::max( 0,                 (int)(min + 0.5) );
        unsigned max_in = std::min( (int)in_length-1,  (int)(max + 0.5) );
        double sum    = 0.0;
        double result = 0.0;
        for(unsigned i=min_in; i<=max_in; ++i)
        {
            double factor = sinc(i-center);
            result += input[i] * factor;
            sum    += factor;
        }
        if(sum != 0.0) result /= sum;
        if(result <= -32768) output[i] = -32768;
        else if(result > 32767) output[i] = 32767;
        output[i] = result + 0.5;
    }
}


double ViolinClassification::sinc(double x)
{
    if(x == 0.0) return 1.0;
    x *= PI;
    return std::sin(x) / x;
}
