/*
*	
*	Adapted from SolenoidController by Paulo and Katie
*	By Andrew
*/

#ifndef AerophoneController_H
#define AerophoneController_H

#include "Status.h"

/*
*	APPLICATION NOTE
*	
*	ADD HERE
*/

class AerophoneController{
	public:
		/*
		*	Constructor
		*/
		AerophoneController(Status *status, int solClk, int solRst,
				int solEnbl, int solSignal, int driverNum){
			
			// Dereference status class
			_status = status;

			// Save Pins
			_pinClk = solClk;
			_pinRst = solRst;
			_pinEnbl = solEnbl;
			_pinSignal = solSignal;

			// Save the driver number which is used in determining
			// Which information in the status class pertains to the
			// solenoids controlled by this class (object).
			_id = driverNum;

			// Initialize other variables
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
      
      return true;
		}

		/*
		*	Initializes all pins, etc for the class
		*/
		bool begin(){
			pinMode(_pinClk, OUTPUT);
			pinMode(_pinRst, OUTPUT);
			pinMode(_pinEnbl, OUTPUT);
			pinMode(_pinSignal, OUTPUT);
			
			clear_shiftregister();	
			return true;
		}

	private:
		/* Declare Private Variables */
		// Stores the last known state of the solenoids
		word _lastSolenoidState;
		// Array of Solenoid Pins
		int _pinClk;
		int _pinRst;
		int _pinEnbl;
		int _pinSignal;
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
			word lower8 = (word) _status->solenoidGroup[_id*2].get();
			word upper5 = (word) (_status->solenoidGroup[_id*2+1].get() & 0x1F);
			word currentSolenoidState = lower8 | (upper5 << 8);

			// If any of the solenoids changed state
			if (_lastSolenoidState != currentSolenoidState){
				set_shiftregister(currentSolenoidState);	
				_lastSolenoidState = currentSolenoidState; // Update Class State
			}

			return true;
		}

		void clear_shiftregister(){
			digitalWrite(_pinEnbl, HIGH);
			digitalWrite(_pinEnbl, LOW);
		}

		void set_shiftregister(word b){
			//word i = 0x800;
			word i = 0x1000;

			while(i){
				if(b & i) digitalWrite(_pinSignal, HIGH);
				else digitalWrite(_pinSignal, LOW);
				digitalWrite(_pinClk, HIGH);
				i >>= 1;
				digitalWrite(_pinClk, LOW);
			}
			
			digitalWrite(_pinEnbl, HIGH);
			digitalWrite(_pinEnbl, LOW);
			digitalWrite(_pinRst, LOW);
			digitalWrite(_pinRst, HIGH);
		}

		/*
		*	Returns a bit in the word. Where the rightmost bit is 0
		*/
		bool _getBitWord(word data, int bit){
			return data & (1 << bit);
		}

};

#endif






