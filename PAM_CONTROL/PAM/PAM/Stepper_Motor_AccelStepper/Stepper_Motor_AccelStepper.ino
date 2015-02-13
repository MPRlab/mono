// ConstantSpeed.pde
// -*- mode: C++ -*-
//
// Shows how to run AccelStepper in the simplest,
// fixed speed mode with no accelerations
/// \author  Mike McCauley (mikem@airspayce.com)
// Copyright (C) 2009 Mike McCauley
// $Id: ConstantSpeed.pde,v 1.1 2011/01/05 01:51:01 mikem Exp mikem $

#include <AccelStepper.h>

AccelStepper stepper1(1, 7, 8); // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5

void setup()
{  
   stepper1.setMaxSpeed(30000);
   stepper1.setSpeed(30000);	
}

void loop()
{  
   stepper1.runSpeed();
     //stepper1.moveTo(100);
    // stepper1.setSpeed(5000);
    // stepper1.runSpeedToPosition();
}
