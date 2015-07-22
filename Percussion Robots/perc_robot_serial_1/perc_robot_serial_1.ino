//written by Scott Barton 7/22/15

int MappingBase = 70; 
int drumMapping[] = {27, 25, 28, 29, 26, 24, 52, 53};
byte drumNum;
byte drumVel;
byte stopByte;

char startChar = '!';
char endChar = '.';
 
void setup() {
    for(int i = 0; i < 8; i++) {
     pinMode(drumMapping[i], OUTPUT);
     digitalWrite(drumMapping[i], LOW);
    } 
    Serial.begin(115200);
}

void drumOnOff(byte drumNum, byte drumVel) {
    drumNum = drumNum - MappingBase;
    if ((drumNum>=0) && (drumNum<=7) && (drumVel > 0)) {
      digitalWrite(drumMapping[drumNum], HIGH);
    }
    else{
      digitalWrite(drumMapping[drumNum], LOW);
    }
  }
  

void readSerial(){
  while(Serial.available()>0){
    //byte incomingByte = Serial.read();
    //if(incomingByte==startChar){
      drumNum = Serial.read();
      drumVel = Serial.read();
      //stopByte = Serial.read();
    //}
    //if(stopByte==endChar) {
      drumOnOff(drumNum, drumVel);
    //}
  }
}

void loop() {
  readSerial();   
}
