#include <avr/io.h>
#include <avr/interrupt.h>

class PriorityNode {
        long time_till_off;
        PriorityNode * right_child;
        PriorityNode * left_child;
        byte associated_notes[];
        int num_associated_notes;
    public:
        PriorityNode(long duration, byte * assoc_notes, int num_notes);
        void AddNode(PriorityNode * toAdd);
        PriorityNode * RemoveNode(PriorityNode * toRemove);
        void UpdateNode(long time_elapsed);
};

PriorityNode::PriorityNode(long duration, byte assoc_notes[], int num_notes) {
    time_till_off = duration;
    std::copy(std::begin(src), std::end(src), std::begin(dest));
    num_associated_notes = num_notes;
};

PriorityNode::UpdateNode(long time_elapsed) {
    time_till_off -= time_elapsed;
    if (right_child) {
        right_child->UpdateNode(time_elapsed);
    }
    if (left_child) {
        left_child->UpdateNode(time_elapsed);
    }
}

void PriorityNode::AddNode(PriorityNode * toAdd) {
    if (toAdd->time_till_off < time_till_off) {
        if (left_child) {
            left_child->AddNode(toAdd);
        }
        else {
            left_child = toAdd;
        }
    }
    if (toAdd->time_till_off >= time_till_off) {
        if (right_child) {
            right_child->AddNode(toAdd);
        }
        else {
            right_child = toAdd;
        }
    }
}

PriorityNode * PriorityNode::RemoveNode(PriorityNode *toRemove) {
    if (*toRemove == this) {
        if (right_child && left_child) {
            parent = this;
            minimum = left_child;
            while (minimum->left_child) {
                parent = minimum;
                minimum = parent->left_child;
            }
            this->time_till_off = minimum->time_till_off;
            parent->left_child = Null;
            delete minimum;
        }
        else if (right_child) {
            return right_child;
        }
        else if (left_child) {
            return left_child;
        }
        else {
            return Null;
        }
    }
    else {
        if (right_child) {
            right_child = right_child->RemoveNode(toRemove);
        }
        if (left_child) {
            left_child = left_child->RemoveNode(toRemove);
        }
    }
}

void setup()
{
    for(int i = 0; i < 8; i++) {
     pinMode(drumMapping[i], OUTPUT);
     digitalWrite(drumMapping[i], LOW);
    } 

    // initialize Timer1
    cli();          // disable global interrupts
    TCCR1A = 0;     // set entire TCCR1A register to 0
    TCCR1B = 0;     // same for TCCR1B
    TCNT1 = 0; //initialize counter value to 0 
    // set compare match register to desired timer count:
    OCR1A = onTimeMin; //(stepTime * 10^-6)/6.25e-8;
    // turn on CTC mode:
    TCCR1B |= (1 << WGM12);
    TCCR1B |= (1 << CS10);
    TCCR1B |= (1 << CS12); // Set CS10 and CS12 bits for 1024 prescaler
    //TCCR1B |= (1 << CS11);
    // enable timer compare interrupt:
    TIMSK1 |= (1 << OCIE1A);
    // enable global interrupts:
    sei();
    

}

 
void handle_NoteOn () {
  if (drumOn >= 0 && drumOn < 8  && velocity > 0) {
    int timerStart = TCNT1;
    OCR1A = (((((int)velocity  * (700-onTimeMin)) / 127) + onTimeMin) + timerStart);
    armGo = 1;  
    digitalWrite(drumMapping[drumOn], HIGH);
  }
}


void loop() 
{

}

int main(int argc, char * argv[]) {
    setup();
    loop();
    handle_NoteOn();
}

