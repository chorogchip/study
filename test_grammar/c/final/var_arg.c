#include <stdio.h>
#include <stdarg.h>

#define ASD(...) printf("asd" __VA_ARGS__)

int main(void) {
    ASD(" sad%d", 123);
    printf("%d|", 21000000001LL);
    printf("%5.1f", -1.25f);
}