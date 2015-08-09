/*
*	This class will define an abstract generic data type. 
*	It will be used for storage of arrays with the ability
*	to get the average of all elements, set or get specific 
*	elements among other atributes. 
*	By Paulo
*   Modified by Nathan for AVR-libc
*/

#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <avr/stdint.h>

#define SIZE_OF_ARRAY 5

struct Array {
uint8_t data[SIZE_OF_ARRAY]; // Keeps Data
uint8_t tag[SIZE_OF_ARRAY]; // Tags for Reporting
uint8_t num_of_calls[SIZE_OF_ARRAY]; // Number of calls before tagging
uint8_t calls_made[SIZE_OF_ARRAY];
uint8_t untag[SIZE_OF_ARRAY]; // Untag Automatically?
uint8_t max_value[SIZE_OF_ARRAY]; // Limits maximum value of data

};

typedef struct Array Array;


void init_array(Array * array);

uint8_t set_array_data(Array * array, uint8_t data, uint8_t index);

uint8_t increment_array_data(Array * array, uint8_t index);

uint8_t decrement_array_data(Array * array, uint8_t index);

uint8_t set_max_value(Array * array, uint8_t value, uint8_t index);

uint8_t tag_array(Array * array, uint8_t index, uint8_t tag);

bool tagged_array(Array * array, uint8_t index);

uint8_t self_tag_on_diff_array(Array * array, uint8_t index, uint8_t num_of_calls);

uint8_t self_tag_on_diff_array(Array * array, int index);

#endif