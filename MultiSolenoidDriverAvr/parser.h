/*
*	This library parses or creates a message based on the 
*	Musical Robotics Protocol V1. Interacts with 
*	a compatible status class.
*	By Paulo
*   Modified by Nathan for AVR-libc
*/

#ifndef __PARSER_H__
#define __PARSER_H__

#include "status.h"
#include "packet_headers.h"

struct Parser {
	Status * status;
};

typedef struct Parser Parser;

#endif