all: audio_processing shared_memory message_passing

audio_processing: build/analysis_ap build/tone_gen_ap

shared_memory: build/parent_sm build/child_sm

message_passing: build/server_mp build/client_mp

experimental: build/server_ap

clean: 
	rm -rf build/*

build/analysis_ap: AudioAnalysis/mpr_processing_client.c
	gcc -o build/analysis_ap AudioAnalysis/mpr_processing_client.c -lpthread -ljack -lm
	
build/tone_gen_ap: AudioAnalysis/note_generator.c
	gcc -o build/tone_gen_ap AudioAnalysis/note_generator.c -lpthread -ljack -lm

build/parent_sm: SharedMemoryTest/test1.cpp
	g++ SharedMemoryTest/test1.cpp -o build/parent_sm -lpthread -lrt

build/child_sm: SharedMemoryTest/test2.cpp
	g++ SharedMemoryTest/test2.cpp -o build/child_sm -lpthread -lrt

build/server_mp: MessagePassing/server.c 
	gcc -o build/server_mp MessagePassing/server.c

build/client_mp: MessagePassing/client.c
	gcc -o build/client_mp MessagePassing/client.c

build/server_ap: AudioAnalysis/mpr_processing_client_wmp.c
	gcc -o build/server_ap AudioAnalysis/mpr_processing_client_wmp.c -lpthread -ljack -lm
