#include<stdio.h>

int main(void) {
    int a = 2;
    //int *p = a;  // warn
    int *p2 = 0;  // OK
    //int *p3 = 1;  // warn
    //int a2 = NULL;  // warn

    //int* pp1 = (int**)NULL;  // warn
    void* pp2 = (int**)NULL;  // OK
    //int* pp3 = (void**)NULL;  // warn
    //void** pp4 = (int*)NULL;  // warn
    int** pp5 = (void*)NULL;  // OK
    void* pp6 = (void**)NULL;  // OK
    void** pp7 = (void*)NULL;  // OK

    //void** pp8 = (int**)NULL;  // warn
}