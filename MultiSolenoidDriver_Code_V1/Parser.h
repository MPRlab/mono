/*
*	This library parses or creates a message based on the 
*	Musical Robotics Protocol V1. Interacts with 
*	a compatible status class.
*	By Paulo
*/

#ifndef Parser_H
#define Parser_H

#include "Status.h"
#include "PacketHeaders.h"

class Parser{
	public:
		/*
		*	Constructor
		*/
		Parser(Status *status, int id){
			// Dereference status class
			_status = status;

			_id = id;
		}

		/******************************************************/
		/********************** RECEIVER **********************/
		/******************************************************/

		/*
		*	This method parses a given message and update all
		*	pertinent fields in the status class
		*/
		bool parse(byte *data, int length){
			int i=0; // Iterator variable
			while (i<length){
				switch (data[i++]){
					/************* REQUEST RELATED **************/
					/* 	
					*	Requests are send by devices to request
					*	that the 2560 return the associated info
					*/
					
					// MESSAGES FOR REQUESTING GO HERE!!!

					
					/************* SET RELATED **************/
					/* 	
					*	Sets a given attribute. 
					*/
					
					case SET_ALL_SOLENOIDS: // Sets all solenoids
						_status->solenoidGroup[0].set(data[i++]);
						_status->solenoidGroup[1].set(data[i++]);
						_status->solenoidGroup[2].set(data[i++]);
						break;

					case SET_POWER_SOLENOID_ON: // Turns ON DRVS Sol
						_status->powerSolenoid.set(true);
						break;

					case SET_POWER_SOLENOID_OFF: // Turns OFF DRVS Sol
						_status->powerSolenoid.set(false);
						break;

					/* 
					*	In case the header is not found
					*/
					default: // Header has failed Message Break
						_status->commNumHeaderFail.increment(_id);
						return false;
					
				}
			}

			return true;
		}

		/******************************************************/
		/********************* TRANSMITER *********************/
		/******************************************************/

		/*
		*	Checks all the requests and tags and adds the 
		*	related headers and content to the passed array
		*/
		bool construct(byte *data, int *length){
			int i = 0;

			/*************** TAG RELATED ****************/
			/* 	
			*	Tags are used to send data 
			*/

			// ADD MESSAGES FOR SENDING HERE!!!

			*length = i; // Return length of message

			return true;
		}

	private:
		/****** Declare Variables, Pointers, Objects ******/
		Status *_status;
		int _id; // ID of the Comm class that calls this parser	
};


#endif