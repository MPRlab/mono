/*
*	This class will deal with all aspects related to communicating
*	over serial. To work it requires the presence of the parser 
*	class.
*	By Paulo.
*/

#ifndef Comm_H
#define Comm_H

#include <Arduino.h>
#include "Status.h"
#include "Parser.h"

#define MAX_PACKET_LENGTH 250
#define START_DELIMITER 0xFD
#define BROADCAST_ID 0xFF

class Comm{
	public:
		/*
		*	Constructor
		*/
		Comm(HardwareSerial *serial, Status *status, int id, int boardID) :
			_parser(status, id){
			// Initialize Serial
			_serial = serial;

			// Dereference pointer to status class
			_status = status;

			// Identifier of the class
			_id = id;

			// Used for keeping track of packet reading
			_length = 0;
			_startByteFound = false;
			_idIsValid = false;

			// ID of the boad for addressing
			_boardID = boardID;
		}

		/*
		*	Should be called as often as possible.
		*	Makes all function calls to send and receive the 
		*	necessary data. 
		*/
		bool update(){
			// If serial is available the function reads the input
			// buffer, checks for start delimiter, etc
			if(_readBuffer()){
				if(_parser.parse(_inputBuffer, _inputLastGoodLength)){
					// If parsing was successful add a packet to the count
					// of good packets which is used in calculating rate
					static long goodPacketCount;
					static unsigned long timeLastGoodPacket;
					goodPacketCount++;
					if ((millis()-timeLastGoodPacket) > 1000){
						_status->commPacketPerSecond.set(
							goodPacketCount, _id);
						goodPacketCount = 0;
						timeLastGoodPacket = millis();
					}

					// Tag Acknowledge so that an ACK is sent back to sender
					_status->commAck.tag(true, _id);

				}
			}

			// Create outgoing message
			int outputBufferMessageLength = 0;
			_parser.construct(_outputBuffer, &outputBufferMessageLength);

			// If contents are available, encapsulates buffer and 
			// sends over UART.
			_sendBuffer(outputBufferMessageLength);

			return true;

		
		}

	private:
		/****** Declare Variables, Pointers, Objects ******/
		HardwareSerial *_serial;
		Status *_status;
		Parser _parser;
		byte _inputBuffer[MAX_PACKET_LENGTH]; // Stores content of RX Message
		int _inputLastGoodLength; // Length of last good packet
		byte _outputBuffer[MAX_PACKET_LENGTH];
		int _id; // Identifier of the class
		int _boardID; // ID of the board for addressing
		// Keeps track if a valid start delimiter has been
		// found. Used to branch code in _readBuffer.
		bool _startByteFound; 
		// Length of the message currently in buffer
		int _length;
		// Keeps track if current message is intended to current board
		bool _idIsValid;

		/*
		*	If serial is available reads the serial buffer. Calls
		*	functions for start delimiter and checksum check. Also
		*	sets appropriate flags for knowing if packet is read.
		*	Does not parse the packet but takes care of checksum.
		*	Returning false indicates packet is not ready to parse.
		*/
		bool _readBuffer(){
			// Check if byte being read is the start byte
			if ((_serial->available() > 2) && !_startByteFound){
				if (_serial->read() == START_DELIMITER){ // Check Start Byte
					_startByteFound = true; 
				} else {
					_startByteFound = false;
					// Add 1 to count of start delimiter fail
					_status->commNumStartDelimFail.increment(_id); 
				}
				// Check if message is destined to this board (id)
				byte id = _serial->read();
				if ((id == _boardID) || (id == BROADCAST_ID)){
					_idIsValid = true;
				} else {
					_idIsValid = false;
				}
				_length = _serial->read(); // Read Length
			}
			// Check if entire message is in buffer
			if ((_serial->available() > _length) && _startByteFound){
				// Read entire message
				for (int i=0; i<_length; i++){
					_inputBuffer[i] = _serial->read();
				}
				// End of reading packet
				_startByteFound = false;
				_inputLastGoodLength = _length;

				// Check the checksum if passes return true
				// Increments counter of good or bad checksum
				_status->commLastChecksum.set(_calculateChecksum(
					_inputBuffer, _length), _id);
				if(_status->commLastChecksum.get(_id) ==
						_serial->read()){
					_status->commNumChecksumPass.increment(_id); 
					// Only return true if message is intended to this board
					if (_idIsValid){
						// FOR DEBUGGING! REMOVE!!
						pinMode(42, OUTPUT);
						digitalWrite(42, HIGH);
						return true;
					} else {
						return false;
					}
					
				} else {
					_status->commNumChecksumFail.increment(_id);
					return false;
				}
			}

			return false;

		}

		/* 
		*	Function returns the checksum of the arguments
		*/
		byte _calculateChecksum(byte *data, int length){
			byte computedChecksum = 0xFF;
			for (int i=0; i<length; i++){
			  computedChecksum -= data[i];
			}
			return computedChecksum;
		}

		/*
		*	Encapsulates and sends data in the output buffer
		*/
		bool _sendBuffer(int length){
			// If there is a message to send
			if (length){
				_serial->write(START_DELIMITER);
				_serial->write(byte(length));
				for (int i=0; i<length; i++){
					_serial->write(_outputBuffer[i]);
				}
				_serial->write(_calculateChecksum(_outputBuffer, length));

				return true;
			}

			return false;
		}
		
};



#endif Comm_H
