#include <bits/stdc++.h>

int main(void) {
    int c[100];
    memset(c, 0, sizeof(c));

    scanf("%5d", c);

    for (int i = 0; i < sizeof(c)/sizeof(c[0]) && c[i] != 0; ++i)
        printf("%d\n", c[i]);
}