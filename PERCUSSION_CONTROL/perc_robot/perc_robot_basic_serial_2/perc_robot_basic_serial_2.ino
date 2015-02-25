/*
How does this work?

When a new note comes in:
First, a note command comes by (with multiple different notes to play), along with a value for how long to play it
All notes in the command get played (i.e. the solenoid triggers)
Then, the note command gets scheduled to shut down by the command being placed into the priority queue

Every time step:
update all previous priorities
peek at the initial priority.  While smallest priority has elapsed, pop event off, deal with it, return

*/



int MappingBase = 70;
int drumMapping[] = {54, 53, 52, 51, 58, 57, 56, 55};
byte drumNum;
byte drumVel;
 
class PriorityNode {
    byte * notes;
    long time_remaining;
    PriorityNode * left_child;
    PriorityNode * right_child;
  public:
    PriorityNode (long duration, int[] notes, int num_notes);
    void update_value(long delta);

};

PriorityNode::update_value(long delta) {
  time_remaining -= delta;
}

PriorityNode::PriorityNode(long duration, byte[] notes, int num_notes) {
  time_remaining = duration
  notes = (byte *) malloc(4*num_notes);
  //copy notes over to node
  left_child = 0;
  right_child = 0;
}


class Scheduler {
    PriorityNode root;
    PriorityNode min;
  public:
    void add_node(PriorityNode p);
    PriorityNode peek();
    PriorityNode pop();

};


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
