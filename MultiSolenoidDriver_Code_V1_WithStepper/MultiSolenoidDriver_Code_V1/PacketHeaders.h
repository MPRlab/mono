/*
*	Contains all the packet headers for communication
*	By Paulo Apr 3, 2015
*/

#ifndef PacketHeaders_H
#define PacketHeaders_H

// Headers according to ProtocolV1
// As viewed from ATMEGA2560:
// GET is a request. SET acts on received command. REPORT sends status

#define SET_ALL_SOLENOIDS 0x10
#define SET_POWER_SOLENOID_ON 0x11
#define SET_POWER_SOLENOID_OFF 0x12

#define SET_STEPPER_FORWARD 0x21
#define SET_STEPPER_REVERSE 0x22



#endif