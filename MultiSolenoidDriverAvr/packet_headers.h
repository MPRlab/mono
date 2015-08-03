/*
*	Contains all the packet headers for communication
*	By Paulo Apr 3, 2015
*/

#ifndef __PACKETHEADERS_H__
#define __PACKETHEADERS_H__

// Headers according to ProtocolV1
// As viewed from ATMEGA2560:
// GET is a request. SET acts on received command. REPORT sends status

#define SET_ALL_SOLENOIDS 0x10
#define SET_POWER_SOLENOID_ON 0x11
#define SET_POWER_SOLENOID_OFF 0x12

#endif
// __PACKETHEADERS_H__