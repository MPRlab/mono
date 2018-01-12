//written by Scott Barton 7/22/15
// updated by Chris Bove 12/8/17

int StepPin = 2;
int Dir = 3;
int StepDelay = 1350;
byte rotation = 50;
 
void setup() {
    pinMode(StepPin, OUTPUT);
    digitalWrite(StepPin, LOW);
    digitalWrite(Dir, LOW);
    Serial.begin(115200);
    Serial.println("Setup Completed.");
}

void pick(byte rotation) {
   for(int i = 0; i < rotation; i++) {
    digitalWrite(StepPin, HIGH);
    delayMicroseconds(StepDelay/2);
    digitalWrite(StepPin, LOW);
    delayMicroseconds(StepDelay/2);
  }
}

void readSerial(){
  while(Serial.available()>0){
    if (Serial.available() > 1)
      Serial.println("More than 1 byte");
    rotation = Serial.read();
    pick(rotation);
    
  }
}

void constant_step(){
  // 500 steps/sec -> 2ms period
  digitalWrite(StepPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(StepPin, LOW);
  delayMicroseconds(1000);
}

void loop() {
  //readSerial();
  constant_step();
}

