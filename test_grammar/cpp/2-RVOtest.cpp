#include<iostream>
using namespace std;

struct A {
    int i;
    A(int i): i(i) { cout << "construct " << i << endl; }
    A(const A&) { cout << "copy " << i << endl; }
    ~A() { cout << "delete " << i << endl; }
};
A foo() {
    A a(2);  // construct 2
    a.i = 3;
    return a;
}  // a is not deleted
A foo2(int i) {
    if (i == 0) {
        A a(2);  // construct 2
        return a;
    } else {
        A a(3);  // construct 3
        return a;
    }
}  // a is deleted
int main() {
    cout << "first" << endl;
    {
        A b = foo();  // not constructed, not copyed
        b.i = 4;
    }  // delete 4
    cout << "second" << endl;
    {
        A c = foo2(0);  // copyed
        c.i = 4;
    } // delete 4
}
/*
first
construct 2
delete 4
second
construct 2
copy4
delete 2
delete 4
*/