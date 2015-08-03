/*
 * Implementation of methods from comm.h
 * Nathan Hughes
*/

#include "comm.h"

good_packet_count = 0;
time_last_good_packet = 0;

uint8_t calculate_checksum(uint8_t *data, uint8_t length) {
	
	uint8_t computed_checksum = CHECKSUM_STARTING_VALUE;

	for (uint8_t i = 0; i < length; i++) {
		
		computed_checksum -= data[i];
	
	}

	return computed_checksum;
}

uint8_t read_buffer(Comm * comm) {

	if (bytes_available(comm->serial) > 2 && !comm->start_byte_found) {
		
		if (read(comm->serial) == START_DELIMITER) {
			
			comm->start_byte_found = 0x01;

		}
		else {
			
			comm->start_byte_found = 0x00;
			increment_comm_num_start_delim_fail(comm->status);
		
		}
		
		uint8_t id = read(comm->serial);
		if (id == comm->boardID || id == BROADCAST_ID) {
			
			comm->id_is_valid = 0x01;
		
		}
		else {

			comm->id_is_valid = 0x00;

		}
		
		comm->length = read(serial);
	}

	if (bytes_available(comm->serial) > comm->length && comm->startByteFound) {
		
		for (uint8_t i = 0; i < comm->length; i++) {
			
			comm->input_buffer[i] = read(comm->serial);

		}
		
		comm->start_byte_found = 0x00;
		comm->input_last_good_length = comm->length;

		set_comm_last_checksum(comm->status, calculate_checksum(&(comm->input_buffer), comm->length);

		if(get_checksum(comm->status) == read(serial)) {
			
			increment_valid_checksums(comm->status);
			
			if (comm->id_is_valid) {
				
				return 0x01;
			
			}
			else {
				
				return 0x00;

			}
			
		} 
		else {
			
			increment_invalid_checksums(comm->status);
			return 0x00;

		}
	
	}

	return 0x00;

}

uint8_t sendBuffer(Comm * comm, uint8_t length) {

	if (length) {
		
		write(serial, START_DELIMITER);
		write(serial, length);
		write_buffer(serial, &(comm->output_buffer), length);
		write(calculateChecksum(&(comm->output_buffer), length));
		return 0x01;
	
	}

	return 0x00;

}

void init_comm(Comm * comm, HardwareSerial * serial, Status * status, Parser * parser, uint8_t board_id) {
	
	comm->serial = serial;
	comm->status = status;
	comm->parser = parser;
	comm->length = 0;
	comm->start_byte_found = 0;
	comm->id_is_valid = 0;
	comm->board_id = board_id;
	comm->input_last_good_length = 0;

}

uint8_t update(Comm * comm){
	
	if(read_buffer(comm)){ 

		if(parse(comm->parser, &(comm->inputBuffer), comm->input_last_good_length)) {
			
			good_packet_count++;
			
			if ((millis() - time_last_good_packet) > 1000) {
				set_comm_packet_per_second_status(comm->status, good_packet_count);
				good_packet_count = 0;
				time_last_good_packet = millis();
			}

			tag_status_comm_acknowledge(comm->status);

		}
	}

	construct_message(comm->parser, &(comm->outputBuffer), &output_buffer_message_length);
	send_buffer(comm, output_buffer_message_length);
	
	return 0x01;

}