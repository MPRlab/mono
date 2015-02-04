int StepPin = 7;
int Dir = 8;
int StepDelay = 2000;

void setup() {
  pinMode(StepPin, OUTPUT);
  digitalWrite(StepPin, LOW);
  pinMode(Dir, OUTPUT);
  digitalWrite(Dir, LOW);
}

void loop() {
  for (int i = 0; i < 400; i++) {
    digitalWrite(StepPin, HIGH);
    delayMicroseconds(StepDelay);
    digitalWrite(StepPin, LOW);
    delayMicroseconds(StepDelay);
  }
  delay(500);
} 
