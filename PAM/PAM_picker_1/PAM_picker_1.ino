//written by Scott Barton 7/22/15

int StepPin = 2;
int Dir = 3;
int StepDelay = 1350;
byte rotation = 50;
 
void setup() {
    pinMode(StepPin, OUTPUT);
    digitalWrite(StepPin, LOW);
    digitalWrite(Dir, LOW);
    Serial.begin(115200);
    
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
    rotation = Serial.read();
    pick(rotation);
  }
}

void loop() {
  readSerial();
}

