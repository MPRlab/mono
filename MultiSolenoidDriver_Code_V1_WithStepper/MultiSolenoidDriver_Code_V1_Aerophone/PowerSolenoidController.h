/*
*	Updates the solenoid attached to the large driver
*	solenoids to reflect the current state in the Status class.
* 	By Paulo and Katie
*/

#ifndef PowerSolenoidController_H
#define PowerSolenoidController_H

#include "Status.h"

/*
*	APPLICATION NOTE
*	
*	ADD HERE
*/

class PowerSolenoidController{
	public:
		/*
		*	Constructor
		*/
		PowerSolenoidController(Status *status, int sol1, int solEnbl, int solFault){
			
			// Dereference status class
			_status = status;

			// Save Pins
			_pins = sol1;
			_pinEnbl = solEnbl;
			_pinFault = solFault;

			// Initialize other variables
			_driverLastPulse = 0;
			_lastSolenoidState = 0;

			// In the current verion of the board and PinDef file
			// the ID of the power solenoid driver is always 7
			_id =7;
		}

		/*
		*	Update Method.
		*	When run syncs the solenoids to the status class
		*	and holds solenoids that were pulsed.
		*/
		bool update(){
			// Actuate solenoids
			_sync();

			// Set PWMs
			_pulseAndHold();
		}

		/*
		*	Initializes all pins, etc for the class
		*/
		bool begin(){
			
			pinMode(_pins, OUTPUT);
			pinMode(_pinEnbl, OUTPUT);
			pinMode(_pinFault, INPUT_PULLUP);
			
			return true;
		}

	private:
		/* Declare Private Variables */
		// Variables below store the most recent time in which
		// a solenoid from the given driver has been set to high
		unsigned long _driverLastPulse;
		// Stores the last known state of the solenoids
		bool _lastSolenoidState;
		// Array of Solenoid Pins
		int _pins;
		int _pinEnbl;
		int _pinFault;
		// Id of the class
		int _id;
		// Status Class
		Status *_status;

		/*
		*	Syncs the solenoid state to the status class and marks
		*	each group where a solenoid has changed as a pulse instead
		*	of a hold. It then updates the solenoid last state variable.
		*/
		bool _sync(){
			// Get the information from status class that pertains to this
			// class
			bool currentSolenoidState = _status->powerSolenoid.get();

			// If any of the solenoids changed state
			if (_lastSolenoidState != currentSolenoidState){
				if (currentSolenoidState - _lastSolenoidState){ 
					// Solenoid has been switched to ON!
					_driverLastPulse = millis();
				}
				digitalWrite(_pins, currentSolenoidState);
				
				_lastSolenoidState = currentSolenoidState; // Update Class State
			}

			return true;
		}

		/*
		*	Sets the PWM for each solenoid driver based on the time
		*	variables.
		*/
		bool _pulseAndHold(){
			// If any of the solenoids has been turned recently
			// set PWM to pulse mode. Else, hold mode.
			if ((millis() - _driverLastPulse) < _status->driverPulseHoldTime[_id].get()){
				analogWrite(_pinEnbl, _status->pulsePWM[_id].get());
			} else {
				analogWrite(_pinEnbl, _status->holdPWM[_id].get());
			}

			return true;
		}

};

#endif