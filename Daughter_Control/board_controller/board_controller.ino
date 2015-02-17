/*
	Copyright Nathan Hughes 2015

    This file is part of code developed for the Music Perception and Robotics 
	Labrotory at Worcester Polytechnic Institute.

    This file is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This file is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    somewhere in this repository.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "PriorityNode.h"
#include "Scheduler.h"

PriorityNode::PriorityNode(long duration, int assoc_notes[], int num_notes) {
    time_till_off = duration;
    associated_notes = (int *) malloc(num_notes*sizeof(int));
    memcpy(associated_notes, assoc_notes, sizeof(int)*num_notes);
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

Scheduler::Scheduler(PriorityNode * start) {
    root = start;
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

const int pin_mappings[] = {41, 40, 37, 36, 35, 34, 33, 32, 31, 30, 15, 14, 29, 28, 27, 26, 25, 24, 23, 22, A15, A14, A13, A12, A11};
const int num_pins = 23;

const int pin_enables[] = {25, 24, 23, 18, 17, 16, 15};
const int driver_number = 7;

void Scheduler::AddEvent(long duration, int notes[], int num_notes) {
    PriorityNode * temp = new PriorityNode(duration, notes, num_notes);
    for (int i = 0; i < num_notes; i++) {
      digitalWrite(pin_mappings[notes[i]], HIGH); 
    }
    root->AddNode(temp);
}

void Scheduler::ProcessMessage(int message[]) {
    long time_stamp = ((long)message[1] << (sizeof(int)*8)) + message[2];
    int num_notes = message[2];
    int * notes = (int *) malloc(sizeof(int)*8);
    for (int i = 3; i < num_notes+3; i++) {
        notes[i-3] = message[i];
        //DigitalWrite(PinMapping[message[i]], HIGH);
    }
    this->AddEvent(time_stamp, notes, num_notes);
}

void Scheduler::CheckNoteOffs() {
    PriorityNode * next;
    while (next = this->GetNext()) {
        Serial.print("Removed Event:");
        int * notes = next->GetNotes();
        for (int i = 0; i < next->GetNumNotes(); i++) {
          Serial.print(notes[i], DEC);
          Serial.print(" ");
          digitalWrite(pin_mappings[notes[i]], LOW);
        }
        Serial.println("");
    }
}


Scheduler * scheduler;
long prev_time;
long add_time;
int notes1 [] = {1, 2, 3};
int notes2 [] = {4, 5};


void setup() {
  for (int i = 0; i < num_pins; i++) {
    pinMode(pin_mappings[i], OUTPUT);
  }
  for (int i = 0; i < num_pins; i++) {
    digitalWrite(pin_mappings[i], LOW);
  } 
  PriorityNode * root = new PriorityNode(10000, notes1, 3);
  scheduler = new Scheduler(root);
  prev_time = millis();
  add_time = millis();
  Serial.begin(115200);
}

byte flag = 0x01;

void loop() {
  if (millis() - prev_time > 100) {
    prev_time = millis();
    scheduler->UpdateSchedule(100);
    scheduler->CheckNoteOffs();
  }
  if (millis() - add_time > 2000) {
    add_time = millis();
    scheduler->AddEvent(1000, notes1, 3);
    Serial.println("Added Event!");
  }
  
}

