#include<stdio.h>

constexpr int szld = sizeof(long double);

union Un {
    long double ld;
    unsigned char arr[szld];
};

int main(void) {
    printf("%d\n", szld);
    Un un;
    un.ld = -1.0L;
    for (int i = szld - 1; i >= 0; --i)
        printf("%x ", un.arr[i]);
    printf("\n%Lf\n", un.ld);
    for (int i = szld - 1; i >= 0; --i)
    {
        un.arr[i] = 100;
        printf("%Lf\n", un.ld);
    }
    un.ld = -1.0L;
    for (int i = szld - 1; i >= 0; --i)
        printf("%x ", un.arr[i]);
}