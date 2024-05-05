#include <stdio.h>
#include <signal.h>

void ss(int sig) {
    printf("asdadadsad\n%d", sig);
}

int asd(int a) {
    int arr[10000];
    printf("%d\n", a);
    arr[a] = asd(a+1);
    return arr[a];
}

int main(void) {
    signal(SIGILL, ss);
    int a = asd(1);
    printf("%d", a);
}