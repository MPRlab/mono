all: audio_processing shared_memory message_passing

audio_processing: analysis_ap tone_gen_ap

shared_memory: parent_sm child_sm

message_passing: server_mp client_mp

experimental: server_ap

analysis_ap: AudioAnalysis/mpr_processing_client.c
	gcc -o analysis_ap AudioAnalysis/mpr_processing_client.c -lpthread -ljack -lm
	
tone_gen_ap: AudioAnalysis/note_generator.c
	gcc -o tone_gen_ap AudioAnalysis/note_generator.c -lpthread -ljack -lm

parent_sm: SharedMemoryTest/test1.cpp
	g++ SharedMemoryTest/test1.cpp -o parent_sm -lpthread -lrt

child_sm: SharedMemoryTest/test2.cpp
	g++ SharedMemoryTest/test2.cpp -o child_sm -lpthread -lrt

server_mp: MessagePassing/server.c 
	gcc -o server_mp MessagePassing/server.c

client_mp: MessagePassing/client.c
	gcc -o client_mp MessagePassing/client.c

server_ap: AudioAnalysis/mpr_processing_client_wmp.c
	gcc -o server_ap AudioAnalysis/mpr_processing_client_wmp.c -lpthread -ljack -lm
