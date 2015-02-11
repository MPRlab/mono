// #include <avr/io.h>
// #include <avr/interrupt.h>
#include <iostream>
#include <iterator>
#include <cstring>
#include <cstdlib>

class PriorityNode {
        long time_till_off;
        PriorityNode * right_child;
        PriorityNode * left_child;
        int associated_notes[];
        int num_associated_notes;
    public:
        PriorityNode(long duration, int assoc_notes[], int num_notes);
        void AddNode(PriorityNode * toAdd);
        PriorityNode * RemoveNode(PriorityNode * toRemove);
        void UpdateNode(long time_elapsed);
        void PrintTree();
        PriorityNode * GetMinimum();
        int IsDone();
        int * GetNotes();
        int GetNumNotes();
};

PriorityNode::PriorityNode(long duration, int assoc_notes[], int num_notes) {
    time_till_off = duration;
    
    std::memcpy(associated_notes, assoc_notes, sizeof(int)*num_notes);
    num_associated_notes = num_notes;
};

void PriorityNode::UpdateNode(long time_elapsed) {
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
    if (toRemove == this) {
        if (right_child && left_child) {
            PriorityNode * parent = this;
            PriorityNode * minimum = left_child;
            while (minimum->left_child) {
                parent = minimum;
                minimum = parent->left_child;
            }
            this->time_till_off = minimum->time_till_off;
            parent->left_child = 0;
            delete minimum;
        }
        else if (right_child) {
            return right_child;
        }
        else if (left_child) {
            return left_child;
        }
        else {
            return 0;
        }
    }
    else {
        if (right_child) {
            right_child = right_child->RemoveNode(toRemove);
        }
        if (left_child) {
            left_child = left_child->RemoveNode(toRemove);
        }
        return this;
    }
}

void PriorityNode::PrintTree() {
    if (left_child) {
        left_child->PrintTree();
    }
    std::cout << "- " << time_till_off << std::endl;
    if (right_child) {
        right_child->PrintTree();
    }
}

PriorityNode * PriorityNode::GetMinimum() {
    PriorityNode * current = this;
    while (current->left_child) {
        current = current->left_child;
    }
    return current;
}

int PriorityNode::IsDone() {
    if (time_till_off < 0) {
        return 1;
    }
        
    else {
        return 0;
    }
}

int * PriorityNode::GetNotes() {
    return associated_notes;
}

int PriorityNode::GetNumNotes() {
    return num_associated_notes;
}

class Scheduler {
        PriorityNode * root;
    public:
        Scheduler(PriorityNode * start);
        void AddEvent(long duration, int notes[], int num_notes);
        PriorityNode * GetNext();
        void PrintSchedule();
        void UpdateSchedule(long time_step);
        void ProcessMessage(int message[]);
        void CheckNoteOffs();
};

Scheduler::Scheduler(PriorityNode * start) {
    root = start;
}

void Scheduler::AddEvent(long duration, int notes[], int num_notes) {
    PriorityNode * temp = new PriorityNode(duration, notes, num_notes);
    root->AddNode(temp);
}

void Scheduler::PrintSchedule() {
    std::cout << "Current Scheduled:" <<std::endl;
    root->PrintTree();
}

PriorityNode * Scheduler::GetNext() {
    PriorityNode * minimum = root->GetMinimum();
    if (minimum->IsDone()) {
        PriorityNode * toReturn = new PriorityNode(0, minimum->GetNotes(), minimum->GetNumNotes());
        root = root->RemoveNode(minimum);
        return toReturn;
    }
    else {
        return 0;
    }
}

void Scheduler::UpdateSchedule(long time_step) {
    root->UpdateNode(time_step);
}

void Scheduler::ProcessMessage(int message[]) {
    long time_stamp = ((long)message[1] << (sizeof(int)*8)) + message[2];
    int num_notes = message[2];
    int * notes = (int *) std::malloc(sizeof(int)*8);
    for (int i = 3; i < num_notes+3; i++) {
        notes[i-3] = message[i];
        //DigitalWrite(PinMapping[message[i]], HIGH);
    }
    this->AddEvent(time_stamp, notes, num_notes);
}

void Scheduler::CheckNoteOffs() {
    PriorityNode * next;
    while (next = this->GetNext()) {
        int * notes = next->GetNotes();
        for (int i = 0; i < next->GetNumNotes(); i++) {
            //DigitalWrite(PinMapping[notes[i]], LOW);
        }
    }
}

int main(int argc, char * argv[]) {
    int notes1 [] = {1, 2, 3};
    int notes2 [] = {4, 5};
    PriorityNode * root = new PriorityNode(10000, notes1, 3);
    Scheduler * scheduler = new Scheduler(root);
    scheduler->AddEvent(1000, notes1, 3);
    scheduler->AddEvent(1500, notes1, 3);
    scheduler->AddEvent(2000, notes1, 3);
    scheduler->AddEvent(2500, notes1, 3);
    scheduler->AddEvent(3000, notes1, 3);
    scheduler->AddEvent(2750, notes1, 3);
    scheduler->AddEvent(2250, notes1, 3);
    scheduler->AddEvent(1950, notes1, 3);
    scheduler->AddEvent(1450, notes1, 3);
    scheduler->AddEvent(950, notes1, 3);

    std::cout << "Before Update:" << std::endl;
    std::cout << "*******************************" << std::endl;
    scheduler->PrintSchedule();
    
    std::cout << std::endl;
    std::cout << "After Update:" << std::endl;
    std::cout << "*******************************" << std::endl;
    scheduler->UpdateSchedule(975);
    scheduler->PrintSchedule();

    std::cout << std::endl;
    std::cout << "After Checking for Note Offs: " << std::endl;
    std::cout << "*******************************" << std::endl;
    scheduler->CheckNoteOffs();
    scheduler->PrintSchedule();
}

