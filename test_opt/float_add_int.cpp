#include<stdio.h>

int main()
{
    while (true) {
        float f;
        int i;
        scanf("%f%d", &f, &i);
        *(int*)&f += i << 23;
        printf("%f\n", f);
    }
}