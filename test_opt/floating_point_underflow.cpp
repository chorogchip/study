#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    double f = 1.0;
    for (int i = 0; i < 1100; ++i) {
        f *= 0.5;
        unsigned long ul = *(unsigned long*)&f;
        printf("%.500f %01lx %03lx %013lx\n", f, ul>>63UL, ul<<1UL>>53UL, ul<<12UL>>12UL);
    }
}
// ??