#include <stdio.h>

long double f(long double a, long double b) {
    long double c = a + b;
    long double c2 = a - b;
    long double c3 = a * b;
    long double c4 = a / b;
    double d = c;
    d += 2.0;
    return d + c2 + c3 + c4;
}

int main(void) {
    double d = f(2.0L, 4.0L);
    d += 1.0;
    printf("%lf", d);
}