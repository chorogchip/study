#include <stdio.h>

int main(void) {
    long double d = 1.0L;
    if (d > 0.5L)
    {
        d = 2.0L;
    }
    double d2 = d;
    d2 += 3.0;
    if (d2 > 4.0) d2 = 5.0;
    int i = d2;
    printf("%d", i);
}