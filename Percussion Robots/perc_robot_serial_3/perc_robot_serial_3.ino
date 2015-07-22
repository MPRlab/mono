//written by Scott Barton 7/22/15

int MappingBase = 70; 
int drumMapping[] = {27, 25, 28, 29, 26, 24, 52, 53};
byte drumNum;
byte drumVel;

#define DATABUFFERSIZE 4 //buffer size 
char dataBuffer[DATABUFFERSIZE+1]; //Add 1 for NULL terminator
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
    if ((drumNum>= 0) && (drumNum<=7)  && (drumVel > 0)) {
      digitalWrite(drumMapping[drumNum], HIGH);
    }
    else{
      digitalWrite(drumMapping[drumNum], LOW);
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
    drumNum = dataBuffer[1];
    drumVel = dataBuffer[2];
    drumOnOff(drumNum, drumVel);
  }
}
