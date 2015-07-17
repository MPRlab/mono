//created by Scott Barton May 29-30 2013

#include <Shifter.h>
#include <MIDI.h>

const int debugPin = 14;
const int openString = 70;
int tangentMapping[] = {0, 1, 2, 3, 4, 5, 6, 7, 15, 14, 13, 12, 11, 10, 9, 8, 16, 17, 18, 19, 20, 21, 22, 23};
int PAM_channel = 1; //MIDI channel for PAM
int PAM_picker = 34; //control change number to turn the picker on and off
int PAM_damper = 14; //control change number to turn the damper on and off
boolean PAM_picker_on = false;

#define SER_Pin 2 //SER_IN
#define RCLK_Pin 4 //L_CLOCK
#define SRCLK_Pin 3 //CLOCK

#define NUM_REGISTERS 3 //how many registers are in the chain


//initaize shifter using the Shifter library
Shifter shifter(SER_Pin, RCLK_Pin, SRCLK_Pin, NUM_REGISTERS); 

void setup(){
  
  pinMode(debugPin, OUTPUT);
  MIDI.begin(PAM_channel);
  MIDI.setHandleNoteOn(handle_NoteOn);
  MIDI.setHandleNoteOff(handle_NoteOff);
  MIDI.setHandleControlChange(handle_ControlChange); 
  shifter.clear(); //set all pins on the shift register chain to LOW
  shifter.write(); //send changes to the chain and display them
  
}

void handle_NoteOn (byte channel, byte note, byte velocity) {
  int tangentOn = note - openString;
  if (tangentOn >= 0 && tangentOn < 16) {
    shifter.setPin(tangentMapping[tangentOn], HIGH);
    shifter.write();
    if (PAM_picker_on == true) {
      shifter.setPin(16, HIGH);
      shifter.write();
      delayMicroseconds(500);
      shifter.setPin(16, LOW);
      shifter.write();
    }
    else {
      shifter.setPin(16, LOW);
      shifter.write();
    }
  }
  else {
    for (int i=0; i < 24; i++) {
      shifter.setPin(i, LOW);
      shifter.write();
    }
  }
}

void handle_NoteOff (byte channel, byte note, byte velocity) {
  int tangentOff = note - openString;
  shifter.setPin(tangentMapping[tangentOff], LOW);
  shifter.write();
}
  
void handle_ControlChange (byte channel, byte number, byte value) {
  if (number == PAM_picker && value == 127) {
    PAM_picker_on = true;
  }
  if (number == PAM_picker && value == 0) {
    PAM_picker_on = false;
  }
  if (number == PAM_damper && value == 127) {
    shifter.setPin(17, HIGH);
    shifter.write();
  }
  if (number = PAM_damper && value == 0) {
    shifter.setPin(17, LOW);
    shifter.write();
  }  
}
    

void loop() {
  MIDI.read();
}
