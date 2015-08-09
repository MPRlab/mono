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
#include <avr/stdint.h>

struct Parser {
	Status * status;
};

typedef struct Parser Parser;


void init_parser(Parser * parser, Status * status);

uint32_t parse(Paser * parser, uint8_t * data, uint8_t length);

uint8_t construct_message(Parser * parser, uint8_t * data, uint8_t * length);

#endif