int StepPin = 7;
//int Dir = 8;
int stepsPerPick = 50;
int stepperDelay = 450;
int openString = 73;

byte tangentNum;
byte tangentVelocity;
byte checkSum;

void setup() {
  pinMode(StepPin, OUTPUT);
  digitalWrite(StepPin, LOW);
  Serial.begin(115200);
  //pinMode(Dir, OUTPUT);
  //digitalWrite(Dir, LOW);
}

void readSerial() {
  if(Serial.available() > 0){
    
    //grab our header byte
    byte inbyte = Serial.read();
    Serial.print(inbyte);
    Serial.print(" ");
    // if the header byte doesn't equal 255, read the next byte
    if(inbyte != 255) {
      inbyte = Serial.read();
    }
    else {
      tangentNum = Serial.read(); //read the second byte
      Serial.print(tangentNum);
      Serial.print(" "); 
      tangentVelocity = Serial.read(); //read the third byte
      Serial.print(tangentVelocity);
      Serial.print(" ");
      checkSum = Serial.read(); //read the fourth byte
      Serial.print(checkSum);
      Serial.print(" ");
      Serial.println();
      if (checkSum == (255 - tangentNum - tangentVelocity)) {
        tangentOnOff(tangentNum, tangentVelocity);
      }
      else {
        Serial.print("noCheck");
        Serial.print(" ");
        Serial.println();
      }
    }
  }
}

void pick() {
  int i;
  for(i=0; i < stepsPerPick; i++ ){
    digitalWrite(StepPin, HIGH);
    delayMicroseconds(stepperDelay);
    digitalWrite(StepPin, LOW);
    delayMicroseconds(stepperDelay);
  }
}

void pickAdjust() {
  int j;
  for(j=0; j < 14; j++ ){
    digitalWrite(StepPin, HIGH);
    delayMicroseconds(stepperDelay);
    digitalWrite(StepPin, LOW);
    delayMicroseconds(stepperDelay);
  }
}

void tangentOnOff (byte tangentNum, byte tangentVelocity) {
  tangentNum -= openString;  
  if (tangentNum == 18 && tangentVelocity > 0) pick(); //picker on
  if (tangentNum == 19 && tangentVelocity > 0) pickAdjust(); //adjust picker
}

void loop() {
readSerial();
}    
  

 
