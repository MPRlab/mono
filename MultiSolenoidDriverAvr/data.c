#include "data.h"

void init_data(Data * t) {
	
	t->untag = 0x01;
	t->data = 0;

}

uint8_t set_data(Data * t, uint8_t data) {
	
	t->data = data;

	if (t->self_tag) {

		tag(t, 0x01);

	}

	return 0x00;
	
}

uint8_t set_data_bit(Data * t, uint8_t bitToChange, uint8_t value) {
	
	bitToChange = 0x08 - bitToChange; // Bit 1 is Left most!
	
	if (value) {

		t->data |= (0x01 << bitToChange);

	} 
	else {

		t->data &= ~(0x01 << bitToChange);

	}
	
	if (t->selfTag) {

		tag(t, 0x01);

	}

	return t->data;

}

uint8_t get_data_bit(Data * t, uint8_t bitToRead) {
	
	bitToRead = 0x08 - bitToRead; // Bit 1 is Left most!
	return t->data & (0x01 << bitToRead);

}

uint8_t tag_data(Data * t, uint8_t value) {

	t->tag = value;
	return value;

}

uint8_t tagged_data(Data * t) {
	
	uint8_t old = t->tag;
	
	if (t->untag) {

		t->tag = 0x00;

	}
	
	return old;
}


uint8_t increment_data(Data * t) {

	t_>data++;
	return t->data

}

/*
*	Sets the flag that is used by the communication class
*	to decide if this information should be requested from the 
*	2560.
*/
uint8_t set_request_data(Data * t, uint8_t flag) {
	
	t->request = flag;
	return 0x01;

}

/*
*	Gets the flag that is used by the communication class
*	to decide if this information should be requested from the 
*	2560. If flagged unflags. 
*/
uint8_t request_data(Data * t) {
	
	uint8_t old = t->request;
	t->request = 0x00;
	return old;

}

/*
*	Sets the data for forwarding. Ex: Information received
*	from UI should be sent to NIM.
*/
// bool forward(int id){
// 	_forwardID = id;
// 	return true;
// }

/*
*	Check if the current serial class should be the one 
*	forwarding data.
*/
// bool forwarded(int id){
// 	if (id == _forwardID){
// 		_forwardID = 0;
// 		return true;
// 	}
// 	return false;
// }
