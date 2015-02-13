#include <Stepper.h>

Stepper stepper(400 , 7, 8);


void setup() {
  stepper.setSpeed(100);
}

void loop() {
  stepper.step(200);
  delay(1000);
}
