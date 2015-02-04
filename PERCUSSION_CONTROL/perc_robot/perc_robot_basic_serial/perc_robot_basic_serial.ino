int MappingBase = 70; 
int drumMapping[] = {27, 25, 28, 29, 26, 24, 52, 53};
 
void setup() {
    for(int i = 0; i < 8; i++) {
     pinMode(drumMapping[i], OUTPUT);
     digitalWrite(drumMapping[i], LOW);
    } 
    Serial.begin(9600);
}

void drumGo() {
  if (Serial.available() > 0) {
    int inByte = Serial.read();
    int paNum = (inByte - MappingBase);
    if (paNum >= 0 && paNum <= 7) {
      digitalWrite(drumMapping[paNum], HIGH);
      delay(47);
      digitalWrite(drumMapping[paNum], LOW);
    }
  }
}

void loop() { 
  drumGo();
}
