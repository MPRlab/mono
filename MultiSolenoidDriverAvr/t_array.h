/*
*	This class will define an abstract generic data type. 
*	It will be used for storage of arrays with the ability
*	to get the average of all elements, set or get specific 
*	elements among other atributes. 
*	By Paulo
*   Modified by Nathan for AVR-libc
*/

#ifndef __TARRAY_H__
#define __TARRAY_H__

#define SIZE_OF_ARRAY 5

T _data[SIZE_OF_ARRAY]; // Keeps Data
		bool _tag[SIZE_OF_ARRAY]; // Tags for Reporting
		unsigned int _numOfCalls[SIZE_OF_ARRAY]; // Number of calls before tagging
		bool _untag[SIZE_OF_ARRAY]; // Untag Automatically?
		unsigned long _maxValue[SIZE_OF_ARRAY]; // Limits maximum value of data




#endif