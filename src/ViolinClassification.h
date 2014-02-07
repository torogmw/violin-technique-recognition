//
//  ViolinClassification.h
//  PitchTail_1
//
//  Created by annie zhang on 11/15/13.
//
//

#ifndef __PitchTail_1__ViolinClassification__
#define __PitchTail_1__ViolinClassification__

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include "ChromaFeat.h"
#include <math.h>

#define SAMPLESIZE 44100
#define F 44100
#define FS 4000

using namespace std;

class ViolinClassification{
    
public:
    ViolinClassification();
    ~ViolinClassification();
    void getReady(float* gWavDataIn);
    void normalize(vector<float> &data);
    void normalize(float* v, int size);
    void getFeatures();
    void timeDomainFeat();
    void envelope();
    void chroma();
    void chromaPeakPair(float *data, vector<int> &v);
    float getSum(vector<float> &v);
    float inProduct(vector<float> &v1, vector<float> &v2);
    float max(vector<float> &v, int start, int end);
    float absmax(vector<float> &v, int start, int end);
    int maxIdx(float *data, int size);
    int maxIdx(vector<int> &data);
    void resample(vector<float> &input, float* output, unsigned in_rate, unsigned out_rate, long in_length);
    double sinc(double x);
    int svmfun(vector<vector<float>> &sv, vector<float> &alpha, vector<float> &shift, vector<float> &scalefactor, float bias, vector<float> &feat);
    void doClassify();
    void svmClassifyAll();
    void svmClassifyPizz();
    void svmClassifyStaccato();
    void svmClassifyTremolo();
    void svmClassifyTrill();
    void svmClassifyVibrato();
    int chromaCompare();
    bool valid();
    bool contain(vector<int> &t, int q);
    void smooth(vector<int> &c);
    
    ChromaFeat *cf;
    string classLabel = "^_^";
    vector<int> toggleState;
    float threshold = 0.005;
    int pitch = 0;
        
protected:
    const int blockSize = 1024;
    const int hopSize = 100;
    const int env_blockSize = 512;
    const int env_hopSize = 100;
    
    const float bias1 = 1.6914;
    const float bias2 = 0.0029;
    const float bias3 = -0.8262;
    int numblocks;
    int numdownSamples;
    float* resampleddata;
    float* chromahist;
    vector<int> targetEnergyPeaks;
    vector<vector<float> > sv1;
    vector<vector<float> > sv2;
    vector<vector<float> > sv3;
    vector<float> alpha1;
    vector<float> alpha2;
    vector<float> alpha3;
    vector<float> shift1;
    vector<float> shift2;
    vector<float> shift3;
    vector<float> scalefactor1;
    vector<float> scalefactor2;
    vector<float> scalefactor3;
    vector<float> inputData;
    vector<float> env;
    vector<int> chromaFreq;
    vector<float> featToCompare;
    vector<float> featurelist;                                      // 1. std
                                                                    // 2. skewness
                                                                    // 3. kurtosis
                                                                    // 4. envelope mean
                                                                    // 5. envelope std
                                                                    // 6. special feature

private:
    ofstream outfile;

};

#endif /* defined(__PitchTail_1__ViolinClassification__) */
