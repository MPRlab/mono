//created by Scott Barton May 29-30 2013, modified 7/14/2015
//serial communications adapted from JHaskell's Blog post from May 6, 2011


#define DATABUFFERSIZE 4 //buffer size 
char dataBuffer[DATABUFFERSIZE+1]; //Add 1 for NULL terminator
char startChar = '!';
char endChar = '.';
byte tangentNum;
byte tangentVelocity;
byte prevTan;
byte checkSum;

void setup(){
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(115200);
}

void tangentOnOff (byte tangentNum, byte tangentVelocity) {
  if (tangentNum >= 0 && tangentNum < 16 && tangentVelocity > 0) {
    digitalWrite(tangentNum, HIGH);
  }
  if (tangentVelocity == 0) {
    digitalWrite(tangentNum, LOW);
  }
  if (tangentNum < 0 || tangentNum > 23) { //turn tangents and damper off
    for (int i = 0; i < 22; i++) {
    digitalWrite(tangentNum, LOW);
    }
  }
}
 
boolean getSerialString(){
  static byte dataBufferIndex = 0;
  static boolean storeString = false;
  while(Serial.available()>0){
    char incomingbyte = Serial.read();
    if(incomingbyte==startChar){
        dataBufferIndex = 0;  //Initialize our dataBufferIndex variable
        storeString = true;
    }
    if(storeString){
      //check to see if outside buffer size
      //We use our define here so our buffer size can be easily modified
      if(dataBufferIndex==DATABUFFERSIZE){
        //Oops, our index is pointing to an array element outside our buffer.
        dataBufferIndex = 0;
        break;
      }
      if(incomingbyte==endChar){
        //Our data string is complete.  return true
        dataBuffer[dataBufferIndex] = 0; //null terminate the C string
        storeString = false;
        dataBufferIndex = 0;
        return true;
      }
      else{
        dataBuffer[dataBufferIndex++] = incomingbyte;
        dataBuffer[dataBufferIndex] = 0; //null terminate the C string
      }
    }
  }
  //We've read in all the available Serial data, and don't have a valid string yet, so return false
  return false;
}

void loop() {
  if(getSerialString()){
    tangentNum = dataBuffer[1];
    tangentVelocity = dataBuffer[2];
    tangentOnOff(tangentNum, tangentVelocity);
  }
}
