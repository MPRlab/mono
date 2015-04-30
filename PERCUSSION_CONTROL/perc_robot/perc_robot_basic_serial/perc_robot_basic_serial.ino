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

void drumOnOff(byte drumNum, byte drumVel) {
    if ((drumNum-MappingBase) >= 0 && (drumNum-MappingBase) <= 7  && (drumVel > 0)) {
      digitalWrite(drumMapping[drumNum], HIGH);
    }
    else{
      digitalWrite(drumMapping[drumNum], LOW);
    }
  }
  
void readSerial() {
  if(Serial.available() > 0){
    
    //grab our header byte
    byte inbyte = Serial.read();
    while(inbyte != 255){
        inbyte = Serial.read();
    }
    
    //we now hav a frame
    while(Serial.available() == 0);// <- wait for serial if our buffer is empty
    drumNum = Serial.read();
    
    //check if we have an error
    if (drumNum == 255) readSerial();
    
    //first message byte checked out
    else {
      //read the second message byte
      while(Serial.available() == 0);// <- wait for serial if our buffer is empty
      drumVel = Serial.read();
      
      //see if our second message byte is valid
      if (drumVel == 255) readSerial();
      
      //we don't have an error
      else drumOnOff(drumNum, drumVel);
    }
  }
}

void loop() {
  readSerial();
}
