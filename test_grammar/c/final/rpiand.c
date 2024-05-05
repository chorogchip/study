#include <stdio.h>
int main(void){
    int n, a;
    a = printf("abcdef\b\b\ba%n\n", &n);
    printf("%d %d", n, a);
    return 0;
}