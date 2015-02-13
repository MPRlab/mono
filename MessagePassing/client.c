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
#include <netdb.h> 
#include <string.h>



int main(int argc, char *argv[])
{
    int sockfd, n;
    int PORT_NUMBER = atoi(argv[1]);
    struct sockaddr_in serv_addr;
    struct hostent *server;

    unsigned char buffer[256];
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
   
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname("localhost");
    
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }
    
    bzero((char *) &serv_addr, sizeof(serv_addr));
    
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    
    serv_addr.sin_port = htons(PORT_NUMBER);
    
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
    
    //n = write(sockfd,buffer,strlen(buffer));
    
    /*if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }*/
    
    while (1) {
        bzero(buffer,256);
        n = read(sockfd,buffer,256);
    
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        int freq = 0;
        freq += buffer[0];
        freq += ((int) buffer[1]) << 8;

        long seconds = 0;
        seconds += buffer[2];
        seconds += ((long) buffer[3]) << 8;
        seconds += ((long) buffer[4]) << 16;
        seconds += ((long) buffer[5]) << 24;
        seconds += ((long) buffer[6]) << 32;
        seconds += ((long) buffer[7]) << 40;
        seconds += ((long) buffer[8]) << 48;
        seconds += ((long) buffer[9]) << 56;

        long nano_seconds = 0;
        nano_seconds += buffer[10];
        nano_seconds += ((long) buffer[11]) << 8;
        nano_seconds += ((long) buffer[12]) << 16;
        nano_seconds += ((long) buffer[13]) << 24;
        
        printf("Frequency: %d began at time: %ld s %ld ns\n", freq, seconds, nano_seconds);


    }
    return 0;
}
