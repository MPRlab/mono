int MappingBase = 70; 
int drumMapping[] = {27, 25, 28, 29, 26, 24, 52, 53};
 
void setup() {
    for(int i = 0; i < 8; i++) {
     pinMode(drumMapping[i], OUTPUT);
     digitalWrite(drumMapping[i], LOW);
    } 
    Serial.begin(9600);
}

void drumOnOff(drumNum, drumVel) {
    if ((drumNum-Mapping Base) >= 0 && (drumNum-Mapping Base) <= 7  && (drumVel > 0)) {
      digitalWrite(drumMapping[drumNum], HIGH);
      else
      digitalWrite(drumMapping[drumNum], LOW);
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
    drumNum = mySerial.read();
    
    //check if we have an error
    if (drumNum == 255) readSerial();
    
    //first message byte checked out
    else {
      //read the second message byte
      while(mySerial.available() == 0);// <- wait for serial if our buffer is empty
      drumVel = mySerial.read();
      
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
