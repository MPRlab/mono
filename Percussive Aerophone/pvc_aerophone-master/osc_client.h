/**
 * osc_client.h
 * Definition of a class for connecting to the central controller using OSC over UDP
 *
 * @author  Tanuj Sane
 * @since   4/20/2018
 * @version 1.0
 *
 * Changelog:
 * - 1.0 Initial commit
 */

#ifndef OSC_CLIENT_H_
#define OSC_CLIENT_H_

#include "mbed.h"
#include "UDPSocket.h"
#include "SocketAddress.h"

#define BROADCAST_IP			"192.168.1.255"
#define OSC_PORT				1234
#define INSTRUMENT_NAME			"pvc_aerophone"
#define OSC_MSG_SIZE			256

typedef char byte;

enum {
	OSC_SIZE_ADDRESS = 64,
	OSC_SIZE_FORMAT = 16,
	OSC_SIZE_DATA = 128
};

typedef struct {
	char address[OSC_SIZE_ADDRESS];			// The OSC address indicating where to dispatch
	char format[OSC_SIZE_FORMAT];			// Format specifier for the contained byte array
	byte data[OSC_SIZE_DATA]; 				// The byte array containing the data
	int data_size;							// The size of the data array
} OSCMessage;

/**
 * Calculate the OSC size (next multiple of 4 to the length) of a string
 *
 * @param str	The string
 *
 * @return The padded length to be used for this string in OSC handling
 */
static int OSC_SIZE(char* str) {
	int len = strlen(str) + 1;
	if(len % 4 != 0) len += 4 - (len % 4);

	return len;
}

/**
 * Create a new OSCMessage with the given values
 *
 * @param address	The dispatch address
 * @param format	The format of the data
 * @param ...		Variadic parameters to be stored in the data array; informed by "format"
 */
static OSCMessage* build_osc_message(char* address, char* format, ...) {
	OSCMessage* msg = (OSCMessage*) malloc(sizeof(OSCMessage));

	// Copy in the strings that can be placed immediately
	strcpy(msg->address, address);
	strcpy(msg->format, format);

	// Create two variadic parameters arrays, one for calculating size and the other to populate
	va_list args; va_start(args, format);

	// Populate the data buffer with the variadic arguments
	int i = 0, j = 1; unsigned int k = 0;
	uint32_t int_container; float float_container; char* string_container;

	while(format[j] != '\0') {
		switch(format[j++]) {
		case 'i':
			int_container = (uint32_t) va_arg(args, int);
			memcpy(msg->data + i, &int_container, sizeof(uint32_t));
			i += sizeof(uint32_t);
			break;

		case 'f':
			float_container = (float) va_arg(args, double);
			memcpy(msg->data + i, &float_container, sizeof(float));
			i += sizeof(float);
			break;

		case 's':
			string_container = (char*) va_arg(args, void*);
			int m = strlen(string_container) + 1, n = OSC_SIZE(string_container);
			memcpy(msg->data + i, string_container, m);
			for(k = m; k < n; k++) {
				msg->data[i + k] = '\0';
			}
			i += n;
			break;
		}
	}
	msg->data_size = i;

	// Free the variadic arguments
	va_end(args);

	return msg;
}

class OSCClient {
private:
	SocketAddress controller;		// The address (IP, port) of the central controller
	SocketAddress address;			// The address (IP, port) of this instrument
	UDPSocket udp;					// The socket used to communicate with the controller over UDP

public:
	/** Constructor */
	template <typename S>
	OSCClient(S* stack):
		controller(BROADCAST_IP, OSC_PORT), address(stack->get_ip_address(), OSC_PORT), udp(stack)
	{/* Empty */}

	/**
	 * Get the IP address of the controller
	 */
	const char* get_controller_ip() {
		return this->controller.get_ip_address();
	}

	/**
	 * Send an OSC Message over UDP
	 *
	 * @param msg	The OSCMessage to send out
	 *
	 * @return The number of bytes sent, or an error code
	 */
	nsapi_size_or_error_t send(OSCMessage* msg) {
		// Calculate the length of the buffer to send
		int address_length = strlen(msg->address), format_length = strlen(msg->format);
		int length = address_length + 1 + format_length + 1 + msg->data_size;

		// Allocate the buffer and a position pointer
		byte* stream = (byte*) malloc(length);
		byte* posn = stream;

		// Flatten the OSCMessage into the allocated stream buffer
		strcpy(posn, msg->address);
		posn += address_length + 1;

		strcpy(posn, msg->format);
		posn += format_length + 1;

		for(int i = 0; i < msg->data_size; i++) {
			*(posn++) = msg->data[i];
		}

		// Send out the stream and then free it
		nsapi_size_or_error_t out = this->udp.sendto(this->controller, stream, length);
		free(stream);

		return out;
	}

	/**
	 * Receive an OSC message over UDP
	 *
	 * @param msg	The OSCMessage to populate with incoming data
	 *
	 * @return The number of bytes received, or an error code
	 */
	nsapi_size_or_error_t receive(OSCMessage* msg) {
		char* buffer = (char*) malloc(OSC_MSG_SIZE);
		char* start = buffer;

		nsapi_size_or_error_t recv = this->udp.recvfrom(&this->controller, buffer, OSC_MSG_SIZE);
		if(recv <= 0) return recv;

		// Clear the struct
		memset(msg, 0, sizeof(OSCMessage));

		// Copy the buffer directly into address, which will capture everything up to the first null terminator
		int address_length = strlen(buffer) + 1;
		strcpy(msg->address, buffer);
		buffer = buffer + address_length;

		// After advancing to that point, the next string extracted by strcpy will be the type tag
		int format_length = strlen(buffer) + 1;
		strcpy(msg->format, buffer);
		buffer = buffer + format_length;

		// Blindly copy everything else up to the end of the received byte stream
		memcpy(msg->data, buffer, recv - address_length - format_length);
		msg->data_size = recv - address_length - format_length;

		// What I wouldn't give for C to have automatic garbage collection
		free(start);

		return recv;
	}

	/** Register name and supported functions with the central controller */
	void connect() {
		// For the setup phase, allow the socket to block
		this->udp.set_blocking(true);

		// Create and send the OSC message for registering the name of the instrument
		OSCMessage* msg = build_osc_message(
				"/controller/register/name",
				",ss",
				INSTRUMENT_NAME,
				this->address.get_ip_address()
		);

		int size_or_error = this->send(msg);
		if(size_or_error < 0) {
			printf("Error sending the registration message! (%d)\r\n", size_or_error);
			exit(1);
		}

		// Get back a request for functions from the controller
		size_or_error = this->receive(msg);
		if(size_or_error < 0) {
			printf("Error finding controller! (%d)\r\n", size_or_error);
			exit(1);
		}

		// For normal operation, socket should be polled
		this->udp.set_blocking(false);

		// FREEDOM!
		free(msg);
	}
};

#endif /* OSC_CLIENT_H_ */
