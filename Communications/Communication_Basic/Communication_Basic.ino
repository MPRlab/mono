//created by Scott Barton May 29-30 2013, modified 7/14/2015


byte tangentNum;
byte tangentVelocity;
byte prevTan;
byte checkSum;


void setup(){
  Serial.begin(115200);
}


void readSerial() {
  if(Serial.available() > 0){
    
    //grab our header byte
    byte inbyte = Serial.read();
    Serial.print(inbyte);
    Serial.println();
    // if the header byte doesn't equal 255, read the next byte
    /*if(inbyte != 255) {
      inbyte = Serial.read();
      Serial.print(inbyte);
    }
    else {
      tangentNum = Serial.read(); //read the second byte
      Serial.print(tangentNum); 
      tangentVelocity = Serial.read(); //read the third byte
      Serial.print(tangentVelocity);
      checkSum = Serial.read(); //read the fourth byte
      Serial.print(checkSum);
      if (checkSum == (255 - tangentNum - tangentVelocity)) {
        Serial.write("note on");
      }
    }*/
  }
}

void loop() {
  readSerial();
}
