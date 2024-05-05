#include<iostream>
using namespace std;

class X {
private:
    int i_;
public:
    explicit X(int i): i_{i} {
        cout << "con\n";
    }
    explicit X(X const &x): i_{x.i_} {
        cout << "copy\n";
    }
};
int main() {
    X x1(1);
    X x2{1};
    //X x3 = (1);
    X x4 = {1};
    X x5 = X(1);
    X x6 = X{1};
}