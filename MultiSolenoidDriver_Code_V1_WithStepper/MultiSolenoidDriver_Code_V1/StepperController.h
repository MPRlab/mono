/*
*	Moves the stepper motor
* 	By Paulo and Katie
<<<<<<< HEAD
=======
*   Modified by Chris Bove
>>>>>>> origin/master
*/

#ifndef StepperController_H
#define StepperController_H

#include "Status.h"

#define FORWARD 1
#define REVERSE -1
<<<<<<< HEAD
// Number of milliseconds between two consecutive steps 
#define TIME_BETWEEN_STEPS 5
=======
// Number of microseconds between two consecutive steps 
#define TIME_BETWEEN_STEPS 1700
// Number of ms to wait before sleeping stepper after motion
#define TIME_UNTIL_SLEEP 2000
>>>>>>> origin/master

/*
*	APPLICATION NOTE
*	
*	This library deals with the control of a stepper motor.
*	It checks the status class for the stepsLeft attribute and
*	moves the stepper motor one step in the correct direction
*	on each call of the update method.
*/

class StepperController{
	public:
		/*
		*	Constructor
		*/
		StepperController(Status *status, int in1, int in2, int in3, int in4,
				int enbl1, int enbl2, int enbl3, int enbl4, int nsleep, int nrst){
			
			// Dereference status class
			_status = status;

			// Save Pins
			_in1 = in1;
			_in2 = in2;
			_in3 = in3;
			_in4 = in4;
			_enbl1 = enbl1;
			_enbl2 = enbl2;
			_enbl3 = enbl3;
			_enbl4 = enbl4;
			_nsleep = nsleep;
			_nrst = nrst;

			// Saves the current step index of the motor
			_currentStep = 0;
<<<<<<< HEAD
			_timeOfLastStep = millis();
=======
			_timeOfLastStep = micros();
      _timeOfLastMovement = millis();
      sleeping = true;
>>>>>>> origin/master
		}

		/*
		*	Update Method.
		*	When run determines if the stepper motor should move 
		*	and if so, moves it.
		*/
		bool update(){
<<<<<<< HEAD
			if ((_timeOfLastStep - millis()) > TIME_BETWEEN_STEPS) {
				// If there are steps left steps the motor once
				int stepsLeft = _status->stepperStepsLeft.get();

				if (stepsLeft > 0) {
					_step(FORWARD);
					_status->stepperStepsLeft.set(stepsLeft - 1);
				} else if (stepsLeft < 0) {
					_step(REVERSE);
					_status->stepperStepsLeft.set(stepsLeft + 1);
				} // else if stepsLeft is zero do nothing.
				
				// Save time of this step
				_timeOfLastStep = millis();
=======
      // need to check if micros counter has overflowed

      
      // check greater than to prevent overflow
			if (micros() >= _timeOfLastStep && (micros() - _timeOfLastStep) > TIME_BETWEEN_STEPS) {
				// If there are steps left steps the motor once
				int stepsLeft = _status->stepperStepsLeft.get();

        if (stepsLeft != 0) {
          // wake up the stepper driver
          if (wakeUp()) {
            _timeOfLastStep = micros() + 1000; // can cause overflow when subtracing at top of loop
            return true;
          }
          _timeOfLastMovement = millis();

          // depending on the direction...
          if (stepsLeft > 0) {
            _step(FORWARD);
            _status->stepperStepsLeft.set(stepsLeft - 1);
          }
          else if (stepsLeft < 0) {
            _step(REVERSE);
            _status->stepperStepsLeft.set(stepsLeft + 1);
          }
        }
        else if ((millis() - _timeOfLastMovement) > TIME_UNTIL_SLEEP) {
          // else if stepsLeft is zero and time has passed, sleep the stepper.
          goToSleep();
				}
       
				// Save time of this step
				_timeOfLastStep = micros();
>>>>>>> origin/master

				return true;
			}

			return false;
		}

		/*
		*	Initializes all pins, etc for the class
		*/
		bool begin(){
			// Set the pin directions
			pinMode(_in1, OUTPUT);
			pinMode(_in2, OUTPUT);
			pinMode(_in3, OUTPUT);
			pinMode(_in4, OUTPUT);

			pinMode(_enbl1, OUTPUT);
			pinMode(_enbl2, OUTPUT);
			pinMode(_enbl3, OUTPUT);
			pinMode(_enbl4, OUTPUT);

			pinMode(_nsleep, OUTPUT);
			pinMode(_nrst, OUTPUT);

			// Remove driver reset
			digitalWrite(_nsleep, HIGH);
			digitalWrite(_nrst, HIGH);

			// Turn ON the outputs
			// TODO: IF we attempt to do microstepping this will have to change
			digitalWrite(_enbl1, HIGH);
			digitalWrite(_enbl2, HIGH);
			digitalWrite(_enbl3, HIGH);
			digitalWrite(_enbl4, HIGH);

			
			return true;
		}

	private:
		/* Declare Private Variables */
		// Stepper driver pins
		int _in1;
		int _in2;
		int _in3;
		int _in4;
		int _enbl1;
		int _enbl2;
		int _enbl3;
		int _enbl4;
		int _nrst;
		int _nsleep;
		// Status Class
		Status *_status;
		// Keeps track of the current step index of the motor
		int _currentStep;
<<<<<<< HEAD
		unsigned long _timeOfLastStep;
=======
		unsigned long _timeOfLastStep, _timeOfLastMovement;
    bool sleeping;
>>>>>>> origin/master

		/*
		*	Steps the motor in the correct direction
		*/
		bool _step(int direction) {
			// Either increments of decrements the current step index
			_currentStep += direction;

			_setPhases();

			return true;
		}

		/*
		*	Sets the motor phases based on the current step index
		*	NOTE: Current configuration is for full stepping
		*/
		bool _setPhases() {
			// ERROR correction code. If current step is our of bounds correct it
			if (_currentStep > 3) {
				_currentStep = 0;
			} else if (_currentStep < 0) {
				_currentStep = 3;
			}

			// Sequence of steps for full stepping
			if (_currentStep == 0) {
				digitalWrite(_in1, HIGH);
				digitalWrite(_in2, LOW);
				digitalWrite(_in3, HIGH);
				digitalWrite(_in4, LOW);
			} else if (_currentStep == 1) {
				digitalWrite(_in1, LOW);
				digitalWrite(_in2, HIGH);
				digitalWrite(_in3, HIGH);
				digitalWrite(_in4, LOW);				
			} else if (_currentStep == 2) {
				digitalWrite(_in1, LOW);
				digitalWrite(_in2, HIGH);
				digitalWrite(_in3, LOW);
				digitalWrite(_in4, HIGH);				
			} else if (_currentStep == 3) {
				digitalWrite(_in1, HIGH);
				digitalWrite(_in2, LOW);
				digitalWrite(_in3, LOW);
				digitalWrite(_in4, HIGH);				
			}

			return true;
		}
<<<<<<< HEAD
=======

   bool wakeUp(){
     if(sleeping){
       digitalWrite(_nsleep, HIGH);
       sleeping = false;
       // it takes 1ms for the driver to wake up. return this flag if we were sleeping
       return true;
     }
     return false;
   }

   void goToSleep(){
      if (!sleeping) {
        sleeping = true;
        digitalWrite(_nsleep, LOW);
      }
   }
>>>>>>> origin/master
};

#endif






