#include <iostream>
int main() {
    unsigned a = 4294967295;
    int b =  -1;
    long c = -1;
    std::cout << (a==b) << (b==c) << (c==a);
}