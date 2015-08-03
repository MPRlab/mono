/*
*	This class will deal with all aspects related to communicating
*	over serial. To work it requires the presence of the parser 
*	class.
*	C++ Version implemented by Paulo
*   AVR-libc Version implemented by Nathan
*/

#ifndef __COMM_H__
#define __COMM_H__

#include "status.h"
#include "parser.h"
#include <avr/stdint.h>

#define MAX_PACKET_LENGTH 250
#define START_DELIMITER 0xFD
#define BROADCAST_ID 0xFF
#define CHECKSUM_STARTING_VALUE 0xFF

struct Comm{
	HardwareSerial * serial;
	Status *         status;
	Parser *         parser;
	uint8_t          input_buffer[MAX_PACKET_LENGTH]; // Stores content of RX Message
	uint8_t          input_last_good_length; // Length of last good packet
	uint8_t          output_buffer[MAX_PACKET_LENGTH];
	uint8_t          board_id; // ID of the board for addressing
	uint8_t          start_byte_found; // Keeps track if a valid start delimiter has been found. Used to branch code in _readBuffer.
	uint8_t          length; // Length of the message currently in buffer
	uint8_t          id_is_valid; // Keeps track if current message is intended to current board
};

typedef struct Comm Comm;

void make_comm(Comm * comm, HardwareSerial * serial, Status * status, Parser * parser, uint8_t boardID);
uint8_t update(void);

long good_packet_count;
unsigned long time_last_good_packet;
uint8_t outputBufferMessageLength;

#endif 
//end __COMM_H__