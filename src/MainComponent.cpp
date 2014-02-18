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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "MainComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainComponent::MainComponent ()
{
    addAndMakeVisible (longerDetectionComponent = new GroupComponent ("longer",
                                                                      "offline segmentation"));
    longerDetectionComponent->setTextLabelPosition (Justification::centred);

    addAndMakeVisible (techGroupComponent = new GroupComponent ("new group",
                                                                "techniques for detection"));
    techGroupComponent->setTextLabelPosition (Justification::centred);

    //addAndMakeVisible (videoTrigger = new QuickTimeMovieComponent());
    //addAndMakeVisible(animation = new ThreadingDemo());

    
//    addAndMakeVisible (pitchDisplay = new Label (""));
//    pitchDisplay->setEditable (false, false, false);
//    pitchDisplay->setColour (Label::backgroundColourId, Colours::chocolate);
    
    addAndMakeVisible (pitchInfo = new Label ("pitch",
                                              "pitch\n"));
    pitchInfo->setFont (Font (26.20f, Font::plain));
    pitchInfo->setJustificationType (Justification::centred);
    pitchInfo->setEditable (false, false, false);
    pitchInfo->setColour (Label::backgroundColourId, Colour (0xfff8ebeb));
    pitchInfo->setColour (TextEditor::textColourId, Colours::black);
    pitchInfo->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    pitchInfo->setColour (TextEditor::highlightColourId, Colour (0x40080808));

    //addAndMakeVisible (liveDisplay = new LiveAudioInputDisplayComp(deviceManager));
    addAndMakeVisible (techInfo = new Label ("tech",
                                             "Technique\n"));
    techInfo->setFont (Font (24.20f, Font::plain));
    techInfo->setJustificationType (Justification::centred);
    techInfo->setEditable (false, false, false);
    techInfo->setColour (Label::backgroundColourId, Colour (0xfff8ebeb));
    techInfo->setColour (TextEditor::textColourId, Colours::black);
    techInfo->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (modeInfo = new Label ("mode",
                                             "mode"));
    modeInfo->setFont (Font (26.20f, Font::plain));
    modeInfo->setJustificationType (Justification::centred);
    modeInfo->setEditable (false, false, false);
    modeInfo->setColour (Label::backgroundColourId, Colour (0xfff8ebeb));
    modeInfo->setColour (TextEditor::textColourId, Colours::black);
    modeInfo->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    modeInfo->setColour (TextEditor::highlightColourId, Colour (0x40080808));

    addAndMakeVisible (thresSlider = new Slider ("threshold"));
    thresSlider->setRange (0, 1, 0.001);
    thresSlider->setSliderStyle (Slider::IncDecButtons);
    thresSlider->setTextBoxStyle (Slider::TextBoxRight, true, 40, 20);
    thresSlider->setColour (Slider::backgroundColourId, Colour (0x00f3b3b3));
    thresSlider->setColour (Slider::thumbColourId, Colour (0xff1a1adf));
    thresSlider->setColour (Slider::rotarySliderFillColourId, Colour (0x7f3a3aa3));
    thresSlider->setColour (Slider::textBoxHighlightColourId, Colour (0x40484857));
    thresSlider->addListener (this);

    addAndMakeVisible (textThres = new Label ("new label",
                                              "sensitivity \n(0-1)"));
    textThres->setFont (Font (19.60f, Font::plain));
    textThres->setJustificationType (Justification::centred);
    textThres->setEditable (false, false, false);
    textThres->setColour (TextEditor::textColourId, Colours::black);
    textThres->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (streamButton = new TextButton ("stream"));
    streamButton->setButtonText ("live stream");
    streamButton->setConnectedEdges (Button::ConnectedOnBottom);
    streamButton->addListener (this);
    streamButton->setColour (TextButton::buttonColourId, Colours::chocolate);
    streamButton->setColour (TextButton::buttonOnColourId, Colours::coral);

    addAndMakeVisible (fileButton = new TextButton ("file"));
    fileButton->setButtonText ("file input");
    fileButton->setConnectedEdges (Button::ConnectedOnTop);
    fileButton->addListener (this);
    fileButton->setColour (TextButton::buttonColourId, Colours::chocolate);
    fileButton->setColour (TextButton::buttonOnColourId, Colours::coral);

    addAndMakeVisible (chooseinput = new Label ("choose",
                                                "choose input\n(live / file)\n"));
    chooseinput->setFont (Font (19.60f, Font::plain));
    chooseinput->setJustificationType (Justification::centred);
    chooseinput->setEditable (false, false, false);
    chooseinput->setColour (TextEditor::textColourId, Colours::black);
    chooseinput->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (legatoToggle = new ToggleButton ("legato"));
    legatoToggle->addListener (this);
    legatoToggle->setColour(TextButton::buttonColourId, Colours::chocolate);
    addAndMakeVisible (pizzToggle = new ToggleButton ("pizz"));
    
    pizzToggle->setButtonText ("pizzicato");
    pizzToggle->addListener (this);
    pizzToggle->setColour(TextButton::buttonColourId, Colours::chocolate);
    
    addAndMakeVisible (stacToggle = new ToggleButton ("staccato"));
    stacToggle->addListener (this);
    stacToggle->setColour(TextButton::buttonColourId, Colours::chocolate);
    
    addAndMakeVisible (trillToggle = new ToggleButton ("trill"));
    trillToggle->addListener (this);
    trillToggle->setColour(TextButton::buttonColourId, Colours::chocolate);
    
    addAndMakeVisible (vibratoToggle = new ToggleButton ("vibrato"));
    vibratoToggle->addListener (this);
    vibratoToggle->setColour(TextButton::buttonColourId, Colours::chocolate);
    
    addAndMakeVisible (tremoToggle = new ToggleButton ("tremolo"));
    tremoToggle->addListener (this);
    tremoToggle->setColour(TextButton::buttonColourId, Colours::chocolate);
    
    addAndMakeVisible (playButton = new TextButton ("play"));
    playButton->setButtonText ("load");
    playButton->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnBottom);
    playButton->addListener (this);
    playButton->setColour (TextButton::buttonColourId, Colours::chocolate);

    addAndMakeVisible (resultButton = new TextButton ("result"));
    resultButton->setButtonText ("show segmentation");
    resultButton->setConnectedEdges (Button::ConnectedOnTop);
    resultButton->addListener (this);
    resultButton->setColour (TextButton::buttonColourId, Colours::chocolate);

    addAndMakeVisible (recordButton = new TextButton ("record"));
    recordButton->setConnectedEdges (Button::ConnectedOnRight | Button::ConnectedOnBottom);
    recordButton->addListener (this);
    recordButton->setColour (TextButton::buttonColourId, Colours::chocolate);
    recordButton->setColour (TextButton::buttonOnColourId, Colours::coral);

    addAndMakeVisible (offlineStatusLabel = new Label ("choose",
                                                       "record a piece and segment it wih detected techniques"));
    offlineStatusLabel->setFont (Font ("Arial", 17.20f, Font::plain));
    offlineStatusLabel->setJustificationType (Justification::centred);
    offlineStatusLabel->setEditable (false, false, false);
    offlineStatusLabel->setColour (TextEditor::textColourId, Colours::black);
    offlineStatusLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

//    addAndMakeVisible (midislider = new Slider ("new slider"));
//    midislider->setRange (55, 90, 1);
//    midislider->setSliderStyle (Slider::LinearHorizontal);
//    midislider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
//    midislider->addListener (this);

    
    addAndMakeVisible(selectAudioIPCombo = new ComboBox ("Select Audio Input Device"));
    selectAudioIPCombo->setEditableText(true);
    selectAudioIPCombo->addListener(this);
    selectAudioIPCombo->setJustificationType(Justification::centred);
    selectAudioIPCombo->setColour(ComboBox::buttonColourId, Colours::chocolate);
    
    // init the pitch contour labels here
    for (int i = 0; i <330; i++){
        pitchContour.add(new Label(""));
        addAndMakeVisible(pitchContour.getLast());
        pitchContour.getLast()->setEditable(false,false,false);
        pitchContour.getLast()->setColour (Label::backgroundColourId, Colours::chocolate);
        pitchContour.getLast()->setBounds(i*2+30, 680, 2, 0);
    }
        
    
    
    cachedImage_violin_png = ImageCache::getFromMemory (violin_png, violin_pngSize);
    cachedImage_legato_png = ImageCache::getFromMemory (legato_png, legato_pngSize);
    cachedImage_musicpizzicato_png = ImageCache::getFromMemory (musicpizzicato_png, musicpizzicato_pngSize);
    cachedImage_musictrill_png = ImageCache::getFromMemory (musictrill_png, musictrill_pngSize);
    cachedImage_musictremolo_png = ImageCache::getFromMemory (musictremolo_png, musictremolo_pngSize);
    cachedImage_staccato_png = ImageCache::getFromMemory (staccato_png, staccato_pngSize);
    cachedImage_musichalfnote_png = ImageCache::getFromMemory (musichalfnote_png, musichalfnote_pngSize);

    //[UserPreSize]
    //[/UserPreSize]

    setSize (1024, 768);


    //[Constructor] You can add your own custom stuff here..
    midiOut = new MidiOut();
    deviceManager.initialise(2, /* number of input channels */
                                  2, /* number of output channels */
                                  0, /* no XML settings*/
                                  true, /* select default device on failure */
                                  String::empty, /* preferred device name */
                                  0 /* preferred setup options */);



    deviceManager.setDefaultMidiOutput("from violinTrigger");
    recorder = new AudioRecorder(deviceManager);
    startTimer(40);
    channel = 0;
    note = 0;
    timerCount = 0;
    //[/Constructor]
}

MainComponent::~MainComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    longerDetectionComponent = nullptr;
    techGroupComponent = nullptr;
    //animation = nullptr;
    pitchInfo = nullptr;
    //pitchDisplay = nullptr;
    //liveDisplay = nullptr;
    techInfo = nullptr;
    modeInfo = nullptr;
    thresSlider = nullptr;
    textThres = nullptr;
    streamButton = nullptr;
    fileButton = nullptr;
    chooseinput = nullptr;
    legatoToggle = nullptr;
    pizzToggle = nullptr;
    stacToggle = nullptr;
    trillToggle = nullptr;
    vibratoToggle = nullptr;
    tremoToggle = nullptr;
    playButton = nullptr;
    resultButton = nullptr;
    recordButton = nullptr;
    offlineStatusLabel = nullptr;
    //midislider = nullptr;
    selectAudioIPCombo = nullptr;
    
    pitchContour.removeRange(0, pitchContour.size());

    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xfff8ebeb));

    g.setColour (Colours::black.withAlpha (0.792f));
    g.drawImage (cachedImage_violin_png,
                 864, 2, 128, 124,
                 0, 0, cachedImage_violin_png.getWidth(), cachedImage_violin_png.getHeight());

    g.setColour (Colours::black);
    g.setFont (Font ("Arial", 25.20f, Font::plain));
    g.drawText ("Violin Technique Recognition",
                312, 26, 348, 52,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.drawImage (cachedImage_legato_png,
                 324, 172, 75, 50,
                 0, 0, cachedImage_legato_png.getWidth(), cachedImage_legato_png.getHeight());

    g.setColour (Colours::black);
    g.drawImage (cachedImage_musicpizzicato_png,
                 328, 250, 60, 60,
                 0, 0, cachedImage_musicpizzicato_png.getWidth(), cachedImage_musicpizzicato_png.getHeight());

    g.setColour (Colours::black);
    g.drawImage (cachedImage_musictrill_png,
                 544, 162, 60, 76,
                 0, 0, cachedImage_musictrill_png.getWidth(), cachedImage_musictrill_png.getHeight());

    g.setColour (Colours::black);
    g.drawImage (cachedImage_musictremolo_png,
                 544, 314, 60, 76,
                 0, 0, cachedImage_musictremolo_png.getWidth(), cachedImage_musictremolo_png.getHeight());

    g.setColour (Colours::black);
    g.drawImage (cachedImage_staccato_png,
                 336, 330, 44, 52,
                 0, 0, cachedImage_staccato_png.getWidth(), cachedImage_staccato_png.getHeight());

    g.setColour (Colours::black);
    g.drawImage (cachedImage_musichalfnote_png,
                 544, 234, 60, 76,
                 0, 0, cachedImage_musichalfnote_png.getWidth(), cachedImage_musichalfnote_png.getHeight());

}

void MainComponent::resized()
{
    longerDetectionComponent->setBounds (712, 136, 288, 272);
    techGroupComponent->setBounds (208, 136, 472, 272);
    selectAudioIPCombo->setBounds (getWidth()/4+120, getHeight()/4-120, 200, 24);
    //animation->setBounds (0, 464, 616, 304);
    //pitchDisplay->setBounds(900, 542, 40, 10);
    pitchInfo->setBounds (640, 488, 296, 64);
    //liveDisplay->setBounds (8, 408, 1032, 56);
    techInfo->setBounds (640, 557, 296, 64);
    modeInfo->setBounds (640, 626, 296, 64);
    thresSlider->setBounds (48, 96, 97, 104);
    textThres->setBounds (40, 32, 112, 56);
    streamButton->setBounds (64, 272, 56, 64);
    fileButton->setBounds (64, 336, 56, 59);
    chooseinput->setBounds (32, 208, 128, 56);
    legatoToggle->setBounds (248, 176, 72, 32);
    pizzToggle->setBounds (248, 264, 80, 24);
    stacToggle->setBounds (248, 344, 80, 24);
    trillToggle->setBounds (448, 176, 56, 32);
    vibratoToggle->setBounds (448, 264, 80, 24);
    tremoToggle->setBounds (448, 344, 80, 24);
    playButton->setBounds (865, 264, 96, 48);
    resultButton->setBounds (768, 312, 192, 48);
    recordButton->setBounds (769, 264, 96, 48);
    offlineStatusLabel->setBounds (728, 168, 256, 80);
    //midislider->setBounds (648, 704, 280, 48);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MainComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == thresSlider)
    {
        //[UserSliderCode_thresSlider] -- add your slider handling code here..
//        if (thresSlider->getValue() < 0.5)
//            animation->addABall();
//        else
//            animation->removeABall();
        if (audioInputSource)
            audioInputSource->vc->threshold = thresSlider->getValue();
        
        //[/UserSliderCode_thresSlider]
    }
//    else if (sliderThatWasMoved == midislider)
//    {
//        //[UserSliderCode_midislider] -- add your slider handling code here..
//        midiOut->sendMidiOut(2, midislider->getValue(), 127);
//        //[/UserSliderCode_midislider]
//    }
//
    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void MainComponent::timerCallback()
{
    timerCount++;
    selectAudioIPCombo->clear();
    AudioIODeviceType* const type = deviceManager.getCurrentDeviceTypeObject();
    const StringArray devs(type->getDeviceNames(true));
    for (int i = 0; i < devs.size(); ++i)
        selectAudioIPCombo->addItem (devs[i], i + 1);
    
    if (audioInputSource){
        int height = (int)(200*1.0/60*(audioInputSource->vc->pitch-36));
        //pitchDisplay->setBounds(900, 542-height, 40, height);
        // move forward the label and attach the final pitch
        for(int i = 0; i<330; i++)
        {
            if (i!=329){
                // move forward
                int temp = pitchContour[i+1]->getHeight();
                pitchContour[i]->setBounds(i*2+30, 700-temp, 2, temp);
            }
            else{
                pitchContour[i]->setBounds(i*2+30, 700-height, 2, height);
            }
            
        }
        
        pitchInfo->setText((String)audioInputSource->vc->pitch, NotificationType::sendNotification);
        techInfo->setText(audioInputSource->vc->classLabel, NotificationType::sendNotification);
        string templabel = audioInputSource->vc->classLabel;
        int tempChannel = 0;
        int tempNote = audioInputSource->vc->pitch;
        if (templabel == " ")  tempChannel = 0;
        else if (templabel == "pizzicato") tempChannel = 1;
        else if (templabel == "staccato") tempChannel = 2;
        else if (templabel == "trill") tempChannel = 3;
        else if (templabel == "vibrato") tempChannel = 4;
        else if (templabel == "tremolo") tempChannel = 5;
        if (note != tempNote && channel !=tempChannel)
        {
            channel = tempChannel;
            note = tempNote;
            if(tempNote!=0 && tempChannel!=0 && timerCount > 50)
            {
                midiOut->sendMidiOut(channel, note, 127);
                std::cout<<"send midi in channel "<<channel<<" note "<<note<<endl;
                //animation->addABall(note, channel);
                timerCount = 0;
            }
        }
    }
    
    
}

void MainComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == streamButton)
    {
        //[UserButtonCode_streamButton] -- add your button handler code here..
        audioInputSource = nullptr;
        audioInputSource = new AudioInputSource(deviceManager,0);
        audioInputSource->vc->threshold = thresSlider->getValue();
        updateToggleState();
        //[/UserButtonCode_streamButton]
    }
    else if (buttonThatWasClicked == fileButton)
    {
        //[UserButtonCode_fileButton] -- add your button handler code here..
        audioInputSource = nullptr;
        audioInputSource = new AudioInputSource(deviceManager,1);
        audioInputSource->vc->threshold = thresSlider->getValue();
        updateToggleState();
        FileChooser chooser (("Choose audio file to open"),File::nonexistent,"*",true);
        chooser.browseForFileToOpen();
        File audioFile = chooser.getResult();
        audioInputSource->setFile(audioFile);
        //[/UserButtonCode_fileButton]
    }
    else if (buttonThatWasClicked == legatoToggle)
    {
        //[UserButtonCode_legatoToggle] -- add your button handler code here..
        //[/UserButtonCode_legatoToggle]
    }
    else if (buttonThatWasClicked == pizzToggle)
    {
        updateToggleState();
        //[UserButtonCode_pizzToggle] -- add your button handler code here..
        //[/UserButtonCode_pizzToggle]
    }
    else if (buttonThatWasClicked == stacToggle)
    {
        updateToggleState();
        //[UserButtonCode_stacToggle] -- add your button handler code here..
        //[/UserButtonCode_stacToggle]
    }
    else if (buttonThatWasClicked == trillToggle)
    {
        updateToggleState();
        //[UserButtonCode_trillToggle] -- add your button handler code here..
        //[/UserButtonCode_trillToggle]
    }
    else if (buttonThatWasClicked == vibratoToggle)
    {
        updateToggleState();
    }
    else if (buttonThatWasClicked == tremoToggle)
    {
        updateToggleState();
    }
    else if (buttonThatWasClicked == playButton)
    {
        FileChooser chooser (("Choose audio file to open"),File::nonexistent,"*",true);
        chooser.browseForFileToOpen();
        currentFile = chooser.getResult();
    }
    else if (buttonThatWasClicked == resultButton)
    {
        //[UserButtonCode_resultButton] -- add your button handler code here..
        /*videoTrigger->loadMovie(File("/Fall2013/6201/project/violin-technique-detection/res/pizz.mp4"), false);
        videoTrigger->play();*/
        
        if  (currentFile.exists())
        {
            recorder->readSamplesFromFile(currentFile);
            recorder->visualization();
        }
        //[/UserButtonCode_resultButton]
    }
    else if (buttonThatWasClicked == recordButton)
    {
        //[UserButtonCode_recordButton] -- add your button handler code here..

        if (!recorder->isRecording())
        {
            FileChooser chooser (("Choose directory to record"),File::nonexistent,"*",true);
            chooser.browseForDirectory();
            File audioFile = File(chooser.getResult().getFullPathName()+"/test_"+Time::getCurrentTime().toString(false, true)+".wav");
            recorder->startRecording(audioFile);
            recordButton->setButtonText("stop");
        }
        else
        {
            recorder->stop();
            recordButton->setButtonText("record");
        }
    }
    
        //[/UserButtonCode_recordButton]
    

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void MainComponent::comboBoxChanged(ComboBox* comboBoxThatHasChanged)
{
    if (comboBoxThatHasChanged == nullptr)
        return;

    if(comboBoxThatHasChanged == selectAudioIPCombo) {
        AudioDeviceManager::AudioDeviceSetup config;
        deviceManager.getAudioDeviceSetup(config);
        String error;
        config.inputDeviceName = selectAudioIPCombo->getSelectedId() < 0 ? String::empty
        : selectAudioIPCombo->getText();
        error = deviceManager.setAudioDeviceSetup (config, true);
       // if (THINK_DEBUG) std::cout<<"select audio input: "<< selectAudioIPCombo->getText() << std::endl;
    }
}


void MainComponent::updateToggleState()
{
    if (audioInputSource){
        audioInputSource->vc->toggleState.clear();
        if (pizzToggle->getToggleState())
            audioInputSource->vc->toggleState.push_back(0);
        if (stacToggle->getToggleState())
            audioInputSource->vc->toggleState.push_back(1);
        if (tremoToggle->getToggleState())
            audioInputSource->vc->toggleState.push_back(2);
        if (trillToggle->getToggleState())
            audioInputSource->vc->toggleState.push_back(3);
        if (vibratoToggle->getToggleState())
            audioInputSource->vc->toggleState.push_back(4);
    }
}

//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="1" initialWidth="1024" initialHeight="768">
  <BACKGROUND backgroundColour="fff8ebeb">
    <IMAGE pos="864 2 128 124" resource="violin_png" opacity="0.792" mode="0"/>
    <TEXT pos="312 26 348 52" fill="solid: ff000000" hasStroke="0" text="Violin Technique Recognition"
          fontname="Arial" fontsize="25.2" bold="0" italic="0" justification="36"/>
    <IMAGE pos="324 172 75 50" resource="legato_png" opacity="1" mode="0"/>
    <IMAGE pos="328 250 60 60" resource="musicpizzicato_png" opacity="1"
           mode="0"/>
    <IMAGE pos="544 162 60 76" resource="musictrill_png" opacity="1" mode="0"/>
    <IMAGE pos="544 314 60 76" resource="musictremolo_png" opacity="1" mode="0"/>
    <IMAGE pos="336 330 44 52" resource="staccato_png" opacity="1" mode="0"/>
    <IMAGE pos="544 234 60 76" resource="musichalfnote_png" opacity="1"
           mode="0"/>
  </BACKGROUND>
  <GROUPCOMPONENT name="longer" id="8d09c1f5059b3db1" memberName="longerDetectionComponent"
                  virtualName="" explicitFocusOrder="0" pos="712 136 288 272" title="offline segmentation"
                  textpos="36"/>
  <GROUPCOMPONENT name="new group" id="1f6126618c6d34b4" memberName="techGroupComponent"
                  virtualName="" explicitFocusOrder="0" pos="208 136 472 272" title="techniques for detection"
                  textpos="36"/>
  <JUCERCOMP name="" id="17550f2957b480b7" memberName="videoTrigger" virtualName="QuickTimeMovieComponent"
             explicitFocusOrder="0" pos="0 464 616 304" sourceFile="" constructorParams=""/>
  <LABEL name="pitch" id="be57c969c4335408" memberName="pitchInfo" virtualName=""
         explicitFocusOrder="0" pos="640 488 296 64" bkgCol="ff808080"
         edTextCol="ff000000" edBkgCol="0" hiliteCol="40080808" labelText="pitch&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="26.2" bold="0" italic="0" justification="36"/>
  <JUCERCOMP name="" id="7ae7661960f1aa23" memberName="liveDisplay" virtualName="LiveAudioInputDisplayComp"
             explicitFocusOrder="0" pos="-8 408 1032 56" sourceFile="" constructorParams=""/>
  <LABEL name="tech" id="b2e3f89b287e736f" memberName="techInfo" virtualName=""
         explicitFocusOrder="0" pos="640 557 296 64" bkgCol="ff808080"
         edTextCol="ff000000" edBkgCol="0" labelText="Technique&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="24.2" bold="0" italic="0" justification="36"/>
  <LABEL name="mode" id="c59e6921b9d479f4" memberName="modeInfo" virtualName=""
         explicitFocusOrder="0" pos="640 626 296 64" bkgCol="ff808080"
         edTextCol="ff000000" edBkgCol="0" hiliteCol="40080808" labelText="mode"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="26.2" bold="0" italic="0" justification="36"/>
  <SLIDER name="threshold" id="544a432c5ddba7d6" memberName="thresSlider"
          virtualName="" explicitFocusOrder="0" pos="48 96 97 104" bkgcol="f3b3b3"
          thumbcol="ff1a1adf" rotarysliderfill="7f3a3aa3" textboxhighlight="40484857"
          min="0" max="10" int="0" style="IncDecButtons" textBoxPos="TextBoxRight"
          textBoxEditable="0" textBoxWidth="40" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="b95e02a169509f74" memberName="textThres"
         virtualName="" explicitFocusOrder="0" pos="40 32 112 56" edTextCol="ff000000"
         edBkgCol="0" labelText="sensitivity &#10;(1-10)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="19.6" bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="stream" id="15bea8c854a039e2" memberName="streamButton"
              virtualName="" explicitFocusOrder="0" pos="64 272 56 64" bgColOff="ffd2691e"
              bgColOn="ffff7f50" buttonText="live stream" connectedEdges="8"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="file" id="211bedc05b8830fa" memberName="fileButton" virtualName=""
              explicitFocusOrder="0" pos="64 336 56 59" bgColOff="ffd2691e"
              bgColOn="ffff7f50" buttonText="file input" connectedEdges="4"
              needsCallback="1" radioGroupId="0"/>
  <LABEL name="choose" id="cc9f35c8a2738847" memberName="chooseinput"
         virtualName="" explicitFocusOrder="0" pos="32 208 128 56" edTextCol="ff000000"
         edBkgCol="0" labelText="choose input&#10;(live / file)&#10;"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="19.6" bold="0" italic="0" justification="36"/>
  <TOGGLEBUTTON name="legato" id="377ce95d920178f4" memberName="legatoToggle"
                virtualName="" explicitFocusOrder="0" pos="248 176 72 32" buttonText="legato"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="pizz" id="2e3a3a14af51764d" memberName="pizzToggle" virtualName=""
                explicitFocusOrder="0" pos="248 264 80 24" buttonText="pizzicato"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="staccato" id="2c4af8e6055edca" memberName="stacToggle"
                virtualName="" explicitFocusOrder="0" pos="248 344 80 24" buttonText="staccato"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="trill" id="1bda8544f7f412af" memberName="trillToggle" virtualName=""
                explicitFocusOrder="0" pos="448 176 56 32" buttonText="trill"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="vibrato" id="ef2c33cba173715" memberName="vibratoToggle"
                virtualName="" explicitFocusOrder="0" pos="448 264 80 24" buttonText="vibrato"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="tremolo" id="e76c0bbb66e54910" memberName="tremoToggle"
                virtualName="" explicitFocusOrder="0" pos="448 344 80 24" buttonText="tremolo"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TEXTBUTTON name="play" id="ad7e2028f010f73e" memberName="playButton" virtualName=""
              explicitFocusOrder="0" pos="865 264 96 48" bgColOff="ffd2691e"
              buttonText="playback" connectedEdges="9" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="result" id="b0297a4fcbae9fcc" memberName="resultButton"
              virtualName="" explicitFocusOrder="0" pos="768 312 192 48" bgColOff="ffd2691e"
              buttonText="show segmentation" connectedEdges="4" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="record" id="7e0ca783b8ee7f93" memberName="recordButton"
              virtualName="" explicitFocusOrder="0" pos="769 264 96 48" bgColOff="ffd2691e"
              bgColOn="ffff7f50" buttonText="record" connectedEdges="10" needsCallback="1"
              radioGroupId="0"/>
  <LABEL name="choose" id="91ef262372ca418f" memberName="offlineStatusLabel"
         virtualName="" explicitFocusOrder="0" pos="728 168 256 80" edTextCol="ff000000"
         edBkgCol="0" labelText="record a piece and segment it wih detected techniques"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Arial" fontsize="17.2" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="a4940b27adc6a5ba" memberName="midislider"
          virtualName="" explicitFocusOrder="0" pos="648 704 280 48" min="55"
          max="90" int="1" style="LinearHorizontal" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: violin_png, 147794, "../res/violin.png"
static const unsigned char resource_MainComponent_violin_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,231,0,0,1,44,8,6,0,0,0,56,172,164,227,0,0,32,0,73,68,65,84,120,1,220,221,201,175,
173,107,146,30,244,88,125,191,118,223,157,246,182,121,179,207,202,172,198,13,182,171,202,22,152,70,200,72,6,100,132,177,16,120,0,3,6,102,100,25,203,46,97,166,150,152,32,11,70,12,44,49,64,72,48,193,54,
170,162,108,23,85,84,149,169,204,202,202,246,246,247,180,187,111,86,179,87,223,240,139,149,46,196,191,112,239,202,60,247,156,179,207,222,107,125,223,251,190,17,241,196,19,79,196,87,248,135,255,205,95,
91,207,190,255,42,206,202,235,248,104,50,141,155,155,136,249,237,77,252,27,111,85,163,48,29,197,213,213,36,254,194,123,221,152,45,199,241,27,31,86,98,213,93,197,94,220,197,79,238,34,190,89,24,199,123,
135,157,248,111,255,201,105,60,254,235,127,45,254,214,223,254,219,81,40,151,227,217,7,223,139,191,242,239,252,213,248,15,223,222,137,211,98,61,126,116,55,143,175,213,239,98,175,22,241,241,217,42,254,249,
77,49,254,242,59,235,120,171,93,140,127,250,217,58,222,241,245,110,57,226,110,186,142,87,195,136,227,150,107,40,173,226,176,219,136,209,116,17,255,231,164,19,255,240,127,254,159,226,228,201,187,241,209,
63,250,239,227,111,254,221,255,58,158,46,218,81,45,22,162,88,88,198,126,107,21,55,179,136,242,186,18,79,151,235,104,28,151,227,245,100,28,79,142,159,198,104,28,113,126,241,42,74,205,74,12,220,219,227,
163,122,252,111,159,156,197,191,251,55,254,118,252,213,191,254,159,196,79,190,247,221,248,247,255,210,95,137,191,252,173,183,162,212,169,198,171,171,65,116,198,203,248,168,214,136,237,202,78,44,214,171,
120,231,248,157,152,29,127,57,222,191,122,63,190,213,152,70,241,252,60,126,111,184,140,105,169,24,239,134,107,47,86,227,106,53,139,143,23,238,179,81,143,193,186,23,131,203,179,120,235,240,32,250,211,251,
232,79,10,241,184,181,136,39,245,82,204,71,189,248,176,183,136,78,97,21,181,198,58,150,243,106,188,213,176,0,229,97,220,184,215,167,59,219,81,156,151,227,147,251,65,52,167,211,56,218,62,136,235,90,61,
230,195,65,116,11,197,232,68,57,198,179,187,40,110,85,99,113,191,140,229,172,26,165,250,118,220,205,175,226,164,57,141,71,149,82,92,143,86,49,241,94,237,114,49,238,214,197,176,52,209,116,31,165,230,42,
6,131,136,155,251,114,204,103,197,120,176,61,139,163,86,49,138,197,136,78,183,20,163,251,85,140,23,171,216,111,180,99,181,88,196,168,48,141,134,61,122,121,177,140,157,7,229,88,140,230,113,82,43,199,116,
89,138,207,250,243,56,222,105,70,101,107,21,49,26,69,76,87,49,171,180,99,124,85,136,97,97,18,45,215,177,187,211,141,63,188,156,198,167,119,235,40,151,42,49,114,13,183,179,81,236,173,203,241,181,253,110,
60,140,251,248,120,88,137,106,125,63,158,185,202,245,193,78,204,253,220,236,220,123,140,110,227,173,7,133,216,159,108,199,119,237,241,118,167,16,111,53,183,226,163,131,159,139,242,170,20,255,241,227,207,
226,231,126,101,26,203,235,185,251,143,248,209,255,241,73,252,244,117,121,254,214,187,251,15,255,220,223,250,71,151,110,249,115,255,42,14,151,133,152,119,26,49,140,106,52,43,221,120,92,47,196,145,67,212,
170,149,162,189,90,69,189,48,139,198,106,29,37,59,60,89,141,227,190,16,177,44,119,226,110,81,137,247,167,197,40,204,231,185,47,177,94,172,25,74,33,42,118,122,62,185,143,251,251,69,220,218,196,252,181,
158,206,226,157,118,196,151,154,133,24,49,194,246,110,39,42,213,118,244,239,91,113,82,93,69,121,167,30,205,221,102,188,179,187,102,16,17,143,170,190,199,239,229,118,33,46,252,124,161,88,138,170,77,91,
187,14,167,37,214,149,134,247,104,68,189,221,136,117,97,237,64,216,135,97,33,246,202,243,152,181,23,81,41,204,99,107,85,143,186,207,154,174,231,81,94,212,162,52,109,71,177,206,136,27,85,6,95,117,248,150,
177,246,191,146,67,83,98,100,87,215,179,184,187,118,200,38,189,104,185,214,111,55,90,81,140,73,12,130,161,50,148,173,78,57,254,196,214,118,44,6,247,14,202,86,108,237,238,122,63,239,25,214,143,147,234,
45,231,225,143,81,115,184,139,215,87,113,195,32,207,134,179,152,142,110,162,206,97,60,239,47,227,71,253,169,235,169,199,163,246,78,212,27,221,88,173,11,140,169,24,143,220,244,91,157,90,124,115,183,110,
61,202,209,168,212,227,208,30,116,186,149,152,247,198,177,24,87,99,110,125,175,189,23,151,17,15,202,199,177,156,140,162,231,107,235,218,174,251,188,139,237,82,57,110,39,213,120,205,177,76,58,245,120,237,
0,151,187,109,134,86,143,118,181,18,53,134,186,156,214,226,102,89,140,254,106,30,205,210,60,134,171,66,156,15,214,140,190,28,221,195,90,212,218,19,6,230,61,23,211,88,207,230,156,95,49,26,59,213,152,86,
10,177,188,159,197,1,103,50,242,231,231,19,134,56,101,64,55,211,40,13,230,81,113,31,197,114,33,58,59,133,104,30,173,162,55,43,196,194,58,140,25,92,127,94,136,93,123,249,110,117,25,133,229,34,182,107,220,
75,179,17,119,165,220,223,106,172,139,28,126,171,18,15,219,181,248,211,237,147,88,44,59,113,58,91,68,119,127,43,106,205,221,56,159,223,197,25,167,80,172,236,69,207,121,219,171,55,226,29,107,181,223,232,
219,171,105,204,251,215,27,167,113,125,95,137,253,159,251,133,194,183,255,245,255,226,115,111,148,127,124,3,197,147,110,53,58,237,93,71,112,25,125,191,6,203,73,148,25,232,150,195,81,20,61,70,213,189,184,
42,55,99,208,155,197,203,193,109,196,197,40,126,174,186,136,63,193,78,46,71,235,248,148,215,181,206,49,154,117,88,40,195,89,79,227,205,119,150,81,111,149,121,232,219,152,47,239,226,190,91,143,143,231,
237,248,253,94,193,102,21,227,164,116,31,91,14,211,29,99,75,227,187,22,5,203,247,197,216,169,87,163,205,67,150,27,206,185,13,191,114,222,155,197,85,44,125,31,91,103,68,140,182,60,142,213,100,22,23,34,
213,22,131,93,242,252,163,221,66,20,252,204,90,228,155,249,166,159,244,87,241,99,6,121,119,51,142,202,124,26,171,173,53,227,185,179,151,14,249,180,25,227,233,36,250,222,111,237,51,86,140,106,157,81,165,
197,1,116,59,28,212,110,108,21,218,241,213,253,189,152,84,106,142,87,137,131,186,137,210,217,239,69,249,236,253,248,70,107,29,191,180,95,140,199,203,81,20,134,183,113,227,32,47,189,207,161,232,121,96,
237,122,211,94,220,175,26,177,207,64,246,173,203,118,113,63,246,203,181,232,48,194,215,227,251,24,49,212,90,113,17,187,171,1,103,38,130,249,158,193,244,154,179,43,69,115,121,20,183,247,227,248,254,120,
20,130,95,8,142,49,240,62,227,249,50,30,112,44,187,181,74,44,171,23,177,115,112,25,222,130,129,150,99,191,194,3,213,150,140,111,30,123,203,114,84,56,212,230,96,28,71,214,102,190,94,199,237,234,62,86,156,
42,15,17,11,142,144,157,122,31,70,212,133,78,170,133,184,29,174,69,171,53,231,211,228,48,234,81,186,95,135,160,27,130,171,200,185,142,54,167,247,6,167,187,191,215,228,76,32,11,81,237,217,169,8,60,91,198,
144,227,91,44,103,49,16,25,99,80,17,133,91,97,171,99,188,92,66,1,165,248,141,79,214,241,225,237,42,58,213,25,7,219,139,182,253,59,46,117,98,103,81,142,157,121,35,138,213,221,88,151,75,241,41,103,94,92,
55,162,95,189,225,212,185,195,189,189,40,216,139,155,235,94,220,186,182,74,19,18,90,86,156,129,73,240,84,209,141,243,141,179,89,113,50,227,219,231,113,245,163,235,184,119,174,154,111,125,121,248,254,241,
161,139,249,98,188,138,159,188,156,196,142,141,125,115,123,18,149,233,48,26,117,30,125,82,137,201,66,20,220,118,248,133,204,107,16,102,222,30,197,155,39,123,209,98,57,45,11,214,108,13,99,108,25,38,51,
27,158,107,97,35,151,235,69,44,24,77,181,241,166,191,150,163,227,223,155,37,94,110,61,139,81,113,55,110,10,173,152,20,183,162,90,120,0,6,214,29,252,113,148,218,109,145,174,17,165,202,50,62,185,169,68,
195,233,121,247,65,139,87,21,25,109,200,151,74,133,40,21,215,14,198,26,196,4,213,106,211,120,216,156,199,227,70,33,158,28,108,199,67,158,252,8,36,43,87,91,49,236,49,84,7,163,7,158,85,86,253,104,131,187,
5,144,113,25,149,168,48,142,57,239,94,24,142,194,111,177,44,56,41,126,207,215,60,35,127,121,1,33,244,227,0,188,255,185,162,247,95,194,192,32,228,178,186,142,111,62,56,136,111,1,148,128,87,76,68,138,201,
109,15,36,23,195,28,230,145,195,57,226,96,30,48,130,189,245,56,38,165,70,212,132,222,71,188,251,152,129,156,50,252,235,217,165,40,212,136,183,172,197,86,97,16,47,23,195,56,43,50,40,159,51,100,56,119,227,
90,244,6,229,248,172,119,11,214,47,227,162,215,7,127,43,49,156,219,7,215,112,82,31,251,217,101,60,181,14,165,217,96,19,149,183,150,91,241,118,181,22,171,233,88,84,181,206,53,200,103,103,177,65,54,3,80,
166,228,126,138,105,148,25,29,69,185,59,198,82,184,22,9,125,137,253,67,55,235,56,24,175,226,189,109,206,208,239,113,55,225,4,68,77,235,52,21,33,223,239,45,227,218,223,133,91,17,21,134,128,2,62,189,89,
196,249,4,82,114,45,101,152,161,4,110,159,15,75,113,150,78,23,2,219,218,45,199,0,180,170,88,219,226,78,39,94,78,172,169,245,220,94,62,136,69,28,68,207,217,249,193,188,23,61,247,190,223,44,66,103,133,56,
149,46,157,79,43,113,11,81,252,14,244,114,203,224,191,90,154,68,21,130,121,41,56,92,213,182,227,132,161,62,168,21,227,162,38,77,58,123,21,215,159,62,139,194,174,123,172,215,161,162,167,177,20,113,151,
91,251,241,71,63,121,249,159,253,252,201,207,95,111,54,245,11,240,159,114,109,56,141,253,167,91,241,236,85,147,167,122,25,157,163,82,116,219,227,184,185,154,109,32,102,23,236,171,52,75,241,168,198,213,
46,186,241,131,37,239,191,246,61,229,118,188,91,185,227,133,69,75,135,188,89,25,70,211,169,95,20,108,202,203,31,91,154,101,188,115,248,48,250,60,245,128,193,172,229,128,91,235,65,124,231,141,199,60,52,
200,210,251,56,30,148,22,140,93,206,83,154,242,184,227,184,152,151,98,219,65,232,212,23,177,116,96,155,219,141,120,176,53,143,7,175,3,116,90,58,224,21,145,138,247,230,60,182,231,147,152,212,94,71,25,92,
76,47,255,233,124,16,245,69,49,222,112,24,223,219,7,211,93,83,9,116,174,13,199,113,176,2,15,69,158,65,101,16,141,70,135,135,111,196,162,239,132,58,60,149,170,13,22,65,210,41,119,91,14,1,131,41,131,126,
103,16,238,92,164,137,49,104,0,238,78,79,142,132,237,118,252,238,235,171,56,173,1,108,179,153,40,222,142,157,86,23,10,128,32,134,189,184,92,77,99,6,238,231,189,223,141,103,113,200,41,172,10,125,17,66,
174,235,123,90,133,69,120,199,152,202,173,143,249,134,45,169,102,158,164,107,7,178,205,144,31,181,166,113,56,106,198,90,52,219,114,175,183,243,89,44,43,162,10,88,255,138,51,43,129,134,53,215,220,227,132,
214,197,137,131,191,138,97,123,30,59,51,80,184,236,51,193,188,149,181,144,34,198,22,99,60,118,224,47,239,135,28,165,247,3,149,135,194,237,29,103,118,35,92,119,24,198,100,38,106,250,254,33,100,242,47,126,
56,140,17,163,108,186,166,229,104,17,117,183,125,208,40,197,11,240,127,105,189,93,178,80,42,234,22,228,191,197,177,232,87,136,54,248,186,148,247,219,54,206,119,29,231,119,227,184,245,61,49,46,196,125,
169,201,129,223,71,107,217,140,239,14,134,113,59,30,199,254,86,41,222,46,214,236,91,35,62,181,182,243,129,8,14,45,189,17,45,41,203,36,150,80,197,3,247,112,48,141,232,249,247,47,129,14,183,174,29,182,182,
110,96,59,14,100,135,177,63,56,224,24,203,249,253,114,235,225,53,200,43,50,175,183,164,16,247,243,66,65,148,248,130,188,202,55,32,70,255,140,129,46,107,113,176,191,31,111,118,186,22,120,16,119,242,163,
109,209,97,105,3,86,140,107,124,203,179,202,127,106,54,125,52,106,196,174,168,245,45,240,247,27,79,246,226,247,118,46,54,81,116,230,112,150,192,148,65,255,110,243,51,69,16,115,175,80,225,53,243,128,141,
227,43,141,101,220,46,174,226,253,211,203,120,236,239,69,27,219,64,110,220,49,234,31,242,210,35,81,233,96,205,40,247,119,228,20,172,5,105,114,7,74,245,88,255,207,130,156,200,37,74,205,144,25,187,13,185,
205,100,194,128,24,170,72,94,202,104,32,23,45,215,86,209,146,111,45,22,247,177,70,152,172,202,149,56,134,0,214,179,82,76,221,203,110,219,33,71,44,196,20,156,21,50,249,248,56,114,248,75,162,244,205,106,
59,234,149,75,247,224,144,238,159,196,19,136,161,54,24,49,152,121,188,158,242,214,125,158,157,117,117,23,141,56,146,107,127,153,145,158,200,151,206,46,239,227,35,239,95,170,30,200,223,144,90,183,195,120,
28,211,216,195,114,237,32,86,10,19,215,209,62,141,162,195,255,177,40,54,3,115,219,179,90,44,122,195,184,238,250,124,7,113,159,33,148,88,241,18,228,223,107,61,12,1,59,198,227,97,148,68,191,129,165,56,180,
214,19,7,253,181,8,253,86,101,28,67,196,217,170,42,247,69,40,21,56,170,123,107,81,147,211,239,181,154,49,131,94,30,136,210,59,210,143,83,150,51,150,195,205,231,163,77,254,60,144,11,39,114,128,20,145,85,
17,51,240,135,239,141,69,70,101,171,92,241,89,115,70,178,35,130,54,17,80,69,206,234,212,251,173,253,89,138,189,129,150,77,123,85,117,47,69,6,213,96,197,11,176,183,47,226,95,61,191,1,93,107,97,203,99,121,
123,25,239,88,251,5,39,242,83,142,236,28,132,63,46,52,125,246,18,74,234,130,195,211,184,96,176,111,53,78,162,32,2,94,222,221,70,199,122,159,108,237,70,195,197,221,9,239,21,107,141,246,226,116,70,210,164,
61,196,95,7,68,134,82,142,24,35,8,176,90,181,57,18,41,143,247,95,120,143,47,63,145,219,124,129,94,229,75,176,8,136,15,40,209,193,221,149,151,221,98,1,87,114,144,19,168,238,50,179,208,232,148,223,136,75,
155,255,177,3,185,200,3,212,114,192,27,168,144,107,73,191,200,52,113,200,11,224,103,66,79,251,108,67,139,137,166,226,217,120,18,221,234,72,128,114,152,16,75,37,14,96,49,94,196,222,160,24,95,245,153,59,
78,201,165,228,234,145,131,113,207,0,147,162,41,219,232,1,0,57,195,138,214,69,184,171,254,64,78,198,216,18,42,121,207,169,131,51,147,87,177,132,184,42,98,16,69,156,59,30,244,30,76,114,206,99,181,219,142,
115,17,162,227,103,66,100,95,46,219,16,193,36,234,140,184,233,144,213,167,231,242,27,185,33,67,155,138,48,233,102,207,157,166,71,88,205,185,72,213,7,211,243,224,62,64,18,237,184,150,130,136,94,219,5,173,
16,28,21,95,59,134,36,222,61,1,119,239,10,241,241,29,226,199,247,175,25,219,3,167,122,23,108,127,49,27,199,59,5,159,59,239,202,107,27,81,112,152,150,24,219,45,215,214,42,202,147,93,219,190,40,55,169,86,
99,194,145,237,201,209,30,118,155,121,234,55,215,117,219,222,138,31,49,232,190,40,241,11,203,110,148,70,156,12,180,210,116,48,39,171,5,163,117,197,22,98,230,224,31,110,45,68,106,4,138,72,87,218,18,169,
224,219,69,15,139,138,188,170,202,199,46,240,4,193,193,214,228,135,99,228,209,196,166,116,161,4,65,51,14,24,80,61,145,142,53,40,91,251,246,30,162,76,254,60,28,67,47,156,202,72,46,158,145,172,101,49,234,
62,47,247,133,141,196,11,60,76,67,10,50,226,44,128,1,14,189,140,4,99,224,67,164,13,162,175,38,223,159,217,147,157,102,91,10,49,140,79,188,247,122,85,140,237,122,133,99,1,77,39,55,177,43,210,127,165,116,
24,135,246,236,133,92,17,171,16,221,238,50,94,221,219,59,95,251,105,239,126,147,47,255,169,163,131,104,9,20,99,159,189,87,182,158,133,158,212,161,17,171,139,139,88,131,214,43,247,51,93,110,35,228,220,
215,87,126,41,190,254,167,191,105,149,255,254,23,198,60,203,111,63,149,160,63,168,198,197,103,153,75,93,196,217,53,211,88,204,44,194,32,30,34,109,158,236,109,49,190,91,158,12,148,178,169,29,27,83,183,
25,51,57,202,117,46,58,232,180,199,3,87,211,184,252,123,130,186,178,195,202,82,145,68,235,141,129,205,150,202,0,114,34,167,47,106,34,213,99,81,162,38,42,226,91,226,73,3,164,115,90,174,185,201,98,179,110,
193,39,177,112,192,123,242,144,177,67,222,25,97,14,163,233,189,121,104,159,91,44,183,28,152,90,156,222,174,149,14,90,34,198,32,38,114,166,123,7,40,25,201,211,187,129,77,95,241,183,136,46,159,181,70,210,
92,250,252,131,121,230,158,216,214,184,5,69,23,14,154,104,0,17,212,120,220,147,102,230,174,171,88,33,92,62,21,73,202,190,247,147,217,235,248,177,123,124,192,41,76,16,50,85,7,188,4,90,127,69,153,103,23,
124,254,196,215,246,90,59,113,2,78,223,148,45,128,156,124,119,122,20,144,90,92,59,96,151,61,135,220,253,117,48,185,207,96,230,169,92,172,207,17,21,24,120,161,133,5,246,249,123,77,17,200,113,138,25,136,
166,116,84,23,193,107,144,204,43,172,236,90,100,41,48,140,61,119,127,47,250,189,148,131,46,234,247,114,181,82,12,7,156,162,247,102,37,34,199,61,72,60,179,220,73,182,53,217,45,67,22,117,150,34,244,189,
40,62,67,168,21,64,208,245,205,18,204,182,5,114,204,159,246,252,174,20,118,44,18,14,241,120,45,251,82,24,33,140,108,96,29,106,88,137,180,215,55,32,227,120,30,143,68,188,49,103,88,19,45,159,245,229,158,
34,53,184,179,113,190,130,172,117,4,229,65,255,9,86,182,117,125,31,159,189,146,227,50,224,182,53,152,112,48,237,202,81,140,68,249,177,20,166,91,71,24,213,68,113,103,230,20,1,135,235,138,87,151,206,13,
168,254,96,159,227,246,245,107,17,248,252,30,187,251,104,59,14,79,30,196,103,47,175,99,39,79,77,150,103,236,241,211,157,117,60,126,162,180,119,121,30,3,72,39,209,210,126,71,201,232,226,131,223,120,243,
225,95,252,117,151,244,133,121,149,239,173,196,170,168,102,104,241,210,96,78,90,187,241,49,40,55,176,113,183,173,90,156,159,206,120,222,106,92,79,27,60,244,52,78,64,146,161,60,181,131,8,169,148,246,162,
166,12,83,23,178,56,50,11,8,62,34,109,158,48,248,3,236,223,129,131,191,112,240,202,181,125,112,240,46,126,228,231,243,112,151,193,179,87,72,129,42,111,186,99,195,74,34,197,142,188,235,153,67,208,182,1,
219,34,78,197,239,21,16,233,237,157,45,76,174,152,234,123,188,249,38,122,21,24,106,183,225,103,192,228,147,101,53,46,69,194,31,51,208,107,121,237,136,117,212,31,96,2,229,54,173,113,5,236,195,116,214,106,
241,74,16,41,86,154,209,170,110,139,42,231,28,7,127,237,240,21,213,101,15,121,252,36,62,154,34,232,155,21,23,216,26,59,164,160,123,165,35,226,214,226,186,173,212,144,37,3,145,175,35,2,55,132,92,164,98,
44,93,195,202,129,238,48,168,89,245,4,195,122,31,149,197,45,134,185,140,33,102,204,139,190,186,171,242,17,230,187,138,81,93,201,247,86,242,201,204,138,218,96,121,217,61,246,56,131,254,208,225,196,134,
74,159,227,30,147,124,162,204,113,210,104,250,30,208,18,44,156,47,154,209,3,111,11,34,123,105,146,229,27,134,12,186,247,48,224,3,238,102,191,113,19,23,246,232,149,72,226,86,193,99,46,146,225,151,221,251,
172,55,137,21,232,87,149,239,213,193,255,31,92,99,174,237,247,47,158,112,134,139,81,220,187,190,86,123,21,83,198,218,112,125,105,132,69,223,247,182,164,184,96,253,111,18,254,67,38,108,32,134,246,97,36,
175,124,204,153,110,139,192,3,14,248,18,129,95,134,193,147,34,250,236,202,186,88,215,39,245,90,92,205,176,226,28,121,173,132,100,84,27,223,45,61,68,16,22,93,111,11,129,211,149,147,202,81,173,67,193,253,
29,112,0,11,36,193,98,122,25,15,22,251,74,107,25,16,202,241,253,211,81,156,45,145,131,156,199,65,213,5,112,74,143,235,175,68,101,206,7,38,95,12,46,227,179,15,95,196,215,127,229,87,227,96,251,173,155,66,
225,219,238,226,139,243,146,84,200,49,220,240,253,244,99,204,215,44,222,118,224,223,205,154,151,58,167,204,49,94,139,133,175,65,179,161,50,192,162,152,70,85,70,161,35,18,150,251,177,188,25,69,179,247,
44,42,188,93,91,113,58,107,29,83,222,178,52,255,56,6,242,160,215,96,240,76,212,216,95,223,133,32,26,87,153,225,77,65,98,145,181,33,234,118,42,34,206,182,77,202,159,243,30,7,190,255,13,165,157,227,3,223,
195,251,183,228,151,123,74,50,133,172,153,41,139,100,238,187,245,16,236,60,146,235,170,141,118,28,174,165,188,175,143,201,19,216,196,197,98,60,5,179,138,12,255,129,232,121,36,7,43,99,107,17,161,49,194,
220,206,65,236,182,232,52,229,132,138,219,160,100,194,86,145,110,230,251,190,15,50,158,186,214,57,54,241,90,20,169,205,212,57,231,106,154,34,95,93,36,41,108,96,33,35,148,39,21,234,61,53,68,134,45,71,187,
19,9,27,91,8,139,123,68,142,58,30,172,26,117,133,245,119,65,243,71,222,187,168,70,185,199,217,44,89,100,30,102,41,42,6,22,28,243,43,141,148,255,139,3,48,178,98,13,46,16,61,207,213,132,107,243,150,40,42,
146,48,212,38,131,104,41,79,61,187,7,57,149,44,242,251,27,187,1,217,140,162,139,233,172,249,247,194,106,63,230,144,201,253,210,117,113,114,21,181,196,5,2,239,14,113,87,242,33,111,28,150,98,139,161,179,
209,77,193,254,1,177,66,17,196,159,49,230,38,167,213,187,44,34,137,160,28,123,190,227,251,186,109,12,43,54,244,104,191,21,79,173,99,205,126,207,108,85,25,195,187,222,98,68,206,204,68,125,244,128,83,238,
30,33,12,165,49,121,63,69,103,165,13,110,207,146,161,173,207,176,234,16,25,134,183,238,107,111,118,56,174,82,31,167,180,136,175,237,76,226,41,6,246,226,2,127,96,15,215,91,99,247,61,140,30,207,178,191,
191,136,183,182,48,250,205,195,13,83,189,194,118,223,97,136,39,114,206,23,247,253,168,227,47,20,93,148,205,198,200,75,70,191,83,140,170,8,123,127,244,70,98,137,47,212,171,152,17,111,191,203,123,238,236,
50,210,195,248,67,244,253,249,18,155,57,224,57,41,6,18,219,63,147,179,85,166,45,48,81,173,43,97,167,141,77,207,153,48,47,169,186,189,134,232,115,124,228,239,149,141,18,164,194,32,26,114,80,231,153,247,
220,145,139,129,34,232,241,47,57,56,75,135,32,163,214,24,221,95,31,149,226,74,41,231,131,115,30,114,204,130,228,31,73,144,158,59,227,201,238,239,85,212,177,74,156,97,77,46,11,255,217,39,133,127,7,204,
54,92,170,5,46,93,219,9,102,245,17,167,250,115,188,249,47,31,23,227,16,249,50,191,93,196,99,2,134,110,81,132,247,30,199,14,221,227,141,161,16,4,200,201,154,162,123,33,161,232,38,227,68,134,112,62,71,60,
127,83,36,59,87,2,202,34,122,77,132,124,226,251,186,179,243,168,51,140,25,195,131,182,145,43,8,52,63,218,5,239,154,74,9,199,68,3,37,208,249,186,124,234,240,13,227,145,114,194,78,83,9,161,63,65,230,20,
226,213,250,54,30,96,84,223,82,143,149,156,198,83,81,233,29,215,179,237,87,195,13,109,49,214,90,230,160,224,105,73,73,171,236,107,109,135,29,199,139,169,196,38,203,113,27,28,225,49,241,197,67,121,97,121,
15,236,68,201,22,65,240,197,42,69,9,67,48,191,197,25,117,227,61,14,82,108,118,39,67,36,89,162,25,70,3,234,39,131,251,66,174,175,60,28,111,218,163,109,4,87,79,158,218,231,49,175,229,149,99,198,119,148,
73,113,162,153,125,112,216,62,124,244,90,180,165,230,121,72,201,81,177,30,170,97,174,185,140,192,129,148,212,122,135,246,180,34,21,216,229,24,7,246,52,249,134,61,144,251,94,18,123,208,42,196,151,31,206,
226,202,231,140,214,45,229,41,209,210,254,221,139,216,15,82,216,224,205,110,229,168,231,147,97,188,130,102,10,101,42,39,255,62,247,222,35,36,86,125,121,1,57,203,43,221,205,154,131,57,238,238,199,13,52,
119,243,234,131,56,122,108,189,190,116,24,75,14,229,197,251,119,210,159,131,248,201,139,187,217,155,111,126,235,15,191,80,150,233,102,138,152,108,117,171,253,168,175,177,100,252,218,7,118,48,73,142,253,
45,201,184,136,53,80,223,98,43,216,236,90,188,91,234,42,234,131,100,32,235,209,195,97,236,236,49,166,238,49,230,212,134,85,182,45,38,120,196,232,10,55,191,45,114,36,28,154,43,121,240,116,138,242,79,108,
242,47,217,152,55,183,70,160,206,2,105,81,140,45,80,174,160,78,118,232,115,218,114,144,23,32,214,220,102,53,121,222,66,23,188,116,128,43,224,243,49,226,162,9,6,165,2,41,237,105,142,215,23,160,192,113,
185,6,214,112,203,129,126,194,219,183,144,176,119,46,246,150,130,101,56,33,163,27,109,139,46,200,33,62,56,35,222,122,201,239,22,70,14,5,207,43,18,231,123,229,91,62,70,67,254,28,104,246,14,39,83,162,46,
218,5,199,30,149,239,227,145,200,177,183,219,141,183,149,44,42,107,204,41,230,178,234,58,106,115,44,233,120,42,23,18,97,213,54,119,49,207,79,124,54,0,43,74,12,163,179,91,138,27,145,172,79,206,214,222,
173,41,221,248,124,255,58,4,199,241,37,241,24,35,189,37,97,115,62,227,78,62,166,210,0,154,139,70,245,57,136,170,188,84,39,155,43,111,129,193,237,184,3,57,73,20,98,139,99,172,213,30,113,14,91,49,92,200,
205,40,5,138,24,226,185,131,61,173,193,216,156,192,158,60,175,103,109,62,149,207,246,33,157,82,159,1,33,223,198,179,138,210,11,164,219,81,216,151,232,255,88,142,216,194,0,78,172,235,11,247,95,98,200,91,
91,152,110,44,120,79,121,119,200,56,51,26,14,33,149,151,12,180,70,169,52,243,247,75,251,187,100,88,83,31,183,227,179,150,190,239,236,98,14,226,19,26,48,224,94,150,121,236,127,69,164,123,246,130,99,133,
142,14,187,51,254,27,28,159,237,199,33,146,44,165,150,231,131,41,134,251,38,42,214,247,9,212,80,246,62,131,250,35,106,167,253,120,245,170,20,239,223,170,20,84,170,28,23,178,201,231,110,73,143,58,74,85,
187,144,71,77,110,202,131,57,11,82,142,253,247,98,84,123,16,63,126,62,190,125,248,240,107,127,247,11,103,156,75,134,49,60,195,98,130,71,28,125,188,3,106,190,225,144,78,28,226,17,195,149,24,42,46,75,192,
121,196,201,194,33,201,175,241,146,3,185,199,43,222,126,81,71,102,248,210,157,136,146,74,153,164,98,198,55,109,37,19,12,160,67,253,212,225,108,118,42,209,109,54,99,255,144,215,222,7,157,212,53,207,149,
99,254,159,52,144,38,8,42,170,52,228,166,107,139,126,107,163,166,222,167,163,158,57,151,163,150,111,169,134,108,114,202,244,126,246,74,38,24,249,225,243,100,114,162,142,189,114,200,46,120,239,2,213,201,
215,14,155,88,231,82,124,228,228,191,198,60,246,125,239,170,80,139,221,38,17,1,70,245,188,78,204,32,129,154,200,85,129,52,239,208,138,71,91,111,198,153,251,59,167,128,234,202,111,186,160,123,95,57,232,
250,150,72,128,114,103,52,87,50,81,155,61,86,119,221,81,132,107,54,73,252,246,39,113,212,233,145,35,14,92,47,184,173,52,210,42,236,109,164,130,45,110,174,206,97,220,15,239,228,215,136,39,198,52,80,38,
72,69,211,34,11,247,179,251,77,36,126,192,40,230,162,215,11,215,126,235,122,32,64,70,233,224,33,135,102,112,228,142,50,69,11,212,163,226,181,182,87,162,215,21,245,86,35,102,238,97,37,253,168,117,182,165,
3,164,135,4,179,9,169,51,226,149,25,221,112,208,138,222,93,49,218,219,85,132,83,58,64,232,200,126,224,130,136,34,228,106,162,247,4,153,93,21,53,223,73,214,29,10,90,65,30,77,95,71,27,72,81,74,72,33,209,
49,183,154,209,162,127,226,57,130,40,107,152,117,226,134,44,185,12,28,150,170,232,157,229,50,182,25,175,6,246,221,58,52,188,143,176,46,106,211,194,242,228,223,105,236,19,37,100,57,107,28,223,172,13,57,
239,94,28,113,112,111,238,147,22,202,53,167,12,241,51,121,113,147,67,249,10,231,181,227,107,235,218,177,52,11,49,217,123,30,79,48,238,77,191,47,201,248,158,66,15,117,44,253,244,242,84,137,239,66,173,246,
2,39,112,29,143,119,231,133,223,252,205,95,115,18,190,88,175,226,184,116,176,145,174,169,68,218,130,90,60,148,227,101,110,144,204,217,18,25,114,192,235,61,84,71,74,50,163,87,31,248,30,245,78,94,121,153,
197,232,59,240,228,249,41,207,187,67,228,253,54,50,54,205,212,193,105,29,198,185,13,223,219,105,96,4,27,241,112,135,50,200,225,185,148,203,13,78,105,78,193,157,63,0,105,206,253,61,117,179,247,52,147,219,
72,147,239,144,223,149,250,189,120,126,62,193,169,166,17,182,227,35,202,245,5,66,162,196,96,83,102,87,160,192,41,250,181,148,188,65,163,113,36,26,214,225,182,199,173,106,188,157,240,14,69,250,88,62,90,
198,238,77,192,232,42,199,208,220,175,50,216,22,169,91,131,209,99,253,24,226,171,241,41,153,89,194,229,106,156,202,25,79,193,229,42,120,95,35,65,28,33,35,78,69,160,57,134,102,116,94,143,59,240,98,58,235,
201,237,146,184,72,38,244,38,22,34,61,123,219,232,83,135,162,44,236,71,26,215,164,196,17,161,149,142,14,72,214,90,85,206,203,129,191,25,98,107,69,150,142,252,180,180,98,106,140,191,76,95,59,69,70,17,14,
57,96,169,63,5,209,25,93,139,163,41,231,193,151,161,175,169,129,82,100,222,37,156,96,35,148,76,211,24,223,95,40,222,247,25,159,28,79,68,169,181,25,169,18,10,201,176,26,52,131,22,77,219,28,217,152,108,
241,156,18,41,32,149,153,92,113,192,130,10,88,172,249,149,82,22,251,201,210,85,195,154,127,137,158,55,81,75,159,150,182,129,164,106,119,228,162,174,37,181,188,5,95,91,222,34,121,92,67,117,175,180,137,
122,168,179,120,45,223,252,169,61,147,219,64,40,8,38,236,111,158,15,219,25,151,169,225,197,240,207,83,32,128,85,188,65,158,85,69,247,21,231,255,178,116,205,240,103,162,37,146,231,150,120,255,6,170,82,
251,220,119,241,15,9,112,231,55,47,55,40,225,169,50,90,66,254,42,182,250,233,225,211,56,36,33,173,113,42,87,189,79,73,57,207,53,40,60,136,231,31,183,227,15,254,240,21,21,209,78,28,191,245,240,139,101,
149,255,242,110,138,45,112,109,230,198,7,72,155,50,82,100,185,247,78,236,116,118,48,173,215,54,155,40,0,163,122,192,157,238,43,210,31,129,174,39,11,145,102,123,63,14,68,196,244,236,67,208,227,172,175,
212,114,253,12,17,147,62,213,255,28,140,167,188,227,174,136,83,7,183,170,247,231,113,115,171,60,130,240,41,118,230,234,150,171,120,168,198,247,11,143,65,41,69,233,107,240,55,37,116,197,84,43,241,240,37,
112,110,158,197,246,237,221,120,244,104,31,212,116,16,29,38,111,157,255,223,188,154,54,189,35,79,41,136,206,75,6,144,149,154,107,6,244,234,234,74,55,199,36,190,198,91,63,1,57,91,216,160,217,232,103,101,
134,190,58,235,222,122,135,42,5,188,229,169,105,196,17,36,160,87,249,28,171,90,85,130,217,65,64,213,24,3,40,125,172,192,190,61,5,247,52,1,128,201,35,107,51,159,158,197,35,132,213,33,99,191,166,100,233,
221,244,98,187,175,36,128,173,93,250,204,100,145,43,152,85,226,21,236,97,157,147,144,187,139,138,89,210,120,44,108,181,165,11,211,100,103,51,15,100,56,87,162,187,70,150,56,148,159,171,16,66,15,25,73,9,
20,64,79,74,188,40,98,112,74,14,238,216,90,14,25,200,72,29,181,234,90,74,84,9,21,140,247,221,224,142,195,24,16,116,32,183,56,28,104,89,30,136,197,166,240,202,232,149,101,78,168,52,184,21,73,50,18,74,84,
61,0,191,183,50,127,100,84,85,6,244,90,218,242,74,254,121,7,61,205,48,175,115,82,188,173,114,58,22,41,70,38,254,174,101,66,245,212,31,234,18,146,83,118,9,225,203,180,204,79,58,140,253,122,26,47,46,213,
80,125,91,29,194,26,59,27,119,82,152,87,195,68,7,20,78,88,218,215,53,80,93,98,253,83,247,254,172,179,31,123,157,119,227,39,24,245,127,76,117,116,42,77,122,188,189,64,2,114,48,144,218,103,12,252,21,111,
181,76,195,68,46,237,29,236,197,148,243,188,167,240,90,77,236,171,92,182,6,238,102,77,253,209,87,142,163,112,242,141,248,163,11,144,120,249,176,246,43,191,242,133,67,181,108,3,120,41,167,1,34,35,42,40,
248,57,146,134,130,46,142,120,246,241,250,28,148,193,138,41,0,215,69,178,54,207,126,97,35,110,123,60,186,29,57,218,63,138,109,37,131,87,171,107,135,231,108,115,56,171,162,218,228,236,35,249,94,234,48,
171,241,38,131,149,137,137,144,96,95,181,31,135,12,253,68,173,171,234,239,75,173,100,119,200,155,29,17,101,169,140,162,148,135,178,167,240,1,141,158,174,148,88,228,82,77,81,41,107,169,115,112,51,133,234,
117,198,181,47,66,53,40,68,182,228,32,43,229,16,31,169,134,198,200,228,39,51,221,39,67,204,205,202,251,21,119,72,11,17,42,41,97,187,78,81,58,34,171,160,30,249,152,65,149,176,131,45,4,206,122,197,24,17,
39,131,107,122,214,146,146,18,209,193,118,11,4,133,24,82,62,56,152,13,213,117,251,16,128,26,233,221,41,38,18,121,228,0,53,228,93,215,147,173,77,173,54,197,245,163,241,96,35,42,63,18,90,22,69,194,13,180,
12,25,45,125,42,242,139,129,117,169,121,102,19,105,1,1,122,91,244,76,21,146,165,73,27,34,33,36,207,19,141,102,12,123,203,94,220,148,132,34,198,118,136,160,154,130,172,13,6,158,37,142,42,244,81,70,192,
136,211,81,209,22,87,98,136,157,68,17,156,215,146,209,39,57,55,230,68,10,14,249,76,121,70,74,79,233,147,181,203,41,24,91,136,215,119,43,17,73,132,205,202,145,53,158,48,254,101,138,66,176,213,13,198,120,
169,204,83,145,75,110,137,116,51,231,97,102,95,22,88,244,162,51,80,134,23,209,105,79,0,0,32,0,73,68,65,84,36,10,59,224,46,135,86,240,115,45,76,45,109,4,150,149,210,136,179,121,27,188,205,42,114,199,53,
150,56,190,17,212,179,34,190,80,103,137,30,180,241,253,123,196,92,227,32,182,168,162,158,35,7,183,182,143,228,160,28,44,7,122,131,164,187,150,15,175,117,161,188,35,106,103,75,216,156,129,30,62,250,58,
120,188,138,23,223,255,173,248,204,121,250,246,147,71,162,61,102,124,125,31,195,254,13,39,176,151,137,122,116,59,91,255,220,146,252,113,222,243,51,239,253,5,248,111,241,132,32,160,193,227,175,73,220,26,
52,143,121,16,103,169,246,231,89,27,106,126,199,14,227,113,119,76,150,117,173,182,68,38,230,176,53,183,37,253,71,60,100,239,26,158,153,198,49,117,202,238,214,17,47,254,179,184,150,224,118,140,97,61,1,
21,135,179,54,143,45,7,21,173,250,216,189,132,78,15,16,38,101,189,130,221,60,56,14,219,4,132,218,119,88,186,60,252,189,50,71,137,177,111,171,245,117,168,138,150,54,171,200,208,74,106,124,138,146,126,117,
227,13,5,239,55,69,110,77,13,81,212,34,86,116,168,186,14,234,26,97,83,71,231,102,4,27,48,130,241,242,220,215,8,25,144,41,85,95,75,41,225,120,14,6,83,15,213,6,175,24,251,207,234,166,135,132,211,187,44,
169,128,136,105,202,117,202,52,176,197,193,17,152,165,148,160,14,219,234,110,137,74,73,126,29,69,191,72,59,76,164,48,165,51,222,150,15,226,194,212,49,65,71,247,211,235,63,143,58,232,95,102,8,93,93,49,
59,252,63,87,31,67,76,85,201,122,236,58,188,91,140,178,166,134,90,91,208,23,39,169,229,158,159,97,152,39,52,180,37,14,161,6,118,31,90,199,100,190,201,34,176,159,202,8,34,47,93,127,12,56,147,43,174,174,
75,161,213,94,41,65,48,224,59,135,255,67,229,136,107,209,229,2,234,184,129,112,46,250,82,16,221,59,185,100,13,6,223,240,94,196,63,162,191,245,181,230,151,92,242,57,195,183,123,33,80,110,78,245,136,163,
187,103,180,183,236,233,227,23,72,192,12,135,196,239,247,23,51,37,37,206,207,173,12,68,237,239,178,70,77,36,80,149,18,71,58,25,14,102,143,83,221,146,70,60,18,177,191,164,198,185,95,187,167,64,34,14,89,
238,184,198,86,252,33,7,124,174,76,180,79,254,153,215,220,218,234,114,112,212,82,238,134,199,193,38,227,156,165,58,59,246,187,134,172,187,18,36,70,56,138,250,236,51,53,239,83,14,1,162,154,15,227,79,17,
97,52,42,175,99,126,182,136,31,158,106,91,188,104,75,101,202,241,235,255,224,191,251,59,52,181,121,236,190,80,175,242,0,22,234,157,247,148,5,212,54,229,30,232,177,56,253,136,183,174,136,166,157,69,76,
149,5,146,177,237,88,132,18,200,117,71,208,188,44,170,86,49,154,154,50,66,22,198,91,216,206,138,226,254,2,147,151,148,122,151,20,229,161,205,47,100,71,159,188,165,134,188,161,157,209,185,193,40,145,59,
101,16,231,3,48,234,91,18,169,154,188,207,121,194,8,58,37,160,220,94,22,249,229,120,115,202,155,57,111,91,148,51,86,25,167,186,193,38,231,172,150,63,150,151,245,99,143,152,182,172,64,157,37,24,21,7,165,
139,118,188,166,106,154,214,178,176,174,145,120,181,131,234,65,86,249,199,94,10,8,136,43,246,93,47,70,198,129,34,19,123,241,66,228,80,147,61,64,134,32,192,174,69,219,93,76,226,177,107,172,74,213,166,234,
124,43,165,152,251,129,195,68,137,51,167,184,233,243,240,83,117,212,51,134,86,108,93,18,44,168,39,138,20,19,145,184,206,57,173,27,61,77,209,137,241,186,209,162,255,188,3,189,91,167,136,26,240,243,66,36,
120,87,189,175,207,216,198,12,109,147,211,249,214,100,161,143,160,146,170,182,188,108,48,191,100,156,147,146,251,82,178,170,35,144,160,190,56,180,47,75,142,114,60,182,79,214,167,172,86,188,22,41,79,25,
89,143,142,183,173,252,176,128,235,39,88,210,59,183,56,16,217,178,6,187,165,156,116,71,29,149,178,45,189,0,33,61,13,60,209,70,26,183,219,3,87,169,135,102,58,124,90,8,180,181,245,189,66,37,243,113,113,
200,81,46,56,24,129,88,36,229,64,122,96,53,212,210,245,111,109,81,246,72,91,223,83,159,253,130,163,78,127,185,107,63,143,148,137,10,201,83,184,110,54,77,167,92,140,63,98,80,29,66,149,215,206,193,67,66,
142,2,178,231,134,179,236,95,105,143,179,118,83,165,161,1,231,165,65,56,198,151,156,224,222,40,230,251,29,186,93,202,43,206,242,234,6,129,100,175,90,56,132,19,41,150,75,137,181,125,92,20,207,16,74,205,
248,250,207,187,54,107,249,254,221,151,27,241,191,254,206,23,202,48,243,102,202,213,82,26,154,69,234,119,228,27,125,112,75,13,179,177,71,61,130,41,229,177,70,242,181,2,247,120,172,216,60,72,153,217,72,
33,57,59,47,144,47,123,104,254,54,178,231,118,71,110,3,242,78,146,128,0,171,210,6,138,60,177,190,30,31,33,127,40,246,41,143,116,198,43,98,86,68,129,3,80,238,144,7,191,18,49,252,166,6,218,160,60,130,80,
16,1,53,17,187,124,93,143,151,234,152,111,51,136,93,132,79,71,233,101,68,74,184,228,117,139,8,166,130,112,181,56,147,227,193,104,170,141,68,6,227,184,242,239,83,237,41,71,91,212,57,242,224,186,235,152,
41,143,212,53,246,174,119,102,81,86,175,88,40,13,44,138,168,38,148,127,54,240,179,118,71,216,111,32,221,152,70,115,161,156,52,21,193,146,126,190,248,108,28,83,135,227,94,206,89,144,27,45,92,227,116,113,
25,205,62,13,170,226,191,211,26,69,78,168,37,193,172,136,202,147,100,133,213,241,202,34,118,41,15,55,125,242,84,11,212,227,98,75,68,24,109,58,63,250,24,232,45,70,52,96,128,175,49,221,13,142,176,8,198,
46,48,163,41,4,159,50,224,172,161,94,211,36,119,252,219,174,8,185,42,82,112,129,148,35,145,167,196,97,86,220,87,217,26,222,105,178,254,125,211,2,142,240,5,71,224,252,181,82,209,3,249,114,75,83,52,114,
56,65,245,6,238,15,164,3,79,69,204,133,168,218,228,84,198,222,171,137,29,223,135,120,174,17,95,45,209,117,87,221,178,71,158,89,97,108,39,216,219,29,101,174,107,4,142,229,66,62,129,173,163,26,190,107,26,
154,124,162,43,119,110,209,213,94,185,230,73,26,188,168,154,61,10,99,228,86,246,221,182,33,147,215,248,221,23,203,189,141,216,164,3,194,30,106,255,122,71,201,164,169,197,174,160,147,167,138,201,205,52,
224,39,151,13,29,67,122,93,229,174,247,135,91,250,232,37,196,247,47,33,39,231,78,51,122,7,51,123,199,65,222,136,216,55,55,235,56,107,13,172,1,126,253,248,81,60,209,213,212,249,182,139,219,127,39,10,47,
108,226,23,240,85,174,19,78,95,138,120,141,134,98,255,234,42,90,115,139,90,223,210,226,243,25,141,164,220,67,78,215,161,246,72,246,109,204,146,170,188,237,174,67,93,243,245,42,56,50,192,170,20,65,146,
86,173,37,232,182,98,37,162,77,232,178,14,25,214,148,54,181,170,105,121,74,83,218,239,221,197,109,109,130,16,192,212,129,68,89,203,172,232,195,108,160,224,139,96,244,66,75,212,82,18,86,145,240,46,169,
95,182,200,221,234,89,152,174,201,191,68,247,162,207,79,102,55,226,36,19,166,232,99,98,147,217,108,73,160,94,223,223,199,181,168,246,132,3,144,254,40,249,97,123,253,108,27,73,209,228,72,246,69,164,137,
60,247,78,20,191,85,104,95,42,21,176,71,223,136,16,162,231,173,231,161,247,239,21,164,88,79,153,163,195,251,87,87,28,11,52,81,32,116,104,49,144,86,121,36,250,97,82,25,83,13,60,107,117,30,197,135,132,221,
89,14,153,233,3,29,81,239,44,145,54,169,155,93,141,229,65,228,134,217,92,60,117,208,10,66,208,210,129,60,195,226,166,113,214,25,200,182,60,115,33,167,43,64,14,119,16,194,14,178,35,9,174,132,137,119,214,
244,221,118,39,30,49,130,148,36,190,146,63,46,65,186,154,131,190,130,10,122,107,159,199,224,114,138,194,19,37,162,9,88,123,149,236,42,167,131,224,149,54,48,40,134,50,7,255,129,31,173,98,34,159,181,218,
203,210,12,70,61,145,70,65,206,184,16,105,231,222,231,165,124,55,219,138,182,178,246,105,81,78,209,174,183,156,77,190,42,34,251,66,185,11,105,75,164,193,232,25,99,78,57,48,105,37,78,51,71,181,224,15,69,
232,37,199,125,193,33,180,56,170,247,252,76,146,71,75,68,217,194,253,223,119,187,241,64,190,170,13,136,164,17,57,164,46,188,160,36,97,150,68,14,114,220,147,26,104,126,233,30,158,50,226,167,154,244,175,
227,195,249,9,71,192,145,75,49,154,119,47,169,198,168,156,188,199,224,227,79,56,50,108,60,53,66,233,248,171,28,235,151,120,144,84,249,126,241,94,197,79,238,94,243,84,219,241,232,240,93,185,130,3,44,223,
187,213,9,82,91,83,3,193,44,85,137,81,209,230,24,202,161,135,147,135,213,171,183,84,110,232,240,228,229,213,30,166,86,215,68,110,172,5,203,92,47,71,126,92,126,56,220,108,114,121,7,44,173,42,35,128,184,
119,152,216,170,194,105,151,7,207,108,42,169,168,130,40,176,137,76,58,84,242,75,11,70,219,39,2,104,144,247,45,121,200,83,112,86,51,204,38,146,21,18,218,122,21,65,190,29,215,5,237,108,198,149,172,140,186,
40,109,183,69,133,142,58,30,166,211,33,106,56,140,187,116,105,157,182,235,168,235,249,148,19,54,233,53,167,12,160,8,214,30,144,149,101,55,11,160,236,13,19,126,59,136,247,102,28,249,251,99,249,241,14,184,
125,167,153,124,164,105,186,187,189,165,5,141,35,26,169,197,34,151,234,186,74,74,74,23,42,147,90,178,72,7,213,98,135,186,71,42,136,170,237,29,119,38,159,133,116,141,226,16,89,157,230,85,74,176,124,97,
200,153,77,172,79,83,95,105,151,213,182,125,78,54,162,23,213,81,115,52,76,3,44,204,53,111,202,33,15,68,184,148,82,158,33,163,50,205,40,209,162,22,51,34,91,227,91,141,233,151,57,21,161,59,137,175,203,81,
167,24,112,156,206,198,217,100,163,249,165,136,118,105,169,146,20,146,222,203,235,156,93,48,119,202,27,117,30,98,91,57,42,128,71,218,226,90,146,240,113,255,23,73,234,112,126,85,17,255,220,247,158,74,21,
148,175,137,250,241,14,126,190,76,193,180,99,137,84,135,18,33,103,183,29,168,20,148,89,232,68,17,247,125,78,233,130,48,165,132,47,152,232,197,237,164,94,58,97,233,250,90,169,106,30,239,237,203,37,161,
152,115,198,217,39,133,204,110,157,31,201,133,111,58,214,70,203,96,79,205,114,128,52,218,133,80,198,16,219,2,211,244,196,207,169,244,196,115,247,220,118,95,223,70,128,61,124,88,87,146,226,62,148,246,206,
62,108,196,247,255,177,70,133,79,146,137,183,225,95,192,87,241,200,193,200,2,255,66,62,211,179,112,21,209,162,108,23,214,133,45,253,139,34,27,140,151,69,254,214,30,88,194,35,222,99,199,198,36,126,51,132,
80,211,162,119,218,77,100,4,8,71,131,153,173,98,217,235,122,118,161,247,195,114,53,45,228,73,239,60,14,113,244,251,74,30,172,93,237,204,103,57,136,19,135,37,41,241,236,52,232,48,148,165,72,50,113,16,161,
50,222,215,162,171,146,159,17,204,22,229,35,255,223,203,123,175,56,134,30,73,88,9,233,81,150,203,78,9,35,246,229,45,143,68,154,83,135,232,222,181,60,65,22,237,83,52,21,124,222,238,108,55,180,63,170,157,
234,244,224,12,118,116,180,12,175,146,253,252,153,54,246,103,239,45,234,104,69,2,218,28,44,185,16,129,68,143,209,21,49,197,117,249,246,107,88,243,55,166,251,241,195,108,120,198,64,118,83,32,171,60,212,
93,92,135,32,185,233,66,41,211,248,46,23,189,141,83,74,5,203,92,126,57,145,115,238,171,35,30,128,218,202,132,241,115,71,229,216,86,100,92,51,156,137,181,233,131,183,43,191,208,77,114,226,134,92,144,36,
81,52,218,225,8,51,18,93,91,140,30,40,223,5,139,43,14,109,193,58,101,138,33,128,26,117,164,244,161,71,115,206,9,165,150,181,1,170,150,65,210,166,247,199,207,37,21,197,66,57,60,191,101,227,185,17,61,96,
130,201,3,216,248,103,32,247,11,209,56,203,58,123,210,8,105,52,184,136,123,0,171,147,124,130,79,33,14,134,45,191,204,83,159,186,91,85,22,242,59,182,100,153,46,69,254,151,234,182,41,165,76,241,67,79,40,
158,43,45,33,94,227,165,238,155,179,177,50,138,107,188,179,254,43,70,91,132,70,124,171,51,213,66,42,165,113,65,10,248,129,45,253,170,61,208,255,53,177,199,35,158,100,167,169,61,80,86,145,103,100,54,185,
221,136,81,126,240,66,203,161,243,242,100,119,104,210,133,218,104,235,81,148,186,219,241,242,163,243,248,253,239,150,227,135,223,83,251,157,96,27,191,128,47,138,56,7,90,141,142,152,150,225,201,225,204,
144,121,27,148,88,142,174,98,33,153,168,237,32,126,228,112,11,179,119,80,17,113,40,207,107,110,180,166,14,206,217,37,245,137,60,142,209,114,250,12,19,193,176,84,154,97,112,89,75,203,218,216,216,66,175,
184,218,140,53,19,144,106,110,4,223,152,49,93,218,200,197,196,33,244,243,103,96,220,200,68,175,9,89,89,1,196,42,99,242,190,141,137,248,134,162,92,229,48,91,198,24,147,131,229,95,5,58,226,117,140,101,197,
129,41,42,238,167,66,5,182,81,208,167,186,193,246,189,146,195,220,77,241,190,99,29,40,60,116,199,104,182,22,6,113,81,200,92,243,103,100,147,86,195,24,202,81,185,139,205,225,171,129,112,91,60,123,128,139,
99,39,108,234,30,170,99,253,134,152,170,145,46,147,21,149,143,172,103,35,132,47,154,119,84,210,208,124,203,62,239,68,156,218,253,150,82,192,37,67,236,235,56,17,113,57,135,37,101,204,200,154,94,91,151,
30,120,219,98,52,251,224,122,146,64,47,79,65,76,134,85,243,158,91,114,188,140,218,99,209,255,94,89,33,187,130,114,202,220,210,90,119,56,197,175,42,229,116,69,183,178,104,215,85,115,169,50,156,7,102,23,
149,173,233,93,95,20,99,228,73,224,64,134,155,82,11,235,142,145,61,92,211,54,230,129,206,86,188,156,194,208,243,158,147,100,127,181,141,77,192,221,165,136,87,181,158,185,116,217,246,170,131,78,109,213,
127,240,11,59,156,74,29,49,182,52,119,233,206,234,244,189,103,6,184,13,42,181,96,115,228,80,14,97,203,201,129,183,242,192,119,253,249,61,166,81,7,117,145,241,88,91,181,72,29,53,79,245,148,238,145,112,
94,113,4,151,246,32,213,79,143,125,96,179,57,161,186,34,144,95,119,104,158,93,255,33,135,136,118,223,71,71,15,172,207,144,122,236,104,123,59,150,205,147,141,193,183,7,31,110,4,8,233,51,214,222,123,125,
203,25,189,88,196,201,195,118,60,125,247,50,30,157,140,227,205,119,218,255,227,111,254,218,111,254,255,188,248,23,195,82,139,21,245,183,121,143,246,242,154,254,85,153,162,145,3,182,184,222,66,118,35,240,
156,35,177,179,8,142,21,46,205,12,146,211,36,225,49,81,92,134,100,8,23,134,148,31,51,158,158,179,229,77,243,168,209,130,89,69,6,230,143,99,100,201,21,134,110,196,40,38,168,254,231,14,206,139,79,28,46,
100,15,228,182,57,144,119,114,150,87,14,205,245,115,170,35,156,253,1,133,82,150,114,246,141,61,57,228,149,155,188,112,26,229,194,161,242,182,94,202,42,118,170,41,191,204,235,74,134,242,98,76,245,169,78,
185,159,147,169,20,229,63,211,64,88,0,125,23,114,213,59,44,241,107,115,51,39,132,210,15,228,103,157,132,177,152,225,161,252,46,141,62,141,163,0,66,63,167,149,213,142,24,165,36,94,212,232,234,212,74,203,
229,173,67,199,25,32,76,190,179,61,212,247,137,232,152,162,255,243,37,135,124,225,243,238,193,240,99,93,36,41,156,168,148,65,48,247,179,13,134,86,8,10,234,242,208,27,42,163,161,46,21,36,119,252,88,126,
125,167,68,65,6,33,170,27,27,226,224,14,41,109,250,4,5,135,34,215,177,107,42,136,44,6,76,146,59,82,17,57,140,115,152,117,153,12,173,242,194,66,46,104,57,168,139,126,166,238,201,177,159,121,232,111,44,
54,113,16,9,38,227,181,70,46,153,231,16,61,51,221,112,127,15,115,89,220,223,25,173,237,90,100,123,146,142,142,243,204,136,216,99,232,57,115,105,224,189,45,13,178,139,1,248,186,173,230,168,178,156,81,222,
140,83,65,104,203,63,17,121,16,143,35,64,103,140,89,71,28,37,44,206,182,177,153,251,118,140,54,77,13,112,3,206,34,27,42,14,117,36,105,233,235,55,141,145,33,43,96,120,109,162,130,186,246,175,61,107,213,
35,248,253,240,182,47,178,43,213,97,252,71,253,139,88,92,92,0,30,174,91,169,104,120,49,148,74,53,149,213,170,148,84,166,76,152,235,50,195,246,174,218,199,113,252,120,20,111,61,254,93,239,253,42,238,122,
175,27,191,242,119,127,213,85,125,177,94,69,41,14,67,163,33,149,43,12,213,167,238,73,74,38,8,145,6,79,184,117,3,38,81,206,76,16,70,87,188,119,149,234,37,27,102,135,22,117,38,55,201,88,218,73,114,72,94,
186,4,23,83,197,83,225,170,147,36,216,117,176,42,14,70,137,81,229,232,196,181,131,252,1,200,118,165,152,92,243,161,15,20,147,251,74,51,83,239,117,132,197,51,233,82,206,1,58,235,248,207,220,228,146,96,
96,113,87,137,171,179,93,68,67,26,154,147,227,181,114,112,126,234,0,246,179,151,116,239,112,3,201,199,254,237,218,63,95,27,193,81,147,211,110,241,206,179,249,141,195,117,227,176,33,151,158,62,141,173,
191,240,175,201,165,47,29,220,190,174,20,36,143,235,74,111,156,47,231,112,243,171,219,178,191,224,223,8,69,121,206,48,223,87,106,25,128,98,43,209,113,132,105,61,183,54,91,126,118,216,83,99,20,229,155,
102,225,86,21,0,31,82,184,228,24,150,185,18,211,94,113,155,215,98,224,12,170,104,77,102,14,126,10,32,146,104,185,103,68,67,208,125,201,216,95,129,130,207,92,247,52,255,158,26,98,37,143,42,102,121,144,
95,3,207,11,188,215,84,153,170,182,89,63,16,24,4,172,103,30,150,125,154,233,249,176,180,117,208,188,196,208,82,201,227,252,82,115,21,226,132,115,213,136,133,104,34,39,244,125,124,163,53,209,244,109,109,
114,242,65,46,227,132,35,189,146,223,183,253,253,201,142,251,16,129,75,160,62,59,181,183,74,64,82,221,123,134,189,116,175,83,81,63,201,121,74,206,141,195,77,13,110,42,247,118,68,201,35,250,222,59,234,
172,123,123,210,230,68,160,226,228,149,204,19,90,154,154,65,107,235,250,82,37,150,19,23,215,174,63,27,203,42,102,46,77,133,225,133,217,190,5,132,225,46,178,240,43,18,227,6,161,196,67,73,230,19,17,183,
59,190,142,238,228,220,136,86,181,114,99,72,43,164,153,149,156,161,235,30,94,255,209,52,62,252,222,105,244,79,77,220,251,104,63,190,247,147,78,124,246,122,90,254,221,223,253,7,79,55,155,249,5,250,79,49,
7,106,45,75,20,45,45,114,61,135,242,202,0,231,193,240,216,230,105,231,2,87,246,144,22,117,52,249,149,67,80,166,27,221,5,191,42,131,20,132,233,64,23,137,166,132,208,3,27,177,209,161,249,170,51,104,35,109,
168,122,202,188,170,199,209,151,234,153,231,169,31,182,65,173,236,228,111,50,252,207,140,162,24,136,160,71,96,117,42,114,14,116,27,180,119,145,42,248,250,35,155,188,107,206,207,124,235,48,102,173,237,
56,99,156,247,114,80,151,161,67,159,46,215,240,177,223,66,32,156,50,196,25,163,25,203,203,230,10,244,109,239,221,192,228,102,83,47,78,56,78,16,69,57,95,232,189,95,124,18,127,238,47,188,187,137,68,169,
19,172,201,169,134,222,107,237,94,178,65,220,31,49,168,14,28,163,88,26,200,53,76,210,65,221,246,248,248,43,224,238,33,184,126,168,212,100,178,156,182,165,142,78,156,154,158,207,183,218,135,241,181,109,
195,202,210,95,155,97,187,224,225,71,106,24,173,197,174,95,140,128,161,158,49,146,155,124,115,249,84,182,174,22,49,179,204,26,9,132,161,54,150,36,15,122,143,91,184,21,198,238,49,198,215,214,17,121,26,
187,135,200,34,121,237,152,147,171,34,149,138,162,179,174,171,12,214,81,51,141,224,161,176,197,158,148,151,148,71,220,207,187,162,25,126,39,46,125,45,115,195,252,122,33,201,47,14,239,10,90,73,97,123,69,
94,90,83,146,200,203,185,98,240,72,119,14,33,226,204,191,67,167,27,178,108,236,122,22,44,143,221,110,28,201,200,69,223,64,49,108,136,212,208,90,99,224,239,64,207,107,159,117,239,61,110,123,208,5,195,75,
245,81,102,70,233,219,202,62,247,181,168,253,10,55,112,175,68,146,93,59,111,115,94,187,66,241,243,91,242,60,210,195,22,67,46,178,246,170,155,248,178,156,180,11,206,55,164,78,95,34,134,255,134,137,226,
117,227,114,186,210,72,46,25,57,212,131,44,116,18,157,223,66,96,16,150,78,163,161,185,166,215,47,165,70,151,149,248,225,139,187,120,125,86,223,173,150,31,255,125,183,246,133,122,233,205,213,141,33,41,
175,40,113,236,148,182,54,221,30,217,76,221,208,226,149,36,199,204,172,215,210,245,33,137,148,3,76,5,114,155,121,98,66,43,197,235,172,89,222,51,136,33,247,220,200,26,150,191,83,106,68,127,0,70,50,196,
167,234,86,183,90,198,198,22,119,46,231,49,183,107,35,19,204,78,151,198,206,125,124,233,1,200,34,106,124,164,131,62,201,151,31,26,202,85,217,109,17,65,119,227,76,222,149,93,16,109,53,206,85,142,218,112,
32,242,229,76,200,93,28,88,249,230,239,152,135,241,162,175,238,137,217,252,182,210,203,3,174,123,100,42,194,88,9,225,30,116,221,225,149,91,10,227,31,254,198,111,27,32,245,155,241,150,89,64,51,225,225,
202,204,206,110,150,37,178,166,192,161,180,228,66,93,135,46,167,185,221,251,247,57,70,84,188,52,213,252,202,84,8,50,63,90,226,17,97,123,78,4,156,200,57,119,187,83,57,223,121,60,83,50,202,81,245,213,25,
37,204,64,238,36,98,47,154,55,238,153,216,224,22,163,140,128,42,40,125,140,45,216,46,72,71,178,187,17,213,167,198,53,163,168,0,17,143,49,69,93,3,172,239,53,169,191,34,103,228,175,98,201,9,52,13,87,102,
14,156,30,114,70,90,208,5,227,127,122,147,136,64,45,146,182,53,187,63,10,32,37,45,136,136,4,86,10,89,202,196,228,148,24,87,63,41,192,122,79,251,35,226,41,151,110,162,98,114,10,75,196,102,54,78,223,48,
228,153,136,103,107,144,51,202,47,190,111,76,76,96,126,157,50,72,94,39,177,60,99,172,184,214,1,103,211,203,232,104,127,115,28,73,26,117,142,209,60,51,76,109,146,44,47,184,155,211,10,19,102,247,237,205,
82,233,237,17,135,240,85,141,182,15,41,128,46,95,95,196,39,214,224,134,81,62,36,246,88,154,106,127,3,230,118,120,155,187,163,109,145,17,1,9,113,157,94,93,198,206,253,141,20,137,240,224,225,158,173,225,
68,207,95,10,10,189,168,189,181,27,71,79,7,174,75,93,251,217,80,89,101,17,191,119,122,138,187,120,228,73,5,197,248,143,222,123,242,203,31,126,250,59,191,252,238,155,127,250,159,229,57,249,34,188,202,219,
148,26,7,245,79,28,34,69,246,42,38,76,215,67,89,221,46,165,101,93,6,85,2,237,38,14,255,10,105,147,192,164,216,38,115,3,71,215,121,80,108,214,226,30,41,227,48,215,229,76,73,104,219,55,4,134,218,85,202,
178,64,145,4,89,53,121,199,157,22,172,215,14,197,8,52,238,108,47,227,232,165,166,90,57,80,118,50,36,11,236,12,68,149,129,252,224,106,229,81,7,171,248,94,239,42,222,157,245,227,249,133,28,82,52,207,3,152,
176,169,46,146,124,93,110,246,150,211,55,146,155,101,227,246,143,16,32,89,47,44,115,16,111,40,114,119,65,210,20,212,247,228,176,219,234,138,99,243,57,153,138,249,53,93,227,49,69,13,35,226,135,32,219,66,
196,77,166,154,227,223,232,85,215,14,206,158,114,200,142,211,118,229,164,85,20,202,143,177,210,89,255,189,146,47,146,116,210,3,27,110,236,48,62,215,85,147,179,111,219,14,252,203,155,51,7,84,125,193,26,
228,112,159,57,150,114,73,240,253,72,94,153,16,111,130,5,191,87,18,56,32,240,88,186,199,91,70,163,174,31,79,15,144,41,6,146,77,17,112,136,93,81,208,122,139,146,3,249,234,157,232,125,136,164,153,88,27,
38,174,133,205,172,37,127,78,242,234,142,129,228,188,31,127,228,0,64,81,191,220,62,136,204,232,252,57,163,168,106,139,124,214,229,184,214,181,20,68,138,135,112,67,238,248,253,142,51,157,72,47,142,124,
127,34,157,220,180,134,55,187,240,239,111,130,199,95,61,44,199,63,181,49,217,185,82,247,134,215,74,63,35,17,213,208,25,82,59,206,203,130,145,191,111,216,239,34,39,177,107,227,115,60,76,230,156,249,120,
137,240,120,136,38,15,144,76,116,15,139,254,89,193,104,24,108,253,1,99,67,114,112,123,202,41,238,185,97,109,167,222,235,2,17,213,201,181,35,98,201,62,213,177,153,41,85,249,122,157,90,232,193,209,163,24,
188,182,207,216,234,153,49,241,243,235,155,152,146,20,182,191,3,85,36,13,45,176,188,194,220,190,254,248,247,246,182,142,183,80,125,95,156,87,25,7,169,28,193,120,44,234,84,110,116,4,170,30,25,231,49,62,
71,246,224,223,115,80,177,10,157,195,142,73,228,73,247,192,170,91,7,109,5,190,212,12,104,70,102,218,4,38,232,160,38,65,147,42,156,171,203,73,124,131,87,239,170,229,169,138,80,129,152,225,170,151,111,219,
236,212,246,27,8,38,234,147,45,68,195,90,121,166,2,190,228,92,117,150,66,72,173,199,83,13,107,190,234,197,123,90,137,222,99,128,3,144,184,172,198,40,13,222,132,136,52,210,215,14,210,174,8,242,139,219,
229,120,87,131,242,201,153,104,193,72,207,77,19,127,157,132,71,33,27,164,61,231,132,186,228,144,54,184,35,159,153,50,140,65,225,133,118,35,35,51,28,216,36,177,70,233,234,69,38,218,67,119,40,85,100,76,
79,210,43,141,117,217,208,207,62,49,168,248,13,9,219,71,47,13,88,97,84,59,162,87,133,206,120,212,119,47,48,99,37,235,177,137,232,25,81,201,223,63,149,183,53,93,67,139,254,239,68,223,229,20,20,126,46,207,
122,219,225,174,91,163,55,65,183,204,195,82,222,118,44,178,36,67,188,204,124,212,53,38,226,40,203,69,91,174,223,101,147,3,170,247,186,180,57,177,250,156,17,219,34,53,62,151,230,58,10,36,133,137,36,50,
238,39,73,150,127,78,225,122,66,221,100,201,147,33,47,29,169,203,50,182,177,95,105,208,52,12,73,198,38,80,216,252,224,90,189,218,246,108,114,210,156,166,159,245,209,185,195,174,69,148,224,157,97,112,58,
125,209,112,205,9,116,172,53,114,54,114,116,241,37,103,247,9,67,61,128,125,59,202,55,134,222,35,149,188,37,67,46,249,185,156,173,89,82,187,186,87,55,254,200,215,42,114,246,215,190,225,4,22,121,176,77,
48,33,151,94,96,175,114,15,110,149,175,198,153,222,72,145,90,102,39,183,70,175,227,20,33,199,3,59,84,102,15,109,191,17,255,2,12,62,227,16,127,105,114,164,145,226,185,231,221,220,97,169,243,115,186,38,
112,160,187,148,239,94,126,250,105,124,246,65,196,159,121,251,207,254,205,235,235,15,127,107,111,239,93,92,246,231,255,85,110,48,146,74,251,33,249,29,175,88,61,115,200,182,80,243,134,252,106,114,205,22,
166,236,25,236,247,52,251,34,130,222,52,140,105,41,41,191,226,61,151,140,33,213,51,21,208,208,185,248,153,7,246,91,138,181,167,175,77,58,224,210,199,99,94,78,100,45,121,104,205,161,62,203,6,133,207,90,
99,237,128,134,115,234,176,222,56,109,107,115,100,51,167,220,118,128,206,89,32,224,25,223,2,105,52,118,196,163,227,177,13,42,199,31,8,51,77,134,189,22,237,102,126,221,249,236,87,232,249,114,207,129,145,
7,63,118,248,191,52,85,243,148,47,78,24,223,185,123,250,222,133,72,132,218,172,63,240,121,84,42,3,215,179,195,147,231,112,177,53,168,105,76,153,63,99,47,149,62,82,104,97,204,14,181,145,136,226,68,142,
213,50,139,216,234,116,24,35,207,3,17,146,149,7,204,23,18,186,199,35,154,87,78,42,149,59,51,93,254,41,46,237,58,100,181,204,25,181,190,221,168,223,53,69,220,185,188,247,130,36,47,89,203,54,171,105,161,
59,11,240,224,31,23,240,23,14,252,165,183,222,151,179,239,16,121,43,198,200,133,179,244,161,230,203,65,221,25,212,147,163,188,82,37,149,77,212,11,215,122,143,141,29,131,195,4,53,106,209,74,46,140,252,
181,181,132,22,163,3,122,100,78,158,170,169,156,59,59,247,189,178,18,108,178,207,6,131,83,136,208,113,221,57,178,228,80,254,87,243,125,89,130,145,213,32,188,144,118,2,127,21,1,243,194,58,204,244,126,238,
121,207,9,139,76,50,41,167,196,167,225,183,221,195,11,9,231,16,67,190,179,47,119,103,2,109,161,57,231,47,173,172,221,14,136,251,16,206,30,74,69,18,85,45,171,157,248,216,245,221,82,141,189,101,16,92,223,
247,124,54,60,231,124,73,42,171,248,5,159,63,51,193,226,3,143,248,104,48,186,2,140,157,205,226,119,20,63,157,135,90,194,116,21,93,255,224,179,184,129,203,39,221,135,49,58,107,233,251,85,242,91,125,20,
147,231,201,130,123,44,199,221,171,141,154,12,94,146,118,124,250,103,94,30,130,42,95,144,87,177,250,48,39,22,220,107,140,229,201,229,57,180,30,250,227,76,1,176,169,69,37,130,142,118,168,87,52,152,11,117,
199,57,234,124,180,75,148,32,7,44,89,232,150,65,92,89,248,78,229,208,42,75,19,162,101,122,242,54,143,186,81,218,129,182,5,191,210,93,23,124,223,202,70,204,228,85,187,32,78,203,175,145,154,230,216,40,206,
212,147,125,68,234,245,28,129,240,53,176,245,196,51,55,150,34,93,83,149,123,35,44,55,48,117,129,90,47,102,132,177,161,46,77,176,35,70,7,159,127,162,227,225,247,65,225,51,229,143,108,246,126,71,131,243,
155,59,131,56,65,39,174,219,247,241,93,145,232,251,55,148,53,162,88,105,254,68,147,178,66,57,200,149,35,42,83,19,187,17,234,99,93,15,21,239,42,224,251,146,10,104,2,25,172,97,196,26,232,186,242,112,159,
166,200,122,156,173,74,140,37,159,179,50,80,147,43,30,81,196,184,86,114,12,95,53,83,174,170,247,147,115,249,178,107,219,19,93,114,184,181,138,74,166,164,60,188,158,208,36,206,224,204,156,224,48,55,23,
39,141,204,114,169,11,235,115,156,247,61,146,0,216,99,41,169,40,122,6,75,12,213,19,231,126,238,70,174,191,102,125,13,209,50,199,143,250,48,99,68,17,52,34,104,254,124,150,80,16,183,32,163,168,105,61,39,
114,193,86,50,182,246,225,78,206,157,109,117,217,238,229,246,105,141,193,94,86,150,240,183,42,165,203,135,155,45,165,22,43,33,85,197,218,35,34,144,81,24,169,186,207,70,25,80,43,101,170,145,145,56,199,
153,36,236,5,237,165,42,171,36,170,188,127,215,103,237,177,48,186,116,29,63,88,107,101,176,28,238,124,193,241,156,115,134,41,106,233,247,233,127,213,96,246,49,241,149,84,210,67,88,219,134,171,109,49,196,
61,133,226,138,131,226,25,2,241,252,244,101,28,157,124,37,86,71,79,227,140,68,114,54,161,80,211,140,157,67,165,79,69,215,127,250,225,179,248,196,189,244,113,35,249,204,150,193,245,34,46,110,175,148,1,
47,163,37,124,79,4,16,173,119,171,71,119,191,240,95,126,65,108,83,95,176,250,224,75,53,204,94,245,54,190,197,40,118,199,187,14,177,68,191,162,187,99,103,4,78,38,117,223,48,118,4,105,67,5,178,37,106,77,
82,219,165,112,94,161,32,106,139,24,137,33,214,140,51,15,78,230,48,77,26,186,156,154,150,99,18,201,80,21,189,61,161,202,230,118,109,106,203,20,229,212,229,230,60,85,246,109,28,134,40,116,135,217,116,72,
222,117,216,223,125,196,219,79,206,54,26,208,213,74,219,150,200,182,47,68,204,81,242,9,253,146,205,220,115,40,182,17,40,81,210,5,15,107,125,114,119,31,175,8,16,102,109,208,21,124,203,8,251,176,121,181,
201,23,63,237,145,4,26,95,82,105,31,197,165,207,236,232,90,217,19,10,254,47,137,86,10,181,185,141,141,35,169,57,205,149,142,136,39,34,237,220,129,210,14,69,221,228,229,118,237,216,211,180,132,21,165,137,
3,82,187,22,249,96,170,95,138,43,35,82,16,73,11,215,151,221,56,3,142,227,70,164,149,161,250,199,138,131,41,71,114,173,236,28,211,77,240,78,145,115,131,177,190,58,216,87,134,234,199,157,180,161,150,134,
194,177,229,227,249,50,175,60,16,202,90,16,198,37,120,156,53,69,84,23,78,4,22,225,216,232,62,244,166,138,230,254,79,53,72,164,32,234,121,239,52,196,93,37,148,140,172,53,145,49,149,117,27,136,238,247,129,
124,48,165,122,253,87,116,202,180,180,150,45,240,103,27,177,192,169,111,188,245,254,111,90,131,113,87,241,223,194,174,32,165,19,144,241,204,207,254,20,188,76,134,183,3,106,223,123,159,129,155,89,200,7,
179,172,181,37,42,238,0,13,115,168,166,201,122,223,202,203,178,6,5,78,233,84,25,70,27,175,251,33,172,160,183,206,1,222,115,159,147,220,192,169,242,73,206,228,125,232,209,142,217,107,123,111,82,126,77,
183,202,47,60,220,130,208,232,164,42,111,24,237,242,7,218,244,144,141,115,3,205,81,234,133,173,55,237,157,9,240,234,161,45,132,94,193,25,57,68,192,109,235,145,189,58,53,106,134,99,187,241,8,139,219,247,
95,196,171,63,250,65,113,190,85,252,75,46,255,239,249,245,185,127,21,7,84,45,35,7,110,189,243,40,110,182,120,86,5,252,50,140,243,37,155,121,72,2,39,89,148,11,25,91,98,86,78,113,144,218,88,245,59,135,61,
5,211,9,65,178,148,143,225,222,24,101,174,70,70,181,28,64,125,235,32,30,11,27,29,145,168,9,130,54,60,128,232,222,243,67,50,206,204,184,252,158,195,244,210,97,249,177,72,54,227,225,127,117,175,161,153,
118,7,101,31,134,23,47,227,51,248,235,67,185,74,1,65,210,68,26,148,96,182,36,132,48,251,88,67,7,20,122,25,169,157,53,140,202,248,242,49,175,77,16,113,232,208,236,167,56,26,252,202,71,161,148,57,147,111,
74,224,126,85,195,225,92,185,226,131,126,31,225,96,195,135,187,24,94,239,37,50,230,5,207,92,203,218,225,169,220,19,233,247,40,128,220,247,131,67,141,229,140,147,53,83,0,0,32,0,73,68,65,84,14,232,255,242,
7,215,158,131,66,37,164,9,59,167,160,151,116,192,20,188,103,142,70,153,164,225,51,194,190,40,62,228,20,160,209,248,192,218,93,98,118,19,46,166,1,249,49,243,150,228,188,174,173,10,234,230,196,128,29,78,
201,208,120,133,119,196,138,53,42,145,11,86,188,87,78,196,207,217,178,15,149,31,10,222,163,162,78,147,51,155,102,20,85,215,24,157,129,235,76,230,199,48,2,98,0,181,100,191,100,103,208,183,60,206,154,24,
144,8,190,235,168,177,70,57,129,65,112,7,85,165,33,238,117,206,8,215,254,60,22,21,251,24,248,143,57,128,23,70,157,120,86,90,150,118,55,255,222,160,10,210,16,20,191,39,146,158,171,207,102,186,146,31,185,
226,184,58,186,115,198,174,63,255,158,211,151,242,241,17,75,81,242,10,137,85,6,153,147,107,248,16,60,238,217,247,3,78,75,18,67,208,193,193,136,150,55,18,243,83,208,119,137,183,216,147,43,230,72,206,137,
54,188,155,189,237,232,155,236,56,211,12,255,134,22,176,59,50,207,75,35,88,190,227,177,32,15,222,160,149,126,212,228,72,173,77,77,37,160,251,152,3,200,177,57,116,197,4,9,55,206,204,7,32,117,217,200,204,
186,168,252,192,154,213,159,127,100,124,232,233,214,175,255,250,223,255,146,91,250,220,191,138,57,174,176,92,217,223,228,128,83,162,131,107,61,146,215,14,94,79,36,187,181,65,5,189,137,21,163,62,56,50,
222,211,161,23,253,174,48,161,51,68,74,81,232,27,163,10,53,132,216,98,187,230,181,49,206,36,45,252,175,41,130,212,180,137,53,232,186,6,8,150,239,102,183,136,250,72,9,28,174,131,104,191,205,163,159,217,
212,111,158,152,46,0,30,125,108,86,237,251,231,134,113,153,164,94,130,171,134,138,235,21,36,77,213,102,87,178,6,8,2,122,219,12,30,78,205,210,112,227,136,55,180,73,25,226,22,15,25,104,139,97,102,221,81,
103,37,44,166,14,234,231,251,162,73,81,212,253,10,70,228,171,106,6,217,128,124,237,190,86,121,202,242,205,224,240,18,121,223,133,67,112,67,227,217,146,51,13,52,252,190,84,170,185,209,186,85,147,175,110,
25,27,122,80,62,218,200,229,242,153,33,249,156,144,51,84,218,103,30,104,155,15,153,157,154,169,52,38,214,222,162,124,169,105,45,123,37,177,108,169,243,61,244,60,188,156,30,113,227,186,151,212,86,15,120,
125,103,92,207,106,33,222,161,129,61,112,221,2,238,38,231,29,59,236,35,221,47,44,65,219,26,221,178,235,46,57,244,115,228,75,137,113,215,177,183,249,252,146,131,77,93,218,237,91,132,148,43,59,163,254,226,
158,57,188,52,216,77,99,1,120,155,74,30,111,189,65,39,219,202,53,249,140,205,23,72,159,138,235,91,139,206,74,169,241,109,139,149,207,111,145,22,110,102,52,109,91,139,44,153,188,33,90,126,153,163,110,114,
40,122,6,226,13,17,117,129,217,251,136,19,186,6,191,39,152,251,83,236,254,51,209,252,138,24,35,159,83,58,114,127,75,123,242,148,70,184,168,124,197,211,40,73,105,220,215,188,254,132,36,176,227,249,154,
117,107,120,220,122,19,225,37,109,1,75,175,179,214,235,44,29,219,209,39,84,63,171,109,19,17,148,211,46,113,21,5,124,65,195,154,164,222,184,201,217,94,154,243,244,19,173,135,151,67,194,18,132,101,14,21,
203,231,166,20,219,123,214,52,71,154,48,212,221,126,84,171,227,119,12,20,255,75,235,245,175,37,142,251,92,191,8,246,70,60,186,233,109,218,150,42,132,230,251,218,169,154,42,222,41,106,198,183,51,10,94,
63,13,214,129,91,161,216,71,146,252,215,66,229,213,7,131,232,93,141,212,2,245,51,50,180,82,202,246,28,118,199,93,157,51,72,219,138,241,76,145,250,51,158,115,192,243,73,222,48,117,245,120,37,183,28,33,
0,138,140,59,71,253,127,135,112,115,104,51,159,201,35,50,223,217,177,17,91,91,154,107,121,195,2,182,248,165,16,151,229,0,217,38,147,147,103,137,56,25,181,207,13,23,235,131,175,55,112,227,39,232,244,115,
133,233,18,178,42,15,106,211,225,73,49,119,27,156,188,5,69,127,239,245,107,80,211,198,97,18,175,124,125,1,166,109,241,226,11,141,207,153,35,119,244,70,118,61,192,233,66,36,157,25,177,49,65,28,157,99,51,
187,136,177,95,124,239,192,122,80,232,24,234,85,244,51,142,153,3,190,179,153,187,154,161,113,71,126,93,229,145,204,53,48,218,69,211,113,89,84,38,96,88,169,93,126,228,80,63,3,253,239,16,48,205,28,39,192,
41,93,123,204,68,69,169,37,141,50,73,164,38,103,23,6,46,239,106,48,237,202,125,175,81,185,137,46,82,227,122,10,65,220,11,137,121,72,179,238,90,144,59,154,7,141,57,199,12,128,17,189,180,76,17,49,123,3,
158,113,68,73,24,241,5,155,209,36,19,106,172,204,233,159,165,42,75,89,34,25,213,169,235,204,123,81,85,149,247,129,169,246,237,28,9,117,235,90,144,186,185,221,155,238,43,41,223,6,142,111,182,212,229,13,
57,149,231,214,120,156,61,158,214,254,149,207,251,208,185,177,84,202,82,217,130,71,84,96,127,246,129,217,129,36,39,89,242,186,247,213,220,226,209,145,249,140,147,118,124,70,93,117,129,153,126,45,253,24,
121,191,3,43,185,205,209,21,120,137,42,104,62,51,69,240,250,5,164,32,141,154,166,118,91,160,88,186,159,234,228,26,90,178,191,55,215,106,213,180,219,211,124,150,44,40,110,239,26,34,249,22,120,187,58,220,
165,79,206,118,180,239,199,221,79,126,18,39,123,157,191,247,147,239,149,31,127,174,45,211,197,147,111,138,114,242,133,82,182,84,89,188,193,121,182,202,26,151,47,71,122,67,97,184,160,7,113,164,186,61,211,
56,157,15,44,90,25,178,220,205,3,193,243,22,25,17,13,65,236,248,217,166,8,156,57,97,190,223,192,78,103,177,60,121,179,9,22,226,165,161,209,215,106,145,215,146,145,127,162,204,50,21,185,14,28,196,35,27,
125,10,210,237,154,0,254,6,70,241,214,166,188,50,121,239,157,145,1,31,212,41,99,176,84,181,198,28,213,154,163,192,64,145,56,105,76,121,80,179,51,127,46,146,95,233,4,41,30,116,98,37,111,157,58,204,11,172,
96,205,132,183,28,10,229,35,76,16,87,34,242,115,99,121,233,196,244,245,98,193,180,217,246,169,233,120,250,45,171,119,114,70,70,79,239,153,207,241,60,194,4,214,146,217,212,4,124,172,132,243,41,57,99,17,
164,158,202,181,102,214,33,93,79,143,64,224,149,166,198,28,208,252,64,59,89,167,184,167,136,126,179,137,200,63,118,159,171,93,15,234,193,6,79,73,7,139,38,20,126,25,171,82,113,88,71,28,223,244,194,248,
142,197,89,236,31,76,24,174,220,26,75,243,20,220,94,96,113,43,14,89,35,199,214,43,57,165,216,189,144,164,154,18,82,30,196,137,58,98,142,19,1,32,32,17,121,36,7,150,218,224,156,74,184,105,106,135,32,170,
114,194,172,161,54,69,176,172,163,102,64,173,40,119,93,72,49,78,68,116,160,20,171,204,33,49,54,189,12,90,210,192,90,209,121,237,231,10,12,21,234,244,73,82,18,76,79,238,105,146,65,130,231,166,51,228,3,
227,72,164,220,206,67,50,225,164,134,242,138,67,142,37,27,11,214,208,74,79,234,49,2,111,27,114,227,236,13,158,185,239,67,127,190,198,140,87,179,105,130,216,247,99,117,202,47,139,252,91,196,45,119,34,54,
190,15,217,116,31,23,167,139,248,243,79,60,222,111,64,87,203,233,28,61,126,40,26,191,50,2,71,43,217,135,100,142,38,239,183,149,212,222,230,88,191,163,187,251,150,74,99,232,243,206,175,149,101,46,172,79,
73,3,188,89,83,5,141,242,197,30,210,242,249,171,88,125,251,157,90,235,224,201,223,113,249,255,169,95,159,219,87,113,235,32,135,79,41,67,40,33,156,245,213,165,44,120,22,175,103,146,240,49,141,235,194,78,
109,219,140,109,100,203,203,203,107,30,159,250,195,176,171,166,133,111,58,4,111,146,234,101,127,227,102,103,45,3,255,190,25,242,156,29,251,93,144,165,101,67,22,162,241,174,97,201,143,154,34,147,175,159,
24,183,159,249,209,136,165,29,116,142,228,163,140,6,196,25,97,135,223,69,74,61,36,231,43,174,143,12,183,6,105,57,8,85,30,62,153,19,113,56,11,10,126,55,140,53,35,239,227,93,249,153,7,25,61,116,144,78,200,
190,182,58,96,14,250,161,236,240,86,24,213,66,119,73,77,167,201,145,130,225,158,205,35,224,84,50,34,61,68,12,37,57,213,112,127,203,172,254,211,116,142,50,98,131,243,217,211,88,164,102,233,128,148,108,
138,113,96,93,29,176,21,178,230,78,147,192,138,150,246,17,79,159,121,247,171,75,44,114,58,7,202,169,15,149,79,94,26,135,82,192,216,62,196,230,60,204,116,65,125,117,173,247,170,160,188,211,207,135,31,221,
38,197,35,207,149,56,35,166,55,19,238,30,97,56,115,40,119,42,100,198,8,152,22,217,98,155,202,97,232,243,17,186,155,232,150,240,113,225,239,46,77,148,4,43,49,222,57,192,75,97,74,14,86,48,164,90,211,181,
235,219,98,208,80,54,166,147,131,113,91,72,97,242,72,239,169,12,148,236,177,169,153,27,145,124,54,45,244,228,149,153,195,23,25,227,90,180,106,171,63,182,41,167,170,34,181,241,63,162,144,102,106,159,155,
26,219,28,213,153,99,75,6,186,85,114,176,87,83,222,119,32,215,155,131,176,215,238,189,165,11,165,158,132,25,35,42,233,201,92,19,130,192,196,12,155,179,154,95,203,129,199,250,88,181,240,29,55,41,202,246,
162,127,201,50,213,113,215,18,234,237,10,237,108,241,88,100,245,108,79,229,178,177,190,220,43,74,250,190,57,181,43,233,77,197,200,146,109,83,24,191,125,180,21,59,219,156,254,141,139,95,120,16,175,3,116,
15,57,245,135,125,228,31,225,136,40,124,253,129,32,210,127,198,241,218,247,88,253,155,159,91,171,252,151,23,94,60,35,219,41,41,140,231,96,169,93,178,171,214,222,137,252,74,239,161,200,209,162,184,49,61,
149,8,30,20,147,107,28,106,64,126,195,65,219,6,211,198,26,251,174,232,93,39,216,141,91,6,152,29,37,155,23,131,43,57,232,37,7,52,91,127,178,245,169,2,178,86,60,233,57,53,148,57,61,125,87,51,243,26,193,
211,33,198,44,54,175,77,115,51,255,214,97,58,71,153,31,248,220,115,97,233,159,153,174,118,139,4,249,198,137,241,137,162,68,219,225,216,228,137,34,102,18,24,15,13,36,203,103,116,62,218,197,132,234,228,
88,56,240,45,245,176,135,218,185,150,244,192,43,98,145,58,167,51,166,132,233,131,188,189,210,5,3,58,51,59,183,167,150,11,154,58,208,253,243,159,21,243,179,155,164,166,213,108,34,186,207,7,219,155,71,8,
222,208,248,94,205,158,232,202,151,67,209,25,239,76,28,46,195,207,26,4,238,169,33,173,202,77,51,159,238,145,13,165,148,45,27,5,222,20,129,222,117,113,135,4,9,101,99,54,151,169,164,114,99,187,222,219,52,
157,77,241,126,102,28,202,154,211,201,193,229,123,200,159,172,7,122,103,99,67,168,129,120,159,145,103,81,180,57,198,108,143,202,90,231,212,231,206,104,98,51,203,176,124,172,198,207,216,147,204,173,115,
176,89,71,17,30,79,181,209,186,230,99,21,242,129,184,64,181,67,79,17,197,26,15,68,215,108,213,243,118,155,178,136,166,14,26,94,223,159,136,105,179,97,34,167,247,205,63,231,32,112,104,146,110,95,84,189,
14,210,197,66,60,7,193,95,131,197,9,35,63,3,157,95,64,5,152,4,242,196,115,6,130,137,149,115,94,145,57,166,242,104,166,139,165,175,153,61,31,41,81,182,30,45,232,68,1,72,135,207,174,242,26,103,5,161,140,
69,189,146,115,81,224,132,242,49,247,95,123,247,173,120,73,248,50,135,70,190,249,213,111,35,229,76,60,144,71,254,41,79,55,255,133,135,41,177,52,133,1,73,212,214,242,183,165,27,234,23,142,57,121,131,149,
174,48,254,55,88,221,108,68,168,214,168,172,112,3,37,164,229,123,79,53,193,31,104,76,191,187,70,197,125,190,95,197,20,61,247,213,237,208,52,2,11,122,141,204,174,164,179,191,140,57,156,140,201,242,76,59,
120,36,234,28,33,42,182,9,48,235,34,71,209,193,188,242,156,197,28,14,213,117,160,214,30,124,58,3,67,11,12,39,161,109,223,179,47,115,98,94,71,45,171,152,20,187,26,229,98,51,33,30,59,105,115,23,234,43,103,
106,147,53,17,211,54,41,30,51,60,5,187,172,77,86,149,93,84,27,227,51,19,7,0,81,245,197,85,188,65,97,84,209,176,155,198,153,135,182,237,240,180,244,127,46,201,11,251,100,115,121,4,202,114,230,190,176,81,
32,135,203,153,72,55,230,104,48,31,17,68,228,163,255,173,97,140,167,154,124,47,69,156,236,49,252,44,137,141,124,2,173,83,217,48,170,100,205,107,191,70,234,24,186,200,113,32,147,144,31,23,140,126,238,254,
206,228,171,31,115,68,210,46,12,46,15,143,10,126,138,101,253,234,3,114,64,12,104,1,59,241,6,105,205,35,114,52,103,217,116,187,165,186,45,22,215,161,223,193,104,151,172,67,78,101,175,54,148,14,172,83,207,
227,8,218,43,195,193,6,205,248,128,44,112,68,208,208,112,237,99,172,230,152,131,204,252,79,5,98,243,76,207,44,247,20,25,92,193,231,108,220,159,142,151,180,81,75,189,225,5,54,37,43,134,166,135,90,249,75,
68,132,102,54,237,117,16,193,88,206,121,42,247,203,182,178,236,80,201,238,29,1,109,83,252,207,82,141,96,131,21,134,117,56,137,37,195,110,250,28,207,103,242,89,156,161,8,249,139,122,111,59,199,62,44,155,
31,240,194,85,6,87,148,174,228,35,252,230,41,140,32,94,47,121,162,116,82,197,251,38,20,246,240,10,62,222,128,236,244,33,72,40,107,111,248,229,230,225,72,91,242,204,161,167,80,247,239,110,48,172,34,95,
113,71,94,157,15,179,114,207,26,46,158,60,249,106,92,81,96,133,105,138,127,229,223,254,106,148,9,87,94,156,129,232,250,125,71,175,62,140,15,94,191,138,179,179,87,49,58,242,248,14,147,32,167,72,59,159,
30,111,96,191,119,9,93,10,36,127,173,39,28,157,245,206,231,118,206,169,187,62,239,175,242,190,50,201,210,163,228,94,242,128,207,166,79,163,214,122,29,15,60,82,238,118,228,193,173,240,125,139,122,37,159,
11,89,38,217,201,39,101,1,192,14,7,22,146,234,227,137,233,105,99,155,149,27,81,78,53,188,87,230,45,251,190,175,155,195,153,69,199,29,74,155,247,30,107,253,250,160,23,255,2,155,215,77,154,80,173,109,223,
33,185,146,80,206,69,210,138,153,165,15,29,220,60,112,55,234,86,7,54,233,155,36,92,175,237,244,39,186,17,46,68,174,137,211,151,222,63,161,109,126,223,213,229,34,14,176,188,195,158,48,47,23,90,102,109,
68,146,251,250,250,44,158,35,74,186,162,227,138,241,78,177,27,107,195,155,203,136,136,71,126,182,97,110,81,215,160,168,231,194,77,223,28,200,60,160,61,189,142,67,2,247,19,112,45,31,12,155,194,250,107,
170,244,167,160,216,76,110,214,112,192,203,69,61,162,62,98,219,180,242,54,217,223,239,59,156,87,228,63,187,34,27,101,130,81,144,140,65,78,157,15,121,170,54,46,61,9,236,145,231,120,210,202,50,232,41,195,
56,17,169,179,141,110,65,172,144,2,129,10,248,123,155,48,81,4,220,151,159,229,3,158,242,90,250,12,160,36,82,38,91,189,128,32,110,229,161,249,152,139,115,208,243,49,79,210,197,106,167,131,202,72,147,66,
132,38,167,73,32,37,146,64,44,214,133,141,41,27,37,61,35,127,196,98,158,49,248,46,72,155,53,209,156,191,150,81,54,107,159,83,247,148,15,211,149,150,210,128,56,212,174,241,83,177,134,234,112,35,238,168,
186,158,170,17,51,15,65,219,87,25,45,189,215,67,185,252,169,207,59,147,252,222,155,61,149,249,122,178,72,79,9,7,182,210,33,14,79,105,134,143,55,143,35,44,89,135,51,145,181,73,202,247,228,134,30,89,247,
201,237,182,161,112,34,103,120,212,223,20,113,54,69,60,230,51,92,171,36,126,103,151,125,249,228,197,102,182,238,255,240,191,127,143,81,83,27,61,253,21,221,73,137,147,56,95,196,227,66,228,92,49,238,38,
113,201,159,36,26,249,237,171,29,1,133,230,120,11,119,112,99,189,16,140,63,190,220,142,189,158,244,198,115,95,63,239,175,226,216,116,238,178,26,81,149,78,180,100,158,203,90,148,211,214,11,226,34,67,80,
238,249,100,226,91,19,197,59,52,163,166,220,88,50,198,192,64,235,102,143,230,132,247,97,62,141,7,3,91,73,85,13,163,76,227,220,114,66,30,102,68,19,37,156,155,205,99,213,77,234,136,109,155,92,6,159,231,
140,242,107,135,52,155,242,203,95,23,65,199,218,189,78,228,13,13,236,106,205,230,175,25,99,87,116,121,234,208,92,185,174,23,14,78,254,239,143,95,25,157,179,213,173,132,36,104,18,129,183,228,56,5,144,74,
26,203,80,28,36,36,83,81,189,113,6,138,57,65,216,87,37,9,19,171,119,156,222,3,6,183,163,63,112,91,222,57,164,48,89,179,184,162,207,77,161,197,82,7,77,91,116,221,2,147,114,144,217,54,165,212,142,247,200,
201,14,199,106,32,82,58,181,81,181,65,247,242,152,218,233,40,115,83,19,36,42,199,162,63,212,209,51,90,227,112,247,144,48,226,80,109,206,117,33,60,12,110,216,76,49,216,174,122,36,159,104,249,20,86,120,
11,6,172,32,118,234,166,248,237,48,246,185,52,96,37,95,219,87,26,104,9,189,151,32,238,192,33,46,130,219,187,22,112,215,231,63,246,253,91,126,205,51,1,183,11,57,72,250,214,189,150,165,20,144,187,186,31,
232,201,144,116,101,109,200,163,205,70,200,121,161,254,205,0,179,158,127,151,38,199,13,232,253,190,245,52,240,35,46,173,221,29,86,61,39,35,140,51,66,203,63,179,35,101,31,44,77,148,146,57,167,193,3,155,
241,152,187,157,182,153,187,68,7,246,191,233,94,79,8,16,116,88,111,30,116,180,103,111,118,176,226,251,133,163,120,211,207,14,38,47,129,217,9,62,66,141,146,113,205,136,223,11,242,203,182,161,104,203,154,
65,160,74,1,79,177,198,5,231,100,237,123,6,42,0,61,105,204,54,222,227,149,15,252,238,85,37,222,222,61,137,247,182,250,113,127,246,59,241,109,247,240,111,61,61,142,127,229,97,211,240,106,50,63,121,124,
138,35,154,212,106,41,130,88,73,169,138,52,224,81,120,176,65,125,57,143,184,107,76,233,231,253,85,126,112,208,141,103,55,47,163,230,209,2,127,138,14,235,245,224,103,20,126,19,53,221,167,11,195,158,243,
216,73,0,241,204,54,106,237,107,93,155,185,198,186,229,76,158,108,93,90,55,191,226,188,248,198,127,249,114,150,40,69,230,72,152,124,4,95,87,206,163,187,210,225,254,218,183,140,63,156,189,218,20,232,42,
249,16,88,63,63,4,191,178,53,236,133,182,161,62,184,153,198,84,196,252,189,47,151,248,147,187,38,137,27,198,245,82,94,87,212,104,156,19,223,51,114,166,178,232,73,146,0,169,196,81,229,223,76,184,227,28,
38,234,44,205,100,4,25,120,73,100,202,199,9,214,21,174,175,193,176,124,112,81,78,184,59,18,185,90,100,138,57,130,178,169,142,185,97,152,83,243,203,64,133,28,223,95,141,31,128,142,167,96,101,3,133,127,
72,61,51,39,80,152,48,238,162,249,38,63,85,159,43,51,204,119,64,209,125,182,223,240,158,249,48,221,11,79,75,107,75,36,91,90,195,114,182,209,250,226,154,209,155,106,104,157,150,72,172,43,79,156,206,38,
245,1,57,97,53,197,238,14,121,101,78,18,168,235,103,46,127,106,60,22,31,148,94,146,164,233,104,98,222,212,57,133,57,1,40,197,88,224,189,190,73,208,182,73,66,153,45,91,67,209,241,43,7,12,75,121,161,207,
249,164,248,224,234,66,147,130,102,229,3,70,118,147,165,12,191,103,237,177,7,26,30,121,15,8,80,94,93,82,71,228,220,228,232,71,72,160,145,118,171,140,179,136,113,232,5,193,7,222,127,138,192,73,33,3,95,
20,75,228,87,135,1,220,25,111,185,173,118,217,98,20,249,48,221,130,135,33,231,19,234,118,181,211,93,40,197,93,16,18,60,227,148,38,155,49,53,30,248,228,167,151,246,104,44,165,184,17,221,130,150,118,45,
223,87,1,139,95,62,194,35,72,29,62,186,188,140,79,198,29,124,131,166,123,95,63,242,136,135,255,224,27,143,226,91,181,139,248,50,149,198,255,253,250,133,167,133,191,138,63,243,164,26,111,124,9,74,187,82,
226,186,67,132,9,239,115,142,236,218,103,13,46,207,226,75,198,239,31,253,137,63,25,247,31,28,198,86,54,147,154,148,136,222,250,227,227,248,185,253,189,184,127,188,111,130,247,13,217,22,86,118,135,7,67,
170,108,203,9,208,26,8,181,117,252,34,227,219,42,233,28,176,121,243,236,222,101,120,115,158,127,236,64,37,92,76,122,127,101,161,22,114,67,129,115,227,176,165,99,34,155,241,147,254,128,223,176,1,140,156,
60,112,114,118,170,49,86,151,188,156,52,39,149,231,208,228,167,194,221,87,202,251,54,94,135,7,203,187,229,85,231,32,83,23,131,154,116,126,215,33,28,57,252,51,172,113,246,47,230,43,63,103,140,68,42,235,
93,188,119,0,7,168,197,11,195,174,242,1,73,85,240,11,200,137,103,194,201,16,164,91,213,229,144,14,251,184,69,80,224,58,27,14,229,104,120,133,216,145,139,230,172,14,239,85,193,198,158,138,168,89,44,153,
138,32,35,82,159,76,127,170,62,111,157,79,36,115,248,179,120,223,17,185,30,111,115,56,174,253,18,57,178,32,57,203,167,167,101,43,86,129,19,153,200,189,254,224,236,2,156,59,37,28,207,17,155,73,188,120,
128,172,232,84,176,150,95,3,19,27,96,252,210,247,213,136,249,183,182,221,139,123,156,186,247,50,163,25,19,26,92,32,219,170,74,28,57,165,96,142,240,202,209,191,35,55,172,130,33,95,149,141,99,212,23,156,
201,142,127,207,135,11,43,7,67,58,200,37,215,62,87,214,88,249,66,221,58,46,64,244,212,220,38,241,213,134,42,214,41,106,184,78,125,49,84,194,186,51,0,23,221,95,54,74,223,49,228,172,217,102,119,202,79,137,
47,84,164,228,221,184,3,176,117,79,90,208,181,246,61,99,222,127,32,125,121,125,135,33,229,84,110,224,148,190,97,217,101,115,143,111,117,52,125,170,76,181,148,91,207,228,246,115,81,61,187,113,122,20,97,
7,156,125,62,82,97,49,58,85,174,209,135,105,157,47,40,187,190,47,24,156,111,189,75,183,237,17,244,214,236,70,139,224,253,217,15,213,149,235,241,103,191,174,76,242,217,75,179,122,239,227,223,251,249,227,
248,22,199,53,126,125,131,32,19,209,61,142,176,40,226,159,126,214,139,247,245,1,239,191,245,94,60,250,250,87,162,254,228,61,74,42,181,250,202,79,112,25,82,129,108,227,249,156,191,138,75,76,109,71,20,123,
107,247,137,221,242,140,206,101,223,3,81,127,86,215,74,168,215,116,160,239,213,147,86,114,171,28,208,156,240,164,140,40,169,168,48,23,108,96,1,147,186,84,50,89,82,160,164,166,117,161,247,49,133,236,217,
163,9,5,43,140,223,199,205,51,13,182,12,231,198,115,50,214,14,79,223,163,12,110,145,65,11,80,46,103,225,94,139,106,125,11,126,67,40,125,230,168,101,55,253,177,235,58,1,165,107,88,211,23,232,250,169,129,
172,69,42,149,50,97,192,200,38,157,57,120,57,191,70,81,133,176,154,161,243,208,75,208,234,142,104,98,168,245,41,7,124,21,13,250,90,120,160,78,41,107,121,152,203,156,129,52,102,120,57,72,42,141,114,140,
164,202,200,89,71,76,172,148,132,232,115,160,226,86,188,109,226,213,27,34,108,181,134,236,16,121,91,190,103,225,217,42,43,83,181,178,205,235,132,35,42,43,15,21,119,73,206,50,250,11,49,5,159,223,244,254,
59,12,175,34,103,101,246,122,40,13,232,98,156,67,107,225,188,131,251,123,186,42,56,67,249,248,157,73,9,107,239,89,225,36,118,169,133,178,35,102,122,95,85,200,247,76,79,159,55,117,141,109,16,122,143,129,
248,235,166,31,179,104,205,179,245,45,13,186,40,149,184,228,228,114,72,116,10,12,114,182,80,182,68,182,83,86,199,80,5,217,205,83,180,211,136,31,99,73,203,156,236,138,177,167,0,62,89,225,133,125,203,30,
216,21,84,112,38,92,63,183,47,61,200,1,49,202,184,212,133,25,106,182,102,61,121,251,200,44,41,144,86,74,178,227,223,155,174,115,75,52,13,130,146,18,135,213,150,47,166,3,224,190,56,6,19,243,53,72,156,40,
173,44,76,143,120,225,233,115,23,84,17,19,11,116,185,56,220,144,115,69,53,204,31,190,184,137,151,144,73,54,190,159,62,127,225,89,168,131,248,181,191,120,18,255,249,47,236,42,143,65,24,157,7,158,111,99,
92,184,39,17,28,209,48,79,25,248,11,50,180,219,17,73,95,19,133,232,154,175,57,231,183,158,60,136,95,253,87,127,37,26,111,127,13,2,25,120,148,229,139,120,241,163,151,28,216,173,170,67,86,105,63,223,47,
22,118,29,45,19,208,170,91,158,241,33,103,202,102,89,104,207,204,81,42,18,154,219,3,155,95,82,238,200,71,175,103,165,61,85,35,5,115,103,138,26,152,11,140,167,32,225,239,202,37,202,200,151,100,14,107,106,
117,117,76,234,140,49,44,181,219,239,107,53,107,123,84,65,91,142,184,158,93,211,124,222,199,209,142,188,3,196,185,38,132,158,105,78,126,65,85,146,144,249,19,76,106,19,61,254,3,107,250,177,131,254,109,
195,195,230,160,87,14,58,170,203,75,146,86,207,233,5,73,124,116,21,242,102,230,111,22,29,170,74,230,66,132,249,21,243,117,243,25,145,69,180,253,19,192,170,43,175,153,230,163,35,180,110,21,16,87,55,148,
19,21,39,184,35,199,235,200,237,178,132,148,215,92,134,247,246,28,190,158,110,225,107,122,218,182,136,91,80,171,88,49,210,132,191,41,96,109,115,8,55,216,207,162,250,224,99,137,96,203,147,179,134,138,235,
3,139,213,226,104,198,162,196,189,90,95,51,243,66,215,87,33,190,168,51,188,207,228,216,51,17,167,171,63,149,240,76,119,6,68,193,104,91,134,90,101,237,241,22,92,206,9,4,35,236,244,80,231,202,190,14,161,
140,60,43,198,153,6,70,255,32,183,134,16,68,207,6,56,170,181,221,207,65,44,100,65,125,198,83,85,147,188,165,164,81,171,135,112,82,107,11,73,200,183,151,202,66,201,149,245,165,27,42,180,114,75,240,84,212,
206,25,75,35,198,196,143,33,184,148,106,236,103,155,49,174,117,247,100,163,246,137,123,45,120,191,228,58,187,28,115,234,139,127,152,251,160,150,253,152,152,33,33,253,34,135,104,35,104,166,234,186,83,79,
82,203,73,245,53,136,197,155,248,28,157,36,144,64,79,10,50,177,198,249,168,198,68,60,181,84,154,185,135,46,46,226,155,143,183,226,153,198,233,239,254,214,239,198,159,255,114,55,254,171,191,241,229,120,
244,184,101,36,169,105,250,31,127,178,113,194,219,111,26,128,102,176,212,10,188,168,229,52,124,141,247,43,79,158,27,157,97,195,95,243,134,96,193,87,187,190,230,153,55,203,249,51,143,140,224,20,142,44,
214,183,30,17,141,72,69,122,57,247,254,243,253,178,93,52,163,38,157,55,110,41,52,108,198,182,67,156,130,129,170,141,112,94,209,247,6,23,131,177,165,21,42,143,158,114,173,124,180,194,136,204,255,95,246,
238,60,88,246,252,60,11,251,183,183,211,125,186,79,47,103,95,238,126,239,220,217,37,121,102,180,32,203,66,182,36,67,140,193,198,11,224,66,177,67,48,184,192,64,129,73,40,226,84,156,84,65,138,20,36,225,
15,160,72,32,224,130,164,128,80,14,96,2,6,12,50,246,196,150,109,73,72,214,50,35,205,104,182,187,157,125,233,115,122,57,167,247,206,231,237,209,224,36,255,4,28,105,40,226,219,51,119,238,220,115,207,233,
254,245,175,191,239,246,188,207,251,188,166,75,38,12,115,130,121,51,209,254,8,40,40,162,80,207,129,239,199,4,11,118,54,57,234,56,215,60,42,185,67,145,102,11,136,20,203,91,219,253,227,116,217,125,12,150,
205,170,78,255,179,210,187,162,122,241,117,245,222,9,241,172,129,195,126,125,105,99,54,169,63,56,61,154,1,8,121,128,138,24,34,210,88,12,235,247,215,76,234,151,143,12,245,74,67,115,218,1,251,20,252,214,
150,86,233,232,98,238,0,121,202,62,200,158,130,109,16,204,25,215,16,117,85,48,117,38,120,115,93,145,44,38,240,99,151,201,68,77,6,137,194,133,245,129,250,255,87,212,86,215,244,71,151,213,174,243,192,137,
60,207,29,20,193,146,209,177,55,83,63,41,85,160,36,140,167,202,72,226,80,246,81,212,98,65,143,146,13,123,69,157,41,218,93,210,255,173,104,143,12,164,137,25,236,159,53,209,43,140,57,203,80,53,130,100,10,
212,246,200,177,199,180,198,24,165,239,16,37,82,31,30,48,37,74,67,158,122,90,61,206,228,12,153,14,162,127,204,194,14,33,194,179,177,28,64,80,143,177,148,189,183,7,82,198,51,199,112,131,1,151,189,135,158,
126,223,152,119,8,193,108,137,201,172,141,226,22,205,80,220,80,80,136,158,108,240,146,243,26,250,89,239,33,31,36,3,173,169,37,78,16,39,3,128,23,25,144,175,113,120,199,106,250,151,94,184,199,241,114,100,
202,11,133,137,89,78,70,107,85,66,8,62,135,132,223,178,172,38,54,185,69,39,55,6,3,192,103,94,25,90,174,38,93,48,106,56,61,81,243,219,11,90,130,57,132,144,118,108,24,255,236,231,239,19,139,91,78,63,244,
77,155,233,143,124,223,98,170,62,119,53,117,94,252,197,212,123,157,8,120,191,153,54,182,174,166,38,66,73,166,64,65,65,125,81,20,198,111,144,9,237,208,83,189,16,133,251,50,29,187,8,76,58,209,40,210,235,
221,189,211,178,123,167,175,36,32,233,125,235,221,253,122,239,49,120,193,19,127,252,223,111,211,140,210,185,179,157,206,30,124,5,26,235,160,108,222,148,110,241,222,154,228,69,222,183,23,59,59,69,204,85,
168,161,220,15,240,227,131,213,144,94,32,109,18,28,213,22,148,23,58,32,141,60,96,0,49,24,228,80,240,152,83,135,126,172,207,24,147,26,2,106,58,220,219,159,165,48,171,234,208,3,236,144,156,231,42,88,247,
54,16,61,227,239,115,190,63,242,168,75,8,14,11,29,134,9,88,41,65,98,167,140,164,161,7,185,230,195,200,58,13,19,41,100,95,47,114,77,10,122,110,34,226,148,247,168,73,51,47,92,99,23,72,213,68,64,175,184,
246,156,136,162,249,130,99,74,116,139,145,101,20,81,69,135,175,28,61,61,41,120,94,36,190,231,249,188,21,87,236,151,223,149,114,94,83,223,22,228,95,133,30,79,25,199,84,27,163,88,215,138,208,34,89,96,160,
67,237,148,18,195,159,23,61,218,194,82,67,239,14,249,78,205,133,209,34,20,197,206,160,168,223,86,87,164,201,34,210,193,145,146,193,193,238,137,36,29,142,108,25,181,176,198,41,76,57,135,77,238,98,81,212,
28,186,254,22,77,218,46,167,84,98,36,101,206,167,13,205,150,56,204,200,237,51,25,16,239,33,171,189,18,143,152,137,156,99,236,35,145,55,208,241,99,207,23,209,122,69,138,184,207,208,58,238,67,73,51,51,39,
148,158,81,19,240,237,72,16,82,92,207,253,5,142,225,144,19,121,154,161,141,124,175,110,20,126,179,107,246,188,193,140,18,108,221,95,247,67,250,26,136,118,11,123,169,230,103,98,135,202,137,182,8,46,133,
76,5,105,30,122,95,160,232,126,128,190,57,41,161,117,26,54,111,242,36,67,211,17,185,252,101,145,53,54,216,48,84,159,91,191,125,152,170,68,160,43,203,85,247,131,238,210,235,247,210,119,60,251,120,250,19,
63,248,116,90,190,216,213,253,58,78,103,63,247,243,240,8,247,60,34,45,112,112,23,149,111,251,75,116,154,134,187,238,173,8,123,111,15,129,99,148,238,24,38,40,84,110,250,28,124,142,151,110,167,95,254,236,
221,231,23,191,242,149,238,34,20,252,233,239,251,88,122,234,59,190,225,191,251,51,63,242,87,63,249,67,191,229,38,2,195,7,130,241,249,239,245,35,63,185,183,43,109,208,11,220,164,184,135,183,119,164,30,
137,249,192,1,234,213,136,225,197,142,198,114,52,198,213,0,230,52,192,215,162,12,239,123,116,64,17,32,228,36,160,156,89,69,80,104,216,69,244,140,127,3,28,25,73,217,94,1,112,112,242,60,120,180,89,42,106,
37,243,254,14,195,33,82,119,3,112,208,205,152,239,243,65,222,181,122,124,147,170,192,83,34,216,107,94,127,31,50,209,96,4,29,209,178,178,65,232,177,181,147,90,59,34,168,168,55,117,80,26,234,165,149,181,
70,90,123,199,99,233,228,193,27,233,129,150,72,24,97,35,214,232,241,218,175,156,74,61,213,87,69,0,204,189,99,132,6,145,190,46,186,119,32,125,171,34,204,179,107,89,209,112,148,190,236,48,250,119,118,221,
175,163,201,44,72,233,63,4,12,59,150,222,207,249,249,136,92,109,215,129,33,160,30,22,105,213,99,208,124,207,145,183,20,22,133,143,193,176,245,25,199,245,65,12,40,171,225,230,101,0,23,3,202,6,199,238,159,
247,26,53,117,140,74,69,31,246,28,223,23,191,136,129,50,100,117,114,65,95,182,229,158,31,107,196,71,116,93,228,12,218,162,109,139,1,173,112,27,130,168,247,171,94,101,92,0,102,173,23,55,215,159,51,208,
211,24,20,191,144,106,79,15,49,130,172,100,140,229,73,56,232,190,145,179,242,61,3,131,227,125,209,86,120,84,3,251,178,39,107,153,52,138,190,170,176,147,222,64,126,136,109,212,151,212,144,45,145,114,199,
81,246,81,205,200,8,143,88,50,26,123,108,90,187,84,25,65,197,115,66,122,168,33,246,213,252,23,118,140,102,237,188,153,11,122,33,176,168,201,225,157,159,180,105,73,29,166,169,65,232,162,86,92,93,62,86,
135,220,30,120,127,5,207,125,197,20,194,167,239,190,145,38,219,47,165,31,253,224,181,244,187,127,232,114,106,92,3,10,254,204,75,169,93,219,194,175,133,160,75,70,236,168,74,119,63,215,79,119,246,247,213,
241,87,210,61,229,201,171,96,232,201,198,251,82,241,198,214,180,122,158,123,254,167,159,255,23,127,45,11,134,255,175,254,240,31,77,239,250,77,223,241,191,127,211,42,47,225,241,55,62,245,179,41,125,53,
86,254,213,127,244,87,227,75,255,222,63,172,201,116,136,129,60,103,210,141,80,138,203,235,175,157,241,170,69,236,159,5,81,48,47,10,197,180,66,134,177,102,213,11,89,248,249,133,9,131,188,72,52,111,237,
65,22,196,191,126,249,93,78,145,147,20,15,231,39,143,34,82,236,46,152,34,208,144,15,54,137,191,58,114,144,230,164,197,179,177,51,186,48,201,134,172,18,34,243,162,39,239,3,18,22,145,165,215,172,248,90,
0,0,32,0,73,68,65,84,235,14,216,72,11,36,14,110,164,85,135,168,114,117,6,147,113,128,74,241,201,137,66,5,156,213,190,176,114,122,104,239,230,189,179,116,176,7,21,117,72,134,172,36,195,120,99,165,96,77,
157,85,45,172,26,251,58,73,159,193,67,141,90,172,133,84,31,242,37,143,110,26,2,14,36,85,132,169,74,195,93,46,206,106,140,165,49,54,223,51,84,196,181,81,208,98,68,173,165,191,48,167,45,19,236,150,99,123,
75,46,24,89,135,119,175,169,213,98,213,123,240,87,155,106,236,145,61,116,5,104,241,20,80,20,58,58,231,234,226,93,215,120,25,154,156,183,159,114,142,186,249,86,181,105,19,54,209,48,14,168,231,208,62,224,
28,166,44,46,239,231,42,136,23,37,41,121,223,200,220,5,214,210,156,40,55,6,138,5,63,88,185,54,187,198,0,177,50,110,100,104,204,134,72,118,137,236,232,57,231,112,168,45,19,11,114,239,179,172,168,17,219,
106,209,174,94,109,78,142,186,194,170,117,74,244,129,17,9,144,24,98,26,38,246,217,196,82,165,140,172,164,230,94,189,198,217,133,96,89,221,215,187,106,71,153,109,218,82,26,92,133,232,238,50,172,51,168,
119,236,199,89,198,133,157,144,15,25,250,28,193,212,179,222,229,238,5,133,124,124,235,57,14,229,163,31,252,214,116,114,122,152,218,187,175,204,150,14,111,3,0,243,62,135,201,74,131,97,238,165,119,90,84,
244,99,63,250,141,233,214,123,23,103,156,219,214,23,191,40,109,13,135,51,151,94,253,244,107,28,93,51,237,73,131,119,243,183,211,141,15,125,175,5,88,55,211,198,17,230,217,157,47,164,167,190,97,45,125,240,
35,207,30,62,114,253,195,127,164,186,244,103,95,136,99,246,135,62,246,157,241,219,255,175,31,249,3,158,113,27,24,176,46,5,93,7,240,156,201,239,206,150,105,254,144,195,63,62,187,79,149,173,141,219,153,
213,88,95,80,95,169,103,140,143,245,15,24,26,150,141,79,155,77,218,245,81,139,202,242,255,241,208,62,88,37,68,83,178,75,242,87,154,166,61,180,51,6,0,165,5,81,248,49,64,211,2,164,239,170,49,169,18,3,44,
224,88,198,168,88,94,31,45,214,18,108,48,198,75,60,233,133,101,61,85,105,230,62,21,247,118,231,193,172,166,141,87,9,146,195,61,6,222,104,191,70,63,86,195,122,115,51,125,234,78,115,22,25,123,222,207,138,
148,245,208,243,188,184,63,208,132,175,164,39,29,244,208,182,189,170,125,113,83,164,111,235,57,214,212,117,55,29,204,168,199,198,140,247,61,14,103,136,127,45,66,168,35,134,228,200,132,6,169,189,160,197,
20,170,128,129,8,31,56,204,103,222,243,146,190,225,41,112,104,129,252,102,164,132,21,209,233,145,37,14,4,49,62,102,65,107,230,13,163,237,155,147,234,158,177,174,88,247,183,73,245,189,202,225,13,25,205,
192,166,161,254,176,150,142,100,11,53,150,83,69,131,27,136,78,247,52,149,139,82,206,53,142,79,210,42,69,100,89,46,48,34,90,93,24,142,8,58,210,11,117,217,162,163,113,61,215,21,106,132,144,0,66,208,122,
155,94,180,41,219,25,170,9,99,179,90,135,16,153,32,159,10,193,42,18,97,195,248,98,177,196,2,135,83,227,76,131,76,97,34,149,99,212,146,17,169,171,126,31,114,44,247,77,188,75,148,102,142,249,220,207,4,176,
84,87,163,148,181,218,206,149,29,75,76,184,160,38,124,178,186,230,254,87,211,182,80,188,254,174,247,167,7,207,255,67,101,81,197,152,96,41,61,77,38,84,66,144,62,131,83,184,169,252,249,3,191,225,106,186,
241,174,53,172,172,87,211,197,93,212,80,19,224,83,169,242,235,119,62,147,62,251,106,59,45,92,126,71,186,250,161,143,114,222,107,233,23,222,248,92,186,243,241,191,65,233,224,149,217,42,199,95,249,217,97,
122,240,175,126,118,237,187,126,224,206,143,186,21,31,243,235,215,197,35,63,161,12,16,244,244,132,88,252,138,253,156,165,202,214,12,144,217,165,36,188,119,90,74,47,227,44,222,42,75,47,29,154,5,211,250,
161,86,30,155,168,54,73,70,68,143,51,11,196,9,41,145,183,30,209,59,203,49,158,117,131,205,45,92,220,49,244,238,81,205,232,107,212,5,94,122,233,12,79,151,238,140,122,179,9,193,205,117,95,74,3,130,95,215,
98,5,61,54,139,153,144,116,69,155,101,14,20,223,69,251,235,104,174,86,40,192,95,98,88,103,177,113,75,141,21,241,57,26,240,151,1,46,215,183,168,56,0,103,78,206,79,103,181,95,16,171,163,110,154,226,243,
70,123,225,154,33,233,130,239,109,66,158,114,174,97,104,172,236,115,15,240,57,77,216,119,165,95,250,247,44,51,134,178,240,128,165,125,109,125,219,189,238,145,254,39,112,199,245,128,49,69,175,85,117,183,
145,48,169,84,76,247,215,68,242,82,1,121,158,145,134,210,121,180,8,43,210,231,5,0,90,104,30,133,108,70,28,116,25,108,252,23,177,253,2,152,34,106,101,150,69,158,190,145,42,96,27,192,171,14,234,239,81,53,
63,215,47,141,213,243,93,37,64,19,152,115,67,75,166,206,73,64,143,56,6,45,15,150,120,42,122,73,112,102,189,207,170,76,166,166,236,120,9,159,119,223,215,158,3,171,198,74,81,151,162,187,17,245,190,186,17,
34,30,237,157,152,48,81,57,120,79,144,112,142,165,236,94,84,212,144,59,12,46,114,6,183,104,166,240,23,64,150,129,156,25,112,150,183,242,224,37,35,51,99,154,60,139,86,82,84,41,20,212,137,66,79,177,229,
247,140,251,173,201,6,74,176,131,238,218,147,233,99,63,252,39,82,239,23,127,41,189,248,63,255,79,233,95,124,233,207,120,14,67,16,80,245,143,61,177,100,233,239,32,253,147,151,14,211,211,154,189,171,193,
22,227,16,206,15,238,1,7,101,101,238,249,1,121,203,159,248,169,221,52,190,113,37,93,253,109,191,61,45,172,63,145,254,233,63,255,39,233,95,62,255,201,116,122,122,10,166,244,190,244,52,215,47,109,224,104,
211,117,26,146,63,43,174,235,211,253,250,121,228,143,120,185,203,34,203,61,111,123,164,150,88,199,58,25,14,239,66,222,108,15,227,33,183,22,87,136,95,217,82,124,178,51,91,79,95,212,74,232,58,252,3,170,
231,61,48,251,4,130,80,199,90,137,244,112,236,0,172,19,67,61,150,250,28,32,178,135,48,86,40,121,231,12,35,86,172,227,42,47,18,139,230,134,191,0,69,253,204,189,23,80,244,206,211,150,15,51,64,159,108,80,
176,28,158,50,65,176,129,250,176,25,192,15,173,153,49,1,176,117,233,218,130,109,102,161,148,199,182,13,99,83,115,63,112,248,68,60,18,196,51,69,240,129,58,167,138,45,158,5,26,76,68,229,26,105,143,121,169,
107,27,186,28,105,220,80,189,121,232,96,44,169,207,98,83,118,159,33,29,75,7,163,55,27,219,175,91,190,103,91,218,186,44,221,212,145,49,125,63,77,27,162,232,92,72,1,248,218,68,4,171,205,119,208,5,161,186,
12,57,35,98,23,25,93,232,214,6,144,43,1,77,187,57,173,40,207,151,129,214,194,174,16,42,212,131,50,130,101,245,235,188,22,17,110,16,248,104,162,97,15,212,25,238,204,150,66,181,12,164,239,109,75,67,29,222,
88,40,92,49,145,18,67,209,199,28,81,78,191,57,166,253,115,210,202,38,35,245,82,179,251,19,82,151,27,17,249,128,64,129,172,70,166,137,159,160,60,81,19,51,178,150,200,222,54,81,18,233,113,240,95,207,32,
194,154,73,38,97,124,94,162,237,137,207,73,133,48,3,194,178,28,64,44,123,234,96,60,237,184,15,223,67,249,240,28,240,23,20,191,44,101,196,86,168,58,192,3,91,152,71,237,250,22,62,117,37,93,189,125,37,45,
188,235,163,233,39,126,250,231,211,175,252,131,191,150,62,200,241,197,182,186,79,236,119,211,7,175,108,205,68,170,255,226,231,118,210,71,175,85,211,51,248,215,127,231,227,189,244,129,103,56,27,247,190,
183,195,57,24,237,186,43,53,207,255,166,223,153,86,111,62,155,158,127,254,23,210,63,254,233,63,238,190,141,1,84,185,116,221,124,240,220,146,246,139,215,31,27,212,62,237,16,149,94,187,126,124,239,35,191,
87,85,249,131,191,110,172,51,223,211,38,217,110,61,72,71,36,49,23,245,12,7,166,63,50,144,190,37,55,166,100,200,250,214,102,53,189,178,179,143,59,171,153,111,21,193,96,87,20,18,50,95,2,245,229,29,196,152,
152,200,150,111,185,97,126,151,26,182,187,77,51,128,102,28,103,95,193,124,113,72,166,140,241,14,180,162,43,68,156,32,57,172,224,171,126,63,144,224,196,222,140,22,22,200,5,79,95,81,47,94,128,228,199,168,
96,69,20,183,186,122,107,77,202,151,205,91,253,102,226,196,73,116,154,194,152,68,0,206,68,120,18,129,0,15,148,225,7,158,123,13,104,83,170,7,181,173,159,118,224,253,125,136,226,132,1,70,175,173,45,236,
132,118,79,65,223,114,197,80,117,145,211,24,106,131,196,46,207,40,149,3,101,14,38,19,149,146,84,20,193,78,176,159,242,65,248,135,96,47,81,99,64,55,119,216,79,160,212,177,240,21,178,42,27,136,109,94,75,
238,199,36,80,221,136,74,78,112,37,54,94,75,201,23,220,171,216,52,61,81,35,14,188,247,130,52,251,140,19,169,162,60,13,213,221,25,128,85,94,184,27,226,46,95,0,119,230,57,153,10,64,168,37,139,56,135,60,
71,126,112,225,57,249,138,217,96,122,40,29,44,35,199,3,147,221,31,128,154,90,19,160,26,219,237,103,223,67,105,114,22,85,3,192,10,237,32,156,121,104,107,74,175,43,38,11,28,81,12,25,68,49,185,171,255,23,
43,33,234,62,191,120,223,154,96,218,94,122,177,82,247,44,195,184,102,70,179,172,101,241,236,90,63,189,251,138,137,25,70,254,41,60,215,2,149,136,111,127,28,2,251,216,123,210,199,95,56,72,95,124,241,75,
169,253,133,47,164,79,220,33,186,205,152,214,101,17,47,55,174,164,167,62,248,161,148,253,202,23,210,127,249,211,191,144,30,65,16,248,190,119,115,198,144,166,203,248,195,155,107,68,184,149,77,159,248,76,
74,159,254,133,222,244,253,127,224,15,111,151,115,215,254,208,237,245,149,255,188,177,185,252,13,191,229,251,127,7,122,222,48,237,60,56,75,207,127,250,31,103,198,59,119,230,58,84,33,218,90,120,31,121,
247,202,244,219,62,250,254,31,253,22,1,254,215,141,101,122,163,58,213,36,238,209,179,150,232,189,196,70,171,7,82,168,45,7,185,118,153,66,249,252,165,180,183,59,77,47,222,133,184,45,175,99,147,236,160,
80,237,235,135,174,154,68,47,72,87,195,251,242,236,37,219,176,121,248,137,131,48,175,151,181,118,251,114,26,190,102,119,137,22,68,180,64,222,80,147,61,160,56,55,113,162,230,212,25,13,81,112,197,215,118,
213,103,49,222,213,1,230,212,12,27,103,25,198,14,165,187,101,141,237,203,13,134,139,25,114,102,107,235,35,0,159,130,246,71,68,103,231,118,6,247,83,195,53,99,138,134,134,44,48,199,41,4,168,85,87,171,157,
209,41,10,118,77,109,216,144,106,102,211,87,128,61,2,3,231,98,130,222,193,221,59,54,207,168,37,114,238,125,83,39,81,199,197,196,97,206,214,171,55,211,188,45,68,236,93,41,217,75,60,123,164,195,107,110,
81,204,132,230,28,90,33,109,38,130,28,116,190,19,232,235,144,227,57,83,123,230,213,158,81,155,231,164,106,35,96,17,124,72,27,35,104,119,140,144,3,200,16,226,222,54,50,246,200,58,222,235,252,134,254,49,
62,176,72,56,7,0,41,234,37,230,144,49,46,68,185,151,105,53,93,169,33,117,135,113,97,7,132,76,71,232,245,116,57,36,137,46,212,28,66,11,172,131,181,184,175,140,211,243,199,120,88,204,103,2,192,25,88,18,
253,24,40,220,96,133,88,87,36,175,251,65,241,83,203,71,106,237,163,154,17,218,195,40,163,214,126,235,164,7,1,189,36,194,127,232,246,134,145,186,86,250,73,115,132,85,125,226,140,50,225,93,239,124,118,150,
90,215,179,187,233,245,79,253,92,186,123,255,130,148,39,44,64,79,243,42,230,208,58,199,242,194,245,119,167,141,111,255,206,244,91,111,93,75,63,251,231,127,38,253,215,223,125,59,61,107,156,238,234,13,74,
21,123,23,233,58,40,246,228,65,63,253,149,31,175,166,95,126,176,48,46,78,202,63,240,195,191,235,63,253,169,239,93,202,156,77,167,175,252,220,121,122,223,194,197,69,57,67,222,102,244,18,33,131,199,190,
237,122,229,209,202,179,127,253,143,253,240,31,203,47,140,239,165,223,254,125,223,247,87,62,252,189,127,228,111,167,244,35,113,2,126,221,60,242,3,169,229,82,97,203,225,183,179,196,10,182,171,38,209,31,
125,207,53,7,110,49,101,144,183,191,116,250,42,36,80,196,132,200,221,194,20,169,233,115,141,45,18,154,245,254,120,224,22,114,193,169,9,222,197,204,213,217,77,139,168,26,223,123,122,206,40,184,235,28,130,
193,17,233,194,222,224,48,173,123,206,158,116,121,106,178,160,205,104,46,164,146,123,61,74,224,106,146,186,200,119,81,168,80,42,88,50,87,121,10,113,181,210,157,194,81,99,78,83,33,179,45,29,140,248,230,
17,135,79,212,136,89,201,5,131,208,45,96,83,213,236,225,104,31,210,25,235,15,32,206,72,101,34,165,86,12,53,183,145,215,206,64,72,241,213,93,103,21,80,20,179,147,131,116,85,120,217,23,53,50,162,114,70,
90,190,73,253,79,187,142,102,174,215,80,83,29,29,35,193,119,252,161,162,209,77,184,167,190,120,53,29,239,158,164,251,128,152,96,248,96,127,70,135,101,70,53,140,157,151,7,232,101,33,209,91,210,115,140,
249,200,102,211,143,50,160,170,84,186,139,216,93,182,232,232,12,155,104,94,170,26,249,228,206,120,57,85,108,5,47,48,212,69,105,228,156,44,164,161,198,234,153,226,56,149,57,152,122,130,158,159,115,90,50,
4,247,41,232,119,109,70,52,84,107,242,83,72,3,12,85,212,158,216,230,93,230,1,114,65,134,144,219,134,34,192,161,72,118,20,43,253,188,191,30,167,217,209,222,169,114,100,11,126,190,227,90,35,23,8,53,132,
224,52,4,181,48,239,121,34,149,254,244,189,215,213,192,12,41,242,103,70,7,66,77,243,221,23,76,248,100,211,243,150,87,205,205,55,144,227,175,168,95,239,80,172,207,219,141,121,61,221,126,246,125,24,57,253,
244,218,231,126,33,253,141,127,248,23,211,239,123,214,184,223,55,173,166,159,250,31,62,47,99,184,205,89,29,43,159,187,233,229,204,19,105,249,131,223,159,86,238,52,255,163,31,255,115,127,234,111,255,132,
180,53,30,153,204,76,157,93,147,234,255,246,56,244,167,143,188,245,149,111,253,157,159,120,235,127,127,93,253,46,15,148,78,209,23,189,139,140,28,186,63,11,192,136,72,172,30,236,220,129,204,209,193,65,
155,202,131,247,79,143,15,212,37,154,233,32,190,49,241,170,99,220,206,83,31,106,75,180,45,52,95,159,213,158,97,61,113,203,143,31,92,216,30,61,100,212,103,233,62,116,178,172,61,243,1,192,194,101,163,92,
163,139,58,5,182,77,14,129,6,141,126,168,35,150,174,224,75,46,121,206,162,26,175,234,16,219,18,170,230,212,136,47,54,165,104,167,182,98,193,24,25,69,164,181,78,12,20,88,122,38,170,213,113,84,47,47,139,
210,56,167,199,240,162,125,253,197,161,212,41,39,125,140,232,114,209,174,206,182,135,101,25,99,76,65,151,189,214,227,14,232,53,175,253,216,42,26,95,244,31,163,31,226,57,11,82,104,25,26,196,19,85,76,141,
215,152,154,160,65,247,107,65,39,15,69,199,221,175,156,166,7,184,193,187,246,194,156,67,157,166,122,134,49,192,12,15,155,165,246,44,71,157,24,64,22,196,86,65,23,154,177,129,108,79,91,162,178,72,61,112,
237,135,82,240,62,131,156,216,55,51,186,125,203,36,206,45,196,69,215,53,47,157,28,46,205,4,200,106,174,47,132,199,92,138,148,148,12,72,216,178,215,96,11,51,240,102,28,253,76,182,19,89,64,80,36,71,125,
245,53,103,80,197,76,90,51,199,90,149,9,212,145,36,226,239,14,128,77,69,215,50,102,108,48,53,145,149,113,122,158,112,110,241,203,183,120,4,50,44,53,103,200,39,148,20,173,192,113,227,100,36,209,28,13,202,
165,146,99,239,129,172,120,180,42,67,193,37,70,96,223,64,195,250,192,183,126,111,250,158,63,250,99,169,127,233,106,154,126,229,139,233,167,255,230,223,76,119,190,252,82,122,252,218,98,234,108,27,229,211,
102,235,31,34,171,35,160,220,120,238,209,116,90,190,253,137,239,254,29,127,240,177,191,254,238,167,255,215,120,213,135,143,255,247,59,144,95,174,212,25,220,142,20,16,35,3,93,106,15,203,38,255,185,123,
228,240,45,28,170,95,54,83,231,38,151,112,98,217,69,169,219,74,125,77,243,198,101,194,75,198,119,138,154,196,103,82,199,161,49,163,88,33,63,5,62,140,136,82,85,33,142,103,69,105,101,236,171,244,33,183,
129,43,5,242,33,45,20,181,220,153,3,171,56,138,229,62,11,14,122,108,129,62,205,153,142,119,184,219,106,189,161,149,111,11,52,77,135,134,15,119,25,70,29,187,231,88,228,136,5,183,81,111,6,141,44,246,129,
198,212,68,8,83,233,120,128,234,13,238,190,124,129,241,130,168,96,137,206,128,241,44,106,207,68,45,247,234,112,47,2,128,122,152,65,51,242,13,130,92,32,34,168,102,16,22,128,79,140,49,158,55,120,134,2,86,
58,242,90,49,237,191,2,76,106,201,38,142,192,190,94,74,4,247,243,24,71,83,142,138,191,225,39,80,0,177,148,58,200,6,240,101,81,11,159,85,251,226,72,202,151,69,211,235,155,50,217,211,58,57,71,252,126,212,
180,200,156,49,184,34,186,91,217,22,181,251,219,231,233,202,117,53,234,245,122,122,253,151,239,235,27,35,104,0,99,242,131,37,173,3,245,172,11,46,219,73,56,100,145,3,91,119,7,12,196,21,6,128,171,166,101,
164,82,237,182,154,58,63,167,143,76,224,59,12,235,76,219,102,94,52,237,113,54,5,31,86,77,36,189,35,162,214,61,111,236,252,12,209,235,41,227,12,5,120,118,73,53,1,72,198,98,167,6,194,167,60,76,214,235,197,
2,42,67,59,62,63,76,45,198,63,123,160,221,229,149,32,61,72,246,54,153,203,203,141,197,244,145,119,190,7,254,176,146,254,210,255,248,151,229,161,191,132,152,209,72,239,184,190,158,126,224,27,110,160,43,
226,57,91,213,240,216,165,98,250,196,167,246,32,184,229,244,244,71,62,44,106,63,253,119,86,87,75,95,121,243,73,31,254,247,223,228,14,232,245,3,82,0,43,139,166,37,58,120,141,93,109,146,146,158,211,173,
247,85,173,181,35,178,116,39,147,190,241,217,231,168,176,107,162,127,242,147,106,19,135,66,193,147,201,51,84,161,38,171,86,108,215,86,0,55,62,242,56,228,14,114,212,158,123,34,241,251,68,145,21,179,124,
159,183,141,245,37,233,43,61,117,250,60,39,134,121,43,233,102,30,154,225,0,188,110,194,229,102,204,51,66,109,131,181,83,131,238,94,166,33,115,223,215,150,2,169,100,156,49,124,61,65,144,15,131,136,3,213,
71,14,8,240,169,3,164,233,73,181,87,232,245,172,170,153,10,12,235,13,146,23,200,151,212,243,40,207,193,40,187,250,176,215,230,47,35,13,64,118,245,78,238,88,68,84,174,106,209,0,95,90,67,59,64,161,145,179,
6,77,68,54,135,127,222,20,203,129,200,49,201,55,211,3,17,55,140,114,224,112,163,46,164,21,14,164,172,85,180,162,14,190,3,251,201,218,213,17,232,104,87,61,119,226,253,47,138,94,161,181,20,242,32,87,212,
176,101,7,185,39,229,239,68,152,210,91,13,174,241,93,195,237,247,143,57,22,81,166,190,164,190,212,234,232,45,28,91,24,108,247,231,116,19,25,157,78,43,35,11,103,87,244,92,101,189,145,67,53,174,167,150,
157,64,170,93,109,75,228,127,13,185,226,134,109,109,117,158,131,159,76,59,140,172,175,177,56,231,122,167,90,37,61,243,184,149,80,27,140,168,234,51,42,199,19,72,157,155,234,230,67,159,15,90,170,207,15,
70,80,175,188,201,106,18,113,27,178,168,53,217,76,197,132,248,145,246,203,85,237,161,250,234,114,250,185,221,87,211,115,128,193,247,253,150,223,159,142,10,27,233,228,51,255,50,189,252,197,191,149,94,219,
63,76,223,119,233,70,250,134,155,70,11,191,235,122,26,221,233,166,221,55,246,83,17,131,254,227,31,191,7,52,44,165,15,255,190,239,79,87,158,253,230,31,252,224,83,223,249,227,255,38,7,242,225,247,252,234,
29,200,222,105,222,77,119,232,200,118,44,114,60,210,4,111,65,21,206,42,59,233,133,47,147,183,127,117,39,125,150,124,199,93,189,196,129,67,83,161,252,181,64,65,173,143,20,48,239,80,116,154,39,36,52,145,
16,68,57,71,98,246,172,49,186,187,45,61,162,120,152,230,141,213,135,98,219,80,253,87,167,47,179,76,147,40,227,64,12,161,154,115,25,188,93,94,255,50,168,99,25,89,109,162,214,93,38,126,188,194,163,71,68,
91,154,147,78,75,183,12,161,205,218,0,111,194,23,34,39,239,30,189,212,161,218,119,185,176,66,103,135,8,25,213,112,187,116,141,72,233,17,58,212,53,197,222,25,67,142,189,35,181,136,10,134,33,131,207,90,
4,168,76,0,55,193,106,27,5,197,144,193,6,49,94,204,23,129,47,67,127,165,244,28,70,27,113,248,226,212,50,95,135,120,206,172,233,216,107,68,81,20,163,88,19,3,225,1,230,228,113,79,203,12,193,120,167,94,46,
2,184,244,177,194,153,0,155,103,59,84,72,228,64,87,247,92,159,190,160,98,246,142,176,188,111,73,73,6,159,177,188,28,203,30,6,106,216,166,239,5,38,25,3,43,41,45,186,210,223,54,160,165,100,146,167,16,218,
193,82,81,111,7,232,34,139,81,99,247,213,145,121,168,206,57,67,106,67,88,135,218,23,33,224,92,28,84,211,45,217,68,73,255,166,135,70,216,85,122,156,138,158,99,78,166,237,51,61,210,38,185,192,104,242,118,
102,206,51,220,145,59,226,150,106,221,152,211,44,152,179,28,161,14,206,1,239,174,60,113,45,205,95,190,156,246,160,218,151,86,27,233,189,118,105,46,83,172,248,216,143,252,80,186,242,238,71,210,63,253,23,
127,151,158,15,114,192,230,86,122,230,201,167,210,10,205,147,15,127,239,53,146,150,28,10,93,169,80,106,108,239,225,221,66,170,115,207,60,221,89,126,228,55,252,209,235,15,13,243,87,45,238,223,226,255,178,
39,253,45,100,99,81,5,123,231,144,90,220,97,123,46,237,220,161,33,244,226,235,250,148,11,38,253,139,233,39,63,251,130,244,206,26,119,96,203,177,97,219,54,198,208,0,171,229,216,1,219,145,227,29,138,81,
113,196,229,77,156,243,97,250,180,99,124,44,5,60,179,81,245,197,151,48,98,200,31,182,0,60,47,82,242,110,33,205,23,128,24,115,14,156,12,149,231,151,178,233,15,46,215,2,152,242,188,196,197,98,250,113,81,
139,231,72,141,23,107,233,97,71,51,185,11,214,230,208,250,101,96,55,38,44,186,106,179,94,68,129,24,38,166,131,212,190,160,78,127,78,192,216,33,124,25,66,218,61,91,74,223,136,236,48,21,189,50,150,229,174,
75,183,55,181,67,86,240,124,87,29,190,13,7,60,118,136,206,30,40,123,135,248,100,75,156,201,18,226,253,6,71,20,227,84,58,61,51,33,231,101,169,251,88,116,12,13,220,74,101,101,38,192,93,208,185,239,144,235,
152,211,42,104,72,45,131,84,127,166,157,131,99,48,3,139,114,96,219,170,232,115,44,178,230,180,41,50,102,67,79,56,166,5,40,104,113,64,37,61,198,233,170,22,230,122,95,145,94,174,24,67,219,194,206,42,138,
148,99,243,171,81,15,122,210,153,195,8,222,123,133,226,224,144,8,218,60,167,112,157,238,18,0,148,246,211,185,123,213,75,171,202,143,232,181,206,1,186,194,17,226,3,204,164,36,41,63,233,143,70,77,25,59,
63,69,205,160,25,121,248,180,140,177,97,66,137,164,39,242,229,190,217,184,23,30,52,211,202,249,189,244,77,91,221,244,238,71,31,65,189,187,146,246,109,237,254,205,255,241,31,51,245,147,210,159,251,147,
127,42,29,126,233,75,150,23,173,164,27,50,174,227,123,219,51,145,232,188,81,177,246,209,65,90,122,238,25,243,160,71,233,149,175,28,164,231,62,250,77,233,59,62,246,251,238,252,230,239,253,93,127,97,246,
130,15,255,243,111,125,7,178,203,144,200,114,221,152,211,124,43,93,169,87,211,77,11,102,150,48,130,186,134,156,71,80,201,0,228,23,224,244,107,116,122,134,244,85,15,90,199,214,228,93,224,174,74,121,208,
240,10,80,133,98,244,16,69,136,136,158,35,228,129,27,218,12,79,147,21,153,120,142,76,190,110,122,30,9,27,205,108,85,13,181,130,44,208,53,222,240,58,227,57,37,148,85,18,98,182,208,192,76,93,65,22,241,122,
29,240,139,24,61,194,31,171,232,49,198,202,251,202,236,176,26,75,19,117,35,115,142,186,179,30,189,198,214,153,104,25,61,133,94,58,44,181,180,47,24,58,196,119,81,26,124,93,20,171,97,238,28,232,237,245,
161,149,139,234,222,69,145,180,47,130,182,141,181,141,99,77,95,252,29,176,132,249,3,93,32,179,156,195,210,10,2,122,131,234,187,26,44,100,69,134,82,219,217,84,189,40,118,230,231,10,222,71,217,243,248,139,
148,83,135,85,92,83,3,113,0,31,131,242,157,107,243,108,68,85,144,14,0,46,12,255,129,244,252,53,244,189,173,34,77,36,59,243,70,150,19,79,105,233,14,50,39,105,11,224,131,87,196,65,24,135,139,105,159,11,
75,99,245,150,91,82,208,30,154,222,17,71,116,192,73,133,122,222,105,104,0,49,226,176,170,186,154,124,194,224,247,165,248,115,12,47,104,126,47,55,129,78,1,228,80,208,239,41,57,26,174,171,36,123,80,128,
164,203,50,134,178,210,37,150,29,5,153,34,30,224,47,164,244,248,204,60,162,14,117,47,158,211,119,189,78,250,99,239,181,3,138,15,245,244,196,71,63,154,38,183,223,159,78,41,89,252,189,191,247,143,210,150,
158,243,251,31,191,140,94,104,168,28,242,220,69,135,92,150,98,247,246,15,140,203,173,168,141,167,233,47,253,157,59,105,176,242,84,250,141,255,225,31,223,121,223,183,126,236,247,198,211,63,124,252,218,
238,64,190,136,63,90,1,182,172,54,182,210,238,225,61,133,148,136,102,80,121,42,53,141,21,11,55,215,151,73,85,72,187,28,136,238,209,3,67,199,218,240,64,160,121,61,197,154,148,102,85,228,154,232,79,134,
180,98,76,74,76,49,58,158,17,77,58,12,116,99,13,179,7,112,241,134,180,243,153,91,171,68,132,59,233,175,191,214,166,226,61,76,191,105,13,201,193,52,253,57,138,222,235,198,200,202,158,167,1,101,173,21,236,
216,116,80,58,192,155,43,155,107,230,242,8,39,171,155,98,141,64,140,163,69,52,201,147,173,140,20,181,172,230,237,96,14,236,3,151,238,34,173,111,45,74,9,29,202,188,72,90,93,71,216,222,139,86,74,131,246,
46,68,51,20,250,92,39,202,146,3,27,50,35,65,12,176,91,197,233,140,153,206,197,250,53,233,245,66,106,26,16,63,5,122,93,24,85,90,145,29,212,22,129,87,167,82,105,123,64,131,30,135,232,56,107,216,7,120,52,
9,222,27,18,70,69,90,56,239,154,201,1,169,113,23,136,79,153,243,228,164,206,25,205,17,228,247,190,90,239,221,230,68,75,196,202,150,240,144,131,220,223,227,8,154,40,129,13,189,224,9,106,98,129,186,192,
129,20,127,28,219,199,100,40,227,170,195,238,26,171,180,121,138,34,115,212,246,154,53,200,234,103,218,31,68,180,148,25,85,17,114,51,62,119,127,206,64,179,171,144,220,30,54,80,32,179,5,17,247,129,224,27,
125,214,121,215,221,100,220,161,240,23,232,114,252,157,109,52,51,244,182,40,146,134,66,225,99,239,216,74,223,184,177,144,62,191,123,148,254,209,157,227,180,112,255,147,233,226,231,62,103,127,141,129,7,
192,222,55,162,209,213,87,54,100,44,48,10,41,240,47,181,7,233,185,219,165,244,45,143,19,148,6,6,181,95,111,167,63,249,103,158,79,59,52,106,127,224,195,31,121,125,241,169,247,125,155,62,236,67,0,40,62,
159,95,227,35,159,143,137,10,104,233,228,196,26,0,140,144,53,141,190,50,148,242,198,147,234,136,15,60,149,150,105,133,30,191,240,42,22,16,47,126,50,111,130,129,88,148,232,215,140,237,206,200,205,32,72,
230,162,22,115,78,99,203,240,68,93,57,36,226,156,17,113,206,13,217,54,214,43,105,13,9,116,251,172,169,206,145,150,57,24,215,164,117,91,93,114,153,192,155,2,160,228,190,233,148,134,233,132,178,118,199,
0,26,186,177,184,152,238,130,13,59,154,240,243,94,47,143,46,40,201,156,165,120,241,62,11,230,65,131,211,59,210,54,153,168,167,22,229,124,79,150,214,204,95,34,188,147,73,25,217,209,185,175,101,147,1,248,
196,66,216,233,8,235,199,224,232,130,141,100,79,136,180,251,218,52,93,173,160,169,33,103,25,98,100,227,38,95,60,15,84,114,138,20,59,84,175,21,13,67,231,24,100,44,175,205,51,166,50,244,179,163,174,43,136,
24,209,146,104,48,202,51,84,193,158,159,169,215,232,208,70,219,193,245,194,104,76,185,48,4,165,194,72,191,113,196,240,150,101,30,177,14,177,44,3,88,203,1,137,92,227,89,57,54,120,83,40,39,112,85,192,68,
26,233,127,182,124,22,45,25,193,187,188,55,54,128,254,55,239,239,25,226,196,14,74,209,117,226,94,133,210,67,151,83,90,147,18,7,250,187,39,154,142,131,17,165,201,90,244,245,11,209,115,30,11,233,44,192,
58,14,45,246,130,150,253,12,255,203,160,33,208,34,252,128,35,61,150,238,174,184,174,250,124,21,74,223,79,47,159,153,240,145,187,198,130,170,154,76,99,106,170,38,232,137,79,172,232,25,155,4,186,162,255,
124,228,179,235,40,99,186,129,134,147,14,253,29,239,184,150,158,124,191,22,203,250,66,250,231,127,247,151,211,79,238,180,211,159,253,211,63,152,148,162,191,189,148,169,61,52,204,95,163,81,190,245,99,249,
53,136,195,80,52,68,214,0,48,248,96,68,145,2,154,93,217,136,214,200,8,211,201,157,7,14,215,17,50,242,48,125,242,112,63,61,81,215,163,20,62,154,120,172,53,116,184,93,224,68,1,152,33,16,56,216,72,220,120,
177,5,39,254,78,243,44,85,219,150,206,224,149,54,105,221,108,78,86,16,197,29,126,135,237,6,206,236,136,76,255,28,80,230,218,252,58,98,66,76,187,244,210,238,113,153,60,138,141,83,192,150,116,208,72,219,
247,153,243,6,168,223,129,239,242,214,17,55,195,9,100,57,4,115,31,209,186,132,74,50,10,208,127,201,117,156,169,171,86,136,96,15,53,57,135,234,231,251,34,109,134,190,238,186,246,194,60,9,145,142,81,167,
14,16,72,254,101,114,69,180,245,245,137,104,18,252,210,126,176,139,188,64,0,61,21,244,187,78,48,231,161,177,193,237,156,47,65,120,3,201,4,4,197,26,190,169,52,186,172,213,114,1,64,89,198,204,169,74,95,
249,53,215,36,202,99,90,197,66,222,185,122,136,48,23,212,182,157,244,136,54,75,129,209,207,73,243,115,238,111,94,137,80,97,244,37,130,61,23,128,177,192,130,215,181,28,130,67,59,42,138,172,178,141,234,
4,5,18,130,219,20,109,3,125,205,248,190,133,224,201,122,141,129,209,183,218,28,93,247,185,7,132,200,108,71,147,198,247,56,166,130,20,51,35,98,143,24,125,44,98,90,246,121,108,16,1,159,42,21,130,228,112,
28,32,13,227,83,129,112,42,158,199,231,145,229,104,135,178,142,152,86,153,247,222,135,200,10,171,203,11,86,67,16,228,134,92,47,114,192,161,96,88,86,248,239,218,104,93,211,218,217,152,59,78,239,126,78,
29,194,9,220,251,244,131,116,93,15,244,11,95,60,74,127,240,187,63,148,62,242,237,223,254,51,199,207,124,215,203,41,253,233,183,206,216,195,223,127,141,119,32,31,108,150,83,116,173,21,232,107,32,163,29,
155,182,150,86,175,161,188,209,190,121,227,8,114,184,104,154,0,42,107,33,78,70,61,115,85,221,153,63,185,11,45,13,21,180,168,57,113,67,203,38,47,252,163,34,116,160,31,152,163,164,232,46,10,92,50,247,89,
69,199,43,48,154,138,41,149,163,238,41,118,17,205,91,76,156,29,8,106,89,223,51,102,45,155,208,202,60,145,167,146,182,201,64,52,234,48,214,41,111,158,135,100,54,112,217,98,5,224,28,32,103,6,144,248,111,
116,5,162,78,140,102,252,105,164,186,14,81,68,216,156,40,145,181,95,99,20,81,74,43,35,79,128,184,69,188,108,133,231,95,201,147,96,108,1,167,128,42,115,162,69,203,28,233,41,208,165,19,194,97,254,137,25,
75,148,87,105,182,20,93,144,14,169,143,117,134,24,98,93,109,17,122,100,162,228,88,253,56,114,77,181,104,211,176,228,121,11,134,131,246,86,102,8,167,244,140,86,124,61,86,211,241,19,140,151,182,18,227,239,
187,200,69,105,106,65,90,93,18,101,207,80,246,52,130,12,43,171,189,57,132,190,159,89,68,78,152,154,2,138,182,206,45,74,229,197,21,195,204,200,11,83,58,61,115,196,149,46,144,33,98,155,248,188,14,109,203,
231,212,35,82,150,177,208,36,86,98,180,69,206,170,76,164,171,126,239,249,21,156,220,160,250,173,134,163,241,235,117,98,103,118,0,207,12,178,197,185,4,135,57,38,93,102,17,88,93,156,229,76,114,156,12,209,
23,67,230,101,235,48,176,130,76,243,236,236,238,65,143,125,80,94,107,222,80,194,197,152,88,151,84,58,134,184,111,63,158,210,141,141,90,250,153,231,5,199,77,229,198,252,177,45,226,165,244,236,115,207,253,
108,241,153,239,250,158,91,153,248,132,30,62,254,191,222,129,108,41,115,148,58,102,51,123,40,107,33,19,49,97,116,37,41,43,201,61,41,225,158,232,200,80,246,244,45,213,160,183,80,241,106,166,247,98,177,
106,71,116,106,131,225,71,126,102,6,4,49,205,64,108,199,168,123,175,97,13,229,140,72,45,45,213,83,206,135,150,65,207,155,39,211,81,210,180,159,170,227,152,206,108,162,226,72,61,211,149,42,133,82,95,44,
180,201,155,138,201,72,189,42,218,23,235,64,135,44,169,146,177,175,53,28,142,32,180,71,250,236,188,165,177,200,204,255,167,222,177,131,110,177,205,57,194,126,205,2,157,97,180,131,28,253,190,8,211,99,92,
99,135,112,42,61,86,13,170,171,136,101,115,34,203,13,138,177,85,218,67,210,218,177,25,197,33,98,133,167,194,8,66,10,128,102,182,164,153,157,209,38,126,174,52,14,226,217,194,123,13,67,159,48,208,64,136,
163,151,218,66,48,224,87,180,85,0,93,152,74,251,156,68,79,52,175,136,224,3,223,123,71,52,174,143,234,64,41,81,215,235,220,103,173,35,17,42,27,153,67,238,72,20,220,159,13,28,87,220,235,53,125,157,2,83,
133,255,43,0,0,32,0,73,68,65,84,0,172,43,195,200,120,207,101,20,188,146,33,209,166,158,236,136,117,5,1,160,54,3,116,92,140,55,95,150,114,198,138,134,118,212,184,210,203,175,112,104,111,72,157,59,102,38,
91,90,41,213,48,52,64,214,156,212,58,190,191,226,117,151,224,8,253,232,131,70,212,70,183,140,12,102,44,19,217,84,134,108,0,179,22,3,40,146,14,199,198,177,154,242,229,62,61,169,158,76,225,230,202,122,186,
2,101,174,65,177,43,90,92,79,226,5,243,124,234,85,124,104,219,224,78,181,109,10,184,212,189,163,211,244,93,191,231,187,211,35,31,254,198,67,134,169,115,251,240,241,181,184,3,217,21,55,251,138,232,183,
201,200,230,124,8,101,7,100,112,114,47,109,191,220,230,245,27,105,104,246,50,123,139,119,215,131,124,68,147,187,115,126,128,177,163,5,128,213,178,38,170,133,56,212,148,247,14,148,50,56,163,3,84,186,35,
191,162,79,50,32,168,197,102,200,73,74,241,206,234,52,118,164,185,182,152,169,46,211,117,100,134,119,110,93,194,183,85,11,74,203,42,90,33,165,141,216,92,69,166,226,156,18,59,79,157,61,164,221,51,217,18,
48,3,53,125,51,173,141,55,29,135,115,226,122,43,53,194,212,166,75,46,44,40,58,161,159,90,87,19,94,5,74,249,42,169,21,198,110,3,114,99,1,55,150,122,195,200,97,59,167,67,211,54,117,131,128,55,219,50,70,
142,119,86,39,198,222,205,34,193,169,19,8,239,30,196,116,82,56,84,63,95,88,100,20,43,7,188,1,45,155,54,197,57,65,55,149,100,25,161,59,235,232,75,243,74,233,21,28,218,72,151,7,12,240,4,72,178,168,166,141,
250,243,208,174,148,137,200,218,144,109,172,106,71,13,176,126,154,227,88,244,14,104,50,18,21,235,1,85,137,238,183,218,17,48,52,101,48,43,28,64,86,10,58,192,50,154,51,216,30,195,220,83,227,122,231,174,
37,214,4,198,3,191,202,243,73,59,227,158,64,191,251,178,138,216,25,115,202,201,53,99,28,133,14,140,151,247,90,130,30,237,167,53,247,121,16,253,93,212,200,13,200,247,20,137,127,17,0,180,100,10,102,221,
116,79,164,215,1,180,133,44,204,170,213,28,129,204,134,195,93,242,153,77,206,118,81,9,165,202,248,180,5,148,192,237,139,251,210,116,99,129,43,171,72,12,198,218,48,202,254,233,23,233,71,157,110,166,91,
223,252,253,167,55,159,254,206,191,60,187,200,135,255,249,154,220,129,108,215,7,211,166,1,179,47,173,194,166,115,40,163,254,48,46,188,240,244,108,59,215,240,174,122,112,218,48,67,153,81,151,134,218,153,
67,97,85,220,25,234,92,11,107,135,3,118,184,98,221,107,196,52,209,68,13,187,40,122,212,173,118,232,157,72,77,253,253,186,190,97,23,162,72,73,153,89,182,232,180,221,183,222,160,106,129,42,64,95,6,20,189,
203,33,30,45,40,134,82,130,29,144,210,202,61,147,50,19,155,201,198,234,174,129,104,145,227,161,131,102,23,191,150,234,171,234,64,181,110,213,74,66,236,237,169,84,177,234,112,213,26,103,196,156,161,184,
144,214,9,194,117,14,202,184,184,176,162,15,136,193,43,213,158,196,254,151,86,3,34,75,129,29,25,160,41,149,61,215,255,140,199,88,221,121,223,91,24,1,89,178,174,233,204,206,244,113,40,63,68,111,82,61,151,
23,133,67,25,111,30,97,123,73,150,177,106,10,166,199,41,133,156,231,188,168,178,97,29,158,32,196,112,69,106,12,161,1,16,171,239,185,42,208,208,21,105,107,62,116,97,213,185,49,26,214,136,26,82,219,40,203,
177,229,161,210,35,123,61,106,139,101,166,234,58,237,111,41,45,209,236,93,193,208,146,10,15,24,92,19,121,97,183,89,32,127,226,207,20,28,78,93,119,223,22,236,144,228,92,142,190,49,103,21,138,238,21,0,84,
15,203,74,162,41,227,32,61,227,115,248,4,20,247,151,141,123,28,33,252,135,106,221,84,193,25,171,23,55,253,204,72,161,252,37,66,108,71,34,253,153,212,27,28,128,80,47,122,59,1,163,14,105,110,89,193,161,
50,167,233,51,8,176,234,203,90,44,151,56,185,149,39,173,125,231,168,63,115,124,156,254,193,46,30,240,71,190,147,56,116,246,99,171,213,194,243,179,155,249,240,63,95,147,59,144,239,72,105,14,165,148,27,
162,70,232,151,246,128,3,35,94,217,10,78,44,112,70,177,70,246,66,143,238,60,102,160,138,16,76,109,140,145,244,231,212,65,156,167,232,30,61,237,169,40,57,101,148,241,136,45,196,55,213,127,79,222,144,2,
45,1,92,28,212,69,245,99,101,165,159,30,243,115,251,205,88,57,175,7,201,184,75,38,32,198,154,232,3,189,197,50,3,206,236,13,210,163,17,133,165,94,103,106,185,137,9,143,46,224,105,32,149,236,59,60,65,223,
243,31,243,148,77,12,36,179,156,177,228,50,88,46,165,45,17,60,22,230,6,72,227,96,170,61,67,24,185,167,110,187,48,190,114,219,193,175,168,161,207,109,11,59,53,4,214,119,192,130,163,58,29,30,104,127,0,100,
60,103,132,194,10,167,52,159,221,32,88,220,167,2,17,90,183,17,37,101,18,210,238,145,186,53,70,197,72,82,167,134,191,247,55,210,237,190,118,8,64,141,211,201,122,237,21,78,230,126,219,244,7,164,180,33,130,
102,128,43,115,34,102,142,38,207,208,240,229,92,108,15,23,5,247,221,99,1,202,188,42,114,66,24,170,175,15,40,217,101,25,252,156,181,14,211,80,205,99,180,19,84,198,64,105,207,77,215,108,115,140,37,228,139,
93,34,221,182,46,224,22,47,185,219,184,187,254,137,148,127,197,107,98,42,51,76,239,197,200,201,130,54,216,107,52,126,216,33,48,199,219,229,80,131,217,152,83,143,187,28,106,23,74,4,145,57,182,132,151,161,
223,19,217,80,212,180,33,15,26,242,34,252,166,51,176,200,137,157,113,76,22,223,46,111,165,235,183,223,153,174,127,248,49,236,164,81,250,63,236,8,252,244,225,94,122,242,234,226,254,163,191,237,247,252,
253,113,122,236,115,126,234,225,227,107,120,7,242,117,53,224,138,180,135,174,52,48,8,227,198,28,99,153,230,108,85,42,86,87,244,119,199,175,171,45,73,79,158,80,50,64,5,171,56,140,155,26,228,199,34,79,108,
212,10,131,9,111,60,229,149,163,94,236,235,137,46,73,37,55,159,196,166,209,178,152,52,3,132,208,6,240,115,37,198,241,14,35,81,83,156,207,18,239,63,164,161,115,186,99,239,163,185,205,162,8,110,73,49,149,
1,42,227,75,118,117,8,201,77,116,181,199,241,100,199,210,172,241,40,146,85,175,233,205,231,188,222,42,167,208,55,229,18,180,188,146,240,28,99,78,193,183,173,232,117,102,29,206,18,3,143,20,241,40,182,117,
91,58,25,43,232,129,176,210,242,115,194,97,52,107,12,115,230,160,153,177,61,59,206,115,137,211,57,97,164,3,145,56,47,245,237,136,186,45,83,24,55,69,171,58,231,144,65,36,0,78,207,148,225,67,165,32,227,
245,158,89,47,164,43,81,199,185,246,12,128,71,128,53,215,105,14,86,159,115,222,194,218,80,209,59,212,90,138,41,238,5,164,134,155,248,203,103,16,112,3,59,234,62,131,224,193,25,166,173,212,3,80,145,189,
82,7,139,220,106,212,17,141,161,139,72,111,165,233,160,103,239,153,26,161,20,190,46,138,183,180,142,250,174,41,54,159,85,220,195,101,169,247,1,167,242,242,33,112,75,116,142,245,125,117,181,231,177,233,
151,80,101,88,5,22,61,2,120,26,251,218,142,246,207,158,251,219,112,63,249,69,61,235,175,130,88,222,119,101,8,8,148,29,236,171,99,39,238,99,1,1,36,134,3,242,196,201,150,1,65,251,199,15,210,239,255,131,
63,154,190,149,216,214,209,223,250,207,210,167,191,108,48,214,231,241,99,255,201,239,41,207,47,60,246,183,169,78,236,124,13,207,229,195,167,114,7,242,11,82,167,173,252,142,102,253,188,37,70,246,130,248,
208,171,189,29,250,162,7,54,95,61,155,174,60,118,219,132,200,174,54,128,52,71,74,123,42,125,44,137,16,107,208,207,189,214,43,32,247,25,70,251,175,111,102,206,244,133,46,225,172,110,201,58,76,25,81,165,
64,141,239,20,130,82,147,210,25,169,156,69,163,35,64,72,23,176,114,30,209,174,99,99,180,52,183,94,222,181,11,179,163,29,195,152,79,244,51,237,55,105,208,16,202,59,126,19,169,102,68,171,72,107,27,11,102,
77,213,85,244,180,102,91,206,118,142,143,210,42,14,232,82,141,214,81,212,127,83,77,253,224,163,66,76,11,230,71,139,177,217,57,80,85,34,87,35,68,132,249,178,212,45,218,31,174,58,244,88,163,63,59,135,210,
51,9,99,218,179,231,113,41,24,53,248,181,22,226,28,162,217,245,244,47,107,166,59,224,61,179,69,63,124,146,121,204,152,48,245,124,65,78,87,71,231,212,137,39,82,234,150,191,12,121,204,2,99,205,74,119,131,
120,95,195,146,50,82,13,233,5,148,153,30,105,132,195,225,196,98,127,194,29,125,211,1,9,151,77,83,59,167,34,50,132,137,220,36,0,12,183,54,35,188,198,180,74,119,70,194,160,142,200,112,170,34,105,217,115,
84,17,11,230,101,59,115,88,90,199,8,14,244,189,24,52,7,39,19,18,152,189,127,61,202,208,27,246,103,212,232,25,128,118,2,92,234,113,180,231,56,196,171,222,179,91,2,41,230,60,165,182,196,18,211,5,73,154,
1,229,1,193,53,61,106,16,183,7,100,202,246,207,240,157,27,210,111,204,165,207,255,68,250,249,79,220,77,31,172,117,210,51,152,100,239,125,247,230,244,189,223,246,193,255,5,206,247,169,127,125,0,30,254,
207,215,236,14,100,31,236,113,206,14,242,61,116,185,227,253,144,189,36,31,226,67,205,66,91,219,124,97,172,84,159,39,104,85,49,155,153,51,45,18,240,253,96,106,137,233,24,234,232,3,62,103,168,111,66,21,
14,0,131,153,215,211,44,70,203,162,27,251,37,99,93,131,222,158,40,16,91,202,26,164,63,90,118,90,220,63,239,248,26,80,66,84,169,25,241,106,72,253,222,75,51,100,117,69,170,22,7,76,179,189,198,48,231,35,
18,75,177,79,68,149,1,121,147,144,117,20,52,49,120,40,207,209,202,29,34,100,199,210,223,37,108,154,229,226,50,0,11,141,15,197,46,174,57,15,125,205,73,23,47,1,101,150,182,174,105,177,92,154,53,207,91,104,
108,107,54,43,111,154,130,241,84,179,71,252,30,218,178,241,123,87,158,254,70,7,11,202,225,172,0,67,14,93,235,125,134,55,166,227,90,165,134,16,216,180,82,81,205,27,43,22,244,29,99,202,3,95,118,234,207,
33,219,9,104,157,41,41,220,129,126,102,245,90,13,176,232,89,134,212,151,121,83,198,23,173,159,83,180,194,161,168,55,91,61,232,25,231,0,66,39,0,177,2,196,119,158,34,97,3,27,104,89,38,146,119,77,241,115,
248,65,51,9,201,118,212,134,140,183,70,45,225,2,81,228,69,245,238,103,198,123,72,245,28,159,222,233,162,214,141,94,141,107,65,5,36,3,115,174,126,63,118,223,79,124,78,71,106,204,80,219,171,169,227,23,129,
72,18,139,244,42,64,236,4,63,184,33,171,153,112,40,167,208,247,216,148,29,169,120,221,12,238,50,192,233,26,242,251,117,83,68,143,219,143,90,121,241,179,105,240,202,171,202,14,227,109,20,180,223,251,193,
247,142,174,44,173,252,23,202,2,230,255,240,241,181,190,3,217,38,246,204,68,250,118,206,40,43,91,1,84,0,21,2,37,109,44,105,21,28,165,139,87,80,205,180,70,122,164,31,47,66,34,223,81,41,72,107,171,234,153,
186,159,41,128,233,167,193,244,158,61,80,175,69,142,144,27,201,248,64,51,122,115,121,104,231,52,34,139,159,205,178,222,82,73,36,100,176,1,48,77,77,171,68,68,169,50,166,130,40,231,137,29,12,233,39,164,
48,34,243,227,52,134,202,14,210,171,188,251,3,253,182,28,99,152,229,160,88,42,33,239,88,80,187,246,68,183,73,180,41,48,108,50,16,219,37,2,101,35,138,8,175,233,73,78,168,199,133,96,88,150,151,153,218,100,
117,79,253,250,58,67,9,48,8,191,128,97,71,180,137,6,205,155,143,136,202,98,62,160,229,220,215,9,96,27,215,170,33,76,220,192,57,141,84,48,54,117,245,177,121,166,126,69,132,10,1,159,154,218,53,84,4,246,
184,168,81,21,213,78,13,57,64,195,49,246,108,24,157,0,202,208,136,55,64,229,34,70,214,8,57,55,113,122,67,142,242,136,211,185,199,121,52,130,132,239,85,247,135,122,202,208,218,106,238,18,230,83,164,229,
113,59,180,83,48,149,210,72,239,182,187,168,78,37,211,201,120,58,178,155,125,57,116,196,238,104,207,228,164,245,231,200,31,161,150,176,34,162,46,75,155,231,25,234,129,16,170,20,77,235,234,243,40,170,125,
180,216,84,225,92,68,75,245,110,100,45,219,156,209,158,247,61,208,143,221,32,233,249,4,67,189,70,204,123,48,210,247,212,174,25,73,117,94,144,254,94,182,26,254,210,210,162,172,103,62,253,171,95,218,79,
189,155,79,165,204,205,39,126,228,39,234,187,122,81,15,31,95,143,59,144,127,132,206,75,251,236,20,20,128,231,10,184,140,233,249,154,72,145,219,127,0,240,241,97,168,63,23,50,143,248,240,142,210,225,235,
159,242,129,75,167,186,75,244,100,77,68,28,1,88,252,76,129,215,141,199,255,117,87,202,192,70,40,20,24,3,217,56,186,96,204,44,207,59,9,221,198,224,172,54,86,25,16,226,180,40,0,15,181,137,202,46,80,32,146,
245,29,233,118,118,9,141,142,209,211,172,29,59,164,125,105,213,22,110,233,198,202,26,22,145,200,224,96,245,139,155,105,23,203,167,220,58,77,57,175,115,170,109,17,139,133,52,102,69,33,215,34,125,222,111,
181,82,65,228,30,48,212,169,161,231,1,150,79,72,74,174,218,244,213,19,97,247,25,184,150,30,202,96,36,167,111,62,4,53,116,194,106,90,3,166,60,16,165,142,244,49,39,28,211,170,104,83,69,129,186,64,231,235,
56,188,17,105,178,210,86,126,109,198,205,61,160,138,144,195,24,26,144,237,155,66,95,22,104,248,132,180,201,9,196,22,74,165,45,20,155,178,68,51,252,217,50,231,180,170,12,29,203,64,154,156,206,13,169,230,
5,18,70,149,122,126,14,217,224,216,42,130,169,244,183,175,118,28,107,179,148,50,107,234,95,235,218,181,187,4,102,227,106,192,185,241,186,50,246,52,45,219,82,214,80,175,94,184,71,161,51,212,149,105,132,
20,232,5,99,178,211,215,231,230,23,148,124,135,65,158,74,115,163,118,142,79,138,207,146,166,251,172,221,78,210,109,64,62,8,187,20,124,73,205,250,168,108,164,228,222,222,147,3,196,250,194,151,201,216,44,
64,129,151,140,185,141,187,187,86,193,163,249,177,248,71,126,235,213,47,188,255,155,191,237,159,173,103,222,241,86,226,244,213,187,248,240,183,175,213,29,200,30,28,146,197,164,77,33,168,164,254,158,141,
212,162,225,26,113,168,142,104,148,170,100,18,125,80,103,62,252,186,37,184,139,106,178,144,207,204,109,74,125,125,208,15,120,245,115,19,42,125,20,185,217,195,7,158,115,216,232,10,207,162,79,25,201,60,
175,63,115,68,129,237,62,96,40,246,108,246,69,203,80,38,31,141,184,3,227,82,151,165,179,143,17,138,170,73,27,35,93,138,141,85,71,26,240,15,124,111,108,107,62,180,40,105,221,215,214,213,86,83,145,114,42,
181,205,208,35,10,121,200,140,200,20,139,128,186,184,168,161,104,16,68,241,214,174,49,40,89,214,22,82,253,2,3,204,74,1,199,144,160,145,239,89,30,83,73,144,130,14,128,61,121,135,120,202,0,58,145,206,186,
238,124,48,158,68,162,109,215,21,27,191,36,126,220,134,84,14,137,191,171,135,25,224,78,145,22,81,129,243,10,197,189,67,224,74,211,79,12,21,92,136,61,51,37,191,117,25,69,86,4,106,114,52,109,175,61,21,45,
171,164,243,150,107,90,37,44,197,203,57,242,208,95,188,219,121,69,245,80,134,113,36,124,15,189,175,18,227,239,206,181,33,231,116,26,76,237,12,212,129,193,189,237,250,231,84,47,178,8,25,15,122,96,147,97,
44,69,13,42,245,31,249,153,109,17,188,41,165,142,220,5,153,73,196,51,140,237,255,101,172,140,147,65,250,94,19,122,179,210,35,22,56,237,33,112,204,65,105,99,139,223,154,247,93,3,132,69,75,167,166,23,220,
246,186,187,198,1,17,158,56,58,142,7,136,150,122,237,244,158,69,53,234,26,60,226,208,224,252,49,37,120,252,77,115,159,247,215,215,223,241,154,239,124,248,248,58,221,129,236,33,54,208,5,17,172,170,245,
107,203,22,240,244,16,178,23,69,160,181,5,107,251,112,40,123,187,95,209,183,51,221,113,130,77,99,33,105,76,176,156,98,164,116,137,80,143,245,192,192,55,191,26,121,252,95,150,101,230,24,77,0,25,25,253,
199,241,252,41,206,43,29,26,105,232,220,252,13,250,54,36,69,28,209,35,108,155,133,146,9,14,70,183,92,172,205,60,250,24,131,167,192,120,27,250,137,125,232,98,144,172,175,92,186,38,149,178,143,241,208,204,
168,195,21,82,27,27,43,150,199,170,207,234,14,217,132,22,234,37,7,112,153,50,252,198,250,34,10,157,131,174,142,170,57,104,193,112,42,154,229,140,113,182,136,82,47,15,206,102,132,250,3,124,89,246,132,167,
202,104,29,238,156,3,159,147,78,111,57,221,101,98,211,115,210,235,30,134,66,56,168,99,53,117,144,253,207,105,41,109,147,7,24,144,107,244,3,177,113,29,97,28,170,170,221,177,108,111,41,233,93,233,178,63,
11,150,49,75,57,241,124,121,78,167,39,237,223,135,78,31,72,149,251,35,162,221,102,78,207,144,52,6,200,0,13,41,233,130,123,77,6,200,123,108,51,102,160,152,90,58,111,244,77,139,85,29,140,107,91,38,41,201,
177,100,165,192,175,33,248,63,224,104,14,250,65,162,40,235,171,130,202,76,21,245,144,43,150,220,175,172,235,15,49,174,144,27,17,195,103,123,55,199,50,131,208,225,117,235,220,23,76,40,169,249,62,34,197,
27,12,62,246,203,12,57,147,32,222,183,93,120,143,160,218,107,240,129,207,3,158,238,185,230,58,226,252,135,87,74,233,219,55,161,226,212,19,79,244,58,95,226,168,206,235,27,253,155,239,251,230,159,253,58,
157,201,135,79,251,213,59,144,191,141,26,215,87,87,228,165,111,75,70,192,122,160,247,19,7,185,97,120,118,66,79,104,32,181,205,31,238,74,171,56,81,107,221,50,82,157,34,161,175,41,164,113,135,170,64,215,
48,115,221,176,85,28,240,81,0,24,190,207,57,81,199,154,188,143,222,156,3,176,76,174,100,100,29,65,174,184,110,212,236,28,211,100,223,124,165,20,76,42,125,214,59,178,204,200,186,115,147,41,25,236,22,101,
102,106,220,64,189,211,204,155,106,115,76,81,140,166,72,14,73,74,21,172,247,144,113,108,174,45,72,187,82,186,206,81,92,115,61,74,35,26,55,77,217,172,29,39,234,165,24,247,106,105,81,12,59,4,186,246,69,
28,178,36,50,55,40,170,154,82,171,35,246,125,116,33,162,129,216,198,162,160,89,51,48,162,133,214,74,70,59,41,7,241,189,236,181,6,98,208,178,52,190,194,8,66,14,196,236,56,4,155,67,112,176,231,24,108,69,
100,239,106,65,228,213,199,71,82,246,188,72,101,216,142,83,65,35,212,10,186,236,61,222,145,114,119,58,85,76,168,115,12,29,115,152,184,188,77,132,138,186,186,123,232,26,6,198,228,10,164,246,234,229,138,
181,13,231,100,82,132,57,172,32,120,210,108,183,76,48,116,98,245,214,27,246,165,198,52,201,178,182,84,79,73,48,96,116,27,222,251,21,232,234,3,6,118,40,19,136,209,183,89,207,214,181,94,168,37,135,190,127,
44,122,71,93,173,77,204,41,74,219,165,242,177,3,103,239,128,83,18,205,179,250,195,51,25,24,127,113,225,122,214,57,147,156,116,60,118,144,62,77,98,230,125,183,237,199,116,54,94,217,229,216,220,145,140,
90,246,163,239,124,164,253,244,123,191,231,207,127,245,12,61,252,237,235,116,7,178,121,163,71,39,122,143,123,168,92,35,53,75,236,148,92,39,213,184,182,90,145,86,45,167,174,89,198,115,235,144,39,116,122,
26,139,54,121,209,166,41,106,91,220,147,6,79,181,67,198,20,250,90,166,253,35,37,140,127,6,134,117,239,137,120,93,81,214,60,74,186,32,197,145,213,36,95,20,167,198,5,6,36,53,156,74,69,107,140,34,86,213,
149,20,64,67,94,123,4,208,152,152,134,153,32,216,119,204,83,158,96,175,104,126,88,183,222,156,237,12,109,112,253,49,51,26,192,198,252,224,10,190,168,40,167,241,24,175,210,169,67,131,129,72,157,206,124,
186,75,247,232,68,49,152,211,26,42,229,150,165,179,106,93,76,151,45,207,253,36,166,208,85,195,210,19,7,177,235,154,34,250,101,24,225,91,143,176,211,224,233,102,22,12,154,79,76,125,0,69,12,84,146,204,244,
206,212,191,117,138,114,69,116,184,192,38,149,219,234,90,19,31,106,207,62,146,197,118,68,117,215,155,5,174,197,102,177,51,131,216,243,34,223,156,58,183,170,223,184,0,80,154,211,187,24,20,130,7,75,251,
87,164,12,112,169,125,212,182,197,43,118,123,150,56,183,19,28,97,4,247,217,189,3,116,49,156,11,158,110,158,180,230,16,157,113,217,252,230,109,195,216,161,164,16,78,106,94,171,163,173,162,152,40,19,34,
98,202,213,25,160,90,153,108,138,55,78,171,41,214,28,198,12,106,136,116,97,6,49,204,224,138,176,107,212,187,137,205,225,50,19,63,215,116,167,219,156,205,136,211,170,245,234,233,81,104,212,251,212,183,
43,13,189,109,6,124,110,223,73,19,33,229,249,151,125,126,16,235,223,248,187,191,167,242,133,233,158,155,243,240,241,245,188,3,217,99,7,119,202,19,199,114,31,229,39,205,25,189,45,72,231,169,34,244,53,180,
189,198,173,15,164,203,215,31,215,247,91,33,101,161,135,137,240,190,190,74,52,10,237,77,105,166,110,99,30,206,69,60,2,237,44,24,41,130,142,248,147,40,172,61,211,107,173,232,135,90,247,7,209,205,93,2,0,
25,147,106,51,162,88,92,59,165,98,14,146,73,151,104,236,84,117,224,75,254,92,172,91,146,103,23,102,110,66,124,75,100,156,104,11,136,29,102,39,213,70,12,36,30,161,132,16,203,119,58,22,48,237,137,222,99,
77,242,24,245,42,56,252,149,252,218,236,245,179,180,111,59,40,110,61,181,231,146,86,209,62,102,205,27,0,162,19,19,44,115,172,242,74,166,129,209,19,87,9,60,137,20,220,243,70,250,119,44,133,28,137,250,221,
92,59,29,99,234,20,227,224,187,23,29,17,163,201,42,71,34,93,236,163,212,230,132,58,75,213,165,165,45,211,35,3,160,208,1,110,237,200,235,157,233,29,39,253,213,81,139,238,18,185,150,38,14,242,235,20,2,143,
185,168,49,84,167,34,146,197,14,204,121,172,156,88,221,55,209,243,188,43,61,157,132,170,0,112,232,2,9,66,203,84,141,169,238,197,24,50,76,107,248,28,178,45,229,47,217,69,57,85,130,140,57,151,158,122,54,
150,76,229,93,91,140,204,141,165,190,19,159,15,60,73,175,152,147,97,144,37,159,201,41,96,107,32,245,153,147,98,212,41,1,238,199,187,142,207,90,10,125,234,233,11,238,107,13,227,104,81,121,209,89,48,103,
42,51,216,211,131,62,118,207,61,93,122,229,224,129,207,57,32,195,97,250,240,71,63,144,10,107,143,253,217,119,166,117,238,249,225,227,235,121,7,242,13,0,69,172,84,8,193,226,178,72,24,211,8,177,220,182,
4,134,127,66,13,186,249,132,41,141,207,109,35,136,31,203,250,160,167,145,142,233,99,210,175,10,145,59,243,131,234,76,233,236,91,143,152,229,188,234,47,131,80,61,237,73,49,153,86,91,58,57,87,94,55,1,162,
142,212,163,108,5,122,169,209,54,116,224,90,40,116,213,234,134,20,75,235,133,4,100,22,64,52,44,3,75,140,116,133,76,138,170,245,77,87,31,196,3,47,50,115,0,250,165,53,209,153,125,154,4,105,56,92,117,117,
51,67,40,74,187,194,40,24,92,199,1,108,153,65,29,88,140,20,202,235,167,34,228,161,227,110,232,11,77,45,151,46,33,198,151,2,201,245,79,172,178,151,15,166,75,126,6,175,129,220,24,67,7,103,94,168,139,107,
156,200,72,237,28,219,190,231,165,143,23,12,118,134,110,242,63,235,232,137,49,114,55,56,65,131,235,86,189,31,147,26,88,80,203,75,151,244,105,9,165,13,239,105,181,212,144,1,170,38,85,68,66,200,237,24,185,
224,64,218,248,56,69,132,140,145,172,163,179,67,136,43,160,140,49,44,171,249,186,106,220,156,90,190,162,108,120,195,103,18,64,213,2,67,142,186,119,102,80,162,97,159,97,158,2,201,10,17,229,221,199,170,
116,182,229,179,235,187,150,5,245,118,124,26,81,167,55,248,136,136,176,45,41,238,20,9,36,24,86,25,159,53,28,206,189,194,245,229,136,114,34,236,130,225,129,169,40,90,152,1,123,122,152,178,128,55,142,38,
233,25,224,219,18,192,171,203,89,220,166,81,244,31,220,172,218,137,249,91,211,202,230,83,255,76,250,236,131,121,248,248,122,222,129,236,220,85,224,202,38,208,64,19,123,65,116,172,217,167,248,128,55,30,
74,109,22,129,44,23,56,117,77,11,83,243,151,30,77,181,205,75,228,75,186,162,137,131,233,112,47,74,121,54,106,155,160,121,31,238,236,42,29,82,104,104,247,0,72,209,54,45,194,88,206,161,146,153,2,194,130,
221,32,147,7,106,73,253,205,172,22,139,109,57,169,127,36,13,38,83,50,69,72,8,234,80,80,214,2,200,80,8,65,47,204,83,74,173,51,66,212,144,154,94,38,14,93,20,179,241,16,97,70,49,198,164,87,216,147,70,247,
68,201,48,218,85,44,155,161,230,120,39,118,126,90,119,94,27,216,159,230,233,14,131,42,23,27,175,161,193,145,215,117,189,206,231,204,154,222,213,55,140,206,173,31,69,0,8,29,164,32,22,4,122,235,253,58,208,
121,92,96,87,96,79,73,104,244,74,75,165,171,231,0,161,136,223,99,209,247,254,14,114,190,208,130,33,200,236,9,119,153,220,8,113,174,158,45,187,35,226,203,125,142,233,4,178,220,7,158,133,162,254,100,176,
135,252,96,122,6,69,47,104,124,231,94,255,72,52,59,83,115,46,75,183,243,200,252,53,245,178,216,72,246,196,188,43,117,134,1,50,192,57,39,53,224,128,152,236,76,157,239,140,40,218,32,210,95,53,113,29,45,
48,52,124,163,222,45,35,29,116,93,255,185,95,5,185,107,212,165,219,74,149,140,116,188,43,43,65,186,82,159,162,11,138,168,125,96,84,95,186,90,145,85,100,181,174,150,120,186,223,32,11,186,142,17,21,88,64,
120,130,203,26,163,11,254,190,164,78,127,253,0,41,228,246,163,105,243,221,31,124,169,56,95,136,167,122,248,248,58,223,129,236,206,145,52,199,250,243,45,181,103,69,58,119,191,121,145,222,32,89,113,79,196,
249,242,107,219,233,227,63,254,113,77,244,92,42,111,72,83,9,117,157,232,129,22,48,73,174,47,27,232,181,43,32,164,40,99,14,52,30,130,143,15,221,159,161,15,83,0,199,80,234,59,205,159,217,255,17,195,81,116,
123,16,213,231,60,87,240,97,167,14,67,79,77,91,44,46,58,96,162,47,208,35,131,131,182,224,207,133,185,43,166,63,200,140,72,15,71,184,157,199,106,186,195,195,109,70,19,177,83,171,100,186,147,238,33,216,
15,92,243,6,38,147,121,97,51,193,162,18,240,165,136,204,144,13,192,74,248,152,170,171,218,40,129,217,242,190,77,215,163,244,30,59,90,174,226,206,70,11,161,47,130,180,164,165,202,52,223,24,87,239,183,37,
253,81,145,117,40,69,60,109,106,255,216,133,50,70,96,15,25,206,166,8,170,93,168,121,47,85,180,97,108,18,66,95,192,171,88,50,212,84,207,230,60,191,43,192,164,130,208,186,182,160,238,93,34,216,29,97,172,
43,35,24,72,97,143,244,96,199,0,177,57,17,170,229,2,137,51,0,125,236,61,69,69,47,129,123,251,72,27,7,36,73,226,70,46,196,48,2,17,181,134,17,173,151,206,247,210,43,199,77,232,106,37,221,195,44,26,144,38,
93,197,226,106,184,215,153,168,111,25,85,204,175,182,212,154,241,188,19,81,51,84,247,182,253,110,2,79,26,47,181,149,189,44,139,178,53,198,26,211,42,103,222,120,101,206,40,154,168,232,175,210,77,17,94,
143,73,77,76,218,4,210,188,46,155,216,184,98,8,220,154,138,237,237,73,250,204,11,23,105,229,55,254,174,241,234,237,119,254,36,109,160,87,222,188,99,15,255,251,245,188,3,249,201,46,196,149,33,165,185,3,
224,11,129,41,41,207,165,106,35,221,112,8,207,213,75,61,145,144,239,116,152,13,48,75,50,167,154,248,251,56,182,5,147,9,254,4,224,33,220,149,137,100,240,205,199,44,195,21,117,66,83,178,99,156,73,169,151,
150,215,183,102,50,26,125,99,17,103,93,82,33,93,210,23,22,235,70,115,123,14,34,152,81,103,9,120,38,72,68,29,81,88,81,37,2,234,7,70,164,148,122,70,105,26,45,148,153,245,123,205,188,254,169,74,113,134,70,
78,245,31,3,116,153,106,123,140,69,191,33,178,118,25,191,151,15,128,208,50,100,7,127,89,170,73,106,94,29,91,76,143,138,50,219,145,218,26,2,255,109,213,249,180,2,184,153,209,133,216,125,13,164,123,136,
183,58,81,211,245,245,248,234,27,106,77,192,205,161,247,80,241,110,107,12,35,234,223,88,123,152,23,185,178,178,128,208,237,201,104,26,46,107,95,92,198,6,234,1,115,150,161,158,53,53,95,137,44,194,194,72,
123,132,84,200,125,64,91,78,196,156,71,211,91,42,234,27,203,14,198,232,119,193,162,154,50,108,139,190,57,29,236,43,87,44,33,72,35,89,195,88,3,117,224,123,58,210,224,11,220,223,216,99,178,227,222,100,168,
246,213,198,117,195,225,148,36,244,108,187,34,224,174,84,119,232,250,3,152,235,73,5,194,223,188,149,222,183,61,199,37,89,65,148,1,83,253,233,224,47,77,0,80,241,125,49,19,186,46,50,135,206,239,142,244,
56,68,169,131,47,92,115,125,197,104,239,248,167,165,20,89,186,114,133,24,247,220,43,47,127,50,255,99,95,253,168,31,254,246,117,190,3,217,234,141,88,185,62,74,159,178,199,242,231,49,193,123,180,110,154,
23,62,108,189,182,76,233,44,61,126,185,75,117,45,192,63,9,167,15,43,100,43,78,164,172,123,34,75,76,53,148,24,205,60,79,28,143,128,241,39,122,113,39,14,88,76,132,160,219,164,83,53,96,51,166,66,140,61,213,
32,189,93,19,35,213,221,154,195,98,0,91,139,35,49,214,190,200,253,22,104,170,57,1,240,65,150,247,82,100,26,212,87,104,123,106,189,136,202,179,135,3,149,91,220,72,55,129,69,52,234,1,21,6,147,69,151,44,
6,77,191,5,104,146,190,198,122,130,224,30,29,139,88,43,210,180,246,220,210,76,70,178,137,179,119,234,112,54,161,45,11,34,190,117,87,94,205,1,21,101,226,233,207,233,242,52,36,168,85,154,73,53,244,182,96,
2,245,189,222,28,224,100,67,79,214,153,85,55,50,84,93,253,32,59,41,49,181,68,172,149,7,148,181,188,239,145,149,22,23,168,116,125,196,139,46,3,70,91,22,213,240,115,7,81,219,217,8,93,88,52,233,194,176,57,
164,146,172,160,195,40,155,82,252,144,23,57,139,213,128,34,92,157,241,198,150,180,150,107,111,49,190,29,27,175,7,94,239,17,75,141,159,166,235,83,215,135,93,18,217,218,208,184,61,36,172,34,227,94,10,245,
4,207,23,40,120,174,18,142,233,173,155,229,246,122,15,57,3,237,177,8,55,250,160,199,140,207,39,229,93,119,189,183,65,122,231,213,75,34,168,153,24,159,235,200,189,142,37,183,35,173,160,154,218,101,105,
221,102,57,72,253,142,231,109,188,231,90,122,226,185,245,233,183,124,139,244,234,225,227,109,185,3,217,151,46,236,238,96,64,3,31,80,44,89,173,64,35,59,203,141,244,241,47,156,164,147,87,37,71,243,55,145,
190,237,240,252,149,207,206,90,34,211,138,88,100,141,192,163,183,2,5,37,72,140,96,208,116,168,226,49,145,82,157,157,98,142,18,199,154,214,214,120,106,209,7,250,80,43,106,164,83,190,27,151,183,210,192,
166,217,206,154,221,43,0,151,177,3,188,128,76,48,100,140,97,29,97,220,117,68,248,168,157,150,10,230,46,201,90,14,189,134,128,110,218,35,60,190,135,239,187,216,115,62,212,124,217,220,146,52,214,247,112,
40,33,59,82,179,44,41,212,222,39,136,20,107,14,238,64,52,248,34,167,16,81,120,60,92,158,173,229,187,231,207,177,74,190,228,96,118,244,81,99,37,1,72,200,175,24,87,149,124,59,228,215,26,151,208,252,136,
144,137,56,113,150,87,0,54,103,234,187,109,214,121,102,113,239,73,236,40,1,212,20,172,152,184,144,74,134,2,96,30,50,221,45,106,191,32,65,12,128,58,122,67,122,152,132,177,17,232,119,33,226,101,217,193,
28,56,216,241,159,161,188,27,94,115,78,123,100,14,169,160,167,151,121,128,117,112,106,5,196,129,148,191,9,116,235,113,88,67,6,31,75,57,35,26,206,49,198,139,44,145,79,142,212,52,23,7,106,177,146,231,29,
113,128,99,181,233,186,108,98,67,134,83,209,130,98,175,145,77,147,148,145,182,199,13,243,30,66,32,173,47,203,24,70,58,45,165,61,86,138,108,16,19,91,87,94,178,64,128,23,54,148,190,111,134,19,222,194,2,
123,118,93,41,130,94,249,197,47,159,164,95,54,219,90,184,254,92,170,110,188,79,138,245,240,241,118,221,1,29,122,32,4,234,200,253,22,44,19,122,184,184,188,36,165,117,80,8,6,87,213,50,59,36,51,167,111,180,
147,51,45,125,84,29,249,224,178,26,213,5,31,244,145,230,244,254,230,117,60,82,167,37,82,169,112,216,162,73,6,192,160,50,157,233,237,204,161,191,192,151,82,19,245,107,14,48,50,175,158,43,99,242,180,165,
203,101,70,60,148,218,78,24,101,31,1,96,28,181,154,167,242,155,57,199,48,40,237,19,105,97,70,97,55,123,238,184,43,14,90,94,26,217,97,212,37,233,88,168,174,135,146,249,150,158,103,214,4,202,176,187,143,
252,189,12,157,181,98,128,194,192,133,247,177,131,112,94,128,218,148,137,135,5,181,160,40,50,20,8,149,205,211,183,141,85,244,67,78,41,46,29,205,200,90,120,20,54,122,73,209,202,136,200,152,81,219,77,252,
108,151,147,168,25,134,14,154,99,183,93,18,13,25,109,249,92,204,133,142,65,102,91,158,163,174,5,149,141,11,197,163,61,170,158,211,249,129,128,114,92,151,88,83,219,84,79,205,146,159,80,250,107,107,31,181,
176,122,78,166,39,56,173,193,117,165,112,192,192,107,106,194,121,206,241,4,40,20,154,63,29,125,206,83,164,247,83,55,164,145,59,240,220,238,7,167,145,209,75,141,247,177,140,252,190,238,245,154,238,247,
185,128,214,112,47,183,195,225,201,95,235,0,179,177,145,179,78,120,23,89,58,210,247,0,0,32,0,73,68,65,84,151,52,86,106,4,83,42,104,122,97,160,25,245,108,135,115,249,236,78,87,255,212,25,160,228,208,98,
152,65,84,136,1,240,69,215,189,191,191,159,158,255,188,77,111,12,255,234,227,79,144,92,217,250,239,227,54,61,124,188,61,119,32,251,168,67,250,56,239,123,193,91,167,250,86,202,241,146,43,221,157,244,132,
117,4,5,232,225,133,145,169,130,34,232,250,187,54,236,62,161,30,167,142,59,52,223,248,138,29,157,167,154,253,55,29,206,224,105,198,1,136,223,66,22,50,214,234,237,19,125,26,88,138,89,12,38,13,146,66,21,
108,127,89,251,96,165,191,144,174,3,77,230,17,191,187,162,198,80,125,23,237,141,243,24,122,118,120,36,198,179,212,49,151,33,43,2,137,204,88,170,51,53,4,60,139,154,179,151,81,11,171,113,79,201,129,44,136,
54,27,64,140,13,245,81,180,87,219,125,10,126,102,21,151,69,182,46,231,209,96,88,43,210,231,158,180,242,80,132,108,106,105,100,53,242,59,168,115,7,22,247,246,169,18,76,253,252,80,78,157,103,148,213,250,
85,76,27,92,98,235,33,46,0,75,19,108,163,51,82,44,247,32,170,50,96,50,145,69,227,115,156,136,193,235,37,249,109,133,161,12,237,33,93,193,59,93,21,81,71,210,211,88,137,184,34,50,229,164,207,161,44,177,
72,96,44,214,30,196,48,247,129,175,5,1,118,19,145,62,47,59,232,187,127,99,207,55,245,90,108,82,116,180,178,80,219,4,13,67,237,173,118,230,169,26,107,171,250,159,60,150,232,31,91,181,27,102,67,207,240,
127,99,94,51,180,127,90,140,50,175,255,74,181,119,166,70,239,203,210,82,105,62,231,213,213,67,125,235,17,75,140,167,122,182,93,117,165,111,177,130,30,154,235,117,206,125,86,91,156,92,41,8,209,238,21,172,
139,70,173,87,66,223,203,140,86,211,229,165,249,244,204,237,245,25,82,253,217,127,245,194,255,246,214,243,61,252,253,235,127,7,242,109,242,145,89,218,54,69,144,121,14,96,147,137,97,92,233,210,34,198,77,
140,246,151,29,170,188,246,74,214,97,159,162,243,169,38,213,121,154,253,56,165,33,45,48,35,120,75,31,103,159,184,3,108,234,41,77,215,165,132,14,77,201,50,162,140,26,108,158,138,219,24,185,62,43,141,58,
158,129,31,103,233,17,154,181,92,184,22,6,111,206,178,22,168,227,157,155,197,156,182,236,119,60,0,70,56,92,245,101,145,180,122,74,153,225,77,42,90,164,159,89,4,135,105,198,66,93,87,114,64,23,39,244,114,
22,237,246,108,117,233,238,154,40,137,81,173,62,148,120,77,31,175,5,184,58,147,50,135,122,222,80,84,24,82,102,47,199,116,7,131,168,2,193,150,139,82,79,232,101,28,214,48,137,205,152,160,17,59,202,214,172,
79,79,69,73,12,156,179,32,62,96,50,213,39,248,177,246,137,196,114,160,13,181,112,207,115,172,162,227,141,165,199,231,40,124,243,40,127,108,199,68,72,23,66,140,176,225,57,115,82,222,46,180,183,147,233,
208,85,138,62,34,25,18,239,49,178,132,75,152,54,173,142,237,108,253,99,32,17,135,35,50,183,60,55,229,35,169,186,95,28,82,172,56,220,162,33,91,47,109,166,131,206,113,218,57,186,155,174,202,90,6,158,55,
118,169,126,217,133,95,248,222,209,49,99,244,25,14,209,9,55,24,119,49,208,112,233,47,25,46,171,39,176,153,220,234,248,136,194,44,35,178,79,56,143,178,235,169,115,204,235,193,124,66,130,56,247,62,10,34,
232,134,235,40,95,132,92,137,31,224,72,242,36,76,231,16,54,214,183,182,210,237,119,220,122,200,10,250,250,219,228,191,126,133,108,11,146,121,33,253,89,0,122,236,75,181,246,106,171,169,83,173,19,118,18,
5,227,219,156,205,121,4,243,56,28,177,47,115,234,67,187,76,230,227,41,245,93,93,173,183,32,109,204,6,188,200,73,135,241,20,201,65,174,44,46,167,27,214,98,201,160,210,152,134,79,137,1,244,28,224,67,41,
100,140,86,141,245,250,122,82,180,2,240,161,138,245,178,96,87,139,224,50,51,112,151,65,184,75,186,75,183,104,112,238,123,165,94,20,122,24,217,155,53,167,160,32,130,141,237,29,209,163,155,39,189,89,133,
188,54,202,34,74,172,1,20,131,213,77,214,142,72,89,11,233,22,186,222,173,141,124,122,76,84,219,10,240,199,220,232,145,190,65,219,225,60,151,182,5,50,44,131,140,75,215,204,207,219,170,69,210,195,207,150,
180,61,14,79,68,51,117,238,181,122,223,236,170,200,41,91,232,71,139,70,185,123,79,138,120,161,70,183,82,59,61,208,175,188,71,65,226,56,162,47,48,170,104,227,218,125,20,194,140,200,51,150,146,143,57,161,
160,254,141,112,118,151,56,155,62,103,247,57,91,221,246,205,231,117,188,199,174,159,59,7,110,197,178,161,170,33,236,152,52,25,224,204,134,176,217,132,161,77,219,86,35,132,60,169,124,122,30,39,55,43,75,
88,150,5,12,44,156,42,7,239,182,107,59,153,200,58,181,214,161,39,157,45,25,10,24,99,75,133,42,125,200,176,188,9,117,197,7,233,225,189,85,160,179,83,153,82,1,42,125,93,102,240,148,254,235,21,227,50,67,
239,233,12,202,117,8,205,126,221,189,190,208,102,25,206,157,165,99,172,163,42,2,255,147,79,189,67,235,204,65,120,248,120,219,238,0,81,184,197,217,100,194,20,10,88,16,73,250,164,50,119,24,83,45,254,89,
192,224,209,147,155,82,111,107,67,243,186,129,115,64,18,167,208,209,88,229,23,75,94,65,57,179,195,29,87,28,202,8,23,166,87,26,1,144,224,198,157,222,117,80,128,34,57,145,38,139,253,18,146,150,55,76,112,
52,245,50,139,82,179,226,66,68,39,169,166,200,36,28,64,59,69,110,217,117,70,106,89,22,9,250,14,222,8,167,144,174,178,246,136,244,47,44,211,99,78,45,150,119,157,101,8,106,81,47,177,245,64,212,16,125,180,
12,103,67,138,45,53,223,80,84,174,170,17,115,198,174,50,106,190,173,169,150,143,186,48,184,173,101,109,142,161,232,195,15,152,94,17,227,100,5,25,215,176,211,90,247,190,212,133,16,202,62,167,16,154,102,
99,19,32,77,239,235,92,143,105,44,234,85,161,179,61,170,234,21,108,156,61,243,157,247,165,188,85,206,41,170,207,3,156,215,88,229,80,65,39,108,104,69,141,244,123,203,136,243,132,128,103,171,35,70,182,53,
173,153,231,124,176,221,77,247,14,58,233,142,186,124,9,8,85,225,4,122,218,46,125,181,255,156,20,181,77,113,111,46,198,181,204,120,22,0,100,55,169,199,127,246,158,73,20,196,9,67,107,82,101,104,42,180,213,
226,9,32,142,65,4,206,102,77,107,228,150,18,226,13,169,234,9,199,19,8,243,17,100,168,169,197,18,89,70,84,213,225,255,226,87,70,234,221,148,77,4,223,247,42,174,112,80,56,247,48,172,234,164,71,202,88,71,
215,220,255,113,179,159,238,191,225,186,240,122,231,55,27,230,106,59,47,250,150,152,68,123,248,120,155,238,64,246,152,186,218,182,72,54,149,226,8,58,126,65,230,240,79,107,254,124,10,204,105,51,138,129,
70,245,105,51,59,19,110,46,171,91,238,83,59,63,81,171,204,136,36,97,48,111,218,140,90,199,135,202,3,7,117,108,10,105,157,106,31,204,69,255,145,76,101,95,26,213,81,239,76,236,216,88,144,218,102,200,149,
196,129,142,122,51,150,38,77,24,105,222,170,247,17,195,106,237,123,194,211,224,169,88,18,68,217,224,154,41,141,134,136,18,35,84,241,224,26,80,234,84,102,22,250,182,141,97,141,59,71,162,172,26,119,63,188,
71,9,114,41,146,248,213,145,166,245,176,149,94,125,208,75,59,70,165,34,226,134,250,29,20,42,160,89,12,27,201,44,129,157,145,22,75,60,243,192,97,125,67,58,126,10,178,137,190,233,41,21,191,19,125,221,129,
123,49,132,46,79,203,161,26,144,24,192,92,218,198,2,106,118,118,232,194,2,115,24,238,130,195,30,67,204,121,223,83,157,95,146,46,235,223,186,23,45,17,114,200,145,133,148,246,17,199,213,27,29,176,57,142,
199,164,203,2,26,99,197,109,172,187,167,193,153,157,64,156,151,42,72,1,162,150,70,213,108,31,77,81,228,181,16,35,109,67,110,87,128,73,57,63,11,200,21,233,109,109,19,200,150,32,211,43,6,187,135,126,174,
104,22,180,38,2,175,73,185,31,85,150,220,148,118,231,244,71,227,157,54,164,38,75,82,153,130,231,137,20,61,79,50,244,208,247,246,221,199,212,173,225,83,187,199,94,255,228,104,47,61,98,254,180,141,75,251,
37,53,241,237,231,46,165,15,125,240,86,122,225,197,127,246,223,32,96,236,204,62,128,135,255,121,91,238,64,190,29,72,138,131,175,212,212,227,18,162,116,239,51,221,64,232,212,141,77,212,62,156,214,28,112,
98,147,208,214,146,20,180,137,190,7,198,160,175,138,100,109,42,163,6,236,17,22,93,172,218,205,248,82,44,183,205,163,206,100,29,204,121,18,33,101,74,116,165,37,216,226,182,52,249,220,243,47,45,72,219,12,
33,19,86,46,87,246,24,143,6,187,180,49,128,137,188,229,70,217,141,240,250,56,172,129,130,178,181,138,195,179,138,167,219,22,245,134,24,64,115,60,251,43,175,114,38,162,197,34,212,243,196,170,136,105,68,
28,7,61,234,171,121,233,116,87,234,61,23,76,38,18,38,197,35,145,219,123,234,142,78,210,166,195,186,172,25,127,142,227,123,234,218,142,69,223,85,244,184,89,65,230,29,244,189,141,216,191,217,128,246,150,
41,225,15,251,45,61,92,74,16,52,122,14,189,126,3,83,168,170,213,114,206,201,44,231,86,211,21,207,209,129,10,199,24,93,86,107,101,212,103,214,156,89,197,140,106,16,39,66,249,224,4,111,117,11,255,55,80,
222,78,212,155,86,245,45,138,228,177,182,239,204,61,108,139,224,195,42,49,239,90,8,106,81,111,144,126,231,66,248,140,19,25,160,31,254,226,203,111,144,234,252,124,90,3,100,53,136,160,53,209,161,90,120,
178,27,216,78,117,244,186,83,178,39,177,121,187,192,241,196,198,234,248,28,108,167,194,8,114,7,69,228,53,165,67,211,232,74,215,199,212,128,108,199,48,123,164,182,177,40,120,17,216,22,179,168,123,196,177,
123,208,219,249,21,19,71,162,110,94,6,16,50,15,21,145,116,245,230,90,218,186,126,217,103,184,5,77,120,248,120,59,239,0,201,31,41,153,37,181,37,105,230,53,135,100,73,228,240,191,210,201,86,90,213,159,92,
200,181,82,150,92,230,8,152,18,44,157,197,108,221,106,114,67,205,155,14,164,136,187,190,249,164,190,33,144,70,4,45,196,236,37,195,11,29,129,185,232,207,161,228,141,102,140,20,253,191,51,251,48,165,187,
23,210,192,99,243,86,25,45,153,2,21,242,113,118,149,7,167,89,67,38,114,220,240,51,0,162,5,168,234,84,191,208,25,194,183,37,218,229,57,102,25,237,87,211,218,216,3,25,179,151,89,215,91,128,50,103,235,84,
228,81,4,11,14,219,200,225,154,0,70,42,12,161,161,254,45,99,13,93,98,36,145,134,23,49,158,26,11,148,224,1,38,139,14,96,193,223,55,173,53,156,136,114,74,173,212,147,6,111,123,173,137,20,187,167,184,156,
224,228,74,236,24,129,76,130,97,100,141,204,109,112,20,87,113,77,167,106,232,57,145,124,77,138,127,217,65,159,234,129,230,213,114,171,210,209,146,11,95,51,89,51,207,153,228,48,137,142,24,236,169,191,159,
114,4,125,245,229,137,232,53,134,44,87,69,168,13,105,121,110,136,188,175,15,26,40,243,212,254,153,174,204,35,138,219,49,132,117,28,50,159,12,255,18,224,167,57,180,30,17,82,220,183,62,123,65,139,132,160,
40,33,112,139,232,233,251,180,101,57,95,36,170,118,159,26,68,207,103,208,70,83,108,203,28,182,208,12,43,238,99,0,121,135,162,248,57,82,194,2,61,167,229,139,38,30,109,130,31,84,160,210,62,115,207,217,233,
148,24,172,177,55,107,50,22,33,183,87,0,100,71,119,31,164,147,211,243,237,73,166,241,133,183,243,96,62,124,45,49,175,8,213,187,201,216,50,184,156,23,188,234,129,131,184,178,65,71,7,53,109,142,97,56,255,
12,0,106,42,18,244,128,3,167,23,12,118,21,2,235,192,79,24,223,209,244,128,49,74,225,220,205,153,16,50,163,232,225,126,142,68,147,73,125,81,243,219,97,49,250,119,36,218,196,48,239,188,52,108,42,93,156,
50,162,89,148,142,8,57,60,212,2,1,251,48,146,145,215,232,218,79,82,50,116,92,140,52,216,14,145,18,36,185,200,48,253,196,236,81,96,73,57,198,54,18,137,155,0,153,145,148,12,153,13,89,60,210,106,245,114,
109,217,193,125,83,84,58,27,173,21,53,234,109,146,42,203,190,55,212,20,74,38,67,234,158,123,10,249,12,34,251,68,148,15,45,220,5,228,118,179,34,169,169,77,114,87,253,86,0,18,81,236,73,125,244,187,199,74,
171,150,221,122,121,128,210,182,166,125,111,94,244,246,126,14,165,200,45,181,221,36,60,137,222,226,130,58,125,195,238,153,91,82,200,121,202,6,23,72,30,93,156,225,48,243,216,58,246,139,59,120,175,154,251,
143,95,93,75,55,99,219,181,217,217,83,245,254,108,243,153,232,24,234,188,37,175,209,84,67,191,214,70,147,178,122,97,125,222,190,18,6,62,175,126,228,70,211,25,21,196,152,64,217,21,221,246,81,33,35,111,
57,143,30,43,163,15,145,232,99,175,99,37,106,58,70,60,8,174,84,193,126,134,160,245,100,32,236,151,244,82,223,161,29,227,173,165,107,203,232,135,162,236,49,35,189,134,204,161,53,11,212,194,193,125,34,159,
110,125,64,27,229,61,75,233,169,111,122,36,117,14,247,94,124,199,51,191,249,23,103,55,255,225,127,222,182,59,160,232,98,86,50,91,115,240,82,70,227,96,224,203,243,227,243,244,37,60,215,99,222,126,205,88,
71,172,31,88,144,66,205,129,217,247,68,167,38,84,183,165,213,112,6,145,92,48,167,88,136,53,117,46,57,208,218,8,110,81,107,133,194,91,65,234,54,143,33,52,15,170,47,70,26,6,69,220,7,162,140,29,184,121,51,
142,115,228,41,243,132,184,66,240,107,42,133,234,232,75,246,252,76,172,49,152,211,38,129,173,16,132,198,140,57,241,188,95,189,37,81,211,62,114,115,69,235,197,224,87,86,68,86,171,198,74,133,222,1,135,32,
114,132,192,116,9,176,164,140,163,80,23,172,27,104,48,29,160,60,94,108,143,252,70,150,68,72,99,185,196,17,137,44,234,235,190,126,170,70,130,3,174,38,69,147,203,234,129,62,208,244,175,107,129,92,102,226,
213,115,198,21,202,125,253,59,38,108,242,148,211,69,56,122,62,27,85,91,187,29,234,137,52,213,121,247,94,144,219,205,77,182,165,232,21,169,111,27,213,113,34,13,46,66,144,99,50,70,91,87,250,109,120,89,185,
80,17,181,99,76,47,143,153,85,178,5,237,204,21,148,22,236,20,229,156,46,92,223,49,50,200,177,89,218,161,84,255,226,240,48,157,65,188,183,129,75,125,148,186,162,30,113,157,241,217,169,171,70,158,136,140,
136,35,17,201,69,237,165,186,101,186,245,165,180,9,72,170,161,248,197,240,244,125,239,249,80,166,49,240,89,22,244,101,203,106,242,46,153,209,11,214,185,0,133,221,147,111,191,1,119,152,136,240,134,140,
210,141,117,3,7,214,116,255,202,235,187,233,238,203,28,133,105,24,177,155,41,63,124,188,221,119,32,155,97,4,221,51,232,162,122,243,58,26,216,178,81,162,150,233,254,88,250,147,119,184,194,216,98,143,230,
208,135,29,59,77,176,82,19,236,197,60,160,169,20,135,172,168,77,144,125,235,179,147,230,141,164,173,19,53,93,97,65,58,124,102,42,69,212,24,58,136,75,16,209,162,131,187,251,250,41,195,62,129,50,66,98,121,
106,131,84,136,14,128,11,127,206,49,138,224,161,159,35,187,79,28,36,251,241,204,120,170,167,68,163,183,30,17,225,98,84,107,206,65,62,109,50,72,40,114,158,40,115,39,122,168,162,254,137,3,27,26,62,204,63,
89,247,161,222,212,147,85,71,102,73,176,216,189,36,85,208,62,1,34,133,180,71,201,251,155,160,62,141,165,144,22,79,204,234,176,112,49,21,76,162,9,207,48,81,47,215,99,171,116,209,224,119,139,145,246,13,
109,251,149,211,106,41,134,97,7,160,34,240,79,33,173,67,61,208,42,241,236,60,116,250,212,251,57,87,163,231,112,109,27,81,35,120,237,125,245,248,29,93,204,142,125,157,97,84,125,61,205,54,233,145,125,233,
36,96,26,250,172,213,2,213,46,175,97,79,169,171,247,134,234,126,160,78,191,182,62,19,242,158,130,172,43,144,211,46,79,208,243,153,77,64,201,29,75,115,41,250,72,95,169,15,114,176,237,216,166,141,147,59,
161,208,213,134,170,215,68,204,13,180,191,45,134,24,35,111,101,142,85,182,173,174,110,211,75,114,223,17,230,79,0,101,215,144,43,66,51,119,199,181,6,193,226,206,167,12,40,220,229,180,212,178,159,63,45,
167,235,223,242,195,96,171,135,143,183,251,14,228,111,45,107,165,248,160,247,228,70,117,164,236,162,15,179,167,22,188,69,245,124,219,161,125,165,57,159,182,244,17,29,59,135,133,60,191,53,123,121,160,74,
222,225,221,227,149,99,133,93,140,28,205,30,162,81,12,34,23,151,165,116,38,125,155,14,200,57,112,35,52,113,166,210,191,69,53,107,161,188,12,198,63,55,8,2,80,58,62,208,191,124,115,13,129,76,89,196,229,
8,162,94,180,39,146,212,2,42,158,195,109,178,197,232,135,3,250,102,90,203,71,56,144,212,213,165,175,79,94,126,60,93,188,241,122,202,238,110,227,164,70,43,37,6,138,213,116,193,181,149,6,246,233,31,69,221,
52,39,234,196,156,100,86,20,107,73,89,243,136,234,139,234,227,137,67,157,165,160,30,121,67,172,148,144,17,106,211,48,20,160,204,208,56,205,88,123,34,36,79,198,158,123,42,146,238,64,128,107,82,233,76,143,
42,187,89,213,37,147,53,241,246,10,222,231,156,116,57,231,94,84,244,87,59,234,243,37,169,99,24,225,169,122,32,119,78,53,93,15,178,232,122,228,1,136,10,14,126,11,133,15,125,239,80,119,226,9,117,94,163,
210,160,68,16,35,108,234,73,81,174,230,253,186,108,247,28,59,86,58,157,87,38,52,213,236,19,6,28,90,186,67,207,81,81,23,134,38,238,156,15,96,206,251,43,219,45,186,185,40,245,245,189,37,63,116,61,60,171,
177,183,6,192,108,38,51,42,59,152,106,141,93,201,46,166,77,106,138,83,111,120,14,114,123,213,125,31,32,103,76,72,148,46,104,167,53,202,216,73,90,97,249,219,155,169,183,185,210,203,20,15,127,240,171,159,
240,195,223,222,198,59,144,15,143,29,43,21,98,237,91,200,102,68,29,184,40,2,174,18,166,165,224,168,166,203,155,254,224,117,29,128,22,178,245,185,250,232,44,75,43,64,131,191,78,218,228,152,146,65,176,129,
156,107,191,240,117,156,135,190,3,209,121,192,32,137,60,207,153,145,156,146,235,40,24,255,154,210,147,93,14,111,173,161,191,243,106,87,43,193,68,7,130,64,67,93,56,47,229,107,249,254,129,212,113,196,24,
15,199,184,50,82,226,209,161,146,212,193,153,237,35,241,220,19,14,224,234,213,155,51,67,233,13,14,240,106,119,210,34,18,67,29,60,90,210,136,55,188,101,121,239,217,76,17,61,104,116,161,14,127,174,159,122,
72,78,100,193,200,85,44,234,153,11,245,118,105,122,11,39,247,203,175,220,159,161,192,147,136,254,106,217,88,239,55,162,160,208,21,109,47,236,190,92,47,138,70,174,51,167,198,84,93,166,115,59,91,98,29,69,
108,252,42,226,202,170,98,103,117,98,232,199,46,26,229,58,180,177,173,66,104,172,22,117,172,44,194,166,149,180,233,245,43,180,114,207,205,159,206,25,29,131,191,152,203,52,82,23,98,98,2,107,244,55,35,75,
232,102,155,8,5,182,115,91,122,164,243,52,51,202,80,124,104,187,86,244,125,181,169,52,151,34,69,168,4,30,67,103,115,122,199,75,94,63,234,235,138,84,184,100,241,237,34,34,68,23,16,181,228,30,198,234,191,
22,174,173,167,244,153,122,9,111,177,160,86,29,234,153,29,72,223,7,12,127,29,185,119,219,53,231,200,161,132,252,203,152,202,94,227,57,103,225,246,149,244,233,237,78,90,127,238,210,180,219,61,124,184,115,
243,109,52,202,183,94,42,159,107,155,196,208,59,203,159,31,50,32,189,78,181,225,60,15,26,77,250,69,45,231,173,155,49,229,48,208,52,119,208,50,75,34,201,33,3,146,38,22,55,252,156,22,25,248,31,28,242,230,
243,57,0,83,32,196,57,89,143,83,135,49,23,43,244,250,86,212,57,196,177,160,103,160,39,88,18,97,66,96,186,100,140,169,1,29,29,27,83,26,67,47,198,168,114,166,191,144,191,163,179,163,134,84,155,22,137,42,
79,12,118,19,10,145,86,139,156,158,63,24,50,15,238,191,225,231,209,212,38,196,191,252,93,94,35,189,64,27,167,224,121,219,6,194,75,14,223,237,45,18,32,71,11,233,21,169,117,180,68,98,62,113,189,81,179,168,
199,206,15,169,240,28,226,192,58,35,171,227,172,6,10,29,172,94,144,110,128,192,179,148,248,138,16,250,101,181,235,200,132,117,16,201,219,162,214,72,42,90,67,98,88,94,39,131,34,149,46,32,165,87,33,168,
51,44,212,228,78,91,232,207,73,107,187,12,93,5,202,137,169,102,57,133,185,43,149,212,124,131,104,89,235,12,112,211,75,134,180,68,50,108,172,17,125,121,74,245,83,196,245,44,112,233,68,191,245,1,86,206,
203,94,231,129,180,190,239,94,222,214,15,46,136,130,67,247,47,230,56,81,180,140,209,197,213,66,123,101,29,67,181,65,193,245,177,208,217,34,165,123,8,5,24,140,140,208,28,40,39,216,132,198,47,139,194,143,
224,73,71,148,63,149,5,156,115,10,219,129,14,139,254,89,60,223,136,212,75,22,207,156,53,123,105,239,12,193,126,233,74,42,61,178,154,42,100,85,106,13,51,57,25,205,230,135,143,183,253,14,100,27,250,142,
11,144,197,146,201,143,26,163,42,74,101,231,163,193,111,34,254,128,172,70,86,205,55,149,150,85,8,63,173,80,3,71,97,183,102,211,65,150,14,69,204,152,29,234,175,94,246,212,193,25,169,123,162,23,216,48,200,
92,1,218,140,41,148,15,24,214,2,208,162,6,250,175,168,203,22,150,237,66,89,133,46,50,122,101,16,222,171,241,95,81,179,96,170,100,62,175,69,129,161,50,161,201,147,147,170,229,49,106,142,204,100,18,81,247,
90,145,63,155,96,81,239,141,29,242,224,188,4,24,213,194,45,237,67,43,11,90,17,56,238,144,102,96,17,7,114,16,27,188,168,36,21,0,40,67,18,156,221,179,22,245,243,148,182,207,204,144,74,207,103,233,174,231,
29,224,146,6,239,53,144,221,11,233,240,131,88,84,137,20,80,98,112,103,90,31,57,114,45,121,198,81,83,11,62,162,239,219,214,103,156,234,153,158,91,65,221,85,27,214,180,107,184,41,245,177,76,65,27,163,37,
237,141,52,124,194,168,78,129,107,63,255,226,43,118,92,98,90,137,130,1,254,116,144,225,199,50,146,140,136,25,226,216,67,207,123,96,174,179,165,181,115,74,190,101,96,72,160,98,28,46,175,94,222,247,90,3,
125,219,17,205,88,110,68,150,162,156,240,123,54,187,166,246,45,99,244,216,11,26,119,214,117,103,68,120,255,226,67,235,247,70,109,44,163,121,183,13,99,215,92,29,254,130,235,55,72,175,237,85,7,200,61,234,
51,218,146,214,238,91,223,221,176,168,40,182,150,175,49,214,0,241,114,155,234,120,43,25,11,75,134,208,74,163,127,178,242,13,120,134,15,31,111,251,29,32,80,126,152,218,32,251,170,5,173,89,176,226,133,182,
192,177,17,171,22,124,189,40,85,202,211,200,9,173,153,169,101,184,157,109,27,65,120,226,155,151,42,100,50,99,127,100,228,153,191,122,205,25,30,60,27,236,27,192,206,188,86,68,86,15,114,106,94,44,83,4,14,
49,200,104,148,159,43,164,70,49,67,122,104,48,121,112,140,24,79,209,207,225,44,24,50,158,88,32,116,38,178,129,147,210,178,17,166,121,245,226,196,235,116,29,204,190,3,250,150,35,112,62,83,22,114,132,207,
2,252,1,148,160,222,21,17,5,250,28,203,2,174,109,212,146,29,195,227,29,32,204,20,74,27,2,154,99,26,73,49,125,178,41,252,62,161,118,28,7,80,19,209,70,244,124,11,237,16,212,173,187,51,100,237,30,236,1,155,
118,69,226,225,234,163,169,189,120,5,224,132,80,143,116,112,0,208,201,168,139,171,164,92,138,65,162,71,126,56,151,142,14,136,114,229,103,131,209,0,25,168,115,97,68,166,197,115,45,2,157,110,205,173,155,
158,193,133,213,102,130,99,67,151,221,187,89,41,160,191,24,136,175,232,125,44,194,199,94,208,232,199,70,116,172,208,69,218,224,164,170,95,205,24,230,8,60,47,153,67,93,6,104,173,89,111,81,197,81,238,184,
15,83,247,46,90,33,231,49,2,38,82,23,100,13,101,215,20,163,111,57,67,230,177,29,187,195,64,79,24,102,12,19,44,32,184,15,48,137,50,178,165,162,235,188,167,118,25,235,173,70,107,171,164,4,137,153,216,214,
253,187,105,184,183,131,159,188,156,126,234,47,252,253,255,246,74,230,27,221,172,135,143,183,251,14,100,183,207,212,77,212,244,200,48,243,168,34,35,131,155,67,255,90,187,140,193,227,195,26,158,237,167,
146,85,10,29,251,57,95,16,201,198,188,253,134,253,153,5,139,142,10,188,123,86,157,246,22,231,53,90,41,49,251,24,189,196,64,104,99,10,172,232,185,230,29,198,178,118,71,235,206,54,25,201,11,169,113,33,189,
246,0,9,156,85,196,33,237,153,228,24,56,160,61,50,31,125,132,236,121,233,222,68,147,63,103,176,59,137,164,43,250,134,53,117,214,84,29,23,143,224,191,78,87,28,40,134,61,242,115,167,162,251,188,150,74,163,
126,5,226,42,90,123,222,121,147,42,87,200,126,108,16,23,179,228,221,251,42,75,37,241,71,69,181,66,129,146,189,127,230,28,246,169,144,18,100,254,120,4,61,48,182,132,141,28,222,156,58,111,226,249,199,82,
209,78,103,23,48,131,129,36,47,60,116,209,197,80,40,52,240,57,17,253,114,80,208,73,164,150,12,127,78,47,162,164,119,26,187,70,247,165,215,161,225,115,74,140,171,172,206,140,13,105,5,68,248,107,153,69,
209,40,84,16,180,50,164,146,49,204,82,96,48,171,0,170,114,80,14,1,60,161,224,16,217,68,108,86,11,18,255,18,58,224,6,198,207,130,235,91,22,77,151,244,128,143,245,82,124,183,126,48,180,119,238,100,6,62,
141,33,226,183,13,124,95,98,192,227,249,179,153,66,223,23,181,92,16,145,104,7,81,1,14,130,1,71,87,228,64,75,106,231,142,54,209,56,50,0,238,235,203,156,91,22,128,84,54,46,118,114,175,146,30,124,178,197,
152,251,233,198,251,110,40,94,30,62,254,93,220,1,237,63,232,31,105,255,28,162,118,14,47,52,115,98,88,87,47,239,210,122,45,189,113,87,170,184,136,190,23,235,229,128,36,7,136,232,25,222,57,196,164,143,7,
139,250,106,237,116,106,151,102,8,22,191,121,188,227,45,248,63,30,125,18,135,213,97,26,225,156,230,168,32,76,239,198,50,123,212,56,101,211,137,86,203,46,216,53,118,114,212,26,140,25,121,224,194,68,132,
87,131,201,88,51,8,49,158,48,230,249,150,212,138,50,221,2,227,190,112,112,50,6,195,89,161,104,105,72,26,136,117,104,226,185,4,185,44,171,145,33,48,34,181,33,100,81,224,162,37,34,85,69,204,221,83,117,155,
189,154,68,167,167,156,198,169,116,61,212,228,22,212,120,19,160,73,187,112,104,125,186,107,215,79,116,41,179,71,188,143,182,231,30,152,180,142,193,240,76,59,90,19,40,4,254,98,128,170,120,2,237,157,226,
194,249,43,168,169,212,120,17,5,157,161,204,171,241,166,158,147,204,60,35,16,197,28,248,49,112,166,199,89,68,58,123,10,64,179,165,93,157,76,25,158,1,246,24,238,132,243,96,219,179,189,159,107,208,237,168,
109,31,196,214,48,95,171,163,245,28,118,160,187,86,140,3,95,165,204,222,39,245,135,146,165,76,29,130,75,49,88,125,117,34,221,150,206,230,161,223,136,233,86,33,2,238,164,243,39,23,132,204,212,251,94,154,
80,27,220,64,148,221,240,123,54,134,11,212,241,58,64,28,144,26,152,89,46,64,195,207,181,116,34,145,184,172,119,155,5,14,229,245,138,107,178,168,174,63,151,87,111,126,245,206,60,252,237,237,190,3,249,5,
104,100,57,14,184,127,250,71,164,73,164,107,115,26,229,103,248,152,177,239,36,80,220,129,94,96,95,154,186,42,7,11,9,200,194,234,13,186,174,148,228,176,131,22,244,240,10,12,112,246,8,232,94,79,45,214,208,
231,183,78,211,216,244,69,168,153,143,68,195,237,163,81,170,55,180,19,0,62,213,80,38,192,204,57,107,58,52,80,218,60,38,82,133,199,190,56,68,17,228,233,115,151,12,72,31,135,82,59,158,111,111,83,187,67,
132,99,192,67,181,90,136,141,77,165,139,23,15,244,226,214,33,198,155,235,12,94,228,172,10,65,44,44,27,209,208,247,183,69,223,251,174,191,201,80,175,99,25,197,226,162,154,175,149,209,224,34,253,75,250,
170,176,79,105,30,131,2,103,6,205,33,178,244,144,42,203,99,53,85,165,160,231,152,60,138,222,52,101,32,83,72,209,124,75,239,81,131,190,163,94,171,71,141,108,32,160,109,181,125,9,205,111,172,253,68,213,
196,46,19,239,153,42,251,53,169,100,160,161,23,104,122,93,169,247,24,84,122,194,232,239,81,180,127,196,84,201,45,14,229,162,20,43,3,165,249,64,167,109,196,224,33,74,94,15,93,47,134,165,59,140,13,162,134,
56,193,153,225,236,150,100,40,103,174,113,41,178,16,76,159,2,20,122,181,100,246,149,76,232,185,159,175,161,233,133,51,60,28,139,244,162,252,130,105,152,37,53,228,8,53,114,37,192,182,165,24,79,243,182,
13,183,231,69,203,161,12,104,213,186,138,12,20,125,8,62,94,117,15,174,220,44,165,59,230,110,107,155,34,232,13,83,58,28,80,89,218,255,240,241,239,230,14,228,23,200,82,46,241,250,77,10,8,172,12,195,100,
136,228,190,164,6,161,109,227,195,81,105,153,20,1,74,104,67,228,9,15,23,205,255,141,205,14,101,163,15,7,44,105,3,99,254,79,246,238,52,214,214,52,187,15,250,179,231,233,156,125,230,241,142,117,171,110,
85,117,245,60,216,29,15,29,207,113,219,81,18,37,136,4,3,6,201,240,1,68,144,34,144,249,192,23,18,3,1,37,18,8,16,18,1,28,225,24,65,28,49,100,144,163,168,109,226,169,211,237,238,184,221,93,93,243,112,235,
78,103,158,246,57,123,58,123,222,252,214,190,85,237,182,33,223,82,85,31,114,222,238,59,212,185,231,236,253,190,207,126,214,179,214,250,175,255,250,175,9,3,126,239,10,251,204,135,196,72,196,172,66,198,
17,68,177,124,174,200,162,174,89,10,112,137,255,172,26,161,158,215,157,114,170,63,242,82,145,123,48,50,155,146,109,21,81,8,163,138,217,62,100,4,44,109,106,46,200,72,158,26,225,90,134,59,41,8,103,237,63,
53,72,222,77,222,119,215,235,207,218,161,162,198,41,188,237,224,142,178,65,225,169,34,62,98,64,22,200,181,165,124,83,25,82,211,147,187,17,27,81,174,241,59,227,45,214,186,20,11,228,101,94,119,12,189,13,
34,66,120,79,62,24,40,149,73,55,74,117,158,22,25,195,179,25,86,224,89,29,8,194,117,216,43,131,138,142,19,7,129,122,234,77,30,172,43,44,207,163,16,134,114,223,49,149,134,155,114,207,138,218,238,64,217,
105,35,234,180,238,53,52,144,66,183,231,212,159,47,232,207,44,113,135,42,78,192,159,85,17,132,114,141,242,79,49,234,150,60,231,20,127,121,48,11,225,9,126,89,155,235,40,126,171,107,91,88,142,136,241,82,
130,1,131,142,212,97,127,124,76,8,44,194,116,139,39,212,158,87,6,91,147,179,174,57,116,222,228,249,10,14,179,53,37,166,170,28,122,106,14,77,72,133,222,144,175,22,188,247,133,207,179,133,20,255,64,212,
83,243,185,108,58,64,70,244,121,43,106,197,117,160,87,135,101,46,60,189,105,74,219,199,223,251,104,175,254,252,128,87,32,91,203,94,67,116,246,97,161,185,229,176,108,86,242,90,164,24,82,211,232,189,28,
166,76,31,161,250,236,114,69,62,183,162,233,88,225,157,65,196,8,242,139,157,51,161,16,93,158,186,66,190,15,63,174,177,56,181,138,58,180,132,171,59,216,227,161,24,117,6,177,58,52,85,39,128,135,57,39,184,
201,70,12,1,180,79,210,15,101,87,199,4,228,81,88,153,141,56,145,55,233,2,70,122,60,102,97,129,231,132,222,158,103,246,177,107,248,235,224,174,70,248,28,198,15,0,154,175,243,216,228,61,192,60,179,178,79,
135,167,47,201,181,202,249,208,254,235,224,173,86,210,45,51,79,54,80,6,7,209,119,122,38,244,243,186,59,13,227,24,132,139,83,27,243,64,190,118,134,140,62,13,139,247,186,85,101,144,168,97,70,237,242,72,
78,25,172,213,34,67,172,25,234,148,63,211,253,162,159,178,27,158,49,198,239,249,190,238,2,239,27,13,216,14,132,134,148,160,79,84,122,200,120,218,37,186,128,60,214,125,209,65,159,225,100,212,61,67,107,
254,80,40,187,198,64,62,131,212,191,162,84,114,201,155,30,163,207,93,240,94,19,47,18,135,92,147,186,68,212,27,215,41,224,175,58,177,86,156,2,11,40,79,93,137,227,152,135,204,10,153,119,172,195,190,62,92,
2,136,51,21,192,232,186,105,154,252,86,199,123,158,23,29,156,14,81,238,228,252,91,188,238,200,73,246,150,150,182,152,234,150,149,175,118,201,114,238,70,126,143,54,24,13,214,61,161,238,188,83,162,66,237,
34,15,188,43,97,134,173,220,48,195,148,64,217,34,175,28,40,244,213,245,225,172,64,182,63,218,83,224,54,12,15,48,179,138,235,218,199,84,105,52,79,102,93,19,136,65,196,187,6,105,227,230,10,145,103,115,52,
124,232,33,78,181,15,105,29,48,134,172,147,185,24,39,49,115,136,205,93,86,27,188,115,11,125,77,169,99,151,39,110,30,216,176,231,234,126,230,116,148,85,219,163,153,187,123,184,159,238,31,239,1,146,70,120,
156,194,172,208,234,209,247,153,167,111,210,135,120,198,172,207,46,242,123,230,40,136,239,200,9,54,113,78,174,53,226,137,135,106,162,113,133,64,124,1,15,118,132,219,219,16,118,54,245,187,197,104,135,161,
158,175,49,242,120,70,13,177,190,12,93,6,252,156,241,240,33,155,217,131,78,46,204,171,75,242,108,81,81,143,129,18,243,208,204,96,59,133,109,198,85,45,81,113,168,175,26,209,30,82,34,144,222,222,41,150,
142,110,13,33,55,170,60,169,17,7,77,168,234,145,237,40,25,42,220,199,89,13,146,134,234,48,50,193,19,186,91,81,126,123,68,119,41,250,89,179,202,34,157,83,192,138,86,184,137,46,242,156,239,93,102,152,71,
206,57,0,0,32,0,73,68,65,84,24,125,247,116,32,79,220,23,194,190,69,103,55,198,65,100,241,154,243,248,180,176,107,161,166,181,114,56,28,43,233,56,250,200,102,86,103,228,248,5,200,243,130,20,66,70,12,204,
209,124,141,220,187,37,58,8,138,99,145,17,119,133,210,123,214,179,37,85,153,135,204,246,188,207,72,20,112,198,91,79,29,16,37,200,241,61,116,202,135,192,159,35,103,97,200,157,22,28,152,231,14,197,54,140,
96,231,65,74,15,222,160,88,241,214,94,218,125,112,56,107,33,171,111,46,207,214,230,234,183,15,126,5,178,19,185,212,216,70,40,243,154,83,35,19,198,0,151,213,100,196,2,131,33,4,171,93,202,134,24,188,69,
172,107,63,13,109,200,128,238,151,121,165,37,96,195,68,126,2,194,156,33,145,108,211,159,0,32,33,226,133,66,248,73,7,241,219,231,58,93,214,114,117,93,251,148,217,126,61,83,115,6,54,106,233,214,167,229,
69,222,131,245,159,82,228,219,65,211,139,46,176,64,93,74,224,251,44,239,90,88,20,102,86,125,175,150,170,200,165,106,17,175,134,21,249,255,4,247,55,216,55,67,125,151,77,210,29,33,246,21,173,85,99,94,46,
134,0,133,16,245,64,238,60,58,35,36,45,78,173,49,168,170,28,43,95,54,26,98,238,20,83,70,221,214,247,206,49,152,134,188,238,242,148,65,240,222,37,26,68,209,157,115,2,7,29,139,24,50,188,250,146,114,80,85,
91,214,169,40,225,12,168,116,11,240,84,45,9,115,121,207,10,227,9,105,208,115,101,146,24,155,216,48,240,118,30,104,85,147,40,198,40,145,18,90,78,200,166,244,69,0,29,70,25,228,244,137,156,247,156,199,202,
146,130,9,117,133,46,67,121,16,70,206,171,109,34,228,127,210,188,209,69,81,196,84,126,159,145,231,199,243,30,242,216,81,127,28,43,139,92,64,146,23,132,249,107,190,222,142,193,196,194,216,129,144,180,168,
135,244,28,179,168,41,124,205,202,201,207,172,201,177,247,43,241,240,219,208,217,160,33,222,195,197,205,26,34,181,198,211,78,33,188,167,152,85,93,225,126,172,215,152,151,159,26,99,49,127,109,209,228,51,
134,107,100,121,81,9,41,55,186,245,193,239,202,171,119,156,173,64,182,19,249,162,218,227,26,239,183,4,33,92,145,127,134,22,106,19,63,116,192,67,142,149,90,246,47,204,199,2,180,148,193,249,57,33,240,248,
132,145,46,175,200,195,66,17,62,202,4,79,86,51,194,195,161,68,181,112,62,78,75,242,188,117,22,236,213,83,27,13,238,4,26,113,40,108,202,41,238,103,212,253,122,194,185,137,186,222,90,11,226,72,125,189,209,
198,52,98,72,75,203,153,244,148,129,173,13,229,157,215,229,88,93,109,82,222,70,254,102,163,6,204,40,231,11,79,219,21,114,77,73,83,142,144,11,118,149,46,134,218,80,10,230,166,132,44,101,20,134,26,102,98,
22,138,107,52,118,229,129,163,115,161,172,230,113,212,192,233,248,132,7,148,119,98,252,180,16,36,90,208,234,190,156,112,204,243,206,194,102,94,50,20,28,202,234,165,75,88,76,57,224,73,72,131,84,133,243,
203,66,192,49,47,60,113,48,100,0,56,126,82,13,151,39,244,172,19,117,205,2,82,197,153,230,231,33,0,106,224,80,202,3,214,34,50,172,203,229,22,120,214,249,32,93,136,0,46,125,239,218,230,83,58,117,214,28,
128,65,168,159,152,128,134,199,107,177,178,14,191,42,207,31,90,66,69,101,145,57,57,241,6,244,116,91,84,191,16,57,191,95,19,188,221,125,249,238,161,5,139,54,183,167,148,111,150,145,66,118,120,197,223,163,
211,212,34,201,50,233,25,107,33,103,14,217,207,16,177,238,59,16,202,114,226,117,146,39,25,128,85,137,167,28,120,207,96,31,173,249,108,231,173,247,245,155,133,244,125,255,234,211,105,251,41,66,225,192,
169,142,40,163,151,9,93,192,171,235,195,88,129,124,120,149,45,33,95,53,223,148,207,69,30,67,167,134,118,198,58,112,98,192,155,76,120,128,185,50,197,116,31,252,28,4,211,252,175,116,136,149,82,167,43,116,
222,220,75,29,176,125,204,74,9,175,57,236,93,8,227,212,222,144,179,215,176,106,148,10,157,216,188,7,144,35,102,95,21,149,16,106,55,62,154,238,160,209,245,72,99,12,31,30,205,228,55,87,150,52,13,239,3,36,
244,63,78,230,8,75,225,188,238,203,131,182,33,170,149,37,60,89,239,25,155,41,116,112,88,14,227,134,244,226,235,46,241,90,5,155,248,213,131,131,180,171,108,177,2,13,206,202,253,42,166,80,95,0,104,2,36,
42,156,68,103,63,48,136,65,30,31,171,79,142,55,140,22,32,27,169,191,243,8,128,20,77,217,133,32,182,75,102,75,203,75,105,233,35,31,79,247,95,251,85,98,208,114,74,222,170,15,94,190,110,243,215,178,71,248,
186,58,113,180,80,161,18,201,33,49,130,80,238,86,168,196,79,187,168,137,138,171,115,194,240,30,35,47,122,173,154,94,215,119,142,58,233,13,241,227,35,6,117,93,206,156,101,152,115,158,99,89,248,249,250,
215,94,78,243,181,203,244,81,185,243,35,135,93,102,21,9,65,206,254,168,163,141,76,205,182,41,71,159,108,20,121,72,194,211,218,107,102,130,207,61,170,7,158,179,76,87,40,102,205,92,180,47,117,226,68,199,
105,100,199,158,49,212,7,77,14,223,97,168,83,20,192,5,185,121,134,87,102,147,106,173,26,210,41,48,156,203,41,99,4,198,80,58,48,241,64,19,207,54,245,13,251,188,244,183,95,58,76,27,175,118,211,237,31,83,
25,118,34,22,72,153,200,20,158,0,10,31,198,238,252,23,252,61,243,49,74,65,138,151,138,107,58,234,113,66,199,54,243,52,52,75,108,188,152,189,145,83,59,203,169,132,119,48,133,174,147,219,152,148,100,168,
188,149,65,92,51,239,81,14,22,79,144,5,68,71,83,27,50,164,20,155,81,202,208,135,248,17,234,116,249,198,34,3,70,96,247,115,89,211,174,122,115,207,72,78,1,41,70,192,15,162,200,79,108,42,179,163,3,66,62,
151,81,82,153,131,18,139,101,211,141,106,43,173,144,196,220,239,24,167,32,247,107,169,53,198,38,18,131,177,13,155,255,134,176,19,185,55,63,168,50,24,229,24,192,203,64,40,90,55,125,123,54,90,0,152,50,182,
153,203,14,156,21,74,1,49,111,116,141,7,218,92,89,247,18,20,230,90,135,30,58,147,158,99,128,49,222,48,188,126,212,91,91,114,233,51,136,241,82,102,131,151,111,201,39,177,164,240,79,47,154,115,238,153,62,
16,50,121,12,76,122,8,220,89,240,245,104,20,200,51,238,104,94,22,209,91,3,161,59,207,58,226,137,242,1,244,44,215,210,51,215,110,167,207,95,71,178,67,229,41,70,239,36,178,194,160,217,78,119,173,67,67,91,
218,46,21,136,6,105,207,19,173,123,29,253,177,49,167,37,138,148,49,190,111,196,195,247,189,239,155,14,202,28,207,127,147,39,157,228,26,188,185,57,42,72,2,71,222,107,137,183,93,23,190,46,72,11,154,158,
99,76,167,40,140,89,149,216,189,184,15,75,58,101,144,32,0,121,109,33,125,76,8,77,114,140,225,145,29,29,215,103,57,243,252,154,240,252,80,122,227,123,139,235,75,41,123,68,197,65,20,225,100,188,186,62,164,
21,200,247,201,144,244,213,222,22,38,80,90,31,124,208,208,66,8,170,178,165,70,23,101,18,158,101,236,131,173,69,51,238,10,66,55,16,162,32,167,44,59,193,75,198,0,118,163,29,236,187,2,31,123,67,61,173,36,
207,50,153,75,62,219,86,184,172,1,154,26,60,199,235,45,8,233,235,111,166,143,126,100,75,190,199,107,201,43,135,218,178,142,13,148,27,200,181,134,64,34,127,77,35,155,84,155,225,76,158,49,99,150,74,25,129,
187,10,12,121,175,55,13,88,57,43,222,31,183,24,53,4,115,205,224,165,105,161,73,183,85,115,117,65,191,168,247,138,91,154,10,87,207,17,248,163,204,192,194,104,245,232,170,201,238,202,21,121,77,162,98,197,
107,120,169,190,247,242,82,120,108,227,78,228,161,157,92,71,216,59,78,79,43,41,188,181,167,70,233,251,58,229,85,4,249,224,194,82,121,152,131,187,30,142,211,39,34,252,244,30,223,58,61,230,177,228,113,234,
172,143,52,91,31,181,186,233,38,66,255,218,218,118,122,238,11,40,238,71,12,68,42,240,119,247,118,48,117,34,172,21,230,251,190,92,245,122,90,106,99,63,45,15,210,79,126,225,105,140,169,123,22,142,177,8,
181,15,221,71,89,254,24,36,255,75,53,213,178,3,33,72,134,83,41,65,65,43,95,247,148,129,59,56,230,117,158,100,29,102,21,107,185,130,84,123,136,238,55,213,40,176,165,17,96,1,48,85,242,126,35,33,191,255,
27,41,33,122,1,126,21,120,211,44,96,106,133,167,220,247,156,93,117,222,130,220,126,83,109,244,238,199,241,108,159,6,92,1,164,180,117,90,192,0,2,174,174,15,107,5,242,85,194,203,69,70,146,195,157,205,189,
195,16,109,210,158,141,121,225,67,31,67,112,11,65,112,151,151,21,72,68,230,177,110,166,147,165,180,161,220,17,182,210,148,67,77,21,236,243,218,143,212,73,120,63,99,128,120,165,154,80,170,46,71,236,210,
179,41,47,173,206,80,202,57,227,28,110,50,230,149,235,140,224,244,13,40,162,198,94,45,95,161,144,119,185,110,166,10,47,115,255,97,63,189,204,24,182,40,23,36,30,102,181,93,83,87,156,79,176,221,212,163,
166,144,113,63,92,122,184,129,217,129,210,54,219,179,196,152,38,242,220,38,48,102,113,147,23,129,200,30,223,143,239,245,109,10,45,61,68,251,140,240,237,68,168,219,103,148,49,215,179,42,159,206,10,221,
151,107,119,210,75,230,147,180,121,39,223,46,36,102,110,16,220,12,154,98,47,228,35,133,142,81,111,204,240,72,89,45,94,69,101,151,115,164,134,158,144,119,30,75,169,2,72,89,23,50,63,144,35,126,251,254,25,
69,251,249,244,39,254,212,247,164,213,141,229,244,202,189,110,250,47,191,244,114,122,253,209,153,16,254,255,207,253,188,206,243,3,215,160,170,159,189,115,145,182,105,253,254,196,205,231,82,83,169,227,
119,239,31,166,199,39,123,105,178,185,173,110,90,163,71,212,162,83,228,6,149,176,150,132,212,231,222,39,84,31,8,2,82,100,208,117,227,121,78,60,195,170,67,177,198,43,119,76,201,238,248,220,198,58,193,119,
212,103,87,144,31,86,149,99,158,112,125,139,122,105,117,28,137,44,230,28,74,42,165,60,232,66,58,163,211,155,49,12,216,55,163,68,6,199,55,182,100,32,6,87,215,135,181,2,249,77,97,87,219,6,31,242,46,229,
45,249,213,17,4,17,213,197,212,132,25,63,181,208,133,116,214,26,10,242,242,71,27,118,218,70,42,39,109,147,143,58,40,104,126,173,120,205,134,102,76,179,67,22,80,226,67,29,248,240,23,229,154,235,248,162,
33,126,121,32,255,185,176,89,110,214,111,164,219,171,119,210,189,195,23,211,193,209,105,186,37,103,172,201,25,179,220,100,129,215,190,77,221,124,43,164,54,200,103,188,229,125,38,80,210,138,92,174,196,
163,182,32,137,99,28,213,89,218,233,61,98,208,44,122,170,112,28,145,193,236,202,50,196,116,209,198,180,215,211,229,184,161,139,100,14,57,220,253,232,250,191,96,156,117,161,239,41,79,148,147,207,230,160,
180,151,60,108,140,106,63,23,38,135,72,9,183,233,197,132,172,10,254,39,24,229,141,37,200,171,188,185,188,66,123,40,106,192,188,230,100,204,40,20,253,7,34,139,251,106,184,161,208,211,101,184,221,195,78,
250,232,214,181,244,19,63,250,35,233,55,15,222,73,255,249,151,126,45,61,32,28,61,5,96,5,167,246,143,94,235,207,60,3,213,22,37,60,162,141,192,177,127,233,197,199,176,168,199,233,165,205,185,244,153,91,
107,233,118,253,22,153,18,29,52,135,238,206,125,87,29,130,3,220,216,178,246,178,178,3,163,143,147,251,112,124,63,221,117,88,221,116,24,61,208,114,183,111,218,211,70,168,54,56,88,96,224,94,175,159,30,136,
56,78,32,183,27,58,143,142,148,76,58,104,139,65,138,239,43,227,68,83,105,214,189,101,47,235,148,236,29,196,52,156,246,223,38,98,54,199,35,191,96,190,203,237,69,33,110,213,116,238,39,159,236,31,125,134,
171,255,126,255,87,32,223,146,119,77,141,141,83,143,32,143,200,11,69,39,176,144,102,77,189,179,35,196,186,80,243,172,65,115,115,106,156,21,198,216,84,66,216,3,243,111,171,201,109,34,24,180,113,56,71,72,
8,81,159,27,57,177,3,152,176,223,132,181,10,234,114,179,75,255,62,191,177,200,56,174,217,220,234,163,227,215,109,138,251,88,72,11,134,234,60,237,251,31,33,151,203,147,212,227,38,148,0,50,54,250,88,47,
231,18,20,50,43,76,235,11,205,236,173,153,33,4,99,9,17,214,207,143,133,116,66,82,155,179,220,85,31,84,34,25,105,204,46,233,172,9,130,195,170,112,53,152,1,249,19,92,94,136,99,155,119,204,224,196,182,180,
137,109,232,222,112,6,164,58,96,183,232,103,54,189,126,143,247,159,0,173,42,188,75,205,51,145,76,154,169,232,245,12,178,189,32,13,50,31,209,128,101,201,201,45,115,134,31,61,35,155,107,206,245,229,195,
103,233,215,14,154,233,103,62,243,177,244,233,63,246,253,233,47,253,131,95,77,223,126,115,103,246,169,5,64,86,150,83,142,148,52,70,214,107,243,246,103,210,173,79,127,52,61,255,204,205,244,231,255,194,
207,120,140,81,250,149,255,234,175,165,255,237,255,254,21,135,14,18,6,133,189,111,226,10,127,99,255,126,122,238,250,69,250,226,31,251,30,107,113,144,78,1,111,53,167,80,3,26,189,236,0,235,90,132,114,231,
24,186,46,63,198,121,254,61,229,172,162,175,229,104,50,221,7,200,85,105,12,221,144,99,247,181,245,205,105,26,136,134,129,172,186,243,158,207,168,39,68,142,217,51,67,30,248,60,114,120,7,95,75,222,121,224,
62,107,242,217,248,20,135,166,148,245,29,150,229,133,248,222,247,127,3,94,189,195,63,123,5,242,29,128,194,42,210,53,215,147,224,60,10,251,226,90,41,90,175,209,73,251,143,120,36,167,237,82,125,89,30,56,
96,16,213,116,44,231,26,31,50,104,200,228,152,32,77,201,73,252,222,56,6,187,48,181,14,79,0,73,66,97,137,225,24,76,95,224,173,130,215,106,143,200,247,212,25,179,203,129,195,164,226,234,122,234,238,60,150,
75,41,183,0,85,6,152,55,189,40,83,168,71,142,214,105,14,56,245,47,212,31,71,0,161,5,229,134,40,75,100,128,30,17,214,142,229,127,45,73,226,245,58,158,41,29,215,206,49,244,215,125,141,160,162,121,0,79,1,
168,211,19,138,79,181,124,52,3,24,34,225,57,161,235,83,23,170,103,234,202,20,216,51,183,235,55,145,210,87,132,112,202,72,151,15,29,41,238,211,50,204,198,59,56,128,86,199,91,169,41,76,63,193,3,126,203,
128,162,207,147,147,175,160,43,102,212,70,46,220,199,145,185,50,251,135,237,244,47,127,234,147,169,246,194,179,233,231,254,214,223,78,135,4,3,10,68,184,178,118,245,140,92,254,174,97,62,245,244,115,233,
199,255,237,159,75,27,78,133,31,134,52,55,255,254,47,210,239,57,72,255,222,79,125,111,218,224,121,255,155,191,251,247,32,212,52,118,245,191,162,105,165,55,246,206,210,237,87,94,78,63,255,131,31,75,15,
181,246,124,21,33,96,232,208,169,59,172,138,181,165,180,206,120,166,163,67,41,68,155,222,80,61,61,229,199,138,51,101,7,7,12,195,59,148,179,31,35,38,44,200,139,11,242,143,182,175,45,16,253,90,69,226,168,
98,52,53,223,173,143,230,180,149,173,59,156,158,7,232,173,40,167,244,120,232,61,98,106,79,107,16,208,207,48,99,20,49,243,171,196,243,159,109,63,239,235,191,228,91,78,204,170,95,57,180,178,13,82,27,156,
150,185,143,60,13,107,90,0,108,104,191,230,241,128,26,62,240,86,79,57,97,239,132,40,214,138,150,45,53,67,13,194,65,29,123,239,128,157,161,139,64,160,60,234,217,4,149,206,78,101,108,85,108,22,93,37,248,
10,225,93,251,102,124,148,42,119,41,27,8,121,161,174,88,164,169,125,2,186,7,52,109,83,13,184,92,66,124,16,110,157,156,47,204,90,182,2,6,61,196,231,189,140,126,83,148,187,56,206,163,131,226,130,64,215,
4,191,116,36,12,29,156,200,111,181,104,77,214,144,25,104,2,181,130,142,230,223,46,145,5,58,54,228,72,243,114,244,154,102,16,193,251,158,165,45,156,126,56,126,68,233,29,1,193,1,114,16,181,90,203,28,228,
247,152,233,25,133,159,81,12,155,117,78,181,121,199,146,220,114,68,40,251,173,236,126,90,11,101,118,117,205,163,243,203,244,175,255,208,243,169,112,231,211,233,223,253,149,127,144,142,78,46,28,12,225,
109,16,253,133,203,248,5,179,80,255,135,127,252,199,210,199,63,251,131,233,241,87,254,113,250,148,188,49,43,164,28,13,205,82,65,96,127,176,247,78,250,209,23,190,31,25,227,47,166,191,246,75,255,45,162,
61,5,68,90,181,121,94,242,203,175,237,202,39,51,233,135,62,253,76,122,230,250,141,244,206,59,143,209,21,149,125,24,255,41,175,121,238,153,34,28,95,113,147,85,221,50,49,217,109,155,231,119,52,57,56,98,
124,163,168,1,194,62,17,49,244,34,58,82,66,89,151,10,100,129,66,225,25,197,54,74,98,64,56,181,208,186,148,224,194,250,212,39,167,105,81,62,31,52,70,89,187,104,69,217,56,4,156,174,174,15,101,5,178,163,
22,89,10,96,77,155,58,64,219,7,25,154,63,173,115,32,81,3,171,7,105,109,175,127,145,246,142,207,109,42,120,161,141,93,203,110,3,27,218,233,2,87,53,107,48,172,42,189,45,253,228,154,213,10,133,74,117,31,
180,237,1,225,68,247,211,123,120,169,47,177,88,103,81,216,49,233,218,54,22,144,77,124,186,107,64,78,0,74,208,80,50,146,49,197,58,70,158,151,148,70,122,80,216,229,114,135,190,13,85,4,123,35,67,105,32,198,
188,79,25,78,188,89,65,7,198,53,101,140,96,194,92,50,132,92,173,7,109,92,72,229,10,158,48,178,252,178,16,49,131,71,219,2,18,13,162,149,74,110,90,87,15,204,33,243,174,0,181,98,206,201,16,170,25,134,176,
226,185,50,7,8,125,182,96,140,212,27,58,168,6,222,171,165,71,243,29,48,242,60,15,93,215,78,215,158,28,32,252,187,55,72,117,251,96,63,253,107,207,222,72,243,207,110,167,127,231,151,254,54,195,196,41,18,
102,23,120,214,48,202,25,203,208,125,254,192,143,125,49,253,71,127,229,175,165,215,95,125,37,109,191,254,91,132,100,127,223,32,93,114,48,202,83,245,205,205,244,240,160,149,254,233,151,254,78,250,11,207,
207,165,159,255,147,63,61,91,199,1,244,153,104,168,154,106,62,253,210,215,119,210,95,254,191,190,174,206,121,146,150,161,231,29,165,163,151,155,103,233,161,207,233,198,141,27,105,99,245,134,177,24,200,
33,72,254,139,65,226,39,193,183,108,56,211,60,15,187,46,18,122,138,80,25,72,193,133,84,130,52,241,54,222,239,219,72,249,23,242,209,101,148,192,53,33,122,89,104,60,114,24,206,57,160,110,173,152,143,67,
254,165,184,238,115,63,144,230,248,108,34,86,185,186,62,156,21,200,110,106,176,94,212,63,153,213,240,219,22,170,53,160,147,35,222,112,232,195,60,83,123,235,226,182,230,149,6,171,66,159,203,61,234,114,
60,222,58,157,161,17,202,95,141,154,220,96,123,157,183,122,98,158,19,97,109,233,162,33,71,82,97,83,171,203,232,230,223,208,238,180,136,56,48,177,99,167,243,219,66,67,94,232,252,129,242,217,49,100,56,218,
187,28,2,54,196,192,61,52,168,194,159,69,119,177,124,241,194,201,222,97,132,57,93,41,21,63,95,177,161,240,120,120,38,57,148,29,51,132,246,78,120,97,46,152,145,34,179,83,6,236,54,232,249,56,76,46,29,16,
77,209,88,113,68,106,218,56,247,41,3,174,26,249,55,37,221,209,180,249,11,186,111,230,108,202,154,208,253,58,47,84,1,6,49,99,0,81,112,95,41,247,241,50,71,40,133,219,148,9,163,177,172,167,244,81,80,14,90,
225,197,43,188,248,71,238,174,166,199,136,25,63,251,139,95,214,115,25,132,123,228,246,8,101,133,158,121,192,90,220,227,242,250,106,186,246,145,79,164,159,255,15,127,46,189,254,79,191,196,139,171,73,18,
125,134,243,170,65,202,171,207,77,64,17,162,46,94,46,164,111,254,218,223,73,127,230,139,127,42,253,169,239,253,179,51,16,169,79,250,146,157,155,216,166,60,115,220,77,175,67,141,158,35,66,189,234,158,242,
232,121,103,34,156,45,200,215,138,3,229,182,182,177,232,215,204,12,141,53,210,70,22,18,223,77,57,106,86,45,228,194,58,94,34,140,156,249,153,150,131,168,128,88,146,97,196,123,72,11,240,106,127,71,249,195,
8,147,172,59,55,149,84,124,6,165,232,233,213,53,19,57,113,25,254,16,222,243,234,250,112,86,32,155,89,69,20,15,229,57,173,99,5,2,92,69,136,236,72,153,32,123,7,143,115,17,56,112,160,211,1,160,48,87,61,151,
107,41,167,44,2,128,168,220,181,81,206,38,232,99,243,8,11,165,239,42,116,198,38,237,10,203,78,132,178,125,57,205,34,35,40,182,108,200,246,50,111,219,78,151,247,94,230,37,201,104,232,229,108,209,159,45,
24,249,80,82,40,15,77,91,56,198,204,51,246,200,162,76,160,136,5,14,109,75,62,21,141,203,13,29,49,25,70,151,229,149,103,40,35,125,160,184,166,114,198,75,7,73,143,145,244,228,154,23,167,106,171,20,7,134,
52,120,203,235,129,80,186,215,115,98,89,23,248,166,54,95,91,78,7,238,192,76,130,130,226,163,206,202,5,51,90,160,191,145,183,95,90,194,91,141,3,73,35,115,140,69,200,88,139,53,3,100,39,74,48,23,251,13,32,
24,46,242,51,207,165,255,244,43,223,34,200,21,134,41,23,118,79,127,248,82,210,89,93,72,71,15,113,146,49,124,174,203,37,207,189,127,70,135,72,213,168,131,78,195,92,147,93,224,89,135,240,216,82,62,237,170,
37,159,31,190,156,254,226,159,251,179,233,218,202,170,103,122,242,106,49,181,45,207,131,254,239,223,122,45,125,229,43,111,107,18,199,46,98,180,207,58,191,238,120,157,57,7,95,150,135,28,49,206,137,126,
210,57,76,165,178,242,213,245,8,105,231,16,47,220,127,75,200,159,13,29,98,129,75,214,161,96,34,46,207,106,77,212,56,167,14,129,109,145,64,144,51,98,20,225,128,146,98,117,65,103,202,250,109,213,42,105,
133,26,180,170,209,147,147,247,15,63,224,213,127,125,0,43,144,109,52,118,103,205,186,43,130,169,5,39,109,93,57,97,32,236,60,197,6,24,195,209,163,217,122,174,162,225,89,215,126,14,154,90,148,183,77,162,
205,73,56,213,51,91,163,42,31,123,47,235,12,21,59,197,150,217,116,100,228,191,84,13,98,193,182,208,19,51,168,64,86,100,30,167,115,248,252,186,17,123,248,183,100,23,11,12,57,230,156,132,103,44,18,132,46,
7,219,198,6,10,47,87,114,194,15,129,33,253,6,189,30,2,144,243,16,205,89,185,35,22,37,178,32,6,85,209,17,19,140,150,220,2,163,179,133,74,192,171,57,5,245,162,205,41,37,35,229,9,149,84,242,104,80,39,152,
16,44,171,155,207,82,119,8,100,161,198,11,20,166,99,66,244,136,71,239,156,220,247,154,54,56,52,54,239,121,105,15,16,187,162,0,63,56,102,16,212,239,8,63,175,10,189,11,10,246,207,93,191,157,126,231,181,
3,194,93,84,229,81,251,50,140,117,106,195,79,229,154,33,219,25,229,147,240,160,187,247,239,167,189,215,190,70,122,43,122,69,209,33,125,125,155,87,202,82,215,83,22,5,254,144,9,145,119,158,202,116,43,0,
180,215,222,254,109,157,51,187,233,223,248,209,159,156,61,224,72,201,39,30,52,111,29,240,26,210,223,125,117,55,189,40,151,142,94,206,187,121,204,37,121,230,84,103,78,30,201,162,143,170,56,175,128,178,
77,68,122,149,1,159,201,35,223,82,82,217,149,79,63,118,95,151,60,105,134,20,11,224,119,102,248,179,137,219,214,0,132,173,31,116,154,30,157,34,241,143,77,40,131,49,84,158,131,59,60,234,167,55,94,57,247,
28,14,237,171,235,67,91,129,236,188,208,47,43,23,27,66,58,27,231,152,51,16,206,204,124,77,93,141,183,129,146,86,54,117,137,144,115,27,119,23,210,2,40,126,2,209,43,108,226,206,154,138,53,38,0,54,192,203,
157,70,103,195,187,87,0,15,53,134,91,55,139,50,242,201,134,49,9,161,80,222,179,169,90,54,225,185,118,164,131,199,59,88,111,194,38,70,59,18,154,238,242,192,71,163,6,166,13,110,47,210,121,95,18,92,44,158,
128,54,24,24,41,202,41,17,178,18,131,155,4,53,200,21,142,110,130,109,20,164,238,50,84,210,244,59,222,60,188,199,124,58,82,211,124,196,203,78,8,83,151,250,116,142,144,206,203,140,248,48,60,133,92,174,45,
151,140,49,13,251,194,219,5,204,162,21,40,48,92,104,38,67,18,175,222,102,108,67,52,196,84,20,41,200,221,154,66,81,79,157,54,188,233,83,198,203,223,19,210,255,227,183,238,205,238,67,48,233,53,227,217,159,
252,10,163,140,144,54,114,207,190,215,127,231,237,61,94,170,153,158,250,190,31,160,174,71,65,80,177,248,141,198,14,35,40,167,167,22,9,59,35,24,204,34,13,107,214,61,113,143,71,71,233,71,62,255,3,233,230,
146,96,26,210,27,115,78,66,213,161,28,145,6,64,237,141,189,71,233,123,214,244,162,10,119,143,48,175,2,156,122,102,228,57,117,11,13,212,134,91,226,253,17,210,125,220,83,127,246,57,40,59,201,203,51,14,157,
137,104,166,129,175,27,90,66,235,209,115,39,157,184,47,146,184,239,192,105,41,47,93,56,252,118,30,165,116,252,85,243,103,30,28,204,202,94,25,32,157,96,229,201,162,207,158,248,234,183,15,114,5,178,197,
117,121,136,58,222,144,81,30,41,190,31,40,29,116,162,172,113,222,74,215,140,20,24,10,185,30,223,191,167,28,129,12,160,175,50,167,109,106,81,119,253,170,206,21,66,109,164,56,108,134,119,235,236,145,19,
246,141,218,155,252,137,31,77,107,95,252,201,212,222,199,201,61,211,217,32,166,138,169,92,59,223,60,78,187,191,255,152,56,85,7,251,6,192,113,194,16,206,160,183,197,85,30,16,184,228,148,111,240,150,111,
30,79,210,3,157,196,97,22,33,75,18,122,62,161,250,23,29,84,177,241,194,20,46,177,146,78,251,200,17,254,45,102,130,228,183,232,198,202,159,242,45,30,91,103,72,86,73,40,135,89,179,204,216,214,121,159,224,
152,86,17,42,166,115,186,76,168,35,228,132,131,134,114,71,52,175,236,226,55,158,51,174,24,15,241,208,126,188,224,185,70,74,54,77,198,158,213,56,93,112,64,61,179,188,156,94,162,75,116,230,222,114,194,205,
216,182,25,15,255,222,175,80,85,8,118,77,180,225,133,209,133,140,229,63,249,189,55,161,220,238,239,243,63,150,94,5,82,85,7,203,26,200,229,247,103,0,38,204,161,188,70,240,92,120,95,29,59,141,111,191,141,
4,80,76,127,254,199,190,240,196,34,162,99,40,32,25,57,125,16,252,191,186,119,153,190,182,123,60,19,2,91,145,138,76,59,251,158,95,246,168,196,21,74,131,1,20,5,139,105,11,105,98,81,105,36,239,115,93,84,
63,14,34,126,129,113,70,68,113,98,221,66,201,176,235,144,45,194,24,182,74,27,105,221,65,80,175,35,87,248,158,131,71,200,17,59,188,40,244,62,134,24,95,93,31,222,10,100,91,114,199,203,168,255,1,113,74,11,
66,47,10,224,203,106,97,91,27,10,246,215,43,51,32,125,194,40,91,250,57,67,237,125,90,220,148,191,201,83,99,83,65,53,179,66,224,217,46,141,223,121,151,182,141,212,121,233,173,212,254,157,215,103,98,82,
33,140,44,111,97,208,157,116,235,26,249,143,79,220,73,119,182,239,64,7,41,148,243,196,5,96,211,28,160,101,197,6,139,121,158,215,117,78,220,202,83,18,16,16,158,11,251,174,33,72,152,150,153,230,215,174,
217,166,218,196,128,59,92,41,94,110,148,70,138,180,104,133,103,65,94,160,247,83,82,138,168,173,21,210,58,53,134,185,117,232,236,234,147,145,247,3,68,241,60,239,94,139,254,45,121,20,55,62,35,88,236,159,
32,247,179,248,85,161,225,152,139,200,67,121,131,92,126,34,244,141,98,239,134,50,208,84,152,124,66,106,228,53,170,129,135,4,164,47,16,45,194,114,2,148,226,150,222,13,105,223,253,83,80,159,15,165,8,134,
155,131,98,199,120,134,16,231,254,141,95,255,205,116,239,49,229,65,122,177,25,109,30,141,135,88,75,225,21,49,126,70,3,35,9,53,141,215,76,46,107,40,85,29,180,238,167,127,233,139,255,10,125,220,69,76,171,
40,241,132,119,142,102,108,126,20,154,252,63,125,235,29,212,66,237,117,214,160,163,92,117,224,128,153,138,96,184,123,26,77,14,17,243,86,79,244,216,54,124,111,7,104,212,224,201,187,66,215,37,121,102,8,
133,237,49,224,253,232,33,245,122,69,135,73,71,167,208,56,135,122,184,56,175,49,93,100,131,167,91,149,191,22,213,130,47,141,188,119,254,198,98,92,93,31,194,10,100,67,64,202,144,13,212,48,220,202,24,145,
119,66,141,160,125,0,32,208,13,161,160,95,206,109,26,230,115,45,141,72,114,52,21,172,199,242,69,131,148,1,42,40,119,144,73,231,241,108,3,197,189,71,142,18,35,22,170,59,47,165,131,221,151,210,16,223,118,
113,53,72,234,38,94,241,142,89,33,242,4,235,102,58,57,179,137,144,7,120,190,131,243,227,244,248,92,39,137,122,226,64,56,25,100,165,173,109,51,48,133,129,25,192,211,177,172,172,225,4,31,155,80,61,5,94,
100,229,149,65,8,239,81,90,40,28,245,204,10,37,114,45,87,157,50,158,144,20,153,96,253,196,140,150,172,238,144,80,22,44,230,151,141,29,172,67,110,181,121,225,199,150,133,240,3,226,217,19,255,221,64,51,
60,213,195,218,183,209,3,105,206,199,6,14,20,84,78,136,238,155,74,24,78,85,181,145,145,62,209,85,78,76,71,102,250,42,195,138,237,154,137,250,46,46,107,6,232,245,7,191,252,124,36,187,177,34,12,56,60,105,
145,2,193,37,190,227,217,254,78,58,93,220,78,175,50,214,117,196,244,104,90,63,22,150,86,235,107,105,89,138,16,157,56,59,20,20,30,189,244,143,211,186,210,202,143,124,246,115,177,162,106,162,60,88,188,135,
247,138,252,243,154,252,241,25,185,253,22,86,211,230,86,61,221,220,208,12,78,243,183,230,215,221,91,207,107,142,175,34,92,16,205,52,199,166,109,157,230,28,72,57,81,78,116,188,92,106,89,187,179,186,33,
119,118,204,5,211,72,77,56,3,63,40,83,217,219,233,214,211,110,35,159,110,11,169,111,252,177,165,116,237,38,86,210,43,111,166,135,199,234,108,87,215,135,178,2,217,233,98,132,111,54,18,70,206,38,133,115,
159,22,143,16,19,156,87,156,158,193,85,5,96,44,104,138,22,226,206,67,65,35,92,27,51,230,161,80,72,100,234,250,131,131,53,80,198,82,141,26,222,51,119,210,42,253,158,138,218,98,33,152,43,54,152,96,56,29,
10,203,246,95,217,75,39,180,96,67,221,61,154,154,218,251,78,105,69,239,182,131,224,173,221,94,122,120,70,178,17,201,62,71,77,221,84,18,211,181,209,20,120,223,38,66,193,8,119,246,189,119,196,3,152,41,177,
183,180,163,189,97,248,111,208,110,251,242,179,206,137,67,69,57,104,12,168,202,11,35,39,49,33,218,127,71,78,213,132,150,214,108,198,60,241,171,41,146,2,252,131,176,85,12,153,157,57,67,65,57,15,195,227,
60,227,77,158,81,110,89,211,14,119,99,169,156,158,118,4,61,163,141,179,160,108,113,74,213,46,60,247,12,250,202,138,36,102,26,68,161,67,36,156,141,255,86,154,137,176,118,226,235,19,225,43,59,157,93,29,
202,16,153,21,196,191,237,219,74,79,90,208,78,52,171,243,214,29,107,209,226,173,218,74,31,142,153,148,21,82,62,124,253,119,210,23,127,226,83,36,75,229,250,17,41,204,174,24,148,100,141,140,76,252,205,123,
59,104,122,14,0,36,252,154,178,202,169,190,208,129,250,230,254,203,175,168,185,238,233,88,71,128,23,218,222,66,120,223,240,12,91,88,66,93,160,85,209,215,150,52,24,116,120,200,37,57,122,232,40,85,228,156,
151,205,90,250,253,139,78,122,96,244,131,98,180,90,183,38,238,117,146,39,13,229,153,119,223,253,234,143,15,126,5,232,60,106,218,69,58,216,167,84,208,7,162,4,59,166,16,253,146,58,237,187,106,133,93,155,
172,173,115,193,126,20,22,65,94,144,3,134,250,252,50,74,17,35,204,146,239,54,206,128,33,7,217,19,101,18,198,193,91,213,150,175,169,29,162,207,33,34,100,104,229,44,182,46,228,50,235,216,69,207,136,194,
106,200,10,40,101,66,208,121,99,16,162,176,87,37,42,189,162,22,215,10,145,47,245,206,229,5,158,206,244,231,229,229,114,186,61,127,87,193,92,207,169,27,153,133,148,138,124,3,158,51,12,161,205,11,13,140,
50,200,147,249,136,170,70,14,97,59,199,48,70,0,163,129,141,25,245,212,205,101,224,15,81,172,163,193,150,214,181,16,188,210,37,195,91,173,35,228,227,252,204,142,152,56,102,42,242,180,32,172,181,35,180,
181,145,23,232,182,142,22,33,187,14,173,125,109,92,195,217,155,123,15,77,202,51,72,248,59,159,89,228,158,84,20,188,111,24,106,70,120,60,243,172,234,137,113,205,47,109,166,213,23,62,146,222,209,234,213,
245,163,53,138,15,85,135,77,12,71,90,246,86,219,238,101,75,94,59,89,152,166,195,87,118,211,167,63,255,124,250,193,103,111,49,32,39,199,187,87,120,227,6,143,248,55,31,104,121,215,137,114,67,61,242,100,
239,33,197,138,99,245,90,164,15,245,222,130,230,111,189,0,233,58,4,92,195,74,26,41,165,76,168,67,60,85,175,166,207,1,179,66,8,237,204,33,117,166,238,185,36,108,90,35,226,118,158,109,167,107,200,198,27,
66,248,14,126,46,8,41,205,139,58,170,93,26,74,221,131,247,222,254,234,207,15,120,5,148,12,87,168,197,201,77,46,17,195,79,53,240,82,206,155,202,229,70,189,166,124,3,87,85,119,201,4,184,210,137,214,169,
160,126,218,164,149,153,168,50,163,35,70,44,114,251,206,53,6,96,180,17,167,171,72,237,85,202,114,147,67,212,50,128,68,110,213,200,191,230,161,77,175,216,198,240,51,53,240,63,207,11,220,79,75,215,229,173,
12,39,38,127,105,200,72,91,43,188,25,52,120,131,60,227,192,100,236,111,17,149,254,127,78,75,233,75,7,123,202,42,234,122,118,104,28,20,64,96,173,79,12,152,65,220,118,72,212,228,121,93,68,247,177,250,105,
116,185,28,241,168,175,208,243,217,7,104,21,161,62,117,157,54,155,158,115,153,39,111,201,177,181,176,50,27,92,175,230,208,0,0,32,0,73,68,65,84,94,9,152,20,252,223,247,174,247,254,214,242,220,230,22,32,
12,184,79,104,231,20,42,154,87,183,41,2,195,226,26,11,119,51,194,248,63,252,11,90,42,167,204,65,66,115,72,24,145,119,70,8,30,215,51,159,66,100,231,72,151,1,72,207,223,126,90,13,118,73,235,90,46,45,10,
77,47,86,41,215,235,179,60,71,183,59,131,88,191,122,140,212,222,93,77,255,230,231,62,235,30,133,220,179,194,103,60,183,131,201,225,209,210,86,119,130,130,120,99,133,202,189,240,188,214,172,104,216,142,
246,185,56,104,244,146,58,160,234,26,221,155,14,8,182,140,74,169,228,36,53,240,211,4,192,16,14,148,158,42,162,164,19,175,119,106,141,54,124,70,79,149,86,177,163,220,135,131,163,242,209,141,84,122,90,136,
222,38,59,29,125,166,87,215,135,178,2,217,208,138,89,91,157,79,215,86,9,65,221,102,56,70,15,92,66,60,207,130,141,2,104,169,169,15,158,41,236,151,120,182,44,213,241,54,50,122,22,248,50,14,29,218,205,219,
218,170,240,108,25,110,196,111,93,161,89,137,250,219,210,115,134,253,160,201,93,56,153,179,20,237,46,136,227,52,132,184,37,60,216,108,245,66,56,118,138,27,170,53,205,190,157,213,82,79,209,223,120,88,163,
158,161,160,0,9,61,133,99,238,228,200,230,126,81,202,211,101,64,215,150,168,217,185,135,39,229,10,205,195,128,159,60,173,33,98,123,105,101,89,173,16,138,92,80,154,152,6,122,44,92,108,246,23,120,4,226,
204,38,156,181,129,79,17,158,141,228,184,117,200,241,13,53,213,172,127,59,231,121,26,0,161,119,43,52,54,175,179,131,23,157,49,222,212,36,135,66,197,105,73,221,143,55,250,150,198,232,224,164,174,44,62,
53,251,160,222,51,186,217,127,124,215,111,113,127,161,153,23,222,115,74,179,119,160,108,19,245,208,239,127,254,83,41,221,123,59,253,36,93,162,218,152,82,1,67,207,105,127,105,29,105,20,56,20,214,242,228,
167,144,228,190,67,237,196,220,210,87,191,254,229,244,244,71,191,39,125,82,200,31,157,45,83,66,216,145,28,48,81,29,63,197,244,117,221,48,77,33,182,216,33,157,98,107,140,13,154,154,58,124,118,176,132,126,
95,56,191,239,36,56,115,144,180,176,151,14,36,242,175,58,24,190,33,79,207,0,225,106,212,47,234,24,78,13,66,109,59,197,230,19,68,92,77,251,101,234,20,123,251,120,203,191,186,147,14,223,190,76,175,237,62,
78,247,222,121,233,187,158,238,234,175,31,228,10,100,123,185,251,84,192,47,211,250,181,143,167,242,115,235,34,57,90,176,122,23,235,183,33,127,216,34,33,127,89,93,44,165,5,27,169,36,79,27,50,214,162,58,
93,149,60,100,33,12,10,61,236,73,104,139,23,27,224,3,47,54,149,247,228,205,243,43,111,219,88,242,155,58,207,181,77,181,238,26,141,219,28,133,244,170,28,180,6,112,42,250,249,92,137,68,37,86,252,2,169,144,
22,197,133,199,114,213,151,119,11,233,157,147,30,1,43,237,102,216,57,63,188,181,158,158,134,36,207,58,188,189,91,68,122,143,142,9,93,243,4,57,97,118,62,122,51,121,168,12,253,163,177,251,28,173,0,98,168,
212,173,34,162,239,202,155,119,9,142,101,148,79,58,154,189,59,188,68,197,215,151,253,119,156,41,42,52,186,49,34,135,116,48,241,202,11,54,108,20,16,130,194,24,132,130,220,244,66,71,136,65,194,66,195,2,
145,174,239,255,4,160,198,123,141,103,7,82,152,243,31,190,2,0,202,201,217,209,7,212,10,229,231,56,171,127,230,79,255,80,90,186,189,154,118,118,222,180,14,139,122,56,49,158,140,189,104,107,238,238,11,147,
235,16,222,107,207,124,78,167,206,22,15,221,72,85,33,233,193,206,107,105,186,8,228,249,200,109,175,19,217,48,196,22,24,86,136,53,6,127,31,57,48,167,214,40,164,83,150,220,6,233,37,247,125,145,22,245,214,
134,106,224,62,94,113,155,81,15,229,148,83,61,168,77,64,84,76,254,46,74,37,122,94,239,240,72,222,202,107,174,81,48,60,160,121,91,148,159,70,205,248,145,83,162,191,51,77,199,15,116,41,137,84,106,242,206,
171,235,195,89,1,162,232,54,172,77,249,250,43,199,233,203,127,63,96,250,234,76,77,64,101,67,39,201,5,192,160,156,182,24,96,222,46,30,130,238,51,212,224,115,11,155,180,113,212,64,207,223,208,55,232,168,
125,55,15,11,244,182,72,148,122,26,109,103,202,26,5,224,202,184,99,236,43,214,79,132,115,51,189,34,189,20,37,53,182,232,143,236,232,206,24,96,187,132,210,92,147,39,105,55,235,233,236,48,151,190,45,188,
14,22,234,26,70,204,22,162,246,59,103,141,244,149,151,247,17,22,66,114,146,239,0,168,116,22,110,177,210,208,198,61,77,175,63,196,133,181,177,218,250,81,139,72,7,49,16,120,78,25,36,75,40,235,156,151,120,
11,50,185,215,57,154,53,30,31,70,193,95,71,73,94,88,10,50,82,227,83,242,224,237,134,81,159,244,191,160,28,137,140,145,48,46,65,88,116,24,32,216,33,155,82,68,23,60,108,237,164,63,253,241,207,166,207,62,
243,89,222,76,78,139,85,243,71,175,25,149,207,179,78,212,18,39,74,24,181,185,74,250,254,159,248,243,233,31,254,189,175,164,27,79,127,34,181,87,111,165,157,150,218,47,0,172,113,182,239,64,171,66,141,135,
233,165,211,215,105,1,31,11,193,29,36,60,224,9,90,208,240,224,141,244,212,138,56,223,245,4,17,150,147,58,153,198,14,182,125,50,151,143,24,207,86,240,146,221,119,65,52,35,56,17,53,240,190,76,185,130,168,
80,16,210,183,133,243,33,218,50,7,189,94,102,160,101,229,160,17,52,251,84,158,9,243,74,55,125,190,135,158,177,162,28,243,17,4,135,2,14,117,76,61,171,213,52,175,59,36,206,118,14,254,232,35,94,253,247,7,
180,2,217,249,204,54,253,29,12,17,229,147,165,178,153,25,107,49,30,0,207,210,8,61,115,218,83,6,154,155,3,170,12,59,194,47,155,174,182,64,111,86,75,88,113,139,231,177,17,46,21,216,217,203,187,23,120,158,
84,100,142,145,134,33,102,109,182,156,188,116,91,187,87,30,253,111,71,254,182,44,124,158,83,75,141,154,226,88,184,154,149,79,105,144,48,72,150,188,8,53,188,117,37,150,207,249,153,187,120,190,47,112,204,
139,8,5,45,208,108,81,215,73,70,78,5,33,241,126,149,244,244,205,53,194,203,54,50,239,59,87,11,61,35,237,109,16,198,42,80,37,186,52,162,233,58,178,189,165,162,134,112,39,205,97,220,187,220,113,65,57,98,
67,11,213,6,120,183,14,129,14,82,66,75,30,23,244,182,48,124,118,44,215,142,113,12,198,14,98,28,181,59,14,9,57,219,134,161,69,249,243,147,212,62,254,70,250,171,127,253,191,72,79,125,250,51,202,28,193,71,
69,150,16,190,78,2,173,141,80,214,175,240,150,17,206,102,213,109,63,243,19,95,76,95,209,143,89,127,238,86,122,234,185,79,136,8,240,113,25,246,188,1,81,49,89,59,211,196,101,21,250,159,162,219,45,169,85,
134,228,203,144,161,157,185,251,182,48,243,199,55,175,167,117,86,20,234,18,79,34,148,104,248,46,165,29,6,118,111,201,129,247,148,209,9,202,67,13,232,119,211,250,92,64,210,43,60,235,80,136,63,148,135,95,
232,192,201,65,187,111,202,105,87,16,220,151,162,153,118,170,33,160,120,3,18,143,88,33,7,205,10,127,143,120,209,11,84,198,186,142,148,152,179,218,119,96,196,224,226,7,143,95,138,55,190,186,62,132,21,200,
110,16,23,190,233,195,172,2,55,214,22,168,229,25,3,191,171,72,221,130,104,86,180,20,77,124,128,143,123,123,64,8,193,222,165,193,171,85,83,182,108,192,211,55,20,177,109,224,121,138,5,236,229,201,197,26,
186,58,81,70,3,249,31,64,37,99,51,204,9,137,243,66,39,116,121,19,172,156,240,45,10,238,254,109,224,117,203,1,84,160,249,25,120,158,214,16,229,159,209,219,85,127,97,62,109,63,143,118,71,147,118,130,246,
39,48,22,210,246,210,134,89,34,49,211,36,78,130,120,187,214,142,18,207,169,210,9,120,54,43,111,142,209,16,211,134,137,89,198,183,183,116,179,136,156,69,1,208,94,204,155,185,2,35,70,192,239,218,116,161,
172,87,94,207,166,91,155,6,252,4,248,37,207,125,210,205,25,225,242,24,89,98,53,221,128,202,198,44,150,29,121,230,89,238,84,132,32,15,70,30,95,165,101,251,141,127,248,203,169,249,246,195,244,215,255,199,
95,74,223,251,195,63,35,23,84,234,177,177,7,164,88,226,87,95,227,192,80,61,120,235,238,221,244,115,255,193,47,164,143,124,225,79,208,129,189,150,62,119,243,150,193,78,123,72,26,103,105,145,150,110,76,
38,187,148,119,151,25,83,30,199,117,177,82,246,62,20,119,49,7,43,144,231,162,116,98,95,55,204,83,119,214,180,206,49,24,97,116,12,24,158,100,176,173,228,147,1,148,191,125,89,72,15,113,143,115,80,229,19,
57,116,48,149,70,126,46,59,21,173,32,42,224,23,88,217,105,186,174,174,122,93,143,231,138,144,183,64,41,97,197,107,109,82,87,204,72,81,30,101,141,67,148,119,15,105,233,54,124,238,83,221,73,2,27,17,9,224,
200,128,171,63,249,239,255,91,159,253,141,223,248,141,89,209,236,67,216,159,255,66,191,101,190,221,208,8,205,187,168,98,160,142,5,181,203,134,161,157,51,188,228,41,15,142,64,162,70,247,228,182,82,121,
109,29,80,212,76,189,230,126,26,19,4,155,86,214,245,100,50,192,239,120,77,7,50,251,237,29,200,222,158,161,98,192,187,245,17,207,135,181,35,202,227,26,183,201,63,230,233,178,30,143,247,149,58,230,160,168,
0,25,121,83,157,135,110,10,211,234,52,108,46,47,10,233,252,53,253,164,104,102,69,70,156,221,66,126,87,22,216,166,169,123,112,40,14,230,13,109,65,121,48,148,248,240,177,191,151,249,23,58,64,81,80,87,250,
88,12,99,6,184,4,187,167,203,11,60,114,36,212,229,160,79,9,187,47,218,8,13,6,241,78,161,208,215,220,104,27,50,153,14,238,33,238,211,68,82,184,143,199,152,218,220,203,242,192,138,28,121,82,190,76,55,209,
247,66,187,231,197,198,113,122,122,5,121,157,106,125,136,74,191,254,203,191,144,62,186,246,223,167,255,225,127,254,95,210,151,127,235,119,211,63,250,237,255,211,204,151,67,249,49,141,33,6,190,86,185,153,
126,250,79,254,148,242,72,62,61,60,57,75,111,200,167,179,175,189,156,22,247,127,75,23,10,197,247,236,70,58,218,223,227,201,81,56,164,12,151,140,37,47,114,89,16,105,44,1,190,50,202,59,151,98,212,243,147,
7,208,85,154,66,213,82,122,217,29,198,215,99,184,110,200,92,70,222,189,67,99,232,83,242,210,107,140,185,134,9,20,200,122,233,76,137,74,73,43,122,83,167,38,125,43,235,206,216,92,247,48,193,230,64,183,91,
21,132,19,132,134,73,207,49,37,108,157,16,219,142,113,131,139,84,0,151,220,79,199,33,124,242,138,207,206,8,240,249,187,240,134,126,255,175,222,59,254,123,127,195,242,156,255,11,109,41,31,194,195,231,219,
147,181,212,92,232,166,50,21,62,81,95,42,173,168,137,49,172,45,229,146,162,48,113,204,107,92,118,22,210,120,161,173,145,24,143,117,108,20,57,58,91,73,94,217,155,117,54,132,49,184,88,105,135,8,87,120,162,
32,126,47,40,112,55,201,108,22,77,171,46,53,76,156,230,97,247,245,128,58,1,82,113,91,125,49,88,58,136,15,77,173,89,33,34,221,71,195,59,49,170,161,108,147,117,228,69,199,64,146,2,239,117,8,244,8,82,65,
71,43,85,38,230,7,50,208,2,96,106,147,17,181,104,238,180,121,198,238,192,102,50,44,87,51,169,70,107,38,107,36,31,26,120,58,179,233,214,51,203,54,216,161,123,66,55,20,2,199,180,180,174,48,187,41,228,235,
120,134,45,225,115,116,170,101,149,94,68,221,198,64,184,7,95,88,230,101,163,196,52,49,202,224,154,201,100,36,122,120,52,195,145,32,201,243,60,241,209,47,254,149,212,127,231,219,105,253,206,231,211,207,
254,233,63,71,115,135,48,217,237,235,6,49,209,245,221,165,131,187,171,173,167,241,78,42,223,223,53,243,244,117,51,90,98,4,4,144,69,132,178,224,57,86,139,151,122,109,16,214,203,91,105,176,54,151,230,206,
41,240,173,88,107,141,216,23,161,40,40,188,206,2,170,242,106,143,159,223,90,77,191,250,240,132,113,170,145,32,173,115,148,62,135,81,218,217,107,167,111,206,53,211,179,107,64,55,245,211,123,12,171,8,48,
90,225,93,171,30,166,233,231,235,14,152,11,50,166,151,250,80,87,124,174,13,105,200,8,7,121,205,250,191,163,183,54,111,252,68,57,186,140,28,142,165,104,118,23,202,46,109,108,82,252,163,102,129,19,245,245,
223,126,169,255,143,190,236,196,189,186,62,240,21,200,151,23,33,181,0,146,158,58,217,4,125,43,68,172,134,60,93,27,125,102,81,110,88,221,226,205,78,53,60,67,249,166,192,135,100,132,192,180,77,182,228,242,
72,94,114,219,4,232,13,6,99,39,5,199,150,225,132,154,222,192,107,21,228,107,203,186,80,106,235,154,149,79,197,87,78,240,194,106,29,149,45,164,50,16,179,213,60,91,68,196,186,132,178,38,84,226,139,131,16,
55,14,207,81,79,199,70,64,20,213,76,175,65,69,107,6,252,236,11,121,59,71,70,215,203,131,194,197,133,140,70,101,21,40,228,116,175,147,66,41,154,249,81,33,243,152,99,72,71,123,56,167,64,159,117,34,56,215,
17,233,199,144,232,182,80,189,238,181,202,114,215,115,250,182,85,224,72,128,36,235,180,133,226,231,23,133,113,3,7,69,140,213,107,34,254,239,66,58,63,121,131,1,16,134,46,18,125,94,90,148,211,98,33,197,
225,21,156,222,150,146,202,248,232,97,58,255,210,223,72,111,140,254,143,180,182,254,188,208,20,10,251,209,27,105,219,189,92,188,252,14,176,231,148,236,37,224,137,241,95,103,228,217,11,228,123,72,240,202,
82,12,48,50,141,91,218,80,142,94,214,85,189,50,104,123,125,222,249,84,190,55,106,55,132,149,58,68,132,12,133,0,223,228,134,153,249,135,60,97,0,65,145,207,187,9,222,179,32,68,141,41,97,99,253,172,101,114,
158,69,81,72,28,30,37,45,110,30,35,85,245,208,53,253,217,246,31,103,66,221,73,168,59,40,199,140,105,41,77,52,170,47,58,204,214,120,206,182,114,81,67,249,101,29,81,100,93,190,158,81,202,42,220,150,51,163,
46,206,107,86,216,224,105,165,199,87,215,135,176,2,217,42,20,178,36,135,172,97,225,68,29,173,137,221,115,198,72,95,63,55,219,228,33,161,127,225,232,169,16,233,24,114,122,143,145,142,156,198,35,221,12,
151,70,49,204,140,50,10,249,113,1,145,2,157,236,210,63,29,229,15,0,24,39,84,21,130,168,0,137,85,234,24,235,188,88,112,26,23,24,65,190,161,23,116,120,154,6,132,87,171,186,241,139,161,74,128,131,219,113,
218,103,240,95,87,214,132,110,114,72,91,26,41,27,223,183,98,90,52,182,131,183,158,93,81,75,84,189,84,55,5,248,32,236,47,199,32,38,198,217,102,104,195,42,100,153,216,87,91,126,24,122,179,133,21,212,67,
97,116,1,235,160,169,22,154,149,227,118,120,239,99,124,217,86,16,34,132,195,19,96,12,123,176,249,149,144,150,54,16,33,214,108,82,234,73,70,22,100,136,102,47,204,43,218,120,141,56,124,86,132,140,89,36,
245,12,209,179,250,6,85,248,114,59,173,159,190,150,202,187,255,48,181,126,227,151,211,228,107,191,149,22,207,30,165,231,148,120,238,234,101,149,232,81,39,52,154,194,140,146,108,168,234,183,28,42,248,203,
143,38,26,176,121,175,252,133,220,221,56,197,254,197,97,58,61,55,225,203,172,19,99,139,228,193,115,233,222,129,175,31,182,210,93,83,198,209,99,223,125,120,128,80,200,176,88,155,168,231,110,162,87,46,9,
193,187,85,229,168,98,27,139,75,94,170,214,27,186,65,23,74,47,121,33,239,71,1,62,142,84,157,60,152,63,222,115,203,103,54,47,194,121,138,68,203,124,172,121,52,158,59,200,54,24,58,249,168,116,241,6,22,216,
30,117,251,205,82,250,194,231,106,233,167,223,254,117,56,240,213,245,65,175,128,79,120,62,245,160,157,225,45,7,202,37,115,194,218,188,16,239,226,72,120,201,251,28,1,57,2,32,128,195,51,52,115,57,148,78,
98,180,66,200,73,182,207,223,212,179,9,106,71,178,29,153,168,156,97,228,96,25,221,244,136,168,38,95,101,124,127,161,79,11,85,24,87,128,44,230,200,251,13,243,167,44,74,7,197,2,208,135,26,64,237,244,16,
34,219,230,93,141,133,39,183,57,12,194,58,212,114,200,19,103,133,93,18,165,180,110,108,253,28,195,120,215,54,21,223,21,236,53,8,151,181,53,29,27,61,16,141,41,185,138,92,173,110,74,214,130,142,20,234,4,
71,0,145,22,138,91,137,193,245,69,6,13,30,116,9,58,187,4,26,62,115,224,28,234,85,221,65,80,136,233,101,38,37,208,30,2,184,120,131,37,121,229,162,159,39,208,226,25,136,98,51,130,85,97,224,246,134,117,41,
95,164,38,96,106,34,108,46,42,57,172,57,29,182,121,170,229,197,110,218,90,90,72,91,192,155,165,91,192,175,69,29,50,140,122,177,178,2,88,2,128,241,112,171,210,130,122,251,62,176,204,52,112,52,200,10,9,
152,114,97,251,9,139,72,169,169,140,144,222,19,61,228,74,183,133,211,250,100,241,127,143,66,81,2,178,251,201,91,207,166,59,65,237,139,221,225,192,153,101,222,225,64,213,144,67,32,122,100,141,58,209,77,
162,139,167,110,36,197,4,26,86,240,243,209,74,87,96,132,85,222,177,130,87,187,169,11,102,74,122,164,170,33,225,186,114,84,176,159,150,132,208,139,144,245,188,92,122,77,58,178,233,0,173,32,45,44,93,195,
217,125,83,39,205,171,141,220,167,127,241,127,253,227,31,244,198,188,122,191,72,107,232,152,106,117,180,41,208,200,98,54,134,19,184,80,59,215,223,135,10,166,84,81,159,239,240,38,33,187,161,157,108,30,
195,36,122,19,81,231,18,177,230,75,161,80,182,16,117,56,158,206,239,115,26,125,43,114,158,254,185,206,135,220,138,232,43,94,27,217,220,160,158,60,79,152,7,235,23,9,115,77,66,30,4,181,167,99,163,119,81,
214,154,106,162,45,163,251,134,84,11,186,60,75,213,233,62,79,33,161,143,0,176,201,75,220,50,209,172,4,141,124,207,56,149,224,120,78,226,97,16,223,5,175,19,163,26,230,214,9,142,201,233,206,137,117,93,2,
60,206,162,83,131,87,190,53,183,130,137,164,228,227,123,99,160,236,121,76,1,99,136,151,163,102,26,236,80,19,100,104,193,95,141,124,58,15,16,57,67,115,187,80,6,217,226,145,43,80,209,188,16,185,137,233,
116,129,27,156,5,222,116,121,240,230,197,57,47,101,156,4,84,218,152,161,212,93,173,164,67,253,149,67,228,246,206,254,99,72,183,38,114,195,100,134,33,108,38,124,207,159,80,20,164,168,95,18,198,182,145,
27,66,165,254,249,181,169,246,185,23,210,210,13,83,196,227,193,16,40,106,181,38,218,162,182,55,99,25,214,120,249,59,94,243,220,251,14,12,40,90,128,156,6,8,196,125,207,208,242,40,219,132,2,254,46,192,42,
139,31,91,85,70,57,16,225,196,9,179,33,117,216,226,53,215,107,34,7,101,169,93,72,243,169,220,115,81,157,58,239,103,242,84,32,134,216,94,13,134,92,132,118,243,221,212,8,151,140,16,196,105,166,116,17,99,
232,231,86,106,233,205,87,17,48,116,122,247,203,253,191,28,239,124,117,125,176,43,144,29,43,102,247,108,190,69,101,145,53,211,164,67,110,99,89,79,101,173,46,119,9,58,94,113,105,54,153,186,9,176,152,200,
249,98,14,101,143,44,70,143,183,139,58,103,102,166,195,243,196,108,66,174,36,114,187,140,238,140,172,188,168,207,115,142,212,19,115,5,155,1,136,17,161,227,80,231,67,78,137,35,195,24,230,161,144,27,138,
238,115,186,40,170,242,194,57,161,100,153,202,123,87,41,34,199,88,243,78,248,24,32,187,243,0,81,33,106,145,239,174,77,65,140,87,245,51,109,73,213,64,111,105,33,118,45,100,184,48,66,206,101,204,67,114,
36,43,234,122,69,33,94,168,48,84,132,120,101,94,225,196,247,116,180,157,173,2,120,190,87,219,218,77,76,168,134,104,97,143,49,230,228,99,113,33,16,42,87,48,125,200,104,223,207,103,212,116,235,184,194,203,
36,240,75,104,113,157,200,131,149,66,218,134,43,157,157,51,62,27,28,155,94,35,58,173,219,168,83,10,53,231,188,127,46,154,0,132,219,227,8,247,215,208,232,68,35,189,9,239,216,91,77,21,95,95,190,99,77,52,
68,239,189,9,60,178,54,109,76,159,14,210,192,148,247,115,246,168,119,50,98,2,215,23,234,168,59,147,29,234,8,62,27,72,122,116,146,100,133,196,65,74,112,182,58,16,124,13,219,169,171,129,224,49,221,220,113,
196,191,148,223,7,56,183,65,132,184,196,82,10,189,95,203,157,14,148,178,226,207,145,49,13,143,91,29,128,81,112,161,149,98,72,178,152,95,150,118,143,12,72,162,128,49,52,71,181,181,171,148,115,81,76,111,
239,159,165,221,87,126,255,255,203,182,136,197,186,186,222,215,21,48,195,213,168,59,61,130,23,216,46,67,229,138,238,91,230,163,32,12,76,32,127,83,196,239,121,161,86,22,218,215,58,4,239,67,85,35,68,42,
128,249,91,140,182,145,81,78,137,157,245,222,197,70,243,12,97,26,210,34,102,147,100,59,193,5,245,250,6,197,14,48,98,66,230,178,216,5,32,133,118,109,169,105,83,180,210,35,51,62,118,31,243,2,152,74,181,
181,160,206,49,68,2,91,5,222,173,6,217,140,158,210,140,3,161,229,103,135,65,130,141,115,0,46,85,167,233,186,40,100,27,243,252,23,190,255,152,7,47,224,226,174,109,78,211,211,128,172,235,202,37,113,111,
151,192,170,115,210,36,85,175,183,134,253,179,128,61,187,160,163,100,133,168,245,122,29,245,173,230,223,220,229,37,144,39,94,58,136,8,115,124,73,75,113,126,90,212,133,114,129,152,208,84,18,66,174,32,210,
128,155,91,39,89,178,13,224,18,18,99,35,45,45,99,211,56,164,22,180,154,12,109,236,177,102,231,5,227,236,115,93,36,141,202,50,143,44,31,214,11,187,199,187,55,247,79,145,1,0,99,194,198,24,18,85,124,249,
126,234,146,223,196,113,23,182,163,252,1,218,74,103,90,217,220,3,117,89,7,37,146,65,110,57,45,105,51,89,217,142,8,229,201,33,232,46,103,7,85,228,212,103,88,63,247,91,66,107,121,251,109,189,171,77,67,114,
119,201,196,196,192,169,240,200,117,158,186,42,84,159,23,134,47,200,125,203,101,28,231,192,25,230,28,6,170,35,62,133,52,143,37,148,213,50,86,35,217,82,174,107,32,80,171,237,99,92,221,160,146,49,118,144,
62,124,69,73,237,234,250,192,87,32,159,3,197,149,132,175,99,134,114,174,206,185,109,115,53,185,184,76,127,41,229,17,202,101,119,140,43,171,33,186,168,81,87,63,167,173,156,21,178,109,96,218,108,221,178,
213,229,131,118,244,236,198,35,240,44,64,104,139,140,100,8,108,201,218,200,89,165,139,106,132,83,66,174,178,206,147,67,49,52,94,144,175,175,33,121,211,3,64,147,171,69,137,0,11,38,212,224,70,114,69,96,
190,247,8,70,3,239,26,45,95,234,158,187,124,218,199,120,227,120,167,248,85,96,168,77,185,210,165,124,112,96,23,198,100,235,21,97,112,23,237,109,170,46,27,13,222,178,177,84,144,27,111,133,98,2,15,28,199,
200,246,172,175,57,74,68,225,137,66,153,23,169,159,167,28,59,120,98,51,199,1,50,8,145,51,74,243,34,224,116,70,137,61,198,189,231,25,200,197,64,114,42,119,59,75,135,134,238,246,149,27,108,112,74,129,83,
224,211,161,255,94,6,251,102,133,230,243,100,52,163,147,167,125,177,151,154,193,180,130,0,47,173,82,86,184,22,173,120,74,60,158,165,73,162,165,158,131,134,94,215,204,77,82,175,173,77,110,1,224,54,150,
175,143,232,3,13,35,135,103,236,23,64,156,174,174,156,219,17,85,184,255,152,148,157,99,180,153,200,201,25,86,163,61,72,135,0,165,59,55,182,77,190,22,153,136,2,174,41,251,132,168,88,77,8,30,53,224,177,
158,81,173,235,179,28,62,234,182,21,159,87,136,171,245,28,8,213,58,114,134,215,124,4,88,248,196,0,44,43,21,201,201,121,175,175,72,95,28,36,135,167,231,233,240,242,117,239,124,117,125,208,43,144,109,27,
72,180,36,231,92,129,240,85,121,195,75,117,181,156,217,34,115,250,37,203,79,153,172,124,87,183,188,13,236,147,181,165,24,141,90,217,64,121,227,194,166,125,164,192,30,130,86,239,93,51,199,38,39,237,235,
13,45,106,208,174,26,8,155,213,45,17,51,72,46,133,84,81,155,203,67,73,115,97,204,190,214,114,58,103,33,133,27,186,249,123,104,107,37,84,185,104,64,190,16,114,30,243,192,199,216,62,237,144,208,148,97,46,
159,233,158,224,37,98,142,102,24,209,142,247,56,214,214,210,50,192,103,232,48,88,228,41,230,169,16,20,58,68,175,117,88,156,240,9,45,50,145,45,33,120,17,58,155,41,71,3,183,46,21,97,108,76,228,90,224,145,
75,154,167,47,102,131,130,24,54,112,37,14,151,242,60,180,23,49,126,64,3,55,207,123,134,236,67,1,216,34,51,157,49,158,202,186,85,20,28,164,118,83,77,210,162,105,96,206,2,102,211,141,57,228,3,160,90,160,
205,34,212,25,9,35,35,207,174,243,66,89,107,60,79,217,97,241,250,74,218,215,14,118,170,135,182,143,198,216,196,5,46,240,200,115,103,68,202,28,136,115,106,172,49,142,162,168,147,164,178,114,35,53,188,231,
233,37,29,96,72,243,29,197,215,170,103,127,146,221,243,161,192,28,241,237,140,12,255,109,57,253,49,82,126,65,158,154,19,190,79,229,168,139,217,80,166,47,167,199,84,85,6,194,216,137,80,248,12,184,36,192,
229,225,181,167,73,57,98,166,231,93,135,77,140,16,60,82,222,186,228,93,187,14,131,111,233,18,10,48,105,149,208,219,13,135,202,162,58,241,213,245,193,175,64,118,158,87,235,79,30,59,113,141,153,71,135,27,
218,224,85,249,75,71,200,120,172,100,112,78,97,188,124,160,61,12,197,235,49,79,112,12,204,24,231,174,167,29,229,150,147,19,225,78,24,218,187,87,176,82,154,114,171,0,88,138,185,53,66,202,145,235,172,80,
51,136,48,22,169,192,137,94,144,79,54,157,238,115,153,99,53,70,155,19,248,112,166,111,176,192,163,20,41,0,22,213,241,214,40,151,103,124,223,196,61,204,241,42,249,240,184,7,15,188,150,82,129,247,235,202,
205,90,234,116,171,106,136,207,47,46,167,77,116,187,101,160,213,168,2,97,197,115,205,34,28,244,8,95,153,179,110,82,153,18,140,123,142,137,210,13,158,249,33,119,120,225,57,47,109,200,190,13,57,84,212,207,
80,70,15,50,249,36,184,190,12,175,206,4,22,161,203,85,155,127,89,152,88,144,15,15,133,253,85,35,235,87,121,209,101,245,212,69,224,81,94,99,192,60,192,101,116,222,64,202,231,181,104,211,14,26,144,83,96,
83,204,37,237,106,187,139,57,125,11,49,185,93,142,190,67,78,51,15,128,217,108,33,97,64,75,231,148,57,6,151,60,23,2,200,156,188,113,201,247,6,83,202,12,121,60,88,165,24,104,237,77,161,107,228,226,151,14,
196,75,7,66,148,151,158,144,224,117,191,56,80,194,24,223,144,130,12,8,145,45,153,172,86,27,172,234,197,53,23,38,140,94,78,219,20,206,87,21,104,139,158,99,26,168,176,231,90,199,152,170,49,212,68,109,34,
171,164,181,57,75,95,136,134,51,76,199,73,186,119,44,127,245,153,31,30,195,21,196,49,95,248,194,103,114,87,20,190,247,118,249,7,247,103,214,97,159,14,177,89,186,186,65,98,72,107,79,56,54,20,70,157,183,
10,233,107,247,114,233,213,183,71,200,211,106,102,33,48,165,38,248,13,223,251,219,175,222,211,148,93,86,231,3,245,247,79,109,18,97,169,107,160,206,121,166,78,90,51,1,123,232,123,251,167,72,13,208,193,
9,196,182,168,207,179,12,1,204,66,10,3,160,25,2,108,98,136,81,29,178,58,143,87,90,183,137,2,13,205,25,140,84,245,61,93,96,70,219,107,143,148,42,70,84,244,80,23,102,134,25,239,51,171,239,121,203,162,205,
59,191,41,116,45,52,102,53,202,75,189,144,115,66,185,106,125,3,225,192,8,64,91,109,168,41,121,100,138,217,197,185,144,116,198,148,49,242,221,240,163,127,112,214,73,95,14,121,19,40,233,57,20,55,194,94,
128,240,76,73,225,45,33,245,153,240,175,195,59,71,123,216,148,215,187,136,113,120,88,75,93,223,159,193,182,65,67,16,58,219,244,202,22,65,94,119,38,105,166,142,220,84,62,8,148,90,199,121,93,240,181,57,
228,247,92,78,234,160,14,91,21,114,87,189,198,132,212,103,85,46,87,227,37,11,106,168,3,50,35,7,192,182,140,40,161,230,96,155,83,86,154,82,121,15,117,246,115,6,252,142,181,24,133,129,199,50,191,59,221,
59,60,103,200,162,200,29,28,2,157,244,53,53,209,71,57,211,177,157,149,45,70,24,77,4,103,0,170,69,244,69,172,72,130,224,21,4,121,207,32,252,158,74,83,42,162,141,57,247,215,20,246,159,59,240,242,56,197,
7,214,121,4,81,94,65,129,44,27,157,177,174,150,219,166,138,127,235,199,127,248,7,139,115,199,63,19,107,127,117,125,112,43,144,111,219,52,11,115,24,38,54,100,198,137,63,197,12,105,106,251,26,59,77,27,248,
167,125,236,150,12,208,100,38,129,33,236,169,9,157,54,240,57,151,8,106,245,148,64,236,155,239,92,246,177,82,137,124,45,104,124,140,121,200,91,141,129,16,232,155,90,150,34,247,225,165,189,207,4,234,88,
149,63,118,133,196,57,60,181,57,93,249,35,242,25,19,48,190,110,68,158,231,28,10,170,156,162,6,155,23,250,94,8,11,43,152,57,57,185,160,72,47,98,58,197,242,39,225,244,37,234,217,37,79,154,63,161,89,100,
3,70,62,86,48,110,62,64,158,215,208,219,98,122,218,134,175,183,121,128,109,28,226,64,148,71,194,231,254,104,37,61,38,40,182,227,29,223,38,98,245,189,6,52,101,133,186,220,82,122,232,143,23,161,152,21,225,
112,65,36,81,39,223,89,16,54,135,110,210,56,228,73,160,156,89,140,157,170,114,207,200,253,213,202,139,198,191,63,18,210,242,224,27,43,36,59,227,224,154,79,21,82,36,3,90,180,109,82,31,217,137,46,23,186,
61,11,188,105,81,142,26,19,195,133,44,80,98,119,36,63,28,144,13,233,245,212,29,49,166,198,45,68,137,38,89,78,154,192,49,16,161,43,194,120,230,70,46,173,138,62,30,43,61,133,194,223,44,172,181,20,17,184,
224,171,167,111,64,174,175,251,28,111,206,45,164,203,198,69,218,133,44,159,182,218,105,115,189,140,87,140,75,44,236,189,3,253,14,241,178,178,168,97,164,147,165,106,150,205,20,144,52,33,133,234,225,169,
43,142,168,29,98,41,81,74,8,181,191,211,6,114,3,240,168,216,57,200,221,190,173,125,231,234,250,64,87,32,91,18,202,84,253,175,165,190,119,98,227,92,170,235,173,202,205,230,65,241,167,186,36,42,114,149,
242,137,118,38,249,73,104,88,44,201,199,62,141,123,58,207,243,29,198,48,163,39,54,50,187,233,153,218,156,16,44,168,95,25,175,241,24,108,255,155,164,227,67,5,161,96,106,87,144,230,50,62,244,169,77,158,
81,78,168,35,134,215,148,83,240,179,103,249,81,45,24,47,70,23,100,11,166,75,67,35,218,74,48,49,54,126,96,243,114,86,106,115,118,161,205,56,203,13,129,65,37,155,106,66,22,164,230,190,178,194,218,238,202,
185,131,224,20,72,213,144,199,10,173,231,253,50,107,101,165,206,128,0,84,121,168,230,45,128,208,79,95,223,74,159,92,184,76,207,85,229,154,91,250,28,145,21,66,110,50,88,65,49,106,48,230,113,94,39,68,189,
132,136,48,81,228,207,35,84,84,161,194,132,253,68,0,194,197,69,161,59,87,121,105,192,111,166,194,195,85,143,105,196,10,45,129,93,99,11,18,154,176,251,108,184,97,244,195,84,227,64,135,209,231,227,96,96,
240,33,207,50,84,126,153,141,192,8,111,125,129,162,39,5,120,42,4,212,176,155,70,140,114,34,82,57,211,129,18,64,20,154,2,196,215,67,87,215,211,6,17,236,217,211,135,67,119,104,188,119,45,46,106,124,55,146,
97,132,233,180,32,74,153,120,142,248,249,235,240,157,133,168,157,132,7,21,218,110,72,5,58,6,0,79,227,253,125,22,135,60,101,214,97,187,73,248,250,182,226,245,84,103,74,93,168,220,199,177,221,235,34,33,
56,60,70,60,247,161,146,202,59,187,56,127,87,215,7,186,2,217,178,19,126,96,138,214,192,166,170,145,228,24,42,1,12,250,170,94,195,70,250,152,92,236,41,92,212,158,188,234,184,79,179,181,113,72,164,89,11,
178,144,71,60,39,151,227,85,191,203,115,118,32,179,83,26,172,115,79,175,166,250,181,98,186,225,4,190,99,131,46,241,164,89,168,108,86,62,89,224,5,138,10,252,209,159,29,74,120,107,12,57,57,213,51,196,183,
230,141,97,56,81,151,219,119,96,156,146,113,236,201,139,250,140,121,172,100,17,80,235,80,94,24,87,14,209,97,12,37,94,82,110,136,169,211,75,60,115,69,127,227,162,123,217,86,131,140,210,64,70,56,118,135,
54,209,29,132,244,5,36,249,133,164,198,136,4,95,83,124,15,20,115,160,212,114,67,77,247,163,248,168,47,40,246,199,44,209,48,250,0,156,174,187,183,207,62,111,38,201,237,65,186,99,130,89,93,123,213,37,174,
235,212,198,173,43,53,12,121,126,196,31,192,24,164,24,75,105,126,163,66,129,192,161,130,88,63,52,138,48,75,231,247,228,222,110,106,188,253,88,174,135,192,97,216,83,135,10,65,94,254,187,44,135,94,146,6,
212,173,75,65,30,123,49,16,146,43,183,76,53,0,92,40,243,28,123,15,66,161,90,203,0,94,192,164,150,159,57,16,171,150,251,91,233,217,120,80,87,52,92,199,189,134,126,17,100,77,212,99,125,207,170,233,53,211,
194,31,157,239,9,165,51,233,14,53,134,85,159,105,79,100,18,152,221,153,16,252,33,92,225,45,198,248,98,228,221,242,235,190,208,182,101,13,180,105,107,46,88,74,15,29,54,125,192,89,64,127,59,81,163,174,161,
49,202,165,143,31,222,7,22,44,255,212,175,253,218,223,65,253,186,186,62,168,21,144,88,121,43,53,190,6,20,181,140,130,214,216,211,85,210,214,63,200,91,148,141,109,159,103,184,235,144,197,17,148,115,36,
41,251,218,254,73,50,35,71,11,24,64,194,230,9,82,74,92,241,71,135,151,43,68,159,32,106,218,96,6,50,20,77,145,198,198,1,120,140,186,81,232,87,179,16,236,17,0,0,32,0,73,68,65,84,74,64,118,24,41,23,12,77,
204,94,132,12,151,245,94,118,188,119,137,158,109,91,185,166,109,131,172,196,166,213,39,153,209,113,178,226,32,168,42,121,188,142,171,59,208,222,21,87,81,185,38,204,180,10,84,41,42,161,12,8,92,151,148,
62,192,41,82,50,202,114,247,141,91,192,81,205,109,108,1,71,40,162,3,157,246,1,76,143,1,64,163,206,124,202,225,251,125,245,196,60,80,218,187,127,156,14,207,156,159,31,141,143,61,3,127,130,79,91,140,162,
189,92,217,128,147,89,212,48,160,198,48,9,245,0,93,50,203,194,202,14,143,82,136,124,80,31,231,28,79,248,216,144,167,134,188,245,169,109,40,168,62,205,85,70,19,81,192,20,211,233,114,214,72,83,38,139,162,
207,210,154,44,65,162,35,183,206,176,238,142,182,187,124,80,231,42,251,12,13,74,236,144,202,35,87,212,148,56,36,22,116,100,229,244,60,247,199,86,47,137,118,157,106,68,15,50,161,195,41,194,239,217,161,
40,188,229,69,219,23,151,222,219,1,227,240,51,225,68,67,53,211,85,158,10,93,166,138,156,146,48,73,154,7,182,45,139,8,98,248,212,165,117,172,82,226,155,202,247,239,243,158,104,13,20,226,149,110,29,76,35,
66,102,77,61,185,23,151,176,4,165,179,21,33,252,122,235,177,78,158,179,159,109,102,70,255,153,183,135,255,94,93,31,196,10,228,155,78,214,125,204,144,51,140,152,141,77,205,211,208,194,190,17,244,99,57,
73,139,80,199,34,253,157,154,104,178,146,89,73,111,64,16,223,193,66,249,196,185,230,93,157,26,139,52,81,163,172,241,222,5,7,65,247,114,218,223,183,105,215,109,64,0,68,140,146,203,9,193,114,193,26,10,228,
181,57,39,207,100,100,58,52,98,52,122,86,232,86,145,135,54,1,34,45,191,230,145,17,230,105,0,29,28,10,41,121,176,160,218,85,80,244,42,208,93,62,99,246,86,225,173,51,157,98,234,49,174,174,156,56,188,93,
78,75,218,196,164,107,226,30,136,11,188,154,238,150,161,176,247,136,17,148,109,208,166,238,140,119,186,102,174,168,233,221,116,239,183,132,168,57,36,133,0,131,238,43,189,220,208,88,61,155,234,197,219,
60,118,232,124,237,203,141,116,251,57,18,155,186,154,251,193,238,81,58,138,156,247,220,132,111,56,148,86,44,204,26,30,103,54,87,229,24,113,124,142,225,68,152,40,191,27,202,187,163,149,99,74,99,115,121,
197,32,34,168,118,221,76,154,18,106,94,12,43,62,242,90,229,222,46,80,236,238,172,246,216,35,191,82,116,8,213,133,248,65,195,155,158,85,152,211,89,170,175,121,79,165,169,211,9,214,84,160,188,94,215,91,
91,5,161,116,156,134,126,27,168,99,134,23,93,94,186,147,110,214,41,238,237,127,11,3,72,174,79,84,109,0,237,206,6,17,94,179,65,12,67,158,19,81,180,208,9,71,140,184,202,192,51,78,214,0,139,198,90,245,150,
28,54,101,81,202,165,62,216,21,164,148,161,3,170,6,16,203,184,255,145,20,229,43,191,241,181,244,235,47,238,72,226,175,174,15,106,5,178,143,80,208,222,80,46,105,103,151,210,139,71,185,244,79,204,200,252,
29,8,231,183,160,146,71,188,196,17,207,114,230,100,126,12,57,61,80,138,120,70,8,247,20,210,250,52,123,174,22,39,127,121,98,47,179,131,220,199,173,12,66,90,68,23,69,69,55,70,126,181,101,35,65,52,109,140,
60,213,129,172,17,233,209,237,143,167,70,255,82,199,165,143,186,127,170,125,44,54,89,72,162,0,128,70,114,164,8,195,106,152,44,224,99,20,183,149,153,58,222,106,200,144,48,156,56,12,98,51,142,245,67,246,
81,15,1,147,179,97,72,165,69,232,35,160,164,216,54,223,12,184,193,222,211,238,217,73,186,215,164,94,223,236,165,219,114,200,23,80,3,23,161,156,107,12,236,57,96,208,77,121,100,211,102,53,213,243,59,87,
60,206,102,80,224,212,29,163,94,218,215,82,119,1,214,44,42,239,68,79,103,120,236,177,252,173,171,100,115,168,92,19,146,46,49,151,76,170,62,155,185,18,42,5,237,201,69,218,23,226,159,168,121,78,168,16,182,
113,92,123,214,175,199,203,142,12,28,202,145,193,207,43,254,175,97,23,149,149,88,42,64,171,58,18,8,98,147,144,189,39,100,238,17,229,206,167,79,208,154,45,9,163,67,193,160,82,92,155,145,12,226,185,50,17,
182,199,47,158,175,200,168,66,245,161,35,245,248,200,71,10,184,205,188,127,40,51,192,4,142,41,81,116,121,112,212,218,116,32,58,122,40,77,152,13,238,245,111,21,97,238,178,131,177,42,26,24,227,221,118,148,
126,218,248,194,15,120,234,245,210,66,186,83,2,108,81,220,191,7,181,111,159,237,164,45,132,230,191,244,243,191,240,11,223,89,168,171,191,188,239,43,144,45,102,20,199,243,26,138,112,92,195,102,6,217,117,
12,25,19,142,87,23,81,195,130,172,62,159,214,182,3,150,224,37,160,173,82,17,228,111,136,163,13,85,142,147,222,137,31,196,183,104,227,186,115,243,250,108,120,78,206,201,235,120,22,66,1,128,2,136,33,148,
140,132,51,11,149,7,194,171,46,47,151,193,111,29,205,241,52,74,50,199,188,211,37,130,55,130,156,205,207,3,250,230,158,166,223,156,254,209,146,82,192,33,222,170,166,54,244,188,224,147,186,216,78,78,158,
88,82,104,31,121,159,46,181,176,11,72,231,185,208,249,92,56,219,33,42,182,160,174,247,172,78,149,23,84,80,182,117,171,220,206,183,129,34,30,144,39,50,134,68,153,33,155,250,45,228,4,63,31,161,249,165,144,
50,84,238,226,138,1,68,61,128,88,110,40,4,54,55,102,170,180,147,241,222,57,70,63,167,129,59,43,236,28,8,115,39,60,144,63,176,116,30,153,6,126,108,252,196,117,40,168,230,245,166,254,83,161,125,22,211,102,
232,192,91,212,71,26,207,124,12,236,25,34,38,204,139,6,242,146,238,69,32,92,173,174,20,4,185,45,10,57,143,172,193,206,145,5,38,54,189,232,212,235,180,28,106,194,221,178,174,158,227,222,225,12,185,14,207,
25,50,49,79,226,90,158,49,190,224,42,200,221,159,33,9,19,157,50,199,102,193,68,55,202,28,145,175,33,195,94,144,78,108,57,68,42,154,196,203,188,127,93,88,173,104,226,224,11,33,180,5,72,52,112,45,16,114,
135,195,87,160,230,15,193,191,53,159,75,199,161,90,22,74,223,126,97,35,125,116,254,132,209,191,245,163,79,222,237,234,247,15,98,5,242,207,64,76,155,66,178,23,109,92,152,140,176,83,190,99,243,125,20,168,
176,191,105,124,57,35,154,162,217,61,119,125,145,82,220,252,76,58,113,132,52,16,237,74,65,8,8,33,173,240,54,241,247,220,244,48,61,120,179,159,22,63,239,103,120,186,26,237,216,210,26,3,87,203,235,61,80,
34,64,169,171,134,40,85,120,65,117,198,194,5,100,83,254,154,49,89,75,198,229,85,34,92,179,169,148,38,234,60,235,117,121,111,78,231,71,79,92,61,25,151,102,68,123,46,195,230,84,46,225,5,231,203,175,167,
234,109,36,244,251,238,1,69,173,140,54,87,210,55,89,213,200,188,41,228,61,17,170,23,148,23,64,80,233,155,70,188,143,213,10,99,102,232,226,179,207,166,167,1,49,167,196,182,180,174,208,231,197,173,5,144,
68,164,200,49,165,199,234,181,19,198,187,168,244,81,22,35,119,253,157,245,196,67,10,13,163,133,78,219,149,31,173,92,71,48,183,201,99,172,195,240,146,72,179,247,168,46,57,13,130,216,160,175,181,32,10,121,
235,108,47,85,145,36,238,82,114,152,115,168,141,132,195,39,56,204,89,158,175,163,174,28,250,69,93,135,4,46,8,47,135,34,168,195,164,224,207,37,90,77,157,24,28,229,128,81,195,241,216,62,11,249,105,216,98,
228,195,19,235,16,52,253,184,98,162,223,37,164,61,82,148,222,2,197,65,205,226,215,16,16,182,128,106,19,192,210,129,53,30,9,81,217,100,170,96,13,21,28,108,149,114,51,45,186,175,93,30,117,4,91,152,56,48,
188,217,76,90,38,4,179,163,93,174,23,232,54,109,224,233,105,53,125,227,119,94,213,136,244,241,8,28,174,174,15,104,5,178,145,23,174,65,108,151,90,249,180,74,89,131,60,144,208,79,39,135,250,86,217,105,252,
251,123,199,233,183,31,26,56,164,67,127,237,102,54,109,218,137,117,106,236,231,250,52,47,30,27,62,36,103,139,45,157,5,170,4,233,125,229,230,178,29,96,19,66,121,71,154,128,115,240,189,193,59,54,81,156,
230,54,102,81,91,87,182,138,253,35,134,91,132,62,134,218,64,69,43,25,61,117,232,33,35,112,186,7,74,181,164,118,210,231,101,46,185,166,170,240,110,217,148,109,157,209,79,28,198,108,113,132,147,194,177,
30,112,102,162,51,165,54,89,55,177,140,114,160,156,183,130,53,211,195,235,125,172,84,113,48,191,158,222,241,108,247,133,182,219,57,207,57,90,166,9,75,132,76,231,72,139,161,102,133,182,215,150,158,16,201,
227,101,163,167,243,134,248,53,31,10,122,66,69,1,255,172,223,113,75,109,178,36,36,110,216,228,1,186,228,33,192,18,108,155,158,55,167,46,160,72,235,251,11,144,230,238,204,155,170,108,68,189,67,216,175,
71,147,80,218,8,242,221,83,178,168,243,242,117,134,62,14,53,118,0,85,140,230,155,96,7,53,124,111,21,33,190,40,180,172,56,140,178,12,231,82,71,79,91,28,219,227,85,7,192,49,208,214,236,254,38,128,166,224,
214,206,152,66,14,32,39,161,28,145,98,59,77,167,155,106,179,91,64,184,3,121,253,169,122,230,42,15,188,198,144,235,128,189,55,49,135,114,214,115,35,216,88,122,101,71,12,176,219,109,56,30,132,206,149,37,
76,164,176,73,98,97,190,39,70,80,28,9,207,79,207,119,211,209,171,187,233,173,215,30,106,130,95,121,250,222,75,175,253,39,179,229,191,250,237,125,95,129,108,145,232,85,153,81,156,93,178,76,225,232,154,
62,206,13,121,206,246,26,118,15,201,138,55,108,140,24,21,118,193,123,156,119,245,49,58,145,199,10,234,141,67,249,31,227,173,2,11,194,219,4,76,145,115,250,46,40,188,103,49,106,138,242,197,185,80,26,80,
26,233,171,187,233,225,101,148,208,194,158,194,247,17,143,43,156,28,218,236,5,97,241,156,206,151,152,143,29,186,236,49,70,112,26,147,154,71,171,236,153,10,129,193,176,21,5,250,142,112,44,232,129,239,93,
28,157,215,211,115,202,176,167,230,124,28,155,85,217,56,123,60,155,142,29,58,70,77,94,103,98,163,229,109,192,44,82,194,45,19,206,54,120,213,190,246,184,93,162,215,130,95,237,112,222,75,199,137,71,152,
17,233,227,152,153,185,79,160,142,73,158,0,38,154,174,190,120,168,180,148,5,212,92,242,156,101,196,140,188,250,235,72,190,86,227,65,71,194,239,70,199,90,201,199,47,134,59,148,248,180,142,233,234,153,174,
44,167,62,46,237,226,181,109,37,22,202,242,90,180,238,129,110,15,32,215,11,202,80,27,11,12,144,192,118,23,167,216,64,234,217,124,206,24,23,56,240,122,101,96,206,168,191,150,246,194,187,50,148,192,151,
86,172,109,54,110,148,235,140,17,131,239,205,100,9,37,248,18,207,215,80,94,121,243,254,158,251,193,66,130,248,206,23,72,111,122,191,199,140,186,232,190,135,34,137,150,31,207,194,19,34,10,120,75,62,125,
136,164,191,188,172,95,22,8,87,31,46,160,245,57,44,98,86,141,245,31,50,232,93,152,67,91,247,204,232,33,238,48,10,229,70,247,65,233,98,231,240,250,123,159,193,213,159,239,239,10,80,223,80,46,128,50,126,
100,221,56,185,237,96,215,132,42,28,201,10,57,94,38,228,61,196,66,43,128,152,22,175,248,6,62,237,1,16,102,40,132,42,44,153,30,182,100,172,95,36,147,54,178,207,127,134,28,238,61,20,68,202,87,70,221,200,
57,145,175,169,14,20,181,119,133,1,79,149,72,242,12,54,169,149,246,79,1,13,122,176,138,128,163,241,82,196,136,148,2,0,45,101,133,242,177,208,172,69,147,103,194,162,71,14,132,246,97,63,125,107,63,154,168,
149,105,188,81,152,104,56,236,0,97,114,242,193,50,227,24,25,194,148,189,112,32,132,198,171,210,140,192,111,70,5,172,19,94,94,1,126,132,132,103,149,23,191,165,219,226,14,112,229,147,26,203,111,48,186,130,
195,231,60,164,58,185,204,200,157,99,40,110,214,97,197,49,17,226,170,152,66,22,227,250,226,208,32,21,25,145,173,220,51,14,137,75,94,189,232,239,75,194,240,172,98,224,5,233,150,140,214,177,49,239,116,122,
73,225,1,8,116,195,65,181,65,71,168,32,108,238,203,87,251,72,6,199,234,143,77,4,133,158,28,95,214,77,214,5,113,1,141,80,149,84,148,202,0,121,194,177,6,247,133,114,32,203,68,189,33,94,43,16,233,30,36,53,
39,228,21,167,206,122,100,179,60,117,128,66,49,84,56,188,221,37,128,238,183,148,185,94,116,79,251,218,215,122,0,169,208,177,125,83,250,161,113,197,96,100,100,6,148,202,156,124,118,44,108,63,224,185,207,
228,150,25,198,191,79,43,232,220,61,87,33,218,31,151,144,199,243,158,27,16,252,182,41,102,99,233,195,198,211,27,233,5,158,52,119,246,14,66,197,3,26,220,250,208,174,174,247,125,5,178,253,51,6,164,54,248,
194,173,90,250,20,33,98,138,23,196,165,6,233,213,71,251,120,180,45,146,91,122,20,1,11,25,45,85,53,222,112,192,211,245,156,226,109,249,205,176,182,1,146,103,33,1,33,186,166,54,206,4,34,56,48,116,21,126,
111,179,69,23,138,25,43,7,202,32,90,53,10,5,161,218,220,57,143,132,18,198,16,115,54,179,40,86,120,5,93,100,240,49,24,55,99,46,73,212,83,83,243,40,229,41,2,20,145,185,99,124,110,69,222,59,144,87,206,222,
199,111,21,27,169,198,155,79,229,133,121,27,190,180,194,3,95,119,80,208,209,209,173,40,23,212,118,133,238,86,228,41,75,16,217,139,139,67,245,192,14,110,171,131,2,183,245,29,130,88,111,170,171,62,138,127,
151,203,5,103,134,109,206,202,41,21,92,223,71,248,173,61,161,252,29,95,254,164,238,149,216,141,35,134,115,96,226,119,30,112,83,137,188,82,106,86,180,79,231,213,107,231,204,9,77,197,235,106,179,45,29,46,
23,166,214,51,188,93,30,139,119,90,179,225,139,74,30,121,66,101,225,201,119,194,32,123,181,116,253,154,214,54,121,96,27,242,171,73,52,221,252,216,199,102,165,148,199,144,185,1,48,110,94,95,102,210,6,119,
48,60,73,251,194,252,133,237,77,29,54,49,28,41,238,198,33,229,189,163,131,166,175,116,50,58,161,154,160,36,178,3,241,62,118,152,94,0,123,138,0,167,239,167,56,95,87,51,14,249,146,240,248,15,173,230,75,
199,62,75,63,215,148,102,188,129,169,245,136,250,187,31,153,105,26,197,0,227,99,180,204,71,114,209,222,202,58,35,246,25,122,62,78,52,53,154,187,105,107,115,225,103,47,71,173,207,199,231,112,117,189,191,
43,144,253,230,131,94,250,250,96,61,125,219,135,187,107,91,55,183,180,53,241,6,251,36,250,231,1,64,5,5,245,83,155,50,106,137,25,122,66,173,232,188,87,248,175,101,149,83,108,210,158,252,199,46,121,114,
151,60,212,84,203,85,193,4,231,172,48,52,43,127,138,58,32,92,149,97,250,187,144,110,170,207,42,35,132,206,18,2,138,62,237,11,243,38,167,194,185,18,131,152,160,184,197,216,246,206,25,175,228,160,200,133,
16,87,183,150,118,67,215,150,87,201,11,221,226,154,121,206,8,151,3,40,210,216,221,229,153,234,75,177,145,81,240,142,53,44,3,169,202,64,166,142,129,188,13,238,85,241,28,37,177,130,61,211,79,175,138,83,
15,60,219,219,216,73,49,171,36,20,234,31,168,69,196,132,239,137,26,95,176,111,86,215,215,149,53,4,218,25,77,226,243,132,170,121,227,55,25,215,145,67,233,134,80,119,42,138,8,53,134,82,129,183,4,168,93,
140,23,9,101,217,192,134,228,182,20,254,165,188,140,18,179,74,190,126,198,192,162,240,31,250,75,165,237,27,116,113,235,179,116,96,228,208,186,68,110,47,50,180,188,67,111,170,87,116,177,140,174,56,60,162,
236,167,109,78,43,220,9,193,178,138,95,43,57,81,132,134,130,213,225,49,47,173,28,19,244,71,235,48,13,86,83,40,56,4,135,89,78,153,193,50,218,150,243,126,18,97,253,99,243,155,51,82,255,105,166,157,14,116,
235,236,59,44,239,250,217,105,115,146,94,33,47,115,113,4,28,83,234,233,59,16,111,25,162,91,20,234,238,133,56,19,78,238,192,231,139,106,146,86,128,101,77,165,175,193,222,158,89,49,234,163,157,227,180,85,
62,204,183,176,172,174,174,247,127,5,242,184,230,105,125,235,70,58,105,156,217,100,20,203,71,192,20,57,215,37,5,186,137,112,103,42,135,2,184,107,130,134,228,1,117,66,176,120,157,206,208,26,150,206,217,
195,39,35,26,194,229,68,88,59,43,66,210,185,157,52,32,171,234,163,23,3,133,116,8,83,150,198,206,212,68,236,196,240,234,4,182,178,106,129,19,212,190,69,197,253,172,58,29,132,68,49,158,94,17,89,142,206,
30,210,118,83,77,142,161,223,224,255,130,4,176,118,71,206,249,90,24,157,205,248,238,154,176,205,116,137,32,113,185,7,47,117,236,247,40,199,77,122,122,77,3,232,32,152,92,200,172,65,132,13,166,69,214,47,
240,140,117,45,85,161,75,93,197,120,153,142,22,211,45,57,212,72,78,221,177,161,29,21,242,186,232,19,229,221,196,179,69,10,124,2,8,181,191,208,240,137,16,186,137,215,11,157,70,203,107,248,122,19,168,21,
81,2,90,237,44,39,164,27,224,47,109,82,147,171,233,129,144,119,128,68,177,33,223,60,59,59,86,131,149,221,106,36,232,86,233,231,106,100,31,117,144,224,141,8,28,18,134,238,41,21,85,29,124,19,107,51,232,
159,167,7,95,251,109,115,73,207,210,242,77,185,234,234,82,186,46,39,173,213,87,168,81,172,226,31,35,38,12,30,198,74,207,254,55,157,29,136,30,200,21,146,158,141,147,134,213,106,166,173,124,61,45,49,190,
62,148,125,63,84,228,33,215,151,113,112,248,169,30,137,150,2,84,190,167,150,233,47,242,84,130,214,122,94,67,137,111,80,146,54,104,74,47,227,33,87,9,159,61,58,127,130,82,111,175,10,225,133,207,49,216,169,
121,76,57,225,128,238,82,241,119,159,22,218,126,85,138,241,222,199,49,187,143,171,223,254,249,174,64,246,238,53,232,36,234,220,39,20,217,231,132,157,101,200,226,167,17,172,111,13,105,4,160,178,109,60,
123,125,54,10,190,65,122,99,93,12,118,199,220,199,10,166,122,73,104,186,100,138,88,158,71,140,13,51,84,63,28,3,69,2,164,41,108,2,52,120,167,57,133,235,74,213,168,121,19,177,199,243,180,93,233,241,4,233,
123,2,53,69,157,183,73,121,71,30,168,96,80,208,108,0,144,60,87,118,71,32,122,148,30,99,196,92,224,171,46,222,184,70,217,78,209,30,181,48,243,29,218,218,19,239,57,18,182,13,25,94,127,87,91,242,49,207,164,
54,89,211,244,28,35,9,14,207,32,201,114,193,28,197,60,115,10,211,14,224,168,6,41,93,116,127,13,97,228,52,88,58,36,72,38,66,235,167,35,31,101,248,236,205,179,224,180,170,95,190,166,92,19,69,251,121,154,
62,219,60,167,192,30,67,8,31,213,247,4,149,47,188,214,153,176,125,18,242,31,134,246,150,174,95,75,219,119,183,83,69,94,112,115,123,37,93,251,244,51,105,233,230,170,90,166,28,156,165,87,116,214,84,247,
14,105,30,17,190,150,115,174,76,98,240,175,102,116,57,251,136,113,118,25,77,244,188,222,224,245,160,110,51,194,69,13,194,123,174,233,187,107,8,83,113,75,189,115,99,201,93,68,102,28,239,47,206,140,149,
87,246,138,95,83,121,115,135,162,197,3,30,121,199,140,149,251,114,213,51,7,219,185,195,103,138,76,80,132,160,77,225,11,121,57,233,134,3,236,204,107,199,12,83,177,191,200,2,67,72,142,191,141,8,242,180,
136,103,67,159,236,110,228,208,108,47,102,174,238,233,67,93,22,26,111,35,78,148,242,143,82,189,50,248,239,222,22,196,255,243,221,138,87,175,246,71,87,32,223,67,201,11,2,65,132,74,3,187,243,152,32,116,
77,71,199,10,146,193,45,0,238,139,4,166,186,1,22,200,101,186,161,208,165,22,54,8,133,245,104,144,14,221,30,94,199,4,94,117,62,94,199,134,88,208,246,145,17,170,101,40,32,84,81,214,242,65,46,149,255,133,
190,230,212,107,142,35,20,108,203,251,0,70,23,222,47,203,168,231,7,102,178,80,45,191,4,222,180,136,112,21,25,202,146,16,120,160,102,56,54,22,226,224,85,64,210,158,110,19,33,152,189,249,228,114,102,151,
161,151,149,77,141,219,60,53,46,189,154,42,207,15,133,236,8,9,139,106,171,107,228,33,251,140,119,223,251,13,113,118,215,237,251,24,239,62,20,190,246,1,73,125,170,14,27,130,238,160,9,158,199,235,190,251,
218,139,14,134,187,188,209,182,231,218,80,147,149,45,167,183,251,74,42,60,123,94,125,244,26,131,156,115,96,48,73,154,190,29,35,228,197,22,54,245,41,54,81,87,131,236,52,66,85,161,253,214,115,119,83,230,
126,35,157,56,56,150,17,240,75,242,185,17,32,168,104,173,75,70,94,132,247,239,65,124,167,14,171,162,220,57,228,74,106,25,223,239,49,155,162,148,135,64,157,99,135,229,162,60,191,168,179,103,135,222,237,
72,120,159,97,208,49,192,41,140,51,126,249,248,120,216,232,162,209,184,128,84,34,98,85,163,52,2,2,199,118,232,160,233,122,173,146,28,255,6,132,121,40,252,93,177,238,45,181,204,18,18,73,9,18,126,40,228,
126,1,167,118,78,168,223,162,186,176,160,180,51,29,31,166,79,67,233,55,0,71,45,235,149,243,189,117,237,103,217,241,59,16,233,183,134,119,51,63,38,92,184,186,222,207,21,200,206,205,219,52,62,152,137,220,
48,16,203,28,250,92,214,8,190,33,248,63,23,221,36,70,143,215,116,232,95,195,178,41,83,228,107,229,59,70,182,155,131,169,142,233,92,181,159,109,70,187,35,74,34,89,228,218,49,232,222,158,118,225,251,52,
141,88,7,102,196,46,204,229,41,231,200,101,139,128,136,220,133,147,30,17,188,194,91,84,77,114,30,206,221,80,128,135,168,46,119,129,58,138,245,80,226,167,17,10,252,39,178,12,114,129,205,194,241,241,16,
177,25,159,108,201,130,205,86,53,232,39,123,166,78,72,25,253,20,79,183,205,43,117,129,73,29,207,80,14,40,23,138,219,3,120,109,66,52,131,84,81,197,172,169,217,172,11,88,47,61,30,243,162,175,38,41,174,111,
120,238,17,84,121,34,239,140,194,208,134,64,254,147,234,143,119,48,110,6,212,216,219,16,227,146,25,43,243,83,45,26,0,148,233,20,193,94,158,28,196,255,9,45,34,141,105,234,27,227,116,122,124,154,250,180,
129,14,145,17,46,219,20,35,228,157,100,249,210,65,238,48,117,151,13,32,146,91,102,51,219,179,246,175,145,48,185,86,51,74,209,244,180,166,161,77,13,156,157,114,30,171,200,33,86,84,75,93,112,159,235,194,
234,5,9,108,21,50,222,237,237,167,71,152,71,193,94,250,131,235,201,122,196,151,58,116,138,158,214,254,246,169,107,148,32,58,186,135,68,37,235,166,199,213,29,182,135,238,173,170,30,51,1,113,15,28,12,101,
198,182,30,157,45,154,196,231,180,185,213,57,208,87,168,34,238,250,52,51,58,92,214,133,220,33,107,189,110,13,94,88,93,78,19,210,44,237,210,25,209,48,101,52,50,159,163,65,161,244,214,254,227,31,250,131,
251,184,250,219,251,177,2,249,51,121,200,161,77,148,233,46,167,61,98,89,243,202,32,183,181,100,117,228,44,71,114,184,16,164,122,118,25,47,150,161,69,167,69,61,138,223,192,139,9,195,13,30,108,52,3,135,
199,137,73,91,211,189,199,169,125,160,123,228,124,67,30,165,44,160,89,56,120,123,65,249,43,9,159,7,192,160,169,77,23,17,209,68,149,190,200,251,102,177,100,198,226,188,33,21,248,33,130,67,133,198,206,0,
81,253,41,132,235,67,186,67,19,53,187,202,50,47,245,246,138,60,137,152,86,24,169,87,24,250,203,137,246,182,162,209,13,37,30,189,165,143,209,254,5,252,224,207,42,129,76,24,231,90,73,158,167,124,147,137,
210,16,245,242,62,20,122,200,51,20,120,182,55,109,198,21,94,227,212,70,173,211,202,217,227,149,6,218,204,138,245,133,116,182,58,151,254,166,30,200,31,217,239,167,143,211,234,93,142,67,11,45,238,80,124,
122,192,112,63,142,193,211,36,106,125,137,68,81,153,143,92,82,228,128,235,123,99,209,251,34,14,76,40,26,236,255,238,183,200,155,120,94,19,164,55,87,148,100,168,33,140,90,188,34,75,106,11,23,43,140,99,
139,118,237,72,15,243,74,127,37,29,107,209,11,54,79,155,126,208,49,84,247,58,67,216,32,133,210,118,104,229,133,148,19,121,224,188,178,86,116,144,132,124,233,20,193,32,136,8,79,86,67,96,226,30,175,9,167,
191,103,189,148,190,108,188,194,106,137,218,215,20,32,86,94,213,224,110,209,120,211,93,37,166,101,135,212,146,207,164,2,55,104,225,245,82,96,242,25,202,103,245,130,6,19,105,164,5,174,192,171,111,1,231,
94,212,192,189,97,79,100,68,38,215,55,221,167,176,246,197,95,223,73,187,223,250,234,252,211,63,117,247,63,246,230,191,229,215,213,245,62,173,64,182,184,135,34,102,35,182,229,85,246,153,15,149,37,233,32,
161,175,151,218,235,219,234,155,85,170,237,131,244,22,163,218,99,4,107,54,235,34,132,179,113,8,81,164,250,54,5,164,204,174,39,199,183,220,7,50,233,68,230,10,227,56,159,229,66,241,239,163,104,67,107,134,
54,16,239,38,39,202,128,232,47,71,212,209,1,132,121,57,213,80,253,116,76,101,126,64,153,161,164,220,48,166,94,48,149,7,79,207,109,159,35,189,38,242,224,32,156,15,229,105,241,142,209,81,49,182,145,78,53,
73,79,38,238,150,106,253,84,93,15,1,208,1,179,12,229,180,161,169,171,199,216,135,50,36,183,178,166,129,187,178,41,199,133,220,170,35,222,224,141,122,139,129,196,82,117,144,75,103,160,170,93,57,91,228,
115,235,26,159,171,54,254,190,218,96,175,205,75,106,237,234,42,234,231,229,225,245,229,133,180,186,5,141,86,255,67,249,21,150,27,21,49,53,23,133,145,151,25,197,4,25,126,162,180,209,62,227,113,1,72,103,
77,209,128,67,101,192,27,158,10,145,151,95,248,100,186,182,122,29,17,129,200,88,239,152,7,51,42,97,113,131,87,38,70,22,60,16,70,54,70,213,107,99,19,201,19,132,206,0,53,94,62,175,132,50,242,252,225,43,
163,132,18,70,25,121,231,12,177,101,124,161,219,132,98,228,16,161,152,16,158,215,119,158,43,53,101,172,195,134,134,131,188,84,161,76,207,182,227,64,59,192,156,138,245,23,225,82,179,215,34,200,224,23,33,
222,119,131,168,32,204,62,67,60,248,190,205,101,17,75,74,191,119,156,75,111,40,251,92,156,195,32,58,35,19,197,129,98,143,143,82,173,251,208,13,94,93,239,231,10,100,171,232,41,183,124,104,139,139,242,69,
225,222,106,116,252,207,11,106,12,14,218,127,252,166,222,74,44,18,158,165,168,52,17,234,226,15,85,242,219,245,85,173,99,231,233,33,96,33,207,40,227,127,17,108,102,87,54,212,249,252,45,132,187,158,18,58,
2,27,70,200,219,42,34,179,208,118,164,143,114,128,136,157,55,169,107,20,117,188,165,182,3,193,116,107,77,194,180,80,52,120,215,209,213,120,31,202,125,7,202,6,237,230,185,58,168,129,58,138,231,23,239,236,
243,206,125,155,148,247,244,114,81,84,153,23,194,46,120,189,115,10,121,45,224,81,79,110,57,216,136,62,206,40,5,29,165,197,63,254,125,233,147,127,225,71,108,126,76,156,7,143,210,228,240,68,8,60,73,39,128,
174,33,233,207,71,148,209,241,35,140,192,19,54,18,237,138,161,64,25,6,49,202,109,164,79,123,237,207,108,240,186,242,182,150,240,55,199,211,174,242,232,53,19,211,58,12,46,167,217,187,154,109,232,115,188,
160,205,131,219,4,129,29,180,201,108,26,178,91,50,60,56,139,37,116,242,6,165,248,61,207,140,117,211,201,193,121,35,127,165,220,80,63,63,50,27,148,217,17,170,174,240,242,157,168,101,234,14,137,46,19,217,
178,1,72,16,100,57,252,145,241,9,213,121,195,112,213,44,187,20,9,42,53,20,69,145,70,128,86,179,37,103,84,239,25,234,216,225,208,22,102,191,188,23,218,68,218,244,188,206,88,190,95,128,14,175,118,30,227,
76,227,67,35,93,68,247,116,205,56,136,75,135,192,16,98,27,175,55,129,59,20,165,46,83,225,107,52,42,76,69,69,115,74,102,153,222,57,225,177,208,38,106,165,111,154,232,54,68,132,254,248,211,43,233,153,244,
40,149,14,78,63,119,49,152,126,143,143,225,234,122,159,86,32,123,168,198,119,164,35,227,204,226,151,144,183,119,32,124,223,56,68,89,179,209,11,138,207,211,149,165,116,31,147,164,189,199,211,245,48,227,
121,212,85,154,66,121,8,103,73,195,110,62,32,206,119,175,140,169,97,92,151,166,98,77,192,188,218,185,144,108,10,4,201,232,13,101,25,106,156,188,152,227,184,4,28,25,65,86,67,32,175,224,53,178,55,214,83,
127,233,46,185,200,21,136,46,142,174,176,115,81,217,33,194,197,75,252,206,210,170,81,8,188,119,120,203,0,159,226,10,31,146,21,18,86,182,106,202,17,176,84,114,151,67,37,130,14,82,196,137,1,181,231,140,
124,254,246,15,240,120,65,91,11,18,185,126,81,10,0,15,120,202,111,210,206,105,200,47,111,18,193,202,117,233,228,50,138,97,120,254,120,77,239,25,67,128,54,228,91,207,105,247,154,24,163,208,160,165,99,34,
132,112,47,186,61,160,211,208,205,80,46,136,137,219,33,13,50,129,102,30,159,63,76,83,128,84,73,9,138,171,228,196,0,100,194,254,181,245,249,84,19,162,79,70,49,172,87,25,163,241,205,244,170,156,112,36,143,
206,104,2,175,106,5,9,63,56,137,215,118,56,142,125,30,231,114,203,202,112,9,153,65,110,40,0,137,38,245,174,146,203,34,9,149,107,188,167,27,176,22,193,175,141,159,180,22,194,228,60,22,209,55,31,181,48,
169,206,210,18,47,171,19,21,187,71,222,207,192,99,142,75,209,247,79,49,9,110,0,202,63,226,68,42,59,132,78,201,166,180,221,127,21,91,42,102,174,180,176,155,86,132,213,253,85,192,153,48,120,2,124,90,118,
143,215,24,237,67,45,124,209,162,183,130,176,178,185,134,93,156,61,186,253,173,175,255,202,141,217,13,92,253,246,190,172,64,126,110,238,182,15,214,201,12,140,104,169,113,238,180,87,213,10,109,14,181,187,
92,12,253,57,27,167,183,184,195,60,164,47,131,87,59,218,121,36,220,2,58,168,77,230,130,172,249,221,87,212,33,109,146,108,27,202,42,204,10,85,129,232,244,31,169,153,101,116,164,0,30,103,160,208,84,3,112,
145,220,100,251,200,191,49,148,28,239,183,119,116,150,174,83,124,175,47,35,178,145,152,12,45,158,115,6,222,7,48,53,21,27,251,140,43,212,196,6,0,147,184,164,139,110,3,210,10,8,42,200,155,179,202,59,65,
143,235,107,4,207,30,163,212,21,46,210,239,253,173,255,26,232,51,74,47,60,187,14,254,215,72,172,236,19,45,80,47,0,95,10,203,81,38,41,165,134,90,233,107,135,36,61,215,61,147,251,143,171,67,249,224,84,126,
218,82,111,85,125,97,28,254,93,68,17,192,89,81,29,241,92,184,126,161,163,37,104,124,47,172,50,131,72,173,253,232,80,161,158,3,78,71,194,216,204,233,113,234,46,160,19,10,13,143,119,14,49,136,16,16,214,
174,253,191,236,221,9,148,164,233,85,30,232,47,246,140,204,140,220,247,165,214,174,170,174,94,37,117,183,26,9,132,22,4,72,6,204,38,225,21,99,3,99,142,151,177,241,57,54,158,25,207,216,30,207,156,57,199,
204,177,61,30,31,99,64,102,177,49,6,203,198,108,66,32,44,9,161,189,165,222,247,174,174,189,114,223,247,136,200,140,101,158,27,89,45,100,176,49,199,18,54,115,168,191,59,151,202,140,140,248,227,255,191,
251,221,123,223,251,222,247,118,90,218,178,131,154,158,163,183,82,253,180,31,177,33,143,156,159,205,46,168,53,250,94,169,169,216,192,48,10,189,92,19,209,106,134,254,22,213,79,43,162,22,82,73,145,58,58,
194,64,35,247,116,77,34,231,119,100,25,234,173,27,87,211,217,187,39,132,251,97,191,90,238,116,159,20,181,189,101,76,22,239,8,85,67,146,187,66,203,136,228,233,93,186,131,58,196,122,93,63,39,69,45,13,225,
108,157,144,117,202,68,142,90,79,39,207,101,211,163,8,19,59,0,183,115,192,164,146,1,198,181,216,52,220,187,145,139,69,81,213,53,27,239,27,191,102,169,221,254,208,68,198,139,221,57,190,236,87,32,91,197,
2,89,198,12,233,18,58,229,218,243,102,140,116,19,155,26,164,176,87,48,136,22,168,99,164,194,126,228,127,129,178,14,117,167,91,138,237,171,58,73,134,162,54,88,98,132,140,209,214,29,78,199,7,207,99,129,
53,251,21,237,133,120,89,83,179,99,0,108,157,23,110,67,133,203,39,167,25,190,108,40,30,7,21,108,240,12,85,160,80,160,154,163,202,228,195,205,69,40,43,96,8,97,32,38,115,237,98,181,20,163,163,131,28,73,
54,228,199,111,131,247,225,227,162,236,83,87,87,61,162,148,30,194,90,71,30,179,102,51,217,86,34,24,27,233,143,65,102,70,247,225,210,154,54,189,113,51,132,184,138,105,102,100,54,149,55,141,68,112,174,177,
97,212,171,61,58,56,138,38,80,155,228,197,203,132,86,110,120,165,88,216,203,60,247,230,228,93,168,107,21,249,41,15,205,155,23,8,130,21,17,12,6,39,133,158,244,114,7,130,140,47,236,175,34,82,180,132,177,
57,170,11,3,120,171,69,231,159,97,73,99,146,248,6,100,119,119,83,206,201,48,86,77,58,203,1,105,78,202,237,179,68,187,26,203,54,31,155,81,101,98,92,254,169,204,18,208,204,152,122,226,212,16,101,138,253,
180,232,186,172,200,254,175,33,205,47,41,115,140,235,162,25,13,54,81,231,98,199,90,136,43,113,252,209,1,137,116,195,54,144,215,219,82,143,21,204,170,188,162,236,38,202,227,194,230,85,42,138,54,47,185,
102,14,241,189,163,79,164,255,117,89,142,169,98,101,210,152,159,15,170,69,151,10,144,121,155,134,13,177,79,36,98,43,76,159,0,240,229,160,214,21,161,114,77,11,92,151,223,85,23,82,186,241,177,79,166,83,
103,142,254,34,253,250,8,167,238,28,191,15,87,32,127,125,110,53,109,110,111,164,187,39,39,160,138,224,253,126,210,253,22,123,149,23,109,152,61,89,156,30,74,151,232,237,84,213,44,143,212,188,230,0,71,119,
49,152,193,104,188,54,80,55,148,226,58,235,195,201,21,183,111,166,51,247,157,169,110,239,157,0,0,32,0,73,68,65,84,178,16,213,237,138,8,96,35,192,145,194,128,80,53,184,167,114,80,136,111,99,225,102,202,
140,138,155,16,20,74,152,72,49,117,108,111,137,113,242,178,37,35,214,119,133,104,89,242,144,61,60,210,0,131,179,98,212,36,209,241,8,60,223,142,104,59,75,147,93,144,55,9,239,204,240,132,110,89,40,233,132,
166,101,223,165,201,55,205,166,235,116,97,143,0,24,83,149,17,97,237,28,193,48,200,167,208,176,174,68,179,142,188,48,79,18,101,24,245,173,60,27,101,34,231,192,229,121,74,148,61,52,185,193,89,44,40,181,
204,233,97,139,81,104,187,10,216,2,180,196,208,92,28,245,52,125,82,248,201,216,118,200,160,236,11,141,179,0,168,146,225,79,218,105,210,50,118,82,81,254,59,62,52,43,68,236,161,64,96,48,110,180,149,168,
182,60,131,192,31,3,133,199,139,194,90,97,231,182,54,173,249,235,203,105,97,251,114,90,43,13,164,251,209,232,6,201,147,134,68,229,142,54,180,145,200,239,205,156,89,235,89,37,185,57,158,38,218,99,41,58,
231,94,59,94,11,107,227,223,138,85,114,88,67,159,68,13,243,194,138,62,37,176,137,9,157,41,106,80,135,68,199,242,138,185,51,195,144,105,249,99,32,192,67,218,221,186,145,247,179,202,76,189,195,71,29,177,
237,140,8,97,154,113,86,169,34,228,219,131,0,56,93,49,162,170,101,225,112,89,78,93,163,208,96,116,147,208,62,165,115,231,117,187,236,62,217,124,241,177,23,238,0,67,175,221,144,47,243,87,74,8,138,248,149,
73,128,136,112,10,2,89,12,128,194,232,188,235,123,36,52,122,78,164,251,207,157,33,199,143,211,9,218,43,105,222,109,162,190,109,10,149,214,117,178,84,169,185,125,97,28,3,239,121,136,220,190,124,105,69,
253,79,39,134,162,120,181,161,150,168,212,33,25,84,252,86,231,232,91,18,74,138,185,170,66,45,11,100,31,57,188,129,62,214,182,219,71,249,36,131,100,80,214,86,230,15,228,126,192,21,77,224,45,225,244,32,
132,117,64,155,21,127,36,178,133,168,50,202,6,239,187,94,235,85,82,209,149,66,47,104,87,248,92,43,0,179,172,156,37,170,235,210,196,52,199,227,60,7,233,189,14,181,92,32,199,114,160,14,218,85,139,240,205,
72,61,30,176,31,216,50,64,147,246,186,82,193,191,67,128,216,150,215,102,3,224,178,72,27,60,248,37,170,4,107,208,226,232,128,57,4,208,100,132,182,19,227,16,228,0,91,0,65,209,13,210,164,96,183,99,147,154,
219,54,62,144,55,58,48,48,120,205,144,163,101,239,249,214,154,249,51,132,172,203,122,102,203,234,158,5,92,223,152,125,218,104,34,188,139,76,70,239,198,46,18,18,239,210,142,125,185,252,48,41,77,158,217,
166,210,230,125,131,180,208,197,168,99,210,219,41,161,111,127,229,164,182,185,7,19,124,233,181,189,240,139,150,66,120,251,136,191,161,232,164,89,170,155,155,105,140,250,196,45,4,118,23,30,232,164,29,7,
34,93,38,24,157,193,213,173,213,112,166,117,171,204,80,246,211,62,110,3,41,154,35,42,50,141,250,176,77,115,20,63,186,129,248,124,194,8,136,62,19,202,231,99,50,57,18,199,171,215,218,233,51,79,18,79,187,
10,97,198,14,75,107,215,178,143,76,254,241,191,245,69,39,114,231,219,47,227,21,200,14,9,77,203,128,138,62,45,91,106,9,136,225,72,207,185,217,116,141,1,86,166,239,79,163,175,31,79,37,19,153,179,114,158,
28,47,210,148,243,225,250,116,26,139,67,83,39,19,2,54,183,143,24,57,183,163,243,35,231,249,178,67,193,24,42,3,117,26,244,119,44,120,34,93,57,74,242,101,20,177,24,59,159,209,9,145,177,112,219,234,147,3,
227,192,10,198,190,117,52,167,245,9,193,193,83,214,149,21,140,14,67,138,240,124,60,99,12,188,13,145,234,0,132,226,163,33,252,140,214,176,86,22,10,137,63,90,81,11,236,87,159,219,91,200,164,151,127,245,
185,148,225,45,186,25,14,124,71,63,234,89,8,241,41,5,121,11,74,153,99,55,114,75,202,233,131,6,232,54,141,67,80,90,77,87,121,168,22,58,94,28,17,161,71,56,62,226,60,183,32,169,109,0,75,76,92,43,217,180,
218,229,157,180,1,96,170,33,135,215,176,113,246,104,206,246,216,112,10,194,215,178,220,110,72,61,51,12,192,126,128,144,95,77,87,160,159,107,194,201,46,148,191,25,127,215,47,151,174,119,79,119,192,151,
61,30,121,68,126,247,21,122,93,223,210,35,220,100,12,235,198,18,230,251,13,110,130,108,31,169,71,118,143,142,105,237,138,57,159,194,234,65,161,184,8,162,115,136,48,90,89,121,111,231,67,57,76,138,32,150,
238,144,12,134,122,134,17,246,39,211,158,104,34,47,191,28,61,50,103,70,254,190,236,154,173,138,126,230,117,226,60,101,148,68,23,32,104,26,232,213,224,25,239,31,29,164,73,214,7,216,138,22,58,172,32,29,
44,187,72,239,69,224,215,190,141,116,216,239,122,17,38,98,238,233,149,57,249,248,156,40,37,219,151,185,54,255,242,183,239,180,119,132,66,119,142,47,247,21,200,174,236,172,67,253,68,93,244,89,119,32,170,
139,226,182,229,245,155,148,222,32,139,218,184,150,151,123,77,101,62,147,106,171,242,158,14,139,8,204,174,75,191,142,92,109,249,9,139,196,89,140,50,142,237,80,15,16,111,6,7,182,165,247,179,139,39,4,99,
168,117,66,56,133,193,13,245,179,235,66,205,117,121,90,77,73,129,155,128,118,114,5,242,175,46,94,175,151,162,94,47,73,140,138,112,47,84,205,203,198,27,116,23,99,167,15,131,12,110,107,120,141,240,172,199,
222,163,132,121,158,35,86,93,140,54,16,158,238,128,119,91,176,57,20,44,168,73,221,34,253,140,102,10,133,189,189,177,153,182,110,152,213,233,60,171,188,69,77,30,61,112,164,126,43,220,94,199,205,25,151,
204,190,110,5,173,80,163,115,48,158,10,158,47,120,170,221,40,108,253,66,251,238,73,195,137,186,249,75,35,246,234,115,186,89,24,254,78,104,46,49,166,224,2,231,157,231,64,113,7,155,73,89,200,66,238,237,
31,214,28,141,80,206,251,109,105,92,94,9,143,108,12,96,240,110,50,88,70,185,195,27,134,252,162,216,233,105,221,134,150,22,133,151,231,155,151,58,42,247,187,116,136,194,136,150,157,99,93,24,126,164,29,
110,109,107,77,253,113,209,153,17,255,130,220,30,95,237,184,10,241,221,107,31,190,243,173,50,112,90,84,250,9,146,197,8,185,151,54,242,251,30,42,226,164,235,92,5,252,108,236,146,105,241,254,26,238,95,85,
185,36,40,136,121,232,237,20,81,238,67,27,192,43,203,162,28,124,222,67,155,87,3,125,240,94,60,223,69,247,184,74,0,174,46,5,185,134,244,15,228,77,11,174,233,135,126,226,163,105,107,165,118,246,198,203,
87,255,68,156,205,157,227,203,123,5,80,64,133,149,202,15,109,134,165,220,71,101,13,10,88,220,77,103,207,76,166,207,61,243,44,30,236,9,141,202,163,169,107,232,114,218,226,245,78,171,233,77,18,255,94,128,
220,214,112,77,91,254,158,229,116,224,252,149,27,93,105,81,142,216,36,11,18,50,52,53,158,164,171,75,93,70,211,110,144,188,107,131,12,243,154,197,122,83,249,131,247,27,47,173,104,104,214,79,202,144,162,
27,34,101,71,45,124,97,29,121,206,190,49,57,96,197,200,7,97,86,1,232,20,3,94,155,183,55,129,192,44,15,143,70,211,139,22,46,46,13,78,41,113,175,198,186,230,109,244,64,158,106,216,32,166,69,72,240,156,156,
50,56,169,33,47,210,70,8,152,179,144,251,149,10,130,118,24,243,95,10,8,227,185,65,245,86,11,122,70,227,119,131,122,66,103,19,176,49,228,0,96,167,49,128,10,61,245,52,129,121,179,138,134,216,216,92,162,
18,49,65,17,130,151,37,247,25,99,10,43,90,214,110,144,158,12,66,249,48,99,189,101,175,234,210,70,87,116,77,7,68,31,103,133,143,137,183,125,174,186,42,143,44,166,139,54,174,65,175,93,212,244,29,154,71,
146,5,38,39,255,68,176,63,103,46,76,148,47,104,189,155,83,66,150,132,12,75,148,87,138,12,56,39,159,110,141,159,148,99,35,186,71,207,12,3,14,29,162,56,90,222,103,199,72,221,191,44,26,101,191,41,228,3,136,
30,183,120,235,108,43,20,229,227,49,85,204,32,6,233,253,52,32,180,177,201,109,218,149,251,244,159,246,202,145,99,232,111,208,23,235,54,151,117,247,120,148,172,75,23,9,150,183,120,174,107,242,243,79,44,
205,25,45,152,199,245,61,76,127,20,161,191,162,249,186,188,226,122,212,111,146,132,25,169,60,254,120,187,240,240,195,29,248,184,115,78,119,62,125,233,87,32,59,211,59,145,134,48,82,162,87,115,131,100,228,
145,1,60,221,237,209,116,109,30,219,6,136,211,154,30,79,183,118,54,211,166,166,231,177,94,35,1,160,133,121,33,233,138,156,52,128,156,14,107,188,227,204,120,16,133,244,42,47,25,45,84,221,232,114,25,187,
124,157,200,87,44,192,182,133,82,210,146,255,192,104,14,72,67,190,146,174,171,209,70,118,107,40,49,34,121,8,79,31,108,242,94,66,193,2,98,68,91,162,215,96,60,85,210,140,77,181,210,77,57,208,113,4,205,16,
16,238,51,16,229,91,96,255,151,8,78,95,86,234,217,212,95,218,82,122,232,139,97,192,94,119,147,113,148,20,39,107,4,178,66,131,104,55,52,137,24,211,44,209,176,9,250,65,109,130,57,171,80,200,85,13,197,151,
133,143,75,195,66,119,253,148,109,245,205,134,143,46,143,155,37,18,125,196,56,118,21,247,241,7,120,60,211,187,6,240,97,201,124,86,133,163,219,58,117,148,254,12,191,29,77,107,167,78,166,53,239,171,84,238,
70,228,232,65,114,159,225,197,116,242,164,69,42,160,194,94,252,225,45,164,140,39,110,208,247,105,82,161,31,154,96,180,8,20,194,254,6,131,205,216,80,214,8,108,111,139,44,70,145,204,67,201,190,196,147,159,
64,254,239,229,117,67,93,162,114,113,70,15,169,16,59,92,100,231,136,152,93,84,161,206,27,211,174,73,167,117,192,179,195,213,170,178,79,140,186,104,167,7,43,93,105,2,150,112,77,52,17,164,248,54,101,247,
67,229,163,178,141,110,75,185,107,87,220,31,115,113,94,89,41,164,5,225,247,97,80,8,35,113,145,195,23,228,197,125,114,253,7,209,55,155,110,117,41,186,92,212,101,231,208,250,122,187,186,211,155,31,154,72,
87,62,241,27,34,145,174,255,115,43,243,252,197,219,39,117,231,203,151,233,10,100,99,16,79,139,68,127,78,78,23,74,227,179,147,21,72,37,175,197,56,102,166,102,0,51,125,105,101,110,13,1,155,34,129,27,124,
211,98,122,86,65,123,78,108,179,219,63,128,14,23,48,13,64,194,9,13,141,174,118,120,155,49,185,185,105,19,109,65,253,66,13,161,221,33,139,11,165,44,170,144,251,31,164,159,211,123,250,43,210,171,3,103,210,
130,48,107,79,78,181,199,109,31,41,175,116,83,200,203,7,179,200,176,161,70,52,117,35,97,247,216,225,183,131,187,171,91,36,66,240,144,42,169,34,10,20,244,74,6,72,51,7,80,217,113,126,53,121,231,6,58,210,
77,128,207,82,239,9,161,103,191,2,59,241,175,177,233,148,177,72,207,15,161,164,13,118,211,211,49,89,11,177,34,35,215,106,43,249,180,170,122,51,195,251,241,246,157,160,145,231,92,135,204,94,191,217,78,
55,111,173,167,149,229,42,143,78,170,133,49,206,47,191,228,60,169,227,91,212,121,141,204,121,128,90,133,218,193,224,252,10,111,67,106,165,177,41,228,211,231,186,71,201,33,202,51,54,154,40,103,228,72,118,
86,49,156,142,228,148,209,96,112,96,170,215,186,210,207,190,77,49,144,226,60,225,49,146,103,202,32,162,2,133,126,233,186,193,183,212,31,148,174,130,211,188,138,183,188,242,249,79,219,180,34,183,140,139,
112,59,247,116,221,95,211,19,202,218,80,130,71,251,177,75,203,182,71,249,61,230,213,181,237,197,180,111,56,81,55,244,245,170,154,239,146,100,120,95,46,94,0,92,149,132,246,43,234,173,187,184,199,145,166,
204,161,31,78,161,102,62,82,30,135,74,239,165,155,213,37,169,14,192,173,155,160,184,251,184,41,10,24,87,231,125,225,58,162,190,238,156,252,180,242,202,229,151,211,254,147,159,206,212,47,61,101,251,186,
115,124,57,175,64,190,177,63,15,240,128,214,185,240,3,104,121,219,22,236,30,160,37,56,155,37,197,239,204,226,139,120,183,186,17,16,5,106,68,180,242,125,99,80,77,55,183,176,150,134,251,39,59,164,128,14,
157,204,89,229,181,119,141,19,148,110,208,176,105,169,137,101,221,248,224,201,102,132,90,17,234,22,44,146,122,116,60,68,189,111,103,21,117,14,189,12,49,188,164,214,58,174,87,242,224,96,27,161,28,199,86,
184,58,122,194,162,160,233,26,232,103,31,254,231,128,159,117,182,0,94,58,60,199,161,133,54,5,201,61,105,54,196,130,50,204,137,198,21,235,149,151,19,79,119,77,40,101,108,202,215,228,114,241,183,45,72,109,
142,247,64,130,194,48,136,1,186,197,180,179,91,84,91,244,92,8,250,93,106,152,55,55,174,167,29,13,207,121,215,161,4,180,233,8,147,32,7,100,240,114,219,40,124,118,41,170,9,234,189,168,110,3,192,149,93,33,
180,204,26,27,71,238,45,100,172,219,176,234,12,190,233,156,114,250,38,139,221,16,78,230,150,3,192,12,228,208,224,52,18,204,41,149,172,234,109,11,205,162,226,1,84,91,154,48,228,239,98,62,211,190,8,163,
145,22,58,224,87,1,200,218,82,186,200,105,171,107,248,101,94,105,165,189,126,93,23,206,76,26,11,77,224,152,176,38,10,240,201,71,216,106,16,224,29,66,221,28,192,200,221,194,208,98,228,242,230,181,205,53,
53,217,17,211,203,60,110,13,211,10,143,55,147,197,109,214,109,19,115,59,57,64,138,11,1,158,241,210,198,110,60,56,21,15,36,12,134,72,114,32,156,93,182,25,84,242,171,66,95,143,19,122,143,169,133,110,152,
221,178,187,161,38,219,51,43,13,186,130,110,248,82,154,125,219,189,255,194,9,220,23,103,115,124,50,119,62,127,169,87,32,219,51,97,81,244,143,144,168,104,166,235,128,151,121,249,206,13,158,167,46,159,89,
182,91,239,203,21,123,0,28,57,249,229,0,21,240,60,138,94,142,106,249,96,176,79,48,97,138,144,201,160,213,197,161,186,150,50,219,91,114,156,152,79,194,3,238,50,76,187,126,6,249,188,100,150,71,65,168,27,
180,208,124,101,51,157,77,47,164,138,249,36,0,192,212,109,50,116,70,104,123,136,253,87,60,105,241,77,132,154,251,245,84,49,43,164,184,204,88,141,27,204,200,211,98,216,80,28,17,213,5,224,90,68,156,200,
251,71,219,194,175,251,126,147,54,208,101,139,110,140,10,67,123,117,129,231,89,246,250,218,184,150,215,145,231,151,145,183,121,227,21,227,29,132,216,67,158,167,192,232,76,241,19,190,246,201,237,244,98,
42,189,112,202,29,52,120,208,57,13,234,9,29,24,22,18,203,13,247,133,129,185,156,252,13,13,47,119,88,1,166,200,111,93,147,29,239,111,151,33,250,177,82,78,59,157,234,31,77,163,200,236,45,143,141,94,202,
29,117,207,122,151,137,213,34,148,138,16,113,200,117,107,34,54,212,109,10,5,229,149,94,161,112,69,148,81,204,47,166,42,84,188,123,232,4,52,187,79,131,187,154,168,208,187,197,8,115,234,207,49,202,240,176,
185,129,32,255,91,30,179,115,49,58,159,130,45,20,145,69,120,213,67,196,133,163,244,44,111,189,143,40,145,85,22,201,68,159,172,246,186,2,20,125,40,183,164,190,171,253,15,48,221,146,134,172,249,186,136,
200,81,2,14,157,17,26,215,188,175,151,231,140,231,216,69,133,20,61,237,58,199,138,251,121,30,177,163,182,77,105,1,152,84,96,200,123,174,71,91,105,237,169,151,215,210,141,207,63,147,170,171,47,161,124,
220,49,204,223,186,39,95,250,119,217,108,127,168,193,161,169,77,14,166,41,3,134,166,132,105,221,80,201,50,112,227,6,15,247,236,246,8,69,132,105,197,107,21,9,42,2,53,225,101,37,80,91,160,135,148,168,3,
80,188,118,26,49,27,164,37,111,145,157,208,144,149,107,106,51,138,197,206,28,148,7,44,180,114,47,146,184,220,174,34,103,243,139,12,234,93,145,167,9,66,124,3,21,48,19,231,209,55,232,245,39,213,229,180,
157,105,166,238,85,247,204,163,10,134,111,16,128,123,50,32,135,29,191,199,130,47,250,200,234,72,89,93,136,162,62,113,50,147,182,146,124,238,26,36,248,58,239,120,96,97,175,171,181,246,244,247,201,1,145,
206,161,199,43,214,239,129,26,106,239,88,16,24,44,74,139,115,155,238,206,85,222,235,64,109,50,182,153,6,176,234,153,185,221,244,204,243,20,216,23,136,93,237,121,31,164,58,11,254,126,29,89,126,205,38,182,
47,175,172,155,213,185,2,181,221,246,58,117,121,105,67,157,179,203,102,149,21,242,109,70,239,37,207,181,167,206,56,231,227,0,253,176,34,167,60,167,143,245,34,35,237,107,235,224,196,194,105,250,155,22,
208,170,213,146,58,236,24,46,172,79,54,38,131,245,43,89,149,53,166,183,69,14,5,168,237,144,92,175,32,103,204,123,142,112,152,109,68,138,80,126,143,8,39,126,112,76,72,176,129,240,252,109,17,196,19,87,55,
58,138,6,143,204,14,171,85,82,144,151,71,23,229,226,85,6,181,23,117,92,162,109,13,26,73,71,230,176,12,65,223,199,162,28,36,22,184,34,204,159,231,217,233,95,107,196,6,24,169,145,102,107,83,169,177,177,
67,101,65,56,110,3,46,9,113,135,167,6,83,249,196,104,154,158,68,18,185,97,238,203,234,198,196,19,79,255,219,31,94,106,47,41,12,221,57,190,28,87,32,123,160,3,127,151,202,94,11,193,121,159,10,248,101,42,
223,91,59,11,60,103,38,221,53,125,70,79,164,5,190,191,174,180,160,109,75,152,202,254,180,18,169,121,169,61,198,232,132,67,178,24,97,128,177,96,242,212,12,90,216,63,251,27,192,143,107,168,116,140,187,137,
92,122,200,24,107,64,135,182,69,156,239,154,148,75,206,40,123,196,19,89,120,114,178,76,69,78,166,22,55,16,69,115,161,166,123,207,56,81,223,6,24,230,9,29,140,242,203,162,154,93,134,97,6,121,59,71,118,18,
134,211,161,249,245,66,137,102,240,102,163,6,111,140,115,26,213,255,153,11,221,85,82,36,53,225,250,34,146,194,179,106,152,115,184,163,107,202,29,171,61,135,74,62,54,138,32,84,108,225,214,202,233,170,140,
164,32,159,229,231,59,33,115,89,171,90,207,148,34,204,240,140,18,211,68,154,66,124,152,24,3,156,48,162,134,143,49,185,100,175,206,155,150,174,141,188,150,177,42,221,221,103,234,221,105,11,42,219,70,207,
19,113,11,75,9,87,59,165,93,232,106,214,6,209,70,156,47,207,68,28,237,196,229,202,5,204,162,208,192,221,38,231,210,208,13,211,86,47,45,64,193,123,144,207,179,122,93,131,192,209,132,246,30,30,56,23,111,
182,12,61,46,234,19,237,151,191,119,46,182,247,112,44,81,18,255,142,195,117,12,244,214,53,206,248,88,53,28,105,123,115,61,189,65,72,251,58,247,240,28,73,204,46,196,249,62,198,94,37,77,186,204,240,214,
121,217,93,130,94,161,126,184,46,180,141,38,133,61,180,197,45,107,161,230,250,29,80,39,108,40,169,28,81,65,156,214,20,127,40,175,127,124,119,187,211,15,187,113,237,48,109,92,17,165,144,103,233,213,173,
189,252,169,23,10,3,189,103,190,239,214,227,151,191,250,248,124,238,124,254,82,175,64,126,183,49,142,154,85,77,243,151,110,166,155,106,122,203,109,30,15,216,113,26,125,237,190,187,103,232,199,44,167,234,
147,243,29,73,145,189,226,180,81,129,58,41,20,229,247,115,24,44,248,170,68,76,111,159,3,131,209,242,117,164,87,49,115,182,63,245,82,144,171,247,61,146,202,167,231,83,227,38,229,189,29,89,92,110,65,46,
202,16,6,106,60,129,133,20,94,80,110,20,10,10,89,109,76,135,140,37,106,167,71,37,57,26,102,74,47,88,191,9,108,241,133,229,11,143,35,124,14,143,27,143,242,253,85,187,249,61,44,160,207,6,113,136,123,122,
196,35,28,105,16,237,135,84,150,112,72,203,114,188,25,243,66,143,104,226,180,0,49,67,66,227,187,38,109,8,90,184,230,22,133,148,144,216,230,105,74,247,61,71,233,1,121,100,49,140,223,115,23,212,30,190,225,
174,73,37,24,157,52,188,223,61,211,212,210,215,247,210,230,18,79,43,36,61,66,168,104,114,185,217,236,122,26,144,83,238,233,121,205,67,175,7,163,52,163,165,237,80,88,186,207,192,166,145,1,78,146,15,3,66,
107,89,171,211,20,234,134,242,142,217,168,208,225,244,150,14,61,120,183,182,186,173,84,125,126,201,251,197,17,230,177,66,178,36,75,222,179,141,34,217,52,15,181,208,75,81,129,103,59,100,160,161,224,215,
231,61,70,76,31,44,169,208,93,234,132,178,145,99,198,69,113,101,66,207,150,235,70,228,104,167,159,126,110,41,93,129,44,93,156,154,78,171,196,206,238,234,25,49,162,65,110,207,179,47,43,217,12,2,144,90,
158,99,79,104,110,215,145,107,219,223,26,187,212,22,133,212,104,151,117,233,65,12,216,205,119,237,98,141,137,74,232,12,173,104,59,251,214,254,161,116,245,230,122,218,253,101,121,170,251,216,150,119,31,
97,67,61,253,225,223,76,135,19,39,123,96,2,48,187,59,33,110,220,145,47,229,200,207,220,119,38,109,47,191,168,180,49,107,145,226,75,110,109,165,147,23,181,133,1,30,186,145,216,123,16,225,167,122,105,5,
97,192,100,35,199,220,188,153,90,3,167,212,51,21,217,121,149,78,168,233,12,194,123,30,108,66,34,121,129,198,238,34,114,245,158,153,32,114,61,134,220,103,129,151,76,78,62,84,119,200,27,121,213,22,114,230,
44,154,98,244,23,46,1,119,232,173,182,232,8,213,132,106,214,116,234,246,251,12,148,48,22,89,76,181,86,136,225,165,213,79,133,214,25,185,172,134,195,206,98,124,201,106,154,233,58,33,228,90,37,213,25,224,
19,21,57,97,119,94,63,106,65,40,121,40,148,172,242,190,133,209,179,222,215,18,18,196,102,90,149,100,149,105,245,196,44,203,116,150,142,142,114,193,240,90,1,201,158,215,191,189,158,154,194,202,87,175,94,
75,147,128,150,32,9,28,225,10,87,23,33,180,16,220,61,39,248,210,89,121,225,77,83,190,245,180,246,201,11,135,247,111,26,76,203,27,98,16,85,121,211,38,20,187,169,70,216,0,206,116,235,91,173,67,159,219,64,
166,204,186,25,49,131,91,188,60,82,57,35,174,233,110,201,72,21,202,131,154,160,247,137,121,203,97,27,186,70,134,33,182,171,139,60,25,143,212,3,29,31,146,35,215,112,110,171,216,252,89,234,238,177,59,137,
188,59,134,249,133,241,243,183,219,199,142,135,28,137,52,220,171,93,228,136,221,254,115,233,37,94,189,32,34,42,25,73,159,65,246,112,181,211,93,250,100,123,120,241,109,121,104,25,239,150,35,150,247,239,
167,243,61,100,83,148,115,134,149,115,170,174,195,203,145,198,54,116,186,184,230,83,192,182,107,54,231,53,215,32,194,226,23,149,198,78,72,94,143,144,24,246,156,223,253,103,134,211,209,217,215,253,243,
79,189,242,169,15,89,18,110,238,157,227,75,185,2,249,90,141,240,134,246,164,137,161,123,33,135,55,211,58,72,125,7,79,244,8,167,173,58,82,50,22,240,150,159,49,32,160,128,88,52,61,114,254,126,253,137,67,
233,202,147,143,165,249,87,159,233,52,40,199,98,225,55,229,72,58,75,10,91,198,40,12,242,78,66,184,194,114,42,109,158,176,43,107,110,46,106,131,26,142,220,86,152,23,121,147,162,127,179,47,202,39,140,74,
232,217,176,91,199,60,73,3,66,197,181,106,169,134,220,86,11,171,169,203,156,207,28,128,165,24,30,86,169,163,165,61,44,135,14,8,95,33,174,165,249,27,143,181,11,1,97,83,190,56,46,79,237,209,60,28,170,236,
117,146,34,21,11,166,108,144,81,195,162,234,149,115,222,84,86,217,18,186,197,68,235,18,227,132,83,167,138,240,118,213,169,126,200,215,135,237,48,17,36,242,231,70,31,234,48,1,152,44,65,130,111,204,17,199,
66,53,236,66,81,10,33,180,97,226,202,187,123,171,194,89,164,10,143,91,226,209,14,213,12,43,152,56,25,0,90,239,1,104,204,251,201,0,112,178,0,148,114,223,62,218,4,148,19,49,62,175,45,235,144,190,109,23,
68,119,119,113,128,7,197,189,13,50,66,241,76,39,164,62,148,62,196,100,179,49,65,241,102,97,68,205,209,124,21,159,251,99,198,233,214,165,116,43,74,41,236,179,83,235,140,11,226,56,14,111,237,92,175,29,126,
127,164,222,60,48,58,144,222,251,192,197,180,255,236,115,48,2,52,77,163,39,14,122,214,229,187,77,125,161,38,89,219,188,2,232,221,7,184,145,69,147,123,2,170,92,235,94,169,195,129,176,124,5,106,91,227,93,
187,109,50,211,26,176,7,221,215,28,20,249,99,68,177,207,171,9,47,193,29,94,82,27,63,63,6,157,46,173,166,223,248,249,95,72,133,55,78,23,122,103,222,16,151,241,206,241,37,94,129,108,23,112,162,66,251,38,
104,101,37,253,144,205,30,97,233,8,176,167,56,145,150,228,246,155,22,218,154,156,173,4,68,25,163,197,122,242,129,65,2,84,234,120,208,191,38,94,110,190,211,252,123,124,22,25,133,235,172,133,95,192,97,237,
202,34,119,211,177,169,202,251,14,120,148,32,36,52,25,222,62,131,81,191,128,74,6,184,97,71,55,26,62,175,0,31,50,28,21,225,97,76,235,210,190,34,4,94,227,89,229,67,136,233,5,26,59,21,161,168,24,179,227,
221,34,132,139,16,116,140,43,221,149,179,177,18,163,226,109,0,234,176,85,140,165,167,169,2,228,20,238,199,241,65,53,142,104,43,35,31,178,142,75,170,158,123,113,204,243,8,133,247,132,224,141,37,232,44,
154,92,85,59,85,104,246,54,149,45,34,176,13,15,90,21,10,235,198,76,227,200,17,119,217,176,242,174,199,230,16,106,93,159,230,233,235,175,218,60,132,117,66,205,170,213,125,109,139,155,16,146,150,41,14,54,
36,191,3,8,228,121,139,124,67,185,36,121,31,61,88,75,166,199,136,68,92,39,222,187,37,194,200,243,116,163,154,152,67,76,171,134,158,183,67,225,240,26,234,36,21,23,231,38,39,151,115,150,228,131,65,252,175,
234,11,93,197,108,42,235,107,13,249,145,206,241,69,81,99,132,182,45,8,108,176,128,194,115,6,26,16,226,216,247,159,154,212,58,23,77,238,115,180,129,168,222,27,48,213,236,232,250,118,83,86,176,217,105,44,
232,137,30,85,141,233,3,217,49,59,159,250,47,128,42,175,252,52,3,128,10,149,122,248,87,90,53,19,103,19,253,175,183,207,38,78,49,193,155,76,253,38,163,45,64,198,87,221,255,115,23,70,210,196,100,95,250,
249,127,243,161,180,119,233,233,242,187,223,48,255,163,199,39,121,231,243,151,114,5,184,29,172,147,214,21,204,26,221,252,22,123,213,162,138,214,217,185,117,161,41,169,18,75,63,245,201,121,70,78,13,33,
137,67,36,215,174,167,179,175,163,103,251,4,13,157,217,135,236,224,1,123,56,98,205,12,33,185,163,239,149,60,79,179,12,100,170,14,116,216,45,89,33,103,139,1,146,153,3,116,224,216,50,194,58,79,213,208,50,
86,224,77,51,0,159,188,144,174,85,149,123,122,193,130,176,174,217,24,3,213,55,44,88,121,149,129,189,55,44,250,19,22,78,188,80,188,20,136,197,168,194,124,58,101,174,100,15,133,246,28,133,243,170,208,177,
134,225,84,163,76,62,65,186,47,103,225,135,112,114,134,225,239,5,18,12,217,108,233,74,233,23,138,30,1,145,38,116,199,132,20,202,217,233,129,244,174,9,236,30,160,83,52,115,231,0,42,39,176,144,214,133,159,
49,77,250,220,80,79,122,201,144,160,129,201,81,139,220,66,142,46,142,117,139,21,249,161,232,253,175,218,168,250,229,232,85,155,210,186,92,238,112,0,151,182,52,106,64,147,89,50,54,182,35,82,157,71,140,
191,12,73,13,6,78,67,105,164,76,159,182,141,148,176,162,227,102,15,208,18,157,40,253,66,71,181,40,124,222,249,142,26,253,126,212,130,69,10,45,229,159,194,16,207,120,94,62,10,182,234,184,119,53,199,206,
133,112,45,66,21,193,103,31,241,61,137,25,192,90,8,77,95,156,185,32,64,81,6,18,178,23,163,199,22,179,105,89,71,76,49,63,167,182,137,72,224,66,6,93,240,30,101,146,33,221,50,87,37,199,125,8,36,147,72,239,
21,180,202,254,0,189,26,58,84,60,223,171,194,251,72,19,6,109,130,175,120,238,91,196,192,190,186,107,204,38,92,69,236,207,170,117,230,211,35,163,36,111,182,127,193,68,199,193,168,84,221,57,190,196,43,144,
221,123,169,173,56,95,2,161,23,210,150,154,98,129,98,94,149,206,105,67,7,69,207,88,45,77,207,234,236,128,182,46,45,12,165,203,115,38,77,13,140,166,135,191,246,30,187,126,12,159,189,209,1,37,58,139,68,
18,212,222,96,128,254,223,213,45,127,21,120,114,20,242,151,122,58,27,40,121,141,195,9,64,8,114,66,116,193,32,81,199,184,229,58,101,130,8,97,75,70,218,23,116,166,20,198,9,104,205,154,235,81,86,159,139,
186,39,239,104,158,142,110,165,53,106,237,194,68,234,111,121,97,96,148,250,122,45,162,177,152,31,130,127,155,131,60,14,224,200,222,77,93,190,46,212,132,138,232,15,229,173,181,70,77,143,217,213,201,121,
78,90,108,247,124,197,87,166,190,169,17,11,48,250,45,1,78,152,66,121,221,24,37,242,40,175,19,54,247,199,123,112,65,179,66,222,34,41,150,97,168,237,93,143,126,165,252,48,136,19,228,82,214,168,181,135,222,
17,99,15,46,225,160,215,109,137,40,38,135,218,233,30,30,185,12,124,26,66,212,111,202,213,187,171,115,105,152,152,115,1,93,110,95,205,233,128,231,41,80,213,11,225,179,24,17,177,190,98,188,253,210,86,90,
210,81,83,80,98,154,82,143,236,67,148,63,82,7,221,151,62,12,10,161,69,212,70,26,242,149,188,87,55,157,221,194,78,57,173,105,32,8,59,12,224,231,152,182,71,162,133,65,30,127,40,163,136,92,66,175,118,96,
180,79,253,246,52,196,117,25,56,4,137,23,42,215,148,153,100,252,52,147,68,63,36,86,38,121,189,73,242,164,81,25,221,38,237,18,51,106,110,242,232,171,154,197,175,45,238,160,64,234,231,212,169,180,178,78,
202,69,142,217,37,146,185,91,116,209,39,252,191,66,139,40,104,213,159,116,93,254,195,83,34,133,157,161,116,63,185,153,197,207,63,159,150,174,54,30,125,230,149,151,190,235,75,92,155,127,232,255,60,219,
117,183,186,21,18,66,151,2,122,86,24,186,139,235,186,11,74,47,32,147,14,224,124,82,90,20,144,133,26,220,38,234,154,122,214,129,210,202,115,64,142,235,123,105,4,56,112,4,52,200,169,161,101,133,101,25,198,
18,19,181,6,142,130,180,48,102,65,152,236,172,92,176,202,51,108,64,254,88,14,37,57,249,43,137,140,134,29,183,70,135,231,96,95,167,7,66,120,14,48,210,5,144,218,92,207,165,27,235,186,59,160,156,197,105,
185,208,176,30,72,231,118,102,250,65,57,156,240,50,136,223,96,254,102,90,78,35,23,206,166,145,147,111,180,203,227,6,239,46,165,170,176,112,48,109,147,161,4,237,243,168,133,19,39,200,94,78,165,69,74,15,
195,148,233,106,171,237,180,129,87,218,14,151,81,11,13,119,8,171,142,155,131,35,172,25,161,253,198,222,14,4,214,166,3,196,233,57,141,252,125,170,156,158,157,127,204,120,249,221,52,245,208,221,169,126,
162,87,187,151,242,145,205,35,131,44,94,87,227,156,183,129,184,4,184,183,242,103,58,64,101,5,250,65,249,116,85,88,121,40,90,168,153,69,154,131,4,167,145,62,136,55,5,38,42,128,189,4,167,143,154,139,230,
187,216,168,108,124,45,249,124,117,155,209,203,43,123,215,114,218,229,130,25,69,31,22,40,118,104,192,112,29,2,189,235,122,237,237,46,83,243,83,128,12,79,217,241,150,145,218,189,150,222,121,79,65,66,240,
186,129,156,245,154,132,220,178,17,68,217,102,4,70,208,211,55,174,14,11,13,238,20,167,229,199,106,180,67,106,154,34,113,220,97,200,183,58,115,8,135,183,108,130,135,206,185,110,13,172,6,233,193,181,207,
216,108,196,87,233,62,34,99,21,215,103,0,235,107,149,153,63,33,236,205,99,57,85,228,163,185,32,204,111,19,86,35,39,250,242,71,127,181,50,216,223,254,201,249,157,246,119,255,161,183,176,47,225,2,100,199,
31,68,212,86,3,43,146,129,236,86,188,127,120,64,187,19,100,214,144,17,196,3,161,226,138,89,146,36,51,102,117,208,159,39,207,241,170,226,246,175,253,234,243,41,139,184,94,239,54,162,62,26,116,145,189,243,
212,20,154,114,144,58,88,125,211,14,189,81,159,55,215,242,80,131,243,160,158,69,165,141,230,188,146,9,117,2,161,227,254,43,243,73,99,7,0,200,122,178,91,215,120,209,131,43,218,183,110,144,205,220,187,41,
133,28,180,227,35,177,51,236,89,101,142,232,180,216,174,47,164,87,158,125,90,136,136,79,107,29,46,221,194,122,33,193,25,172,30,188,187,180,241,242,182,215,111,164,11,179,131,233,193,115,247,162,189,13,
164,165,181,149,180,184,252,92,234,26,153,78,185,25,13,229,60,253,30,69,186,93,202,5,13,160,76,11,61,174,231,22,176,134,154,124,85,88,247,202,243,207,59,41,161,187,243,222,51,170,225,250,43,248,172,47,
242,218,0,146,235,183,132,133,75,112,78,162,209,71,187,161,176,167,148,84,197,44,178,89,244,186,126,10,167,52,98,133,213,64,164,62,222,39,203,0,87,132,200,33,132,61,218,173,139,35,26,60,121,181,162,199,
14,3,169,14,133,195,77,132,5,85,135,116,104,206,73,139,38,109,183,55,150,9,153,146,153,123,212,84,71,211,21,155,223,53,96,77,171,52,45,159,6,210,68,25,51,20,23,94,139,103,127,199,141,87,139,101,156,77,
33,244,216,128,214,183,245,231,117,223,120,77,28,189,49,12,168,9,215,59,194,208,93,57,127,1,16,135,39,129,219,139,94,168,8,91,20,209,132,90,253,56,55,61,200,0,67,159,184,130,166,153,129,73,140,200,221,
11,40,157,77,29,56,91,112,133,73,27,194,132,60,122,1,232,244,40,163,125,189,136,165,102,4,97,77,158,254,230,119,158,78,67,238,213,71,254,221,175,167,27,243,243,127,59,78,241,214,118,123,104,110,179,246,
215,126,199,233,222,249,193,239,122,5,242,115,191,250,27,233,242,139,187,188,21,180,147,74,220,101,30,241,214,2,15,50,170,243,94,237,171,127,84,238,181,158,197,191,161,226,118,225,148,112,53,84,9,160,
137,66,190,188,197,24,40,109,148,83,86,116,71,239,33,51,196,60,199,66,215,38,240,130,112,151,177,124,221,138,4,42,26,55,0,0,32,0,73,68,65,84,254,145,91,101,25,112,87,244,94,98,227,68,218,84,212,157,50,
14,109,232,150,23,230,220,224,134,182,178,98,97,42,77,14,87,141,177,139,238,22,131,115,118,71,61,112,8,163,135,14,14,107,46,239,173,241,34,74,11,194,82,116,134,116,176,132,212,77,125,168,48,60,154,78,
62,114,150,99,134,148,70,223,168,16,114,0,45,174,91,171,91,140,27,184,245,236,83,233,55,158,124,69,221,14,205,78,78,141,195,144,30,64,246,190,235,68,49,109,231,151,1,41,49,60,184,141,174,135,59,107,113,
247,13,12,200,249,6,211,203,128,159,113,244,189,101,215,166,199,232,194,234,86,59,93,91,213,50,103,30,203,186,141,172,71,114,94,228,105,102,93,143,146,157,166,78,152,172,152,27,70,214,71,152,112,190,67,
144,220,222,1,125,164,114,201,172,210,202,54,98,127,113,9,59,17,98,93,144,58,28,45,47,165,242,73,181,86,96,87,169,177,215,161,206,213,205,162,169,98,96,21,121,209,110,202,131,91,74,90,53,209,72,1,146,
90,221,7,208,169,83,30,103,151,175,221,87,129,170,31,4,241,224,216,163,34,240,11,107,191,225,13,58,136,52,5,60,79,63,73,110,33,162,48,15,133,30,81,3,153,96,79,107,220,14,112,168,44,154,57,146,75,182,213,
181,179,144,228,154,13,164,11,27,107,5,200,150,167,76,177,44,202,105,200,137,135,253,190,29,225,47,112,47,215,90,177,81,147,63,17,18,255,10,160,237,25,66,77,39,240,166,95,186,180,201,144,155,105,74,225,
57,56,195,31,249,165,95,68,226,184,176,241,210,78,123,248,40,187,159,207,181,27,63,249,218,25,223,249,250,123,187,2,249,252,91,255,120,58,255,96,53,221,175,9,25,211,58,109,222,120,53,13,240,16,213,76,
254,39,215,46,63,241,232,79,252,220,229,139,53,59,228,176,69,189,107,161,44,32,5,132,26,93,155,104,242,221,111,64,237,202,190,231,248,149,0,29,79,126,98,61,45,110,174,242,184,47,10,143,32,173,118,226,
23,169,226,133,24,113,89,47,224,56,163,124,6,189,239,66,37,151,206,227,212,94,161,110,23,61,45,192,97,50,37,118,113,139,252,69,18,39,235,16,212,65,161,86,73,110,179,7,76,218,241,245,113,205,222,143,206,
188,86,58,235,210,174,117,148,62,184,120,51,157,252,192,150,144,178,47,29,124,250,22,196,211,180,106,101,147,42,239,90,181,88,123,122,167,229,207,187,233,189,223,250,230,244,253,127,249,77,144,96,231,
161,121,88,211,9,208,135,104,21,41,149,125,172,154,44,194,131,245,167,35,102,88,203,87,79,154,61,125,62,125,219,223,252,126,231,180,146,10,13,237,90,202,50,5,158,162,30,229,31,96,73,38,68,182,14,110,58,
247,163,244,228,207,61,150,62,253,255,252,76,122,240,188,124,216,53,170,203,69,55,168,73,108,155,201,25,117,215,97,13,228,53,155,216,33,109,224,30,181,215,58,97,178,218,174,92,89,155,89,214,198,177,163,
43,165,160,204,19,228,133,12,242,3,167,157,54,133,137,97,96,57,27,83,205,232,139,16,206,222,217,30,78,207,205,47,233,20,137,25,159,65,102,4,140,241,180,129,206,6,57,163,13,57,86,199,241,53,16,224,108,
50,151,204,70,105,180,197,152,90,177,124,122,195,166,53,108,115,170,200,199,183,99,112,146,242,77,143,114,78,83,189,243,72,68,147,103,136,145,207,87,229,192,107,234,210,77,27,73,168,30,68,131,59,182,162,
185,55,66,94,155,67,11,59,42,90,205,78,98,25,125,165,205,237,18,166,211,39,183,27,238,251,81,58,41,204,191,242,81,107,101,66,235,221,141,229,52,112,227,213,233,137,210,187,126,125,187,90,250,27,39,7,122,
63,250,123,91,146,119,30,245,218,21,200,15,143,188,201,104,119,32,74,164,44,140,96,114,226,93,202,24,180,75,247,151,222,241,120,223,194,224,141,159,254,108,250,250,175,120,93,154,26,155,236,16,167,27,
125,39,60,180,36,119,155,147,139,76,67,41,129,12,66,213,238,113,89,201,27,191,38,13,225,201,102,58,121,161,155,202,226,242,188,82,81,105,35,118,251,16,196,234,85,38,201,143,15,165,241,71,244,63,254,135,
143,8,139,27,169,52,163,12,210,115,1,192,84,75,253,24,68,149,174,89,196,111,252,78,127,35,27,52,108,183,39,157,99,81,103,39,238,226,13,163,236,211,78,175,123,251,215,35,27,232,154,225,149,27,22,214,38,
68,177,13,121,108,123,173,240,231,7,52,113,250,33,22,121,185,239,155,222,249,238,244,208,155,223,101,35,225,193,67,16,44,58,73,20,55,98,132,129,101,205,48,188,82,44,112,255,106,154,198,149,7,202,156,60,
115,222,245,56,231,199,158,205,235,29,56,111,75,87,169,136,52,10,26,99,110,228,44,227,197,171,221,251,168,141,0,114,60,49,193,211,3,73,120,189,65,236,154,77,242,42,175,168,133,246,209,233,205,10,79,139,
54,130,32,30,84,108,64,53,141,211,53,155,219,216,40,1,109,6,190,137,71,212,206,7,75,232,216,224,216,130,126,78,131,140,0,55,45,145,198,200,8,96,200,56,198,127,253,252,227,184,193,136,19,194,124,91,133,
71,69,47,39,230,126,231,240,222,59,87,89,176,161,76,242,244,171,243,105,154,170,125,102,228,36,13,91,57,172,144,243,176,54,78,118,196,140,209,193,125,26,75,117,35,233,73,177,32,61,4,59,169,234,28,93,90,
37,28,155,154,107,29,132,147,117,173,124,64,104,4,120,156,223,208,246,117,5,214,247,42,233,42,62,243,155,250,7,211,195,122,82,215,110,94,73,207,3,190,202,216,98,17,237,228,109,184,91,88,79,39,140,123,
152,188,246,129,177,157,207,141,142,229,31,250,99,255,200,53,124,200,250,186,13,237,223,62,229,59,95,126,215,43,144,47,4,141,142,129,176,75,109,96,183,91,143,220,228,226,192,248,137,179,23,190,39,189,
239,95,190,7,105,156,183,49,187,49,142,162,122,91,8,96,49,229,212,3,204,168,168,93,54,120,139,209,137,7,211,31,249,27,23,58,28,213,206,3,127,199,39,185,16,61,214,219,187,0,15,113,148,238,121,244,189,157,
127,219,23,192,251,90,196,148,84,98,66,89,169,119,148,81,68,62,22,203,212,18,116,114,209,75,26,143,203,49,246,56,222,250,174,239,72,111,127,247,31,3,56,9,155,253,59,76,171,201,80,143,15,6,45,79,142,233,
104,161,55,212,197,136,143,148,42,218,242,168,92,16,5,34,105,85,220,239,28,29,163,4,234,160,225,29,235,236,90,248,140,109,79,30,172,190,225,89,195,120,93,23,207,35,254,69,154,224,237,22,131,96,65,250,
19,106,91,203,245,167,143,123,217,250,147,215,210,35,70,1,14,33,77,84,129,81,179,94,111,43,164,77,176,149,218,81,75,165,184,126,64,232,43,135,52,49,210,43,244,206,232,97,93,167,65,196,80,50,165,43,76,
77,141,217,115,215,32,192,130,133,14,135,185,205,171,239,34,167,47,121,221,125,51,79,110,137,90,226,232,132,176,54,200,184,150,29,97,175,206,79,181,149,49,188,24,169,184,160,62,186,206,14,190,229,220,
136,142,147,200,49,13,171,66,134,168,202,115,67,77,190,221,236,33,253,185,41,81,65,61,192,229,13,212,85,128,11,228,113,125,189,196,132,48,34,70,72,196,180,179,208,109,138,193,201,91,122,88,99,132,160,
130,110,103,70,205,77,245,210,179,221,171,198,57,152,98,166,47,244,46,155,208,188,30,208,87,120,207,187,61,223,48,149,253,85,99,234,39,111,126,44,181,102,47,206,100,78,189,238,142,97,118,238,211,239,253,
147,88,40,140,178,243,165,179,40,143,255,52,22,114,120,143,139,233,244,93,150,189,123,18,139,180,115,116,190,28,127,31,139,56,138,221,241,187,34,128,100,152,246,233,237,71,29,63,246,183,125,54,55,235,
139,126,18,143,60,54,242,0,137,170,181,109,125,160,120,156,202,10,49,202,32,236,167,96,83,248,226,35,94,239,181,163,32,76,142,35,7,72,249,194,65,58,35,142,200,130,143,132,97,69,227,11,34,26,168,81,9,60,
228,209,242,114,166,70,240,212,194,238,252,151,101,168,121,185,84,236,53,49,85,237,208,134,209,151,215,240,236,101,142,228,101,109,196,140,104,250,142,5,95,65,106,32,83,228,103,140,151,157,110,171,241,
8,244,211,244,217,238,244,45,223,249,45,233,13,23,39,211,230,175,252,92,122,238,249,45,10,1,227,198,185,99,31,33,16,132,66,223,38,47,120,232,125,209,71,144,163,18,33,65,153,83,49,76,240,217,132,247,129,
224,129,145,229,60,43,49,92,88,174,185,13,249,140,226,127,8,121,75,14,210,246,149,70,122,248,235,239,73,127,249,155,219,233,7,223,247,19,222,155,242,139,145,15,241,46,142,175,161,207,254,174,179,231,248,
73,152,112,3,160,84,161,55,220,234,150,203,234,82,105,29,140,161,7,94,119,254,145,47,155,127,90,235,78,195,188,221,190,1,45,69,4,5,149,229,180,171,241,61,211,162,243,107,248,211,41,109,112,116,198,52,
174,43,223,248,237,137,18,161,105,106,12,59,209,91,42,82,217,209,207,59,36,2,248,122,249,254,79,31,161,33,2,239,186,25,244,203,52,156,190,234,164,190,224,87,140,112,128,67,220,179,112,61,250,88,42,159,
126,126,238,239,189,249,190,153,14,64,228,244,238,28,191,135,43,144,143,27,93,15,33,45,136,94,148,17,126,235,136,124,4,162,24,119,250,247,112,196,98,111,219,101,127,183,131,41,119,126,29,6,211,96,144,
241,17,223,199,81,64,185,43,64,34,195,67,135,167,140,227,139,141,177,243,131,47,250,244,159,252,221,109,227,141,112,117,223,4,173,240,170,204,204,135,80,214,127,34,214,227,110,20,0,111,70,211,112,197,
80,162,60,35,143,63,179,78,189,131,227,215,13,207,90,86,42,137,89,47,61,34,131,35,232,230,190,188,239,216,16,138,169,2,253,29,212,7,27,215,235,174,139,15,164,183,188,151,177,41,195,252,218,205,167,211,
75,79,126,38,77,92,162,150,119,97,66,119,50,110,108,183,166,2,174,240,128,145,14,68,139,156,188,61,154,219,99,170,88,134,188,74,78,215,201,190,112,59,167,198,89,68,33,98,55,94,79,3,56,15,52,65,91,118,
93,20,209,67,127,232,96,249,133,244,61,223,245,157,233,211,191,254,145,244,209,91,145,239,70,182,126,124,190,113,89,142,39,93,199,215,104,63,227,233,240,118,159,184,126,37,141,247,211,128,162,3,124,40,
135,199,138,214,207,9,176,17,161,12,11,107,237,78,157,247,127,128,152,49,229,251,19,158,51,167,116,242,138,89,48,187,144,236,161,50,173,168,32,134,80,78,152,50,62,227,198,98,51,125,78,221,8,78,173,102,
202,211,34,113,228,8,123,31,154,96,254,132,205,249,225,73,245,233,133,26,229,64,57,186,110,164,136,56,158,255,165,39,82,185,246,43,133,251,255,210,95,249,230,229,189,246,63,29,239,205,44,199,249,222,57,
254,203,87,32,247,215,255,250,95,255,187,177,44,59,10,118,255,229,199,127,217,30,17,11,59,12,35,199,107,196,71,124,159,183,243,254,214,114,251,18,94,202,147,20,32,25,49,11,180,40,148,44,133,200,245,237,
143,96,120,231,133,230,61,70,253,149,149,15,130,53,145,17,66,199,71,214,199,241,193,243,178,235,188,80,58,78,40,186,65,64,86,62,110,159,29,240,37,23,93,51,8,2,89,45,86,193,118,106,97,56,157,188,103,10,
33,162,150,94,126,254,22,226,189,252,53,18,54,128,88,70,223,233,200,137,147,54,6,132,12,225,230,182,28,46,35,215,235,54,233,123,67,125,36,242,188,178,153,49,13,29,34,65,3,220,231,49,187,120,207,205,173,
161,180,34,206,108,227,244,125,226,249,23,211,217,119,188,67,10,81,74,31,255,220,103,59,94,255,120,14,4,107,86,162,249,194,135,179,148,18,167,123,204,144,121,253,196,100,186,153,157,197,0,83,87,21,225,
236,41,199,28,2,167,122,229,205,227,64,160,162,182,191,77,70,182,197,224,186,177,181,154,58,121,142,200,67,172,212,73,150,208,32,142,102,246,46,140,168,37,94,213,8,37,216,1,63,46,175,247,13,85,65,244,
77,8,245,13,141,238,69,94,211,244,82,146,155,84,19,12,192,121,65,8,191,168,102,250,150,89,12,177,157,157,244,195,191,254,249,52,114,238,190,171,133,254,202,212,119,125,223,119,63,249,99,63,244,67,65,60,
187,115,252,23,174,64,54,140,178,28,90,21,127,16,142,47,10,91,255,107,78,39,188,112,124,132,7,207,138,85,67,165,161,244,219,62,42,3,131,138,255,164,81,228,76,81,15,236,248,75,54,119,236,172,127,203,243,
7,33,61,114,240,172,60,174,147,111,102,52,250,43,17,196,166,18,158,245,144,190,206,234,198,130,90,171,69,45,191,108,40,238,31,82,15,156,122,244,43,84,127,16,249,181,179,181,1,70,203,27,26,211,61,102,5,
27,8,133,54,29,109,160,215,169,165,246,129,105,186,160,191,147,232,129,32,77,221,34,234,189,216,55,221,84,8,179,213,73,245,74,197,171,49,245,87,6,211,127,234,84,58,165,111,242,229,103,111,166,209,209,
11,199,151,198,57,28,179,132,156,19,50,71,124,188,54,130,158,251,76,83,176,132,11,34,131,35,68,130,200,104,171,60,227,84,223,116,154,46,80,89,160,38,191,69,130,34,43,100,173,25,23,120,157,87,92,96,116,
98,13,108,44,138,133,66,237,12,6,81,29,175,249,46,32,207,112,32,198,194,213,145,254,195,244,149,20,45,252,149,13,149,68,140,142,159,9,165,166,89,4,253,83,54,167,53,83,202,111,42,199,220,82,54,90,211,139,
122,128,89,84,30,178,49,237,45,165,245,15,255,200,125,253,221,197,191,218,202,143,222,243,95,115,111,255,48,254,205,113,226,246,255,187,119,126,219,131,117,114,174,227,147,143,16,249,181,80,55,190,143,
35,39,28,123,45,108,14,35,60,62,142,255,182,30,109,91,140,184,196,51,188,246,152,240,222,97,212,71,0,178,120,174,102,16,5,48,142,114,196,165,171,20,8,27,114,172,122,167,43,4,48,36,71,222,37,136,85,213,
24,48,60,34,96,231,21,119,117,240,220,186,190,138,158,40,183,101,108,61,195,211,116,149,120,237,234,74,58,88,217,74,117,53,224,34,16,41,68,237,91,242,217,93,100,141,35,224,77,38,132,179,141,96,140,141,
50,143,147,155,243,247,162,218,132,160,20,115,14,17,241,27,233,212,244,76,234,222,90,132,154,79,164,175,187,112,50,125,248,213,185,78,120,122,12,8,29,167,11,95,0,135,188,213,72,17,186,206,142,165,137,
43,132,189,130,125,84,10,49,178,208,227,245,154,0,159,58,99,28,148,147,246,97,111,117,155,190,22,90,195,19,49,47,69,154,147,147,123,231,148,148,70,8,143,77,120,158,251,120,226,195,86,232,36,197,60,212,
92,122,17,135,120,12,181,175,76,137,222,31,104,108,112,189,92,203,158,72,35,148,168,38,108,246,183,234,171,233,133,224,234,170,25,159,64,203,44,191,250,241,74,225,250,7,12,72,250,230,95,218,217,217,248,
163,125,125,67,159,188,125,67,238,124,249,207,92,129,47,163,113,254,78,131,249,237,175,249,154,241,28,255,252,181,199,199,191,194,112,190,248,223,199,8,237,23,126,228,215,145,211,134,119,11,231,26,64,
77,0,27,113,100,59,195,63,45,96,139,164,225,35,30,20,202,243,71,194,171,24,76,116,252,204,114,91,229,33,241,101,231,113,241,195,54,238,112,32,67,13,33,101,32,189,45,33,109,78,67,241,177,231,165,58,143,
200,16,13,205,53,99,11,163,41,124,119,111,83,253,116,163,3,128,249,69,199,153,230,1,69,34,83,140,166,86,122,233,137,87,80,27,149,61,78,158,74,111,253,179,127,38,125,224,31,252,115,11,183,74,139,86,142,
201,11,143,241,78,75,78,33,39,196,45,3,224,142,186,105,252,236,83,12,212,35,90,52,135,165,215,166,144,197,150,202,172,209,18,18,122,198,198,210,189,161,6,204,160,174,243,188,251,128,152,70,243,70,122,
251,55,189,123,255,141,175,190,125,231,63,252,163,159,156,140,171,242,218,124,206,142,118,45,68,185,5,136,234,188,31,101,169,29,255,174,83,66,200,8,65,71,148,54,242,66,219,235,59,139,105,93,56,59,227,
117,135,163,101,143,199,207,66,186,186,149,90,178,74,43,163,1,14,242,178,117,17,66,174,167,47,45,240,208,55,188,175,158,238,1,20,76,100,10,45,113,93,128,58,35,116,25,122,95,90,82,4,13,141,164,55,244,2,
147,176,167,158,212,116,14,91,39,228,54,166,38,170,198,43,83,216,87,250,169,162,68,222,248,197,247,165,241,239,125,235,96,113,122,246,107,31,111,63,254,216,195,153,135,143,123,222,58,119,242,206,167,223,
126,5,110,27,231,127,108,24,191,253,65,191,251,191,99,249,51,157,78,94,166,238,214,169,33,198,226,15,64,233,216,128,226,239,227,223,71,60,207,241,17,94,41,242,184,248,189,188,204,173,254,237,71,120,177,
140,5,18,71,62,10,236,157,131,49,181,204,109,9,241,101,245,189,182,242,135,202,220,241,175,24,101,13,106,216,4,110,181,116,73,116,140,25,158,122,196,67,30,170,187,149,148,125,194,112,15,247,140,87,176,
72,61,128,1,68,136,234,44,252,59,140,161,108,122,118,88,93,24,101,76,197,142,151,47,34,82,196,131,10,234,156,113,190,89,198,146,87,238,56,210,28,94,100,80,121,222,99,125,105,137,114,33,164,186,175,175,
213,221,223,251,161,179,179,35,239,46,235,103,205,111,175,33,82,104,104,54,87,101,143,254,79,63,227,27,65,192,63,116,142,197,96,227,236,172,165,194,41,53,68,207,92,18,62,102,201,136,172,9,99,135,27,200,
15,197,1,212,187,0,171,156,32,133,194,130,240,58,107,8,238,238,206,198,141,250,102,250,44,206,200,119,31,162,224,29,15,19,14,35,85,178,113,57,11,222,211,3,15,12,167,11,3,71,168,139,251,196,170,113,168,
70,79,41,249,184,246,115,128,33,173,111,21,42,130,165,250,173,116,213,96,221,138,247,59,130,165,181,32,164,30,193,144,218,228,33,111,24,251,88,117,109,119,42,188,162,241,221,253,92,253,24,165,138,101,
138,19,167,93,167,49,70,28,88,245,5,253,190,117,104,246,45,76,168,211,248,182,77,162,100,207,56,207,57,17,199,56,163,222,18,154,63,57,95,77,175,24,241,240,208,217,137,180,252,248,179,233,253,191,249,167,
211,119,255,227,127,252,183,239,123,228,190,127,229,109,191,122,124,243,238,124,254,79,93,129,16,175,227,61,116,118,196,205,123,205,85,117,108,245,56,84,178,159,223,254,187,215,140,240,181,167,137,7,89,
20,20,13,218,232,105,241,81,67,159,83,156,120,237,1,199,94,230,11,255,138,199,90,108,50,22,166,233,119,59,94,45,250,39,227,249,195,64,195,6,142,159,51,158,183,33,143,187,253,67,6,193,80,253,51,138,255,
245,173,171,36,54,145,0,162,238,154,13,66,68,44,96,97,215,30,5,2,211,209,246,25,95,148,102,90,177,57,240,142,77,223,7,136,145,217,94,10,27,187,253,148,199,239,41,47,148,219,225,157,234,248,185,131,195,
216,67,251,3,8,16,192,24,139,180,104,65,174,175,162,185,205,93,247,218,206,19,107,38,132,177,131,211,148,134,206,167,181,149,197,180,117,243,22,79,44,87,91,93,76,119,157,57,203,59,19,93,126,246,90,239,
167,151,62,145,134,240,105,163,31,116,47,102,192,32,217,183,81,240,38,80,244,90,194,224,61,124,214,46,225,98,179,31,149,128,156,104,86,9,35,192,150,174,83,81,14,65,168,215,99,25,148,194,56,221,152,111,
154,233,231,221,120,163,81,154,177,141,253,246,61,127,236,91,191,254,158,31,255,169,159,98,56,126,175,21,46,174,87,40,34,196,28,227,230,161,146,140,13,50,139,190,216,214,226,53,74,2,166,133,60,159,74,
218,187,250,22,83,197,80,162,60,3,155,112,31,118,14,197,205,104,124,187,64,179,13,30,111,83,201,37,23,90,37,101,13,225,194,247,167,177,126,94,63,211,103,202,55,133,9,33,235,1,224,238,192,215,30,27,227,
178,122,210,130,86,182,186,205,228,146,182,184,147,90,203,66,134,116,214,109,121,25,178,93,85,183,70,187,78,151,173,137,30,165,163,1,164,252,182,201,113,75,79,126,50,189,248,207,255,9,90,228,15,252,224,
143,180,219,223,241,125,25,39,126,231,248,79,94,1,27,47,0,192,96,212,206,74,136,69,216,41,63,88,236,53,69,106,30,164,152,211,87,201,120,66,188,57,31,36,129,78,115,181,218,102,244,73,170,220,53,104,206,
52,52,244,214,137,41,231,228,48,217,232,140,8,107,113,52,241,64,27,86,204,109,155,232,252,172,165,176,30,53,212,215,142,108,32,162,142,240,172,1,210,132,34,222,65,72,125,208,1,138,63,108,51,184,48,140,
76,148,88,178,107,188,224,181,116,72,232,106,104,250,130,174,124,237,110,139,87,211,242,220,6,41,71,194,90,128,136,246,246,21,82,36,155,105,84,167,77,48,151,26,91,122,27,189,131,253,53,211,183,252,187,
26,52,53,158,50,62,214,160,172,189,118,122,205,48,233,50,202,92,86,155,213,219,255,226,183,224,39,84,211,7,126,232,99,105,238,149,155,29,105,149,30,210,32,35,101,179,81,44,96,142,128,126,146,126,86,131,
130,38,149,37,140,81,243,26,43,233,90,254,195,114,178,114,182,213,106,188,101,31,141,240,190,123,238,247,174,100,172,26,164,195,16,11,228,11,151,129,74,147,66,224,146,57,52,155,58,81,242,202,21,121,168,
174,54,109,1,128,133,190,98,43,244,216,61,97,229,48,143,86,102,248,3,234,175,161,3,28,249,111,81,196,80,221,253,156,56,154,161,5,210,237,189,68,209,53,194,200,232,233,228,200,65,63,245,52,127,99,33,237,
12,159,76,217,17,185,32,78,238,169,147,19,20,250,175,167,172,82,206,172,146,77,240,130,15,129,55,37,114,45,187,230,120,174,122,63,249,110,155,165,253,184,203,230,208,167,54,186,71,1,161,137,95,171,40,
130,217,69,253,93,138,16,10,134,79,19,68,11,173,222,6,125,166,199,116,189,140,196,216,138,24,92,204,198,22,244,219,246,242,174,67,234,199,59,161,85,100,221,20,243,253,242,212,70,90,38,170,125,241,108,
37,157,185,171,47,221,120,230,231,210,246,175,78,124,203,183,253,169,191,251,115,167,150,218,127,226,235,39,162,131,248,206,241,219,175,64,254,131,255,226,135,233,211,216,226,66,30,32,10,204,114,10,138,
205,36,27,221,105,139,191,45,140,107,203,197,194,120,10,184,160,21,181,184,156,92,34,67,21,190,82,153,78,247,62,248,136,223,239,89,208,215,210,252,213,173,52,143,52,223,238,177,152,86,55,211,226,146,110,
11,121,151,21,116,108,252,190,54,237,214,193,187,37,53,127,236,41,149,56,142,77,57,78,45,22,91,52,68,199,128,35,198,25,206,219,76,79,80,168,85,163,230,120,166,144,30,125,235,68,50,65,34,61,253,107,183,
210,103,62,178,156,42,90,148,54,214,46,203,13,45,5,171,115,79,126,180,97,49,205,140,216,84,98,147,224,46,131,238,183,191,176,152,94,20,74,239,50,242,1,19,168,7,24,201,77,191,174,120,222,73,161,227,85,
57,209,184,157,253,173,223,249,174,244,234,229,213,244,51,63,245,75,233,117,106,117,93,22,228,174,73,215,36,116,73,175,232,207,244,28,209,7,57,191,124,185,19,141,223,107,158,74,85,14,182,38,212,155,145,
215,117,145,0,61,44,159,78,75,136,239,77,227,229,71,3,21,245,28,85,32,203,190,54,144,133,46,237,90,42,56,65,134,232,55,66,162,137,148,176,24,77,228,161,159,228,253,22,177,129,134,241,87,203,85,138,135,
208,226,93,130,98,61,242,195,38,35,110,65,139,231,95,222,164,80,192,236,75,60,47,186,96,94,171,90,16,0,110,95,224,216,207,180,254,41,199,28,108,154,240,141,87,123,114,59,13,215,231,17,243,235,105,103,
167,23,64,35,114,97,104,25,179,58,15,129,92,27,72,235,147,121,162,106,89,157,42,250,81,183,61,111,76,82,185,71,139,221,154,22,176,181,237,174,180,69,224,107,210,236,212,62,141,16,65,125,136,41,218,35,
49,195,19,200,52,82,156,36,107,210,76,115,72,27,123,206,117,220,230,124,202,181,125,138,241,94,243,222,186,232,12,237,106,29,188,70,195,248,148,129,197,125,128,50,179,3,210,47,252,195,31,78,15,108,14,
124,211,3,223,251,253,255,246,39,174,181,191,237,207,157,86,244,189,115,252,71,87,32,255,139,255,203,223,79,55,117,246,231,212,202,6,160,146,101,29,237,85,37,128,69,66,93,53,158,225,235,78,147,230,55,
236,242,242,202,166,63,12,38,80,57,189,254,244,133,116,101,225,122,26,184,251,66,250,254,127,118,79,26,159,214,62,244,194,83,233,241,255,245,231,48,99,166,211,195,247,156,72,159,255,216,111,166,101,109,
88,221,194,178,94,205,203,241,95,209,142,186,98,143,204,243,10,161,132,183,9,21,85,245,134,26,234,10,1,225,71,142,25,165,245,5,117,55,51,93,59,181,190,105,27,65,48,80,63,100,226,217,87,146,189,124,203,
35,127,70,167,73,41,253,251,247,125,48,253,210,103,231,210,35,61,26,170,133,228,93,158,187,41,172,172,200,1,163,144,190,178,61,151,78,128,247,87,132,199,209,60,61,60,81,73,83,224,253,58,47,60,61,76,172,
140,97,78,122,63,251,66,213,16,25,120,114,65,105,96,172,146,186,32,139,123,159,253,44,225,229,148,46,220,59,133,245,226,109,227,235,54,129,52,195,162,133,66,213,200,8,30,248,85,175,209,229,154,205,8,94,
247,52,141,15,89,140,67,106,125,171,132,172,179,140,185,196,163,52,61,6,173,28,207,23,146,89,209,59,9,213,220,35,165,89,218,24,78,147,22,242,190,241,123,7,140,99,203,254,211,28,213,154,39,145,220,23,41,
140,219,4,183,228,128,45,94,175,41,12,230,54,211,142,208,50,58,85,246,133,165,19,218,209,78,106,54,143,81,53,145,107,190,102,152,129,152,218,219,212,76,73,151,26,190,244,224,169,41,155,10,153,152,168,
73,234,107,237,108,182,194,204,156,107,68,59,58,45,97,81,237,213,87,210,52,116,117,159,58,197,26,197,251,97,4,255,238,122,31,21,132,90,58,213,179,107,238,140,251,192,34,183,133,175,151,117,224,76,27,8,
124,138,167,125,166,142,11,236,239,87,133,175,171,176,132,109,233,13,255,171,166,170,101,46,238,185,179,90,67,235,92,209,11,155,6,7,210,175,233,102,186,210,218,72,239,28,153,34,95,170,89,155,136,246,39,
255,245,255,149,102,31,200,191,251,27,191,246,251,126,230,151,23,218,127,234,155,166,132,103,119,142,47,92,129,252,216,204,64,234,129,194,29,49,130,24,160,179,190,82,51,144,199,56,2,61,135,91,136,207,
36,106,83,201,32,160,53,33,109,11,76,30,202,119,3,93,115,105,178,75,239,165,213,81,199,38,105,206,80,102,187,127,154,112,151,82,193,149,43,105,238,169,149,14,149,239,208,140,206,19,218,208,98,248,81,157,
193,7,85,46,199,123,220,107,176,103,193,238,187,172,103,50,67,199,166,194,155,108,243,144,195,10,243,145,133,190,176,73,108,202,64,162,18,29,157,109,13,224,35,60,207,195,47,93,78,15,210,197,141,217,158,
71,118,228,94,222,230,27,209,201,250,31,58,65,128,185,141,77,163,74,135,67,26,99,10,91,64,141,129,104,119,203,162,145,49,150,146,230,238,93,57,84,175,166,110,188,21,94,95,223,35,192,166,106,87,31,29,44,
166,19,67,211,233,204,22,3,163,196,215,219,171,60,130,61,51,13,224,168,41,27,44,24,120,251,122,40,111,8,102,229,108,36,7,140,171,16,188,90,162,101,129,114,238,41,41,108,227,244,238,107,135,107,105,191,
218,220,196,238,33,239,49,110,236,66,142,218,221,90,221,53,180,9,21,149,77,178,106,143,37,6,23,198,94,164,68,191,171,222,152,113,93,78,211,219,173,12,232,160,81,75,204,230,214,72,186,240,110,114,184,226,
38,117,249,110,28,225,224,51,203,19,215,24,110,55,190,95,155,231,222,142,24,54,220,100,135,127,108,167,113,196,32,227,232,47,189,182,182,147,94,190,218,147,30,62,35,92,246,62,74,154,201,187,188,135,109,
124,222,132,118,55,64,32,237,96,147,106,160,250,100,161,111,75,152,46,236,118,13,53,203,226,255,50,44,94,182,198,131,15,242,158,69,198,189,96,131,203,179,250,94,57,101,78,19,246,6,137,148,195,29,17,79,
97,72,174,170,177,61,36,58,25,113,155,241,54,16,24,182,69,43,195,52,120,67,113,226,179,54,134,172,205,41,84,24,63,178,90,78,51,192,167,123,121,239,252,212,132,205,134,228,234,39,254,1,37,138,161,111,57,
55,253,181,63,124,105,105,251,243,61,125,125,79,76,119,103,62,221,121,67,127,200,63,229,207,222,55,203,147,53,210,13,109,68,132,19,141,31,72,105,84,121,97,223,142,119,100,86,193,133,147,101,99,223,82,
58,225,38,101,49,106,6,221,164,123,58,20,86,11,68,158,83,48,170,174,109,204,220,202,246,36,255,70,57,97,118,40,157,61,127,154,254,208,182,209,1,228,54,134,77,202,150,134,86,128,57,69,163,235,239,234,169,
146,95,164,31,4,36,57,160,108,144,35,100,93,183,91,31,232,228,232,7,252,236,233,208,236,183,25,100,45,166,23,228,61,53,51,87,250,102,79,164,53,139,172,49,99,218,213,248,197,206,249,206,94,120,33,189,112,
13,0,69,99,104,94,91,88,15,121,198,28,233,205,65,173,76,154,17,181,93,81,81,160,116,23,234,126,89,104,97,128,81,155,88,62,177,6,91,36,42,91,193,76,98,96,107,1,196,248,121,155,231,190,251,209,135,212,43,
239,78,253,83,215,244,154,103,210,69,212,189,185,134,166,114,11,62,207,171,180,229,124,118,19,255,38,38,173,177,188,91,56,156,145,168,249,41,143,167,151,180,182,40,94,245,51,115,67,247,177,104,14,148,
26,122,105,17,53,133,213,7,26,193,131,64,158,145,99,103,132,176,71,10,248,77,6,216,6,186,100,10,196,199,148,114,10,66,194,117,219,83,67,163,121,46,38,188,69,158,141,90,151,161,66,177,111,162,218,1,170,
95,209,21,202,117,208,229,176,76,71,176,131,58,6,26,255,240,61,169,246,29,74,15,79,52,110,165,119,60,178,148,22,38,81,13,3,197,181,225,197,198,212,108,27,97,184,171,195,198,115,244,96,0,53,117,203,236,
122,31,133,21,155,142,94,84,185,129,220,127,67,131,249,70,218,49,126,113,176,123,60,45,173,171,221,50,252,41,96,211,45,205,11,215,141,106,168,70,201,37,179,150,22,24,246,184,48,245,180,78,152,13,30,116,
180,219,248,11,143,219,41,142,11,97,139,233,109,163,165,244,248,142,232,69,138,52,110,130,248,47,146,94,29,133,34,255,81,205,250,167,94,79,249,223,125,251,220,223,255,187,233,158,239,62,248,206,202,35,
223,180,181,120,105,225,255,248,240,167,159,250,116,95,126,235,187,175,63,242,182,213,239,200,196,27,252,242,29,82,157,210,213,122,58,177,250,153,151,126,108,253,153,207,100,191,250,107,119,210,205,171,
115,255,236,158,183,252,111,31,204,12,12,68,120,248,7,230,200,151,40,3,28,218,241,38,73,86,240,13,66,74,51,39,229,137,90,244,210,172,238,137,11,196,179,22,95,88,178,211,163,111,241,72,101,253,150,7,7,
21,66,90,22,164,158,204,172,93,245,8,141,171,101,150,199,17,214,72,13,175,50,179,177,2,149,36,211,193,123,229,44,196,24,1,144,1,233,15,65,104,155,26,124,119,73,54,238,147,142,223,140,156,204,61,238,105,
104,110,182,171,107,37,84,71,11,74,159,197,181,185,146,94,226,145,30,166,1,59,72,181,160,136,85,163,151,3,234,25,51,45,137,116,89,188,5,27,69,209,185,134,183,221,69,107,203,4,149,204,127,219,58,69,242,
132,178,6,237,240,53,207,23,112,67,75,27,88,31,241,236,24,147,55,169,174,184,104,109,219,192,121,64,51,95,24,102,139,215,232,155,68,117,235,139,174,27,93,27,106,119,25,228,239,186,65,185,187,94,19,109,
188,211,119,218,166,36,176,68,111,164,211,95,35,12,109,210,171,237,182,113,228,132,203,45,231,93,143,225,47,174,100,93,249,163,14,37,205,240,180,77,225,122,47,99,47,69,93,116,112,52,205,51,212,171,71,
27,157,145,136,117,127,91,85,174,200,155,135,169,157,22,250,234,111,203,7,114,68,202,123,222,67,83,195,120,65,216,31,83,197,251,61,231,0,121,147,158,209,93,247,38,147,94,136,50,139,8,196,167,206,130,10,
18,66,160,235,189,58,66,198,144,207,119,75,30,31,109,120,74,52,89,27,96,171,115,175,52,201,51,224,38,182,207,115,115,20,230,17,10,206,118,109,48,182,99,33,235,5,249,104,21,154,236,10,146,103,169,167,211,
144,252,11,34,151,199,246,73,203,208,75,90,195,209,61,208,195,57,58,98,115,237,220,137,240,152,84,136,74,49,33,14,181,159,151,190,142,215,124,3,82,62,27,41,11,222,112,143,22,179,121,90,81,19,125,101,202,
130,93,233,103,174,237,166,251,52,247,126,197,197,153,244,212,39,87,210,254,226,114,202,191,240,211,80,233,214,255,208,51,248,246,174,108,177,246,238,213,197,218,205,253,159,253,208,63,92,88,88,254,92,
154,28,123,124,42,147,185,249,165,90,205,250,81,251,235,126,254,215,31,251,182,141,91,183,190,167,113,237,90,254,198,213,87,211,115,183,182,211,230,226,218,87,190,113,255,151,230,15,219,237,111,47,102,
50,143,125,169,175,243,229,250,251,252,120,197,78,43,1,217,21,90,22,33,171,187,180,120,42,16,139,83,114,151,169,161,62,37,54,5,115,72,97,38,67,64,186,190,110,212,58,213,57,48,253,164,144,244,80,46,212,
224,81,114,32,254,40,242,19,15,80,122,128,24,242,122,117,97,77,136,203,246,75,88,8,96,80,26,144,187,8,123,183,40,14,132,114,91,38,8,160,22,82,133,194,185,20,19,216,98,97,91,107,1,172,107,206,176,77,116,
25,156,228,231,4,140,67,170,82,122,150,70,6,104,247,88,136,214,105,154,57,157,79,207,243,68,179,194,61,178,186,202,7,125,70,212,169,197,9,187,115,33,26,102,177,101,121,246,73,158,12,166,145,214,184,204,
33,231,24,229,128,152,184,85,181,176,243,16,203,89,225,124,81,30,54,234,73,138,165,105,231,20,253,34,71,233,141,80,199,125,160,88,67,249,227,174,3,40,48,15,25,233,93,141,151,203,99,217,244,241,86,89,185,
85,52,41,183,212,12,130,12,80,38,64,86,182,233,44,211,117,45,240,60,39,41,30,132,222,88,139,129,54,148,75,150,189,143,9,94,181,108,244,66,166,222,235,154,225,243,25,125,120,184,61,161,181,43,222,3,82,
186,243,204,241,148,91,218,82,42,114,246,94,222,103,163,126,194,121,111,26,149,184,201,240,8,137,241,244,53,155,71,39,135,180,248,157,92,39,247,12,250,94,167,182,172,161,250,161,193,126,2,100,12,156,252,
104,87,105,210,102,101,3,104,44,27,85,161,228,34,87,12,94,236,40,45,164,54,81,232,97,209,192,117,160,94,203,123,232,206,116,167,69,198,123,193,181,158,173,95,35,206,182,145,46,205,3,2,197,69,35,234,158,
109,253,187,221,244,141,66,233,127,27,177,61,218,250,246,246,30,62,94,0,0,32,0,73,68,65,84,129,91,251,36,68,247,132,219,231,162,189,78,190,221,182,46,26,148,29,131,232,59,123,64,194,68,180,181,225,122,
77,185,62,11,54,196,127,118,89,211,118,126,51,141,0,173,38,68,104,165,120,206,199,126,185,107,59,43,151,253,154,183,2,248,150,11,159,255,196,211,127,179,193,203,247,21,7,159,255,245,15,63,251,242,185,
11,93,159,56,53,115,238,135,126,244,137,148,57,79,248,241,237,255,153,254,208,247,183,223,159,123,111,122,175,64,59,181,159,240,216,169,139,233,129,43,207,223,248,159,126,228,31,253,236,123,94,157,187,
149,182,54,46,233,93,109,167,199,164,96,217,91,51,233,193,55,60,146,174,127,240,195,211,31,255,236,103,255,26,207,250,39,148,244,142,119,187,47,151,149,253,87,62,79,62,208,205,134,5,91,138,122,130,112,
104,202,173,159,62,161,109,42,250,39,215,236,250,12,183,173,129,182,139,197,140,13,1,91,170,100,19,201,106,196,200,0,59,81,167,150,153,181,24,218,38,147,233,170,74,175,66,45,219,188,88,14,37,205,51,116,
106,111,209,26,92,1,166,180,169,10,204,171,160,183,244,89,78,138,159,107,158,115,67,238,215,37,239,170,131,249,227,138,68,109,238,200,130,31,208,220,123,149,145,103,133,139,129,222,108,240,74,182,102,
198,41,28,180,113,244,176,214,156,80,187,104,49,180,162,239,82,244,147,115,211,39,25,120,244,112,54,132,162,57,58,172,251,188,107,203,206,223,165,254,25,185,83,76,212,110,34,43,76,26,224,83,197,98,217,
43,92,183,192,248,27,175,73,145,19,173,77,248,187,116,185,211,209,210,199,227,157,102,72,147,148,0,27,64,168,96,21,237,105,109,233,55,223,165,32,231,173,83,92,200,202,183,154,138,250,7,128,162,94,52,184,
49,72,101,24,237,186,92,107,203,184,193,33,225,223,150,247,240,60,141,166,61,158,115,68,75,150,234,21,191,196,227,101,135,69,16,66,16,209,74,119,68,25,64,158,182,82,70,183,28,173,172,254,88,215,22,182,
141,152,78,57,56,157,37,231,121,5,127,182,74,137,97,71,7,76,229,54,41,191,67,217,11,15,106,61,181,129,70,129,80,115,108,154,185,17,25,94,120,54,237,222,5,224,59,23,48,27,198,17,227,13,182,80,132,217,205,
46,82,159,174,251,45,202,20,55,132,223,71,61,211,12,217,185,3,255,142,246,87,58,2,223,109,17,200,75,43,171,128,193,110,178,47,248,192,12,177,91,232,189,172,116,178,34,31,239,181,27,43,252,136,19,154,233,
148,6,237,53,116,198,136,54,188,77,247,210,246,74,72,124,18,248,116,21,2,220,111,163,206,185,54,7,238,247,27,166,198,211,103,0,112,215,53,140,254,192,125,66,127,145,149,157,202,56,142,75,105,243,230,147,
105,228,109,24,71,111,251,186,116,69,238,252,127,255,191,63,66,100,238,232,190,175,186,231,194,125,207,157,235,253,246,76,229,220,223,170,21,9,98,175,77,165,95,249,149,143,254,249,204,202,202,242,208,
185,241,180,178,99,35,112,204,93,127,54,77,61,118,241,47,220,184,184,255,174,143,126,244,51,105,254,149,249,244,226,63,185,222,125,84,168,245,222,188,254,66,218,92,189,146,6,140,12,25,27,28,54,229,60,
163,25,126,57,237,223,88,75,247,222,125,62,189,249,129,187,222,107,194,204,143,122,154,143,118,158,236,191,243,167,124,17,112,81,163,9,115,101,233,122,194,192,226,113,212,185,120,171,13,59,247,14,132,
116,213,228,174,140,146,194,89,72,119,69,254,182,125,56,36,43,140,14,7,15,6,178,100,66,87,213,205,30,29,29,77,91,99,148,229,212,76,15,195,93,240,90,171,106,135,75,139,197,142,176,212,148,59,182,79,153,
61,79,95,232,254,243,60,129,155,245,42,6,13,18,170,124,166,172,16,110,65,146,236,136,118,177,172,153,45,245,189,50,242,54,54,13,38,77,157,250,91,244,62,23,131,145,237,104,99,30,109,222,184,213,25,23,144,
71,69,139,238,200,38,149,133,140,82,71,80,224,218,241,189,13,39,154,149,155,54,142,140,210,205,36,201,142,108,23,62,173,240,93,246,147,246,133,97,57,245,200,50,15,182,47,31,101,254,184,162,254,134,241,
22,23,150,59,245,207,186,154,239,158,48,110,69,131,114,6,209,29,103,32,157,226,101,154,74,15,219,74,76,7,66,66,145,92,162,123,70,175,214,47,189,118,67,248,56,233,250,21,213,38,235,0,162,138,105,100,235,
225,93,162,254,27,232,52,100,124,71,126,63,130,236,208,109,162,216,158,159,245,148,141,173,176,112,247,58,207,167,83,133,119,153,24,38,133,137,223,186,101,179,107,209,189,45,182,6,99,92,140,251,97,230,
203,64,43,157,32,103,234,54,8,51,148,181,194,48,35,228,136,83,96,243,209,127,250,52,20,250,100,118,3,209,125,14,47,216,168,139,6,89,20,79,208,37,66,170,163,63,54,25,106,129,247,232,82,230,8,52,187,58,
104,35,118,142,7,88,62,35,154,211,43,144,214,133,221,174,52,53,154,210,59,223,254,96,122,233,249,229,116,249,210,21,41,67,45,109,41,135,29,0,234,74,188,115,25,129,163,169,61,45,250,192,179,242,199,138,
60,185,237,117,138,59,234,174,128,187,211,54,244,107,203,133,244,73,97,251,236,176,252,150,161,239,24,195,113,130,10,196,162,220,233,215,150,235,233,219,102,137,170,80,174,200,95,52,188,89,142,154,121,
236,3,105,99,177,43,125,251,31,249,211,233,45,111,123,119,250,241,31,249,123,233,199,127,254,3,105,248,169,98,230,212,240,200,216,54,202,230,197,179,82,144,193,217,95,24,84,254,155,89,22,53,17,9,183,39,
164,69,163,57,94,92,189,150,222,176,252,104,250,200,39,62,70,157,255,154,182,185,66,7,5,127,195,59,78,164,82,233,222,52,197,49,156,24,239,79,81,129,234,218,127,182,51,37,96,234,145,111,120,95,174,231,
117,247,94,186,188,122,41,214,216,31,132,35,127,122,104,50,173,146,142,188,46,76,45,201,77,154,106,108,155,102,53,30,172,154,168,108,98,106,200,82,102,240,66,139,40,107,220,165,206,126,121,35,16,160,205,
88,51,242,162,220,225,58,111,71,185,157,240,244,144,65,182,42,6,74,8,134,21,249,122,100,33,60,45,231,156,230,129,46,0,41,235,123,122,4,173,207,105,161,238,10,64,130,208,186,94,191,30,108,26,139,144,118,
106,211,130,26,49,174,111,195,36,175,44,195,233,193,219,12,15,24,179,66,199,121,209,1,76,22,103,209,41,131,212,21,185,15,109,36,228,152,21,213,121,99,121,161,85,42,7,70,141,3,247,7,109,78,22,168,172,160,
44,132,206,55,162,158,122,31,249,205,91,66,172,46,134,180,78,77,176,0,244,234,47,142,26,174,171,140,66,16,185,111,152,231,17,182,215,110,30,152,49,237,134,186,219,245,230,86,135,213,99,176,130,155,31,
161,119,168,204,203,173,213,131,43,54,139,93,134,218,14,34,135,125,227,8,16,114,36,175,138,146,70,221,15,246,253,237,62,111,172,95,165,163,45,52,68,114,96,219,166,20,198,93,128,18,71,158,217,45,7,107,
1,165,118,169,220,21,132,152,37,69,204,150,133,182,103,248,111,73,199,72,17,3,104,131,71,222,192,125,173,3,176,138,30,103,214,112,26,49,32,56,61,231,106,240,186,199,202,20,190,218,4,142,201,239,186,97,
32,209,151,86,118,211,189,95,55,66,165,98,154,151,34,136,166,20,83,140,180,4,130,213,112,98,121,121,68,132,240,237,6,53,68,239,173,105,67,205,3,178,170,230,143,110,50,160,67,56,67,151,235,252,27,159,126,
81,83,246,48,172,203,120,69,210,43,5,6,209,167,198,217,153,189,42,167,31,80,34,58,164,105,187,99,35,29,151,186,100,40,64,60,39,28,29,64,79,188,120,111,127,135,188,241,20,80,40,228,78,138,4,195,86,55,132,
215,90,211,78,147,14,253,212,53,13,4,54,229,211,90,248,46,126,99,79,90,84,131,126,249,3,55,82,173,242,179,105,234,194,213,116,215,31,127,83,250,59,255,243,15,164,119,188,243,79,167,167,158,252,205,180,
246,234,101,52,198,253,52,63,119,41,53,230,22,176,184,136,112,27,1,50,48,56,153,246,168,45,246,171,4,12,41,245,61,187,240,100,58,3,91,120,232,157,247,165,193,145,243,157,125,177,50,113,38,13,169,75,23,
108,172,57,107,197,44,103,200,251,91,58,169,64,87,249,212,91,233,53,127,254,193,115,227,18,179,63,24,71,126,205,176,219,35,29,21,147,250,9,123,42,140,100,115,33,109,44,200,139,52,5,215,237,102,175,46,
107,173,181,120,90,138,204,77,53,206,50,36,116,208,78,94,16,198,4,247,179,42,103,140,35,194,209,226,136,242,131,240,179,32,231,32,225,154,238,85,85,223,21,58,61,35,207,217,172,81,21,215,116,124,200,136,
111,153,125,25,10,112,65,86,120,117,3,80,195,8,155,10,236,195,104,121,69,194,82,53,33,238,161,145,236,89,121,208,176,231,47,147,117,100,162,220,58,94,108,188,150,48,174,20,220,214,22,108,83,158,220,149,
161,176,96,33,213,133,171,193,139,45,242,28,135,164,26,3,197,44,85,123,149,85,246,32,137,59,80,74,33,112,112,220,132,51,253,188,154,113,178,29,126,108,153,199,96,187,157,185,37,77,125,148,11,235,186,81,
212,50,51,140,183,136,163,90,81,126,219,130,254,182,169,25,172,144,136,44,51,208,126,84,183,208,201,45,8,97,179,74,69,33,17,219,242,183,121,139,116,75,200,151,195,116,138,200,245,72,20,209,231,122,12,
10,187,75,126,126,232,92,14,156,91,115,119,134,209,194,79,165,19,187,216,225,71,194,254,49,145,73,131,193,196,230,177,10,21,29,54,69,188,208,179,103,252,32,99,42,213,92,67,37,10,249,243,168,156,112,48,
100,10,226,90,0,199,90,114,213,227,35,232,127,162,7,127,95,38,231,217,16,145,52,151,99,126,140,16,159,96,88,62,144,233,26,207,111,3,161,80,141,244,128,200,78,46,180,214,92,18,165,140,11,123,25,135,129,
83,164,165,141,181,144,131,43,125,141,210,36,126,28,90,187,98,140,198,120,121,216,102,53,153,198,173,151,33,81,197,18,15,191,39,253,152,116,79,3,92,91,147,123,223,80,238,217,53,63,165,15,168,52,43,116,
28,28,15,210,127,33,93,88,175,34,91,108,74,7,50,233,44,164,246,69,168,237,14,64,237,109,247,158,18,146,110,165,127,255,244,118,122,207,103,39,84,3,8,145,141,1,251,102,54,108,246,159,75,123,159,194,1,46,
215,210,153,201,139,105,234,109,111,75,183,78,222,155,230,228,141,189,67,235,238,3,112,106,11,81,195,121,10,0,245,215,30,165,19,147,99,210,140,51,250,117,41,236,11,187,27,89,83,244,42,0,76,44,165,67,225,
243,138,80,90,156,96,19,183,57,187,132,25,21,136,146,50,97,161,56,127,190,92,238,62,127,233,234,203,11,131,229,225,15,142,78,142,126,236,246,69,253,239,246,37,191,182,139,28,206,176,90,184,164,125,163,
148,200,183,42,105,0,16,84,161,31,185,254,28,98,54,3,29,61,77,155,85,201,66,44,167,47,80,47,99,159,133,74,11,103,128,199,236,51,170,46,242,211,12,207,214,162,22,191,47,140,156,0,210,20,132,187,5,96,192,
59,52,28,239,169,155,93,54,55,228,62,30,183,36,7,105,237,226,147,234,104,156,232,157,74,143,109,44,165,95,94,222,78,179,194,161,111,100,32,211,21,139,126,7,28,47,71,234,83,168,207,199,252,74,97,87,29,
208,179,201,115,159,17,54,238,203,229,118,229,202,248,18,194,216,168,177,9,177,108,10,135,224,206,24,39,88,131,40,119,107,132,94,18,130,245,241,206,165,188,49,10,194,237,10,195,220,83,215,137,249,46,89,
139,174,174,128,158,227,237,182,208,5,187,238,62,149,74,189,68,191,24,215,60,6,68,64,79,211,237,209,180,36,63,222,242,250,246,36,55,49,70,11,42,39,1,117,218,110,182,74,68,71,76,121,71,109,115,223,140,
151,2,38,77,132,248,246,229,142,76,100,153,197,31,240,44,219,66,233,178,243,207,80,192,159,241,62,119,1,76,162,185,142,178,125,87,5,112,66,21,161,164,172,2,204,78,45,222,181,74,49,223,110,163,68,179,41,
31,71,8,24,66,124,135,6,31,101,215,153,34,250,29,100,187,38,138,136,249,50,113,4,16,116,124,68,222,201,243,170,129,30,65,179,247,54,13,120,122,229,89,134,237,245,49,166,98,179,56,8,218,95,96,73,88,95,
57,40,253,137,202,108,218,93,27,78,175,82,77,28,21,205,12,151,70,24,154,56,129,176,244,11,234,223,25,42,253,131,185,73,121,238,156,123,75,195,86,237,56,72,35,227,238,253,234,209,85,233,77,37,221,114,55,
207,120,223,93,54,161,231,24,104,30,243,104,236,228,137,148,78,133,98,60,13,227,229,155,208,102,181,116,127,23,235,227,4,17,240,123,160,226,207,219,209,158,20,181,189,105,104,52,61,118,11,227,235,125,
207,167,239,57,87,73,111,123,147,129,73,186,62,99,179,171,205,163,80,110,127,42,125,238,185,103,81,154,191,42,61,248,85,175,79,231,15,207,166,77,220,230,104,22,207,154,17,179,191,55,106,163,37,215,58,
36,211,53,154,178,211,156,32,226,171,5,80,37,234,219,223,132,116,219,44,7,145,106,224,222,192,177,144,133,17,154,163,171,214,172,175,166,13,49,227,186,237,218,108,103,166,167,255,70,185,183,235,47,95,
185,117,229,61,103,103,207,126,240,246,133,253,239,242,37,127,97,186,36,228,49,238,109,29,203,198,66,237,39,223,209,166,71,154,51,162,189,140,150,54,59,33,240,177,16,100,32,242,21,93,10,202,27,219,0,159,
188,29,231,20,15,80,171,205,211,111,189,15,129,252,86,39,215,27,22,242,4,93,174,197,83,108,122,236,185,225,177,244,122,144,252,45,243,33,87,132,112,25,23,169,123,76,161,27,14,178,252,202,139,233,77,230,
134,60,8,1,124,113,121,215,238,174,127,208,236,199,126,53,185,94,221,255,101,227,20,208,213,211,136,154,205,70,70,209,158,119,234,236,118,66,230,8,201,182,33,67,59,177,83,11,31,171,106,166,33,62,214,205,
72,247,40,241,109,105,211,234,71,32,47,33,37,52,228,141,35,61,147,74,11,104,106,205,85,161,59,190,168,240,178,196,136,243,69,227,225,161,182,249,97,51,68,148,109,162,14,26,185,92,15,175,31,115,43,163,
249,56,75,167,168,143,238,174,104,72,185,131,87,18,53,236,243,28,192,223,206,141,182,247,170,107,218,132,236,228,29,206,171,146,195,65,120,102,121,100,78,180,208,18,154,103,70,133,136,174,109,29,141,45,
47,58,200,243,92,49,236,118,137,149,150,109,48,249,1,81,8,163,170,2,181,42,90,223,122,117,185,28,185,150,135,208,157,77,160,76,68,25,71,38,123,29,122,204,54,175,61,125,118,42,205,14,92,73,55,182,87,189,
6,171,235,28,252,168,243,10,248,103,194,70,162,250,159,214,139,54,82,97,251,16,148,185,233,103,57,101,172,3,208,121,217,38,152,250,39,211,194,171,66,65,64,89,191,64,62,95,166,11,36,127,172,103,134,148,
151,234,16,218,232,92,105,167,233,110,82,41,93,167,210,45,8,252,150,247,246,138,100,45,235,186,76,198,38,21,163,30,25,106,93,61,182,74,89,112,223,5,156,25,157,77,147,148,237,27,64,184,218,208,182,49,19,
168,126,194,227,209,46,70,39,218,58,137,208,113,18,74,157,113,191,62,187,212,74,239,159,191,146,222,121,202,88,123,244,193,255,253,67,11,233,18,116,251,207,79,157,101,120,82,159,241,106,58,185,9,97,221,
58,157,142,110,26,111,127,147,58,224,137,187,244,191,158,74,149,177,64,188,163,206,142,187,187,124,160,214,46,167,182,64,166,135,221,64,70,88,240,247,3,82,44,123,70,7,27,104,41,27,102,221,247,22,80,47,
26,233,139,238,75,55,130,74,68,90,241,95,68,90,53,155,75,174,78,201,170,84,249,197,122,181,254,103,183,118,182,62,59,62,62,126,229,246,5,254,111,250,197,62,10,8,225,73,6,237,41,93,24,32,50,100,100,128,
1,131,110,236,221,74,12,7,202,40,43,47,173,90,168,74,7,98,248,1,111,190,19,74,2,2,54,25,161,117,29,169,158,11,228,98,15,208,150,225,157,50,12,34,104,95,217,156,98,58,68,118,10,21,173,136,217,18,70,187,
42,175,25,165,229,58,194,16,107,188,232,168,5,119,151,157,108,5,72,177,95,239,73,55,53,20,71,46,88,4,114,132,126,235,161,92,114,192,2,47,241,238,254,220,98,16,226,9,219,110,94,223,143,107,105,166,139,
113,237,54,15,241,160,157,54,118,74,137,132,155,181,131,219,218,111,84,124,43,188,58,79,116,196,64,179,78,170,95,252,211,178,224,250,41,17,20,229,204,102,3,162,184,33,227,243,136,161,89,187,29,4,121,231,
127,100,195,216,207,106,245,194,104,233,131,18,239,43,201,236,64,92,203,166,87,231,186,93,39,22,92,245,198,163,17,32,99,161,14,163,192,225,203,51,72,160,135,107,148,193,88,234,197,195,109,139,40,138,3,
54,43,249,116,94,238,27,116,193,46,94,163,13,137,173,169,9,133,246,79,76,102,219,7,192,53,70,105,242,40,240,23,188,94,129,214,111,7,157,86,59,110,28,44,165,193,158,51,82,10,32,138,133,219,37,76,125,219,
123,222,149,222,241,153,249,244,99,31,249,53,207,21,145,139,11,19,75,172,101,7,113,145,172,185,116,31,162,67,94,244,208,22,150,183,144,213,187,186,140,28,84,102,186,246,212,147,29,153,150,123,190,250,
43,83,99,214,230,243,252,186,22,182,125,4,125,155,196,236,76,218,67,181,171,42,163,116,41,171,12,24,120,180,71,120,59,56,183,171,84,244,107,135,198,110,72,3,22,157,215,221,162,140,162,220,189,23,179,235,
64,217,166,79,93,185,223,130,31,87,155,93,94,211,60,78,4,188,244,112,57,61,250,230,225,180,136,183,249,153,121,147,211,228,180,243,34,142,73,225,241,155,166,187,210,249,190,37,94,187,156,62,125,117,59,
61,56,125,210,44,213,201,244,119,62,60,151,94,89,191,156,254,202,131,3,105,246,141,238,213,168,217,159,213,167,210,210,117,225,255,71,174,166,127,186,216,159,78,156,187,144,254,228,119,189,93,234,69,42,
219,122,152,154,12,192,15,83,75,232,122,104,29,247,65,216,139,177,64,28,193,137,110,132,211,8,242,11,195,108,138,66,194,17,4,89,163,25,155,173,125,42,72,18,253,66,249,150,186,222,230,238,10,195,109,107,
10,233,254,87,61,61,197,107,11,11,47,190,125,106,234,158,27,157,39,251,111,248,41,219,80,2,225,242,236,136,221,233,195,87,179,168,115,0,1,187,203,85,185,193,18,61,210,34,239,52,56,160,179,99,72,239,4,
100,17,215,192,194,198,27,181,131,238,147,93,108,199,8,190,142,117,90,75,227,66,78,223,23,133,178,125,194,162,38,154,218,17,227,236,145,15,78,107,250,173,12,178,46,128,196,170,210,204,203,114,142,6,181,
240,134,252,21,36,11,65,27,96,200,232,122,33,233,1,222,143,58,100,143,220,176,236,2,71,87,81,197,206,92,236,195,254,113,68,232,184,163,67,100,218,206,91,65,33,203,11,235,218,168,135,141,168,159,10,31,
71,132,52,227,118,247,93,27,78,51,46,122,176,104,133,190,61,208,216,86,103,241,218,45,145,10,22,24,222,158,124,88,226,109,8,46,52,83,222,189,99,66,115,11,10,61,40,44,236,177,160,67,221,47,3,60,9,143,87,
100,104,35,158,231,72,14,117,147,177,199,236,145,96,76,53,0,94,109,155,68,25,61,47,174,209,44,241,230,0,160,50,128,146,16,108,110,30,0,61,54,145,25,236,228,253,128,181,124,211,228,107,197,254,216,177,
207,145,81,41,40,244,247,219,68,70,157,203,96,41,6,14,87,117,130,232,7,97,103,125,162,149,110,225,93,221,115,228,154,107,186,70,168,225,95,90,73,221,197,145,116,207,195,111,232,92,143,24,1,24,64,86,124,
100,131,245,35,7,123,202,124,213,186,115,153,202,45,166,5,26,195,243,194,189,126,105,66,183,114,77,159,153,47,187,71,55,120,224,173,52,117,247,61,233,96,76,184,127,196,0,235,152,94,59,234,187,145,179,
171,163,182,250,6,73,92,206,8,73,129,58,222,115,15,20,252,72,174,22,115,93,108,65,192,65,57,46,207,85,211,50,86,158,25,229,141,199,82,55,101,135,149,237,149,244,25,155,220,186,146,91,175,156,186,255,52,
73,82,198,178,186,55,159,206,141,186,239,197,77,121,173,77,200,6,118,94,253,246,47,205,12,167,55,192,56,46,249,253,184,142,152,123,199,70,211,191,127,101,63,189,255,51,7,233,214,37,57,178,230,134,94,161,
214,153,83,91,105,117,238,241,244,83,63,253,147,105,227,233,247,167,158,157,95,77,115,31,248,55,169,246,217,87,210,238,214,190,246,187,99,142,245,158,148,235,214,170,202,224,94,108,124,60,37,131,139,173,
43,107,45,69,15,111,47,236,160,87,88,63,62,136,172,49,20,255,150,210,217,223,243,34,144,162,25,50,49,49,188,165,168,189,186,206,113,149,123,78,119,247,141,126,199,252,226,226,143,125,234,83,159,186,175,
115,193,255,27,125,202,47,204,35,39,99,188,84,41,7,60,69,83,102,176,100,0,145,221,187,75,254,118,84,150,249,65,183,202,107,61,24,68,205,52,42,201,203,15,0,14,42,66,84,39,200,28,44,60,214,234,136,104,144,
99,69,4,231,13,132,102,77,94,179,106,12,224,161,55,218,166,240,190,134,21,211,176,216,43,216,43,67,188,215,1,46,107,94,248,41,118,81,139,180,149,50,190,222,232,152,15,162,128,188,170,59,139,30,23,142,
28,154,56,23,90,169,60,78,251,11,225,155,197,106,183,60,100,148,123,22,205,182,5,91,212,244,27,58,60,33,157,17,13,199,61,4,166,178,188,221,46,216,248,144,33,100,229,208,5,134,9,75,145,111,98,200,144,224,
56,226,225,138,1,47,203,163,163,204,123,228,121,218,100,52,139,60,89,143,250,105,3,247,181,128,2,24,175,21,4,132,129,168,169,122,167,89,225,87,129,167,238,97,140,94,213,162,64,16,183,145,12,200,129,250,
232,212,6,186,141,1,105,1,203,189,157,211,158,252,116,216,207,179,1,162,121,172,61,136,213,169,25,246,226,247,42,194,199,162,201,27,189,80,0,88,133,250,192,22,239,8,114,82,246,225,181,44,150,182,63,104,
219,228,114,22,123,196,214,129,105,213,159,154,23,14,71,248,230,71,33,139,217,89,126,113,31,132,209,81,106,178,113,222,56,26,5,184,60,144,70,87,71,82,109,145,20,201,184,18,146,243,42,64,111,11,189,133,
116,5,117,176,123,197,112,164,245,197,78,14,58,211,51,196,251,59,63,158,37,149,38,210,173,220,21,156,101,27,204,158,148,129,199,59,111,195,141,77,252,26,144,175,123,93,164,163,182,91,34,248,93,113,253,
178,202,110,91,74,68,231,241,138,123,252,236,37,50,167,251,54,179,110,128,80,67,84,53,32,26,250,31,191,97,56,189,241,45,119,165,31,255,217,231,210,246,117,132,10,77,221,40,29,105,221,123,184,151,72,117,
14,64,53,15,109,239,166,129,91,56,156,77,255,114,185,149,126,254,95,92,74,223,251,80,111,250,174,111,62,145,122,103,52,122,191,112,61,253,195,175,25,78,15,191,1,241,255,87,63,142,193,101,14,236,206,203,
233,137,87,78,166,217,123,223,156,102,31,66,79,148,191,199,32,169,188,77,45,171,110,28,101,53,123,116,103,83,111,9,251,59,99,30,173,165,140,235,103,9,116,142,130,117,184,1,133,143,105,238,189,154,28,10,
214,97,76,65,127,238,165,207,187,216,7,63,56,174,136,63,48,80,249,238,39,94,158,255,129,189,106,235,23,222,250,250,217,87,143,255,242,247,239,115,62,55,129,194,165,158,216,134,126,158,36,134,220,37,55,
204,157,40,166,115,125,65,96,22,34,78,34,147,19,169,234,67,229,11,0,114,29,35,165,219,128,155,9,168,223,34,86,199,30,34,123,140,3,8,56,191,205,51,5,106,25,121,89,158,113,135,103,40,212,145,156,229,42,
37,74,235,91,66,170,29,76,152,211,83,60,178,213,190,126,157,17,11,87,171,93,0,16,87,47,147,211,31,202,78,99,180,192,14,94,107,15,175,181,32,60,106,3,68,70,20,250,139,188,84,147,151,61,0,30,212,195,195,
186,136,45,205,204,253,110,66,33,107,119,183,25,196,16,161,186,215,12,190,104,89,227,112,33,22,190,238,138,188,231,226,142,25,87,236,162,152,46,62,202,10,242,13,61,141,243,12,255,94,55,39,192,37,214,162,
124,96,119,207,140,170,133,138,14,156,87,209,8,65,14,204,88,2,134,174,156,80,20,226,79,202,91,243,16,231,125,68,135,182,215,223,112,109,42,194,216,64,123,15,0,53,53,125,156,49,17,173,100,51,202,64,108,
163,67,165,181,171,150,200,163,87,32,167,109,17,131,253,142,218,158,249,162,194,212,18,196,117,199,70,210,111,81,197,36,176,24,71,191,204,232,114,222,179,237,62,141,51,236,194,209,73,129,7,228,177,184,
152,86,158,253,112,202,93,158,19,195,184,94,54,149,78,84,235,251,48,84,253,126,6,218,78,164,43,208,213,15,243,60,247,246,159,53,58,112,71,40,10,237,133,6,225,227,232,189,126,148,98,158,73,106,140,238,
254,135,190,54,93,217,120,206,253,181,129,122,254,94,127,95,58,234,79,11,177,128,99,166,213,114,204,215,22,201,192,12,238,233,147,170,184,94,189,100,51,179,72,238,89,169,68,214,77,223,209,211,219,98,164,
3,144,235,1,215,50,238,195,60,5,138,253,157,187,82,227,227,70,106,48,222,187,139,179,233,201,143,45,164,143,93,195,67,230,189,182,61,207,190,180,105,143,24,117,83,72,121,198,186,26,20,98,94,219,115,63,
221,161,92,153,167,174,15,167,191,255,216,97,250,212,141,155,233,207,61,58,153,222,124,225,100,122,232,59,167,211,141,207,139,6,46,95,75,175,251,198,126,117,227,27,233,227,255,250,197,52,174,17,127,245,
214,180,104,233,180,142,41,168,237,68,31,239,71,51,73,186,178,43,133,152,37,164,22,18,43,25,155,37,200,204,122,180,177,6,200,160,28,21,225,238,6,210,67,0,150,147,112,144,165,229,181,52,191,126,75,205,
183,132,47,12,7,225,80,42,250,99,247,247,246,126,176,58,127,249,175,190,255,167,223,247,205,239,253,147,223,123,89,58,97,69,255,254,28,134,75,35,171,171,59,126,230,242,65,26,131,128,78,244,247,167,202,
40,0,5,122,219,216,25,72,115,230,52,30,234,60,9,52,247,208,130,175,175,174,167,27,40,111,251,12,48,250,44,179,184,173,214,6,1,103,32,209,201,211,105,181,254,217,52,42,7,27,233,103,68,208,175,221,126,134,
7,24,26,52,131,179,209,143,182,237,177,209,26,86,87,170,168,51,208,160,114,103,121,154,18,20,86,16,169,164,34,132,86,203,235,146,188,31,241,96,45,23,37,31,181,179,130,90,102,44,62,222,183,16,172,33,155,
66,22,58,60,66,4,58,164,71,14,75,160,78,185,236,145,134,237,109,97,122,212,243,234,144,210,45,200,113,54,26,149,121,147,240,122,81,198,24,102,176,123,128,164,166,221,113,121,167,71,174,97,140,157,60,48,
146,216,133,133,165,52,183,113,104,246,9,16,7,40,146,101,208,161,233,219,27,33,163,48,24,130,212,241,98,193,220,169,90,92,3,114,175,33,97,81,22,253,175,234,119,81,11,109,11,139,163,15,54,43,244,47,168,
235,149,121,201,61,121,119,137,161,15,25,20,148,213,171,26,19,217,42,0,162,22,36,56,218,172,114,178,127,72,21,99,5,184,49,210,18,101,190,152,174,86,21,121,88,57,54,65,175,13,220,40,243,120,72,118,169,
49,49,148,102,188,14,219,151,11,170,237,218,123,194,111,118,142,136,225,108,38,251,183,232,17,21,95,77,187,23,78,137,120,250,59,157,57,227,121,163,48,134,18,66,63,3,2,16,53,201,88,230,114,35,105,250,228,
133,180,182,160,43,70,212,180,61,168,97,97,103,15,43,104,58,141,41,119,172,12,188,156,230,213,16,75,192,186,25,144,114,191,217,156,101,231,220,239,220,94,224,73,79,227,3,7,139,234,41,181,233,155,72,19,
93,48,130,138,115,26,51,148,105,249,69,180,197,109,205,13,253,211,233,57,147,224,94,210,122,152,51,24,89,41,61,205,137,68,182,61,199,152,77,176,79,40,218,86,46,154,181,54,30,81,6,121,147,185,171,191,113,
117,51,173,162,0,158,59,57,156,158,153,155,75,255,251,47,207,167,191,176,61,146,102,174,43,65,209,203,157,58,227,141,238,47,114,6,232,144,253,134,90,105,196,223,248,248,203,105,88,216,222,167,25,254,104,
65,83,199,154,121,61,141,51,105,226,254,89,100,150,97,205,234,141,52,121,94,147,134,178,11,186,154,180,73,201,205,21,61,100,176,51,26,226,235,155,90,47,12,208,186,106,221,191,238,252,168,234,65,49,93,
126,230,38,80,14,6,242,212,75,233,217,207,127,62,61,242,173,95,55,93,152,185,255,115,47,61,245,236,143,248,227,191,216,185,230,191,15,159,242,141,245,26,169,127,203,214,206,54,201,80,23,120,185,181,27,
237,180,102,23,252,252,181,249,116,150,138,250,57,249,38,82,173,200,83,137,194,2,238,86,39,107,42,77,52,132,170,71,136,213,29,175,105,49,228,45,190,187,44,168,222,184,233,188,96,54,74,22,22,98,190,219,
108,74,175,19,8,223,16,99,89,159,95,145,159,13,166,254,129,173,212,39,148,232,82,98,217,112,177,201,46,11,169,118,24,118,24,255,190,176,150,39,70,45,43,238,44,166,75,213,141,244,213,110,102,14,248,80,
158,156,234,24,120,183,49,0,161,138,94,212,224,92,138,6,80,214,187,46,172,139,240,49,195,19,133,58,64,5,178,121,68,169,89,164,219,73,252,243,81,200,23,222,78,171,169,174,69,8,46,167,30,6,10,13,157,138,
124,86,238,181,162,38,41,244,157,18,90,45,40,156,239,169,253,77,152,75,185,103,177,53,16,255,119,148,126,6,229,185,229,136,77,25,156,205,55,40,196,194,190,232,172,97,33,34,132,186,112,58,234,192,253,154,
65,91,188,66,91,4,209,107,115,107,138,161,34,95,13,53,189,172,90,97,211,130,44,1,90,178,22,101,120,222,35,172,156,28,4,119,96,68,136,39,220,219,87,198,200,203,219,203,64,38,226,32,169,54,48,207,27,203,
27,43,144,77,27,72,70,78,228,118,120,223,17,190,217,52,110,27,103,83,9,235,218,226,122,122,231,201,98,122,199,5,198,38,13,121,201,123,203,110,14,165,65,101,178,80,108,63,220,18,81,48,236,58,209,232,181,
198,134,14,36,255,200,226,220,246,19,176,142,46,18,207,187,9,49,239,201,78,107,32,215,182,71,78,229,60,112,104,18,34,187,45,220,95,118,174,135,214,74,179,41,252,118,182,13,247,81,155,64,135,28,127,89,
237,188,219,144,226,251,102,250,210,7,63,55,199,235,54,210,235,239,155,72,47,108,204,167,107,188,117,145,218,195,120,148,129,220,243,72,98,218,202,80,101,81,200,102,49,155,110,146,62,185,119,162,149,46,
74,167,214,78,150,210,75,26,41,174,173,204,119,28,72,255,208,68,250,209,207,201,67,171,47,164,71,167,243,233,61,88,72,61,64,54,244,135,244,250,179,211,105,119,131,116,76,242,88,236,165,181,231,86,17,68,
150,211,197,73,181,221,79,125,32,173,61,37,4,64,219,91,247,190,179,95,125,111,42,159,25,73,91,34,183,160,125,142,25,216,220,61,171,158,46,245,105,237,119,167,155,159,121,74,195,253,147,233,117,221,39,
144,33,172,147,199,63,149,102,223,52,154,158,185,122,45,61,254,204,188,122,31,222,241,3,179,170,113,123,127,228,217,199,127,225,254,7,30,254,150,255,143,183,59,15,146,53,205,202,195,254,230,190,213,190,
87,221,189,151,219,203,244,76,207,206,48,204,48,12,66,195,98,64,8,36,4,178,48,14,36,36,48,22,142,80,216,178,34,80,132,22,75,150,228,8,132,181,217,150,67,178,8,73,160,13,144,16,32,96,6,134,97,246,141,153,
158,238,153,94,239,94,85,183,246,170,172,172,204,202,61,211,191,147,221,173,1,219,127,206,117,70,84,223,219,117,171,50,191,239,253,222,247,156,231,60,231,57,231,60,247,0,206,102,202,47,81,171,52,37,172,
215,23,176,152,6,188,110,221,189,175,152,23,59,41,214,184,32,86,124,251,101,105,20,158,106,79,90,96,202,33,232,30,82,198,240,132,83,114,132,86,5,91,26,151,21,238,48,48,189,156,97,196,35,44,233,172,212,
194,52,120,26,73,152,114,64,179,72,244,98,205,198,60,76,86,66,90,33,165,60,148,184,142,50,51,70,207,29,217,80,203,112,115,116,90,207,35,29,128,69,52,55,239,9,82,215,164,110,38,225,21,201,224,16,61,156,
149,228,46,113,215,57,222,44,228,121,61,23,49,205,131,30,136,96,102,236,184,146,120,50,130,190,32,70,242,232,254,146,52,203,72,130,127,17,141,127,194,163,225,79,28,136,121,228,5,184,105,28,251,189,251,
20,77,24,190,80,215,4,34,136,253,94,111,71,190,80,126,151,167,205,138,247,242,60,69,244,75,154,229,96,171,60,241,177,67,221,19,15,186,66,199,8,172,183,177,34,71,106,136,247,36,246,142,216,47,98,73,54,
11,20,151,90,225,97,250,32,249,140,242,182,53,105,147,156,235,139,181,106,106,85,50,69,111,11,197,130,244,14,118,164,89,122,72,16,243,76,138,72,162,18,225,197,16,123,222,63,21,107,74,103,14,16,60,77,247,
211,85,231,153,115,56,10,14,190,75,240,8,24,36,127,188,250,146,230,1,133,215,17,58,11,240,248,22,5,83,75,30,170,137,84,26,81,83,149,116,210,155,170,26,114,123,231,30,29,47,196,17,90,221,226,91,24,51,134,
202,61,156,28,16,73,148,87,137,238,131,51,184,199,11,246,210,198,212,106,196,94,105,155,170,169,105,237,213,93,130,230,251,105,121,168,182,151,70,185,155,109,169,143,181,185,121,205,3,119,125,143,204,
112,125,116,162,84,16,219,143,0,251,228,11,45,107,139,35,0,171,91,4,22,111,196,222,15,24,158,134,58,215,3,53,162,115,132,38,55,144,73,247,33,136,213,8,77,76,56,155,97,236,191,235,82,203,160,36,227,24,
183,59,105,183,14,237,192,239,143,92,4,205,161,183,159,251,82,61,61,183,187,39,117,50,78,215,158,94,176,31,230,210,198,53,226,135,5,247,63,102,112,46,244,236,69,7,233,186,112,173,166,132,113,126,55,173,
237,151,210,76,253,94,218,255,197,177,110,21,184,128,37,242,197,218,155,211,232,68,31,165,206,174,252,222,48,237,126,226,185,244,245,111,88,72,79,188,227,18,67,214,74,111,223,35,164,120,227,84,90,120,
199,31,77,55,239,253,78,250,224,71,95,73,239,91,217,73,63,240,222,119,92,185,251,220,238,69,107,254,96,14,103,206,96,212,10,198,118,209,64,216,214,120,55,61,164,240,119,131,145,25,16,29,44,174,104,71,
33,72,223,55,151,18,200,195,104,85,82,141,86,178,36,206,136,178,229,48,182,81,163,56,18,75,198,198,136,158,62,21,30,23,105,198,91,136,67,74,182,166,195,136,15,54,108,183,42,16,183,193,20,115,175,104,160,
149,67,6,237,106,91,113,160,50,98,137,191,43,131,114,69,241,22,20,59,9,230,171,98,224,30,236,202,57,0,0,32,0,73,68,65,84,217,40,247,82,67,25,35,247,202,76,249,136,18,40,98,197,253,230,126,218,18,175,109,
248,188,249,206,162,207,118,218,140,77,151,242,150,159,147,108,7,13,103,85,206,52,253,206,0,196,237,211,144,142,233,107,219,98,154,248,183,40,32,222,227,85,71,174,189,108,144,207,188,7,56,179,118,217,
161,12,75,195,40,184,134,24,159,208,23,79,230,120,138,1,24,120,188,107,116,189,218,206,172,141,153,167,88,153,17,171,53,136,223,115,65,120,57,104,29,27,115,44,173,144,153,8,22,128,91,135,121,26,251,52,
209,248,186,143,3,140,243,28,163,17,211,188,118,64,40,141,235,120,11,203,131,248,10,207,35,99,103,227,58,208,226,163,8,32,115,170,72,134,78,122,219,102,61,151,39,22,80,164,105,107,146,83,194,182,184,241,
8,43,175,171,3,45,100,116,181,247,46,158,3,119,255,218,43,43,190,141,117,58,225,81,239,82,234,188,66,70,215,150,146,138,88,183,220,187,143,156,51,10,112,106,41,189,237,109,79,167,163,175,60,159,14,158,
253,184,214,42,216,234,117,138,26,77,160,167,74,143,166,145,34,222,102,71,27,48,57,198,82,212,105,58,12,91,98,179,87,120,221,37,158,105,195,65,238,64,60,29,6,104,102,94,195,50,134,234,33,203,247,52,9,
83,71,44,31,186,217,177,107,124,243,198,227,233,248,203,251,26,162,161,249,240,89,108,54,195,106,63,88,191,144,89,140,90,14,44,68,181,43,21,51,96,140,198,82,63,53,97,196,170,195,90,22,255,181,133,44,215,
253,142,211,37,157,147,77,55,229,110,99,253,50,205,118,186,180,170,212,80,40,241,55,62,124,43,141,63,126,144,158,94,184,104,180,225,105,250,190,235,133,244,253,239,158,247,239,80,218,71,95,78,215,191,
78,65,254,59,173,229,177,142,128,207,184,46,19,222,42,87,104,160,183,6,233,241,247,245,165,221,62,147,78,62,55,233,120,36,124,210,191,247,50,207,79,44,178,253,203,95,84,26,25,19,215,65,219,15,111,166,
198,181,229,212,158,89,79,58,155,145,161,30,166,131,131,244,201,81,182,255,236,235,235,254,181,254,51,223,119,120,26,216,185,46,102,240,138,228,88,180,136,108,159,136,33,162,172,104,226,29,85,180,19,97,
231,17,10,11,53,10,34,3,98,113,250,41,75,187,41,95,235,96,202,111,134,124,204,70,235,183,141,1,116,32,242,254,45,213,48,132,205,35,11,109,235,141,103,39,45,23,115,60,67,219,161,29,41,206,30,97,250,154,
98,186,69,48,120,209,1,8,139,216,6,249,186,190,55,68,68,204,161,242,167,125,175,7,2,133,192,254,170,207,169,218,64,118,161,53,16,206,59,200,39,60,115,209,215,176,117,196,163,249,57,213,18,197,56,16,124,
217,216,70,42,131,136,57,236,156,243,36,208,247,239,222,175,24,12,157,123,172,240,2,29,94,101,150,161,233,242,136,217,242,226,132,232,136,201,212,3,94,112,44,14,206,17,112,159,43,150,142,66,241,41,108,
99,213,189,69,191,220,97,77,211,174,83,239,7,118,15,37,225,33,60,233,28,111,175,250,37,139,121,110,88,83,194,43,144,211,65,103,168,66,211,58,212,85,162,72,162,88,18,63,71,203,195,6,70,182,138,132,152,
70,164,197,32,169,51,135,252,140,119,47,89,212,177,252,114,17,19,28,162,255,129,106,149,140,14,15,139,74,251,242,60,217,156,248,48,43,126,126,25,147,56,106,196,97,183,115,45,73,192,179,215,95,147,174,
130,242,164,159,7,109,87,149,99,141,86,144,90,214,121,139,86,247,146,159,159,33,101,44,154,105,218,86,97,212,145,75,30,233,214,208,158,81,207,106,31,48,191,102,200,204,99,42,239,50,200,242,129,51,87,211,
92,117,75,140,23,5,214,209,32,59,58,241,137,237,243,88,236,180,150,30,89,83,36,239,160,212,102,150,211,83,181,243,116,135,114,199,12,229,244,182,39,222,200,184,158,131,135,13,241,58,162,137,32,88,210,
105,114,143,75,244,87,37,225,72,135,231,15,100,49,114,192,219,132,252,139,66,144,64,28,3,113,111,242,60,74,181,86,186,133,193,158,101,100,214,168,127,22,32,152,167,253,76,70,106,230,23,95,25,165,143,220,
141,105,102,251,233,170,174,10,141,35,117,197,32,81,238,188,157,62,120,39,155,62,177,115,152,46,165,61,6,60,147,30,87,206,246,216,14,85,211,211,87,32,27,61,152,46,183,64,89,147,219,63,98,158,171,122,229,
234,221,205,52,251,214,57,98,149,153,244,197,127,127,83,103,6,121,211,55,79,167,159,255,196,139,233,227,159,59,82,212,97,36,133,2,131,189,116,55,205,93,122,156,102,152,131,89,166,8,171,118,158,125,243,
187,191,31,206,125,48,47,32,144,57,211,48,249,132,224,248,242,244,101,228,143,36,247,34,217,153,3,26,210,138,162,126,59,125,45,68,130,161,235,70,165,10,15,91,33,195,146,98,76,24,118,144,212,222,176,97,
237,77,27,132,103,100,97,195,19,4,148,204,136,187,250,42,76,216,73,98,110,115,43,197,52,39,98,12,77,101,160,78,194,111,66,249,178,13,25,167,252,196,97,248,10,139,123,1,156,142,153,159,103,44,107,25,196,
234,241,28,33,118,49,69,93,206,76,172,198,250,199,43,235,144,14,29,196,145,216,183,44,86,70,75,129,131,198,8,130,115,35,7,240,68,12,20,195,97,115,54,65,28,158,41,155,187,139,100,234,73,131,68,39,193,121,
193,127,91,98,122,28,85,47,140,193,148,177,2,109,82,178,65,71,119,118,155,48,46,43,19,108,30,122,185,227,132,205,32,205,154,8,176,99,247,177,34,142,142,57,160,45,101,103,33,89,43,131,101,20,124,186,22,
144,65,58,120,81,242,182,228,253,251,14,196,129,239,245,28,136,110,147,52,80,252,82,118,16,171,52,169,242,54,202,180,164,106,36,250,199,98,226,45,249,226,73,11,80,127,239,56,212,139,12,94,40,145,92,32,
148,97,158,167,3,88,231,129,71,198,53,180,165,41,154,82,30,151,160,156,43,140,215,62,153,93,54,114,189,97,33,95,123,69,62,111,204,208,220,219,223,79,143,200,47,207,200,211,222,84,177,241,69,60,192,55,
42,15,43,14,110,164,204,69,241,152,4,95,225,169,167,193,193,171,169,117,76,180,127,112,168,210,8,41,231,62,186,208,197,126,97,13,97,71,53,115,122,135,254,54,67,123,75,223,188,179,149,190,245,45,143,164,
236,197,235,233,99,47,110,166,127,242,204,205,244,44,104,220,1,97,89,106,215,44,118,126,81,33,3,148,80,214,198,229,73,215,57,39,134,127,76,75,154,203,136,163,187,66,151,143,30,108,51,182,218,128,58,132,
3,221,225,171,188,112,198,207,151,160,149,174,107,255,44,116,212,149,25,56,28,34,171,24,221,135,53,50,219,116,40,86,185,221,247,62,186,162,66,232,136,170,76,81,183,124,243,11,129,56,52,125,202,42,18,88,
94,161,255,213,151,233,133,251,167,233,83,82,69,81,62,216,123,86,107,22,149,41,79,205,29,164,119,200,109,174,62,18,19,241,192,103,207,114,246,215,200,0,151,87,82,246,209,11,233,115,47,109,166,207,220,
135,224,92,223,175,124,242,36,253,218,179,13,4,226,66,146,65,66,60,49,154,56,135,83,245,173,179,77,156,133,88,34,51,188,39,24,121,112,175,252,2,143,84,228,165,154,30,114,119,138,96,57,114,76,196,7,77,
85,39,109,12,97,105,205,35,7,7,143,108,168,214,50,239,37,93,176,130,162,62,143,254,59,224,175,34,150,87,95,225,57,44,106,145,32,59,139,96,25,168,6,169,242,32,57,228,72,9,244,152,5,91,115,90,113,68,240,
223,176,153,167,166,196,76,210,22,117,7,186,24,108,141,110,5,215,228,31,31,193,250,70,19,172,30,25,94,5,1,20,73,225,150,107,140,87,137,199,202,129,168,17,219,6,100,173,242,246,89,113,229,140,248,43,147,
89,229,197,149,165,129,186,24,126,68,138,56,15,19,151,71,32,45,7,148,18,239,245,29,212,115,30,245,132,215,173,81,7,73,14,24,16,187,171,226,197,47,192,178,99,12,108,79,87,2,89,18,233,29,173,67,32,197,18,
47,155,3,117,166,65,250,134,245,232,122,216,89,86,94,181,62,193,129,120,216,161,232,137,93,67,41,85,142,110,7,218,175,244,121,163,14,61,237,195,17,235,58,12,55,122,92,201,162,10,111,4,210,25,130,168,10,
162,101,102,65,66,247,23,135,244,92,167,135,188,131,124,57,216,108,34,144,146,88,63,100,120,38,222,138,141,121,22,135,218,59,200,55,202,11,130,121,83,242,120,37,226,241,71,113,4,239,94,153,75,159,219,
83,57,243,255,104,94,231,54,165,200,168,156,24,159,156,131,51,51,109,212,31,209,125,75,239,160,77,207,101,238,249,109,99,19,166,211,181,39,28,178,71,54,82,159,90,166,25,121,46,134,45,198,17,206,19,136,
116,32,134,177,230,218,135,32,243,52,177,68,81,40,242,20,54,253,241,71,215,196,220,83,233,167,127,233,99,233,217,205,187,170,89,38,143,103,242,159,40,122,24,248,189,56,152,241,138,206,142,95,192,83,196,
235,25,198,230,155,159,184,148,158,16,239,110,67,34,163,182,170,34,222,51,210,106,85,7,250,158,77,16,202,163,13,178,203,137,23,164,246,201,138,203,55,161,158,171,140,250,67,246,214,29,121,232,252,237,
70,90,225,193,191,222,33,61,244,89,31,199,97,116,173,243,231,193,213,23,142,237,51,233,170,128,167,11,23,24,68,159,143,45,32,37,45,167,15,110,181,211,231,25,158,250,51,6,56,91,222,85,28,74,13,143,81,168,
49,44,227,123,68,24,6,55,91,207,222,150,202,159,123,13,234,181,57,97,6,39,98,245,187,11,211,132,250,215,83,187,126,148,46,175,236,167,141,183,56,19,12,215,131,124,229,27,14,68,180,86,156,183,152,57,29,
214,10,224,78,176,176,37,22,223,182,20,143,142,180,229,104,91,72,15,155,82,166,111,129,115,226,177,131,51,42,15,214,60,60,152,103,105,1,196,165,90,116,92,144,205,63,182,1,35,191,87,195,80,142,199,202,
159,184,216,134,247,153,178,233,122,240,95,65,60,181,86,187,162,35,249,142,195,173,119,108,52,196,154,137,204,22,22,79,188,20,9,150,51,58,223,242,44,242,7,90,131,134,95,37,158,226,3,39,27,33,8,160,12,
214,56,32,34,226,134,71,153,67,191,183,197,143,103,168,252,200,169,109,40,255,202,128,186,249,86,60,40,16,92,66,188,35,230,139,206,5,179,172,119,46,180,175,133,121,208,113,155,151,224,65,189,117,164,100,
10,88,201,14,118,102,68,211,53,15,142,37,7,167,140,81,13,234,191,235,66,22,41,132,58,60,110,20,113,43,61,68,20,201,151,57,228,142,158,116,146,245,113,184,23,120,152,32,129,218,145,55,4,76,34,126,45,90,
231,128,173,249,240,12,86,118,95,154,169,109,135,92,215,105,162,74,180,81,112,72,107,158,65,48,187,45,39,189,26,100,26,212,208,51,80,232,132,26,99,141,7,138,230,207,115,181,190,57,37,86,59,218,102,50,
50,37,94,223,57,116,15,17,152,125,245,21,223,107,80,90,57,195,70,34,228,197,115,140,83,110,67,195,51,94,127,133,72,227,13,15,187,70,135,232,238,237,212,95,92,21,82,232,16,129,93,110,138,249,246,173,99,
15,42,41,57,225,115,212,65,47,15,231,165,57,90,233,241,185,134,58,204,71,211,111,252,222,113,250,153,15,126,100,34,46,136,166,98,57,7,163,224,240,134,18,167,15,254,6,36,15,57,97,84,8,13,36,174,39,51,92,
121,226,99,198,233,183,110,108,165,63,114,33,165,199,103,215,38,161,77,38,127,236,190,136,58,172,111,52,46,155,195,7,68,125,238,169,245,184,136,173,88,96,33,23,29,180,57,63,51,35,46,61,7,81,98,2,64,150,
64,102,95,254,248,220,198,124,39,35,181,58,75,152,80,18,122,48,198,207,216,155,55,100,7,240,75,233,211,32,119,91,252,191,104,12,34,64,98,159,205,165,43,210,67,59,135,253,180,43,148,152,158,149,78,1,135,
71,4,30,69,123,183,66,123,189,86,144,106,225,28,14,193,242,133,72,17,78,173,211,1,139,55,77,107,171,157,237,164,63,246,30,149,46,107,66,184,246,171,138,181,175,174,250,215,246,111,249,72,212,215,85,12,
68,120,94,21,19,237,232,71,90,211,53,174,236,84,244,108,252,54,235,182,41,217,143,217,158,104,69,111,147,161,169,253,50,222,14,177,197,91,44,139,127,58,225,97,253,127,127,188,34,238,244,64,236,212,60,
2,168,175,135,45,94,134,21,182,57,142,197,162,60,83,205,67,43,202,23,110,238,221,78,13,127,206,91,177,62,40,122,202,179,69,237,104,52,242,186,65,36,61,176,41,131,28,138,126,173,121,132,193,239,51,206,
174,84,163,41,113,72,84,129,206,44,121,200,234,68,115,226,150,138,67,80,23,175,77,137,25,163,119,107,28,184,16,72,180,225,218,16,54,248,95,15,79,74,193,95,206,195,227,58,48,123,88,204,2,143,87,112,13,
103,24,218,225,157,59,105,37,187,150,10,96,232,57,189,105,63,32,59,239,88,209,5,97,0,57,12,176,199,179,98,241,62,150,181,41,14,201,205,40,165,115,221,253,45,196,78,232,106,145,24,209,81,33,195,184,28,
128,190,33,186,239,186,7,137,40,185,53,198,142,110,182,24,132,149,248,175,160,56,185,98,189,42,14,100,248,153,30,116,194,209,77,12,144,101,181,65,172,63,212,17,61,132,91,138,95,115,32,111,79,12,118,182,
98,205,133,33,55,117,105,104,44,177,238,54,181,79,244,245,213,87,188,205,166,202,160,10,50,239,168,115,64,102,24,141,64,95,59,192,214,252,76,43,154,240,150,67,6,108,158,124,47,135,65,61,117,40,51,66,143,
117,37,124,187,134,26,109,30,221,178,246,213,52,143,77,158,195,106,166,210,197,244,183,63,248,92,250,237,23,110,76,158,71,25,113,19,175,240,146,33,132,8,190,226,213,235,120,253,90,254,223,215,85,103,248,
127,249,206,118,250,145,183,93,75,151,175,95,76,3,50,191,69,251,79,166,57,221,118,15,151,5,40,23,180,208,212,127,65,204,174,157,233,74,49,109,120,150,199,144,149,38,13,140,186,24,215,97,61,99,76,14,56,
149,83,161,143,170,62,6,61,74,192,70,105,117,21,4,54,254,226,218,133,21,193,211,48,189,123,89,61,175,246,162,121,69,238,83,151,114,233,37,7,183,233,153,62,77,144,112,10,193,229,71,116,228,214,37,166,3,
92,113,16,203,152,242,14,46,224,89,70,55,226,222,185,43,143,154,55,202,131,75,251,212,206,15,210,27,181,191,121,242,157,215,173,5,68,123,206,210,62,192,87,62,242,144,21,155,72,245,172,248,204,38,31,162,
191,81,253,125,27,102,79,78,40,202,182,162,74,229,24,124,232,171,140,232,56,80,121,65,224,220,134,135,93,220,102,61,89,75,234,11,109,79,45,142,110,119,44,78,0,241,25,21,245,37,208,35,195,34,13,73,3,103,
88,252,101,69,208,7,113,88,192,216,188,228,124,95,92,184,45,94,88,85,25,82,228,253,194,11,181,163,67,58,139,22,173,62,130,92,202,72,188,71,97,236,18,249,91,193,67,9,72,91,232,137,33,120,218,247,190,237,
77,233,244,126,61,237,208,233,170,65,153,192,231,152,95,210,117,170,171,84,66,49,111,114,228,125,186,14,145,157,206,130,135,114,9,236,161,240,137,38,87,35,21,31,93,7,255,210,83,88,88,15,170,167,122,163,
99,4,195,242,50,221,39,175,116,134,197,238,249,247,208,199,135,16,127,94,117,198,158,153,41,67,155,190,100,131,55,165,61,2,122,203,253,200,221,185,214,48,84,16,92,215,53,186,92,113,55,213,144,107,46,33,
188,122,172,112,181,111,38,167,84,194,128,200,191,66,148,30,70,98,191,33,46,179,41,25,243,116,46,158,28,195,228,51,242,109,161,42,218,181,73,206,121,239,163,177,2,54,170,161,117,121,199,162,181,62,60,
212,194,146,136,123,181,124,37,253,161,183,190,61,253,139,207,124,113,210,122,52,58,26,188,6,45,252,241,154,57,195,116,231,104,88,207,120,180,168,200,96,11,210,167,49,167,239,100,80,46,23,46,165,161,245,
110,131,210,5,135,49,203,243,31,50,162,221,210,166,54,30,154,113,157,34,5,85,169,108,88,179,57,44,229,207,255,238,167,210,135,158,127,105,242,252,67,96,49,210,48,45,94,49,153,45,116,205,81,196,204,145,
11,13,2,198,190,250,249,49,84,234,245,215,164,84,205,125,214,197,208,191,121,231,126,250,73,29,224,159,120,115,37,125,254,121,125,128,111,238,40,85,43,164,117,41,128,43,82,51,179,134,14,207,89,199,115,
97,214,22,15,127,215,251,7,122,121,196,73,124,101,7,137,133,200,139,233,110,17,190,7,203,219,84,103,27,159,180,227,94,182,21,63,212,116,154,152,49,141,224,105,123,238,33,21,62,35,92,202,194,66,63,173,
217,7,43,235,43,246,128,94,79,188,42,129,24,4,33,236,210,6,100,68,118,248,107,119,140,106,116,168,43,57,109,116,144,79,219,135,140,47,182,250,122,134,218,73,42,234,209,37,239,173,69,235,176,219,233,146,
248,221,121,253,222,30,196,159,116,1,18,255,130,241,1,75,63,194,106,45,178,97,129,209,99,108,123,78,87,188,130,184,169,66,84,92,147,46,176,99,85,147,232,20,112,223,226,99,78,31,190,140,81,179,33,35,51,
24,227,216,243,224,193,20,239,16,205,164,191,160,10,33,160,215,12,245,77,157,59,232,105,128,59,84,245,192,63,217,140,252,180,60,86,86,220,178,110,94,230,148,152,35,19,80,153,32,126,15,156,89,86,218,181,
40,161,216,15,134,53,146,246,226,214,169,152,95,130,76,105,25,37,176,62,47,176,71,100,172,139,169,198,20,31,75,51,75,152,101,135,37,0,35,163,50,229,192,23,80,238,156,164,210,175,46,175,40,86,197,2,118,
64,232,30,120,157,1,181,114,61,16,151,151,14,43,60,123,153,194,196,3,238,200,247,182,121,154,30,107,125,174,21,72,23,59,154,97,181,115,65,12,137,247,186,60,216,200,155,14,88,217,145,158,62,121,222,122,
9,178,40,242,6,219,186,225,157,216,164,171,92,224,67,139,188,186,140,200,156,239,1,145,62,11,193,98,253,78,40,104,162,106,34,214,138,175,97,24,28,224,240,140,28,142,26,8,70,200,189,130,105,103,188,106,
199,154,132,212,176,220,83,211,233,167,203,114,16,121,8,38,43,6,159,247,59,143,225,9,150,141,33,188,236,48,204,33,176,70,222,63,230,109,190,62,171,147,75,180,235,202,186,40,196,193,33,201,196,21,132,216,
64,87,187,116,186,197,152,48,184,181,170,146,63,165,107,103,247,246,82,85,233,217,6,99,149,67,234,68,125,104,86,40,82,92,84,197,162,252,234,34,213,216,80,218,235,51,207,191,56,113,140,89,6,216,170,76,
160,244,164,251,130,43,205,217,27,35,53,145,17,251,230,41,126,242,136,155,24,248,68,176,133,245,126,117,235,2,78,14,213,171,127,127,113,151,36,80,138,231,13,239,122,36,213,140,136,232,50,76,5,34,135,190,
206,135,69,121,246,85,21,56,251,138,222,239,128,255,71,254,140,146,180,224,154,114,78,99,77,124,94,198,128,231,20,168,199,243,27,11,59,142,229,66,219,33,185,28,207,43,92,16,242,136,171,235,114,197,135,
246,226,160,30,52,100,55,221,166,231,222,97,108,235,114,177,119,49,212,103,44,85,31,207,82,214,149,33,34,152,95,121,105,55,253,39,33,220,109,136,160,44,239,115,213,51,42,18,157,148,180,215,89,80,204,17,
253,160,10,138,25,10,42,96,78,238,109,222,155,159,127,203,95,125,16,135,242,245,247,204,86,131,216,96,173,200,107,73,224,60,52,52,119,228,27,135,244,149,53,7,49,132,223,37,208,225,162,24,44,160,214,88,
55,240,168,245,108,222,213,64,138,53,139,158,59,89,61,136,198,32,70,183,191,56,233,67,116,247,104,62,253,210,38,125,44,150,173,74,4,208,23,239,228,163,148,7,27,91,176,185,42,160,68,116,181,235,241,60,
89,204,90,85,46,181,69,49,19,224,143,26,214,38,158,145,123,194,180,177,110,101,15,169,13,134,120,54,147,56,198,143,120,72,133,116,99,247,56,125,240,55,126,87,60,122,162,131,2,111,195,27,151,121,198,170,
3,178,96,211,143,5,49,77,169,144,190,242,176,201,144,89,15,36,154,65,71,189,165,70,11,24,89,12,166,235,155,182,209,22,31,189,110,61,228,103,29,92,116,175,191,74,225,240,198,71,54,53,149,169,116,9,196,
64,162,215,85,148,61,63,81,27,241,146,80,65,158,81,27,27,70,59,83,218,208,136,153,81,96,24,108,63,202,38,13,186,185,137,232,123,228,109,21,244,234,84,199,232,144,19,72,209,16,14,40,80,239,70,9,30,230,
57,166,148,117,252,91,212,151,102,232,89,139,21,68,140,144,162,33,190,141,166,88,151,92,207,170,4,255,134,245,237,40,90,239,209,157,54,155,243,169,69,164,222,114,224,78,149,183,93,35,233,99,114,192,64,
135,3,97,19,135,4,248,240,69,221,130,209,44,64,30,111,102,112,42,57,117,161,163,187,244,177,187,188,188,152,11,188,238,136,233,98,38,103,125,83,227,174,112,229,43,21,242,71,222,95,223,161,249,188,244,
18,70,170,164,66,231,243,47,125,69,44,175,18,197,105,155,8,237,195,160,250,98,173,188,23,166,53,210,32,172,204,152,49,141,175,72,179,65,130,147,41,219,66,207,255,252,18,174,79,94,65,2,22,117,42,120,241,
121,72,132,248,127,85,218,107,154,170,108,151,151,127,165,217,74,47,212,155,233,37,66,130,57,107,250,244,106,53,61,202,88,246,105,147,239,159,230,211,181,149,141,84,96,52,119,165,146,78,197,87,119,20,
208,247,17,104,51,140,121,84,248,196,76,151,140,248,182,7,121,144,3,219,159,164,126,88,218,75,134,26,203,200,34,31,145,110,98,216,8,197,162,84,240,99,123,131,244,55,183,234,233,87,117,164,40,174,188,69,
105,157,226,109,70,63,196,22,150,91,42,113,37,245,86,175,79,98,254,94,115,135,32,196,125,198,100,170,7,252,202,142,196,149,104,77,55,176,74,13,82,72,251,220,119,85,226,117,25,124,154,67,212,100,192,209,
30,66,98,143,186,99,63,88,72,144,118,154,149,155,203,69,183,119,20,191,213,30,41,118,142,222,191,77,208,171,189,152,75,143,208,188,254,209,235,210,36,44,91,103,83,7,61,158,34,154,47,87,109,114,32,106,
210,5,125,190,186,38,61,80,214,203,71,219,72,27,169,72,80,94,64,157,47,59,44,61,112,246,68,66,63,171,82,163,26,48,154,167,170,176,166,145,30,8,18,163,48,88,212,32,11,4,90,89,18,199,130,56,224,75,244,31,
138,26,201,134,127,175,219,196,240,245,68,172,28,57,211,150,205,31,144,39,14,94,19,228,202,50,223,211,54,84,244,243,137,84,80,65,57,85,14,249,49,98,149,7,14,230,188,11,186,90,150,255,26,171,7,213,116,
43,199,172,22,164,21,50,154,97,77,241,246,101,68,87,195,198,14,115,59,158,58,114,31,209,115,72,175,215,18,130,0,158,221,211,196,250,128,247,139,126,181,89,135,240,72,76,56,3,10,93,65,245,207,168,130,9,
143,29,92,113,133,7,24,58,136,121,135,98,104,125,122,24,204,98,36,70,181,139,9,175,111,234,12,13,172,43,215,196,186,0,130,69,173,100,213,70,43,96,52,111,144,246,189,44,36,201,20,77,248,138,190,161,175,
222,161,63,227,36,248,255,184,54,49,88,120,176,161,231,212,218,219,18,54,8,53,24,141,34,148,210,59,56,78,183,95,209,42,68,141,235,112,77,31,221,209,33,138,122,159,151,65,224,32,10,162,92,111,6,196,15,
121,225,158,110,16,31,188,29,34,24,251,36,112,107,188,55,131,27,95,93,12,103,180,98,233,131,1,129,126,162,19,98,196,160,145,22,130,5,34,171,2,13,248,213,215,94,97,128,131,68,138,10,160,173,123,237,116,
36,86,127,206,53,239,78,45,166,195,220,92,122,129,103,187,111,42,56,213,30,201,158,126,64,214,71,128,159,174,128,167,87,202,60,150,229,56,22,111,111,65,5,95,38,217,220,245,207,57,70,117,207,122,31,158,
58,56,71,58,3,250,247,3,247,221,100,128,230,121,193,105,194,142,195,94,61,237,106,140,156,65,92,105,157,6,121,204,147,115,202,253,50,182,31,116,88,95,140,80,199,148,131,132,161,221,49,116,233,84,136,112,
232,126,74,17,155,68,129,135,182,164,111,182,38,43,33,172,41,223,231,32,94,179,50,175,223,216,3,248,51,59,128,207,247,118,20,77,99,23,43,160,97,129,23,106,79,91,108,179,42,167,174,24,99,39,193,88,83,68,
253,155,175,236,164,231,118,162,50,1,36,181,113,206,16,5,85,55,87,2,59,224,8,15,205,3,227,5,76,123,37,154,111,167,119,173,97,216,252,123,29,145,49,37,223,88,147,115,41,160,238,249,42,157,198,17,78,136,
136,166,152,112,204,114,23,98,115,58,164,67,9,165,96,236,50,180,190,213,216,160,197,69,157,232,196,194,81,244,187,28,27,209,7,243,2,125,13,158,130,121,139,66,240,30,203,30,163,3,34,206,203,199,198,211,
188,40,199,120,140,88,68,178,95,63,163,19,130,135,55,244,128,243,30,132,15,176,183,196,179,98,192,144,143,213,193,184,130,150,38,61,73,251,190,92,222,185,84,192,57,207,220,241,32,112,38,62,219,3,117,24,
162,188,104,50,40,137,151,111,131,184,75,8,164,41,63,147,181,41,186,226,185,58,99,49,81,5,185,190,146,118,36,5,94,123,209,3,43,243,184,122,121,137,127,160,18,70,98,33,188,13,214,182,38,111,23,233,137,
40,2,96,232,173,159,88,12,252,219,117,88,198,4,249,83,104,214,18,230,145,131,79,43,170,131,58,80,77,78,119,246,2,166,121,172,16,226,198,157,227,116,162,33,114,193,189,204,170,127,156,224,197,240,98,32,
105,124,69,165,76,16,73,125,155,174,225,116,28,30,72,180,35,134,22,107,24,91,200,164,162,103,108,193,181,175,128,189,49,75,115,23,178,217,164,130,154,150,2,122,82,89,224,236,37,170,167,21,186,234,43,202,
204,164,15,238,237,238,91,250,223,239,44,92,152,195,26,145,71,192,87,32,98,242,66,182,78,160,108,120,238,9,202,241,231,228,103,226,231,124,197,191,199,239,13,28,206,61,109,79,142,145,21,29,169,172,138,
17,32,89,188,198,186,103,184,68,107,124,77,216,80,27,94,68,248,184,31,12,107,176,10,101,169,148,181,41,226,127,130,142,43,28,192,91,197,136,15,177,101,215,172,27,127,152,234,80,204,177,125,117,81,186,
109,214,17,108,146,135,214,79,52,123,97,0,92,126,218,60,132,172,24,230,154,144,167,65,34,122,136,240,219,69,22,206,151,102,53,127,211,11,2,239,49,117,178,153,158,210,212,251,15,95,144,23,21,158,76,113,
38,17,94,20,90,7,233,10,231,115,105,70,175,223,244,176,84,214,107,55,28,183,243,128,94,249,30,23,158,133,163,71,37,10,17,36,203,217,17,143,82,86,50,197,186,103,137,192,75,39,18,5,103,24,51,11,179,164,
121,244,153,42,148,89,94,114,168,107,94,211,102,123,163,133,9,175,50,206,173,72,38,223,208,110,16,221,237,251,237,221,104,182,69,137,33,231,217,138,18,46,184,244,84,90,98,36,14,152,241,89,167,209,47,87,
163,229,242,188,216,143,82,39,100,93,5,205,188,98,166,74,5,140,205,193,19,237,136,21,65,238,142,83,86,44,136,127,97,254,156,56,182,143,16,50,106,143,54,55,12,10,40,131,157,173,122,208,21,30,172,109,161,
91,226,192,22,47,220,129,10,162,45,198,116,116,10,148,70,105,58,136,37,52,127,89,222,46,106,67,51,96,110,40,141,242,43,23,38,121,198,174,78,229,51,44,230,20,35,112,198,251,246,139,82,75,188,245,64,219,
142,168,75,29,196,247,236,201,249,218,101,94,252,152,102,84,19,46,214,253,140,56,190,79,48,125,168,171,68,22,169,53,207,51,68,45,97,95,41,213,88,114,60,14,103,25,89,178,199,52,245,88,239,41,39,110,0,33,
12,141,143,232,17,95,56,6,136,43,105,35,41,148,130,116,71,38,102,132,134,92,60,54,178,28,51,27,198,200,105,194,38,37,84,142,38,97,212,85,11,163,61,144,52,70,249,105,245,168,17,88,74,47,251,98,216,60,139,
201,203,51,10,2,45,20,87,117,107,255,196,198,28,161,9,227,232,16,244,229,79,155,174,239,80,2,248,216,90,188,65,172,191,70,76,159,111,105,127,162,123,221,152,119,142,38,196,49,158,48,36,128,47,30,120,150,
140,75,41,148,39,94,209,189,33,14,88,188,66,195,59,154,224,86,249,103,78,38,94,209,170,51,188,104,104,219,57,89,104,231,213,239,199,127,39,24,198,175,22,89,164,171,111,121,43,38,21,79,176,163,10,70,26,
99,172,201,118,166,128,45,21,74,220,150,18,107,203,25,191,117,17,58,195,90,223,1,61,91,12,229,186,169,83,81,240,191,238,254,246,197,208,199,103,210,102,107,213,244,248,2,118,87,59,213,44,178,237,156,177,
45,58,240,45,242,199,115,107,182,64,33,245,112,97,53,189,34,21,184,125,116,162,237,40,166,157,65,61,98,136,166,162,34,137,83,122,255,163,115,105,251,192,88,18,93,3,191,113,3,223,161,78,121,147,10,44,26,
169,69,74,102,68,50,88,151,219,223,112,84,7,129,68,60,181,7,253,202,47,40,248,29,174,43,201,114,232,242,44,111,116,180,43,178,74,71,42,11,90,14,106,158,2,39,171,201,212,219,65,157,210,12,24,227,226,178,
14,207,20,77,40,224,79,249,99,46,38,41,156,190,1,172,34,146,135,92,204,164,90,76,140,7,215,136,182,17,54,208,137,120,4,245,60,139,221,155,3,61,71,54,112,244,182,13,107,25,121,23,35,85,148,103,201,89,33,
148,74,44,90,150,247,218,7,243,86,145,69,49,207,227,208,96,161,171,65,48,120,216,177,37,226,225,71,29,94,150,183,15,214,176,34,110,238,178,234,141,136,143,192,172,156,17,9,57,222,47,114,182,121,41,26,
91,222,166,151,1,194,168,102,145,14,69,15,244,60,250,228,240,246,107,114,106,37,191,23,141,152,73,3,52,184,2,47,197,162,168,104,240,118,94,183,128,232,248,119,46,63,198,96,128,204,49,180,40,222,191,105,
243,21,220,91,49,88,96,173,25,103,93,195,158,238,12,88,9,215,108,99,1,17,33,76,200,53,136,60,120,216,2,116,17,36,145,163,38,110,183,247,65,218,128,243,121,191,23,132,19,206,131,81,242,31,101,236,101,58,
221,33,98,40,242,190,81,239,216,149,222,154,213,69,176,204,163,198,60,85,2,203,244,16,146,32,106,41,107,226,170,154,82,174,44,3,53,228,145,217,146,201,235,213,22,153,214,202,1,191,117,247,40,61,187,126,
113,82,117,81,61,185,151,182,221,111,87,122,65,185,50,200,45,166,206,174,167,217,139,83,114,169,98,46,6,174,74,119,155,51,169,108,231,185,157,180,82,83,188,44,60,121,245,21,158,51,98,248,176,26,95,245,
162,49,202,34,160,108,16,54,113,32,39,136,223,223,139,158,121,136,233,199,147,251,122,237,45,94,251,35,19,49,121,126,53,77,183,182,210,85,161,64,89,53,79,207,247,130,212,170,129,236,39,158,239,109,161,
211,6,117,213,26,165,79,200,51,247,164,65,134,20,59,69,121,219,179,93,123,73,37,201,208,94,233,129,165,125,63,75,82,148,54,112,35,123,154,201,173,42,108,184,170,22,179,227,193,23,33,169,204,142,131,136,
71,57,99,172,123,88,120,191,69,107,108,52,163,5,155,198,71,60,10,97,144,50,152,235,90,72,239,89,207,167,143,234,73,116,107,83,254,157,104,63,107,226,218,18,244,24,146,82,7,38,53,111,66,45,149,141,63,120,
67,15,224,255,178,81,25,210,12,193,1,242,165,9,232,119,53,189,138,110,226,132,18,224,82,196,67,122,192,130,32,37,27,174,10,14,100,177,89,125,193,127,14,189,60,199,122,53,114,117,228,134,157,237,37,131,
105,235,89,8,123,44,212,31,39,247,117,158,179,193,6,75,54,148,6,83,21,94,52,198,10,158,96,100,170,101,93,236,196,104,99,158,234,156,40,65,103,87,208,182,157,86,8,11,162,248,187,13,126,198,68,179,172,234,
250,21,101,94,203,52,156,40,75,102,88,138,67,23,192,101,20,123,85,60,148,65,161,207,34,32,162,95,76,211,245,76,90,75,58,168,3,222,175,224,186,71,32,111,244,159,13,226,106,236,48,215,121,157,182,107,136,
175,115,144,103,153,55,173,218,216,78,188,54,146,175,72,105,84,120,37,213,243,60,89,244,84,170,204,130,203,136,177,76,244,206,177,86,37,15,188,50,19,125,116,36,181,253,78,217,195,219,160,216,169,4,177,
132,180,89,119,208,106,160,103,9,83,59,37,143,9,189,78,56,166,172,235,9,116,224,15,177,41,133,143,145,236,33,152,159,66,225,207,251,7,9,43,208,22,128,146,118,234,240,250,37,117,159,53,39,171,68,247,27,
213,64,17,43,118,90,11,72,16,136,5,18,153,71,64,249,6,50,228,118,186,116,233,90,122,226,162,156,33,131,55,142,240,34,30,192,107,47,36,112,186,135,153,250,208,221,77,93,5,27,72,149,45,169,12,18,74,77,185,
158,20,106,92,110,235,47,235,52,53,54,143,200,227,52,215,170,239,165,189,151,79,210,126,32,31,240,112,222,250,229,187,92,247,228,69,23,253,26,225,20,226,130,129,120,63,72,168,156,155,156,64,87,143,39,
66,210,24,161,17,16,56,148,83,3,12,249,235,175,188,131,84,136,222,43,94,211,226,246,58,228,208,141,160,223,250,23,188,239,90,127,30,124,196,185,83,118,173,186,238,96,216,95,56,205,166,23,41,57,142,60,
7,11,42,63,109,214,167,61,211,152,213,114,148,72,165,207,152,220,210,207,106,76,224,207,93,167,166,116,76,228,92,183,25,224,155,98,230,168,198,105,219,47,7,158,203,80,28,60,79,204,81,19,90,68,13,107,129,
151,14,33,67,116,171,216,129,228,142,235,14,60,230,125,168,150,246,136,119,236,197,193,134,124,242,172,232,53,240,229,218,42,82,80,54,99,107,203,117,79,193,201,15,248,149,237,179,76,45,50,184,232,98,48,
20,36,53,220,152,97,142,172,133,4,173,96,184,104,96,77,187,120,134,217,10,138,156,208,90,23,239,186,135,127,196,67,244,108,162,24,142,99,55,76,46,115,204,114,135,165,28,57,76,109,113,99,155,36,112,249,
194,101,77,125,149,129,241,20,103,44,253,185,155,12,24,90,150,204,45,10,246,251,177,81,164,74,162,225,82,9,193,209,194,130,158,129,168,211,220,76,108,182,76,206,65,176,1,118,253,88,196,127,3,194,230,38,
118,143,15,209,104,75,135,114,177,216,228,239,32,88,209,195,174,217,224,83,113,10,226,112,235,223,83,225,5,43,129,11,221,87,129,20,43,215,167,128,162,120,41,35,132,68,202,41,171,251,96,33,32,149,253,124,
242,202,238,132,84,138,49,15,37,15,51,24,208,86,187,170,187,195,76,218,101,8,90,152,65,41,78,15,205,3,228,5,199,54,152,20,45,195,160,230,212,55,54,108,190,154,88,189,163,196,109,4,150,69,243,103,103,150,
101,103,212,49,182,251,126,247,174,226,237,157,19,49,15,248,116,206,59,156,219,84,209,237,61,90,122,70,199,151,156,186,176,89,198,169,195,245,14,208,253,83,214,241,189,183,92,102,0,0,32,0,73,68,65,84,
44,163,126,211,161,235,64,55,231,238,173,239,103,203,224,230,162,92,114,159,134,116,117,173,158,126,236,91,159,98,4,120,79,107,25,44,234,235,115,59,195,155,197,82,156,216,168,21,234,154,136,223,103,11,
235,32,191,46,237,112,232,213,252,134,246,161,170,132,238,157,168,135,36,111,99,176,158,211,82,115,75,226,253,28,83,250,74,121,223,53,239,189,250,124,173,109,40,145,38,233,147,240,136,129,26,60,179,104,
5,50,68,206,188,206,208,70,171,73,167,214,146,135,215,12,172,243,234,43,14,116,40,136,226,245,228,195,235,233,178,185,47,61,6,232,64,77,102,87,216,49,27,234,141,57,109,90,160,181,120,118,250,192,167,6,
71,241,9,5,208,251,194,129,43,193,131,184,33,5,117,19,241,202,18,42,246,2,193,196,148,92,124,110,90,201,24,242,112,28,198,23,100,233,59,208,99,134,54,195,149,55,78,65,21,207,50,10,251,207,60,192,103,15,
119,116,131,220,65,182,165,244,5,207,66,159,64,233,184,118,90,181,95,67,151,253,252,65,39,61,43,23,76,82,147,54,232,159,59,144,90,223,243,60,211,210,117,102,6,218,250,134,37,237,87,30,154,220,199,131,
252,79,246,188,85,231,29,200,167,140,105,63,85,253,29,194,109,224,61,117,118,224,234,125,177,37,168,80,102,173,242,60,225,152,232,125,4,6,149,192,207,33,226,40,131,229,204,239,198,110,125,237,1,128,38,
115,68,214,211,44,242,28,169,222,245,117,59,152,238,177,181,173,97,22,122,164,6,14,175,104,201,184,172,88,59,154,95,237,136,209,78,165,19,174,128,10,87,88,180,60,248,208,246,80,170,163,86,154,81,108,29,
181,155,67,58,223,232,36,222,197,214,101,193,232,66,180,136,196,232,101,48,143,231,190,191,41,142,144,154,228,89,64,26,139,88,169,74,26,243,160,225,204,51,54,125,153,33,9,193,64,180,60,28,243,246,43,186,
44,172,176,236,21,112,57,6,237,214,46,176,214,136,150,96,106,207,119,197,53,60,215,233,249,81,154,146,243,173,31,51,88,14,169,57,27,169,35,246,11,239,91,176,25,74,148,64,51,160,225,108,136,252,193,234,
130,150,29,35,20,126,120,223,51,24,29,11,15,142,130,182,136,174,44,232,30,250,166,150,53,58,115,64,123,152,241,168,193,28,232,142,208,112,56,39,223,119,130,203,158,1,201,45,3,32,30,181,164,81,192,158,
245,115,67,228,218,57,168,94,245,222,5,36,206,140,220,43,154,141,12,82,234,105,25,178,193,170,143,182,14,211,119,191,241,109,58,202,128,121,28,145,125,232,37,238,155,24,205,240,98,136,38,221,44,122,234,
47,155,144,79,179,79,47,75,133,117,235,184,43,185,127,154,190,180,221,208,87,184,62,233,195,148,63,233,210,175,214,49,169,47,243,102,114,169,79,93,25,255,201,31,254,145,214,170,152,116,96,141,94,39,156,
10,88,251,104,84,45,241,56,73,221,4,43,28,57,205,240,160,153,16,40,56,248,241,185,175,127,197,53,189,74,6,5,244,117,111,214,239,109,96,233,99,209,198,197,179,238,168,199,61,243,94,222,204,97,112,216,196,
130,101,196,97,72,255,154,60,247,0,241,245,120,116,171,208,70,103,134,145,220,39,110,57,21,61,69,151,193,121,8,107,70,124,121,249,53,47,55,36,76,95,187,228,25,243,182,77,14,163,140,97,93,245,12,103,52,
19,91,87,60,113,1,127,49,15,62,247,132,40,99,164,208,53,176,119,209,94,96,14,173,155,102,119,212,95,219,248,247,243,153,11,122,230,30,64,0,24,121,183,154,17,66,92,198,62,173,95,187,12,205,4,221,247,96,
95,217,57,77,141,71,70,182,15,16,7,179,42,220,43,83,166,65,19,29,68,171,70,14,66,185,144,197,195,22,222,245,51,103,186,20,140,28,214,166,0,169,162,152,182,7,47,198,168,192,1,136,20,175,104,232,27,172,
221,80,26,99,16,73,251,128,40,240,127,228,52,59,67,237,48,88,210,62,173,235,25,143,208,85,199,55,119,46,171,26,12,27,175,120,164,168,213,54,154,16,50,51,72,134,170,164,234,41,151,51,16,251,45,89,148,96,
217,226,1,103,121,248,72,129,191,192,99,55,97,196,69,27,97,40,6,25,198,225,240,32,162,192,249,196,159,231,160,72,54,226,50,27,60,168,251,208,207,198,134,220,6,89,27,172,231,0,164,57,7,93,178,228,127,83,
177,169,29,166,174,196,252,178,251,152,230,157,134,172,112,86,79,162,57,213,44,40,41,29,21,162,239,44,154,134,247,143,158,232,45,100,197,128,177,138,116,82,145,215,103,95,196,66,4,13,72,166,85,21,46,213,
40,41,130,16,22,52,58,91,98,125,47,139,171,162,36,111,213,70,152,102,216,162,56,167,102,141,66,169,18,121,206,166,53,63,139,208,2,90,105,41,58,15,6,55,239,254,122,140,211,44,217,209,64,153,215,8,43,218,
103,108,114,226,187,62,18,237,76,76,159,37,138,111,110,30,166,230,206,221,116,149,152,158,10,96,178,193,173,148,59,225,65,39,12,46,15,231,255,94,180,177,143,24,214,94,251,158,117,26,96,139,197,95,82,103,
221,113,196,114,115,18,239,41,93,226,45,174,50,98,37,41,167,19,80,62,175,63,204,79,252,201,239,249,83,223,241,221,223,61,57,112,175,31,186,104,245,57,57,172,160,162,15,116,32,99,247,198,179,127,245,203,
55,39,241,39,39,143,148,115,37,238,37,14,106,244,139,125,211,91,158,84,0,253,120,90,189,122,89,218,75,40,35,8,175,197,231,81,80,213,113,15,135,144,215,125,236,241,52,230,253,9,21,82,223,115,185,154,222,
181,32,6,183,255,142,25,140,207,59,80,116,145,82,97,253,244,98,160,47,29,231,59,152,231,253,147,99,123,177,109,18,155,48,135,145,29,18,112,44,32,147,150,164,167,34,183,92,244,108,174,169,70,121,76,190,
115,99,126,144,174,35,243,254,202,155,214,210,123,47,199,61,120,14,66,168,232,250,24,57,209,37,134,55,203,48,215,162,51,69,176,184,14,67,213,172,218,47,127,236,56,109,63,115,87,131,52,144,233,1,191,178,
185,252,155,209,238,44,146,248,37,203,90,101,168,77,102,230,120,210,104,182,188,160,13,136,77,160,56,74,140,64,139,202,234,44,96,87,51,4,210,67,27,178,143,39,56,5,37,67,213,18,79,102,204,130,89,255,116,
12,42,180,141,192,235,134,23,68,10,212,242,154,48,17,9,183,227,112,42,26,27,97,122,107,60,229,69,15,237,58,121,89,70,160,210,243,228,214,53,170,94,182,193,131,72,232,56,32,21,177,192,140,248,44,27,121,
134,215,94,241,254,61,7,247,163,30,162,154,231,244,132,114,164,130,135,20,135,230,84,221,104,219,160,165,33,245,79,149,188,173,5,142,215,65,225,147,200,187,249,188,69,82,149,105,63,55,118,237,199,152,
217,200,113,13,208,241,89,198,160,39,54,58,243,253,185,133,57,149,255,26,72,251,160,54,38,245,172,25,49,138,92,153,225,57,69,63,151,3,229,163,231,81,151,39,30,233,135,59,4,171,13,164,14,172,107,147,191,
234,157,227,0,13,88,247,2,23,218,181,174,67,80,181,133,122,173,138,223,43,232,249,93,135,93,242,86,191,38,208,207,102,30,219,232,89,173,26,179,17,187,50,18,85,228,209,16,185,36,92,210,29,94,76,42,110,
47,129,92,33,107,62,39,8,241,147,166,118,71,167,9,34,113,191,123,171,126,108,6,76,62,125,255,31,253,6,39,130,177,178,217,255,96,187,76,222,213,254,59,17,18,188,253,138,138,126,107,236,105,165,45,234,153,
35,158,119,133,17,186,206,128,244,24,144,145,195,32,140,75,217,72,123,110,29,165,47,61,223,154,122,254,168,247,23,190,239,59,126,16,23,0,134,58,68,61,172,245,96,226,162,29,203,240,212,241,114,54,227,43,
212,64,56,191,201,87,172,225,235,175,80,20,197,228,239,248,94,83,121,220,163,23,244,233,185,117,144,62,119,107,151,226,102,197,47,232,59,197,56,93,182,87,22,121,204,150,67,91,204,30,36,13,9,210,155,86,
75,233,241,39,112,35,23,116,132,32,74,217,128,132,130,37,151,38,79,219,32,252,77,161,193,111,237,101,210,167,26,186,184,227,34,150,87,21,150,203,253,94,150,198,187,176,194,227,135,65,214,170,229,12,103,
113,95,215,139,74,101,63,93,190,98,116,195,44,49,255,60,68,34,246,159,7,247,139,126,183,199,203,94,180,255,47,11,165,166,161,137,232,194,183,136,249,125,108,29,132,190,50,159,190,240,59,247,210,225,141,
99,247,39,86,120,192,47,114,75,108,41,22,42,210,31,253,24,11,128,105,173,120,232,227,51,140,161,242,162,94,36,100,181,206,236,170,149,228,191,28,90,222,84,208,221,201,28,76,186,225,21,246,55,229,104,99,
119,122,54,145,124,100,242,163,207,108,81,5,197,42,129,248,136,5,60,69,67,55,88,255,152,46,61,114,128,66,102,159,225,33,50,32,223,61,117,137,135,132,202,203,148,67,25,79,250,132,144,181,174,81,23,253,
63,184,17,69,198,54,164,77,122,206,251,229,162,27,160,60,104,95,211,166,160,239,171,160,200,186,160,125,101,1,113,163,6,47,230,75,246,120,78,189,239,24,25,49,211,169,251,58,211,232,201,68,237,104,205,
95,17,183,205,57,76,225,37,163,113,216,48,20,78,124,69,89,156,227,66,193,103,135,74,157,169,84,174,159,181,145,248,200,136,125,106,188,102,196,164,187,226,227,44,17,193,148,107,15,214,181,228,0,230,122,
124,173,107,200,146,155,116,237,204,60,114,164,192,163,141,29,198,172,126,63,125,42,157,131,40,213,18,247,78,186,228,65,11,252,27,157,110,192,100,105,97,162,251,57,13,213,130,73,89,19,215,110,232,88,64,
238,42,158,71,40,177,222,11,116,185,57,27,55,134,233,46,57,208,53,2,238,142,88,171,33,215,123,170,73,152,27,76,185,109,248,174,179,157,190,233,155,30,74,239,186,200,163,7,44,150,235,244,166,241,88,24,
191,248,127,232,196,115,122,233,174,130,97,235,68,35,147,94,62,98,160,168,113,250,170,45,134,242,125,199,84,50,173,134,80,129,241,187,125,118,96,218,249,97,58,60,219,46,190,244,236,141,247,62,241,158,
183,166,31,252,209,63,55,233,134,49,17,25,240,66,89,95,244,126,214,9,76,247,153,108,224,255,247,87,120,83,70,36,14,102,15,123,94,153,94,117,0,30,73,95,250,240,151,113,4,88,254,64,3,16,78,201,65,169,56,
84,211,186,193,79,113,0,125,222,48,39,221,145,29,206,209,52,99,206,65,243,135,25,244,111,184,126,145,96,96,54,221,58,106,8,3,8,3,12,194,218,23,234,236,59,184,203,218,237,148,61,203,121,122,228,93,61,55,
239,236,41,7,131,22,208,249,100,157,90,171,184,239,145,102,115,247,161,150,104,28,112,231,94,51,237,33,52,66,144,127,19,82,251,245,77,45,98,239,8,233,72,45,99,106,65,27,255,49,212,12,108,122,153,163,48,
78,46,167,160,163,97,49,163,197,230,131,126,169,163,189,59,217,52,121,222,42,58,140,183,157,190,115,37,76,71,24,188,152,141,33,218,177,241,109,186,104,245,1,50,29,97,90,3,147,103,145,36,57,86,165,139,
21,27,131,157,97,54,115,69,58,153,53,201,9,191,63,142,60,168,49,227,147,174,230,146,248,33,0,143,150,30,13,65,121,214,102,175,7,67,8,71,253,7,194,226,103,17,21,83,114,168,125,121,206,6,235,60,22,63,230,
197,30,210,160,54,254,153,195,34,95,232,193,134,38,53,148,5,57,113,209,119,179,130,215,177,161,67,155,56,42,64,138,138,111,115,153,19,127,63,2,97,178,32,43,15,131,40,240,55,111,18,111,36,223,106,243,156,
243,178,101,239,55,171,46,112,28,105,23,36,195,72,143,219,81,227,38,98,137,2,211,38,190,45,86,13,170,255,162,221,52,47,247,219,115,32,123,54,207,72,227,227,42,100,49,109,70,230,34,99,48,99,19,13,67,18,
231,243,11,242,143,139,225,225,189,87,15,65,36,98,130,44,244,203,241,126,145,170,201,241,220,39,14,84,203,122,101,192,182,134,186,214,166,3,81,81,158,150,15,185,27,35,85,1,215,70,209,32,204,219,148,64,
226,144,60,142,125,69,223,237,188,88,57,230,99,78,73,125,229,105,65,169,174,197,160,116,201,74,216,230,64,181,157,189,253,212,184,213,74,111,120,244,106,60,10,104,40,82,30,113,64,45,156,151,112,157,145,
195,218,126,229,149,244,135,181,59,125,122,206,15,233,13,85,41,174,165,251,52,186,247,125,246,14,209,66,93,145,125,223,154,30,110,96,219,133,12,237,179,251,105,91,5,209,230,253,179,244,223,254,196,159,
219,249,214,183,191,247,215,103,232,164,35,93,18,95,195,96,141,145,107,5,70,185,0,121,132,16,132,221,252,3,95,161,42,138,161,190,241,181,161,171,253,183,127,203,251,176,195,119,211,201,141,175,16,19,200,
29,138,93,231,148,178,69,105,91,93,92,212,180,94,131,218,124,186,53,158,75,183,228,184,122,200,166,189,19,188,131,103,127,113,35,138,238,57,13,200,162,239,103,207,177,217,135,170,88,190,101,165,151,222,
127,193,122,210,10,15,154,218,183,134,129,101,48,151,215,76,168,131,246,46,196,51,147,14,155,6,183,142,234,8,205,251,140,17,14,228,52,12,52,65,74,23,167,208,148,59,159,225,181,47,219,55,211,140,123,6,
140,62,227,84,26,72,172,106,189,152,238,62,163,241,54,50,99,95,177,197,233,214,157,201,186,62,200,255,40,20,7,1,117,131,158,138,77,18,244,254,177,182,139,177,177,37,117,163,173,99,222,162,133,99,201,97,
87,91,118,201,14,202,241,72,145,244,57,56,20,45,64,226,217,219,66,44,137,100,58,136,218,59,87,110,21,185,69,86,190,51,43,31,106,140,244,140,131,127,46,15,21,221,223,99,6,100,143,40,96,42,187,132,216,153,
6,201,164,29,244,104,57,69,142,220,80,24,59,103,147,44,72,93,12,171,90,114,70,31,29,139,3,101,176,134,32,49,234,62,115,44,118,69,16,92,128,157,230,165,116,218,82,26,109,215,11,176,138,247,100,42,109,142,
134,239,23,125,78,109,204,163,228,13,99,114,104,67,112,31,80,44,146,224,99,135,104,198,6,202,248,204,232,214,48,105,52,140,28,136,150,39,7,54,198,11,82,70,71,224,232,28,72,61,102,81,155,4,211,29,221,209,
139,212,80,209,157,237,62,2,227,232,212,251,121,251,1,152,57,64,218,52,193,160,172,207,12,61,107,142,66,168,134,113,156,49,218,98,193,12,203,28,205,232,16,52,46,72,240,203,196,40,153,67,60,41,50,86,151,
167,46,86,12,143,149,158,149,243,104,242,32,119,165,22,186,254,126,38,134,171,179,220,125,108,115,155,241,11,152,219,114,45,57,215,206,214,77,122,175,142,8,53,78,197,189,77,198,110,159,80,125,107,55,165,
239,124,255,15,166,121,83,181,122,114,178,114,63,246,78,28,206,48,26,190,252,253,0,54,238,234,19,252,238,13,70,238,236,14,207,8,62,135,140,145,4,243,12,193,246,9,33,201,43,54,95,115,11,74,168,243,92,14,
196,222,246,110,250,205,223,248,205,244,202,243,219,181,255,235,63,254,226,213,191,253,51,127,39,61,252,232,37,225,134,248,31,10,9,168,219,199,178,199,204,153,64,52,191,31,206,198,230,141,159,113,222,
211,55,191,113,35,253,145,119,61,150,30,49,84,169,126,122,83,11,154,24,35,168,206,21,172,124,89,255,225,3,159,85,241,60,163,139,99,43,164,164,226,249,182,89,47,3,100,207,24,139,60,214,9,161,199,81,12,
136,67,134,246,211,117,29,13,222,173,154,234,17,188,192,187,174,78,165,183,59,104,29,150,109,219,2,237,121,30,33,32,136,48,169,224,107,184,44,196,176,111,162,74,102,154,148,114,209,156,149,232,190,63,
187,36,53,198,200,5,121,86,192,107,108,112,72,11,208,196,227,186,54,4,146,219,223,39,186,89,94,76,171,239,186,164,119,19,71,229,61,27,228,153,157,195,255,31,60,103,177,114,213,230,137,60,19,184,161,97,
84,14,100,211,149,132,191,140,34,224,24,30,43,152,198,148,214,15,200,159,180,167,28,138,61,131,41,207,214,212,183,41,84,101,180,109,252,96,223,196,98,54,93,22,204,233,218,72,109,49,221,148,247,11,49,122,
215,6,96,136,236,13,85,14,177,73,193,156,40,49,58,35,96,136,60,101,129,204,239,52,191,15,251,7,123,134,146,103,44,202,14,245,50,207,172,108,128,215,4,73,24,145,178,70,196,99,6,32,54,216,174,77,92,135,
53,235,77,94,216,195,111,123,192,25,212,126,120,122,58,232,137,242,39,218,133,116,88,223,42,11,90,102,149,167,120,130,179,32,30,108,160,44,210,101,6,1,52,135,20,9,149,80,79,193,96,135,58,41,14,206,134,
0,173,236,112,12,229,26,251,160,112,116,178,23,226,76,54,227,16,204,157,70,207,23,202,23,228,120,165,100,120,199,240,154,101,136,35,164,102,245,16,9,80,70,149,149,125,181,28,144,54,242,105,251,60,10,211,
187,166,150,233,193,3,134,141,220,251,156,216,80,48,111,100,128,205,39,132,40,88,167,40,10,238,219,148,125,127,158,139,129,35,172,153,181,25,99,164,4,167,196,123,138,220,228,14,93,34,143,234,189,177,182,
103,24,216,30,105,89,225,200,65,123,238,102,186,160,203,223,7,158,190,28,103,130,167,10,118,85,108,22,95,158,103,126,98,136,82,250,63,254,237,231,49,209,140,49,164,115,126,250,18,92,17,202,39,57,98,196,
80,140,188,111,247,118,85,248,184,6,36,213,249,166,46,118,183,143,82,239,238,110,122,230,67,159,152,249,208,47,253,234,19,239,250,186,111,76,255,238,255,252,183,233,241,107,143,79,62,39,14,223,200,239,
91,49,198,9,145,136,31,12,49,194,235,175,96,92,93,186,3,135,224,122,252,235,210,213,71,175,164,69,34,217,53,233,142,17,141,235,115,208,200,158,142,239,187,211,139,6,47,185,78,235,246,16,235,249,190,11,
153,116,21,244,168,90,219,34,164,212,144,242,11,181,78,8,68,206,24,166,10,105,230,133,121,133,232,12,222,218,21,29,217,175,216,139,65,166,249,156,40,92,108,97,214,79,164,221,182,110,159,76,12,105,188,
207,44,75,223,179,239,122,140,209,178,251,159,10,188,31,214,223,243,152,138,2,118,97,83,204,163,137,230,219,147,58,89,123,179,3,246,222,250,202,221,52,179,66,143,171,45,106,20,6,244,35,196,122,192,175,
252,224,124,75,132,222,78,29,22,100,180,119,12,255,44,166,21,93,247,154,219,60,97,148,49,205,158,96,83,121,7,135,166,74,97,179,47,158,59,111,172,164,233,197,147,9,137,50,217,65,175,93,228,100,162,150,
96,251,80,60,85,163,85,220,191,235,129,241,42,133,21,147,192,212,134,30,144,2,70,199,181,162,207,24,19,171,215,196,101,211,44,95,147,85,95,150,159,83,219,130,161,5,77,124,127,81,156,113,72,108,28,13,153,
51,98,143,252,130,172,23,22,174,79,40,17,116,198,44,207,92,197,212,69,42,163,65,144,127,91,62,114,21,28,57,31,153,186,21,78,131,162,169,130,166,159,70,18,28,15,246,210,46,213,201,101,170,151,89,10,161,
170,152,58,226,88,54,136,97,242,172,5,101,101,112,120,41,14,166,195,29,105,12,125,221,210,174,121,35,5,117,141,215,102,117,102,184,175,85,8,178,224,220,87,73,254,44,114,188,67,15,113,137,119,106,49,20,
7,52,183,67,244,188,68,169,78,245,242,148,82,117,45,30,169,194,224,60,100,103,102,93,212,177,131,26,121,183,18,130,161,27,242,69,247,208,5,233,106,54,69,199,134,67,153,209,18,135,82,198,219,88,143,37,
197,134,147,74,22,161,68,19,203,93,142,207,36,158,103,11,76,61,11,105,94,168,144,252,156,247,156,54,181,123,243,228,249,244,220,75,203,233,39,191,239,219,193,220,227,244,209,27,59,19,101,148,189,58,121,
137,42,38,169,142,207,220,63,74,217,15,126,36,93,94,91,78,247,25,174,232,31,213,146,222,32,194,1,231,4,106,102,203,28,31,241,80,44,234,109,198,57,163,163,222,172,107,104,180,119,210,7,63,124,156,46,125,
121,55,125,224,225,210,164,124,240,213,119,182,109,228,120,131,216,27,4,106,98,88,2,218,254,254,87,168,165,54,158,124,119,250,209,31,255,239,211,249,231,62,146,14,112,21,29,104,236,132,208,60,111,88,111,
68,193,45,158,237,33,169,184,14,35,55,139,212,90,186,164,50,70,113,121,1,147,31,163,59,214,60,223,177,212,70,94,95,223,5,177,249,152,167,107,201,8,244,164,238,78,20,207,215,232,93,203,140,78,185,127,152,
214,176,229,33,143,140,230,78,211,12,64,201,33,67,188,50,140,61,163,42,120,122,121,159,232,43,205,223,167,35,247,31,109,77,47,81,9,61,34,116,10,245,86,84,164,228,24,149,133,202,188,245,217,74,71,47,169,
173,165,128,59,242,220,74,187,157,244,204,231,95,252,253,183,247,64,254,78,137,7,190,240,56,13,189,87,6,18,228,69,30,35,6,194,70,208,159,179,17,103,213,67,198,72,186,139,104,250,89,176,175,214,210,58,
2,145,147,179,51,10,168,111,123,104,146,112,143,120,112,140,57,75,198,163,103,196,54,61,184,31,232,212,56,203,134,176,43,90,103,34,58,94,136,140,0,194,178,57,109,230,99,70,65,154,114,18,151,14,169,94,
246,72,246,162,231,79,14,67,121,180,119,144,154,96,117,103,6,36,66,86,69,67,230,129,93,22,80,52,90,90,70,147,204,145,177,94,209,38,101,19,91,119,211,195,235,18,76,147,165,170,243,20,188,251,121,248,28,
212,62,181,168,96,8,139,24,137,125,193,24,139,235,225,32,40,4,134,169,44,31,27,106,150,246,190,34,115,237,77,198,238,249,168,116,170,40,156,49,81,146,84,21,135,76,249,123,131,204,174,65,126,56,17,233,
75,169,156,105,248,84,133,4,170,82,65,43,122,240,86,65,224,28,81,118,214,225,108,171,91,29,240,32,121,97,64,37,146,151,68,236,135,14,125,244,189,238,242,246,247,9,57,206,188,39,209,228,100,102,104,27,
172,173,75,13,116,173,125,77,29,235,148,175,80,204,157,133,48,132,161,153,120,76,197,224,55,153,236,159,21,43,253,227,45,133,216,210,66,167,214,178,231,80,196,104,97,93,55,88,127,169,167,237,47,165,133,
135,150,210,159,254,175,190,205,134,183,4,226,200,204,107,117,158,33,32,136,62,78,65,136,221,217,217,75,255,195,183,172,165,63,245,117,232,208,211,251,188,37,249,102,70,139,82,221,7,230,61,255,101,144,
124,62,224,14,66,174,43,220,176,220,19,146,42,20,194,143,182,95,78,71,95,250,56,165,204,221,9,106,118,38,189,39,97,6,181,85,158,161,129,195,236,133,175,238,215,16,247,255,192,15,124,219,225,255,242,151,
127,234,110,251,179,47,167,155,159,248,178,231,186,100,56,214,53,119,80,177,206,157,20,147,175,79,180,99,221,58,213,153,30,58,90,196,156,182,104,93,15,244,252,25,234,48,191,186,220,36,231,212,41,195,176,
229,109,247,145,69,24,229,100,25,138,132,13,27,213,245,84,127,165,148,118,94,144,146,113,176,38,237,113,220,67,1,79,114,241,42,163,119,21,39,33,207,25,7,145,230,39,93,185,120,149,150,55,46,90,154,44,196,
34,54,113,32,179,69,241,105,54,224,47,199,49,182,110,177,111,163,85,205,146,67,153,97,208,71,214,227,178,66,144,153,222,129,2,129,91,95,189,193,7,244,183,108,40,115,50,82,38,13,19,127,99,78,70,88,252,
83,57,204,49,11,29,93,13,26,39,54,53,182,54,116,6,49,134,126,73,207,155,114,228,144,144,24,39,112,253,182,77,230,236,128,53,200,31,76,226,217,158,141,5,30,70,207,215,130,116,70,28,242,174,106,128,57,7,
237,50,1,193,12,178,164,47,142,236,59,80,11,180,175,79,96,208,42,161,242,32,156,213,148,145,126,54,82,27,226,171,172,81,123,216,216,2,37,82,64,162,232,20,16,41,149,161,70,91,135,14,228,28,86,180,233,253,
159,67,210,140,197,14,139,216,215,5,186,216,53,169,145,188,60,162,230,119,136,21,164,11,6,245,72,165,199,188,67,22,6,100,143,110,117,211,223,43,172,228,148,248,97,154,142,50,38,101,159,75,182,70,233,83,
116,90,88,113,157,101,56,182,230,224,42,216,148,46,50,67,67,234,36,68,7,3,46,247,238,189,227,52,205,152,196,207,239,168,118,9,5,90,215,67,46,217,152,115,210,65,205,72,203,200,145,204,120,152,5,177,113,
93,108,154,197,236,134,184,182,2,125,84,177,218,69,247,18,93,246,8,128,52,183,246,251,88,73,153,76,170,39,13,214,120,179,16,151,231,163,38,209,247,75,208,196,140,95,159,145,100,191,232,119,230,92,195,
49,104,139,90,146,67,110,27,119,112,110,116,34,67,38,70,108,83,177,188,244,177,15,165,183,190,241,155,211,159,124,207,83,238,141,97,195,94,142,233,71,29,115,191,225,158,252,119,139,226,230,167,127,253,
203,233,10,111,248,253,111,90,114,188,21,53,199,88,71,185,238,58,210,236,108,120,215,251,111,153,8,185,73,134,185,155,94,48,1,169,66,143,156,57,59,75,191,242,217,23,210,127,243,203,191,65,54,199,171,122,
54,19,233,30,17,66,8,75,84,222,250,70,84,242,124,117,199,254,208,31,251,238,227,191,255,191,253,155,191,246,111,254,254,191,111,29,254,238,71,193,83,164,22,136,120,93,229,17,167,231,126,117,90,240,252,
79,144,102,47,104,172,21,242,204,115,162,151,67,41,151,27,168,235,70,119,74,21,16,33,12,113,76,87,249,26,119,153,230,22,53,132,6,125,243,194,140,113,239,56,117,52,131,182,37,211,30,34,224,21,33,216,233,
145,245,20,223,100,145,64,243,16,215,88,12,121,174,245,205,153,181,172,205,116,210,178,112,166,200,243,214,172,247,138,61,179,241,144,156,180,158,204,101,251,121,76,245,116,140,48,220,146,143,63,14,137,
34,120,245,34,132,182,191,147,75,23,24,226,249,69,229,147,117,155,238,1,191,56,30,18,54,48,110,136,224,105,5,124,10,23,159,193,169,74,0,247,156,186,28,247,63,89,103,214,62,218,136,84,88,216,136,45,186,
132,7,77,56,104,211,102,25,146,0,242,1,48,226,172,52,8,169,159,13,183,76,160,60,140,60,225,1,73,155,88,107,109,90,122,197,6,9,207,98,143,160,220,24,101,130,240,107,200,34,78,91,243,39,96,53,246,143,156,
105,78,172,151,83,136,59,111,138,78,13,195,39,253,230,97,139,213,252,189,199,219,46,216,196,209,127,182,40,38,21,197,166,171,146,198,51,165,134,186,195,56,96,72,9,238,102,164,224,121,17,19,185,100,151,
44,129,127,139,224,103,13,83,23,195,146,114,20,40,49,147,52,163,38,44,171,115,121,120,227,179,59,88,93,84,109,158,245,31,115,231,57,48,178,3,155,13,64,244,28,69,83,76,190,154,117,112,27,226,176,213,119,
191,35,45,191,239,81,17,95,64,124,85,56,160,165,140,167,223,247,187,106,255,106,106,81,217,89,243,69,65,52,105,164,105,6,162,44,121,120,162,128,56,202,224,46,202,89,198,140,203,12,3,24,26,114,217,172,
196,230,89,83,97,131,34,239,110,204,22,149,19,12,198,49,94,209,158,35,74,172,86,60,167,111,95,207,165,31,126,124,134,161,19,134,216,30,161,217,213,194,22,105,98,205,202,17,46,128,216,191,247,74,170,43,
255,250,155,127,255,47,165,111,253,250,199,132,36,177,38,78,145,20,87,104,99,195,163,68,60,245,11,159,220,76,127,241,95,126,54,125,242,11,52,197,42,134,250,12,233,145,33,78,209,50,52,186,50,156,116,55,
12,21,186,128,140,141,92,175,180,21,162,140,192,40,253,194,151,63,155,110,129,205,209,212,43,190,66,69,22,210,189,248,140,224,47,194,136,78,140,128,189,245,129,119,63,118,250,63,253,165,31,253,107,191,
246,79,255,237,159,111,55,238,61,89,124,234,74,170,235,124,80,3,51,87,231,29,74,6,176,38,180,121,84,58,239,17,196,205,213,117,195,163,180,187,137,230,90,125,21,68,55,164,139,78,25,242,172,61,86,100,52,
123,136,199,246,150,112,7,188,156,146,134,10,253,114,137,64,161,176,164,207,79,183,150,94,222,214,65,193,158,8,131,159,225,36,184,114,10,176,64,77,82,39,7,194,2,185,222,49,66,178,133,105,63,168,234,175,
132,116,212,6,210,51,199,226,190,162,43,188,102,2,43,38,189,69,201,89,8,90,0,50,121,242,126,122,126,231,196,160,97,104,209,115,90,45,25,129,88,171,92,253,173,15,254,171,255,249,213,39,244,96,254,155,61,
145,95,56,61,246,96,34,81,181,66,173,175,168,57,139,60,201,210,58,2,6,147,68,124,134,180,170,5,182,117,213,112,14,5,225,25,114,181,50,200,21,163,238,118,65,130,182,67,27,86,40,43,145,59,26,155,47,225,
208,237,139,232,250,147,24,203,166,208,38,243,196,2,55,24,128,104,23,209,212,42,178,236,253,135,3,99,224,88,245,5,177,173,6,227,98,22,217,183,120,176,122,203,198,156,148,10,111,59,39,230,140,222,58,57,
65,123,164,7,34,206,136,10,148,35,15,96,158,53,189,112,86,215,41,208,117,210,103,110,10,34,11,38,80,207,240,122,197,160,227,73,233,114,6,239,212,244,192,29,197,20,102,121,220,33,72,59,240,213,241,153,
89,202,160,41,19,204,66,178,56,112,168,87,165,24,198,20,82,247,61,120,50,10,80,8,67,44,85,160,205,15,88,173,67,128,172,119,149,252,240,178,57,32,57,70,108,78,156,136,2,195,86,34,198,108,164,200,145,198,
76,204,232,202,208,231,61,206,145,69,156,109,26,168,113,26,77,241,108,226,183,27,167,199,26,163,41,248,5,125,167,196,121,129,180,77,47,52,94,129,56,1,62,204,40,119,90,83,21,50,135,254,143,246,164,57,249,
181,18,168,214,231,153,198,144,194,164,205,74,144,119,188,234,180,13,125,226,62,226,25,124,150,134,241,215,205,22,125,137,120,187,119,82,72,207,252,234,127,72,135,157,245,225,79,253,212,79,252,199,171,
158,107,95,223,158,73,238,213,53,71,38,184,232,80,229,144,30,47,168,238,248,141,47,221,78,219,119,190,130,157,221,71,132,136,233,193,99,88,216,243,12,253,179,46,131,75,27,158,197,94,250,215,159,254,213,
244,47,62,252,17,157,243,25,106,136,32,26,122,197,33,140,194,234,72,179,217,245,62,67,154,195,77,133,33,253,192,215,95,63,254,177,31,255,211,127,163,55,122,252,207,20,203,75,215,231,174,189,217,58,99,
81,195,136,12,55,120,121,247,132,60,204,10,65,138,44,112,155,11,30,175,60,150,70,230,185,140,42,106,126,65,240,235,52,179,209,33,225,136,240,56,135,168,91,227,1,45,60,59,99,253,133,47,69,131,122,243,114,
216,101,70,180,103,125,163,157,233,69,103,178,7,81,13,25,161,190,61,219,218,103,253,16,72,27,43,58,75,200,83,150,53,168,142,83,86,177,199,206,241,21,193,138,111,30,152,138,38,119,215,11,50,15,139,124,
17,107,249,148,245,61,99,104,91,214,164,12,186,45,174,133,131,8,163,89,49,33,97,179,176,127,227,166,36,247,131,123,101,231,43,247,39,98,226,161,141,82,49,212,180,226,134,71,220,127,83,146,54,175,50,191,
32,206,58,157,120,76,185,183,56,136,60,209,57,241,120,95,60,87,112,80,215,195,122,191,118,125,17,103,84,120,131,18,101,79,127,188,39,102,157,69,107,117,121,197,134,141,98,170,136,3,218,67,144,204,88,152,
60,203,93,39,77,139,210,213,167,65,189,146,22,38,61,135,175,30,11,198,37,84,166,136,190,227,80,251,60,157,124,38,84,124,124,140,45,192,178,130,30,96,108,72,244,78,192,186,98,176,167,48,141,190,87,254,
63,34,11,94,175,179,47,189,208,226,221,244,232,225,173,207,79,169,68,168,135,88,128,9,43,124,126,66,2,147,7,231,230,31,17,115,75,151,8,254,43,30,220,162,188,91,3,92,139,33,61,171,44,115,142,198,54,171,
241,87,153,48,52,7,78,42,21,79,157,207,124,42,117,158,253,2,41,30,239,191,12,138,130,10,97,219,234,117,66,8,247,21,1,87,30,100,95,23,50,180,65,189,82,228,120,67,170,168,89,246,148,67,146,36,184,237,225,
116,159,65,136,131,137,128,21,18,88,60,215,217,34,57,220,146,26,105,66,5,209,121,112,90,236,147,219,151,8,23,26,68,131,174,192,145,29,221,10,6,126,169,125,2,134,219,80,139,138,217,159,192,90,94,226,121,
42,209,238,99,1,185,163,105,243,111,255,163,127,148,153,158,125,243,218,63,249,135,63,149,30,127,72,167,11,7,163,199,187,79,68,241,188,66,206,115,138,120,59,218,148,220,210,211,231,230,75,207,164,23,159,
121,38,213,111,191,140,13,86,169,4,50,170,65,74,157,187,7,233,99,31,250,245,244,194,87,94,246,179,77,207,194,241,102,20,194,11,71,85,202,56,210,71,177,111,172,225,235,194,246,111,124,231,227,71,255,240,
167,255,187,191,118,249,225,55,255,200,75,155,123,111,124,232,155,190,25,19,190,158,14,183,228,53,197,139,189,152,109,83,186,200,232,17,164,71,190,146,72,163,222,61,210,215,167,142,140,242,60,192,129,
11,118,199,67,24,220,83,50,194,142,245,172,98,74,151,164,218,178,170,70,94,6,119,143,192,248,140,67,212,145,3,142,25,51,167,16,211,18,99,184,206,136,205,48,180,85,34,150,27,184,139,155,251,202,16,113,
23,139,114,214,35,6,119,0,162,174,17,59,92,155,195,163,96,138,115,32,123,152,153,186,251,202,232,95,117,18,95,98,205,154,92,115,40,193,142,100,2,114,242,239,171,15,23,211,250,101,10,37,114,194,167,46,
247,210,83,111,235,126,231,243,159,255,197,183,190,182,253,191,230,127,228,115,46,120,8,38,196,204,139,3,138,160,162,250,69,243,31,38,177,79,217,130,84,64,235,115,16,102,8,214,92,4,55,171,130,240,69,194,
225,61,30,15,54,76,111,35,26,207,129,154,147,83,51,217,95,254,99,227,9,165,5,212,17,127,24,171,208,2,29,37,135,29,19,172,172,128,90,109,92,163,165,138,95,62,112,58,122,210,240,202,101,197,196,72,218,201,
65,67,156,99,232,244,148,213,8,184,199,66,46,56,180,83,228,101,17,63,197,7,5,136,158,231,153,58,4,10,109,205,160,143,21,61,175,47,147,216,17,204,156,117,143,245,26,69,171,7,145,69,96,16,189,101,230,169,
130,26,93,131,147,196,76,41,179,53,33,44,50,122,22,245,167,46,128,130,10,188,143,239,65,5,160,138,77,94,179,89,150,244,204,169,232,204,48,2,175,42,230,126,70,251,208,188,141,40,154,86,51,234,52,177,230,
133,150,217,44,177,201,84,116,236,201,251,182,21,168,15,73,252,242,188,246,185,164,124,140,251,107,187,238,208,34,87,4,86,25,6,232,64,158,114,101,66,44,104,8,198,99,230,65,175,51,196,78,196,160,101,198,
241,200,123,223,67,76,125,195,186,222,61,126,79,136,21,83,1,83,117,157,81,20,244,239,159,5,75,205,19,51,26,110,11,163,168,225,154,37,9,230,57,42,49,46,212,64,65,151,119,54,150,90,153,198,50,190,248,82,
246,51,63,247,139,239,252,142,191,248,67,233,231,255,249,133,143,252,228,159,253,203,223,248,241,231,239,106,234,134,252,17,227,133,108,145,195,231,240,88,7,247,22,77,180,23,255,9,253,0,0,32,0,73,68,65,
84,182,91,55,116,198,184,205,75,220,73,11,171,87,229,19,239,165,79,189,240,21,221,31,116,66,96,133,163,184,58,7,53,253,231,38,214,190,23,215,226,82,38,113,38,190,45,253,133,31,253,142,244,227,63,246,19,
255,186,95,186,244,99,219,95,185,247,196,13,147,169,199,207,127,202,228,49,226,133,251,142,65,60,83,132,205,8,209,18,45,98,122,178,1,121,147,197,47,79,71,219,209,108,250,162,103,216,97,120,123,16,68,71,
243,241,193,185,220,178,142,245,10,113,25,223,94,186,226,160,204,10,187,34,63,155,101,68,23,33,149,48,202,83,242,200,75,242,151,7,144,67,173,162,198,86,243,234,32,39,179,20,104,35,168,103,19,38,63,142,
209,31,80,91,223,72,63,118,207,78,243,2,141,251,54,95,8,219,99,166,78,17,60,14,71,84,139,90,94,104,40,231,128,54,78,82,250,196,23,244,180,93,102,220,165,122,250,163,181,84,187,87,91,203,175,229,108,170,
7,243,202,214,81,205,251,224,75,22,75,121,137,37,9,13,102,52,212,157,230,65,98,51,102,204,173,40,97,178,74,210,16,109,144,50,186,134,79,235,88,150,103,217,103,196,103,161,94,233,72,216,199,161,137,236,
210,156,139,207,131,108,240,32,246,23,197,97,35,132,183,139,60,82,36,231,129,187,180,211,60,74,221,163,104,208,76,32,62,35,151,202,155,118,108,236,69,204,231,36,190,44,74,130,11,196,7,164,132,75,42,11,
34,221,49,169,182,143,221,17,204,33,11,25,177,235,186,5,189,44,206,9,125,234,140,244,198,117,112,40,26,49,55,197,21,133,236,162,182,32,72,2,202,155,58,104,154,135,0,22,66,107,235,33,110,169,126,168,35,
189,98,102,166,109,149,78,73,20,59,188,101,91,169,87,67,236,54,141,153,206,35,165,38,147,212,106,209,160,140,135,67,78,180,221,195,17,136,19,196,201,152,225,26,137,69,162,174,181,234,128,142,49,215,161,
16,42,32,50,186,96,86,108,118,57,32,236,39,193,130,24,178,205,75,158,82,243,220,99,172,98,188,162,93,207,91,4,2,137,126,187,150,139,81,200,240,8,143,89,159,60,207,122,90,7,167,188,75,232,151,79,24,165,
168,96,17,6,210,39,139,241,121,217,136,125,106,225,165,217,200,24,54,219,0,1,79,156,180,151,241,4,123,13,69,196,158,91,181,188,157,206,110,124,56,125,252,231,127,215,102,95,235,253,131,159,253,167,233,
135,190,231,219,122,110,103,28,100,150,238,142,60,161,103,140,204,139,175,124,192,75,159,71,242,48,17,30,188,244,197,223,75,47,127,238,119,38,7,19,130,101,76,61,198,96,112,173,217,171,191,243,122,172,
233,59,110,137,108,120,248,119,255,242,7,14,254,250,95,255,11,127,183,184,254,117,63,177,219,204,63,49,115,237,33,130,244,231,210,115,95,249,79,88,78,233,51,177,118,95,55,187,81,214,40,69,149,56,139,69,
201,43,234,162,232,196,48,71,121,52,163,69,202,229,139,143,166,245,71,162,231,64,116,225,232,77,198,255,217,114,194,11,40,74,3,180,8,111,22,221,123,140,196,104,200,115,231,168,203,22,151,103,253,174,107,
51,225,14,47,153,238,223,237,164,155,219,20,111,216,255,149,139,43,246,240,52,17,138,46,127,168,133,76,189,166,240,2,235,139,37,14,14,161,165,80,226,80,188,31,227,28,84,15,2,54,57,237,75,58,138,50,132,
31,30,227,129,175,168,67,142,234,165,83,207,254,19,159,173,235,210,239,220,224,41,118,54,85,211,63,160,87,190,177,203,130,26,146,27,29,17,106,164,99,69,227,245,242,134,158,118,13,47,133,39,194,84,78,134,
17,217,173,90,108,120,64,84,68,61,76,86,78,171,145,24,152,123,30,41,20,151,55,176,121,98,175,132,32,121,142,7,136,138,133,115,30,56,188,111,79,62,235,208,34,100,145,62,81,254,95,45,172,77,218,162,100,
196,128,83,222,127,132,217,141,220,65,222,70,95,226,169,245,81,155,180,73,25,24,195,213,244,166,57,15,175,36,22,30,131,77,254,135,53,99,125,25,138,48,36,89,36,207,234,120,149,9,84,83,104,72,141,6,21,206,
238,25,89,22,107,140,173,141,142,109,72,95,10,24,229,86,98,192,89,57,200,161,157,125,20,157,189,121,196,184,191,28,216,93,213,242,162,84,243,16,213,57,102,17,87,248,90,63,107,199,129,219,85,240,111,128,
133,61,103,49,171,113,152,64,237,104,130,237,249,72,35,233,172,224,109,240,204,232,119,130,6,30,55,98,245,251,82,198,15,137,137,87,220,207,137,24,172,229,122,246,109,134,181,89,162,111,235,123,126,216,
73,207,201,223,14,92,220,53,49,250,174,191,207,242,126,23,101,94,206,247,181,235,64,244,196,134,223,199,58,246,88,241,24,230,211,1,163,207,49,156,35,27,103,206,63,150,108,210,93,86,127,61,26,143,75,101,
88,18,179,68,85,246,4,153,228,128,149,196,92,109,241,84,227,19,191,158,246,238,221,253,192,198,247,126,79,250,7,63,251,11,63,243,195,191,247,241,31,253,199,63,253,183,22,62,250,241,79,58,200,12,166,208,
35,242,175,193,44,59,117,241,168,173,75,28,65,4,23,167,26,4,207,68,150,231,58,70,72,163,96,224,227,218,226,39,226,245,222,119,95,73,239,122,195,19,233,123,223,251,245,31,125,242,219,255,248,79,191,112,
111,248,247,186,233,32,93,212,62,228,190,28,207,7,190,237,15,165,234,31,249,166,244,197,95,249,189,52,58,210,147,10,17,36,49,102,173,131,19,136,194,103,205,209,32,145,163,168,66,98,32,130,65,69,29,104,
57,227,50,196,122,43,122,213,238,200,129,182,212,19,95,144,102,201,10,101,134,132,4,211,115,23,83,67,157,234,150,146,196,53,30,55,230,214,52,209,216,219,247,168,160,164,163,190,176,137,105,245,249,229,
39,41,129,130,77,22,146,68,23,124,145,187,140,159,112,11,148,223,48,123,52,139,184,139,254,188,121,185,213,125,198,254,214,45,26,99,251,248,162,18,181,171,158,109,72,228,218,188,252,105,189,145,190,229,
221,171,169,192,161,149,136,16,70,231,207,71,229,85,232,67,31,200,43,95,243,222,167,234,4,187,198,200,159,178,222,217,168,165,91,144,151,12,131,224,97,87,46,137,15,195,203,40,253,154,37,44,56,84,42,53,
10,139,131,189,221,176,112,49,10,190,39,176,31,177,192,160,60,248,70,6,229,171,166,212,236,152,69,31,81,120,228,229,252,166,209,146,97,33,143,204,3,237,248,249,46,207,24,227,9,90,90,48,70,138,3,93,164,
76,168,155,46,74,235,148,16,82,231,68,218,57,105,150,129,52,78,88,180,2,130,36,44,102,196,92,145,55,43,179,146,217,73,31,87,132,14,175,95,197,238,181,229,71,115,242,138,99,80,93,118,147,246,21,84,57,7,
169,21,41,251,116,94,71,44,18,249,56,197,193,93,7,110,85,167,192,49,177,244,8,2,40,131,185,213,241,5,88,209,193,247,51,235,146,11,11,216,193,51,177,87,232,113,123,98,21,132,159,120,9,41,132,160,42,137,
211,206,52,71,107,219,176,22,136,4,12,235,76,157,19,21,49,87,121,151,44,50,161,227,186,239,138,221,7,122,12,197,56,245,139,70,26,108,216,34,97,88,230,73,27,31,147,183,66,10,179,234,54,225,36,20,5,115,
197,110,5,27,41,208,194,74,192,8,175,3,109,58,162,155,67,244,239,93,244,239,123,240,88,192,220,96,156,39,93,97,168,106,78,108,208,24,248,13,224,120,142,148,61,160,222,53,157,218,155,77,27,205,58,55,49,
181,31,254,95,239,166,59,111,127,199,255,248,212,183,127,103,250,167,63,251,143,255,217,179,159,254,119,127,232,83,47,126,250,242,39,255,229,111,165,223,122,150,140,142,55,253,3,175,216,152,94,17,210,
12,67,241,240,251,94,79,172,24,143,192,11,126,239,143,125,83,250,225,239,255,19,63,87,187,242,29,239,220,59,169,190,255,165,253,230,251,115,174,123,57,158,63,97,250,238,93,144,177,126,35,93,17,202,68,
99,183,246,130,236,44,178,103,220,84,245,164,92,141,186,85,58,73,231,139,200,169,115,14,103,199,20,74,182,251,30,244,145,237,233,27,197,168,143,85,235,140,164,139,194,202,158,74,161,173,93,240,140,197,
195,43,43,118,13,212,50,128,66,142,28,216,69,35,18,171,97,108,85,68,229,84,23,61,62,59,78,111,120,74,106,205,184,190,33,230,182,13,222,198,112,164,22,97,74,198,251,63,60,123,17,252,112,95,246,199,37,241,
193,206,158,53,228,64,174,26,134,84,32,155,164,25,99,243,213,238,198,62,69,54,125,230,224,126,250,193,235,111,79,215,182,186,82,62,20,109,36,73,239,255,174,255,226,39,199,227,63,253,133,76,230,13,60,217,
215,246,149,175,233,116,80,153,16,64,225,134,52,97,88,9,10,122,223,38,229,253,196,78,125,253,97,115,1,255,88,143,160,90,58,54,101,70,154,162,163,210,227,28,230,159,67,239,47,249,185,24,5,24,175,104,239,
17,243,80,98,254,74,129,231,24,144,173,77,131,138,103,216,187,150,222,59,1,53,87,97,135,109,241,77,141,199,12,81,120,153,25,94,99,205,122,164,131,81,136,91,225,113,25,179,137,248,32,6,203,90,6,27,156,
66,38,164,86,188,70,40,174,199,21,7,94,122,166,196,139,145,33,155,254,167,48,215,3,110,179,198,75,179,171,169,115,116,96,100,188,164,52,107,154,199,34,58,127,147,73,101,199,52,113,251,188,223,129,141,
126,249,146,84,10,202,163,3,98,103,84,146,196,181,52,177,215,35,185,190,142,131,173,239,85,58,96,28,86,34,247,200,169,12,20,56,31,120,207,96,73,67,128,48,114,98,26,14,218,192,28,202,37,186,178,29,247,
222,194,80,143,164,93,186,224,115,8,45,78,5,141,211,85,7,223,58,173,205,250,119,216,244,22,168,246,70,6,236,145,141,82,122,222,188,82,251,79,115,105,20,189,222,172,139,14,116,195,207,54,137,36,242,122,
227,92,208,211,38,10,201,163,195,68,28,213,162,248,190,202,8,141,253,76,200,40,131,157,140,62,183,66,176,9,105,182,205,242,95,144,213,138,209,128,247,108,198,248,185,186,117,27,11,93,242,103,183,211,221,
223,254,76,218,253,212,111,165,153,239,250,161,175,255,206,31,254,137,195,119,125,215,247,253,230,159,253,47,15,126,228,217,231,254,221,43,159,251,237,207,141,63,241,59,155,229,195,118,233,90,6,100,188,
9,90,71,23,196,129,181,90,145,56,254,161,119,50,116,211,154,137,63,53,223,191,246,212,83,74,241,215,214,31,121,199,213,239,63,170,191,239,221,91,71,205,149,51,61,126,102,17,117,207,62,27,228,16,146,72,
226,191,17,106,156,253,187,166,168,69,217,86,77,79,97,225,206,169,134,104,16,71,219,84,237,121,207,45,82,84,71,140,110,95,184,161,46,200,13,65,89,98,243,172,3,18,215,31,132,100,1,155,29,68,90,52,138,3,
50,244,156,34,218,224,36,74,202,251,22,24,203,46,175,123,208,168,139,59,121,215,249,72,83,5,45,232,185,138,233,187,81,226,230,121,36,63,187,110,79,222,184,141,229,181,95,215,136,251,139,228,150,21,157,
58,162,169,119,16,1,85,208,186,76,127,120,222,57,166,81,94,72,143,251,253,99,49,179,217,93,233,62,163,251,226,75,247,33,77,184,74,168,148,229,116,12,4,254,99,250,58,252,25,143,230,107,127,56,155,152,178,
178,81,118,202,232,96,214,232,9,43,73,235,6,170,104,227,158,128,50,154,90,13,228,161,150,180,39,108,110,109,138,221,212,116,34,103,78,237,92,172,188,24,4,248,81,62,230,113,196,209,244,30,58,150,217,12,
28,129,228,55,162,199,166,203,177,82,35,27,59,6,189,142,48,159,49,64,54,12,113,132,166,121,55,220,5,231,102,5,255,131,40,208,116,152,153,69,114,43,208,129,247,203,78,201,219,137,111,59,170,15,102,252,
25,237,39,227,203,81,147,186,64,96,209,92,78,239,123,240,14,66,232,67,107,226,185,211,195,91,154,111,209,210,146,109,13,181,57,137,6,100,62,133,231,150,94,129,65,143,195,72,208,153,46,94,188,226,112,178,
198,71,4,206,2,254,193,66,164,120,180,249,247,201,69,9,233,188,120,49,195,208,212,229,247,102,124,111,169,178,58,233,130,23,163,245,6,134,216,134,144,127,222,232,138,75,250,169,6,213,63,60,147,224,81,
19,187,171,12,234,133,250,110,186,228,250,198,68,252,13,18,180,46,120,233,76,241,40,165,116,135,55,237,248,221,247,97,21,23,121,255,104,59,187,133,121,164,100,3,6,93,63,246,48,224,243,137,212,83,5,228,
237,202,199,85,109,224,99,2,138,137,154,197,61,228,22,20,131,235,165,41,67,100,3,251,93,240,246,140,55,85,47,156,214,41,109,138,24,212,208,161,174,243,32,11,82,82,221,246,17,102,137,7,106,172,33,124,238,
164,151,127,225,103,30,239,220,184,151,222,246,199,191,231,233,249,181,39,219,11,79,253,213,191,243,95,127,235,98,255,199,83,253,225,97,251,224,91,114,157,207,222,169,111,245,223,59,189,120,254,219,187,
199,229,254,234,5,215,146,205,204,31,237,230,255,68,101,229,233,134,14,135,191,180,181,211,250,243,175,108,61,252,175,230,53,157,26,219,71,7,251,226,125,49,58,191,175,88,127,31,28,54,106,209,186,228,179,
43,186,25,28,167,87,14,183,211,215,65,16,27,158,233,75,238,55,207,155,53,108,240,232,213,51,48,225,172,44,168,45,98,148,51,16,75,211,64,227,79,75,128,63,105,31,60,225,125,70,12,250,162,210,185,168,234,
137,208,166,71,151,123,247,94,84,194,212,89,44,113,168,25,166,125,210,205,129,195,220,224,108,198,114,202,193,243,23,115,151,173,189,177,150,198,68,150,37,142,247,14,233,169,148,230,49,247,246,139,201,
107,54,104,40,176,26,82,58,85,156,70,9,150,254,204,254,126,218,100,205,191,139,168,36,196,10,103,234,66,23,24,213,85,37,128,207,220,159,17,150,56,51,39,7,105,168,38,237,230,231,191,212,122,248,159,127,
131,141,251,181,127,57,58,152,43,198,106,156,145,186,93,92,54,43,132,208,89,208,17,179,74,230,192,130,227,123,11,38,9,75,188,47,98,202,252,41,31,61,105,144,156,147,87,204,68,195,101,41,149,234,200,228,
100,157,186,115,102,78,148,230,54,82,11,142,223,59,210,1,207,198,27,138,103,206,45,78,223,216,188,80,226,200,158,32,63,44,168,67,89,39,122,136,170,151,104,103,152,103,233,59,20,74,193,172,198,25,31,34,
40,6,188,69,140,112,139,80,168,202,59,245,136,78,107,243,60,227,178,239,41,73,139,42,138,170,83,126,40,77,178,39,69,80,20,23,70,187,152,105,164,80,206,195,13,203,219,138,14,2,30,83,25,235,122,232,193,
119,229,68,23,29,144,145,175,97,77,75,76,208,48,163,44,107,158,46,179,208,7,3,135,90,82,192,153,103,30,126,246,76,3,50,169,2,129,146,180,17,66,136,113,168,48,100,11,4,15,209,50,97,72,121,52,241,240,98,
113,111,7,97,40,192,150,35,201,56,84,157,252,148,107,162,215,100,188,142,224,180,24,123,24,161,117,116,206,127,27,99,180,143,237,62,80,16,192,41,78,144,65,7,108,174,64,24,251,54,95,141,140,114,3,187,210,
118,8,79,120,80,203,160,252,141,78,216,70,46,47,49,154,14,100,133,254,180,20,86,221,90,5,74,25,184,215,42,15,55,109,122,243,41,131,85,11,65,184,124,234,101,241,255,57,207,179,79,57,19,99,130,118,198,135,
74,245,206,64,230,106,218,251,244,191,73,31,123,225,151,115,79,189,231,123,167,246,166,46,252,179,66,117,49,93,123,88,245,197,147,87,63,191,49,247,3,51,197,171,233,67,183,182,14,190,84,111,214,223,83,
28,63,164,6,178,63,221,59,127,153,104,125,126,177,178,126,225,207,31,125,226,179,233,254,87,190,88,216,184,62,155,142,110,105,144,165,25,215,218,195,60,215,116,75,141,36,205,171,134,104,247,160,176,229,
16,39,216,55,13,136,232,25,161,201,251,197,213,75,250,250,70,71,246,211,64,105,208,194,18,152,95,106,221,101,168,130,29,149,59,102,76,26,71,123,105,179,54,149,30,191,58,11,173,68,10,72,225,253,87,158,
215,221,64,245,17,126,160,165,205,74,127,70,65,191,233,236,237,35,228,27,67,57,133,227,104,49,208,69,249,226,41,146,203,169,188,3,138,232,140,158,195,93,60,200,64,165,82,65,253,239,16,201,57,82,254,117,
188,11,70,83,123,13,27,211,234,150,33,176,21,196,15,134,177,189,35,173,101,157,71,222,163,110,253,162,53,206,19,170,87,78,111,251,183,53,164,32,82,161,4,65,141,14,183,166,62,242,141,191,251,87,190,41,
165,191,242,181,62,158,249,44,40,177,16,9,251,220,69,155,74,108,193,245,247,45,220,20,139,50,10,220,4,214,69,76,86,136,67,130,96,137,233,206,83,112,126,197,5,15,113,248,33,232,31,82,151,68,229,72,104,
107,51,164,125,135,130,247,24,29,215,101,241,206,9,0,170,17,227,153,140,45,179,200,122,81,156,208,112,246,88,212,51,177,83,141,122,101,193,103,237,25,18,51,20,231,46,79,226,72,249,37,125,132,50,44,100,
20,227,142,117,141,139,108,253,8,246,143,188,65,206,239,76,10,115,197,25,5,238,55,151,223,147,42,177,224,188,103,87,220,244,102,236,93,111,180,171,155,154,135,140,22,207,179,172,150,81,147,50,157,5,5,
198,125,67,91,95,230,51,31,3,103,66,172,125,44,207,201,89,57,93,188,39,153,93,95,126,247,148,113,137,134,90,67,63,91,150,255,60,99,92,186,100,135,209,135,168,81,215,3,86,99,227,16,4,84,80,159,245,40,77,
195,30,79,105,81,217,147,86,153,21,18,228,48,131,77,253,140,122,14,103,78,210,187,199,243,47,49,64,153,138,241,17,210,2,83,40,197,29,41,133,152,59,82,20,51,74,145,166,69,83,206,102,120,229,101,190,167,
47,127,57,29,13,114,176,175,193,56,4,193,22,211,200,22,192,220,61,253,83,187,46,56,139,48,139,142,242,240,188,25,47,132,9,24,199,89,109,77,43,115,33,53,68,226,104,5,211,133,18,6,98,195,34,11,215,164,25,
37,57,225,161,132,5,96,107,177,134,62,27,16,199,31,253,82,106,125,134,46,54,123,57,125,124,105,93,117,199,59,222,62,179,186,252,118,76,68,239,203,175,236,21,75,188,199,83,79,62,50,57,52,53,5,217,245,43,
238,9,11,117,175,113,148,6,250,192,174,230,121,39,36,201,38,22,182,184,205,216,171,247,109,67,35,37,234,159,145,36,254,158,42,162,11,45,19,225,32,170,253,61,173,79,42,11,186,217,81,54,77,99,106,213,146,
118,240,15,83,24,160,229,233,53,213,78,138,219,117,43,168,235,66,112,17,194,186,132,96,139,130,243,54,153,212,60,100,151,161,222,201,170,52,202,136,87,243,66,176,30,132,180,111,46,79,228,200,179,84,71,
149,232,170,6,165,228,25,182,113,120,100,6,33,143,112,234,98,203,239,168,60,170,34,22,175,175,45,166,61,245,169,89,220,199,52,67,44,241,146,158,103,80,95,244,140,22,149,174,189,83,225,71,149,115,58,242,
62,171,210,46,79,42,236,254,156,18,193,115,213,89,51,216,218,18,107,121,101,149,244,16,44,254,242,139,183,243,163,243,207,127,247,254,254,237,255,125,101,229,218,238,215,242,128,58,111,84,254,136,151,
145,88,240,44,203,202,172,234,37,170,141,229,56,138,21,29,212,113,197,13,137,105,86,80,210,25,201,246,163,72,236,59,112,53,5,191,45,112,171,191,195,211,221,63,73,87,228,43,25,39,22,82,85,7,247,218,226,
89,163,251,89,140,74,207,130,60,115,190,71,71,68,60,29,106,149,152,87,201,146,89,199,145,0,254,161,13,17,231,238,125,49,28,152,140,160,25,48,6,109,155,22,8,35,39,212,130,115,94,67,166,71,47,74,101,176,
112,172,112,200,196,242,22,46,106,240,242,82,53,151,233,99,143,55,139,218,68,54,116,24,144,232,143,248,197,134,63,199,148,42,255,76,23,44,120,144,66,61,15,44,106,46,179,226,182,110,144,71,11,143,58,248,
170,64,180,255,183,151,169,163,16,39,7,76,188,195,191,68,194,152,93,99,160,64,197,50,99,84,7,21,243,60,115,113,149,42,136,55,109,129,65,81,251,182,136,121,141,141,113,67,43,201,166,90,216,37,100,135,246,
68,62,195,104,59,29,6,208,72,42,98,108,68,247,145,209,93,122,220,89,6,133,247,73,227,28,56,186,229,37,119,89,4,113,241,112,114,155,226,76,6,241,76,124,179,0,198,73,229,242,224,172,61,207,121,6,178,235,
43,166,42,131,33,105,128,183,224,110,86,163,50,63,42,145,62,156,116,138,103,41,210,5,104,196,249,85,73,65,20,47,97,127,100,173,66,100,208,93,151,74,16,3,174,240,232,53,149,22,117,108,243,253,250,29,197,
5,174,225,190,251,208,206,227,212,51,27,28,222,144,130,120,73,126,219,58,136,25,166,167,137,196,165,47,238,124,118,91,250,96,63,189,73,39,192,123,109,245,67,155,26,153,157,107,47,25,249,210,229,219,150,
172,143,53,29,25,134,228,64,240,228,187,98,241,235,58,20,92,146,203,221,23,16,47,184,248,235,214,241,83,60,225,45,100,98,137,100,174,43,23,173,92,64,19,45,136,199,118,91,155,155,37,104,111,165,219,96,
231,166,221,178,196,216,173,65,41,247,77,228,190,226,160,93,210,91,247,72,49,248,8,223,144,228,201,151,20,110,31,237,96,231,155,202,16,161,138,110,139,209,183,159,166,168,136,150,181,125,217,87,236,191,
185,233,141,21,92,92,214,226,132,7,113,152,57,30,132,217,93,63,123,62,210,53,209,251,214,232,184,71,66,174,53,177,230,156,150,45,97,13,153,244,244,34,103,181,68,106,249,48,152,252,188,61,84,131,72,118,
196,185,95,212,65,226,253,111,90,76,243,27,214,221,254,207,95,184,240,102,13,200,190,197,163,248,151,95,211,195,57,85,189,138,109,133,243,7,187,147,242,45,230,21,140,10,40,170,216,154,58,38,38,19,23,232,
104,123,1,53,36,127,155,154,62,207,59,172,57,12,228,8,100,44,218,120,145,198,136,136,51,232,245,144,55,141,125,149,41,99,242,10,184,43,176,220,192,238,106,83,119,55,73,203,34,157,240,228,18,235,170,235,
66,94,202,98,158,215,110,157,178,180,226,143,5,130,228,146,248,169,235,141,218,62,47,100,93,49,140,54,26,107,85,177,181,61,240,163,11,211,45,184,166,104,40,213,200,161,202,121,44,167,86,223,31,204,177,
141,60,23,178,57,44,91,131,82,166,239,231,119,21,73,207,216,200,85,7,168,232,176,52,109,212,80,233,196,156,208,232,230,222,71,44,228,26,59,147,105,104,17,187,229,228,86,59,65,59,207,74,167,84,86,64,94,
109,60,12,3,158,165,54,201,137,227,202,14,110,180,172,40,162,110,71,8,177,174,205,16,93,227,58,54,204,136,117,45,137,175,79,89,157,46,24,27,82,193,60,150,239,178,120,245,30,129,252,151,65,214,39,93,110,
84,194,12,24,168,69,88,111,90,106,231,16,203,123,42,205,179,66,96,139,207,38,243,163,203,225,49,67,189,19,241,144,70,12,148,90,246,140,117,217,222,101,28,168,97,166,108,198,140,117,14,30,99,23,147,249,
106,10,216,65,6,46,142,196,105,13,107,231,161,210,138,58,200,0,109,159,183,109,66,40,87,8,39,50,188,109,137,200,97,218,207,101,252,194,30,242,236,104,223,100,150,238,29,141,222,231,221,186,162,132,200,
51,23,150,16,91,186,240,157,207,166,237,252,66,106,236,222,78,123,186,167,47,141,223,168,151,48,40,105,94,229,61,245,184,91,123,4,35,98,251,41,68,201,52,77,245,160,220,192,158,78,91,123,164,159,182,33,
29,8,232,24,59,59,102,60,47,244,169,210,133,66,71,214,164,99,88,241,27,236,147,118,228,224,28,156,182,3,55,176,150,5,18,202,43,98,238,83,94,116,198,222,91,96,100,98,24,241,33,38,61,66,163,109,4,77,251,
132,208,100,67,59,155,57,245,181,14,155,157,39,60,35,115,132,192,162,125,205,20,9,94,107,86,76,137,32,106,222,199,111,122,30,93,97,200,57,200,106,135,233,131,149,75,135,219,186,69,82,150,205,108,32,54,
133,114,139,214,162,109,30,78,8,67,14,133,7,61,122,104,203,57,217,255,129,36,7,226,216,48,226,93,204,247,209,22,80,169,190,121,58,188,244,203,31,77,59,139,173,141,87,94,25,151,30,125,52,72,147,175,205,
11,170,114,99,10,4,7,153,69,144,43,52,146,187,70,50,160,248,235,152,76,29,5,102,7,22,251,68,73,153,27,92,146,128,95,144,146,24,176,134,13,214,234,76,226,173,135,64,217,59,38,214,14,200,7,118,22,38,163,
225,221,36,140,222,103,157,202,96,195,88,1,172,181,86,123,24,195,255,64,42,169,130,243,80,205,208,176,70,29,223,217,153,49,6,140,97,31,163,118,102,3,31,186,164,32,101,195,43,44,46,177,230,193,208,77,122,
143,146,139,33,131,164,192,136,34,162,187,252,171,100,201,190,100,127,79,156,113,17,225,49,165,5,72,219,230,26,232,86,48,37,118,187,52,100,141,117,110,143,164,121,213,162,70,178,255,16,83,18,72,161,16,
249,88,208,105,133,162,102,94,69,245,192,97,43,56,220,67,196,67,88,224,179,72,171,180,167,197,173,242,96,54,89,140,49,175,206,33,86,36,88,123,70,23,40,86,73,39,250,218,132,17,88,47,242,136,138,207,235,
83,10,171,193,70,254,16,33,226,176,147,169,109,88,131,141,26,8,237,112,117,124,94,180,191,204,139,121,162,20,235,126,246,136,215,193,24,138,181,74,51,142,177,84,13,59,228,160,216,195,174,53,132,225,3,
63,143,148,22,119,218,176,14,77,140,37,60,13,230,90,156,58,67,121,132,188,182,213,137,192,221,195,74,8,201,253,172,96,64,222,16,178,193,10,11,159,173,155,141,133,73,30,239,49,92,187,91,10,100,164,139,
116,105,216,240,251,35,135,56,195,88,214,188,127,244,249,29,56,180,117,130,145,94,251,78,234,30,108,89,3,125,138,92,208,61,207,239,203,16,196,124,243,110,90,233,111,51,196,119,226,18,196,114,234,99,133,
63,85,104,171,71,203,124,22,205,211,238,110,153,185,121,154,246,54,59,233,51,47,237,167,207,33,80,26,106,105,203,114,176,181,254,186,251,217,208,113,239,162,171,44,165,117,29,4,31,50,48,43,10,41,58,184,
129,13,134,227,219,215,103,28,92,136,71,104,84,153,182,150,60,222,254,230,158,148,85,228,189,117,108,116,168,178,49,242,207,168,144,19,98,138,145,253,84,85,186,115,200,177,68,42,172,92,212,174,196,207,
22,20,54,140,231,196,170,156,72,31,244,143,174,129,89,100,95,180,154,41,218,39,115,139,24,99,19,15,74,68,208,195,232,94,65,20,243,200,82,148,69,186,174,101,98,5,18,204,13,123,250,109,140,93,155,98,104,
13,89,53,47,180,11,82,49,10,18,68,200,172,225,253,180,185,147,254,206,249,249,205,160,85,191,102,175,252,80,146,182,51,50,3,210,197,230,108,158,2,161,121,15,174,234,217,216,253,210,161,67,107,131,242,
112,209,40,184,175,101,196,113,136,8,124,117,93,40,105,140,155,84,115,119,159,25,17,255,229,44,70,145,140,110,70,213,65,239,174,77,165,84,103,46,76,186,214,30,3,57,189,49,171,216,36,98,184,141,101,172,
147,198,213,44,120,180,130,92,55,72,246,244,108,74,185,18,171,188,72,24,237,145,5,251,59,64,40,40,77,198,174,177,244,32,82,61,216,15,215,40,195,224,48,240,222,140,198,180,135,20,83,173,179,168,246,65,
39,186,230,89,252,144,92,217,177,139,203,145,43,67,58,156,240,152,188,225,12,169,87,204,66,217,9,181,135,79,40,218,252,61,132,82,71,25,210,208,161,46,66,10,77,155,56,163,251,194,9,6,56,149,142,39,36,206,
42,200,151,195,223,239,251,185,44,171,126,81,190,46,36,116,123,44,231,186,157,127,133,96,187,33,30,42,155,33,122,238,243,98,174,202,163,160,84,192,76,33,231,132,65,205,179,220,235,12,209,144,170,40,123,
234,250,194,229,73,235,180,172,229,37,58,226,156,94,171,93,178,185,211,35,179,52,197,99,12,251,228,48,231,9,47,148,149,130,251,98,123,135,173,138,60,145,106,214,1,66,188,105,109,163,143,209,156,245,107,
121,94,229,201,123,218,188,140,9,126,138,113,243,119,198,204,121,112,144,77,128,182,169,138,134,17,183,3,250,242,9,248,87,191,67,66,199,155,76,57,20,165,75,87,82,249,252,222,132,1,142,190,6,77,2,142,156,
3,115,95,83,233,60,168,9,143,155,254,117,15,251,92,159,24,158,12,85,82,89,119,246,205,29,222,202,253,69,71,192,166,124,246,140,67,179,90,210,160,91,174,250,38,141,108,231,108,47,93,184,186,66,239,170,
233,150,146,51,85,3,78,52,5,22,232,28,170,164,130,107,15,206,2,75,195,33,40,48,144,55,46,248,247,117,16,248,28,255,49,148,183,46,33,129,166,212,118,30,42,137,91,89,1,243,25,249,250,253,205,73,47,161,44,
111,215,3,65,215,149,114,21,227,128,211,233,230,196,165,59,224,105,105,51,90,142,75,182,249,140,200,145,87,57,160,209,129,103,183,115,172,49,135,178,63,206,169,88,213,88,155,250,167,205,120,47,11,83,202,
140,205,1,238,96,154,150,247,24,242,200,34,18,175,202,88,204,32,246,198,60,243,69,207,32,202,34,135,28,208,194,194,81,90,92,212,13,242,249,143,165,133,167,223,243,119,173,244,159,250,90,157,78,85,49,33,
128,14,33,178,188,19,175,149,27,45,152,210,108,186,85,95,227,98,16,77,162,208,121,56,101,53,140,178,59,223,96,73,144,48,32,220,208,129,104,248,221,174,205,222,0,245,60,75,223,163,30,162,255,60,6,9,134,
96,215,52,85,133,102,110,52,160,74,113,148,147,5,108,236,149,143,39,65,122,140,249,11,17,114,213,68,167,28,13,100,155,197,139,92,230,60,8,75,171,50,73,181,116,84,20,28,40,125,226,3,57,171,53,27,90,94,
9,189,94,87,116,60,80,226,147,53,144,231,24,17,17,210,208,145,3,119,80,210,157,97,218,56,64,93,220,78,165,52,14,109,204,3,172,223,126,251,190,132,55,143,32,31,219,37,205,202,33,141,30,122,100,102,18,27,
142,28,166,189,155,188,131,177,8,59,145,160,246,0,163,15,77,19,20,31,58,116,209,28,58,235,186,242,32,241,158,252,219,206,125,21,45,8,48,76,200,228,224,158,115,241,205,19,186,211,168,212,232,210,225,178,
164,49,104,120,222,166,91,4,173,71,24,204,240,148,49,98,240,178,56,104,20,177,162,13,92,230,233,143,2,106,59,156,211,253,121,221,199,7,233,198,201,174,131,237,48,33,217,236,115,170,22,147,218,108,38,75,
25,89,46,29,15,24,41,132,217,45,105,172,152,141,50,224,245,154,160,90,232,93,3,221,15,17,84,187,244,187,109,140,113,25,228,189,164,74,8,242,159,20,20,79,219,188,118,50,35,12,14,67,24,119,84,254,156,50,
54,4,59,218,110,68,145,251,97,154,210,121,34,27,49,184,251,61,195,178,79,201,249,45,33,196,102,84,15,173,75,59,124,151,120,236,138,245,120,81,193,247,203,55,111,129,136,194,11,70,40,198,254,69,190,185,
229,207,19,37,116,207,171,188,233,49,232,209,241,57,63,211,77,79,24,190,123,65,53,79,185,129,132,34,24,230,215,98,228,19,166,182,46,6,167,68,115,64,134,198,189,247,183,253,155,135,185,231,218,95,70,42,
181,24,203,37,251,49,115,22,241,240,56,221,3,105,199,211,32,85,94,39,127,135,176,141,8,235,50,118,186,212,34,124,237,26,66,148,60,8,92,151,91,125,110,11,146,139,162,3,185,240,28,15,105,161,165,147,28,
126,228,80,86,5,75,184,252,121,251,100,78,232,114,252,92,157,170,104,15,220,175,165,178,129,209,47,236,91,71,251,42,66,184,145,230,97,17,162,148,40,234,75,12,199,145,3,185,134,29,206,226,52,134,200,166,
170,176,173,167,27,226,137,52,215,223,251,217,159,123,234,107,117,48,227,125,178,53,237,229,203,26,40,149,88,140,153,69,202,29,253,104,218,199,247,65,60,253,61,163,207,170,133,42,138,83,6,36,84,211,46,
178,102,99,180,148,75,53,60,192,142,205,56,192,2,142,88,112,225,133,67,14,10,110,179,174,91,54,13,118,246,28,41,113,134,49,220,5,229,142,16,7,117,94,115,128,61,21,245,192,247,214,139,167,172,138,251,134,
190,178,192,124,213,65,143,238,111,13,132,205,44,98,168,58,39,21,130,104,104,48,4,113,248,35,6,235,169,108,62,6,127,235,98,180,83,155,163,97,67,220,10,178,199,131,92,84,148,91,0,183,119,149,255,236,52,
137,36,28,243,41,49,237,188,235,138,182,152,122,96,121,96,211,233,30,61,102,251,34,201,95,144,83,32,125,102,159,215,3,101,79,21,92,31,213,67,248,86,33,131,131,40,134,187,147,10,154,37,106,36,89,67,153,
85,164,2,168,123,132,64,154,71,32,68,28,152,183,57,34,235,127,122,17,105,132,213,108,209,181,158,112,237,109,195,159,162,249,215,137,120,232,208,134,175,98,129,27,100,64,39,177,110,97,121,165,14,10,174,
127,93,76,185,101,211,81,107,166,71,136,192,175,107,77,114,201,247,56,79,16,145,215,69,92,177,21,122,25,33,200,28,214,91,254,161,205,99,61,170,40,61,234,61,135,214,162,67,56,49,7,210,54,176,223,207,226,
11,203,24,228,40,116,111,201,45,59,57,147,53,206,130,172,29,34,128,99,185,159,136,155,93,170,25,171,218,155,176,2,57,108,232,20,84,113,142,61,235,218,200,83,82,4,209,97,160,182,0,9,248,119,61,31,210,44,
117,76,254,217,207,51,84,242,182,85,80,145,247,61,188,171,125,136,244,218,154,3,223,113,104,235,140,95,158,87,28,89,183,214,255,205,218,157,71,73,154,94,103,129,127,99,207,140,140,220,247,172,189,170,
171,122,151,212,90,91,155,45,75,178,108,44,91,194,54,216,112,192,216,99,22,155,153,193,7,24,56,120,230,176,51,246,28,12,62,102,55,96,188,48,200,43,200,54,146,145,132,218,90,44,181,220,106,45,221,173,238,
46,117,237,85,89,185,103,70,46,145,25,25,17,153,145,17,49,191,27,61,252,195,25,6,99,72,169,186,170,178,50,34,190,239,253,238,250,220,231,222,139,174,180,179,185,4,43,188,15,191,224,105,121,154,35,164,
6,49,57,47,105,190,20,195,81,111,205,153,176,200,192,31,157,242,92,25,192,9,198,204,115,30,183,47,167,48,128,119,108,50,69,32,191,5,247,190,131,222,183,168,107,189,73,121,236,10,86,46,114,85,197,81,171,
62,64,106,210,166,156,81,38,53,202,159,199,16,27,244,188,162,182,125,28,93,59,234,209,89,229,185,60,42,94,142,129,142,13,118,131,15,136,24,212,237,91,20,43,38,13,106,250,233,79,30,60,6,92,174,27,87,179,
201,16,45,8,109,31,49,245,224,49,70,101,82,68,50,196,107,158,213,170,166,5,36,93,83,19,95,132,166,151,245,41,231,201,217,181,59,155,140,240,106,122,252,184,122,110,119,255,254,15,254,143,82,208,236,9,
58,216,128,135,81,17,218,118,132,110,125,47,26,180,59,36,112,174,173,223,248,156,151,143,104,144,35,8,60,146,131,169,243,40,13,35,11,51,8,230,209,0,68,63,7,0,0,32,0,73,68,65,84,58,20,237,86,98,48,101,
20,14,101,124,90,123,142,225,92,172,252,96,140,115,68,201,42,83,224,35,150,184,24,125,130,148,61,198,160,140,67,94,155,184,185,59,148,47,136,15,177,239,114,192,181,100,25,4,120,185,18,12,64,5,248,83,0,
22,140,123,255,8,115,187,64,159,142,63,143,58,204,182,34,118,75,50,62,194,147,140,233,75,60,196,40,137,129,78,77,147,19,50,172,113,193,207,142,247,155,170,221,131,135,123,4,157,108,224,79,146,33,249,158,
201,239,165,217,168,201,11,107,193,243,166,8,4,143,118,140,245,15,198,83,165,123,31,18,105,129,171,214,184,35,161,245,161,26,90,206,104,10,173,213,102,34,1,222,231,21,59,70,177,130,120,184,73,161,235,
160,229,172,101,117,199,160,48,222,198,199,123,37,34,138,193,58,86,212,161,144,20,92,143,182,88,19,198,175,49,44,3,90,199,130,195,220,234,131,87,114,97,86,255,26,36,240,134,240,188,198,187,141,185,142,
113,215,224,109,89,187,80,80,192,23,175,33,165,39,204,192,7,205,219,211,66,250,61,6,178,163,188,36,186,235,131,64,1,186,45,3,169,110,198,183,226,243,89,114,39,97,194,156,55,66,121,27,192,220,89,96,140,
24,123,43,240,128,62,90,165,138,154,217,167,52,28,12,104,229,91,130,211,236,139,30,98,253,95,14,210,58,39,228,108,202,211,15,122,19,60,142,48,95,61,122,159,9,169,34,18,108,130,154,115,234,206,5,17,67,
67,47,112,23,176,51,4,76,105,203,53,199,69,31,15,4,221,137,65,30,10,79,239,94,142,25,161,65,222,177,98,187,192,160,208,177,18,131,225,128,61,195,114,208,35,103,190,164,208,190,94,168,138,222,236,231,212,
102,88,150,227,102,77,33,200,241,122,123,128,202,182,60,58,139,16,31,172,44,23,132,96,160,147,168,26,40,180,149,141,58,81,26,138,231,119,151,144,215,241,132,119,133,161,37,53,206,115,188,117,70,4,115,
28,76,25,151,51,0,187,24,63,195,120,144,163,6,32,232,80,73,238,104,199,68,143,77,77,24,162,174,19,224,207,9,3,62,4,141,158,33,163,195,6,216,13,136,90,14,149,206,246,36,241,39,154,10,206,11,125,39,1,71,
55,189,238,165,221,78,122,65,23,215,226,58,107,104,183,76,241,206,85,128,231,157,177,127,245,15,126,226,137,255,97,202,121,212,152,77,117,73,123,199,252,216,93,144,122,13,177,160,104,28,201,17,218,89,
87,18,93,99,49,14,88,230,172,164,231,40,167,247,159,229,201,24,53,82,99,122,163,67,60,242,160,97,158,137,204,247,191,4,153,132,49,242,84,131,164,89,166,166,92,182,4,217,41,105,43,64,100,99,213,177,127,
40,62,163,200,187,216,197,168,29,40,214,239,29,201,105,115,18,239,81,124,215,5,22,43,135,228,188,165,198,148,65,248,110,242,204,185,32,73,27,165,17,95,28,137,130,117,204,26,26,192,166,145,155,250,61,128,
166,86,214,36,63,175,157,155,174,164,5,94,170,16,253,136,132,109,79,136,217,97,81,51,60,90,96,185,69,33,252,244,164,215,243,62,209,39,115,141,97,104,15,105,47,163,100,93,168,92,135,85,63,80,18,42,160,
225,117,80,2,179,60,78,66,214,239,103,170,101,70,65,141,16,206,155,206,158,61,219,207,65,219,8,17,99,106,185,45,69,240,174,181,237,19,8,231,227,69,0,12,67,54,238,97,151,9,95,244,10,30,135,101,0,112,28,
139,65,119,12,36,187,46,47,62,204,215,250,101,168,81,33,123,23,72,19,227,47,5,100,161,151,196,136,17,18,250,98,230,184,127,211,34,184,82,129,2,101,228,33,8,76,172,22,12,92,40,108,99,44,74,10,174,45,124,
131,1,98,202,156,233,16,65,141,30,104,157,183,222,200,51,213,195,58,206,152,245,180,103,109,152,241,180,94,135,58,66,91,51,208,223,134,26,104,153,161,205,240,30,135,49,57,145,55,215,91,198,160,224,230,
54,239,11,113,13,108,62,123,17,144,36,126,80,74,202,184,191,113,232,117,157,209,235,88,202,84,216,188,163,44,180,99,68,40,182,172,207,60,11,137,62,235,218,98,114,250,92,208,66,123,139,106,219,104,121,
166,47,150,33,199,101,212,166,1,77,232,29,97,125,79,152,218,13,32,206,103,71,84,21,228,250,29,239,147,129,180,6,114,191,184,136,225,117,219,179,165,108,139,128,188,231,171,251,125,71,112,128,214,182,188,
162,231,151,151,223,96,120,138,64,156,33,117,222,53,8,249,146,51,153,152,55,230,242,180,201,237,83,21,245,120,60,107,165,192,134,244,33,214,44,92,62,51,6,108,100,16,201,120,17,178,243,144,201,142,103,
148,74,26,8,26,149,120,198,74,116,13,55,18,131,237,142,80,13,151,245,143,230,119,173,7,132,102,143,192,27,214,92,227,139,183,183,211,196,3,134,92,127,243,99,234,203,190,247,220,151,228,250,199,223,184,
219,219,61,231,209,253,119,127,229,119,106,86,182,40,186,22,53,10,158,172,162,216,17,156,35,249,2,52,154,3,243,224,214,89,73,185,221,137,3,46,56,188,30,96,96,95,93,110,132,21,219,166,44,39,148,32,54,141,
69,205,49,0,138,88,139,87,19,54,197,238,200,34,18,248,174,28,241,80,252,55,44,156,139,8,48,124,96,59,132,155,151,12,4,176,172,240,123,36,180,60,100,173,27,106,165,21,83,242,138,185,93,159,15,26,167,176,
53,30,178,32,220,134,111,234,81,244,190,166,100,29,242,224,57,15,42,20,107,87,56,60,7,61,61,225,49,187,188,64,131,215,143,25,185,117,239,151,205,44,244,31,196,24,242,196,1,68,47,148,175,212,111,41,83,
92,182,246,190,168,239,243,136,50,236,114,249,219,14,59,120,177,7,202,38,57,66,126,194,136,228,157,69,73,45,55,248,158,209,185,145,99,44,108,50,114,45,128,48,0,85,180,195,29,241,242,37,63,23,236,151,22,
16,227,1,196,134,141,165,106,90,134,194,20,1,83,121,94,99,155,215,41,9,189,206,200,193,39,24,10,203,222,121,113,185,10,3,118,34,84,189,36,42,193,127,234,107,89,132,178,17,222,15,161,227,5,152,19,174,30,
88,201,227,240,64,52,54,114,85,186,207,83,49,52,114,69,175,2,160,120,86,44,150,193,117,233,81,175,239,137,40,192,181,106,165,20,89,200,185,188,174,249,218,181,229,34,26,17,106,247,151,20,201,237,84,12,
20,251,13,67,243,250,81,225,102,85,205,110,11,31,119,90,161,126,50,80,96,232,245,49,246,85,40,109,89,179,242,137,144,183,33,167,91,17,218,7,229,50,79,14,178,58,128,30,214,250,37,202,231,117,68,30,193,
24,67,163,200,139,90,194,48,198,142,155,140,112,183,94,49,145,0,139,108,171,113,47,157,11,102,149,134,132,99,6,163,197,56,116,157,95,215,123,31,240,132,19,37,67,181,141,172,44,9,209,187,90,11,99,73,242,
224,81,21,102,224,53,162,173,35,74,182,218,167,238,216,79,163,92,211,20,234,14,234,219,141,81,35,199,234,244,121,165,151,145,150,8,137,188,174,240,0,251,206,121,192,57,229,22,120,206,93,187,59,69,28,39,
242,222,14,135,82,148,58,197,182,240,96,31,45,95,111,168,251,202,235,231,139,105,26,80,148,177,159,243,88,47,105,78,205,116,16,66,221,205,74,60,52,135,92,246,48,214,60,147,24,27,51,69,79,70,69,31,29,19,
40,86,86,15,121,125,163,100,26,139,143,127,230,103,254,201,227,30,203,226,127,175,118,102,39,240,104,115,132,183,131,122,55,44,47,202,128,234,113,212,241,92,89,53,150,109,96,92,177,67,24,27,15,178,197,
234,53,88,124,193,38,65,57,208,217,47,171,67,136,142,5,60,57,36,230,130,230,67,63,134,113,36,250,136,129,192,194,216,1,132,134,41,102,191,172,84,144,161,4,77,240,248,177,190,202,83,172,88,15,64,242,5,
74,179,225,231,11,202,48,131,6,63,69,221,113,135,123,136,137,2,101,202,57,14,248,224,182,189,175,149,1,160,252,40,27,100,121,235,195,220,22,160,69,77,150,165,173,169,91,2,241,211,38,11,39,202,162,248,
114,166,169,73,131,183,98,166,76,38,221,184,185,146,106,75,136,6,154,196,91,32,240,35,51,83,11,254,61,30,124,111,107,75,45,205,251,9,9,235,128,158,81,109,30,209,21,179,166,230,86,149,236,29,241,204,237,
0,7,212,75,163,157,108,82,9,100,144,96,86,183,108,62,94,86,194,193,25,221,111,85,33,155,254,109,224,140,154,228,88,218,20,118,174,10,177,187,74,42,49,75,32,150,49,93,162,132,103,93,107,208,18,166,132,
154,83,198,60,94,16,85,12,250,220,10,161,156,194,43,21,96,247,61,230,0,175,88,115,102,155,66,223,70,32,153,158,199,14,165,28,112,22,147,126,29,17,220,22,80,43,3,216,64,195,246,179,148,15,130,139,32,99,
124,105,36,0,129,48,170,111,226,213,118,135,103,1,83,186,104,160,208,113,158,129,80,159,18,29,140,106,92,136,50,200,78,144,49,252,111,88,201,167,8,61,58,173,185,52,195,91,108,233,86,90,133,25,244,228,
86,71,234,148,123,114,200,250,234,61,207,217,172,92,17,199,179,34,170,223,21,250,207,122,254,147,94,147,87,178,169,239,111,105,154,192,131,61,82,142,51,251,150,41,181,8,11,255,149,194,13,57,207,105,209,
87,160,191,42,99,234,215,209,246,197,72,193,54,54,120,231,19,253,182,29,223,203,172,110,35,90,240,220,148,122,88,253,55,33,10,116,231,24,64,97,105,86,232,57,67,54,102,212,92,155,154,231,171,139,88,96,
81,50,99,100,39,165,102,107,75,41,221,55,177,239,80,238,53,37,84,93,16,253,140,9,231,165,181,253,8,140,62,113,50,64,42,14,33,24,85,217,240,206,34,128,145,57,253,175,243,134,139,73,25,10,206,54,43,55,222,
35,240,177,21,221,173,171,153,74,91,166,44,75,226,49,7,8,224,132,167,218,147,82,28,151,198,210,39,111,170,139,42,67,190,237,201,233,244,174,39,71,210,238,210,162,232,107,226,67,235,7,189,119,255,119,43,
103,4,61,43,75,187,242,42,117,59,31,156,81,167,138,26,99,3,211,163,181,108,74,1,240,36,248,133,219,92,105,77,243,116,77,168,116,196,18,213,17,142,59,166,164,31,17,224,90,132,108,188,75,47,146,78,95,195,
132,125,84,248,80,135,8,246,80,231,138,72,195,97,236,202,4,112,130,69,29,51,228,42,218,199,218,138,246,95,60,36,4,98,179,97,130,86,20,154,181,229,29,29,15,49,66,213,166,82,67,16,26,54,157,106,33,36,201,
207,197,4,118,13,36,253,177,153,220,2,184,94,171,143,156,141,99,150,251,149,21,165,123,233,20,46,229,209,198,65,122,238,249,87,210,228,163,3,159,221,156,89,248,238,139,79,150,91,215,54,54,88,231,104,178,
102,12,194,192,8,169,86,215,23,129,18,242,224,48,80,166,29,148,33,111,75,168,133,155,66,218,93,255,187,171,46,120,95,129,190,41,220,207,18,224,1,136,104,108,45,43,152,181,90,194,179,61,113,77,91,8,6,146,
47,251,29,13,245,194,126,105,27,78,118,81,124,57,170,94,56,68,64,102,89,224,73,37,167,170,114,206,34,65,105,49,136,99,34,144,51,222,103,132,130,238,200,201,241,85,0,55,80,86,191,106,216,68,91,148,166,
65,65,217,52,215,150,212,102,41,170,60,105,145,80,220,133,86,239,186,190,86,73,222,7,29,31,179,241,72,74,171,39,148,87,117,254,28,102,164,237,4,85,61,174,225,15,188,68,144,25,220,174,85,128,2,123,191,
96,128,4,55,99,231,165,122,33,192,173,174,101,110,154,85,157,23,238,195,170,212,79,229,253,74,95,55,120,186,69,207,57,100,98,66,167,206,188,15,248,230,194,78,250,54,169,207,101,70,102,80,10,177,238,26,
142,69,56,219,140,97,109,135,87,101,12,218,46,104,248,176,42,191,151,47,106,187,233,168,45,239,11,55,71,161,242,179,174,71,22,39,76,175,137,178,60,187,64,222,33,161,93,59,65,187,60,94,13,59,42,12,64,91,
139,93,206,217,12,13,95,226,89,135,211,237,141,122,90,82,250,202,75,175,206,140,1,49,41,222,178,252,183,214,190,219,223,58,221,59,48,37,30,167,55,200,34,101,37,186,1,216,70,14,190,112,162,145,226,218,
139,45,163,60,149,210,120,202,154,235,93,95,167,252,22,241,12,50,196,109,215,165,27,146,83,129,147,0,48,135,23,172,164,60,3,161,149,44,117,129,141,123,70,238,236,104,236,63,148,94,28,77,57,159,34,142,
45,16,224,150,158,220,15,191,180,149,62,254,194,126,122,244,194,57,103,71,30,107,235,233,238,245,231,70,63,250,229,207,255,111,210,11,49,201,239,255,43,91,114,177,61,165,140,188,80,42,195,42,53,195,98,
140,178,164,204,112,112,59,99,217,106,20,254,163,111,115,8,132,28,52,188,40,232,142,203,249,98,140,228,73,89,174,198,66,246,228,85,25,30,43,190,98,91,117,112,86,57,89,117,41,19,183,49,253,163,174,9,212,
102,186,74,242,68,237,72,44,108,208,223,222,32,188,61,167,189,167,159,119,138,251,99,141,124,76,77,43,2,24,122,254,29,35,78,78,211,217,214,211,185,56,76,106,14,41,174,115,117,157,194,32,147,217,14,160,
177,13,158,125,88,56,28,140,157,2,100,110,171,122,156,190,176,214,73,79,254,197,191,146,190,243,167,254,253,147,63,241,236,211,63,61,245,237,127,177,180,191,137,209,161,231,143,92,178,194,20,95,168,216,
89,191,206,195,51,74,34,133,18,3,17,163,68,62,191,157,73,215,214,204,151,21,22,141,43,78,7,41,63,6,154,237,66,241,174,34,76,172,241,118,107,188,196,73,240,102,161,135,153,77,64,2,112,43,7,0,219,227,9,
102,229,235,111,153,63,39,119,113,241,192,31,152,23,196,22,39,54,106,165,16,197,87,240,78,175,43,203,28,41,5,108,54,74,233,203,17,1,80,194,211,194,162,17,247,63,46,223,62,39,172,141,85,2,232,179,253,154,
229,121,30,15,30,164,63,52,90,207,188,173,55,237,86,133,158,158,129,126,112,94,74,88,235,53,35,126,78,90,230,26,41,169,126,178,210,222,138,137,251,176,102,158,84,228,143,112,142,222,38,143,206,25,227,
17,5,99,137,74,60,49,8,185,136,134,71,59,230,177,138,149,124,186,112,106,94,155,148,231,172,101,230,140,189,56,101,231,146,31,66,65,1,18,93,208,152,255,112,165,193,104,100,210,215,24,199,231,160,227,207,
92,191,171,172,131,12,78,41,218,97,192,35,223,133,152,150,77,140,175,139,172,142,229,199,167,102,27,120,184,6,73,51,182,75,0,159,168,226,95,40,205,51,166,211,202,34,26,173,69,79,77,232,108,94,27,93,126,
119,141,44,76,184,52,195,184,171,171,105,29,157,50,134,158,205,24,53,179,37,205,218,165,84,25,57,231,136,103,48,200,64,142,185,215,241,57,132,5,227,98,198,108,189,142,173,218,1,92,53,37,221,207,45,118,
211,167,175,238,167,23,113,118,1,184,169,102,130,251,226,102,93,101,32,106,156,24,87,148,179,177,170,10,33,199,206,9,95,11,210,141,73,198,103,78,26,20,17,202,32,15,62,172,219,42,120,227,123,135,203,144,
252,110,58,111,208,118,139,103,29,29,154,78,175,220,52,116,122,123,91,99,61,165,6,148,237,191,240,76,186,208,172,189,239,218,173,123,239,112,184,191,239,175,108,3,16,68,5,37,211,214,43,224,133,118,90,
86,192,241,120,217,168,61,142,10,113,133,44,210,45,121,97,24,1,74,134,201,223,134,184,149,128,40,185,146,70,103,130,43,222,236,135,82,65,173,138,28,169,195,26,7,74,57,201,35,205,180,77,244,54,18,226,32,
20,28,207,182,195,0,28,155,67,212,17,6,7,45,237,20,206,110,81,30,4,171,19,30,28,8,69,21,202,229,106,109,133,189,99,7,219,70,34,191,243,210,75,95,202,14,246,126,185,164,142,90,93,219,80,55,13,160,197,248,
194,81,109,99,128,148,232,198,104,19,170,88,65,222,66,37,124,241,206,110,250,224,159,253,83,233,157,223,251,199,77,82,59,55,112,231,107,183,103,126,235,199,127,62,243,150,243,147,106,135,163,114,3,222,
157,117,102,111,82,79,24,117,138,55,29,166,80,157,61,109,79,166,133,199,132,133,168,241,150,120,253,241,9,20,58,94,36,114,237,19,6,227,4,152,181,185,12,25,148,235,4,59,100,200,48,168,246,160,246,40,136,
98,206,104,150,73,2,25,5,235,125,239,15,38,74,121,45,114,183,228,228,123,136,243,78,135,39,32,120,206,232,88,254,181,41,210,184,193,43,54,1,60,193,186,138,70,246,205,248,187,247,205,104,8,46,10,41,99,
2,76,16,66,162,33,32,242,209,109,255,41,49,42,145,64,52,228,107,247,228,32,95,11,126,171,247,38,155,81,103,7,202,248,93,46,30,202,49,40,116,31,229,33,49,123,251,211,254,242,66,229,65,207,41,186,113,98,
146,67,141,161,137,189,169,83,158,89,83,196,112,100,38,108,7,115,107,249,246,237,212,86,90,25,215,199,22,3,151,151,69,39,95,149,2,172,9,111,119,133,245,93,198,173,173,156,210,185,187,6,12,225,249,78,93,
73,143,62,252,48,150,23,3,181,187,195,240,170,113,59,131,186,122,207,49,131,211,222,219,77,69,36,145,235,242,239,143,221,93,78,47,176,20,115,83,74,52,234,230,93,169,79,133,17,235,76,78,42,232,199,181,
0,142,92,63,120,138,39,5,208,136,76,30,24,27,78,151,213,80,134,1,106,61,107,35,186,100,99,124,90,147,244,105,61,199,228,98,87,24,46,152,215,148,16,204,40,134,139,209,47,8,91,135,133,162,151,167,135,210,
219,30,24,79,143,217,117,66,231,120,73,52,70,51,128,111,221,58,76,183,110,200,83,25,193,158,216,247,1,255,118,241,117,136,209,118,140,220,189,107,42,31,160,44,88,100,109,205,222,227,238,119,142,129,153,
11,92,196,172,163,55,95,24,135,154,67,195,81,45,243,48,150,91,139,247,128,145,131,233,18,158,120,251,254,86,250,212,71,63,146,191,181,114,255,127,239,245,150,34,152,249,125,125,225,164,143,179,180,18,
107,194,29,116,178,45,222,72,26,104,83,19,112,197,172,149,134,48,51,39,12,43,240,80,251,39,172,138,60,115,152,103,140,38,227,67,97,72,207,118,175,29,60,220,22,47,19,27,141,195,16,15,206,185,33,58,59,160,
12,65,116,137,209,54,214,143,122,168,156,81,0,77,80,33,166,64,161,1,22,53,207,162,87,53,55,151,245,252,129,254,132,169,65,118,23,108,247,198,241,107,209,143,27,30,54,153,150,9,20,98,160,115,219,248,253,
8,219,216,126,57,139,193,207,242,187,81,134,34,131,228,222,133,214,45,223,147,199,12,158,77,111,254,131,127,80,7,66,140,84,105,164,27,79,125,46,85,183,239,97,150,204,166,213,26,194,128,67,30,180,215,179,
43,156,235,41,114,149,28,110,219,189,23,8,237,44,107,248,54,94,225,91,213,248,190,17,36,127,192,219,45,98,101,239,202,135,184,148,244,232,212,88,186,52,103,222,145,118,156,33,237,74,131,224,246,169,169,
115,152,74,24,76,187,247,132,74,128,47,84,180,117,124,213,104,77,43,250,156,0,101,166,132,132,115,194,226,30,84,113,194,121,207,18,222,142,176,209,140,131,52,47,97,12,250,225,62,176,107,83,120,125,194,
59,101,132,115,59,4,112,79,120,27,64,80,144,104,167,25,128,139,193,132,98,248,14,148,78,178,102,252,78,8,219,134,25,199,125,192,14,221,20,14,134,72,235,153,244,126,120,36,114,187,8,235,0,24,12,132,120,
83,168,72,224,133,200,21,74,234,146,244,67,122,150,241,25,12,197,16,143,176,31,121,56,15,220,244,253,142,107,9,38,204,186,103,28,68,131,19,215,83,51,149,161,17,30,198,207,207,41,43,61,32,82,121,216,24,
154,243,35,227,154,168,7,161,154,186,146,164,52,163,53,57,190,154,117,164,66,89,202,21,243,123,175,191,98,208,22,67,244,228,153,169,244,94,109,133,177,237,45,219,211,74,95,152,238,51,192,242,104,169,81,
3,206,162,137,138,80,211,186,247,18,164,162,110,91,179,193,128,215,43,115,34,48,141,209,148,41,39,74,58,137,185,57,66,251,173,109,180,207,96,86,153,65,85,81,202,59,177,104,40,38,50,198,102,130,64,123,
167,180,25,158,154,115,126,246,215,76,72,7,122,134,87,231,75,229,116,230,148,136,75,61,56,131,240,62,172,49,96,198,76,171,34,166,216,185,7,78,139,26,145,241,137,115,76,180,232,245,17,109,53,96,50,187,
21,35,94,57,155,51,222,251,2,121,59,142,148,6,80,250,241,151,154,105,113,3,163,78,180,183,165,187,232,11,207,125,46,109,124,245,83,239,91,93,221,127,200,227,248,125,125,229,135,192,255,237,93,21,172,205,
153,132,142,40,15,68,62,208,219,24,7,19,232,103,121,42,44,144,28,135,117,69,36,130,108,10,132,120,196,35,148,166,3,249,106,48,53,6,48,82,142,52,16,71,248,27,176,254,232,76,76,10,144,239,200,39,107,138,
223,89,128,192,69,33,194,144,3,205,66,53,51,190,23,43,1,182,188,87,205,123,5,28,127,137,197,205,210,232,8,91,187,250,26,131,23,41,11,246,160,29,30,79,215,255,34,117,65,86,239,11,97,65,70,40,71,8,54,207,
1,107,223,3,28,140,217,174,245,37,44,231,247,124,224,131,105,116,98,94,152,14,232,17,186,124,238,195,191,150,94,107,244,74,160,200,177,104,103,104,116,70,219,210,152,88,16,232,34,4,28,149,255,70,120,151,
179,111,164,211,28,178,12,8,71,151,37,63,64,122,143,53,5,227,62,28,31,165,239,125,130,56,63,185,160,27,67,196,80,224,122,78,60,164,54,32,43,102,211,156,4,3,72,120,219,49,199,38,186,58,176,202,68,142,199,
233,65,90,48,226,62,183,80,30,51,114,172,186,208,114,132,241,169,224,162,158,143,50,9,79,151,163,152,121,150,122,77,66,125,137,1,136,165,80,77,202,52,72,217,98,55,241,146,243,29,165,52,151,68,202,145,
255,77,243,232,135,20,45,58,89,206,203,173,166,241,140,143,33,172,3,18,203,140,159,141,81,46,49,213,98,102,198,164,196,219,117,10,40,231,245,186,24,40,45,18,21,222,58,204,200,25,253,252,109,128,90,76,
160,136,252,190,199,67,4,1,101,18,227,102,68,226,218,49,217,112,91,216,252,58,157,37,21,222,187,5,177,220,39,220,91,248,212,155,80,215,210,156,126,95,158,178,189,113,85,237,120,28,158,48,98,154,132,16,
85,227,252,37,147,212,99,61,99,12,55,251,168,205,232,25,165,137,119,191,121,42,61,54,142,62,167,133,172,33,183,206,154,51,20,172,36,159,44,125,224,149,93,251,161,200,42,210,164,19,67,191,83,111,18,123,
10,123,137,137,135,33,123,246,218,182,134,145,91,164,45,235,27,114,64,215,123,110,108,72,9,74,233,195,251,204,75,199,218,65,56,112,63,57,57,127,71,222,222,117,198,69,215,126,34,253,56,130,165,148,120,
240,220,240,118,58,109,159,74,91,46,60,116,198,128,48,225,238,98,132,173,40,153,93,96,81,129,231,238,136,88,182,84,5,66,110,121,3,160,163,20,80,196,23,121,195,16,175,60,195,72,188,96,177,215,10,22,88,
13,27,236,145,171,123,233,141,99,82,68,50,81,228,68,46,157,216,234,190,250,242,63,34,62,239,124,85,128,255,219,254,155,141,124,100,4,244,142,183,146,114,147,166,166,64,24,219,232,121,158,13,48,1,243,227,
0,147,227,200,200,15,225,71,9,35,163,41,198,157,20,214,22,89,209,30,133,141,205,94,29,7,212,161,96,49,128,43,10,223,116,66,147,45,240,198,1,5,145,58,170,130,139,98,247,29,66,184,47,135,29,19,167,15,11,
25,235,184,181,91,58,42,246,112,56,147,209,152,219,64,159,224,200,78,240,60,5,198,33,43,87,61,32,185,163,172,108,40,82,120,132,150,223,1,147,66,98,57,173,207,201,40,250,103,121,245,222,184,215,235,47,
108,241,32,15,126,215,55,216,242,21,237,101,157,244,153,223,252,245,180,125,239,174,189,142,202,0,26,123,247,36,104,107,200,208,67,60,92,244,168,173,59,244,33,57,203,145,50,202,49,164,56,16,60,48,0,175,
68,225,60,142,186,124,52,6,66,103,77,114,87,66,3,114,33,78,152,131,26,19,240,186,132,116,55,90,178,252,90,219,19,118,178,192,97,44,14,69,17,69,231,81,247,144,43,131,147,198,102,104,125,130,80,159,33,40,
227,206,240,44,214,201,2,97,172,140,26,219,161,141,108,4,178,56,233,148,166,77,152,184,100,252,104,145,55,202,2,97,166,132,141,243,33,88,60,220,113,68,41,206,116,72,29,215,22,137,40,151,166,219,226,123,
178,214,31,211,33,85,195,78,210,95,138,232,48,70,16,247,60,155,69,163,228,111,213,71,208,24,77,59,247,239,119,68,42,89,57,105,209,123,74,171,82,81,8,152,247,140,67,233,163,108,130,6,139,16,128,198,40,
63,222,18,142,119,33,178,69,209,196,40,96,110,157,82,126,222,53,44,169,71,150,24,204,24,34,29,235,28,247,252,76,132,145,27,157,29,134,86,247,14,18,123,150,97,91,18,113,124,188,122,152,62,97,205,199,117,
23,137,254,155,30,58,131,35,43,223,190,171,61,240,30,74,224,178,2,127,203,106,139,147,6,116,151,130,199,40,22,65,162,233,134,202,27,64,163,41,181,215,60,0,169,37,140,14,249,202,51,92,117,6,41,122,59,247,
125,86,172,235,200,29,161,28,50,246,81,242,136,201,29,139,120,190,129,188,31,242,212,43,91,34,45,108,158,8,250,203,238,97,196,180,132,22,203,116,68,70,142,240,74,87,96,19,199,100,182,227,190,74,222,171,
110,241,213,182,232,109,91,247,84,133,99,26,146,2,237,186,198,101,250,113,172,57,225,2,214,210,156,144,56,167,209,162,166,41,63,163,76,54,107,140,78,199,251,102,45,187,122,246,14,112,206,147,124,200,51,
92,96,148,139,139,207,165,98,117,233,53,155,155,183,190,245,191,77,45,95,253,233,124,16,14,118,175,14,10,209,120,72,164,243,174,98,250,49,56,57,154,116,143,131,176,14,34,143,49,248,187,220,64,23,59,99,
142,16,79,15,33,138,187,128,106,112,92,61,168,24,126,84,223,221,112,3,15,243,108,3,106,85,14,131,64,140,83,52,162,173,75,161,151,190,174,7,110,69,55,64,15,185,249,88,168,19,83,195,201,168,24,253,76,26,
209,189,210,19,102,100,113,112,99,242,193,65,21,93,80,248,208,245,122,242,147,106,148,1,130,211,87,252,24,180,201,217,121,88,90,125,88,252,1,33,94,219,220,91,102,61,125,245,203,75,233,29,223,247,103,211,
153,7,31,241,3,4,233,229,91,233,133,143,126,54,61,56,199,171,1,162,114,200,2,75,144,215,253,7,204,35,66,15,202,32,54,196,138,246,41,209,67,134,130,196,238,198,182,249,186,99,154,106,75,192,154,5,247,130,
63,66,169,129,93,90,187,102,216,239,117,239,155,235,79,227,66,206,16,82,86,185,94,21,168,52,60,35,167,134,204,118,24,15,241,163,238,26,215,135,26,57,227,161,181,121,131,170,135,27,141,194,230,141,51,90,
77,222,192,116,4,145,74,140,95,204,69,88,43,37,8,34,194,24,128,175,66,65,94,157,225,194,248,8,63,115,106,41,99,65,254,38,96,222,170,63,112,42,50,8,228,24,172,26,161,166,51,25,117,198,29,130,215,164,104,
108,6,17,137,210,23,65,150,83,15,8,129,79,57,191,17,158,114,214,81,197,6,173,50,131,178,77,97,246,120,221,211,192,149,193,40,155,76,202,162,125,192,152,115,40,217,49,18,228,250,1,202,204,209,227,218,22,
120,111,163,44,109,138,106,225,43,143,243,136,86,139,186,150,122,26,115,86,43,114,182,62,27,71,222,125,209,153,122,204,105,69,253,115,80,163,117,94,42,244,16,163,50,98,176,120,85,79,232,25,74,61,230,186,
87,55,202,150,70,249,92,13,168,57,205,4,227,186,73,90,97,168,165,79,99,82,162,3,222,115,32,43,239,117,38,121,158,49,172,178,173,172,26,170,229,126,0,193,225,202,172,188,218,243,33,36,145,170,196,62,27,
49,177,63,43,167,72,205,246,35,39,22,9,29,163,80,110,57,199,67,255,214,19,21,230,133,178,1,210,181,45,48,110,217,119,217,58,217,146,182,48,192,148,52,43,207,159,188,96,170,161,231,213,225,53,39,0,75,29,
150,44,26,178,195,145,197,214,246,124,127,236,163,215,106,181,124,179,210,219,166,136,168,223,51,203,8,189,112,93,26,38,233,239,105,4,201,22,183,112,252,175,142,108,62,219,251,174,205,222,230,211,51,153,
153,87,89,52,175,234,222,127,245,191,217,236,61,59,35,184,224,253,157,237,116,120,147,176,170,233,197,100,240,125,44,154,19,205,176,29,219,166,194,107,229,129,53,2,41,66,239,65,89,38,123,194,66,139,118,
65,214,214,15,232,14,239,110,139,201,67,0,29,95,12,88,141,145,140,89,15,110,64,237,241,12,215,31,176,123,5,248,132,205,204,218,193,253,121,176,140,7,20,171,214,207,65,133,13,71,77,135,58,100,238,91,86,
186,201,75,237,250,220,88,166,20,168,42,243,221,191,17,162,39,188,244,87,64,67,199,196,64,166,65,158,134,229,162,89,246,64,110,186,56,52,135,173,241,46,69,105,22,15,27,230,75,255,226,103,83,251,234,167,
210,107,46,105,123,139,169,123,242,1,254,14,91,105,74,253,118,65,78,182,140,212,77,180,61,244,1,176,104,70,88,42,18,231,25,34,28,141,124,9,232,194,155,14,50,84,25,15,169,43,164,29,82,235,28,82,46,136,
61,163,123,206,165,42,31,141,161,83,51,115,138,51,241,196,25,175,150,252,44,20,226,196,123,136,87,213,79,107,86,69,8,211,181,185,77,202,123,246,213,10,215,41,78,75,141,36,192,155,150,124,170,19,233,2,
131,211,19,105,68,132,208,21,146,197,164,5,38,93,184,42,84,99,0,150,209,12,63,143,208,29,131,110,71,166,255,95,170,33,239,57,69,153,166,189,106,150,49,11,160,167,8,49,61,98,207,78,182,205,187,15,138,91,
124,207,155,58,110,139,126,148,196,28,41,219,217,159,38,120,64,73,179,140,77,144,160,76,146,18,233,50,130,120,186,209,97,82,147,111,222,14,18,136,200,4,121,169,63,207,39,136,250,71,132,115,96,140,66,80,
202,22,6,68,236,50,29,36,12,51,62,160,160,172,19,245,203,225,94,53,189,217,229,191,221,36,131,82,227,64,207,231,73,186,183,121,207,253,145,29,43,32,218,166,23,12,140,139,44,32,192,185,93,19,8,120,226,
57,175,215,115,238,89,49,26,20,56,136,235,209,220,16,235,254,166,121,173,158,176,255,44,101,157,80,75,238,68,4,131,108,112,160,252,215,84,146,11,175,58,100,194,95,215,152,195,38,88,187,228,89,199,198,
239,209,113,207,157,119,207,56,147,237,168,173,242,184,195,6,8,196,104,215,156,20,42,184,181,187,48,129,72,179,248,11,225,53,14,248,50,204,192,80,169,136,160,198,144,80,38,180,8,237,49,58,91,40,136,131,
136,28,17,13,230,24,145,72,133,10,176,142,97,142,129,168,96,123,245,210,175,46,173,226,80,103,211,247,190,231,108,58,251,186,32,94,92,79,75,119,87,255,244,199,254,238,63,63,215,23,226,255,134,255,100,
51,224,230,30,228,224,80,152,150,151,107,197,170,237,30,180,118,224,104,74,248,195,53,187,226,3,19,219,209,82,9,31,226,49,247,191,174,16,78,116,4,194,0,4,201,239,0,184,59,7,93,205,137,133,187,44,232,244,
105,37,9,2,112,67,45,168,193,226,183,32,178,123,174,254,44,1,35,155,253,156,39,42,64,91,146,153,175,221,184,145,246,170,194,199,173,131,180,190,115,156,206,76,206,164,211,179,23,113,107,133,136,242,129,
77,86,88,148,215,255,138,126,209,172,178,67,215,205,183,49,74,134,36,234,37,208,252,25,249,215,87,174,87,211,227,175,121,34,205,188,246,13,132,227,40,237,222,186,157,158,249,221,79,165,135,79,43,30,179,
162,199,242,158,188,34,251,174,112,171,75,184,251,155,183,25,139,81,247,157,11,54,12,129,156,138,80,36,20,158,144,228,212,76,235,218,161,14,132,188,39,194,205,10,104,249,196,235,3,228,25,231,33,249,45,
141,213,194,109,117,209,60,55,17,11,141,142,240,107,53,67,234,224,176,235,196,96,234,28,235,63,198,219,21,161,146,115,88,55,103,133,155,29,43,9,57,124,97,158,230,114,81,201,46,69,222,119,146,252,25,211,
7,167,101,255,34,113,175,109,71,233,67,27,147,60,124,23,192,177,226,250,119,132,119,181,72,23,124,124,132,239,202,170,198,59,242,72,4,44,64,243,50,13,172,48,24,93,140,171,162,123,136,146,10,177,52,157,
63,165,77,255,190,230,181,123,155,156,11,133,142,156,76,106,36,18,98,148,40,92,141,70,236,136,128,14,24,216,6,182,141,63,242,238,162,15,169,71,14,96,23,69,253,50,133,153,118,63,177,232,87,217,150,1,83,
122,83,3,138,156,120,28,138,59,3,8,26,4,47,223,20,146,223,196,69,174,43,47,108,88,211,232,167,109,34,167,56,188,240,177,217,78,215,1,82,85,8,240,49,229,88,221,191,206,33,154,95,44,58,168,171,139,154,109,
64,70,212,215,205,90,10,14,216,38,20,59,48,139,35,141,248,53,207,53,79,222,90,114,252,88,242,213,226,60,98,9,87,69,212,167,161,170,127,205,3,56,214,5,138,30,159,186,231,222,162,181,108,102,182,210,167,
148,102,221,79,67,180,119,12,144,203,3,242,26,74,127,117,131,200,71,22,12,239,90,152,197,146,147,134,33,245,239,170,183,16,247,52,105,246,109,69,10,212,214,66,70,8,120,195,33,169,4,64,72,57,113,216,231,
199,120,153,224,222,26,162,8,104,50,100,140,35,137,62,219,160,254,189,6,50,188,141,22,251,204,199,111,167,151,239,220,73,3,11,179,191,218,234,109,62,224,109,127,207,95,217,194,228,37,55,3,124,160,60,33,
244,135,188,148,32,149,128,184,91,135,113,71,17,126,93,247,122,32,132,121,245,201,0,65,186,194,222,6,75,41,111,239,131,19,49,96,121,115,103,171,79,50,232,7,159,4,97,219,131,175,11,43,218,181,129,180,126,
215,28,85,135,149,21,114,69,173,173,161,76,49,172,121,57,230,231,176,143,253,144,53,214,172,149,89,248,33,147,213,247,238,86,83,186,183,7,65,117,180,76,60,25,235,127,101,253,185,198,37,4,123,168,203,235,
244,92,235,56,0,32,207,21,172,66,22,191,227,207,252,105,30,48,64,12,134,162,126,21,16,32,135,22,134,213,116,145,20,9,230,140,67,13,138,27,234,100,191,147,102,191,122,191,239,97,225,31,242,14,117,78,222,
42,188,86,88,193,174,156,243,132,160,78,8,133,7,8,123,148,28,180,161,90,68,212,116,38,123,118,108,178,164,106,117,99,35,193,248,225,169,8,76,236,132,137,166,243,46,175,19,202,112,221,16,226,93,94,23,185,
68,56,171,189,141,162,229,15,98,180,135,146,14,174,239,40,165,166,175,44,241,128,200,66,174,233,53,61,70,194,37,162,195,1,218,116,139,148,105,193,32,175,31,131,186,51,74,9,61,32,74,55,8,10,158,71,132,
17,117,140,160,24,101,178,71,121,215,120,90,3,10,156,167,176,21,128,19,172,33,14,195,163,36,72,190,61,206,24,204,199,7,186,63,246,151,216,228,231,0,0,32,0,73,68,65,84,55,184,9,253,158,207,134,231,25,189,
143,193,25,158,136,231,47,255,92,133,198,230,9,254,69,50,209,195,255,29,22,197,196,138,219,35,109,103,67,194,66,211,68,133,171,122,100,199,133,231,64,182,104,12,223,143,176,212,53,103,212,39,203,89,205,
231,133,85,59,83,129,39,138,246,65,90,60,50,110,114,7,130,155,141,178,210,42,3,73,241,78,24,39,143,158,65,245,172,68,30,61,202,53,203,152,151,140,29,29,148,63,86,186,203,106,164,240,16,30,189,82,193,190,
194,54,57,226,193,122,34,175,3,6,172,64,150,50,168,136,251,162,45,11,210,210,160,57,200,99,147,74,31,250,138,99,65,85,179,198,128,48,22,67,163,147,175,226,12,174,177,46,122,203,67,250,253,193,89,58,32,
237,74,89,74,150,83,103,30,59,151,79,211,23,245,182,42,207,161,29,200,135,49,188,116,222,156,4,37,80,20,112,2,120,200,73,193,114,118,184,244,24,148,40,247,157,134,211,252,9,205,4,125,250,162,231,120,72,
62,175,223,71,134,151,218,28,238,145,5,235,78,38,114,133,71,111,124,225,234,95,245,24,126,207,95,217,156,80,48,166,228,13,40,73,12,57,236,129,49,222,16,133,47,128,151,99,22,204,180,31,197,116,150,140,
7,219,11,243,196,226,106,58,17,210,48,38,44,112,209,207,48,92,253,201,234,45,35,69,156,7,75,71,0,8,140,42,76,42,196,124,30,241,124,223,75,176,198,75,68,175,10,205,188,41,116,168,66,116,195,194,71,94,213,
18,138,100,133,135,205,118,141,16,235,160,39,104,77,200,110,141,4,45,24,3,143,187,27,79,93,254,5,61,163,104,102,112,65,234,8,33,175,118,162,43,97,154,192,142,65,81,243,80,202,200,59,246,132,172,5,104,
235,168,11,170,16,50,233,139,230,1,86,215,245,85,28,104,4,48,25,53,170,17,252,208,33,130,23,200,110,87,248,162,68,217,191,222,6,178,127,244,48,100,184,178,2,14,104,158,119,137,21,242,17,178,238,4,105,
32,72,21,16,201,162,146,75,49,63,229,51,229,231,106,180,44,135,243,59,52,80,89,179,174,213,129,93,141,219,193,247,29,127,128,4,6,222,135,109,49,28,0,147,220,165,65,16,139,106,155,3,106,37,189,200,253,
252,124,129,129,168,59,251,18,82,68,101,148,192,2,96,134,121,246,83,56,157,131,180,183,191,254,130,145,139,25,76,37,66,224,200,81,252,60,143,48,43,254,174,130,193,211,57,123,101,145,209,248,25,247,19,
229,18,76,204,148,13,218,98,88,118,63,186,195,2,57,18,229,39,175,4,130,225,53,232,84,97,112,61,159,32,17,132,193,114,216,233,18,229,135,107,3,71,244,119,18,236,33,155,217,198,78,157,233,15,103,219,51,
20,226,40,72,43,140,230,58,67,188,25,125,170,194,228,30,50,70,23,88,146,71,176,40,83,248,93,138,20,187,74,6,24,164,172,63,143,2,226,122,120,219,81,135,60,210,30,216,96,24,15,246,85,7,156,249,182,6,237,
181,200,244,117,2,245,2,13,246,62,209,114,167,199,153,121,163,68,158,247,152,201,129,96,25,216,8,37,198,195,205,178,248,67,62,247,200,251,173,168,213,238,40,215,52,76,114,156,211,173,212,20,54,221,19,
70,111,25,216,214,241,108,134,167,121,86,10,214,100,76,11,66,236,104,62,207,232,50,105,172,48,30,20,178,101,112,90,33,186,113,200,227,117,148,207,53,128,229,172,68,61,244,162,167,147,167,140,201,148,7,
38,221,7,190,173,9,129,98,241,22,233,64,97,164,232,28,218,174,20,163,70,6,127,235,5,84,198,198,152,116,161,146,22,111,222,72,27,47,127,205,68,255,181,15,236,236,44,5,239,246,247,244,197,121,233,111,3,
92,150,228,53,5,185,98,89,109,113,172,171,51,220,67,234,198,80,35,73,113,172,231,46,176,64,57,249,74,200,95,76,27,143,248,28,166,65,169,49,71,124,84,8,71,215,123,69,219,196,232,67,44,151,159,155,181,59,
175,138,205,191,33,89,63,86,42,216,162,204,209,230,84,1,164,196,22,171,182,156,38,70,144,156,200,83,234,66,229,219,194,140,29,202,215,244,153,89,74,57,193,27,76,249,243,249,71,43,165,110,166,251,116,213,
42,236,74,145,21,99,165,199,29,112,108,181,14,38,210,243,242,131,43,111,123,75,191,96,46,232,235,135,23,215,190,188,217,231,79,238,187,214,160,234,5,156,222,132,6,70,70,174,25,193,235,140,214,220,18,242,
81,242,186,94,194,150,7,28,97,116,6,202,139,21,150,206,232,190,24,231,133,139,66,204,193,0,157,8,89,76,196,27,162,196,3,120,193,199,17,234,107,165,58,20,58,53,229,35,38,106,165,5,113,228,136,195,26,84,
120,159,50,177,237,188,225,214,177,237,57,236,74,94,142,20,96,81,44,230,25,80,158,80,148,32,120,14,144,34,20,176,155,246,182,245,99,120,239,54,80,33,90,247,230,77,177,30,116,239,209,136,16,59,76,207,137,
16,154,128,162,61,63,83,36,136,163,188,91,153,145,9,102,149,168,83,1,156,167,97,48,99,118,237,54,22,122,157,197,142,6,237,216,250,22,99,74,98,18,127,116,177,172,71,73,92,110,58,226,163,135,188,246,80,
4,18,93,122,179,51,104,118,158,111,131,2,207,120,160,81,96,31,115,254,231,213,91,105,95,186,169,20,226,120,80,223,68,54,85,32,147,207,233,4,8,228,254,98,38,79,131,34,53,68,27,219,66,212,106,148,139,200,
65,213,57,198,252,87,227,54,188,69,228,143,188,179,191,47,91,125,113,223,252,161,221,250,78,159,92,65,210,24,149,32,67,200,239,196,218,21,50,50,13,37,55,0,137,33,212,3,172,100,18,232,241,22,72,250,8,58,
223,102,16,2,61,152,32,184,77,211,251,10,184,178,19,100,226,40,64,54,164,133,58,132,56,122,59,203,218,250,78,77,89,33,56,109,222,145,188,44,131,220,210,3,125,199,136,154,99,14,35,71,137,178,209,173,68,
217,91,206,180,139,105,86,221,48,14,229,174,136,40,242,87,32,226,54,153,61,86,159,239,28,51,4,188,205,168,154,110,59,235,126,160,205,19,28,211,24,175,94,16,186,7,154,126,89,152,94,114,15,1,218,237,170,
43,95,191,1,36,5,129,23,81,35,239,189,242,197,116,240,210,111,143,183,238,191,240,61,191,39,205,244,67,89,101,52,15,33,232,91,242,49,222,42,122,18,207,149,149,13,36,122,203,86,177,237,3,64,50,172,119,
116,29,132,135,229,249,251,253,134,147,30,48,98,159,3,9,154,53,69,229,253,34,87,202,129,209,155,91,161,96,106,136,194,224,183,124,195,131,233,137,179,103,211,16,37,189,32,52,121,192,197,95,2,51,86,112,
56,123,208,175,33,74,51,116,5,18,232,93,162,166,199,169,80,248,94,178,193,205,195,4,233,179,154,153,169,108,121,166,252,214,95,29,168,126,245,123,6,16,205,43,177,87,83,191,222,120,228,48,186,102,42,133,
243,233,123,126,228,71,33,166,134,72,81,216,141,231,174,165,207,124,226,121,173,99,121,227,50,24,23,22,45,72,10,17,9,154,194,146,46,233,60,232,225,209,54,133,52,48,135,254,130,154,1,66,186,191,163,131,
3,242,183,227,192,123,0,176,172,220,139,78,234,152,129,214,66,223,230,241,94,79,11,25,192,17,105,73,36,113,221,207,222,132,146,110,202,101,194,219,157,176,72,39,66,158,188,142,149,146,92,101,47,163,254,
167,79,118,152,84,95,191,13,100,195,64,26,210,28,48,219,181,212,87,49,165,125,52,150,154,38,65,180,7,236,87,97,176,54,8,77,63,199,85,26,104,243,170,39,234,103,21,214,60,166,158,111,11,187,14,161,185,11,
232,132,209,44,189,227,153,153,226,195,242,167,244,196,235,166,128,65,186,71,156,237,22,5,220,14,99,66,145,110,136,38,154,66,133,104,253,91,117,159,241,222,131,254,28,94,52,114,133,61,2,180,47,191,218,
219,117,239,145,123,139,98,34,252,13,30,116,221,235,194,27,157,30,211,181,227,179,54,197,193,227,192,150,24,75,211,218,213,12,207,130,141,77,132,130,32,190,51,234,145,247,5,181,42,122,40,103,61,151,97,
130,191,74,73,115,206,112,202,89,53,52,49,55,133,200,121,235,54,50,74,75,21,74,63,0,235,152,97,232,34,100,220,216,95,102,0,17,84,120,186,1,165,148,137,184,49,45,128,163,206,214,252,126,35,69,122,233,43,
117,3,197,148,92,96,183,0,164,48,185,177,17,79,250,225,102,42,21,236,34,113,252,0,131,55,142,140,159,49,74,229,62,164,56,167,217,97,12,45,180,194,249,100,112,143,155,203,185,116,235,166,239,71,77,90,180,
114,251,64,186,177,54,152,214,224,31,121,242,61,44,21,218,177,122,228,64,81,191,38,2,233,202,169,155,194,239,166,233,10,35,34,183,216,186,215,35,251,37,132,148,168,241,159,198,172,10,107,46,54,72,15,217,
133,241,186,126,51,3,187,194,168,124,124,17,41,1,208,249,141,167,38,32,226,219,169,179,245,133,148,221,249,250,95,93,95,223,252,59,142,249,191,250,165,172,231,112,34,132,133,20,14,144,196,42,12,250,133,
234,110,186,46,20,59,52,49,61,38,223,21,20,176,149,127,210,53,191,150,184,158,96,111,24,158,233,6,61,15,72,87,60,235,6,165,32,69,60,5,75,68,128,55,61,156,250,130,164,126,108,202,216,7,214,148,85,143,9,
223,93,10,24,137,247,6,18,243,24,79,118,89,95,211,9,80,101,20,82,155,119,45,177,77,171,67,192,182,8,203,71,181,237,220,136,208,185,125,57,244,63,157,122,225,87,191,218,196,6,105,129,84,239,238,25,116,
49,5,186,190,187,151,166,48,78,78,191,238,97,32,177,137,227,181,106,250,237,95,251,55,44,236,114,122,232,146,48,145,192,198,246,103,206,168,223,219,216,70,101,43,27,212,21,22,229,16,250,202,177,184,126,
97,80,196,189,49,194,223,253,132,171,169,123,48,45,22,90,7,82,63,204,41,120,48,187,90,209,118,192,234,53,96,142,9,185,12,138,221,143,208,104,85,79,220,100,15,149,181,222,23,99,118,228,192,49,76,234,192,
240,169,35,33,235,42,207,186,97,58,93,76,162,43,240,168,27,194,212,77,22,255,136,193,122,208,24,152,18,139,123,131,242,53,89,243,57,130,59,64,112,183,120,168,186,115,143,73,241,177,225,42,24,92,151,68,
23,111,213,37,164,242,3,24,131,18,138,104,198,93,110,245,101,158,104,89,55,8,225,138,102,234,60,47,20,192,113,140,189,132,95,128,254,9,148,243,140,41,119,69,4,238,34,35,89,154,97,0,162,248,232,123,234,
70,128,61,247,11,44,137,42,81,213,107,110,242,202,45,134,161,30,192,11,69,45,11,105,247,196,195,7,20,216,180,72,83,208,53,54,179,0,131,59,158,61,39,183,163,180,209,54,173,175,141,45,35,53,35,79,122,75,
67,70,40,196,33,160,172,142,182,183,224,31,206,64,143,102,253,125,68,52,81,32,212,77,104,120,164,12,243,33,55,222,191,46,162,218,207,110,200,161,23,177,111,48,118,128,80,121,41,215,132,52,32,38,174,183,
181,215,237,162,152,6,115,72,213,175,143,63,28,136,178,98,215,107,68,33,195,60,225,54,146,252,238,17,26,157,51,58,18,142,119,163,250,96,88,122,240,95,151,128,142,199,217,89,169,12,0,135,183,3,24,203,119,
113,180,37,209,57,50,64,205,201,14,10,43,103,53,39,156,29,142,17,62,98,252,24,80,62,36,20,9,40,180,102,181,196,166,218,102,94,105,48,234,195,33,247,5,209,69,157,19,152,119,79,13,103,245,41,225,249,103,
56,142,79,3,133,76,252,132,210,171,185,146,145,76,230,70,186,241,252,39,222,127,216,59,92,248,175,105,103,118,231,1,118,41,96,253,168,205,17,150,146,15,171,177,168,117,150,101,28,140,95,82,166,104,226,
217,110,120,88,46,67,237,142,98,249,247,61,165,129,105,22,62,143,24,29,202,25,64,15,195,204,203,178,184,243,14,201,95,38,200,251,243,79,127,37,21,88,144,71,8,100,228,63,7,60,84,94,173,105,92,40,21,179,
247,94,92,211,11,183,2,48,194,15,13,13,108,81,158,16,172,216,31,146,71,74,8,114,250,197,55,158,238,223,71,173,52,203,158,234,58,113,0,15,200,245,238,222,109,166,175,235,228,126,226,143,253,33,232,42,79,
3,164,249,173,159,253,153,244,137,95,254,215,233,61,175,29,73,15,61,112,133,87,42,163,193,9,71,41,124,86,62,178,27,219,200,102,47,67,162,79,0,83,242,41,31,154,99,157,35,23,109,203,39,58,70,131,142,187,
191,146,247,141,49,151,227,242,174,161,40,93,80,238,178,16,122,95,110,25,33,220,56,165,9,166,120,87,25,196,141,244,107,147,37,253,129,177,227,36,114,225,156,80,52,150,219,50,109,125,36,59,163,6,87,85,
214,200,200,225,64,26,4,83,142,231,207,67,66,231,77,138,17,115,124,142,253,186,125,123,139,86,9,39,17,171,39,141,44,137,38,3,250,65,64,219,114,168,124,122,147,50,82,217,153,208,27,0,132,210,5,195,83,167,
92,225,185,55,89,160,5,151,19,105,138,136,203,53,250,140,248,187,211,179,153,93,202,162,148,162,188,179,193,227,199,234,84,143,64,244,227,172,213,175,143,92,119,236,35,105,122,127,47,245,179,140,164,207,
93,103,12,221,102,154,102,228,162,92,17,147,38,56,84,249,162,231,8,77,238,0,99,138,241,192,2,222,109,172,16,110,117,67,190,172,39,148,139,186,120,70,52,144,5,138,13,136,60,58,74,110,251,230,20,245,178,
187,0,43,180,67,224,209,9,33,143,249,79,221,33,13,212,106,219,99,216,59,45,50,24,70,127,206,192,46,182,0,115,42,118,246,104,144,183,254,160,168,181,236,43,7,107,233,5,86,40,70,222,8,254,129,61,140,152,
28,61,118,247,228,145,7,162,127,52,154,50,98,172,77,211,28,170,6,195,58,61,62,47,162,201,167,7,174,148,210,19,151,7,205,166,66,200,111,207,184,31,205,218,188,117,77,180,211,129,112,54,226,25,185,225,136,
202,42,100,187,128,80,31,92,228,142,95,196,199,253,1,56,133,191,55,57,129,168,95,183,213,189,123,12,78,91,101,163,42,218,106,11,219,223,58,7,135,24,51,205,16,18,104,234,77,250,90,85,170,177,166,33,221,
70,133,129,17,83,1,143,247,159,248,197,127,250,145,247,56,230,255,223,47,196,255,215,247,121,138,253,5,60,78,162,4,57,44,176,68,199,146,229,33,240,215,160,164,186,3,184,137,135,124,142,195,201,43,165,
192,16,12,12,38,155,33,196,172,96,8,68,8,75,124,229,221,212,234,193,76,90,16,222,4,177,29,81,131,217,24,96,141,193,230,44,100,52,102,55,116,7,180,120,139,92,116,174,75,240,251,24,41,229,13,230,138,212,
198,13,246,210,89,146,243,14,101,130,39,128,32,3,146,247,248,138,249,66,7,120,157,35,51,60,155,53,214,47,175,228,211,31,255,235,127,61,93,121,255,7,92,64,39,221,253,242,189,244,239,126,229,19,233,189,
111,153,49,81,97,40,61,255,202,102,191,179,36,38,174,100,25,23,213,45,104,168,109,87,83,23,128,89,254,44,68,42,50,54,195,96,117,204,178,244,149,77,194,231,70,134,40,97,67,255,97,3,40,16,187,54,91,144,
196,35,194,159,204,40,90,7,44,44,42,225,196,80,234,17,57,204,32,84,117,147,130,30,203,211,243,8,210,81,187,221,19,1,212,13,175,26,56,89,85,147,83,212,230,37,114,126,54,131,75,27,198,172,50,97,236,135,
232,162,39,255,108,16,238,219,148,114,15,85,174,96,104,245,145,124,53,184,185,145,135,69,46,73,182,24,14,138,226,60,243,226,209,130,168,35,162,150,64,191,93,145,136,32,192,27,235,27,228,106,227,206,144,
62,51,34,60,10,65,10,195,195,222,246,115,197,208,80,71,222,47,25,59,42,179,110,133,226,60,37,221,78,139,91,175,150,34,98,202,97,164,57,49,6,230,148,247,142,77,108,91,128,152,0,208,98,134,145,129,233,148,
78,168,236,239,51,200,43,175,65,151,204,105,116,142,189,182,145,79,15,107,232,126,144,59,211,106,173,239,83,248,203,80,123,226,174,93,177,136,75,222,37,224,85,17,66,207,238,145,2,37,40,106,196,111,181,
70,208,56,125,207,104,203,142,201,254,19,194,224,168,185,238,10,213,26,144,239,97,206,33,15,160,28,157,52,47,80,202,116,255,104,35,93,3,42,173,201,225,219,104,163,39,228,175,179,63,169,164,162,75,42,234,
149,20,109,44,70,92,158,172,165,12,90,106,117,117,13,31,91,47,170,92,254,200,117,243,131,104,170,144,87,231,113,50,84,245,58,224,149,156,117,7,153,97,75,9,164,214,131,168,45,120,30,44,211,1,160,42,200,
52,37,103,191,11,89,223,21,29,236,139,44,3,131,152,102,180,143,164,23,99,129,178,51,222,117,103,23,35,127,106,18,235,49,57,234,67,106,195,227,12,77,30,241,226,147,107,117,93,48,42,20,26,51,134,31,165,
222,199,183,212,129,239,254,228,205,155,31,11,108,253,191,248,149,45,233,198,40,149,167,64,246,30,2,13,108,74,122,131,22,182,71,65,142,89,136,146,169,115,28,103,122,16,42,53,175,6,180,47,127,218,97,133,
247,88,233,117,238,102,25,2,182,235,225,52,3,190,37,46,25,175,233,173,17,84,86,245,72,8,118,228,1,197,36,132,24,228,20,115,110,102,28,84,129,197,81,94,237,135,72,28,26,203,74,201,9,211,184,247,40,67,236,
10,0,129,152,56,215,112,29,49,79,167,248,200,100,255,6,118,205,6,26,10,75,181,85,79,159,187,118,148,190,227,47,255,133,244,198,15,126,80,193,185,152,238,95,93,73,255,242,167,126,58,157,59,188,151,222,
244,250,199,180,11,141,166,29,147,232,123,66,233,192,93,162,216,206,54,179,30,6,84,207,159,102,237,236,242,0,76,108,147,198,77,214,243,216,53,68,105,160,136,92,174,239,6,108,238,103,117,233,212,105,118,
140,106,137,77,93,247,60,248,170,206,250,152,52,119,19,10,61,20,97,40,178,70,129,55,122,17,172,255,202,218,26,97,33,205,122,0,99,123,116,244,125,214,228,90,155,174,33,47,84,245,12,117,80,72,17,156,91,
192,251,121,128,195,160,115,206,51,134,49,251,181,37,28,156,98,237,99,87,200,190,127,111,43,101,117,9,125,120,43,85,26,249,162,112,153,39,13,234,28,96,146,194,179,232,126,175,56,223,96,220,4,30,247,53,
138,182,35,148,244,145,80,78,22,91,120,190,225,239,27,66,190,248,223,36,203,106,160,157,185,56,206,196,245,120,203,52,117,26,15,55,66,101,215,214,102,88,240,80,240,118,253,140,127,91,35,152,203,206,46,
20,186,20,218,238,43,15,40,202,168,249,30,187,215,152,62,120,224,103,123,180,188,237,90,247,9,105,78,51,247,16,6,217,132,48,124,138,55,142,37,68,122,145,48,138,120,121,138,63,6,33,239,58,187,141,195,77,
133,125,168,183,247,104,33,147,31,50,74,49,136,124,4,37,105,135,188,172,244,141,50,175,170,199,56,35,116,188,131,86,186,196,216,15,23,230,157,133,254,76,220,188,69,121,248,78,212,91,13,0,107,240,192,81,
206,233,201,19,199,75,211,206,4,227,73,153,239,24,182,177,134,148,222,114,88,93,94,110,201,220,160,46,99,147,231,105,7,140,107,233,48,14,124,56,98,18,131,8,124,26,225,97,99,54,85,141,129,89,99,172,182,
128,153,173,104,2,160,148,69,177,219,148,168,233,220,204,148,52,10,231,28,29,49,43,204,142,224,65,191,4,116,59,86,90,146,83,53,242,170,252,124,201,131,218,7,122,190,100,82,194,193,122,104,200,132,217,
194,238,115,101,105,186,94,237,125,79,255,64,255,11,255,137,75,148,79,24,188,236,192,107,194,150,42,228,180,162,227,226,73,252,215,24,225,184,42,161,13,235,91,13,109,9,120,95,146,86,103,154,119,253,238,
217,245,135,56,9,196,49,93,94,85,206,248,28,17,143,145,135,110,86,7,67,60,32,28,129,84,137,50,12,86,81,242,208,58,97,161,189,120,140,32,68,238,148,165,8,241,234,232,132,152,6,226,20,120,128,117,111,18,
147,230,94,246,115,251,163,143,196,219,166,71,230,213,203,244,72,254,219,149,131,244,196,159,252,254,244,142,63,246,3,72,208,38,139,223,185,147,254,254,223,252,219,105,249,107,191,146,190,225,241,161,
180,250,165,21,10,188,129,28,78,0,189,241,50,193,94,7,254,212,88,199,17,130,150,19,83,30,211,132,250,166,58,154,207,142,210,65,120,249,111,138,22,38,39,242,188,150,169,21,30,173,89,179,143,131,247,52,
243,209,172,86,222,16,192,241,160,107,123,171,215,63,42,12,58,203,139,205,138,48,14,40,212,253,227,213,116,135,228,237,241,98,3,4,36,143,32,125,71,72,183,201,72,13,7,154,107,44,227,54,107,191,188,46,47,
85,203,29,212,251,7,62,97,88,124,38,129,25,32,176,77,159,29,225,181,58,11,97,198,25,246,178,60,79,85,98,212,74,148,47,24,67,93,117,208,17,150,148,62,163,189,9,187,8,127,132,157,45,231,104,14,52,65,15,
79,233,1,8,253,163,139,255,140,188,114,132,66,150,227,90,93,123,48,3,131,163,27,187,85,199,93,119,176,161,30,164,220,177,164,246,128,103,243,148,212,186,157,27,101,104,201,189,175,249,121,81,182,144,219,
231,248,199,146,11,12,210,252,49,131,177,141,157,83,151,74,28,202,247,178,188,63,199,223,167,37,30,18,206,11,74,66,87,226,25,243,250,103,213,57,135,157,243,50,3,150,55,137,59,144,230,172,114,68,204,225,
217,230,169,242,242,224,198,174,161,93,238,97,29,153,97,29,155,104,84,233,229,76,128,116,198,225,172,145,165,58,48,72,247,38,121,154,198,83,134,121,80,220,27,114,159,109,207,166,33,164,174,106,101,42,
168,159,102,205,172,109,10,45,155,74,48,251,106,189,29,32,81,160,224,21,171,54,114,148,115,28,208,54,8,16,28,4,98,149,132,203,229,210,142,210,12,134,215,180,53,36,240,128,94,16,63,60,187,14,249,59,127,
170,152,30,58,31,232,189,92,209,185,188,128,170,185,201,98,69,67,199,49,70,26,117,48,154,73,116,96,74,70,195,106,200,30,165,30,133,138,15,0,137,70,164,63,3,206,161,237,217,63,76,97,203,26,190,163,161,
61,29,140,167,173,123,24,84,197,117,107,47,107,63,115,245,218,115,63,226,173,255,63,191,4,169,44,17,23,221,223,63,233,208,42,14,232,180,80,172,89,173,98,141,176,112,80,46,85,20,136,29,153,217,48,18,211,
3,154,243,16,6,93,196,62,229,89,96,205,206,177,156,43,194,60,231,209,79,98,66,190,24,145,62,229,43,10,239,65,136,55,31,42,157,187,112,158,178,11,113,184,129,25,225,234,182,41,238,71,194,133,146,48,178,
19,227,36,121,173,2,65,145,81,243,174,138,239,242,207,108,8,187,112,49,190,62,243,151,238,54,255,35,68,244,236,163,15,165,55,126,223,255,196,146,143,164,205,123,55,211,79,255,196,79,166,205,23,62,158,
222,255,90,187,52,196,167,232,205,14,25,159,82,33,91,164,37,31,244,187,107,44,184,222,60,79,94,138,250,151,250,218,248,202,243,105,104,58,2,29,158,193,251,247,40,228,198,38,148,142,161,201,9,47,219,4,
106,88,193,251,216,3,43,99,12,53,195,80,9,91,174,1,55,58,172,244,152,226,117,67,110,57,142,180,95,210,24,144,140,171,128,111,120,176,166,195,187,167,97,159,87,17,206,238,80,214,125,33,215,176,201,243,
65,35,140,38,131,32,253,183,244,137,222,247,247,178,188,115,94,91,84,6,57,62,127,140,206,38,148,147,253,194,55,100,216,142,35,195,163,199,255,78,144,29,134,89,226,193,40,154,171,220,23,156,93,215,223,
85,4,93,188,27,160,147,15,79,82,194,73,13,233,202,88,82,60,83,244,132,114,238,57,86,3,198,206,237,65,138,59,195,197,90,180,21,199,252,170,178,18,130,10,1,222,148,35,6,227,230,34,165,106,43,93,92,223,67,
160,160,180,179,4,176,200,75,68,43,159,64,169,191,227,38,80,245,152,161,27,224,82,115,77,248,231,94,7,9,108,172,132,12,6,212,129,231,7,83,100,144,156,59,160,177,172,83,36,227,44,131,116,91,195,238,10,
54,212,136,215,22,189,110,18,197,241,190,209,12,135,140,119,27,178,91,212,174,21,136,248,137,72,165,129,190,231,131,12,138,67,62,113,78,19,80,218,86,68,20,106,204,2,90,53,118,103,130,247,189,37,119,141,
213,149,29,127,15,174,247,14,176,47,74,119,243,152,70,130,57,64,164,130,15,79,223,140,16,193,103,70,187,98,65,153,170,171,205,108,219,104,212,77,59,104,50,202,85,69,242,126,223,246,50,177,120,122,228,
205,103,211,189,59,246,170,220,223,244,44,160,206,148,46,182,172,215,164,49,177,83,116,1,198,16,219,195,61,74,222,23,198,32,242,219,246,217,65,232,105,168,137,63,236,122,183,144,102,42,56,218,77,209,196,
239,124,101,63,157,255,213,223,77,251,43,113,79,38,247,221,252,130,157,45,203,223,126,117,169,247,161,71,207,128,246,255,179,175,0,159,250,104,38,231,209,207,55,38,195,139,65,9,59,204,246,41,179,108,30,
53,197,124,202,253,76,16,224,248,53,227,66,206,135,208,200,217,214,60,221,47,240,4,95,243,160,58,76,114,80,73,67,72,186,14,253,150,112,113,77,168,252,34,5,187,227,6,94,255,216,121,33,65,5,207,80,105,134,
162,111,17,134,69,30,250,6,70,195,170,80,230,62,161,40,168,25,202,218,128,54,148,2,185,249,1,66,53,227,250,206,188,38,236,185,212,245,227,255,226,239,116,231,30,76,223,255,211,255,52,77,158,191,152,234,
119,215,211,199,254,214,63,73,245,167,62,146,254,240,67,144,225,109,202,71,59,186,32,250,2,208,195,140,97,163,244,133,26,211,189,244,38,228,234,64,222,2,189,141,237,83,77,76,159,218,34,5,113,221,95,199,
96,170,222,55,127,232,246,126,154,154,176,90,252,181,38,17,136,14,162,108,116,151,98,111,64,178,75,242,229,24,84,126,192,251,173,75,5,76,184,212,69,223,74,23,25,147,55,49,98,21,33,80,83,152,181,205,59,
215,41,240,86,204,222,45,77,34,229,107,52,23,59,118,99,159,139,80,109,4,253,111,153,53,109,57,163,130,252,185,24,57,210,48,27,42,77,216,231,165,27,250,3,79,60,131,126,251,29,79,217,129,2,30,66,43,221,
90,127,56,87,1,24,69,202,1,30,148,149,244,119,37,146,121,156,72,178,134,171,235,153,251,157,93,81,55,245,12,251,138,73,89,89,237,178,107,47,35,10,84,8,103,52,42,111,5,88,67,209,252,8,128,130,82,194,2,
70,125,174,40,251,213,239,51,190,240,24,227,63,61,0,10,87,246,247,41,168,99,16,76,180,252,50,152,238,95,4,95,208,249,50,172,112,220,144,159,196,74,132,73,104,237,20,101,170,154,87,116,39,174,195,179,220,
241,195,155,114,181,216,220,85,6,186,68,74,211,241,253,224,143,71,233,43,118,190,78,211,246,11,54,5,60,96,90,124,79,45,179,213,137,70,122,152,4,186,227,163,144,210,89,198,171,5,84,10,126,108,78,72,48,
39,229,24,69,1,204,2,246,202,140,90,217,57,28,198,84,64,30,47,58,105,178,144,215,41,231,230,106,25,149,87,39,13,30,242,102,157,3,164,153,88,217,193,184,10,226,253,15,169,101,54,194,122,249,47,48,43,230,
29,141,121,46,225,14,94,254,210,118,122,241,139,251,233,246,254,112,186,177,217,77,143,154,201,244,26,147,67,130,238,120,55,114,125,211,34,39,220,119,137,231,185,12,104,60,13,208,154,34,247,167,237,188,
57,237,188,206,49,156,167,44,99,90,193,36,187,1,157,255,103,87,187,233,95,126,114,67,184,189,45,90,72,233,87,126,238,147,105,177,122,248,205,207,62,245,43,15,245,5,252,63,251,79,190,139,85,63,12,189,76,
181,87,210,176,214,172,30,87,115,72,192,119,93,186,207,81,92,85,96,245,192,42,184,161,69,139,96,123,49,149,76,88,195,14,66,194,88,99,214,167,44,92,234,132,151,101,181,200,77,106,77,201,57,1,64,155,198,
109,148,199,231,116,33,24,218,181,179,158,158,190,131,34,39,7,168,131,18,253,6,237,146,79,132,37,14,100,145,133,142,148,102,3,80,241,117,150,173,12,12,122,83,196,244,18,160,157,246,131,68,40,165,199,31,
45,191,243,199,126,252,255,72,83,231,31,146,71,116,210,83,255,248,223,164,103,62,241,225,244,135,31,53,208,57,242,48,225,204,160,80,168,29,5,111,86,29,177,73,184,22,251,41,133,91,55,15,211,83,6,12,143,
61,10,49,131,236,174,202,125,63,237,243,255,136,142,150,15,126,231,100,58,253,250,137,52,121,105,138,173,202,165,151,111,15,166,87,62,252,181,180,127,191,234,102,66,72,229,135,238,205,127,48,163,220,52,
96,135,115,2,255,11,63,193,227,65,204,24,21,38,129,58,245,32,10,153,132,122,109,121,207,81,212,37,80,91,50,81,114,112,7,37,64,133,255,2,56,244,27,18,142,14,97,202,3,36,246,182,86,121,117,171,0,8,108,73,
57,166,71,176,119,61,104,33,133,48,151,235,81,207,169,16,200,82,148,123,42,71,172,115,108,106,214,135,168,166,118,196,50,159,80,236,33,2,17,93,43,71,192,146,188,207,62,133,240,189,207,227,245,104,237,
161,200,168,234,44,78,133,114,56,211,0,92,118,8,112,212,57,35,15,14,114,2,189,236,179,168,208,167,81,51,125,207,223,57,59,158,198,179,240,115,115,174,101,79,120,29,224,211,60,8,32,0,194,232,119,28,17,
77,12,8,173,7,8,109,212,201,87,48,125,98,116,74,12,196,27,101,128,164,230,58,91,144,10,220,249,142,103,92,247,92,50,60,218,102,120,88,41,79,153,144,111,6,206,224,223,134,61,187,88,247,183,193,72,239,181,
76,96,228,113,155,222,43,230,238,142,49,104,231,252,241,38,74,84,179,125,138,207,12,138,60,114,186,53,18,29,101,157,144,189,156,68,59,104,126,13,127,175,184,129,65,22,116,208,66,163,174,92,178,180,141,
92,35,69,24,154,65,162,144,32,22,32,223,3,162,157,58,15,121,14,73,97,127,21,248,165,85,172,168,246,52,35,26,218,193,238,56,218,228,253,129,66,89,209,21,122,90,122,26,195,172,170,238,31,40,254,190,72,111,
155,30,68,170,112,123,221,115,116,62,70,154,167,69,169,156,39,231,12,164,40,140,198,36,17,88,118,78,29,159,151,209,190,244,244,173,173,244,195,223,139,30,88,170,165,127,251,241,131,244,252,23,62,147,126,
248,7,31,252,87,94,242,106,238,230,15,255,233,43,159,185,66,214,60,255,173,229,110,122,22,210,211,230,142,167,23,134,211,34,120,190,133,127,152,227,5,6,40,229,26,138,147,185,80,105,75,146,61,76,234,119,
32,105,115,14,248,73,86,231,75,1,21,67,121,51,65,146,140,0,81,66,57,204,27,146,220,84,158,156,85,82,161,234,134,239,142,16,158,46,43,62,236,144,130,145,113,17,113,248,13,160,234,85,86,126,146,215,128,
27,164,45,9,247,154,144,236,9,22,62,186,246,183,85,196,143,214,94,58,60,104,28,125,215,126,245,165,217,145,215,200,59,89,244,47,255,198,39,211,199,254,195,191,77,239,16,131,29,251,188,19,32,19,170,36,
161,34,144,188,112,212,8,56,165,244,210,109,163,44,184,254,210,55,15,189,240,190,226,251,15,222,251,135,191,241,157,3,22,222,216,52,144,254,206,79,189,53,189,245,3,143,165,166,92,35,250,246,86,190,124,
152,110,124,234,78,170,157,122,60,21,223,56,79,217,159,54,112,122,197,14,23,141,181,172,120,121,76,114,79,17,102,24,145,32,176,108,211,199,1,82,61,238,33,109,171,213,26,96,136,98,119,64,120,162,190,170,
48,173,231,111,70,238,213,113,94,247,181,194,53,132,22,115,140,223,89,221,248,93,161,242,177,51,216,34,136,227,20,21,232,155,70,121,183,104,5,107,81,130,98,124,128,229,197,189,64,130,229,178,149,80,76,
121,99,203,253,197,134,235,152,24,56,128,226,179,195,203,76,152,78,149,49,213,112,151,144,7,34,107,97,100,127,132,230,138,159,139,60,118,1,243,162,224,207,118,47,25,223,17,221,24,174,57,62,199,121,211,
99,172,28,97,175,168,7,40,221,15,163,141,89,242,30,254,236,223,163,81,161,127,93,202,62,17,24,133,210,146,71,55,202,195,250,243,129,107,231,216,210,8,25,200,51,80,167,49,141,214,132,240,43,190,55,135,
226,54,32,242,136,206,145,199,133,249,166,142,154,39,171,30,204,206,213,24,160,51,136,11,99,92,55,140,171,143,62,239,138,155,199,213,124,58,148,61,128,185,226,142,50,83,212,62,93,172,249,249,233,156,220,
246,1,57,254,81,118,77,88,58,150,30,30,83,73,181,82,98,31,105,161,40,92,142,129,220,121,108,159,42,153,169,83,234,162,27,140,197,69,35,106,74,69,140,178,216,166,199,116,49,248,40,3,114,199,49,196,133,
97,99,88,75,134,67,31,6,98,44,170,153,180,198,99,63,104,158,240,130,188,218,83,75,237,251,177,73,30,146,145,250,240,77,101,144,217,92,122,15,195,119,11,143,50,15,123,200,3,8,215,25,168,174,237,116,167,
121,207,69,48,121,217,180,134,2,97,136,201,255,49,119,104,66,45,255,54,221,185,76,112,119,235,123,233,51,191,179,151,30,61,123,42,221,52,60,111,191,118,63,117,150,191,112,126,127,255,185,63,57,50,242,
250,159,253,79,138,25,191,231,135,175,244,222,91,255,174,177,127,94,124,10,3,5,35,99,99,104,244,194,230,242,126,238,212,164,193,202,148,231,72,184,230,172,181,213,120,136,126,109,249,243,177,130,109,16,
6,206,207,176,118,44,126,85,162,159,195,83,205,16,170,88,29,46,40,3,125,187,225,37,137,116,20,149,89,250,104,105,42,3,39,154,14,101,196,3,124,101,131,213,246,126,99,161,76,4,100,197,161,53,12,150,170,
240,152,179,4,62,7,17,251,85,158,118,232,212,172,50,197,216,155,106,7,95,249,55,221,220,100,121,0,128,178,126,243,86,250,15,255,240,31,2,6,22,211,212,140,112,39,70,87,18,202,81,227,19,131,224,94,194,210,
89,135,118,126,122,201,154,160,227,238,207,189,41,211,254,177,191,242,71,155,173,175,127,231,191,200,78,110,157,124,88,231,204,163,15,60,246,248,104,230,209,255,153,101,126,33,181,110,153,2,183,90,74,
247,95,94,76,123,27,119,211,251,126,232,221,56,182,243,233,55,86,174,166,207,46,221,151,7,10,65,9,203,180,22,169,208,202,146,80,14,103,194,188,216,104,97,146,219,161,118,101,121,227,88,111,126,84,85,118,
50,60,171,8,226,142,30,209,49,101,148,221,186,9,123,251,74,32,12,94,212,56,15,16,21,102,132,60,17,190,7,5,174,162,149,172,6,40,217,160,112,101,150,188,196,64,21,72,126,75,238,82,144,31,31,203,129,107,
132,109,214,231,231,181,235,205,248,115,108,106,139,154,90,164,18,39,132,232,24,106,83,244,75,125,188,95,138,138,97,133,177,250,144,45,212,42,247,234,89,87,196,177,39,177,37,216,103,207,202,173,170,12,
90,236,22,37,63,253,185,184,10,122,66,126,218,72,208,163,193,59,194,208,57,175,95,163,212,235,140,72,228,146,179,187,74,1,210,145,54,131,116,2,137,82,205,72,211,202,81,203,158,249,47,204,180,118,0,0,32,
0,73,68,65,84,134,235,212,147,13,183,160,184,100,34,114,210,105,71,118,147,65,91,226,253,164,132,46,150,129,115,109,89,33,83,27,74,126,43,64,46,207,251,65,185,242,8,224,163,199,160,31,153,94,145,19,14,
30,43,240,198,170,196,3,242,19,93,55,70,95,155,4,225,89,148,212,19,133,201,211,173,41,128,159,252,31,38,17,51,126,15,161,191,57,248,198,136,254,227,162,139,221,197,177,221,51,38,179,32,218,57,143,12,31,
249,113,135,92,229,40,113,77,196,2,3,5,142,73,91,76,159,23,222,24,100,6,137,103,0,239,35,42,68,195,216,156,37,79,177,217,60,23,8,45,110,228,187,181,199,101,144,220,51,194,227,104,175,171,239,115,102,244,
36,47,170,12,100,126,210,32,176,146,72,170,133,139,125,213,245,14,89,50,245,222,71,206,202,237,237,151,249,252,77,169,174,214,201,220,120,250,205,223,222,76,55,230,229,92,162,182,211,62,239,212,108,115,
176,89,61,252,233,175,221,92,191,250,218,203,115,95,252,79,10,106,90,199,107,63,229,47,151,251,223,32,208,189,214,79,252,153,159,254,238,191,246,254,207,254,246,242,7,46,70,7,255,168,146,9,100,46,194,
159,216,113,57,68,40,208,79,117,24,8,189,88,199,70,132,122,30,72,88,221,166,27,141,245,104,225,184,38,133,6,219,154,138,103,220,104,79,231,122,83,24,22,131,124,103,213,60,155,92,252,177,196,101,30,208,
177,205,178,102,188,160,237,48,51,179,211,105,134,194,46,154,73,251,243,66,133,191,248,39,254,120,250,241,255,245,135,133,72,227,149,152,115,42,56,192,247,221,79,79,253,223,191,150,110,222,125,46,253,
161,11,229,180,182,73,152,36,204,29,245,168,91,132,226,112,71,200,130,240,126,219,13,101,102,211,242,51,27,233,135,158,90,235,189,183,214,58,202,60,154,25,120,202,183,223,190,186,186,250,13,197,236,212,
71,111,221,154,30,201,67,63,31,125,224,116,154,156,155,75,37,5,234,211,151,170,172,249,82,26,155,59,149,166,31,22,138,253,122,203,225,153,233,202,146,142,64,113,139,242,169,28,228,58,102,202,150,21,33,
79,176,134,106,172,127,6,248,52,133,227,184,21,121,140,80,191,0,218,28,233,199,133,118,111,218,210,188,195,243,109,42,232,79,152,32,119,159,64,238,43,81,92,132,168,78,17,224,131,232,206,128,88,29,9,89,
67,1,230,221,82,209,117,117,133,67,237,8,135,228,151,189,232,34,192,87,13,192,187,77,200,218,180,175,73,152,50,161,16,184,186,61,197,247,19,249,237,170,115,154,112,61,81,239,148,89,112,149,242,66,207,
230,88,110,124,232,103,43,206,42,230,234,92,135,16,5,127,218,75,8,13,15,35,246,143,208,114,32,18,86,57,114,149,161,13,210,77,228,164,7,242,255,113,194,31,221,43,45,61,146,27,12,106,86,244,19,32,244,8,
40,62,82,147,1,97,79,96,13,27,220,98,212,170,103,189,111,217,191,237,237,0,94,92,3,189,79,87,57,255,0,156,166,228,121,45,161,255,9,6,206,1,192,108,99,185,14,184,10,89,85,195,246,140,181,170,154,190,199,
192,145,179,50,35,82,17,234,102,41,73,217,245,157,160,197,13,8,15,119,134,86,61,135,136,42,48,121,8,248,160,190,203,154,178,66,6,29,47,228,112,104,194,214,110,198,41,22,39,69,167,204,18,79,173,106,34,
117,208,252,30,37,19,117,214,109,242,190,205,185,100,239,147,27,158,48,199,235,61,125,255,48,253,187,149,147,244,184,156,238,181,114,218,5,70,40,87,5,94,74,97,230,109,205,155,246,12,178,192,159,53,134,
117,153,133,30,48,1,194,83,96,132,7,180,26,10,126,241,209,87,61,164,187,66,152,43,228,228,0,142,113,219,208,184,41,161,116,19,224,52,194,3,215,225,33,13,58,241,102,35,92,187,234,164,219,119,55,211,39,
239,124,180,208,121,228,27,190,183,215,187,249,124,38,115,217,149,58,131,248,79,234,125,165,240,187,203,111,24,126,233,153,59,157,191,245,175,47,126,232,111,252,214,39,190,124,231,135,158,253,192,111,
253,204,93,44,23,150,207,225,222,115,176,11,14,45,16,184,64,87,51,242,144,61,7,189,175,180,145,35,72,219,26,5,91,90,164,28,231,171,121,206,173,61,94,208,207,42,196,215,229,128,1,28,245,196,73,54,184,167,
81,36,132,0,25,164,28,60,178,131,244,170,32,152,236,174,105,164,245,253,155,32,190,15,188,237,187,27,223,253,231,126,116,208,162,26,14,89,40,3,34,47,83,102,246,240,35,249,231,62,52,109,123,245,91,183,
89,222,27,155,134,146,17,184,183,11,223,230,117,28,140,191,111,58,61,128,45,49,116,102,33,157,122,251,119,28,229,30,248,142,15,180,154,119,62,220,213,201,191,177,177,254,57,131,164,151,230,230,230,127,
248,153,47,127,249,3,249,86,237,83,197,110,45,183,233,144,71,20,142,79,43,213,28,117,47,48,68,186,113,178,15,166,71,254,144,57,173,31,125,37,29,44,71,48,36,116,101,225,35,223,139,89,166,121,74,58,7,130,
143,90,225,129,144,177,20,15,89,177,54,152,47,163,39,192,12,94,165,72,153,55,36,113,47,19,254,117,73,246,67,81,246,240,80,243,234,102,97,189,243,192,147,85,218,88,55,29,96,253,120,18,235,134,112,250,247,
178,159,3,226,242,16,56,199,148,100,11,122,120,129,149,29,20,158,213,133,49,209,143,25,75,139,7,39,181,177,49,255,145,6,23,162,118,230,117,101,152,223,80,8,173,115,13,134,82,40,159,202,147,57,188,166,
193,3,41,166,189,231,43,242,147,167,81,12,95,55,210,238,3,23,225,233,162,222,153,101,104,99,97,241,156,84,99,153,49,213,62,11,112,18,106,139,70,166,76,50,136,154,235,18,35,52,233,188,99,154,252,57,30,
211,96,80,168,62,131,234,58,6,25,200,136,134,52,139,152,10,225,90,201,200,166,95,102,100,245,1,164,49,94,62,6,158,149,120,144,37,32,77,153,60,204,115,209,33,176,25,10,195,126,42,13,201,15,157,115,24,152,
232,49,109,194,32,142,148,40,38,200,216,145,200,160,141,144,48,36,15,31,161,168,205,140,5,66,228,169,136,79,216,150,34,52,69,32,57,63,219,133,37,180,228,56,121,117,198,178,136,39,71,104,233,174,209,34,
106,201,40,120,177,68,185,28,75,145,227,189,228,138,67,66,183,136,114,62,207,136,109,45,157,120,78,131,233,141,125,12,159,18,57,211,104,244,216,23,154,69,250,209,101,224,242,158,243,8,101,126,130,124,
15,3,166,206,184,222,77,165,185,187,7,91,120,219,67,214,92,88,111,162,106,48,108,118,84,96,20,179,198,199,78,233,86,191,15,64,109,91,234,52,2,185,13,190,242,44,128,43,178,151,219,47,222,100,184,234,105,
161,124,225,207,191,184,242,186,159,164,14,203,126,165,252,214,63,123,254,253,205,127,183,251,158,238,27,158,251,225,189,161,229,180,48,177,219,254,205,223,124,248,167,126,228,251,114,233,109,120,138,
29,5,220,119,233,66,223,86,105,30,102,29,214,154,91,105,21,81,123,75,119,127,119,43,150,197,162,193,173,136,173,111,93,213,112,172,7,179,125,133,208,41,66,79,119,89,16,180,63,73,189,252,57,245,46,4,28,
207,66,129,208,109,237,49,184,89,81,31,248,112,214,69,136,102,211,184,105,217,37,185,97,40,255,196,50,48,170,176,247,253,211,11,11,63,119,220,106,13,51,244,108,60,164,177,60,163,166,215,185,251,67,191,
244,157,255,225,209,191,247,145,55,14,45,204,21,158,96,53,74,18,246,135,175,32,82,95,124,60,29,94,124,130,241,152,74,37,117,173,94,110,250,114,187,181,243,235,39,199,227,34,19,225,88,233,232,221,39,189,
86,171,86,27,249,252,244,155,190,248,161,194,181,237,94,105,99,57,157,220,153,72,157,249,197,180,187,126,137,36,190,209,32,233,82,186,243,140,142,249,209,83,233,13,239,124,34,93,253,165,207,177,231,66,
39,15,42,232,131,13,227,11,70,37,90,93,66,21,183,211,213,96,44,32,74,85,161,196,144,155,201,122,232,177,60,216,192,32,33,151,28,138,17,163,75,66,245,24,150,233,222,88,239,134,135,179,136,76,237,221,140,
221,136,142,124,171,3,228,189,103,41,125,214,159,15,12,213,14,74,229,146,218,213,2,207,48,133,29,212,17,58,231,121,217,142,145,34,135,140,209,44,5,31,224,213,106,145,203,179,110,13,37,10,54,130,161,32,
112,242,218,81,43,251,90,148,163,62,3,176,161,64,65,0,56,8,41,53,120,43,39,52,110,40,114,174,138,138,78,9,89,99,128,53,221,148,198,240,116,74,6,147,254,82,55,246,36,22,46,153,182,210,143,134,162,23,246,
33,63,119,133,226,119,160,189,39,52,113,80,121,103,128,98,158,162,36,65,124,160,95,209,105,38,55,23,14,187,71,20,97,115,105,69,202,148,77,186,139,69,115,8,205,38,236,172,198,2,242,193,69,202,18,164,136,
117,7,84,32,32,90,6,68,37,194,214,184,15,239,53,142,249,19,147,13,170,222,60,136,34,177,94,126,72,180,209,113,175,131,162,180,232,118,57,161,232,37,57,94,1,85,179,9,249,61,86,138,178,178,73,51,56,169,
145,82,228,13,28,43,235,136,206,193,50,198,140,209,156,28,117,190,242,189,172,242,88,169,91,181,61,12,72,37,170,25,145,82,188,238,52,101,147,222,101,200,167,18,132,155,178,59,134,193,216,146,63,140,48,
122,25,215,112,171,170,173,205,153,93,100,20,186,64,191,40,67,70,43,99,94,154,81,192,255,61,141,17,53,43,117,120,112,64,59,38,78,245,46,195,188,165,194,17,67,216,198,80,11,117,76,166,151,182,117,49,193,
37,190,237,77,179,233,242,41,229,58,14,233,222,226,215,210,250,213,169,127,73,37,190,173,175,156,6,242,254,86,238,149,79,165,253,55,124,67,122,163,153,157,47,189,244,202,224,241,122,245,111,28,191,238,
114,26,123,115,33,157,121,243,99,105,238,212,25,57,200,185,155,39,249,246,223,31,72,95,241,186,231,82,246,246,75,209,150,113,220,123,199,159,255,145,198,75,133,39,191,122,155,167,188,36,63,68,109,155,
208,189,240,127,253,194,15,167,221,13,107,195,41,156,52,128,98,250,189,177,247,249,185,249,226,241,189,149,59,239,190,249,116,53,51,114,37,58,75,136,125,249,242,209,153,242,245,255,37,93,113,122,17,135,
237,127,235,123,86,107,175,201,215,145,202,195,75,103,229,90,57,113,254,246,222,146,218,215,254,183,87,70,254,122,249,125,63,97,213,121,123,42,173,221,189,159,230,85,165,123,70,143,68,203,87,17,109,171,
226,180,114,197,75,148,228,102,118,109,157,247,207,94,76,163,99,167,185,108,165,147,163,221,235,11,115,143,255,236,173,222,250,76,229,232,23,210,141,207,44,167,117,160,85,165,62,8,152,178,197,250,166,
207,43,222,67,146,70,241,98,173,207,43,115,204,43,34,31,144,54,103,9,25,20,26,33,43,180,16,219,91,144,213,83,44,255,137,124,164,229,1,196,202,137,88,168,26,179,111,86,40,209,40,195,198,39,0,117,116,112,
168,31,29,40,179,28,203,191,130,10,199,255,18,12,3,156,9,116,77,220,119,74,15,235,88,132,69,199,163,105,9,249,97,8,194,61,232,103,47,162,55,142,207,18,122,158,101,103,205,52,0,138,158,163,56,227,234,149,
49,103,231,101,96,75,80,205,74,148,168,22,12,6,30,176,73,200,202,24,52,49,96,45,250,11,135,253,58,241,111,112,19,35,96,130,5,84,72,15,233,12,26,23,170,229,228,181,49,7,183,227,103,43,33,124,220,104,236,
65,197,17,236,83,0,243,52,36,43,149,9,229,221,241,62,26,49,120,55,68,115,202,210,22,70,198,248,206,32,148,132,226,110,121,116,74,158,90,169,136,8,197,186,39,188,221,81,4,156,16,247,238,10,133,87,125,254,
12,75,203,89,41,233,184,78,202,122,64,200,215,189,126,201,107,47,201,7,167,40,107,157,134,27,163,204,104,3,204,144,229,71,120,243,240,232,35,64,169,42,131,209,16,10,183,89,241,152,112,184,207,108,14,3,
219,84,57,204,136,58,78,43,158,139,136,25,61,79,10,68,14,154,34,147,88,152,60,164,100,215,172,98,132,41,113,197,24,135,200,161,71,197,223,21,225,103,140,227,220,226,109,61,22,161,104,204,46,42,167,27,
138,196,15,67,233,135,163,89,28,74,39,213,79,123,48,131,49,145,93,158,1,11,228,108,21,80,88,100,44,30,242,154,113,175,105,24,237,217,35,194,83,158,217,145,206,166,147,222,106,122,214,61,214,201,240,136,
28,247,162,16,61,34,184,229,45,12,34,249,127,3,40,24,17,89,76,154,127,237,57,30,154,236,52,118,246,223,112,208,108,126,211,240,224,224,103,242,123,23,91,138,171,143,165,131,11,15,125,95,249,48,253,145,
183,190,125,230,77,189,39,95,59,211,100,113,39,223,253,50,100,108,86,81,181,220,61,106,78,223,45,20,78,61,177,219,121,243,242,212,68,233,199,62,252,153,222,233,247,190,55,189,43,223,173,61,210,121,35,
30,105,225,235,242,198,24,138,228,137,152,172,215,58,247,100,42,210,135,184,143,46,237,172,99,103,84,42,229,215,108,149,207,252,189,137,133,207,61,242,218,7,27,243,99,103,191,85,163,178,101,71,169,246,
3,153,204,55,253,202,143,253,131,222,236,251,191,37,189,253,161,135,110,125,48,187,178,245,237,181,141,189,74,193,3,201,241,196,163,198,157,28,236,102,210,237,23,238,222,121,240,177,198,155,154,23,191,
187,112,188,247,82,42,222,124,42,117,199,174,240,16,60,135,131,159,187,240,0,207,196,139,153,137,212,56,26,79,167,206,154,151,186,40,7,213,85,127,214,124,143,163,38,9,243,85,220,158,56,87,31,124,107,38,
255,214,81,93,29,149,116,77,139,217,193,240,237,180,138,189,241,246,185,99,173,82,135,233,119,33,189,131,58,232,99,94,107,208,218,98,97,176,6,6,86,27,251,196,161,231,197,229,5,10,86,6,172,20,21,187,87,
8,93,144,30,26,14,59,248,188,131,66,159,21,185,217,142,159,89,128,102,131,14,251,75,97,99,85,221,12,15,54,132,35,188,135,121,180,163,216,127,218,84,183,73,66,50,200,3,138,130,229,231,193,56,150,50,120,
248,49,31,152,241,118,45,16,113,207,229,94,159,129,45,173,32,196,235,148,178,14,16,57,101,101,93,148,146,38,77,17,104,64,136,187,66,171,40,77,76,241,238,112,53,197,110,83,9,129,109,129,158,230,25,154,
135,129,8,142,20,24,135,185,68,224,34,204,234,224,142,158,240,130,109,222,52,192,168,64,207,39,40,101,147,54,237,142,159,210,166,118,144,6,141,148,233,8,47,3,128,219,164,184,167,92,229,49,197,23,197,191,
74,61,12,194,2,101,235,185,174,162,215,118,72,124,94,125,85,51,159,210,137,164,199,233,15,250,204,162,215,4,135,215,44,53,21,130,87,189,118,124,230,22,79,20,57,236,152,207,68,28,234,143,199,41,58,247,
2,69,232,122,191,138,60,123,4,5,179,71,88,155,152,57,45,121,112,77,105,106,120,204,243,39,99,209,210,229,71,82,222,121,30,59,251,66,172,174,148,179,111,221,215,143,28,141,13,24,106,45,207,179,100,180,
106,32,192,29,70,227,72,25,198,35,115,173,158,5,227,21,51,111,219,254,124,219,207,197,243,188,162,253,239,145,242,46,131,10,196,35,62,163,140,211,12,79,95,2,152,70,121,177,228,186,118,149,120,236,184,
162,224,134,133,179,14,135,140,231,176,103,62,38,202,40,236,35,227,67,208,71,162,51,137,33,188,230,253,183,24,192,51,158,205,221,219,42,19,148,126,234,219,244,244,254,202,205,116,170,80,154,121,230,215,
111,159,11,25,205,231,116,223,31,223,22,126,190,88,125,195,51,119,106,31,153,24,207,204,156,93,184,60,83,20,178,116,185,226,19,163,37,122,72,137,229,137,244,241,169,193,118,203,2,215,76,227,160,246,231,
142,79,118,255,210,64,183,117,182,222,184,155,110,223,92,74,139,55,182,210,133,139,167,133,63,150,214,90,235,183,179,30,60,198,72,224,21,203,153,243,73,99,28,118,14,219,163,167,206,143,253,159,213,235,
134,113,29,156,79,143,142,204,179,76,219,105,235,118,245,157,207,126,234,153,233,11,143,223,250,254,161,202,204,249,198,97,254,139,19,11,205,247,101,44,72,93,186,143,49,82,26,222,57,169,29,253,226,64,
169,253,71,127,251,231,127,225,155,51,239,156,78,147,31,124,144,117,231,73,237,143,92,221,155,78,155,215,246,211,221,251,251,233,241,119,159,181,98,62,151,62,249,197,45,245,204,249,254,100,239,59,119,
182,82,131,36,188,187,253,122,179,145,114,51,159,125,230,224,207,177,251,63,250,145,143,223,206,29,124,233,105,64,205,126,122,102,237,190,190,207,42,35,51,147,190,100,58,65,121,210,3,229,42,167,209,0,
143,163,167,20,2,156,5,202,196,0,231,76,112,52,229,111,65,103,91,246,112,183,120,160,34,15,17,3,159,200,44,112,6,49,218,191,239,144,146,174,159,45,242,160,81,243,28,208,203,216,1,89,174,168,149,197,88,
140,22,84,114,137,0,4,250,154,17,251,199,158,211,30,182,204,184,146,68,79,104,186,35,176,141,54,178,160,126,69,63,226,132,7,186,141,203,25,11,132,219,6,84,71,15,225,188,80,187,27,107,236,25,198,170,198,
247,22,227,8,87,34,48,66,68,229,162,186,181,142,17,70,157,4,50,76,88,45,146,235,47,135,154,22,14,159,80,216,104,170,137,181,123,69,86,244,154,252,125,8,162,62,31,97,158,156,238,244,24,122,37,91,251,202,
90,112,157,35,50,48,18,21,11,230,68,73,224,180,63,199,146,165,65,94,233,172,214,189,154,231,221,146,139,158,230,116,163,249,161,71,201,47,218,189,178,134,172,114,66,57,34,31,110,201,149,163,163,38,60,
249,0,15,26,83,11,219,238,63,8,251,193,184,233,5,107,202,245,5,79,53,234,213,177,97,238,216,53,54,177,149,22,46,227,60,59,147,219,100,39,103,250,35,209,236,167,73,243,148,168,96,138,126,48,145,218,126,
54,30,128,118,206,190,215,45,25,15,88,137,120,158,81,60,70,189,44,136,102,178,16,222,19,104,111,17,201,36,131,6,121,162,252,84,85,242,168,67,207,72,171,177,165,154,15,44,71,234,122,174,121,103,186,99,
178,116,70,196,21,11,164,2,252,156,213,47,25,188,235,88,93,18,51,141,70,92,119,0,106,135,186,134,182,228,233,243,228,99,134,87,220,162,237,17,106,79,73,81,238,183,54,129,132,3,233,146,242,79,209,185,76,
154,143,124,147,81,201,217,27,244,220,210,70,122,45,96,236,188,149,20,51,227,55,83,169,126,87,116,178,240,62,237,109,191,174,84,83,188,87,248,250,234,249,79,221,61,254,243,215,81,167,54,214,175,34,28,
156,79,231,222,48,151,46,79,189,54,221,221,190,27,121,83,225,194,185,250,79,109,126,253,217,126,23,196,235,222,240,168,58,205,89,80,185,109,94,148,241,214,205,155,150,217,12,164,243,5,213,105,15,58,230,
217,222,215,103,249,236,139,187,50,170,74,250,150,119,189,238,215,190,241,155,174,252,237,141,221,238,197,242,120,43,95,63,251,250,159,61,91,124,80,179,232,153,63,123,119,235,206,197,135,30,155,252,203,
29,136,230,218,226,203,14,98,160,150,41,206,156,105,118,94,97,109,204,99,185,111,248,197,217,215,191,255,209,39,63,240,197,197,171,127,247,29,171,155,95,154,250,236,139,143,165,231,238,49,26,161,52,114,
171,237,107,66,179,137,115,202,55,3,233,243,191,180,149,110,109,18,124,200,91,175,187,132,202,181,204,163,176,104,144,178,23,126,243,55,82,253,254,230,194,15,252,141,191,246,143,174,60,252,206,253,143,
255,251,95,234,45,190,252,229,204,163,23,231,109,130,118,47,149,179,14,58,24,61,7,105,107,213,184,126,135,125,170,141,209,33,44,105,72,236,39,61,251,232,78,63,162,124,228,5,247,211,223,9,98,244,66,78,
18,0,169,156,81,27,114,57,2,18,29,241,43,166,35,244,8,89,9,212,222,194,157,141,114,83,197,92,215,135,128,70,57,222,42,234,198,27,80,210,115,147,144,66,22,187,114,88,73,107,24,66,251,140,64,44,64,58,84,
167,136,162,122,206,123,196,236,214,26,37,143,137,238,21,57,97,89,83,240,216,105,76,156,101,231,13,49,62,198,116,138,166,238,9,244,198,120,10,39,94,247,220,186,134,121,2,59,174,99,229,180,48,147,161,70,
2,136,214,39,181,213,40,193,0,120,164,189,164,217,191,249,199,243,132,90,0,0,164,144,171,81,100,111,217,111,181,11,250,209,201,193,170,188,25,226,203,16,213,69,50,208,5,33,56,16,143,16,87,92,95,135,199,
108,248,44,36,159,254,164,244,77,0,205,184,51,8,244,125,135,39,190,43,71,37,183,12,154,154,184,207,220,119,78,195,40,72,107,146,246,45,249,245,121,103,22,203,107,203,120,192,70,16,11,45,221,207,92,55,
189,235,205,167,211,22,195,91,194,238,42,97,79,140,206,174,51,60,148,140,55,142,129,0,135,6,1,236,43,83,133,66,207,82,118,248,89,186,239,179,76,206,64,189,164,171,198,140,24,45,11,185,49,158,85,30,121,
165,89,133,224,2,188,182,140,127,49,113,46,75,137,26,168,85,53,168,214,180,235,28,179,102,254,174,114,143,34,69,122,189,33,109,215,98,142,22,228,248,235,188,251,91,78,13,164,11,112,132,19,207,250,234,
189,118,191,65,228,109,211,66,117,134,172,186,63,144,158,21,251,94,56,103,224,157,136,103,211,77,122,59,40,191,112,92,237,117,81,141,245,22,146,67,217,249,28,25,22,48,67,30,198,133,95,64,219,244,121,147,
23,174,60,245,66,58,119,246,65,131,198,174,24,12,182,250,71,95,254,236,111,252,243,252,192,81,246,31,183,54,111,253,228,202,254,203,233,45,223,245,93,233,244,27,105,61,224,226,153,107,181,244,133,149,
223,77,35,224,222,18,212,233,250,245,69,12,139,224,118,130,144,151,174,165,79,124,242,211,80,196,227,244,77,223,112,57,157,84,37,211,227,147,18,119,137,68,84,242,40,205,62,110,235,23,238,238,164,39,30,
210,237,63,82,24,253,150,31,252,249,135,127,240,143,124,243,47,208,220,252,47,127,244,211,197,139,243,247,210,235,159,120,243,63,248,248,115,95,203,190,94,45,19,78,154,158,255,242,134,153,64,135,163,179,
227,181,209,219,218,153,150,244,254,213,110,95,235,109,215,254,227,13,111,172,4,243,112,46,123,241,49,53,209,209,244,229,117,245,171,216,227,193,75,28,44,189,130,214,197,2,174,44,11,53,131,227,35,57,103,
189,98,84,103,140,90,145,53,17,102,7,141,91,185,120,123,53,253,129,165,155,106,110,239,253,193,246,96,241,95,119,7,16,5,161,115,106,209,125,222,37,204,69,57,67,72,68,128,135,121,155,10,225,203,200,133,
98,21,97,237,213,66,157,102,232,147,52,172,159,181,29,101,37,225,208,130,240,46,192,138,240,164,59,4,124,78,200,56,172,118,176,234,239,183,9,206,182,13,206,35,44,115,244,121,214,3,150,38,184,5,158,203,
115,130,244,197,96,47,158,48,60,11,2,124,132,105,89,30,123,146,224,13,8,209,162,241,218,183,236,57,21,90,6,24,162,177,244,76,31,185,196,94,113,141,25,130,68,7,40,160,225,97,114,222,9,64,196,82,228,93,
188,248,26,171,30,99,72,46,250,115,148,50,22,208,49,99,10,226,42,195,114,64,73,220,66,31,205,141,229,70,187,94,7,236,236,79,65,16,249,246,21,51,114,81,93,92,72,40,194,82,90,54,172,197,107,63,148,22,90,
93,149,58,180,1,43,131,238,123,19,137,36,67,129,99,161,80,180,35,175,10,105,163,249,254,50,163,24,139,170,54,8,246,182,15,11,66,125,28,33,91,215,87,254,158,90,229,161,8,35,239,179,99,116,74,108,74,139,
141,220,193,184,138,156,118,26,99,173,214,154,75,155,26,165,219,8,10,35,163,198,187,240,94,177,9,27,96,106,98,163,107,99,40,194,104,6,218,220,146,2,181,141,45,237,241,234,129,116,11,122,201,12,32,70,156,
28,224,229,68,144,34,38,234,60,84,33,109,239,8,53,77,218,142,49,171,61,249,96,240,159,163,244,210,241,247,19,37,150,32,230,228,157,109,164,6,96,159,126,100,113,15,23,124,199,191,41,236,184,129,94,186,
136,128,51,161,117,174,202,136,143,32,205,92,153,84,58,116,143,203,18,239,155,82,142,131,162,153,187,162,167,99,93,95,21,224,215,172,53,245,85,45,82,135,193,118,66,101,221,221,105,244,27,60,94,6,128,62,
241,213,173,52,125,1,24,6,108,234,74,198,235,175,249,3,159,205,151,47,44,252,228,141,234,86,250,220,179,159,76,159,55,218,225,93,79,94,210,201,160,147,252,197,219,233,217,231,238,27,103,137,36,238,70,
139,66,178,49,101,147,253,93,187,36,173,125,235,234,173,108,168,3,253,220,213,207,225,134,86,210,206,242,90,250,209,191,240,3,233,194,229,215,83,134,148,238,60,251,116,90,186,37,100,93,124,46,125,236,
163,31,250,22,72,202,183,252,133,47,124,44,141,204,207,164,229,231,158,149,163,141,164,95,28,248,144,32,185,157,158,242,243,227,243,115,198,133,216,77,178,188,110,183,197,139,17,27,129,188,33,154,235,
6,69,191,245,177,193,171,207,60,147,62,249,59,55,122,79,61,253,117,30,210,206,70,66,27,67,156,163,27,244,24,26,23,91,163,131,170,150,101,88,4,44,66,106,11,154,40,103,197,42,185,3,72,219,32,242,194,36,
37,88,86,38,89,215,17,15,199,233,102,135,53,219,182,54,210,173,29,140,14,211,212,246,1,49,35,129,168,24,202,212,197,94,153,98,237,198,20,237,71,21,118,151,245,23,174,200,77,70,161,211,202,84,222,159,215,
225,69,68,196,12,138,188,152,199,57,246,247,73,166,187,32,119,187,171,222,215,86,27,45,170,237,50,232,212,3,210,136,160,1,35,52,221,1,83,136,66,156,22,182,7,167,179,192,243,118,132,226,93,74,57,107,220,
99,209,232,198,216,79,185,171,139,33,194,201,152,143,27,74,58,2,9,238,176,218,65,34,40,80,138,19,93,18,3,92,157,219,52,193,156,59,66,71,219,21,174,197,74,69,59,124,211,24,175,108,52,154,54,38,238,75,248,
150,231,57,112,74,0,17,132,58,114,44,127,14,47,118,192,176,249,120,247,45,199,98,80,202,88,241,53,200,226,144,240,173,225,53,97,36,230,253,59,128,19,120,226,151,123,190,20,222,128,177,30,228,178,98,200,
179,72,24,33,94,93,51,20,147,241,225,184,248,86,198,75,100,49,192,27,154,209,38,135,115,110,128,156,26,163,22,131,219,98,228,203,48,227,213,135,146,67,222,189,62,195,104,4,55,61,106,174,139,176,130,90,
253,235,158,13,190,52,3,145,1,6,141,250,172,24,6,80,114,102,25,223,171,82,254,9,247,24,94,185,43,132,30,229,183,74,218,115,34,157,24,136,17,131,148,173,37,228,156,140,13,196,72,189,245,106,60,39,216,160,
239,149,148,70,90,40,157,180,210,145,50,232,242,252,46,156,160,32,109,216,134,212,93,83,170,107,169,7,207,216,185,115,113,64,12,232,62,154,20,124,156,124,236,24,12,22,74,91,32,115,123,8,253,178,145,116,
133,204,234,82,77,95,4,100,238,114,14,243,172,221,188,135,191,45,74,216,151,55,23,145,245,71,253,92,30,197,175,34,84,222,84,101,184,85,37,59,12,215,239,212,202,233,187,51,147,105,229,246,90,250,156,129,
100,141,209,231,144,190,140,9,156,156,63,157,174,184,248,79,223,126,46,61,165,255,48,14,39,111,221,221,222,238,166,235,30,79,7,27,222,192,52,180,107,13,133,110,225,198,164,237,78,57,161,93,209,166,175,
0,105,14,52,77,175,222,250,58,98,193,119,176,138,14,134,7,184,253,252,243,105,245,21,57,156,137,2,93,136,98,142,165,136,175,198,206,178,135,32,52,67,18,175,200,241,54,32,92,197,242,28,171,121,53,29,172,
120,47,96,71,213,100,190,211,231,70,210,194,244,105,214,113,59,247,67,127,242,79,125,244,231,255,217,223,251,209,31,255,171,127,169,178,139,70,200,217,9,27,213,146,120,138,125,225,176,64,75,184,128,128,
109,82,248,113,212,175,114,226,75,7,151,17,162,54,35,127,83,107,68,62,76,167,78,139,65,94,190,99,120,245,117,10,131,91,162,21,169,105,141,92,197,40,199,240,0,19,128,134,67,225,83,16,200,7,247,119,212,
191,244,113,238,215,16,4,130,168,14,29,141,97,102,66,46,186,41,95,33,188,206,162,69,160,182,9,238,60,135,56,72,66,56,183,180,132,218,120,77,126,212,223,100,198,178,159,117,13,93,117,218,41,138,157,161,
224,243,132,178,226,7,99,82,123,86,173,52,8,231,71,36,166,105,164,32,126,55,35,19,11,115,32,159,4,108,52,4,7,173,108,8,224,1,248,87,79,243,254,40,123,35,216,72,5,168,227,161,80,210,109,88,204,4,44,18,
246,238,71,13,148,64,4,168,18,84,64,99,11,173,13,20,230,11,245,162,231,51,148,49,66,101,12,70,189,177,106,216,132,101,139,126,204,248,125,217,25,132,114,78,123,62,113,29,187,140,66,139,34,185,85,184,131,
28,156,92,88,3,149,16,188,24,131,232,149,165,36,194,225,2,133,108,82,150,46,69,102,67,52,151,83,76,103,120,203,65,205,242,70,81,23,61,229,77,246,92,91,195,153,69,13,180,22,61,189,114,210,17,8,81,91,46,
216,219,160,124,16,214,57,97,121,228,121,100,185,31,250,23,121,195,9,215,19,168,230,9,67,22,104,57,251,37,93,114,253,62,99,156,33,16,200,132,47,3,236,196,22,245,168,111,202,161,129,99,209,69,19,91,7,98,
146,228,106,212,152,212,37,139,8,4,71,0,164,85,121,255,3,202,57,99,64,157,6,207,151,215,148,28,235,15,131,210,60,164,194,80,16,239,223,115,207,210,110,159,111,154,46,206,114,83,243,66,78,109,120,66,153,
110,21,226,119,16,229,29,232,50,81,211,245,35,181,161,196,87,119,241,152,16,11,46,247,198,250,75,138,103,249,239,235,186,176,98,144,64,44,80,154,245,179,173,41,92,92,119,48,135,214,185,37,183,89,54,207,
234,46,106,87,158,65,58,207,27,63,167,6,125,6,232,148,111,1,60,82,125,57,205,158,157,37,52,99,70,219,35,46,35,133,183,2,230,45,206,244,91,128,80,24,41,130,229,62,138,206,199,202,2,5,112,92,71,209,180,
43,223,27,134,108,54,99,4,156,175,176,86,17,98,5,177,250,177,183,141,165,95,254,194,29,181,36,61,114,146,246,80,144,113,140,153,35,45,64,13,194,199,215,201,49,42,194,65,200,38,40,60,214,221,145,29,97,
155,57,161,59,20,26,203,102,121,237,54,128,192,4,237,221,70,108,93,255,155,103,206,44,92,42,121,152,131,20,241,68,115,109,175,187,230,58,0,20,194,187,8,41,163,96,26,107,239,93,173,95,17,204,122,144,126,
197,67,139,19,220,39,177,17,240,141,25,113,18,63,114,168,104,156,179,187,164,32,180,42,48,169,121,247,213,180,144,55,128,133,158,48,189,204,69,100,89,216,29,49,83,108,143,246,12,133,162,234,144,44,117,
83,3,246,125,96,70,76,83,143,117,0,187,161,96,222,246,200,25,133,165,156,39,184,177,62,174,206,155,198,18,218,160,26,47,11,239,178,66,228,74,120,22,2,85,13,206,43,97,29,129,110,12,71,7,134,40,130,197,
0,80,224,201,198,21,19,236,89,94,160,40,148,59,140,121,66,174,35,3,137,205,11,145,130,156,94,231,25,201,160,62,88,159,79,233,35,148,205,16,196,48,77,90,14,133,185,161,232,152,57,20,51,20,120,202,231,7,
157,47,207,3,196,217,76,121,255,21,72,161,40,66,120,45,156,163,104,7,20,99,210,121,220,164,104,34,216,254,70,57,145,28,47,67,161,176,125,130,152,0,139,74,119,252,59,226,12,233,167,8,238,149,126,42,145,
0,132,68,4,125,36,55,188,183,247,207,250,185,24,137,98,31,17,254,179,243,225,237,200,177,210,4,198,140,226,63,190,190,178,6,5,224,145,253,95,155,95,12,46,203,164,135,124,63,154,30,246,33,227,147,115,202,
65,148,178,195,187,137,169,211,172,52,171,7,121,62,1,160,69,105,74,32,216,7,176,98,58,69,78,244,81,145,39,118,120,216,168,233,4,121,161,14,233,85,118,21,181,120,15,64,78,151,23,175,71,26,67,110,134,120,
214,242,176,161,98,166,233,163,218,235,166,209,252,237,218,38,120,246,188,40,36,218,192,246,35,167,247,218,162,245,127,57,122,176,1,112,216,136,238,33,33,111,222,0,177,48,174,77,43,69,58,62,103,65,36,
129,138,98,178,134,233,130,56,175,67,34,140,5,7,208,102,124,131,139,93,115,63,85,116,207,211,188,244,91,102,102,210,22,143,188,169,102,91,23,5,125,230,139,47,165,63,246,228,169,244,158,215,77,164,175,
222,122,10,86,18,130,176,122,75,142,185,234,98,9,132,221,135,39,165,61,119,178,173,8,15,208,137,145,136,226,160,88,3,216,165,84,69,181,159,134,202,114,38,123,74,40,51,72,56,26,106,76,113,172,30,64,80,
155,88,129,1,48,248,148,154,167,239,200,85,120,9,8,96,71,156,125,128,181,193,126,249,115,77,183,5,132,139,34,77,204,154,140,192,3,236,81,156,109,232,238,65,192,206,158,193,46,215,17,194,88,98,194,103,
102,170,91,71,71,245,63,240,242,179,47,94,15,233,26,215,73,211,17,190,70,33,127,176,12,60,1,104,196,184,196,24,231,209,140,60,19,17,57,114,6,118,22,16,227,207,186,216,179,17,119,50,60,83,66,231,123,247,
87,127,241,169,103,238,125,238,206,189,59,197,174,137,111,187,141,93,175,69,90,38,72,133,35,30,74,40,156,7,216,68,137,36,102,228,146,23,196,112,29,23,132,252,152,5,142,153,51,247,35,167,112,253,108,152,
121,61,175,134,105,141,48,92,222,99,142,192,95,30,55,30,84,104,84,96,237,35,233,239,80,140,24,40,118,23,130,183,69,185,119,9,114,135,48,73,119,40,184,121,176,34,129,125,33,236,6,99,117,194,48,205,90,57,
16,123,49,227,3,138,34,143,146,179,201,200,133,57,208,116,69,16,114,150,33,25,80,68,31,182,139,101,62,210,14,215,219,241,253,176,98,209,204,108,217,89,223,51,206,243,82,193,143,141,94,214,157,16,14,103,
27,161,216,142,156,126,147,34,199,86,164,232,30,41,186,135,17,215,20,227,97,6,125,47,200,236,100,188,223,237,19,61,182,86,245,40,230,191,170,248,179,98,226,254,242,35,239,91,229,21,95,246,125,128,174,
23,202,243,189,255,85,111,27,249,236,233,248,22,197,83,66,20,75,166,116,193,123,207,251,183,43,206,114,94,186,84,114,182,149,109,222,201,57,185,250,16,23,53,86,158,208,107,81,146,25,74,231,203,144,13,
139,185,107,194,97,36,179,87,41,139,90,181,244,253,120,22,145,78,48,112,238,49,202,39,130,30,134,222,42,5,239,211,229,165,131,48,112,226,179,194,80,87,200,100,93,8,29,115,134,50,18,214,89,247,90,160,84,
135,66,228,216,49,155,37,116,209,145,117,194,179,118,36,199,97,60,39,120,192,158,231,118,66,238,243,24,88,89,207,40,207,240,70,121,168,75,222,142,128,72,203,171,214,113,252,63,3,54,151,223,2,251,242,160,
244,32,4,204,140,194,192,52,5,218,27,17,133,127,217,0,0,0,65,73,68,65,84,12,170,193,223,2,91,72,175,129,45,170,231,64,245,247,129,227,31,159,129,114,223,128,243,227,159,129,131,82,183,128,5,193,91,96,
248,49,2,151,178,130,78,98,216,119,247,11,195,45,224,82,62,9,222,151,192,81,222,119,12,0,149,63,145,206,253,149,132,251,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MainComponent::violin_png = (const char*) resource_MainComponent_violin_png;
const int MainComponent::violin_pngSize = 147794;

// JUCER_RESOURCE: musicpizzicato_png, 910, "../res/Music-pizzicato.png"
static const unsigned char resource_MainComponent_musicpizzicato_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,200,0,0,0,200,8,4,0,0,0,7,81,102,21,0,0,0,44,116,69,88,116,67,114,101,97,
116,105,111,110,32,84,105,109,101,0,70,114,105,32,50,53,32,78,111,118,32,50,48,48,53,32,49,55,58,48,50,58,52,53,32,45,48,56,48,48,71,26,21,8,0,0,0,7,116,73,77,69,7,213,11,27,22,23,23,224,20,24,32,0,0,
0,9,112,72,89,115,0,0,11,18,0,0,11,18,1,210,221,126,252,0,0,0,4,103,65,77,65,0,0,177,143,11,252,97,5,0,0,2,229,73,68,65,84,120,218,237,221,77,139,141,97,28,199,241,191,135,80,68,145,44,44,164,148,146,
133,82,54,179,96,207,59,176,96,103,105,163,188,11,188,3,75,27,101,97,99,39,73,182,172,38,89,88,82,148,100,225,105,49,238,49,41,202,195,220,199,49,215,239,186,207,231,115,53,83,211,233,212,127,250,118,
157,251,156,123,174,154,42,0,0,0,0,128,25,108,106,61,192,92,156,254,246,253,65,235,49,230,97,26,65,86,166,243,187,108,110,61,0,63,19,36,140,32,97,4,9,35,72,24,65,194,8,18,70,144,48,130,132,17,36,140,32,
97,122,10,178,242,219,245,231,199,111,182,30,124,140,158,130,44,4,65,194,76,226,150,181,219,239,252,55,130,132,17,36,140,32,97,4,9,35,72,24,65,194,8,18,70,144,48,130,132,17,36,140,32,97,182,182,30,96,
46,46,182,30,0,0,0,24,97,83,157,105,61,2,63,242,73,61,140,32,97,166,113,235,100,119,157,172,99,117,184,14,214,222,218,54,252,252,174,94,213,147,122,80,203,173,7,91,60,123,234,82,61,252,237,169,222,187,
117,160,245,128,139,228,64,93,175,247,127,56,130,189,186,150,107,95,235,49,23,195,150,186,250,215,24,107,235,86,235,81,23,193,161,122,188,174,24,107,235,80,235,113,167,110,169,94,142,200,177,50,92,101,
58,210,223,187,172,165,186,87,187,70,61,227,68,235,145,199,232,237,115,200,209,209,57,170,118,180,30,122,140,190,130,108,175,219,163,115,116,166,175,32,87,234,248,12,207,122,211,122,236,169,218,89,111,
71,93,204,191,175,179,173,7,159,170,243,51,229,120,61,188,208,117,164,167,151,172,115,51,61,235,70,125,106,61,248,84,45,207,176,63,158,247,181,63,250,242,101,116,142,47,117,178,245,208,83,54,126,127,92,
104,61,242,180,141,205,113,185,245,192,83,55,38,198,135,225,61,25,255,217,250,115,188,112,237,216,8,235,205,113,179,246,180,30,117,49,172,39,198,253,90,106,61,230,191,233,233,92,214,253,225,235,90,93,
172,189,191,124,244,115,61,174,59,245,180,245,144,255,170,183,191,135,220,173,123,117,106,184,66,28,169,253,195,218,82,107,39,76,158,213,147,33,199,199,214,195,205,67,111,65,86,63,30,62,26,214,100,245,
116,47,139,48,171,23,237,201,179,67,194,8,18,70,144,48,130,132,17,36,140,32,97,4,9,35,72,24,65,194,8,18,70,144,48,130,132,17,36,140,32,97,4,9,35,72,24,65,194,8,18,70,144,48,91,59,58,151,181,170,175,105,
103,96,135,132,17,36,140,32,204,204,185,44,54,158,32,97,4,9,35,72,24,65,194,8,18,70,144,48,130,132,17,36,140,32,97,4,9,35,72,24,65,194,8,18,70,144,48,130,132,17,36,140,32,97,4,9,227,92,86,24,59,36,140,
32,97,4,97,102,206,101,177,241,4,9,35,72,24,65,194,8,18,70,144,48,130,132,17,36,140,32,97,4,9,35,72,24,65,194,8,18,70,144,48,130,132,17,36,140,32,97,4,9,35,72,24,231,178,194,216,33,97,122,250,79,159,11,
193,14,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,128,185,248,10,157,62,146,126,184,238,114,144,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MainComponent::musicpizzicato_png = (const char*) resource_MainComponent_musicpizzicato_png;
const int MainComponent::musicpizzicato_pngSize = 910;

// JUCER_RESOURCE: legato_png, 2313, "../res/legato.png"
static const unsigned char resource_MainComponent_legato_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,200,0,0,0,200,8,4,0,0,0,7,81,102,21,0,0,0,44,116,69,88,116,67,114,101,97,116,105,
111,110,32,84,105,109,101,0,70,114,105,32,50,53,32,78,111,118,32,50,48,48,53,32,49,55,58,48,50,58,52,53,32,45,48,56,48,48,71,26,21,8,0,0,0,7,116,73,77,69,7,213,11,26,8,27,13,31,199,71,73,0,0,0,9,112,72,
89,115,0,0,11,18,0,0,11,18,1,210,221,126,252,0,0,0,4,103,65,77,65,0,0,177,143,11,252,97,5,0,0,8,96,73,68,65,84,120,218,237,157,127,104,85,101,24,199,191,115,115,218,230,238,26,78,90,22,173,212,36,38,75,
45,208,44,99,75,13,35,43,43,201,81,16,34,66,100,127,88,16,132,84,127,4,253,97,17,40,6,34,134,208,47,162,164,200,66,164,116,136,136,102,67,178,153,133,75,211,166,51,92,98,104,91,206,31,115,236,246,156,
115,207,126,233,230,238,57,247,188,231,125,206,189,223,207,249,67,239,197,123,238,115,158,207,125,127,158,243,190,2,132,16,66,8,33,132,16,66,8,33,132,16,66,8,33,132,16,66,8,33,132,16,66,8,33,132,16,146,
75,36,229,72,131,17,182,227,36,3,161,16,101,80,136,50,40,68,25,20,162,12,10,81,6,133,40,131,66,148,65,33,202,160,16,101,80,136,50,40,68,25,20,162,12,10,81,6,133,40,131,66,148,65,33,202,160,16,101,80,136,
50,40,68,25,20,162,140,2,212,218,14,33,135,168,29,254,159,176,132,40,131,66,148,65,33,36,71,225,147,139,241,132,66,148,65,33,202,160,16,101,80,136,50,40,68,25,20,162,12,10,81,70,246,11,73,115,64,166,133,
236,23,18,51,40,68,25,20,162,12,10,81,6,133,40,131,66,148,65,33,202,160,16,101,80,136,50,40,68,25,185,241,92,150,150,107,76,35,14,150,16,101,152,20,178,83,14,226,19,150,144,28,66,199,196,183,142,40,248,
92,86,92,161,16,101,80,136,50,40,68,25,20,162,12,10,81,6,133,40,131,66,148,65,33,202,160,16,101,80,136,50,40,68,25,20,162,12,10,81,6,133,40,131,66,148,65,33,202,160,16,101,80,136,50,76,63,151,101,246,
236,241,138,34,173,56,10,108,199,152,149,20,99,140,251,231,121,116,248,253,40,133,132,201,120,204,198,52,84,161,180,247,157,51,216,143,239,241,75,250,167,160,144,112,24,129,26,60,133,234,107,222,31,135,
71,228,56,132,213,182,3,116,208,241,68,84,20,81,212,225,15,247,123,134,62,174,104,200,134,130,16,34,136,162,18,59,135,145,209,119,100,121,42,52,68,81,135,255,210,214,97,61,27,10,66,48,28,197,219,62,100,
40,200,134,130,16,140,70,177,198,167,14,235,217,80,16,130,193,40,222,240,173,195,122,54,20,132,96,44,138,249,1,116,88,207,134,130,16,12,69,81,42,3,62,255,58,206,165,115,106,78,46,6,225,45,148,7,248,212,
113,219,97,103,107,9,25,139,139,129,42,172,245,233,156,156,37,196,63,79,98,116,160,207,125,101,59,240,108,45,33,155,3,149,143,38,219,137,200,94,33,205,129,132,44,180,157,136,236,21,18,68,199,151,182,211,
96,38,21,58,162,240,223,229,109,66,177,237,52,152,73,133,142,40,190,243,169,163,21,183,216,78,130,169,84,232,136,98,137,207,210,113,147,237,20,152,75,133,142,40,70,13,123,59,170,239,248,92,71,101,101,
42,21,90,162,184,55,173,187,32,173,88,100,251,226,205,167,66,75,20,15,72,186,175,47,227,101,41,73,1,200,51,248,204,146,179,23,208,67,198,206,110,59,138,4,158,199,19,40,188,230,253,78,236,67,61,246,160,
59,216,105,249,212,73,80,218,177,14,159,98,22,170,112,155,247,206,25,25,50,30,146,227,74,38,167,165,144,76,104,199,54,57,66,133,147,139,57,68,54,55,234,198,96,9,81,6,133,40,131,66,194,99,26,22,14,210,
13,86,132,142,218,59,170,40,10,241,5,58,240,217,32,15,92,171,33,183,132,204,71,155,251,93,171,144,111,251,146,109,167,66,67,20,101,222,35,215,13,168,180,125,193,182,83,161,33,138,60,188,134,46,249,158,
54,41,39,138,137,94,72,169,252,62,157,163,180,223,123,81,68,81,235,77,53,110,96,163,158,98,34,94,197,150,1,183,86,79,226,67,212,68,20,69,5,246,186,223,114,16,19,34,186,222,128,68,33,36,31,117,216,61,228,
36,248,143,152,106,60,138,124,188,139,110,249,142,203,120,206,248,213,102,136,121,33,26,150,146,45,70,187,251,29,155,80,100,248,106,51,198,108,42,116,44,37,171,198,97,247,27,14,107,30,127,244,96,50,21,
58,150,146,149,97,171,123,254,118,41,39,49,192,92,42,116,44,37,203,151,65,160,211,217,237,210,60,24,236,143,169,84,104,89,74,182,212,107,61,182,74,73,137,5,102,82,161,101,41,89,13,142,123,157,221,201,
102,211,24,30,38,82,161,101,41,217,4,52,120,79,151,204,51,159,200,176,8,63,21,6,151,146,249,162,2,245,238,153,59,240,34,242,162,73,102,24,132,47,196,127,235,225,28,141,33,71,81,130,245,238,80,176,11,107,
195,159,42,137,211,126,89,9,188,20,232,115,45,161,70,49,10,203,241,184,91,46,182,99,27,238,15,241,204,46,97,61,6,148,193,14,81,105,51,59,224,239,113,87,136,49,140,192,2,57,156,251,172,141,248,24,23,194,
191,200,76,133,132,176,67,84,218,204,10,244,169,22,252,28,90,4,5,34,99,153,155,179,70,188,135,211,6,174,49,3,33,209,239,16,53,41,208,167,62,8,237,251,139,68,198,2,247,137,93,71,71,107,232,215,151,17,54,
166,245,130,52,232,225,45,37,43,193,58,119,92,158,196,14,109,211,236,182,166,245,108,46,37,203,199,74,79,135,186,105,68,123,211,122,246,150,146,229,75,207,42,53,77,114,20,115,162,79,249,245,176,57,173,
183,196,103,233,8,107,41,89,9,86,121,58,26,188,187,144,106,176,59,173,103,103,41,89,133,12,3,149,182,29,246,167,245,162,95,74,54,83,218,203,110,157,58,116,76,235,25,91,74,54,8,249,88,44,109,134,115,214,
110,212,107,211,161,101,90,207,217,139,103,205,160,187,241,92,196,102,41,25,225,221,40,42,235,109,57,58,240,190,84,92,17,145,238,92,229,26,188,18,224,236,7,48,221,72,212,99,241,24,238,195,93,222,171,191,
240,155,52,183,13,184,28,226,55,84,227,29,169,19,28,189,199,240,58,190,65,167,145,235,200,32,1,6,119,136,82,71,33,150,138,134,164,206,126,85,138,101,129,116,36,49,215,118,224,1,168,144,10,170,195,141,
190,11,91,181,181,28,61,196,118,135,40,223,244,245,170,206,74,27,162,246,94,121,115,32,33,10,118,136,242,69,17,94,240,238,147,59,119,202,31,213,252,36,73,16,29,42,118,136,242,65,53,54,73,183,32,85,85,
109,210,254,224,66,108,119,136,74,147,132,148,141,158,102,252,44,86,162,196,118,64,195,17,219,29,162,210,32,129,58,105,55,46,123,3,192,189,94,103,87,57,75,124,150,14,53,59,68,13,67,161,164,191,71,70,82,
198,51,43,163,27,0,102,70,108,119,136,186,14,121,152,130,13,222,186,192,164,187,92,115,106,156,30,233,137,233,14,81,67,224,200,88,45,37,34,217,91,81,45,210,189,246,105,48,162,156,214,51,201,64,25,177,
170,168,174,38,170,105,61,115,92,45,163,77,95,69,229,55,24,243,211,122,230,174,180,10,203,176,184,183,255,215,46,35,165,143,176,79,219,180,97,110,144,192,60,108,28,80,77,109,68,77,252,90,141,108,32,15,
147,176,2,187,189,233,66,231,56,42,149,214,20,93,213,84,174,144,42,23,45,222,100,161,211,155,106,17,25,19,41,35,106,242,112,51,230,72,223,169,127,185,104,151,87,43,164,180,80,70,196,20,97,54,214,202,48,
182,175,55,120,69,94,173,198,12,41,47,36,82,202,80,43,165,98,103,239,216,59,53,81,88,143,103,165,188,196,168,92,100,22,234,92,148,99,187,145,71,25,210,165,0,227,100,88,87,37,195,214,153,210,25,239,91,
186,127,9,199,176,69,58,182,191,155,88,50,160,149,132,59,49,183,31,171,112,79,228,93,200,2,25,17,205,192,114,124,141,63,165,125,232,238,87,42,218,208,40,77,249,195,113,29,125,103,82,66,234,240,137,39,
226,28,126,144,99,15,14,186,51,94,230,40,64,41,110,149,146,48,77,58,174,119,202,16,175,255,125,11,103,116,177,23,7,34,136,194,40,153,8,153,139,55,165,108,148,244,158,163,93,126,173,135,209,140,38,28,193,
9,252,29,74,82,242,220,149,89,229,184,17,147,61,13,227,251,125,163,67,82,210,127,18,59,68,198,126,247,38,83,204,201,172,13,73,224,14,25,241,62,35,90,6,110,188,210,129,86,73,207,1,156,22,49,255,200,235,
110,121,221,137,243,195,166,107,52,70,138,128,113,238,223,139,48,93,142,132,136,200,23,33,37,242,254,213,177,118,137,136,102,124,139,93,82,54,206,198,95,69,138,48,250,31,9,169,205,159,150,228,221,62,72,
189,125,201,221,9,61,137,83,210,17,61,210,219,192,118,73,181,146,90,139,56,121,192,205,172,74,55,245,169,255,180,113,196,16,247,85,46,200,240,238,95,25,85,52,137,234,159,164,178,188,100,59,133,225,18,
94,135,176,88,132,204,20,45,149,94,90,199,132,118,238,46,119,84,113,202,211,208,140,95,69,130,185,165,165,150,9,191,135,94,128,27,220,58,255,65,169,243,157,218,191,210,253,205,143,76,243,63,99,236,73,
126,167,252,254,79,120,37,201,249,155,83,233,101,177,134,62,76,15,153,28,61,78,171,80,222,111,183,206,98,220,221,111,177,233,105,169,202,250,232,73,126,167,84,117,89,86,25,17,66,8,33,132,16,66,8,33,132,
16,66,136,65,254,7,143,98,80,173,54,211,166,19,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MainComponent::legato_png = (const char*) resource_MainComponent_legato_png;
const int MainComponent::legato_pngSize = 2313;

// JUCER_RESOURCE: musictrill_png, 1429, "../res/Music-trill.png"
static const unsigned char resource_MainComponent_musictrill_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,200,0,0,0,200,8,4,0,0,0,7,81,102,21,0,0,0,44,116,69,88,116,67,114,101,97,116,
105,111,110,32,84,105,109,101,0,70,114,105,32,50,53,32,78,111,118,32,50,48,48,53,32,49,55,58,48,50,58,52,53,32,45,48,56,48,48,71,26,21,8,0,0,0,7,116,73,77,69,7,213,11,26,10,25,34,133,164,204,252,0,0,0,
9,112,72,89,115,0,0,11,18,0,0,11,18,1,210,221,126,252,0,0,0,4,103,65,77,65,0,0,177,143,11,252,97,5,0,0,4,236,73,68,65,84,120,218,237,221,65,104,28,85,28,199,241,95,77,177,194,22,43,77,37,133,8,169,164,
80,208,130,98,69,15,9,164,208,139,16,193,99,197,30,44,68,241,152,131,66,14,30,122,80,240,32,24,239,30,114,240,160,135,66,10,17,82,80,136,18,36,72,17,227,41,74,10,21,44,88,72,161,72,132,84,99,89,223,166,
201,58,47,217,118,119,54,201,254,255,239,237,247,243,88,200,204,236,194,127,246,199,123,111,118,102,118,35,1,0,128,44,244,88,23,176,7,123,240,134,94,208,117,173,91,23,130,154,65,93,83,85,191,91,151,129,
251,206,107,53,196,81,213,164,117,33,144,42,154,218,8,163,214,134,172,139,193,115,90,174,199,193,128,101,110,48,76,225,213,122,251,200,186,28,188,95,136,163,26,122,11,140,205,23,226,88,182,46,6,253,81,
255,248,192,186,28,140,49,96,249,50,155,243,128,117,208,186,128,210,42,58,91,88,250,50,60,6,116,88,199,117,66,79,109,60,142,135,165,19,97,237,95,97,219,219,155,207,122,89,111,105,88,39,117,87,223,232,
67,253,104,189,11,233,234,141,14,111,203,183,103,85,155,113,102,163,117,235,33,30,180,105,124,87,113,212,230,151,33,173,132,8,166,117,73,115,245,181,179,214,187,245,48,190,135,172,139,77,182,223,214,47,
97,104,186,169,223,116,61,60,110,133,191,238,233,179,48,60,109,57,166,43,97,251,176,126,216,120,238,217,205,181,195,214,187,149,147,11,77,143,176,22,234,91,239,104,53,180,83,155,235,103,11,131,22,246,
204,116,147,35,172,254,109,131,214,155,245,45,215,234,235,230,173,119,34,31,21,173,53,249,72,24,207,58,115,133,45,91,125,107,85,35,214,187,145,143,120,192,106,116,180,52,31,61,35,126,235,71,194,212,62,
161,65,235,157,200,73,113,192,106,116,210,61,30,176,22,172,203,205,93,60,96,53,186,74,56,254,128,249,3,251,34,30,176,26,93,37,44,14,88,171,58,100,93,112,238,202,13,88,159,91,151,155,187,178,3,214,107,
214,5,231,46,30,176,206,53,120,198,66,97,251,26,3,214,126,43,14,88,43,13,110,240,27,140,2,155,182,46,183,93,143,88,23,208,162,138,94,41,44,93,209,189,29,207,120,61,90,186,108,93,112,238,154,15,88,63,69,
3,86,197,186,224,220,149,27,176,92,159,96,207,65,124,132,53,181,99,123,111,20,88,85,99,214,5,231,110,52,122,187,207,111,219,58,22,250,76,124,77,176,215,186,224,220,197,159,48,250,10,91,70,10,167,213,183,
218,215,214,229,238,70,26,71,89,79,52,92,58,167,57,125,171,23,55,254,254,183,176,253,43,235,114,243,23,15,89,55,244,174,62,46,220,108,61,19,250,73,113,142,233,183,46,55,127,61,209,65,109,28,206,168,226,
91,231,184,30,216,17,125,90,218,17,198,154,46,109,158,32,41,158,229,157,176,46,181,91,84,194,219,255,255,209,212,138,38,163,201,61,27,7,172,11,40,165,71,167,55,238,74,188,169,197,6,39,79,0,0,0,0,164,225,
64,244,125,36,152,75,227,108,111,23,33,16,103,124,127,131,170,85,143,235,140,158,209,211,234,215,81,61,26,150,255,212,45,45,234,59,45,89,23,214,125,142,232,157,109,95,65,40,182,153,60,79,64,122,213,167,
201,205,223,203,122,112,91,226,250,122,103,244,104,162,105,24,247,219,23,214,165,118,131,129,232,62,222,102,109,192,186,220,220,13,233,143,18,113,84,195,44,147,144,244,142,178,134,116,85,135,75,189,226,
121,235,146,203,72,237,115,200,169,210,113,72,143,89,23,93,70,90,129,28,210,229,210,113,36,38,173,64,222,211,233,54,94,117,219,186,236,92,85,116,167,212,100,190,213,70,173,11,207,213,133,182,226,88,73,
235,203,109,41,13,89,175,182,245,170,79,245,183,117,225,185,90,106,163,127,44,167,213,63,210,82,254,215,229,214,117,198,186,232,156,149,239,31,252,184,198,190,42,27,199,184,117,193,185,43,19,198,90,56,
38,195,62,107,61,142,27,204,29,157,208,106,28,83,58,98,93,106,119,104,37,140,185,212,255,185,75,74,247,101,213,126,65,241,19,93,212,209,134,91,255,209,130,166,245,179,117,145,187,149,218,245,144,25,93,
213,75,97,134,56,169,39,67,171,253,162,67,237,14,147,95,181,24,226,184,107,93,220,94,72,45,144,218,199,195,239,67,203,86,74,231,178,224,76,109,210,206,30,61,196,25,2,113,134,64,156,33,16,103,8,196,25,
2,113,134,64,156,33,16,103,8,196,25,2,113,134,64,156,33,16,103,8,196,25,2,113,134,64,156,33,16,103,8,196,25,2,113,134,64,156,57,152,208,125,89,53,105,85,219,6,122,136,51,4,226,12,129,160,109,220,151,133,
206,35,16,103,8,196,25,2,113,134,64,156,33,16,103,8,196,25,2,113,134,64,156,33,16,103,8,196,25,2,113,134,64,156,33,16,103,8,196,25,2,113,134,64,156,33,16,103,8,196,25,238,203,114,134,30,226,12,129,56,
67,32,104,27,247,101,161,243,8,196,25,2,113,134,64,156,33,16,103,8,196,25,2,113,134,64,156,33,16,103,8,196,25,2,113,134,64,156,33,16,103,8,196,25,2,113,134,64,156,33,16,103,8,196,25,2,113,134,251,178,
156,161,135,56,147,210,127,250,236,10,244,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,246,196,127,225,1,76,184,113,173,231,97,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MainComponent::musictrill_png = (const char*) resource_MainComponent_musictrill_png;
const int MainComponent::musictrill_pngSize = 1429;

// JUCER_RESOURCE: musictremolo_png, 1197, "../res/Music-tremolo.png"
static const unsigned char resource_MainComponent_musictremolo_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,200,0,0,0,200,8,4,0,0,0,7,81,102,21,0,0,0,44,116,69,88,116,67,114,101,97,116,
105,111,110,32,84,105,109,101,0,70,114,105,32,50,53,32,78,111,118,32,50,48,48,53,32,49,55,58,48,50,58,52,53,32,45,48,56,48,48,71,26,21,8,0,0,0,7,116,73,77,69,7,213,11,26,9,7,0,134,195,12,158,0,0,0,9,112,
72,89,115,0,0,11,18,0,0,11,18,1,210,221,126,252,0,0,0,4,103,65,77,65,0,0,177,143,11,252,97,5,0,0,4,4,73,68,65,84,120,218,237,221,207,75,20,97,28,199,241,111,38,25,24,122,168,16,18,234,176,157,132,80,136,
136,72,176,155,157,250,65,7,15,17,118,10,58,249,7,116,40,240,158,199,160,75,65,144,7,131,133,34,10,60,120,49,130,32,172,139,30,44,10,34,60,8,238,33,67,72,168,158,213,149,221,153,217,103,114,54,103,158,
239,243,236,251,245,28,194,157,21,191,206,135,217,245,249,238,51,79,34,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,63,237,147,11,174,75,64,163,14,215,5,32,42,252,64,230,204,240,72,248,129,
64,153,63,102,120,132,43,68,25,2,81,134,64,148,33,16,101,8,68,25,2,81,134,64,148,33,16,101,8,68,25,2,81,134,64,148,105,231,64,6,101,214,117,9,237,168,121,115,177,36,101,223,218,142,161,72,158,246,146,
60,146,205,173,199,9,196,129,232,105,239,147,41,217,168,133,65,32,78,212,79,123,175,76,70,194,32,16,39,182,79,123,151,220,149,74,44,12,2,113,162,122,218,39,100,165,73,24,4,226,192,126,75,16,219,227,137,
235,242,146,194,94,151,117,94,110,75,191,229,216,188,60,150,207,174,11,76,234,116,93,64,110,206,200,45,57,105,57,246,65,30,202,146,235,2,155,11,51,144,65,185,41,67,150,99,139,38,140,143,174,11,180,11,
47,144,146,9,99,216,114,236,147,121,153,122,227,186,192,118,82,146,105,235,27,248,178,92,143,61,155,94,86,174,250,27,26,34,241,241,77,198,205,223,91,141,232,101,229,108,42,49,7,111,28,93,145,231,210,203,
42,64,243,32,42,102,126,78,47,203,137,100,24,27,38,140,94,161,151,229,72,60,140,41,115,45,212,143,208,203,42,92,253,20,111,154,119,136,254,216,17,122,89,133,171,119,167,74,145,199,189,235,101,133,162,
122,122,203,102,102,17,117,217,204,62,108,97,36,159,141,61,52,39,103,99,143,140,202,130,53,140,228,179,145,171,17,115,202,109,97,188,53,71,81,160,193,218,28,188,217,88,48,47,98,40,16,189,44,69,232,101,
169,66,47,75,25,122,89,202,208,203,82,134,94,150,50,244,178,148,105,173,151,181,236,186,236,164,80,214,101,85,119,252,73,174,180,74,91,151,245,221,132,55,43,191,93,23,30,23,202,170,147,228,74,171,180,
117,89,107,38,186,151,250,194,168,10,229,10,137,74,91,151,181,38,79,229,185,121,167,81,42,148,43,164,46,109,93,214,186,121,153,42,235,13,35,60,105,189,172,74,109,94,130,130,164,245,178,8,163,112,233,189,
172,190,255,255,1,200,166,121,16,213,25,59,211,63,39,146,97,236,204,216,9,196,137,100,24,165,134,35,40,92,99,28,51,145,246,9,129,56,97,95,220,67,32,78,84,79,251,139,166,43,173,8,196,137,57,235,226,30,
2,81,198,179,64,218,121,123,38,149,8,68,25,2,81,134,64,148,33,16,101,8,68,25,2,81,134,64,148,33,16,101,58,131,92,117,18,231,209,239,24,214,170,147,110,57,180,245,239,186,252,116,93,74,171,194,8,228,152,
12,203,144,12,52,44,100,88,149,247,242,90,243,190,88,54,190,7,210,33,35,114,85,78,37,30,63,42,23,205,88,148,251,174,11,108,47,99,41,247,161,239,124,152,235,89,183,215,95,39,82,110,125,230,166,131,194,
141,201,143,93,199,65,32,185,155,204,16,6,129,228,110,42,99,28,4,146,171,59,153,227,32,144,28,141,182,16,7,129,228,166,215,76,248,178,199,81,113,93,118,22,126,53,23,239,201,145,22,190,235,171,235,178,
67,117,56,245,150,3,251,120,224,186,240,44,124,186,66,174,200,193,150,190,239,153,235,194,67,85,110,233,250,80,250,191,32,132,224,75,75,129,176,101,89,110,90,137,99,198,117,209,33,203,254,39,239,146,116,
187,46,58,100,175,50,198,177,98,221,86,3,123,98,60,227,213,193,189,183,57,235,250,231,199,81,245,49,205,139,85,17,78,239,234,83,144,21,185,230,186,208,246,113,222,186,21,217,78,24,19,177,45,47,61,227,
223,110,64,61,114,67,46,201,129,196,227,191,228,157,204,202,188,206,77,151,118,207,191,64,170,122,228,156,12,200,241,218,87,171,102,202,184,104,70,16,187,252,248,25,72,192,124,106,46,2,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,160,216,95,163,253,11,218,68,204,228,255,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MainComponent::musictremolo_png = (const char*) resource_MainComponent_musictremolo_png;
const int MainComponent::musictremolo_pngSize = 1197;

// JUCER_RESOURCE: staccato_png, 1794, "../res/staccato.png"
static const unsigned char resource_MainComponent_staccato_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,202,0,0,0,229,8,6,0,0,0,18,159,104,75,0,0,0,6,98,75,71,68,0,255,0,255,0,255,160,
189,167,147,0,0,0,7,116,73,77,69,7,217,11,28,8,25,35,163,142,183,163,0,0,6,164,73,68,65,84,120,156,237,221,77,168,84,117,24,128,241,103,116,172,80,211,52,44,43,209,52,43,136,202,44,203,136,190,200,77,
68,184,138,8,35,48,130,90,6,17,180,104,21,180,8,34,130,118,73,187,22,73,22,180,136,136,62,23,89,66,31,27,233,203,82,251,208,16,43,63,174,166,230,45,175,45,254,69,215,219,189,249,206,56,231,190,51,231,
60,63,56,136,131,94,222,59,119,158,59,231,204,156,243,159,22,112,28,73,255,103,104,74,246,4,210,32,48,20,41,160,13,172,203,30,66,234,115,71,178,7,144,36,73,146,36,73,146,36,73,146,36,73,146,36,73,146,
36,73,146,36,73,146,36,73,205,114,23,176,119,204,182,49,117,162,154,107,103,15,160,174,156,6,204,25,115,219,172,140,65,154,194,117,189,164,0,67,145,2,12,69,10,48,20,41,192,80,164,0,67,145,2,12,69,10,48,
20,41,192,80,164,0,67,145,2,12,69,10,48,20,41,192,80,164,0,67,145,2,12,69,10,48,20,41,160,13,60,150,61,132,58,118,213,56,183,205,195,159,101,85,142,182,128,227,217,83,72,125,110,200,93,47,41,192,80,164,
128,22,176,36,123,8,117,108,53,240,236,152,219,182,0,119,36,204,210,4,35,109,96,123,246,20,234,216,207,227,220,54,140,63,203,202,184,235,37,5,24,138,20,96,40,82,128,161,72,1,134,34,5,24,138,20,96,40,82,
128,161,72,1,134,34,5,24,138,20,96,40,82,128,161,72,1,134,34,5,24,138,20,96,40,82,128,161,72,1,134,34,5,24,138,20,96,40,82,128,161,72,1,134,34,5,24,138,20,96,40,82,128,161,72,1,134,34,5,24,138,20,96,40,
82,128,161,72,1,134,34,5,24,138,20,96,40,82,128,161,72,1,134,34,5,24,138,20,96,40,82,128,161,72,1,134,34,5,180,128,189,217,67,168,99,167,1,51,198,220,118,12,56,144,48,75,19,28,104,1,199,179,167,144,250,
220,144,187,94,82,64,27,216,144,61,132,58,182,16,88,57,230,182,33,224,173,132,89,154,224,112,246,0,234,206,26,202,46,243,232,109,115,234,68,53,231,174,151,20,96,40,82,128,161,72,1,134,34,5,24,138,20,96,
40,82,128,161,72,1,134,34,5,24,138,20,96,40,82,128,161,72,1,134,34,5,24,138,20,96,40,82,128,161,72,1,134,34,5,24,138,20,96,40,82,128,161,72,1,134,34,5,24,138,20,96,40,82,128,161,72,1,134,34,5,24,138,20,
96,40,82,128,161,72,1,134,34,5,24,138,20,96,40,82,128,161,72,1,134,34,5,24,138,20,96,40,82,128,161,72,1,134,34,5,24,138,20,208,6,30,204,30,66,29,187,110,156,219,230,226,207,178,42,195,45,202,71,47,75,
154,216,144,187,94,82,128,161,72,1,45,224,154,236,33,212,177,219,129,39,199,220,182,21,184,39,97,150,38,56,150,61,128,186,179,134,114,108,57,122,219,156,58,81,205,185,235,37,5,24,138,20,96,40,82,128,161,
72,1,134,34,5,24,138,20,96,40,82,128,161,72,1,134,34,5,24,138,20,96,40,82,128,161,72,1,134,34,5,24,138,20,96,40,82,128,161,72,1,134,34,5,180,179,7,168,169,169,192,82,224,34,224,66,96,17,101,57,161,217,
192,156,191,255,28,6,142,140,250,63,191,255,253,247,67,192,78,224,39,224,67,224,115,92,41,39,157,161,244,198,76,96,21,112,43,176,2,88,14,204,232,209,215,222,9,60,7,60,15,28,232,209,215,148,38,205,108,
202,130,115,239,2,71,249,239,53,236,189,222,246,3,79,80,158,145,188,102,94,125,239,6,224,101,224,48,213,199,49,222,54,68,137,211,80,212,119,90,192,106,202,49,67,70,28,145,205,80,148,234,122,96,19,249,
33,24,138,250,210,217,192,122,96,132,252,8,12,69,125,233,54,202,171,77,217,15,126,67,81,95,154,6,60,69,89,66,51,251,129,111,40,125,196,247,81,254,53,19,216,64,89,215,87,58,129,161,20,243,129,215,113,193,
114,77,192,80,224,18,224,77,96,113,246,32,234,95,77,15,229,114,224,61,96,94,246,32,234,111,77,62,123,120,41,240,54,70,162,128,166,134,114,33,240,62,229,216,68,58,169,38,134,50,143,242,76,178,32,123,16,
13,142,166,133,210,166,188,4,188,52,123,16,13,150,166,133,242,48,112,75,246,16,82,63,155,9,236,35,255,29,116,223,153,31,64,77,122,70,121,0,56,43,123,8,13,166,22,176,45,123,136,73,50,31,152,158,61,68,133,
134,41,39,114,170,247,14,182,40,79,219,146,38,54,212,164,93,47,169,107,109,224,157,236,33,42,118,53,101,169,160,58,251,22,248,33,123,136,26,59,148,61,64,213,166,0,187,201,127,69,170,202,237,32,190,121,
170,83,180,156,252,7,114,213,219,35,61,187,183,212,88,107,201,127,32,87,185,189,65,89,149,82,21,171,251,193,252,197,217,3,84,104,43,112,47,229,178,101,85,172,238,161,204,201,30,160,34,223,81,22,192,216,
151,61,72,83,212,61,148,211,179,7,168,192,143,148,72,118,100,15,210,36,117,15,165,110,47,235,125,5,220,12,124,159,60,71,227,212,61,148,58,237,154,108,2,110,196,247,75,82,212,61,148,237,217,3,244,200,107,
148,143,149,216,155,61,136,234,233,50,242,95,194,61,149,109,4,120,146,250,255,66,83,178,41,148,103,149,236,7,124,55,219,111,192,221,189,191,75,164,241,61,74,254,131,190,211,109,51,176,172,138,59,67,154,
200,233,192,215,228,63,248,35,219,17,224,113,202,26,200,210,164,187,150,242,82,113,118,8,19,109,35,192,171,192,165,85,221,1,82,212,157,148,223,216,217,81,140,222,142,1,175,0,87,84,248,125,75,29,187,9,
248,133,252,64,14,2,235,48,16,245,177,115,41,239,75,100,4,242,25,240,16,112,102,229,223,165,212,35,171,128,141,84,127,236,241,9,229,0,221,103,15,13,180,43,128,103,232,221,43,99,219,128,23,41,207,28,23,
76,226,247,161,10,181,178,7,232,51,231,83,174,97,89,0,156,67,89,167,120,42,101,61,176,169,192,172,81,255,118,152,114,74,201,30,96,23,176,5,248,2,248,117,18,231,149,36,73,146,36,73,146,36,73,146,36,73,
170,1,79,97,233,157,203,128,251,128,43,41,87,85,110,5,94,2,62,160,156,28,41,53,218,34,224,35,198,255,120,137,253,192,55,148,51,149,165,198,90,70,89,226,244,100,103,20,239,6,30,76,154,81,74,53,155,114,
74,125,244,244,251,93,192,13,41,147,74,137,94,160,92,243,222,201,181,42,159,166,76,42,37,153,70,249,232,133,78,47,234,218,3,172,72,152,87,167,200,165,58,187,179,146,114,49,87,167,230,226,234,143,3,201,
80,186,115,1,39,94,237,216,9,215,238,26,64,134,210,157,97,186,255,72,184,186,125,102,75,35,24,74,119,190,164,187,143,96,24,1,62,238,241,44,82,95,235,102,213,150,29,192,121,25,195,74,89,214,82,86,124,236,
100,141,175,245,25,131,74,153,90,192,91,192,159,196,66,249,134,242,38,165,212,56,211,129,119,129,3,76,28,200,31,148,221,180,197,73,51,74,125,161,5,220,79,57,192,223,69,217,29,59,66,57,191,107,43,240,52,
37,40,13,48,79,179,239,173,133,192,18,224,12,202,167,247,254,115,192,47,73,146,36,73,146,36,73,146,36,73,106,170,191,0,30,199,90,8,70,44,205,21,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MainComponent::staccato_png = (const char*) resource_MainComponent_staccato_png;
const int MainComponent::staccato_pngSize = 1794;

// JUCER_RESOURCE: musichalfnote_png, 980, "../res/Music-halfnote.png"
static const unsigned char resource_MainComponent_musichalfnote_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,200,0,0,0,200,8,4,0,0,0,7,81,102,21,0,0,0,44,116,69,88,116,67,114,101,97,116,
105,111,110,32,84,105,109,101,0,70,114,105,32,50,53,32,78,111,118,32,50,48,48,53,32,49,55,58,48,50,58,52,53,32,45,48,56,48,48,71,26,21,8,0,0,0,7,116,73,77,69,7,213,11,26,2,58,27,106,27,98,45,0,0,0,9,112,
72,89,115,0,0,11,18,0,0,11,18,1,210,221,126,252,0,0,0,4,103,65,77,65,0,0,177,143,11,252,97,5,0,0,3,43,73,68,65,84,120,218,237,221,177,107,20,89,28,192,241,159,174,122,72,132,3,15,43,65,139,8,22,34,10,
22,225,208,226,196,210,194,230,192,194,70,176,176,176,180,176,176,176,200,31,96,33,114,224,21,41,174,176,184,34,112,150,22,41,78,8,104,161,96,97,161,96,37,22,130,130,10,130,34,241,101,35,146,205,204,174,
74,156,204,111,198,207,103,32,201,102,95,241,178,223,188,157,221,201,131,68,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,208,77,155,226,143,182,167,192,106,155,219,158,0,163,250,31,100,161,28,29,210,255,32,36,
179,84,142,14,177,66,146,17,36,25,65,146,17,36,25,65,146,17,36,25,65,146,17,36,25,65,146,17,36,25,65,146,17,36,25,65,146,17,36,25,65,146,17,36,25,65,146,17,36,25,65,146,217,242,83,236,203,234,208,207,
104,133,36,35,72,50,130,176,193,236,203,98,61,4,73,70,144,100,4,73,70,144,100,4,73,70,144,100,4,73,70,144,100,4,73,70,144,100,4,73,70,144,100,4,73,70,144,100,4,73,70,144,100,4,73,70,144,100,236,203,74,
198,10,73,70,144,100,4,97,131,217,151,197,122,8,146,140,32,201,8,146,140,32,201,8,146,140,32,201,8,146,140,32,201,8,146,140,32,201,8,146,140,32,201,8,146,140,32,201,8,146,140,32,201,8,146,140,32,201,216,
151,149,204,150,182,39,240,67,108,141,131,113,56,246,197,238,216,21,219,203,237,183,241,34,158,196,131,184,19,175,219,158,218,247,234,254,127,250,60,20,39,227,216,48,67,213,251,248,47,254,44,159,143,183,
61,201,111,215,237,21,114,52,206,150,117,49,222,182,97,14,54,196,161,88,28,238,185,170,30,255,199,197,114,239,84,57,102,63,127,135,198,93,138,15,53,41,222,197,181,216,63,50,110,94,144,230,77,197,191,181,
43,99,174,156,212,215,186,34,72,211,166,202,83,82,53,198,253,152,169,29,253,151,32,205,26,196,173,74,140,15,101,29,12,106,71,255,18,207,5,105,214,229,74,142,71,229,4,62,206,37,39,245,102,29,168,156,202,
231,202,83,216,248,209,239,4,105,214,252,72,140,55,113,126,194,216,169,178,118,150,4,105,210,238,145,245,241,60,142,76,24,59,136,219,95,70,190,106,123,226,125,117,126,36,199,254,9,35,7,35,47,140,23,219,
158,120,95,205,173,122,178,154,153,48,110,176,230,125,202,108,219,19,239,171,133,47,15,241,201,9,163,6,149,183,141,211,109,79,188,175,22,190,225,55,254,215,85,231,142,149,227,102,219,211,238,175,149,32,
15,199,188,9,92,118,52,158,174,201,241,38,246,182,61,237,254,90,9,114,106,204,189,131,242,166,177,122,193,241,116,219,147,238,179,191,135,47,97,235,215,199,145,218,139,241,78,231,141,186,56,188,136,88,
53,93,94,127,213,93,140,191,218,246,132,251,110,102,120,33,113,122,205,247,254,169,141,177,20,87,218,158,238,207,224,113,121,160,31,199,137,242,213,111,229,227,236,240,118,221,241,106,236,153,134,31,234,
204,152,0,163,199,173,154,63,84,117,70,215,118,157,92,248,202,182,133,39,113,35,238,181,61,201,245,232,218,174,147,235,241,44,206,197,142,154,123,62,198,221,152,239,118,140,101,93,91,33,203,182,198,239,
113,56,246,148,39,166,109,177,51,94,196,203,225,166,184,187,221,219,20,87,167,139,65,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,32,161,79,243,218,56,170,217,222,232,126,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* MainComponent::musichalfnote_png = (const char*) resource_MainComponent_musichalfnote_png;
const int MainComponent::musichalfnote_pngSize = 980;


//[EndFile] You can add extra defines here...
//[/EndFile]
