#include<iostream>
using namespace std;

class X {
public:
    int i;
    //X() = default;
};
int main() {
    X x;
    cout << x.i << endl;
}