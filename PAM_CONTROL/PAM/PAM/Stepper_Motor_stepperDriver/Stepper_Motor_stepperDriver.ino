#include <StepperDriver.h>

const int stepsPerRevolution = 800; // change this to fit the number of steps per revolution for your motor
StepperDriver stepper1; //initialize for one stepper

void setup() {
  stepper1.setStep(stepsPerRevolution, 8, 7);
  stepper1.setSpeed(100);
}

void loop() {
// step one revolution in one direction:

  if (stepper1.update() == 1){ //here we check to see if the motor has finished the last step command and at the same time call the update for the motor to keep running
    delay(1000); //when a full revolution is complete, wait 1second and do another full rev.
    stepper1.step(800);
  }
}

