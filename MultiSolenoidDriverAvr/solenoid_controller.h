/*
*	Updates all solenoids to reflect the current state in the
*	Status class.
* 	By Paulo and Katie
*/

#ifndef SolenoidController_H
#define SolenoidController_H

#include "status.h"


class SolenoidController{
	public:
		/*
		*	Constructor
		*/
		SolenoidController(Status *status, int sol1, int sol2, int sol3, int sol4,
				int solEnbl, int solFault, int driverNum){
			
			// Dereference status class
			_status = status;

			// Save Pins
			_pins[0] = sol1;
			_pins[1] = sol2;
			_pins[2] = sol3;
			_pins[3] = sol4;
			_pinEnbl = solEnbl;
			_pinFault = solFault;

			// Save the driver number which is used in determining
			// Which information in the status class pertains to the
			// solenoids controlled by this class (object).
			_id = driverNum;

			// Initialize other variables
			_driverLastPulse = 0;
			_lastSolenoidState = 0;
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
			for (int i=0; i<4; i++){
				pinMode(_pins[i], OUTPUT);
			}
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
		byte _lastSolenoidState;
		// Array of Solenoid Pins
		int _pins[4];
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
			byte currentSolenoidState = _status->solenoidGroup[_id/2].get();
			if (_id % 2) {
				currentSolenoidState = currentSolenoidState >> 4;
			}

			// If any of the solenoids changed state
			if (_lastSolenoidState != currentSolenoidState){
				for (int i=0; i<4; i++){ // Go through each bit
					bool tempValue = _getBit(currentSolenoidState, i);
					if (tempValue - _getBit(_lastSolenoidState, i)){ 
						// Solenoid has been switched to ON!
						_driverLastPulse = millis();
					}
					digitalWrite(_pins[i], tempValue);
				}
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

		/*
		*	Returns a bit in the byte. Where the rightmost bit is 0
		*/
		bool _getBit(byte data, int bit){
			return data & (1 << bit);
		}

};

#endif