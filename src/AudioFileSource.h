//
//  AudioFileSource.h
//  OnsetReal
//
//  Created by Minwei Gu on 8/28/13.
//
//

#ifndef __OnsetReal__AudioInputSource__
#define __OnsetReal__AudioInputSource__

#include <iostream>
#include "JuceHeader.h"
#include "DetectionFunction.h"

#define PI 3.1415926535


class AudioFileSource : public AudioIODeviceCallback
{
public:
    AudioFileSource(AudioDeviceManager& deviceManager);
    ~AudioFileSource();
    void audioDeviceIOCallback(const float** inputChannelData,
							   int totalNumInputChannels,
							   float** outputChannelData,
							   int totalNumOutputChannels,
							   int numSamples);
    void audioDeviceAboutToStart (AudioIODevice* device);
    void audioDeviceStopped();
    void setFile(File audioFile);
    void stopPlaying();
    void goOnset(float* data);

private:
    
    AudioDeviceManager& deviceManager;                          // global device manager
    AudioSourcePlayer audioSourcePlayer;
    AudioFormatReaderSource* fileSource;
    AudioTransportSource transportSource;
    AudioFormatManager formatManager;
    TimeSliceThread playingThread;
    int sampleRate_;
    int inputSize_;
    AudioSampleBuffer sampleBuffer = AudioSampleBuffer(1,INPUTSIZE); //the buffer is for store;
    AudioSampleBuffer calculateBuffer = AudioSampleBuffer(1,INPUTSIZE); //the buffer is throwing to the pitchtail
    AudioSampleBuffer tempBuffer = AudioSampleBuffer(1,INPUTSIZE); // this buffer is for sliding buffer window
    DetectionFunction *detectionTrail;
    bool bufferReady;
    float* temp;
    
};
#endif /* defined(__OnsetReal__FileInputSource__) */
