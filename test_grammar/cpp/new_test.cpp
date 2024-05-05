
#include <stdio.h>

struct S
{
    int a;
};

int main() {
    for (int c = 0; c < 10000; ++c)
    {
        S* s = new S[100];
        for (int i = 0; i < 100; ++i) if (s[i].a != 0) puts("asdasd");
        delete[] s;
    }
}

