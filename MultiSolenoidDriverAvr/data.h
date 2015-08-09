#ifndef __DATA_H__
#define __DATA_H__


struct Data {
	uint8_t data;
	uint8_t tag;
	uint8_t request;
	uint8_t untag; // Self untag?
	uint8_t self_tag; // Self tag on sets?
	uint8_t forward_id; // Serial port for data to be sent
};

typedef struct Data Data

void init_data(Data * t);

uint8_t set_data(Data * t, uint8_t data);

uint8_t set_data_bit(Data * t, uint8_t bitToChange, uint8_t value);

uint8_t get_data_bit(Data * t, uint8_t bitToRead);

uint8_t tag_data(Data * t, uint8_t value);

uint8_t tagged_data(Data * t);

uint8_t increment_data(Data * t);

uint8_t set_request_data(Data * t, uint8_t flag);

uint8_t request_data(Data * t);

#endif