//
//  AudioRecorder.cpp
//  ViolinMIR
//
//  Created by Minwei Gu on 11/23/13.
//
//

#include "AudioRecorder.h"
class OfflineWindow  : public DocumentWindow
{
public:
    //==============================================================================
    OfflineWindow()
    : DocumentWindow ("",
                      Colours::lightgrey,
                      DocumentWindow::allButtons,
                      true)
    {
        // Create an instance of our main content component, and add it to our window..
    }
    
    ~OfflineWindow()
    {
        // (the content component will be deleted automatically, so no need to do it here)
    }
    
    //==============================================================================
    void closeButtonPressed()
    {
        // When the user presses the close button, we'll tell the app to quit. This
        // HelloWorldWindow object will be deleted by the JUCEHelloWorldApplication class.
        delete this;
    }
};


AudioRecorder::AudioRecorder(AudioDeviceManager& deviceManager_):backgroundThread("Audio Recorder"),  sampleRate(0), activeWriter(0),deviceManager(deviceManager_)
{
    //    audioDeviceManager.initialise(2, /* number of input channels */
    //                                  2, /* number of output channels */
    //                                  0, /* no XML settings*/
    //                                  true, /* select default device on failure */
    //                                  String::empty, /* preferred device name */
    //                                  0 /* preferred setup options */);
    deviceManager.addAudioCallback(this);
    formatManager.registerBasicFormats();
    backgroundThread.startThread();
    
    // load dataset
    File dataSet = File("/Fall2013/6201/project/violin-technique-detection/res/ftOffline.txt");
    StringArray lines;
    dataSet.readLines(lines);
    int row = lines.size();
    database = new float* [row];
    for (int i = 0 ; i<lines.size(); i++)
    {
        StringArray oneLine;
        oneLine.addTokens(lines[i], "\t");
        int  len= oneLine.size();
        float* temp = new float[len];
        for (int j=0 ;j<len; j++)
        {
            temp[j] = oneLine[j].getFloatValue();
        }
        database[i] = temp;
    }
}

AudioRecorder::~AudioRecorder()
{
    stop();
    deviceManager.removeAudioCallback(this);
    //delete bufferToFill;        
}

void AudioRecorder::readSamplesFromFile(const juce::File &audioFile)
{
    currentFile = audioFile;
    AudioFormatReader* reader = formatManager.createReaderFor(audioFile);                  //create reader
    totalLength = reader -> lengthInSamples;                            //get length
    bufferToFill = new AudioSampleBuffer(1,totalLength);
    reader->read(bufferToFill,0,totalLength,0,true,false);
    
//    for (int i = 0; i<totalLength; i++)
//        std::cout<<bufferToFill->getSampleData(0)[i]<<std::endl;
    vs = new ViolinSegmentation(bufferToFill->getSampleData(0),totalLength,database);

    delete reader;
    delete bufferToFill;
    delete vs;
}

void AudioRecorder::visualization()
{
    vector<int> result = vs->getResult();
    offlineResult = new OfflineWindow ();
    offlineResult->setContentOwned(new AudioDemoPlaybackPage(deviceManager,currentFile, result), true);
    offlineResult->setVisible(true);
}

void AudioRecorder::startRecording(const File& file)
{
    stop();
    if (sampleRate > 0)
    {
        // Create an OutputStream to write to our destination file...
        file.deleteFile();
        ScopedPointer<FileOutputStream> fileStream (file.createOutputStream());
        if (fileStream != 0)
        {
            // Now create a WAV writer object that writes to our output stream...
            WavAudioFormat wavFormat;
            AudioFormatWriter* writer = wavFormat.createWriterFor (fileStream, sampleRate, 1, 16, StringPairArray(), 0);
            if (writer != 0)
            {
                fileStream.release(); // (passes responsibility for deleting the stream to the writer object that is now using it)
                
                // Now we'll create one of these helper objects which will act as a FIFO buffer, and will
                // write the data to disk on our background thread.
                threadedWriter = new AudioFormatWriter::ThreadedWriter (writer, backgroundThread, 32768);
                
                // And now, swap over our active writer pointer so that the audio callback will start using it..
                const ScopedLock sl (writerLock);
                activeWriter = threadedWriter;
            }
        }
    }
}

void AudioRecorder::stop()
{
    {
        const ScopedLock sl (writerLock);
        activeWriter = 0;
    }
    
    // Now we can delete the writer object. It's done in this order because the deletion could
    // take a little time while remaining data gets flushed to disk, so it's best to avoid blocking
    // the audio callback while this happens.
    threadedWriter = 0;
}

bool AudioRecorder::isRecording() const
{
    return activeWriter !=0;
    
}

// general setting about audio device start here
void AudioRecorder::audioDeviceAboutToStart(AudioIODevice* device)
{
    sampleRate = device->getCurrentSampleRate();
}

void AudioRecorder::audioDeviceStopped()
{
    sampleRate=0;
}

void AudioRecorder::audioDeviceIOCallback (const float** inputChannelData, int totalNumInputChannels,
                                           float** outputChannelData, int numOutputChannels,
                                           int numSamples)
{
    const ScopedLock sl (writerLock);
    if (activeWriter != 0)
        activeWriter->write (inputChannelData, numSamples);
    // We need to clear the output buffers, in case they're full of junk..
    for (int i = 0; i < numOutputChannels; ++i)
        if (outputChannelData[i] != 0)
            zeromem (outputChannelData[i], sizeof (float) * numSamples);
}
