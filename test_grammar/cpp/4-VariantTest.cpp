#include<iostream>
#include<variant>
using namespace std;

template<int sz>
struct st {
    variant<int,char[sz]> v;
    static constexpr size_t siz = sizeof(v);
};

#define a(X) static_assert(st<(X)>::siz == (X) + 4UL);

int main() {
    a(100)
    a(300)
    a(1224)
    a(312)
    a(252)
}