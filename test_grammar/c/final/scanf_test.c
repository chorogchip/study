#include <stdio.h>

int main(void) {
    int a;
    printf("%d", a);
    scanf("%d    ", &a);
    printf("%d|%d", a, getchar());
}