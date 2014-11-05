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

    char buffer[256];
    
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
        freq += buffer[1] << 8;

        long long seconds = 0;
        seconds += buffer[2];
        seconds += ((long long) buffer[3]) << 8;
        seconds += ((long long) buffer[4]) << 16;
        seconds += ((long long) buffer[5]) << 24;
        seconds += ((long long) buffer[6]) << 32;
        seconds += ((long long) buffer[7]) << 40;
        seconds += ((long long) buffer[8]) << 48;
        seconds += ((long long) buffer[9]) << 56;

        long nano_seconds = 0;
        nano_seconds += buffer[10];
        nano_seconds += ((long) buffer[11]) << 8;
        nano_seconds += ((long) buffer[12]) << 16;
        nano_seconds += ((long) buffer[13]) << 24;
        
        printf("Frequency: %d began at time: %lld s %ld ns\n", freq, seconds, nano_seconds);


    }
    return 0;
}
