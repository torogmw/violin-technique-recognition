//
//  OfflineVisualization.cpp
//  ViolinMIR
//
//  Created by Minwei Gu on 12/2/13.
//
//

#include "OfflineVisualization.h"

class DemoThumbnailComp  : public Component, public ChangeListener, public FileDragAndDropTarget, private Timer
{
public:
    DemoThumbnailComp (AudioFormatManager& formatManager,
                       AudioTransportSource& transportSource_,
                       Slider& zoomSlider_)
    : transportSource (transportSource_),
    zoomSlider (zoomSlider_),
    thumbnailCache (5),
    thumbnail (512, formatManager, thumbnailCache)
    {
        startTime = endTime = 0;
        thumbnail.addChangeListener (this);
        
        currentPositionMarker.setFill (Colours::purple.withAlpha (0.7f));
        addAndMakeVisible (&currentPositionMarker);
    }
    
    ~DemoThumbnailComp()
    {
        thumbnail.removeChangeListener (this);
    }
    
    void setFile (const File& file)
    {
        thumbnail.setSource (new FileInputSource (file));
        startTime = 0;
        endTime = thumbnail.getTotalLength();
        startTimer (1000 / 40);
    }
    
    void setZoomFactor (double amount)
    {
        if (thumbnail.getTotalLength() > 0)
        {
            const double newScale = jmax (0.001, thumbnail.getTotalLength() * (1.0 - jlimit (0.0, 0.99, amount)));
            const double timeAtCentre = xToTime (getWidth() / 2.0f);
            startTime = timeAtCentre - newScale * 0.5;
            endTime = timeAtCentre + newScale * 0.5;
            repaint();
        }
    }
    
    void mouseWheelMove (const MouseEvent&, const MouseWheelDetails& wheel)
    {
        if (thumbnail.getTotalLength() > 0)
        {
            double newStart = startTime - wheel.deltaX * (endTime - startTime) / 10.0;
            newStart = jlimit (0.0, jmax (0.0, thumbnail.getTotalLength() - (endTime - startTime)), newStart);
            endTime = newStart + (endTime - startTime);
            startTime = newStart;
            
            if (wheel.deltaY != 0)
                zoomSlider.setValue (zoomSlider.getValue() - wheel.deltaY);
            
            repaint();
        }
    }
    
    void paint (Graphics& g)
    {
        g.fillAll (Colours::white);
        g.setColour (Colours::lightblue);
        
        if (thumbnail.getTotalLength() > 0)
        {
            thumbnail.drawChannels (g, getLocalBounds().reduced (2),
                                    startTime, endTime, 1.0f);
        }
        else
        {
            g.setFont (14.0f);
            g.drawFittedText ("(No audio file selected)", getLocalBounds(), Justification::centred, 2);
        }
    }
    
    void changeListenerCallback (ChangeBroadcaster*)
    {
        // this method is called by the thumbnail when it has changed, so we should repaint it..
        repaint();
    }
    
    bool isInterestedInFileDrag (const StringArray& /*files*/)
    {
        return true;
    }
    
    void filesDropped (const StringArray& files, int /*x*/, int /*y*/)
    {
        AudioDemoPlaybackPage* demoPage = findParentComponentOfClass<AudioDemoPlaybackPage>();
        
        if (demoPage != nullptr)
            demoPage->showFile (File (files[0]));
    }
    
    void mouseDown (const MouseEvent& e)
    {
        mouseDrag (e);
    }
    
    void mouseDrag (const MouseEvent& e)
    {
        transportSource.setPosition (jmax (0.0, xToTime ((float) e.x)));
    }
    
    void mouseUp (const MouseEvent&)
    {
        transportSource.start();
    }
    
    void timerCallback()
    {
        currentPositionMarker.setVisible (transportSource.isPlaying() || isMouseButtonDown());
        
        double currentPlayPosition = transportSource.getCurrentPosition();
        
        currentPositionMarker.setRectangle (Rectangle<float> (timeToX (currentPlayPosition) - 0.75f, 0,
                                                              1.5f, (float) getHeight()));
    }
    
    void drawSegment (const vector<int>& result)
    {
        float timeLag = (result.size()-1)/44100;
        for (int i = 0; i<result.size()-1; i++)
        {
            segmentationBar.add(new DrawableRectangle());
            switch (result[i]) {
                case 1:
                {
                    segmentationBar[i]-> setFill (Colours::red.withAlpha (0.9f));
                    addAndMakeVisible (segmentationBar[i]);
                    segmentationBar[i]->setVisible(true);
                    segmentationBar[i]->setRectangle (Rectangle<float> (timeToX (i+timeLag+1) - 0.75f, 0,
                                                                          3.0f, (float) getHeight()));
                    break;
                }
                case 2:
                {
                    segmentationBar[i]-> setFill (Colours::yellow.withAlpha (0.9f));
                    addAndMakeVisible (segmentationBar[i]);
                    segmentationBar[i]->setVisible(true);
                    segmentationBar[i]->setRectangle (Rectangle<float> (timeToX (i+timeLag+1) - 0.75f, 0,
                                                                        3.0f, (float) getHeight()));
                    break;
                }
                case 3:
                {
                    segmentationBar[i]-> setFill (Colours::blue.withAlpha (0.9f));
                    addAndMakeVisible (segmentationBar[i]);
                    segmentationBar[i]->setVisible(true);
                    segmentationBar[i]->setRectangle (Rectangle<float> (timeToX (i+timeLag+1) - 0.75f, 0,
                                                                        3.0f, (float) getHeight()));

                    break;
                }
                case 4:
                {
                    segmentationBar[i]-> setFill (Colours::green.withAlpha (0.9f));
                    addAndMakeVisible (segmentationBar[i]);
                    segmentationBar[i]->setVisible(true);
                    segmentationBar[i]->setRectangle (Rectangle<float> (timeToX (i+timeLag+1) - 0.75f, 0,
                                                                        3.0f, (float) getHeight()));
                    break;
                }
                default:
                {
                    break;
                }
            }
        }

    }
private:
    AudioTransportSource& transportSource;
    Slider& zoomSlider;
    AudioThumbnailCache thumbnailCache;
    AudioThumbnail thumbnail;
    
    OwnedArray<DrawableRectangle> segmentationBar;
    double startTime, endTime;
    
    DrawableRectangle currentPositionMarker;
    
    float timeToX (const double time) const
    {
        return getWidth() * (float) ((time - startTime) / (endTime - startTime));
    }
    
    double xToTime (const float x) const
    {
        return (x / getWidth()) * (endTime - startTime) + startTime;
    }
};

//[/MiscUserDefs]

//==============================================================================
AudioDemoPlaybackPage::AudioDemoPlaybackPage (AudioDeviceManager& deviceManager_, const File& audioFile, const vector<int>& result)
: deviceManager (deviceManager_), thread ("audio file preview"), directoryList (nullptr, thread)
{
    addAndMakeVisible (zoomLabel = new Label (String::empty,
                                              "zoom:"));
    zoomLabel->setFont (Font (15.00f, Font::plain));
    zoomLabel->setJustificationType (Justification::centredRight);
    zoomLabel->setEditable (false, false, false);
    zoomLabel->setColour (TextEditor::textColourId, Colours::black);
    zoomLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    
    addAndMakeVisible (explanation = new Label (String::empty,
                                                "red: Legato; yellow: Pizzicato; blue: Staccato; green: Tremolo"));
    explanation->setFont (Font (14.00f, Font::plain));
    explanation->setJustificationType (Justification::bottomRight);
    explanation->setEditable (false, false, false);
    explanation->setColour (TextEditor::textColourId, Colours::black);
    explanation->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    
    addAndMakeVisible (zoomSlider = new Slider (String::empty));
    zoomSlider->setRange (0, 1, 0);
    zoomSlider->setSliderStyle (Slider::LinearHorizontal);
    zoomSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    zoomSlider->addListener (this);
    zoomSlider->setSkewFactor (2);
    
    addAndMakeVisible (thumbnail = new DemoThumbnailComp (formatManager, transportSource, *zoomSlider));
    
    addAndMakeVisible (startStopButton = new TextButton (String::empty));
    startStopButton->setButtonText ("Play/Stop");
    startStopButton->addListener (this);
    startStopButton->setColour (TextButton::buttonColourId, Colour (0xff79ed7f));
    
    
    
    //[UserPreSize]
    //[/UserPreSize]
    
    setSize (600, 400);
    
    
    //[Constructor] You can add your own custom stuff here..
    formatManager.registerBasicFormats();
    
    directoryList.setDirectory (File::getSpecialLocation (File::userHomeDirectory), true, true);
    thread.startThread (3);
    

    
    deviceManager.addAudioCallback (&audioSourcePlayer);
    audioSourcePlayer.setSource (&transportSource);
    showFile(audioFile);
    thumbnail->drawSegment(result);
    
    //[/Constructor]
}

AudioDemoPlaybackPage::~AudioDemoPlaybackPage()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    transportSource.setSource (nullptr);
    audioSourcePlayer.setSource (nullptr);
    
    deviceManager.removeAudioCallback (&audioSourcePlayer);
    
    //[/Destructor_pre]
    
    zoomLabel = nullptr;
    explanation = nullptr;
    zoomSlider = nullptr;
    thumbnail = nullptr;
    startStopButton = nullptr;
   
    
    
    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void AudioDemoPlaybackPage::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]
    
    g.fillAll (Colours::lightgrey);
    
    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void AudioDemoPlaybackPage::resized()
{
    zoomLabel->setBounds (16, getHeight() - 90, 55, 24);
    
    explanation->setBounds (16, 8, getWidth() - 32, getHeight() - 245);//(256, getHeight() - 82, getWidth() - 275, 64);
    zoomSlider->setBounds (72, getHeight() - 90, 200, 24);
    thumbnail->setBounds (16, getHeight() - 221, getWidth() - 32, 123);
    startStopButton->setBounds (16, getHeight() - 46, 150, 32);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void AudioDemoPlaybackPage::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]
    
    if (sliderThatWasMoved == zoomSlider)
    {
        //[UserSliderCode_zoomSlider] -- add your slider handling code here..
        thumbnail->setZoomFactor (zoomSlider->getValue());
        //[/UserSliderCode_zoomSlider]
    }
    
    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void AudioDemoPlaybackPage::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]
    
    if (buttonThatWasClicked == startStopButton)
    {
        //[UserButtonCode_startStopButton] -- add your button handler code here..
        if (transportSource.isPlaying())
        {
            transportSource.stop();
        }
        else
        {
            transportSource.setPosition (0);
            transportSource.start();
        }
        //[/UserButtonCode_startStopButton]
    }
    
    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void AudioDemoPlaybackPage::showFile (const File& file)
{
    loadFileIntoTransport (file);
    
    zoomSlider->setValue (0, dontSendNotification);
    thumbnail->setFile (file);
}

void AudioDemoPlaybackPage::loadFileIntoTransport (const File& audioFile)
{
    // unload the previous file source and delete it..
    transportSource.stop();
    transportSource.setSource (nullptr);
    currentAudioFileSource = nullptr;
    
    AudioFormatReader* reader = formatManager.createReaderFor (audioFile);
    
    if (reader != nullptr)
    {
        currentAudioFileSource = new AudioFormatReaderSource (reader, true);
        
        // ..and plug it into our transport source
        transportSource.setSource (currentAudioFileSource,
                                   32768, // tells it to buffer this many samples ahead
                                   &thread, // this is the background thread to use for reading-ahead
                                   reader->sampleRate);
    }
}
