//
//  LiveDisplay.h
//  DAFX
//
//  Created by Minwei Gu on 6/20/13.
//
//

#ifndef __DAFX__LiveDisplay__
#define __DAFX__LiveDisplay__

#include <iostream>
#include "JuceHeader.h"

class LiveAudioInputDisplayComp  : public Component,
                                   public AudioIODeviceCallback,
                                   public Timer
{
public:
    //==============================================================================
    LiveAudioInputDisplayComp(AudioDeviceManager& deviceManager);
    ~LiveAudioInputDisplayComp();
    
    void paint (Graphics& g);
    void timerCallback();
    
    void audioDeviceAboutToStart (AudioIODevice* device);
    void audioDeviceStopped();
    void audioDeviceIOCallback (const float** inputChannelData, int numInputChannels,
                                float** outputChannelData, int numOutputChannels, int numSamples);
private:
    float samples [1024];   //live display. why not live play? 
    int nextSample, subSample;
    float accumulator;
    
    AudioDeviceManager& deviceManager;
    LiveAudioInputDisplayComp (const LiveAudioInputDisplayComp&);
    LiveAudioInputDisplayComp& operator= (const LiveAudioInputDisplayComp&);
};
#endif /* defined(__DAFX__LiveDisplay__) */
