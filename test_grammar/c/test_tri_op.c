#include<stdio.h>
int main(void) {
    int a = 1, b = 2, *pa = &a, *pb = &b;
    //(0?*pa:*pb) = 3;  // error
    printf("%d %d %d %d", a, b, *pa, *pb);
}