

//created by Scott Barton May 29-30 2013

#include <Shifter.h>
#include <MIDI.h>
#include <SoftwareSerial.h>

#define SER_Pin 2 //SER_IN
#define RCLK_Pin 4 //L_CLOCK
#define SRCLK_Pin 3 //CLOCK
#define NUM_REGISTERS 3 //how many registers are in the chain

SoftwareSerial mySerial(6, 7);

const int debugPin = 14;
const int openString = 73;
int tangentMapping[] = {0, 1, 2, 3, 4, 5, 6, 7, 15, 14, 13, 12, 11, 10, 9, 8, 16, 17, 18, 19, 20, 21, 22, 23};
int PAM_channel = 1; //MIDI channel for PAM
int PAM_picker = 100; //control change number to turn the picker on and off
int PAM_damper = 101; //control change number to turn the damper on and off

#define STEPRS_PER_REV 400
#define NUMBER_PICKS 8
#define STEPPER_DELAY_US 1000

int stepperDelay = STEPPER_DELAY_US;

byte tangentNum;
byte tangentVelocity;
byte prevTan;

//initaize shifter using the Shifter library
Shifter shifter(SER_Pin, RCLK_Pin, SRCLK_Pin, NUM_REGISTERS); 

#define STEPPER_PIN MISO

void pick() {
  int i;
  for(i=0; i < STEPRS_PER_REV/NUMBER_PICKS; i++ ){
    digitalWrite(MISO, HIGH);
    delayMicroseconds(stepperDelay/2);
    digitalWrite(MISO, LOW);
    delayMicroseconds(stepperDelay/2);
  }
}

void setup(){
  pinMode(debugPin, OUTPUT);
  MIDI.begin(PAM_channel);
  MIDI.setHandleNoteOn(handle_NoteOn);
  MIDI.setHandleNoteOff(handle_NoteOff);
  MIDI.setHandleControlChange(handle_ControlChange); 
  shifter.clear(); //set all pins on the shift register chain to LOW
  shifter.write(); //send changes to the chain and display them
  
  pinMode(6, INPUT);
  pinMode(7, OUTPUT);
  mySerial.begin(57600);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(MISO, OUTPUT);
}

void tangentOnOff (byte tangentNum, byte tangentVelocity) {
  tangentNum -= openString;
  if (tangentNum >= 0 && tangentNum < 16 && tangentVelocity > 0) {
    shifter.setPin(tangentMapping[prevTan], LOW);
    shifter.write();
    shifter.setPin(tangentMapping[tangentNum], HIGH);
    shifter.write();
    prevTan = tangentNum;
  }
  if (tangentVelocity == 0) {
    shifter.setPin(tangentMapping[tangentNum], LOW);
    shifter.write();
  }
  if (tangentNum == 17 && tangentVelocity > 0) {
    shifter.setPin(tangentMapping[tangentNum], HIGH);
    shifter.write();
  }
  if (tangentNum < 0 || tangentNum > 23) {
    for (int i = 0; i < 22; i++) {
      shifter.setPin(i, LOW);
      shifter.write();
    }
  }
  if (tangentNum == 18) pick();
}


void handle_NoteOn (byte channel, byte note, byte velocity) {
  int tangentOn = note - openString;
  
  //pick for note below open strint
  if (tangentOn == 18) pick();
  
  if (tangentOn >= 0 && tangentOn < 16 && velocity > 0) {
    shifter.setPin(tangentMapping[tangentOn], HIGH);
    shifter.write();
    /*if (PAM_picker_on == true) {
      stepperStatus = 1;  
    }
    else {
      stepperStatus = 0;
    }*/
  }
  //if (tangentOn == 18) { //turn the picker on with a NoteOn message
    //stepperStatus = 1;
  //}
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

void readSerial() {
  if(mySerial.available() > 0){
    
    //grab our header byte
    byte inbyte = mySerial.read();
    while(inbyte != 255){
        inbyte = mySerial.read();
    }
    
    //we now hav a frame
    while(mySerial.available() == 0);// <- wait for serial if our buffer is empty
    tangentNum = mySerial.read();
    
    //check if we have an error
    if (tangentNum == 255) readSerial();
    
    //first message byte checked out
    else {
      //read the second message byte
      while(mySerial.available() == 0);// <- wait for serial if our buffer is empty
      tangentVelocity = mySerial.read();
      
      //see if our second message byte is valid
      if (tangentVelocity == 255) readSerial();
      
      //we don't have an error
      else tangentOnOff(tangentNum, tangentVelocity);
    }
  }
}

void loop() {
  //MIDI.read();
  readSerial();
}
