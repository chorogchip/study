#include<stdio.h>

int main(void) {
    _Bool b = (sizeof(char) - 100) < 100;
    printf("%d\n", b);  //0

    printf("%ld %lu\n", sizeof(char), sizeof(char));  // no warn cause
    printf("%ld %lu\n", 1UL, 1UL);  // no warn
    printf("%ld %lu\n", 1L, 1L);  // no warn
}