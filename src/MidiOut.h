//
//  MidiOut.h
//  Thinkplay Back-End
//


#include "JuceHeader.h"


//========================================================================================
/*
 MidiOut class for the Thinkplay application.
 
 Sends the raw midi that we recieve out a user-specified channel, so that the midi device can
 be routed to other applications after the thinkplay software.
 
 */
//========================================================================================


class MidiOut : public MidiOutput, public MidiMessage
{
public:
    MidiOut();
    ~MidiOut();
    
    /** Pointer for the midiOutput
     */
	ScopedPointer <MidiOutput> midiOutput;
    
    /** Function to send the midi out of the program to the specified channel
     
     Only works for note-on and note-off messages, not control (i.e. pitch bend, mod, etc)
     */
    void sendMidiOut(int channel, int noteNumber, int velocity);
    
private:
    
    //the message to send
    MidiMessage outMessage;
    
};

