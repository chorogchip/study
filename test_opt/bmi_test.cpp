#pragma GCC target("bmi")

#include <stdio.h>



int main(void) {
    int a;
    scanf("%d", &a);
    printf("%x %x", a^a-1, a&a-1);
}