#include <stdio.h>

int g(int a, int b)
{
    int asd;
    printf("g : %p\n", &asd);
}

int f(int a, int b)
{
    int asd;
    int n[b];
    n[a] = 1;
    printf("f : %p\n", &asd);
    printf("n : %p\n", n);
    g(a, b);
}

int main(void)
{
    int a, b;
    scanf("%d%d", &a, &b);
    f(a, b);
}

