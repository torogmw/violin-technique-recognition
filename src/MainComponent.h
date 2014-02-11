/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_9002020A4DD09B20__
#define __JUCE_HEADER_9002020A4DD09B20__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "LiveDisplayComponent.h"
#include "AudioInputSource.h"
#include "MidiOut.h"
#include "AudioRecorder.h"
#include "ViolinSegmentation.h"
#include "ThreadingUI.h"


class MainComponent  : public Component,
                       public SliderListener,
                       public ButtonListener,
                       public ComboBoxListener,
                       public Timer
{
public:
    //==============================================================================
    MainComponent ();
    ~MainComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);
    void timerCallback();
    void updateToggleState();
    void comboBoxChanged(ComboBox* comboBoxThatHasChanged);
    
    // Binary resources:
    static const char* violin_png;
    static const int violin_pngSize;
    static const char* musicpizzicato_png;
    static const int musicpizzicato_pngSize;
    static const char* legato_png;
    static const int legato_pngSize;
    static const char* musictrill_png;
    static const int musictrill_pngSize;
    static const char* musictremolo_png;
    static const int musictremolo_pngSize;
    static const char* staccato_png;
    static const int staccato_pngSize;
    static const char* musichalfnote_png;
    static const int musichalfnote_pngSize;
    
private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    AudioDeviceManager deviceManager;
    //ScopedPointer<LiveStreaming> streaming;
    ScopedPointer<AudioInputSource> audioInputSource;
    ScopedPointer<MidiOut> midiOut;
    ScopedPointer<AudioRecorder> recorder;
    ScopedPointer<ViolinSegmentation> segmentation;
    ScopedPointer<DocumentWindow> offlineResult;
    
    File currentFile;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<GroupComponent> longerDetectionComponent;
    ScopedPointer<GroupComponent> techGroupComponent;
    //ScopedPointer<ThreadingDemo> animation;
    ScopedPointer<Label> pitchInfo;
    ScopedPointer<Label> pitchDisplay;
    ScopedPointer<LiveAudioInputDisplayComp> liveDisplay;
    ScopedPointer<Label> techInfo;
    ScopedPointer<Label> modeInfo;
    ScopedPointer<Slider> thresSlider;
    ScopedPointer<Label> textThres;
    ScopedPointer<TextButton> streamButton;
    ScopedPointer<TextButton> fileButton;
    ScopedPointer<Label> chooseinput;
    ScopedPointer<ToggleButton> legatoToggle;
    ScopedPointer<ToggleButton> pizzToggle;
    ScopedPointer<ToggleButton> stacToggle;
    ScopedPointer<ToggleButton> trillToggle;
    ScopedPointer<ToggleButton> vibratoToggle;
    ScopedPointer<ToggleButton> tremoToggle;
    ScopedPointer<TextButton> playButton;
    ScopedPointer<TextButton> resultButton;
    ScopedPointer<TextButton> recordButton;
    ScopedPointer<Label> offlineStatusLabel;
    //ScopedPointer<Slider> midislider;
    ScopedPointer<ComboBox> selectAudioIPCombo;
    OwnedArray<Label> pitchContour;
    
    Image cachedImage_violin_png;
    Image cachedImage_legato_png;
    Image cachedImage_musicpizzicato_png;
    Image cachedImage_musictrill_png;
    Image cachedImage_musictremolo_png;
    Image cachedImage_staccato_png;
    Image cachedImage_musichalfnote_png;
    int channel;
    int note;
    int timerCount;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_9002020A4DD09B20__
