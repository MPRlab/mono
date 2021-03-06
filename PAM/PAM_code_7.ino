
//created by Scott Barton May 29-30 2013, modified 7/14/2015

#include <Shifter.h>
#include <SoftwareSerial.h>

#define SER_Pin 2 //SER_IN
#define RCLK_Pin 4 //L_CLOCK
#define SRCLK_Pin 3 //CLOCK
#define NUM_REGISTERS 3 //how many registers are in the chain

SoftwareSerial mySerial(6, 7);

const int debugPin = 14;
const int openString = 73;
int tangentMapping[] = {0, 1, 2, 3, 4, 5, 6, 7, 15, 14, 13, 12, 11, 10, 9, 8, 16, 17, 18, 19, 20, 21, 22, 23};

#define STEPS_PER_REV 400
#define NUMBER_PICKS 8
#define STEPPER_DELAY_US 1000

int stepperDelay = STEPPER_DELAY_US;
int stepsPerPick = STEPS_PER_REV/NUMBER_PICKS;

byte tangentNum;
byte tangentVelocity;
byte prevTan;
byte checkSum;

//initaize shifter using the Shifter library
Shifter shifter(SER_Pin, RCLK_Pin, SRCLK_Pin, NUM_REGISTERS); 

#define STEPPER_PIN MISO

void setup(){
  pinMode(debugPin, OUTPUT);
  shifter.clear(); //set all pins on the shift register chain to LOW
  shifter.write(); //send changes to the chain and display them
  
  pinMode(6, INPUT);
  pinMode(7, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(MISO, OUTPUT);
  mySerial.begin(115200);
}

void pick() {
  int i;
  for(i=0; i < stepsPerPick; i++ ){
    digitalWrite(MISO, HIGH);
    delayMicroseconds(stepperDelay/2);
    digitalWrite(MISO, LOW);
    delayMicroseconds(stepperDelay/2);
  }
}

void pickAdjust() {
  int j;
  for(j=0; j < 25; j++ ){
    digitalWrite(MISO, HIGH);
    delayMicroseconds(stepperDelay/2);
    digitalWrite(MISO, LOW);
    delayMicroseconds(stepperDelay/2);
  }
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
  if (tangentNum == 17 && tangentVelocity > 0) { //damper
    shifter.setPin(tangentMapping[tangentNum], HIGH);
    shifter.write();
  }
  if (tangentNum < 0 || tangentNum > 23) { //turn tangents and damper off
    for (int i = 0; i < 22; i++) {
      shifter.setPin(i, LOW);
      shifter.write();
    }
  }
  if (tangentNum == 18 && tangentVelocity > 0) pick(); //picker on
  if (tangentNum == 19 && tangentVelocity > 0) pick(); //adjust picker
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
  readSerial();
}

