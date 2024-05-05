
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* thread(void* vargp) {
    printf("Hello, World!");
    return NULL;
}

int main(void) {
    pthread_t tid;
    pthread_create(&tid, NULL, thread, NULL);
    pthread_join(tid, NULL);
    exit(0);
}
