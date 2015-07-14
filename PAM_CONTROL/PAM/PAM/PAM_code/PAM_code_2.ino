//created by Scott Barton May 29-30 2013

#include <Shifter.h>
#include <MIDI.h>
#include <StepperDriver.h>

#define SER_Pin 2 //SER_IN
#define RCLK_Pin 4 //L_CLOCK
#define SRCLK_Pin 3 //CLOCK
#define NUM_REGISTERS 3 //how many registers are in the chain

const int debugPin = 14;
const int openString = 70;
int tangentMapping[] = {0, 1, 2, 3, 4, 5, 6, 7, 15, 14, 13, 12, 11, 10, 9, 8, 16, 17, 18, 19, 20, 21, 22, 23};
int PAM_channel = 1; //MIDI channel for PAM
int PAM_picker = 17; //control change number to turn the picker on and off
int PAM_damper = 14; //control change number to turn the damper on and off
boolean PAM_picker_on = false;
const int stepsPerRevolution = 200; // change this to fit the number of steps per revolution for your motor
int stepperStatus = 1;

//initaize shifter using the Shifter library
Shifter shifter(SER_Pin, RCLK_Pin, SRCLK_Pin, NUM_REGISTERS); 
StepperDriver stepper; //initialize for one stepper


void setup(){
  pinMode(debugPin, OUTPUT);
  MIDI.begin(PAM_channel);
  MIDI.setHandleNoteOn(handle_NoteOn);
  MIDI.setHandleNoteOff(handle_NoteOff);
  MIDI.setHandleControlChange(handle_ControlChange); 
  stepper.setStep(stepsPerRevolution, 8, 7);
  stepper.setSpeed(190);
  stepper.step(50);
  shifter.clear(); //set all pins on the shift register chain to LOW
  shifter.write(); //send changes to the chain and display them
}

void handle_NoteOn (byte channel, byte note, byte velocity) {
  int tangentOn = note - openString;
  if (tangentOn >= 0 && tangentOn < 16 && velocity > 0) {
    shifter.setPin(tangentMapping[tangentOn], HIGH);
    shifter.write();
    if (PAM_picker_on == true) {
      stepperStatus = 1;  
    }
    else {
      stepperStatus = 0;
    }
  }
  if (tangentOn == 18) { //turn the picker on with a NoteOn message
    stepperStatus = 1;
  }
  if (tangentOn == 17 && velocity > 0) {  //turn the damper on with a NoteOn message
    shifter.setPin(17, HIGH);
    shifter.write();
  }
  if (velocity == 0) {
    shifter.setPin(tangentMapping[tangentOn], LOW);
    shifter.write();
  }
}

void handle_NoteOff (byte channel, byte note, byte velocity) {
  int tangentOff = note - openString;
  if (tangentOff >= 0 && tangentOff < 18) { 
  shifter.setPin(tangentMapping[tangentOff], LOW);
  shifter.write();
  }
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
  if (number == 110 && value == 0) {
    for (int i=0; i < 24; i++) {
      shifter.setPin(i, LOW);
      shifter.write();
    }
  }   
}
    

void loop() {
  MIDI.read();
  if (stepperStatus == 1 && stepper.update() == 1) {
    stepper.step(50);
    stepperStatus = 0;
  }
}
