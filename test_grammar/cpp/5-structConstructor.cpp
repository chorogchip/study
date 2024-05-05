#include<iostream>
using namespace std;

enum class E {A, B};
struct A {
    //A(const A&) = default;
    int x;
    int y;
    E ee;
    string ss;
    A(int xx, int yy, E eee, string ssss): x(xx), y(yy), ee(eee), ss(ssss) {}
};

ostream& operator<<(ostream& ostr, const A& a) {
    ostr << a.x << ' ' << a.y;
    return ostr;
}

struct B {
    A a;
};

int main() {
    A a{1, 1, E::A, "sad"};
    A b = a;
    cout << b.x << b.y << (int)b.ee << b.ss;
}