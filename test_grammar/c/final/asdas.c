#include <stdio.h>
#include <limits.h>
int main(void) {
    double d = __DBL_MAX__;
    scanf("%f", &d);
    printf("%f", d);
}