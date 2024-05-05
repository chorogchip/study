#include<stdio.h>

int main(void) {
    register int a;
    int *p = &a;
    //printf("%p", p);  / error
}