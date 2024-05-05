#pragma GCC target ("avx")
#include <stdio.h>
int main()
{
    int i;
    float f;
    scanf("%d", &i);
    f = (float)i;
    printf("%f", f);
}