//
//  AudioRecorder.h
//  ViolinMIR
//
//  Created by Minwei Gu on 11/23/13.
//
//

#ifndef __ViolinMIR__AudioRecorder__
#define __ViolinMIR__AudioRecorder__

#include <iostream>
#include "JuceHeader.h"
#include "ViolinSegmentation.h"
#include <vector>
#include "OfflineVisualization.h"


using namespace std;


class OfflineWindow;


class AudioRecorder : public AudioIODeviceCallback
{
    public :
    AudioRecorder(AudioDeviceManager& deviceManager);
    ~AudioRecorder();
    
    // method from recorder
    void startRecording(const File& file);
    void stop();
    bool isRecording() const;
    // general method
    void audioDeviceIOCallback(const float** inputChannelData,
							   int totalNumInputChannels,
							   float** outputChannelData,
							   int totalNumOutputChannels,
							   int numSamples);
	
	void audioDeviceAboutToStart (AudioIODevice* device);
    void audioDeviceStopped();
    
    // to segmentation
    void readSamplesFromFile(const File& audioFile);
    void visualization();
    
private:
    //variable from recording
    TimeSliceThread backgroundThread; // the thread that will write our audio data to disk
    ScopedPointer<AudioFormatWriter::ThreadedWriter> threadedWriter; // the FIFO used to buffer the incoming data
    double sampleRate;
    CriticalSection writerLock;
    AudioFormatWriter::ThreadedWriter* volatile activeWriter;
	AudioDeviceManager& deviceManager; //use pointer to initialize audio device manager
    
    // variable for segmentation
    AudioFormatManager formatManager;
    OfflineWindow* offlineResult;
    AudioFormatReaderSource* source;
    AudioSampleBuffer* bufferToFill;
    int64 totalLength;
    
    File currentFile;
    float** database;
    ViolinSegmentation* vs;

    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioRecorder)
};
#endif /* defined(__ViolinMIR__AudioRecorder__) */
