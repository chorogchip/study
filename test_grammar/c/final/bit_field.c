#include <stdio.h>

typedef struct {
    unsigned int a:1, b:1, c:1, d:1;
} SA;
typedef struct {
    unsigned int a:8, b:8, c:8, d:8;
} SB;

int main(void) {
    SA sa;
    SB sb;
    *(unsigned*)&sa = 0;
    *(unsigned*)&sb = 0;
    sa.a = 1;
    sb.b = 0xff;
    printf("%x %x", *(unsigned*)&sa, *(unsigned*)&sb);
}