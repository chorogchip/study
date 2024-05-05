#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <memory.h>

#include "common.h"

void server_create_room() {

}
void server_delete_room() {

}
void server_view_room() {

}
void server_create_user() {

}
void server_delete_user() {

}
void server_view_user() {

}
void server_kick() {

}


struct LinkedThread {
    struct LinkedThread* next;
    pthread_t thread_data;
    int socket_fd;
    int state;
};

void* input_thread(void* arg) {
    struct LinkedThread* self = arg;
    char buf[256];
    int res;

    res = send(self->socket_fd, "Hello", 5, 0);
    if (res == -1) {
        perror("error in server send");
    }

    res = recv(self->socket_fd, buf, sizeof(buf), 0);
    if (res == -1) {
        perror("error in server recv");
    }  else {
        printf("recieved room number from client %d - %d\n", self->socket_fd, (int)buf[0]);
    }

    buf[0] = 0;
    res = send(self->socket_fd, buf, 1, 0);
    if (res == -1) {
        perror("error in server send");
    }

    while (1) {
        res = recv(self->socket_fd, buf, sizeof(buf), 0);
        if (res == -1) {
            perror("error in server recv");
            break;
        }
        buf[sizeof(buf) - 1] = '\0';
        printf("%d: %s\n", self->socket_fd, buf);
        
        res = send(self->socket_fd, "asd", 4, 0);
        if (res == -1) {
            perror("error in server send");
            break;
        }
    }

    self->state = 1;
}

struct LinkedThread* threads = NULL;


int main(void) {
    int sockfd, new_fd;
    struct sockaddr_in my_addr;
    struct sockaddr_in their_addr;
    int sin_size;

    int res;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(PORT);
    my_addr.sin_addr.s_addr = INADDR_ANY;
    bzero(my_addr.sin_zero, sizeof(my_addr.sin_zero));

    if (bind(sockfd, (struct sockaddr*)&my_addr, sizeof(struct sockaddr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, 10) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        sin_size = sizeof(struct sockaddr_in);
        if ((new_fd = accept(sockfd, (struct sockaddr*)&their_addr, &sin_size)) == -1) {
            perror("accept");
            continue;
        }
        printf("server: get connection from %s\n", inet_ntoa(their_addr.sin_addr));

        struct LinkedThread* new_thread = malloc(sizeof(struct LinkedThread*));
        new_thread->next = threads;
        new_thread->state = 0;
        new_thread->socket_fd = new_fd;
        res = pthread_create(&new_thread->thread_data, NULL, input_thread, (void*)new_thread);
        threads = new_thread;

        struct LinkedThread** tmp = &threads;
        while (*tmp != NULL) {
            if ((*tmp)->state == 1) {
                pthread_join((*tmp)->thread_data, NULL);
                close((*tmp)->socket_fd);
                struct LinkedThread* next = (*tmp)->next;
                free(*tmp);
                *tmp = next;
            }
        }
    }
}