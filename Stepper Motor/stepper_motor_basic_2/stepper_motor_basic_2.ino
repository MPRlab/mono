int StepPin = 7;
//int Dir = 8;
int stepsPerPick = 50;
int stepperDelay = 1000;
int openString = 73;

byte tangentNum;
byte tangentVelocity;

#define DATABUFFERSIZE 4 //buffer size 
char dataBuffer[DATABUFFERSIZE+1]; //Add 1 for NULL terminator
char startChar = '!';
char endChar = '.';

static char pickNum = 0;

void setup() {
  pinMode(StepPin, OUTPUT);
  digitalWrite(StepPin, LOW);
  Serial.begin(115200);
  //pinMode(Dir, OUTPUT);
  //digitalWrite(Dir, LOW);
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
        Serial.println("oops");
        dataBufferIndex = 0;
        break;
      }
      if(incomingbyte==endChar){
        //Our data string is complete.  return true
        Serial.println("go");
        dataBuffer[dataBufferIndex] = 0; //null terminate the C string
        storeString = false;
        dataBufferIndex = 0;
        return true;
      }
      else{
        dataBuffer[dataBufferIndex++] = incomingbyte;
        Serial.print(incomingbyte);
        dataBuffer[dataBufferIndex] = 0; //null terminate the C string
      }
    }
  }
  //We've read in all the available Serial data, and don't have a valid string yet, so return false
  return false;
}

void pick() {
  int i;
  for(i=0; i < stepsPerPick; i++ ){
    digitalWrite(StepPin, HIGH);
    delayMicroseconds(stepperDelay/2);
    digitalWrite(StepPin, LOW);
    delayMicroseconds(stepperDelay/2);
  }
}

void pickAdjust() {
  int i;
  for(i=0; i < 14; i++ ){
    digitalWrite(StepPin, HIGH);
    delayMicroseconds(stepperDelay/2);
    digitalWrite(StepPin, LOW);
    delayMicroseconds(stepperDelay/2);
  }
}

void tangentOnOff (byte tangentNum, byte tangentVelocity) {
  tangentNum -= openString;  
  if (tangentNum == 18 && tangentVelocity > 0) pick(); //picker on
  if (tangentNum == 19 && tangentVelocity > 0) pickAdjust(); //adjust picker
}

void loop() {
  if(getSerialString()){
    tangentNum = dataBuffer[1];
    tangentVelocity = dataBuffer[2];
    tangentOnOff(tangentNum, tangentVelocity);
  }
}    
  

 
