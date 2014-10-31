all: audio_processing shared_memory message_passing

audio_processing: client client_gen

shared_memory: parent child

message_passing: server client_mp


client: AudioAnalysis/mpr_processing_client.c
	gcc -o analysis_ap AudioAnalysis/mpr_processing_client.c -lpthread -ljack -lm
	
client_gen: AudioAnalysis/note_generator.c
	gcc -o tone_gen_ap AudioAnalysis/note_generator.c -lpthread -ljack -lm

parent: SharedMemoryTest/test1.cpp
	g++ SharedMemoryTest/test1.cpp -o parent_sm -lpthread -lrt

child: SharedMemoryTest/test2.cpp
	g++ SharedMemoryTest/test2.cpp -o child_sm -lpthread -lrt

server: MessagePassing/server.c 
	gcc -o server_mp MessagePassing/server.c

client_mp: MessagePassing/client.c
	gcc -o client_mp MessagePassing/client.c
