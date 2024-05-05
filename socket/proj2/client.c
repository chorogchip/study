#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>

#include "common.h"

int sockfd;
int to_close_thread = 0;

void* input_thread(void* ptr) {
    char buf[256];
    while (1) {
        fgets(buf, sizeof(buf), stdin);
        if (strcmp(buf, "/exit") == 0) {
            to_close_thread = 1;
            break;
        }
        int res = send(sockfd, buf, strlen(buf) + 1, 0);
        if (res == -1) {
            perror("error in send message to server");
        }
    }
}

int main(void) {
    puts("please input an ip address.");
    printf("$ ");
    fgets(input_buf, sizeof(input_buf), stdin);
    for (int i = 0; i < sizeof(input_buf); ++i) if (input_buf[i] == '\n') {
        input_buf[i] = '\0'; break;
    }
    struct hostent* he = gethostbyname(input_buf);
    if (he == NULL) {
        perror("error on gethostname");
        exit(1);
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("error on socket");
        exit(1);
    }

    struct sockaddr_in their_addr;
    their_addr.sin_family = AF_INET;
    their_addr.sin_port = htons(PORT);
    their_addr.sin_addr = *((struct in_addr*)he->h_addr_list[0]);
    bzero(their_addr.sin_zero, sizeof(their_addr.sin_zero));
    
    int res;
    res = connect( sockfd, (struct sockaddr*)&their_addr, sizeof(struct sockaddr));
    if (res == -1) {
        perror("error on connect");
        exit(1);
    }

    res = recv(sockfd, input_buf, sizeof(input_buf), 0);
    if (res == -1) {
        perror("error on recv room info");
        exit(1);
    }

    input_buf[sizeof(input_buf) - 1] = '\0';
    puts(input_buf);

    input_buf[0] = 1;
    res = send(sockfd, input_buf, 1, 0);
    if (res == -1) {
        perror("error on send room number");
        exit(1);
    }

    res = recv(sockfd, input_buf, sizeof(input_buf), 0);
    if (res == -1) {
        perror("error on recv room join signal");
        exit(1);
    }

    if (input_buf[0] != 0) {
        perror("room join signal in invalid");
        exit(1);
    }

    pthread_t thread1;
    res = pthread_create(&thread1, NULL, input_thread, NULL);

    while (1) {
        res = recv(sockfd, input_buf, sizeof(input_buf), 0);
        if (res == -1) {
            perror("error on recv message");
        } else {
            input_buf[sizeof(input_buf) - 1] = '\0';
            puts(input_buf);
        }

        if (to_close_thread == 1) break;
    }
    close(sockfd);
    pthread_join(thread1, NULL);
} 