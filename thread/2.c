
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define N 10

void* thread(void* vargp);

char** ptr;

int main(void) {
    int i;
    pthread_t tid;
    char* msgs[N] = {
        "Hello from foo",
        "Hello from bar"
    };

    ptr = msgs;
    for (i = 0; i < N; ++i)
        pthread_create(&tid, NULL, thread, (void*)(size_t)i);
    pthread_exit(NULL);
}

void* thread(void* vargp) {
    int myid = (int)(size_t)vargp;
    static int cnt = 0;
    printf("[%d]: %s (cnt=%d)\n", myid, ptr[myid], ++cnt);
    return NULL;
}