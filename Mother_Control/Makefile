all: client server

client: example_client.c
	gcc -o client example_client.c -llo

server: example_server.c
	gcc -o server example_server.c -llo

clean: 
	rm client server
