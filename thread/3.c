#include <stdio.h>
#include <pthread.h>

#define N 1000

int cnt = 0;

void* thread(void* vargp) {
    for (int i = 0; i < 100; ++i)
        ++cnt;
}

int main(void) {
    pthread_t tid[N];
    for (int i = 0; i < N; ++i)
        pthread_create(&tid[i], NULL, thread, NULL);
    for (int i = 0; i < N; ++i)
        pthread_join(tid[i], NULL);
    printf("N: %d cnt: %d\n", N, cnt);
}