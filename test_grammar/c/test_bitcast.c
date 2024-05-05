#include<stdio.h>
int main(void) {
    float a = 5.12, b = 5.12;
    printf("%d %d %x", (int)a, *(int*)&b, *(int*)&b);
}