
#ifndef __ThinkPlayAudio__LiveStreaming__
#define __ThinkPlayAudio__LiveStreaming__

#include <iostream>
#include "JuceHeader.h"
#include "ViolinClassification.h"

#define RECORDSIZE 44100

class LiveStreaming :public AudioIODeviceCallback
{
public:
    LiveStreaming(AudioDeviceManager& deviceManager);
    ~LiveStreaming();
    void audioDeviceIOCallback(const float** inputChannelData,
							   int totalNumInputChannels,
							   float** outputChannelData,
							   int totalNumOutputChannels,
							   int numSamples);
	
	void audioDeviceAboutToStart (AudioIODevice* device);
    void audioDeviceStopped();
    void violinTracking(float* data);
    
    ViolinClassification* vc;
    
private:
    AudioDeviceManager& deviceManager;
    TimeSliceThread liveStreamingThread;
    AudioSampleBuffer sampleBuffer = AudioSampleBuffer(1,RECORDSIZE); //the buffer is for store;
    AudioSampleBuffer calculateBuffer = AudioSampleBuffer(1,RECORDSIZE); //the buffer is throwing to the pitchtail
    AudioSampleBuffer tempBuffer = AudioSampleBuffer(1,RECORDSIZE); // this buffer is for sliding buffer window
    bool streamingAlive;
    bool bufferReady;
    int bufferIndex;
    int inittime = 0;
};
#endif
