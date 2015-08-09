#include "array.h"

void init_array(Array * array) {
	
	for (uint8_t i = 0; i < SIZE_OF_ARRAY; i++) {
		
		array->untag[i] = 0x01;
		array->max_value[i] = 0xFF;
		array->num_of_calls[i] = 0x01;

	}

}

uint8_t set_array_data(Array * array, uint8_t data, uint8_t index) {
	
	if (data > array->maxValue[index]) {

		array->data[index] = array->max_value[index];
		return 0x00;

	}

	array->data[index] = data;
	return 0x01; 

}

/*
*	Increments the data of given index by one
*/
uint8_t increment_array_data(Array * array, uint8_t index) {
	
	array->data[index]++;
	return 0x01;

}

/*
*	Decrements the data of given index by one
*/
uint8_t decrement_array_data(Array * array, uint8_t index) {
	
	array->data[index]--;
	return 0x01;

}

/*
*	Sets the maximum admissible value to be stored
*/
uint8_t set_max_value(Array * array, uint8_t value, uint8_t index) {
	
	array->maxValue[index] = value;
	return 0x01;

}

/*
*	Sets the tag for reporting
*/
uint8_t tag_array(Array * array, uint8_t index, uint8_t tag) {
	
	array->tag[index] = tag;
	return 0x01;

}

/*
*	Returns the state of the tag
*/
bool tagged_array(Array * array, uint8_t index) {
	
	uint8_t old = array->tag[index];
	
	if (array->untag[index]) {

		array->tag[index] = 0x00;

	}
	
	return old;

}

uint8_t self_tag_on_diff_array(Array * array, uint8_t index, uint8_t num_of_calls) {
	
	array->num_of_calls[index] = num_of_calls;
	return 0x01;

}

uint8_t self_tag_on_diff_array(Array * array, int index) {

	array->calls_made[index]++; // Increment counter

	if (array->calls_made[index] >= array->num_of_calls[index]) {

		num_of_calls[index] = 1; // Reset counter
		tag_array(array, 0x01, index);
	
	}

	return true;

}