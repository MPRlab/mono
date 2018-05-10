/*
*	Abstract data type for holding 
*/

#ifndef TData_H
#define TData_H

#include <Arduino.h>

template <typename T>
class TData{
	public:
		/*
		*	Constructor
		*/
		TData(){
			_untag = true; // By default the data self untags
			_data = 0; // Data starts as 0

		}

		/*
		*	Returns the stored data
		*/
		T get(){
			return _data;
		}

		/*
		*	Sets the variable to the desired value
		*/
		bool set(T data){
			_data = data;

			// Self tag if selected
			if (_selfTag)
				tag(true);

			return true;
		}

		/*
		*	Sets a single bit in the data 
		*/
		T setBit(int bitToChange, bool value){
			bitToChange = 8 - bitToChange; // Bit 1 is Left most!
			if (value){
				_data |= (0x01 << bitToChange);
			} else {
				_data &= ~(0x01 << bitToChange);
			}
			// Self tag if selected
			if (_selfTag)
				tag(true);

			return _data;
		}

		/*
		*	Get a single bit from data
		*/
		bool getBit(int bitToRead){
			bitToRead = 8 - bitToRead; // Bit 1 is Left most!
			return _data & (0x01 << bitToRead);
		}

		/*
		*	Tags the value for reporting
		*/
		bool tag(bool value){
			_tag = value;
			return value;
		}

		/*
		*	Returns the tag
		*/
		bool tagged(){
			bool old = _tag;
			if (_untag)
				_tag = false;
			return old;
		}

		/*
		*	Increments the value of the data by 1
		*/
		T increment(){
			return _data++;
		}

		/*
		*	Sets the flag that is used by the communication class
		*	to decide if this information should be requested from the 
		*	2560.
		*/
		bool request(bool yes){
			_request = yes;
			return true;
		}

		/*
		*	Gets the flag that is used by the communication class
		*	to decide if this information should be requested from the 
		*	2560. If flagged unflags. 
		*/
		bool request(){
			bool old = _request;
			_request = false;
			return old;
		}

		/*
		*	Sets the self untagging flag. If set the tag is reset
		*	whenever tagged is called. 
		*/
		bool setUntag(bool untag){
			_untag = untag;
			return true;
		}

		/*
		*	Sets the self tagging flag. If set the data is tagged
		*	anytime there is any change to it.
		*/
		bool setSelfTag(bool selfTag){
			_selfTag = selfTag;
			return true;
		}

		/*
		*	Sets the data for forwarding. Ex: Information received
		*	from UI should be sent to NIM.
		*/
		bool forward(int id){
			_forwardID = id;
			return true;
		}

		/*
		*	Check if the current serial class should be the one 
		*	forwarding data.
		*/
		bool forwarded(int id){
			if (id == _forwardID){
				_forwardID = 0;
				return true;
			}
			return false;
		}
		
	private:
		// Declare generic variable
		T _data;
		bool _tag;
		bool _request;
		bool _untag; // Self untag?
		bool _selfTag; // Self tag on sets?
		int _forwardID; // Serial port for data to be sent


};

#endif