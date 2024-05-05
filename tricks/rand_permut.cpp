#include<bits/stdc++.h>
using namespace std;

int rand(int beg, int end) {
    float rd = (float)rand() / (float)(RAND_MAX+1LL);
    return rd * (float)(end - beg) + (float)beg;
}

int main() {

    int k = 10;
    int* D = new int[k];
    for (int i = 0; i < k; ++i) D[i] = i;
    for (int i = 0; i < k; ++i) {
        swap(D[i], D[rand(i, k)]);
        cout << D[i] << '\n';
    }


}