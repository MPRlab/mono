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

#ifndef SCHEDULER_H
#define SCHEDULER_H

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



#endif
