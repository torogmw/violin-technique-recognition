//
//  ViolinSegmentation.cpp
//  ViolinMIR
//
//  Created by Minwei Gu on 11/23/13.
//
//

#include "ViolinSegmentation.h"

ViolinSegmentation::ViolinSegmentation(const float* data, int numSamples,  float** featDataset)
{
    startIdx = 0; // before cut default start index of raw data
    endIdx = 0;
    vector<float> rawData(numSamples);
    //>>>>>>>>>>>>>>>>> loading dataset >>>>>>>>>>>>>>//
    cout<<"loading dataset....."<<endl;
    for(int i = 0; i<numSamples; i++)
        rawData[i] = data[i];
    for (int i = 0 ; i<featDataNum; i++)
    {
        vector<float> oneData(featDataIndex);
        for (int j = 0; j<featDataIndex; j++)
        {
            oneData[j] = featDataset[i][j];
        }
        dataSet.push_back(oneData);
    }
    //>>>>>>>>>>>>>>>>> pre-processing >>>>>>>>>>>>>>//
    cout<<"remove silence and normalization....."<<endl;
    removeSilence(rawData);         //pre-processing
    int overLapNumSamples = 1*sampleRate;  // 1 seconds overlap for testing smooth, or not
    cutAndNorm(rawData,true,overLapNumSamples);
    
    //>>>>>>>>>>>>>>>>> feature calculation >>>>>>>>>>>>>>//
    cout<<"feature calculation....."<<endl;
    getFeatures();
    
    //>>>>>>>>>>>>>>>>> distance calculation >>>>>>>>>>>>>>//
    cout<<"distance calculation......"<<endl;
    getDist();
    
    //>>>>>>>>>>>>>>>> post-smoothing >>>>>>>>>>>>//
    cout<<"post smoothing......"<<endl;
    smoothing();
    print();
}

ViolinSegmentation::~ViolinSegmentation()
{
  
}

void ViolinSegmentation::removeSilence(vector<float>& rawData)
{
    const int sigLen = rawData.size();
    endIdx = sigLen - 1;
    // block based standarad deviation calculation
    vector<float> deviations;
    for (int i =0; i<sigLen; i=i+hopSize)
    {
        if (i+blockSize-1>=sigLen)
            break;
        else
        {
            vector<float>::const_iterator first = rawData.begin()+i;
            vector<float>::const_iterator last = rawData.begin()+i+blockSize;
            vector<float> temp(first,last);
            float sum = getSum(temp);
            float mean = sum/blockSize;
            double sq_sum = 0.0;
            for (int j = 0; j<blockSize; j++)
                sq_sum+=(temp[j]-mean)*(temp[j]-mean);
            float stdev = sqrt(sq_sum/(float)(blockSize-1));
            deviations.push_back(stdev);
        }
    }
    // remove start and end silence
    float devMax = getMax(deviations);
    for (int i = 0; i<deviations.size(); i++)
    {
        if (deviations[i]>0.03*devMax)
        {
            startIdx = (i+1)*hopSize;
            break;
        }
    }
    for (int i = deviations.size()-1; i>0; i-- )
    {
        if (deviations[i]>0.03*devMax)
        {
            endIdx = i*hopSize+blockSize-1;
            break;
        }
    }
    std::cout<<"start from "<<(float)startIdx/sampleRate<<std::endl;
    std::cout<<"end at "<<(float)endIdx/sampleRate<<std::endl;
}

void ViolinSegmentation::cutAndNorm(vector<float>& rawData, bool needOverlap, int stepLength)
{
    int numFrames = 3*sampleRate; //3 seconds for each cut files
    if (endIdx-startIdx<=numFrames)
    {
        std::cout<<"not even have a single frame to detect! "<<std::endl;
        return;
    }
    
    
    for(int i = startIdx; i <= endIdx; i=i+stepLength)
    {
        if (i+numFrames<=endIdx)
        {
            vector<float>::const_iterator first = rawData.begin()+i;
            vector<float>::const_iterator last = rawData.begin()+i+numFrames;
            vector<float> temp(first,last);
            float localMax = getMax(temp);
            float localMin = getMin(temp);
            float maxRef = localMax>fabs(localMin)?localMax:fabs(localMin);
            for (int i = 0; i < temp.size(); i++)
            {
                temp[i] = temp[i]*0.9999/maxRef;
            }
            processedData.push_back(temp);
        }
    }
}

void ViolinSegmentation::getFeatures()
{
    int numFiles = processedData.size();
    for (int i = 0; i<numFiles; i++)
    {
        vector<float> temp(6);
        featList.push_back(temp);
    }
    
    cout<<"totla file Number: "<<numFiles<<endl;
    if (numFiles==0)
    {
        std::cout<<"error! not ready for calculatiing features"<<std::endl;
        return;
    }
    for (int i = 0; i<numFiles; i++)
    {
        featZCR(processedData[i], i);
        featRMS(processedData[i], i);
        featEnv(processedData[i], i);
        
        //featCentroid(processedData[i], i);
    }
}

void ViolinSegmentation::getDist()
{
    if (featList.size() ==0 || dataSet.size() == 0)
    {
        cout<<"not able to calculate the distance due to errors"<<endl;
        return;
    }
    vector<double> dist(featDataNum);
    for (int i = 0; i<featList.size(); i++)
    {
        for (int j = 0; j<featDataNum; j++)
        {
            dist[j] = sqrt((featList[i][2]-dataSet[j][2])*(featList[i][2]-dataSet[j][2]) + (featList[i][4]-dataSet[j][4])*(featList[i][4]-dataSet[j][4]));
        }
        
        double minValue = INFINITY;
        int minIndex = 0;
        for (int k = 0; k<featDataNum; k++)
        {
            if (dist[k]<minValue)
            {
                minValue = dist[k];
                minIndex = k;
            }
        }
        if (minIndex<featLabel[0])
            result.push_back(1);
        else if (minIndex<featLabel[1])
            result.push_back(2);
        else if (minIndex<featLabel[2])
            result.push_back(3);
        else
            result.push_back(4);
    }
    result.push_back(startIdx);
    //cout<<"final push "<<startIdx<<std::endl;
}

void ViolinSegmentation::smoothing()
{
    //int window = 3;
    int numSeq = result.size();
    for (int i = 1; i<numSeq-1; i++)
    {
        if (result[i-1] == result[i+1])
            result[i] = result[i-1];
    }
}

void ViolinSegmentation::print() const
{
    for (int i = 0; i<result.size(); i++)
    {
        if (result[i] == 1)
            cout<<"L ";
        else if(result[i] == 2)
            cout<<"P ";
        else if (result[i] == 3)
            cout<<"S ";
        else
            cout<<"T ";
    }
    cout<<"end..."<<endl;
}

void ViolinSegmentation::featZCR(vector<float>& tempData, int fileIdx)
{
    int numSamples = tempData.size();
    vector<float> ZCRList;
    for (int i = 0; i<numSamples; i=i+hopSize)
    {
        if (i+blockSize-1>=numSamples)
            break;
        else
        {
            vector<float>::const_iterator first = tempData.begin()+i;
            vector<float>::const_iterator last = tempData.begin()+i+blockSize;
            vector<float> temp(first,last);
            int zcrCount = 0;
            for (int j =1; j<blockSize; j++)
            {
                if (temp[j]*temp[j-1]<0)
                    zcrCount+=1;
            }
            ZCRList.push_back((double)zcrCount/blockSize);
        }
    }
    float meanZCR = getSum(ZCRList)/ZCRList.size();
    double sq_sum = 0.0;
    for (int j = 0; j<ZCRList.size(); j++)
        sq_sum+=(ZCRList[j]-meanZCR)*(ZCRList[j]-meanZCR);
    float stdevZCR = sqrt(sq_sum/(float)(ZCRList.size()-1));
    featList[fileIdx][0] = meanZCR;
    featList[fileIdx][1] = stdevZCR;
}

void ViolinSegmentation::featEnv(vector<float> &tempData, int fileIdx)
{
    int numSamples = tempData.size();
    vector<float> envList;
    for (int i = 0 ; i<numSamples; i=i+hopSize)
    {
        if (i+blockSize-1>=numSamples)
            break;
        else
        {
            vector<float>::const_iterator first = tempData.begin()+i;
            vector<float>::const_iterator last = tempData.begin()+i+blockSize;
            vector<float> temp(first,last);
            float tempMaxEnv = getMax(temp);
            envList.push_back(tempMaxEnv);
        }
    }
    float meanEnv = getSum(envList)/envList.size();
    double sq_sum = 0.0;
    for (int j = 0; j<envList.size(); j++)
        sq_sum+=(envList[j]-meanEnv)*(envList[j]-meanEnv);
    float stdevEnv = sqrt(sq_sum/(float)(envList.size()-1));
    featList[fileIdx][4] = meanEnv;
    featList[fileIdx][5] = stdevEnv;
}

void ViolinSegmentation::featRMS(vector<float> &tempData, int fileIdx)
{
    int numSamples = tempData.size();
    vector <float> rmsList;
    for (int i = 0; i<numSamples; i = i+hopSize)
    {
        if (i+blockSize-1>=numSamples)
            break;
        else
        {
            float sum = 0;
            vector<float>::const_iterator first = tempData.begin()+i;
            vector<float>::const_iterator last = tempData.begin()+i+blockSize;
            vector<float> temp(first,last);
            for (int j = 0; j<blockSize; j++)
            {
                sum = sum + temp[j]*temp[j];
            }
            rmsList.push_back(sqrt(sum/blockSize));
        }
    }
    float meanRms = getSum(rmsList)/rmsList.size();
    double sq_sum = 0.0;
    for (int j = 0; j<rmsList.size(); j++)
        sq_sum+=(rmsList[j]-meanRms)*(rmsList[j]-meanRms);
    float stdevRms = sqrt(sq_sum/(float)(rmsList.size()-1));
    featList[fileIdx][2] = meanRms;
    featList[fileIdx][3] = stdevRms;
}

void ViolinSegmentation::featCentroid(vector<float> &tempData, int fileIdx)
{
    SplitRadixFFT* fft = new SplitRadixFFT(log2(blockSize));
    float* X = new float[blockSize*2];
    int numSamples = tempData.size();
    vector<float> centList;
    for (int i = 0; i<numSamples; i=i+hopSize)
    {
        if (i+blockSize-1>=numSamples)
            break;
        else
        {
            vector<float>::const_iterator first = tempData.begin()+i;
            vector<float>::const_iterator last = tempData.begin()+i+blockSize;
            vector<float> temp(first,last);
            vector<float> dotProduct(blockSize);
            for (int j=0; j<blockSize; j++)
                X[j] = temp[j];
            for (int j=blockSize; j<blockSize*2; j++)
                X[j] = 0;
            fft->XForm(X);
            for (int j = 0; j<blockSize; j++)
            {
                X[j] = sqrt(X[j]*X[j]+X[blockSize*2-j]*X[blockSize*2-j]);
                temp[j]=X[j];
            }
            for (int j = 0; j<blockSize; j++)
                dotProduct[j] = temp[j]*(j+1)*sampleRate/blockSize;
            float centroid = getSum(dotProduct)/getSum(temp);
            centList.push_back(centroid);
        }
    }
    float meanCent = getSum(centList)/centList.size();
   
    double sq_sum = 0.0;
    for (int j = 0; j<centList.size(); j++)
        sq_sum+=(centList[j]-meanCent)*(centList[j]-meanCent);
    float stdevCent = sqrt(sq_sum/(float)(centList.size()-1));
    delete []X;
    delete fft;
}


float ViolinSegmentation::getSum(vector<float>& tempData)
{
    float sum = 0;
    for (int i=0; i<tempData.size(); i++)
        sum += tempData[i];
    return sum;
}

float ViolinSegmentation::getMax(vector<float>& tempData, int start, int end)
{
    float max = 0;
    if (start >= end)
    {
        for (int i=0; i<tempData.size(); i++)
        {
            if (tempData[i]>max)
                max = tempData[i];
        }
    }
    else
    {
        for (int i=start; i<end; i++)
        {
            if (tempData[i]>max)
                max = tempData[i];
        }
    }
    return max;
}

float ViolinSegmentation::getMin(vector<float>& tempData, int start, int end)
{
    float min = 10000;
    if (start>=end)
    {
        for (int i=0; i<tempData.size(); i++)
        {
            if (tempData[i]<min)
                min = tempData[i];
        }
    }
    else
    {
        for (int i=start; i<end; i++)
        {
            if (tempData[i]<min)
                min = tempData[i];
        }
        
    }
    return min;
}

vector<int> ViolinSegmentation::getResult() const
{
    if (result.size()>0)
    {
        return result;
    }
    
}





