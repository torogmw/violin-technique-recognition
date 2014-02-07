//
//  OfflineVisualization.h
//  ViolinMIR
//
//  Created by Minwei Gu on 12/2/13.
//
//

#ifndef __ViolinMIR__OfflineVisualization__
#define __ViolinMIR__OfflineVisualization__

#include <iostream>
#include "JuceHeader.h"
#include <vector>
using namespace std;

class DemoThumbnailComp;


class AudioDemoPlaybackPage  : public Component, public SliderListener, public ButtonListener
{
public:
    //==============================================================================
    AudioDemoPlaybackPage (AudioDeviceManager& deviceManager_, const File& audioFile, const vector<int>& result);
    ~AudioDemoPlaybackPage();
    
    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    
    // These methods are our FileBrowserListener implementation:
    void showFile (const File& file);
    //[/UserMethods]
    
    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);
    
private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    AudioDeviceManager& deviceManager;
    AudioFormatManager formatManager;
    TimeSliceThread thread;
    DirectoryContentsList directoryList;
    
    AudioSourcePlayer audioSourcePlayer;
    AudioTransportSource transportSource;
    ScopedPointer<AudioFormatReaderSource> currentAudioFileSource;
    
    void loadFileIntoTransport (const File& audioFile);
    void updateSegmentation();
    //[/UserVariables]
    
    //==============================================================================
    ScopedPointer<Label> zoomLabel;
    ScopedPointer<Label> explanation;
    ScopedPointer<Slider> zoomSlider;
    ScopedPointer<DemoThumbnailComp> thumbnail;
    ScopedPointer<TextButton> startStopButton;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioDemoPlaybackPage)
};

#endif /* defined(__ViolinMIR__OfflineVisualization__) */
