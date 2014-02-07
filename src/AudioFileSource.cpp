//
//  AudioFileSource.cpp
//  OnsetReal
//
//  Created by Minwei Gu on 8/28/13.
//
//

#include "AudioFileSource.h"

AudioFileSource::AudioFileSource(AudioDeviceManager& deviceManager_):deviceManager(deviceManager_), playingThread("file audio IO")
{
    AudioDeviceManager::AudioDeviceSetup config;
    deviceManager.getAudioDeviceSetup(config);
    config.bufferSize = 1024;
    config.sampleRate = FS;
    deviceManager.setAudioDeviceSetup(config, true);
    
    
    formatManager.registerBasicFormats();
    audioSourcePlayer.setSource(&transportSource);
    deviceManager.addAudioCallback(this);
    playingThread.startThread();
    
    sampleRate_ = FS; //default value
    inputSize_ = ceil(INPUTSIZE);
    std::cout<<"current fs: "<<sampleRate_<<"current input size: "<<inputSize_<<std::endl;
    
    bufferReady = false;
    temp = new float[inputSize_];
    
    detectionTrail = new DetectionFunction(inputSize_,sampleRate_);
    
}

AudioFileSource::~AudioFileSource()
{
    deviceManager.removeAudioCallback(this);
    transportSource.setSource(0);
    deleteAndZero(fileSource);
    audioSourcePlayer.setSource(0);
    detectionTrail = nullptr;
    delete []temp;
}

void AudioFileSource::setFile(File audioFile)
{
    if(audioFile.exists())
    {
        if (fileSource)
        {
            transportSource.setSource(0);
            deleteAndZero(fileSource);
        }
        AudioFormatReader* tempReader = formatManager.createReaderFor(audioFile);
        fileSource = new AudioFormatReaderSource(tempReader,true);
        transportSource.setSource(fileSource,32768,&playingThread,sampleRate_);
        transportSource.start();
    }
    else
    {
        std::cout<<"nothing to be player! "<<std::endl;
    }
}

void AudioFileSource::audioDeviceIOCallback(const float** inputChannelData,
                                            int totalNumInputChannels,
                                            float** outputChannelData,
                                            int totalNumOutputChannels,
                                            int numSamples)
{
    
    if (bufferReady == true)
    {
//        temp = calculateBuffer.getSampleData(0);
//        for (int i=0; i<inputSize_; i++)
//            std::cout<<temp[i]<<" ";
        goOnset(calculateBuffer.getSampleData(0));
        bufferReady = false;
        
    }
    
    if (bufferReady == false)
    {
        sampleBuffer.copyFrom(0, 0, outputChannelData[0], numSamples);
        tempBuffer.copyFrom(0, 0, calculateBuffer, 0, numSamples, inputSize_ - numSamples);
        calculateBuffer.clear();
        tempBuffer.copyFrom(0, inputSize_ - numSamples, sampleBuffer, 0, 0, numSamples);
        calculateBuffer.copyFrom(0, 0, tempBuffer, 0, 0, inputSize_ );
        tempBuffer.clear();
        bufferReady = true;
        sampleBuffer.clear();
    }
    audioSourcePlayer.audioDeviceIOCallback (inputChannelData, totalNumInputChannels, outputChannelData, totalNumOutputChannels, numSamples);   //pass the output to the player

}

void AudioFileSource::goOnset(float *data)
{
    //float *temp = new float[inputSize_];
    memset(temp, 0.f, sizeof(float) * inputSize_);
    for (int i = 0; i<inputSize_; i++)
    {
        temp[i]=data[i];//*32768;
        //std::cout<<temp[i]<< " ";
    }
    bool existOnset = 0;
    existOnset = detectionTrail->onsetMain(temp); //mono data
    if(existOnset == 1)
    {
        std::cout<<transportSource.getCurrentPosition()<<" ";
    }
   
}

void AudioFileSource::audioDeviceAboutToStart(AudioIODevice* device)
{
    audioSourcePlayer.audioDeviceAboutToStart (device);
}

void AudioFileSource::audioDeviceStopped()
{
    audioSourcePlayer.audioDeviceStopped();
}

void AudioFileSource::stopPlaying()
{
    transportSource.stop();
    transportSource.setPosition(0);
    
}