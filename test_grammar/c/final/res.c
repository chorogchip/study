#include <stdio.h>

int main(void) {
    char str[256];
    scanf("%[^\n]", str);
    printf(str);
    getchar();
    scanf("%[^\n]", str);
    printf(str);
}