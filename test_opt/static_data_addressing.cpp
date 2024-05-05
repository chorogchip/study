#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;

int a, b[100];


__attribute_noinline__ void f(int *b) {
    for (int i = 0; i < 100; ++i)
    {
        b[i] = a % 3;
    }
}

int main() {
    int d;
    int e[100];
    scanf("%d", &d);
    a = d;
    e[d] = 1;
    f(e);
    f(e);
}