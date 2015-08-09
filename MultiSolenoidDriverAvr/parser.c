#include "parser.h"

void init_parser(Parser * parser, Status * status) {
	parser->status = status;
}

uint32_t parse(Paser * parser, uint8_t * data, uint8_t length){
	uint8_t i=0; // Iterator variable
	while (i < length) {
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
				set_solenoid_group_status(paser->status, 0, data[i++]);
				set_solenoid_group_status(paser->status, 1, data[i++]);
				set_solenoid_group_status(paser->status, 2, data[i++]);
				break;

			case SET_POWER_SOLENOID_ON: // Turns ON DRVS Sol
				set_power_solenoid(parser->status, 0x01);
				break;

			case SET_POWER_SOLENOID_OFF: // Turns OFF DRVS Sol
				set_power_solenoid(parser->status, 0x00);
				break;

			/* 
			*	In case the header is not found
			*/
			default: // Header has failed Message Break
				increment_comm_header_fail(parser->status);
				return 0x00;
			
		}
	}

	return 0x01;
}

/******************************************************/
/********************* TRANSMITER *********************/
/******************************************************/

/*
*	Checks all the requests and tags and adds the 
*	related headers and content to the passed array
*/
uint8_t construct_message(Parser * parser, uint8_t * data, uint8_t * length){
	uint8_t i = 0;

	/*************** TAG RELATED ****************/
	/* 	
	*	Tags are used to send data 
	*/

	// ADD MESSAGES FOR SENDING HERE!!!

	*length = i; // Return length of message

	return 0x01;
}
