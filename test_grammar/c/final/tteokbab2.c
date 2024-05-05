#include <stdio.h>

int main(void) {
    char str[] = "%c%d";
    scanf(str, str+2, str+1);
    printf(str, str+2, str+1);
}