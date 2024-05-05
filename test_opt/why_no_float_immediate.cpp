#pragma GCC target("sse4")
#include <stdio.h>

int main(void) {
    float a = 3.0f;
    float b;
    scanf("%f", &b);
    printf("%f", (a + b) * 0.5f);
    
    int c;
    int d;
    scanf("%d", &c);
    scanf("%d", &d);
    printf("%d", c + d);
    return 0;
}