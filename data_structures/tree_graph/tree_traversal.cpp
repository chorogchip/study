#include <iostream>
using namespace std;

int N;
char C, Crr[27 * 6], *P = Crr, *PP = P, Vrr[30], *V = Vrr;
struct Tree {
    char l, r;
} T[128];

inline void pre_order() {
    C = 'A';
    while (true) {
        if (C != '.') {
            *P = C; ++P;
            *V = T[C].r; ++V;
            C = T[C].l;
        } else if (V != Vrr) {
            C = *--V;
        } else break;
    }
    *P++ = '\n';
}

inline void in_order() {
    C = 'A';
    while (true) {
        if (C != '.') {
            *V = C; ++V;
            C = T[C].l;
        } else if (V != Vrr) {
            C = *--V;
            *P = C; ++P;
            C = T[C].r;
        } else break;
    }
    *P++ = '\n';
}

inline void post_order() {
    char *p2 = P += N;
    C = 'A';
    while (true) {
        if (C != '.') {
            *--p2 = C;
            *V = T[C].l; ++V;
            C = T[C].r;
        } else if (V != Vrr) {
            C = *--V;
        } else break;
    }
    *P++ = '\n';
}

int main() {

    N = getchar() - '0';
    while ((C = getchar()) != '\n') {
        N *= 10;
        N += C - '0';
    }
    fread(Crr, 1, N*6, stdin);
    PP += N*6;
    do {
        C = P[0];
        T[C].l = P[2];
        T[C].r = P[4];
        P += 6;
    } while (P != PP);
    P = Crr;
    
    pre_order();
    in_order();
    post_order();

    fwrite(Crr, 1, P - Crr, stdout);
}