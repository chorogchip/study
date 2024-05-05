#include<iostream>

struct S {
    int const &i;
    S(int const &r):i(r){}
};

int main(void) {
    int *a = new int();
    *a = 3;
    S s(3);
    delete a;
    std::cout << s.i << std::endl;
}