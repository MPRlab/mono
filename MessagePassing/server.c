/*
	Copyright Nathan Hughes 2015

    This file is part of code developed for the Music Perception and Robotics 
	Labrotory at Worcester Polytechnic Institute.

    This file is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This file is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    somewhere in this repository.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define IN_BUFFER_SIZE 256
#define OUT_BUFFER_SIZE 256

int server_socket_fd, client_socket_fd;

int setup_server(int PORT_NUMBER) {
    
    int clilen;
    struct sockaddr_in serv_addr, cli_addr;
    
    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    //socket error
    if (server_socket_fd < 0) {exit(1);}
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT_NUMBER);

    //bind error
    if (bind(server_socket_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("");
        exit(1);}
    
    listen(server_socket_fd, 5);

    clilen = sizeof(cli_addr);
    
    client_socket_fd = accept(server_socket_fd, (struct sockaddr *) &cli_addr, &clilen);

    if (client_socket_fd < 0) { exit(1);}

    return client_socket_fd;
}

void read_message(char * buffer, int fd) {
    memset(buffer, 0, IN_BUFFER_SIZE);
    if (read(fd, buffer, IN_BUFFER_SIZE) < 0) {exit(1);}
}

void write_message(char * buffer, int fd) {
    if (write(fd, buffer, OUT_BUFFER_SIZE) < 0) {exit(1);}
    memset(buffer, 0, OUT_BUFFER_SIZE);
}

int main(int argc, char *argv[])
{
    int message_fd;

    char out_buffer[OUT_BUFFER_SIZE];
    char in_buffer[IN_BUFFER_SIZE];
    memset(out_buffer, 0, OUT_BUFFER_SIZE);
    memset(in_buffer, 0, IN_BUFFER_SIZE);

    message_fd = setup_server(atoi(argv[1]));

    int i, j;
    for (i = 0; i < 20; i ++) {
        char message[] = "Hello World!\n";
        for (j = 0; j < 13; j++) {
            out_buffer[j] = message[j];
        }
        out_buffer[13] = i + 30;
        out_buffer[13] = 0;
        write_message(out_buffer, message_fd);
    }

    shutdown(message_fd, SHUT_RDWR);
    shutdown(server_socket_fd, SHUT_RDWR);
    return 0; 
    
}
