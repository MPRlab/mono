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
    int i;
    for (i = 0; i < 20; i ++) {
        bzero(buffer,256);
        n = read(sockfd,buffer,256);
    
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        
        printf("%s",buffer);

    }
    return 0;
}
