//
//  ViolinSegmentation.h
//  ViolinMIR
//
//  Created by Minwei Gu on 11/23/13.
//
//
#ifndef __ViolinMIR__ViolinSegmentation__
#define __ViolinMIR__ViolinSegmentation__

#include <iostream>
#include <vector>
#include <math.h>
#include "rsrfft.h"

using namespace std;


class ViolinSegmentation 
{
public:
    ViolinSegmentation(const float* data, int numSamples, float** featDataset);
    ~ViolinSegmentation();
    //void getFeatures(float* data, bool overlap);
    void removeSilence(vector<float>& raw);
    void cutAndNorm(vector<float>& raw, bool needOverlap, int stepLength = 3*44100);
    void getFeatures();
    void getDist();
    void smoothing();
    vector<int> getResult() const;
    void print() const;
    void featZCR(vector<float>& tempData, int fileIdx);
    void featEnv(vector<float>& tempData, int fileIdx);
    void featCentroid(vector<float>& tempData, int fileIdx);
    void featRMS(vector<float>& tempData, int fileIdx);
    // useful math function
    float getSum(vector<float>& tempData);
    float getMax(vector<float>& tempData, int start=0, int end=0);
    float getMin(vector<float>& tempData, int start=0, int end=0);
    
private:
    const int sampleRate = 44100;
    const int blockSize = 1024;
    const int hopSize = 100;
    const int featLabel[4] = {74,158,223,301};
    const int featDataNum = 301;
    const int featDataIndex = 6;
    int startIdx;
    int endIdx;
    vector<vector<float> > featList;
    vector<vector<float> > dataSet;
    vector<vector<float> > processedData;
    vector<int> result;
};


#endif