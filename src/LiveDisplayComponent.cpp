//
//  LiveDisplay.cpp
//  DAFX
//
//  Created by Minwei Gu on 6/20/13.
//
//

#include "LiveDisplayComponent.h"

LiveAudioInputDisplayComp::LiveAudioInputDisplayComp(AudioDeviceManager& deviceManager_):deviceManager(deviceManager_)
{
    nextSample = subSample = 0;
    accumulator = 0;
    zeromem (samples, sizeof (samples));
    setOpaque (true);
    deviceManager.addAudioCallback(this);
    startTimer (1000 / 50); // use a timer to keep repainting this component
}

LiveAudioInputDisplayComp::~LiveAudioInputDisplayComp()
{
    deviceManager.removeAudioCallback(this);
}

void LiveAudioInputDisplayComp::paint (Graphics& g)
{
    g.fillAll (Colour (0xfff8ebeb));
    
    g.setColour (Colours::darkgrey);
    const float midY = getHeight() * 0.5f;
    int sampleNum = (nextSample + numElementsInArray (samples) - 1);
    
    for (int x = jmin (getWidth(), (int) numElementsInArray (samples)); --x >= 0;)
    {
        const float sampleSize = midY * samples [sampleNum-- % numElementsInArray (samples)];
        g.drawVerticalLine (x, midY - sampleSize, midY + sampleSize);
    }
}

void LiveAudioInputDisplayComp::timerCallback()
{
    repaint();
}

void LiveAudioInputDisplayComp::audioDeviceAboutToStart (AudioIODevice*)
{
    zeromem (samples, sizeof (samples));
}

void LiveAudioInputDisplayComp::audioDeviceStopped()
{
    zeromem (samples, sizeof (samples));
}

void LiveAudioInputDisplayComp::audioDeviceIOCallback (const float** inputChannelData, int numInputChannels,
                                                       float** outputChannelData, int numOutputChannels, int numSamples)
{

    
    for (int i = 0; i < numSamples; ++i)
    {
        for (int chan = 0; chan < numInputChannels; ++chan)
        {
            if (inputChannelData[chan] != 0)
                accumulator += fabsf (inputChannelData[chan][i]);
        }
        
        const int numSubSamples = 100; // how many input samples go onto one pixel.
        const float boost = 10.0f;     // how much to boost the levels to make it more visible.
        
        if (subSample == 0)
        {
            samples[nextSample] = accumulator * boost / numSubSamples;
            nextSample = (nextSample + 1) % numElementsInArray (samples);
            subSample = numSubSamples;
            accumulator = 0;
        }
        else
        {
            --subSample;
        }
    }
    
    // We need to clear the output buffers, in case they're full of junk..
    for (int i = 0; i < numOutputChannels; ++i)
        if (outputChannelData[i] != 0)
            zeromem (outputChannelData[i], sizeof (float) * (size_t) numSamples);
}