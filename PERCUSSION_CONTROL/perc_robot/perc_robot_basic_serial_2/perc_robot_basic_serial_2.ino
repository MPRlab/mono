int MappingBase = 70; 
int drumMapping[] = {27, 25, 28, 29, 26, 24, 52, 53};
byte drumNum;
byte drumVel;
 
void setup() {
    for(int i = 0; i < 8; i++) {
     pinMode(drumMapping[i], OUTPUT);
     digitalWrite(drumMapping[i], LOW);
    } 
    Serial.begin(57600);
}


void drumGo(byte drumNum, byte drumVel) {
    drumNum = (drumNum - MappingBase);
    if (drumVel > 0) {
      digitalWrite(drumMapping[drumNum], HIGH);
    }
    else {
      digitalWrite(drumMapping[drumNum], LOW);
    }
}


void readSerial() {
    if (Serial.available() > 0) { 
      byte drumNum = Serial.read();
      while(Serial.available() == 0);  //wait for serial if buffer is empty
      byte drumVel = Serial.read();
      drumGo(drumNum, drumVel);
    }
}

void loop() { 
  readSerial();
}
