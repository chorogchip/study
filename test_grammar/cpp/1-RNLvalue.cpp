#include<iostream>
using namespace std;

struct A {
    A() {}
    A(const A& a) { cout << "A&\n"; }
    A(A&& a) { cout << "A&&\n"; }
};
void foo(A&& a) {
    A b = a;  // A&
    A c = move(a);  // A&&
}
int main() {
    foo(A{});
}

