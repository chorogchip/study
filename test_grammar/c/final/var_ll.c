#include <stdio.h>
#include <stdarg.h>

long long asd(int n, ...) {
    va_list a;
    long long sum = 0LL;
    va_start(a, n);
    for (int i = 0; i < n; ++i) {
        sum += va_arg(a, long long);
    }
    va_end(a);
    return sum;
}

int main(void) {
    long long sum = asd(3, 3000000000000LL, 2, 5L);
    printf("%lld", sum);
}

#if defined(asd)
    int a = 1;
#elif 2
    int a = 2;
#endif