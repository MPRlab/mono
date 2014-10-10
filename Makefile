all: client client_gen

client: mpr_processing_client.c
	gcc -o client mpr_processing_client.c -lpthread -ljack -lm
	
client_gen: note_generator.c
	gcc -o client_gen note_generator.c -lpthread -ljack -lm
