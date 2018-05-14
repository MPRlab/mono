/**
 * main.cpp
 * Controller for PVC Aerophone, vIII on Nucleo-144, F767ZI
 *
 * @author  Tanuj Sane
 * @since   4/26/2018
 * @version 1.0
 *
 * Changelog:
 * - 1.0 Initial commit
 */

#include "mbed.h"
#include "EthernetInterface.h"

#include "driver_board.h"
#include "osc_client.h"

#define EVER		;;
#define T_SYNC		7		/* ms */

DriverBoard left(PC_8, PC_9, PC_10, PC_11);
DriverBoard right(PC_6, PB_15, PB_13, PB_12);

/**
 * Dispatcher function for OSCMessages that calls the proper routine immediately
 */
static void osc_dispatch(OSCMessage* msg) {
	// Ensure that this message is addressed to this instrument
	char* token = strtok(msg->address, "/");
	if(strcmp(token, INSTRUMENT_NAME) != 0) {
		printf("Unrecognized address %s\r\n", token);
		return;
	}

	// Get the desired function call and dispatch the data to it
	token = strtok(NULL, "/");
	if(strcmp(token, "play") == 0) {
		// Cheat a bit and just check that the format is correct without actually using it to extract the data
		if(strcmp(msg->format, ",ii") != 0) {
			printf("Incorrect arguments (%s) for %s()\r\n", msg->format, token);
			return;
		}

		uint32_t pitch, velocity;
		memcpy(&pitch, msg->data, sizeof(uint32_t));
		memcpy(&velocity, msg->data + sizeof(uint32_t), sizeof(uint32_t));

		printf("play(%d, %d)\r\n", pitch, velocity);
	}
	else {
		printf("Unrecognized address %s\r\n", token);
		return;
	}
}

int main() {
	EthernetInterface eth; eth.connect();
	printf("Connected at %s\r\n", eth.get_ip_address());

	OSCClient osc(&eth); osc.connect();
	printf("Controller found at %s! Registered as %s\r\n", osc.get_controller_ip(), INSTRUMENT_NAME);

	OSCMessage* msg = (OSCMessage*) malloc(sizeof(OSCMessage));
	nsapi_size_or_error_t size_or_error;

	// Enable the DriverBoards (drive RST to high)
	left.init(); right.init();

	Timer sync_timer; sync_timer.start();
	int elapsed = 0;

	for(EVER) {		// I'm hilarious
		elapsed = sync_timer.read_ms();

		// Poll for an incoming OSCMessage and dispatch it
		size_or_error = osc.receive(msg);
		if(size_or_error == NSAPI_ERROR_WOULD_BLOCK) /* Skip */;
		else if(size_or_error <= 0) {
			printf("ERROR! %d\r\n", size_or_error);
		}
		else osc_dispatch(msg);

		// Synchronize the internal state out to the DriverBoard pins at the desired frequency
		if(elapsed >= T_SYNC) {
			left.sync(elapsed);
			sync_timer.reset();
		}
	}
}
