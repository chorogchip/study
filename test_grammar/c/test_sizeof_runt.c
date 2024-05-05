#include<stdio.h>
int main(void) {
    int *i;
    double *dp = (void*)&i;
    printf("%ld", sizeof *dp);
}