#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h> // read(), write(), close()
#define MAX 80
#define PORT 8080
#define SA struct sockaddr

// comm between server and client
void comm(int connfd) {
    char buff[MAX];
    int n;

    // chat loop
    for (;;) {
        bzero(buff, MAX);
        // read client msg and copy it into buffer
        read(connfd, buff, sizeof(buff));

        printf("From client: %s\nTo client: ", buff);

        bzero(buff, MAX);
        n = 0;
        // copy server msg into buffer
        while ((buff[n++] = getchar()) != '\n');

        // server exit if msg contains "Exit"
        if (strncmp("exit", buff, 4) == 0) {
            printf("Server exit\n");
            break;
        }
    }
}

// driver function
int main() {
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Failed to create socket\n");
        exit(0);
    } else {
        printf("Socket created successfully\n");
    }
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // bind new socket to IP
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        printf("Failed to bind socket\n");
        exit(0);
    } else {
        printf("Socket bound successfully\n");
    }

    // server ready to listen
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed\n");
        exit(0);
    } else {
        printf("Server is listening\n");
    }

    // accept data packet from client
    len = sizeof(cli);
    connfd = accept(sockfd, (SA*)&cli, &len);
    if (connfd < 0) {
        printf("Accept failed\n");
        exit(0);
    } else {
        printf("Accepting client data packet\n");
    }

    comm(connfd);

    close(sockfd);
}