
#	Copyright Nathan Hughes 2015

#   This file is part of code developed for the Music Perception and Robotics 
#	Labrotory at Worcester Polytechnic Institute.

#   This file is free software: you can redistribute it and/or modify
#   it under the terms of the GNU General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.

#   This file is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU General Public License for more details.

#   You should have received a copy of the GNU General Public License
#   somewhere in this repository.  If not, see <http://www.gnu.org/licenses/>.



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
