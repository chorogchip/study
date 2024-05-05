#include<bits/stdc++.h>
using namespace std;

struct S {
    int a;
    int b;
};

ostream &operator<<(ostream &ostr, S const &s) {
    ostr << s.a << ' ' << s.b;
    return ostr;
}

S s7;
S s8{1};

int main() {
    S s;
    cout << s << endl;
    S s2{1};
    cout << s2 << endl;
    S s3 = {1};
    cout << s3 << endl;

    unsigned char buf[100];
    memset(buf, (unsigned char)-1, sizeof(buf));

    S *s4 = new(buf) S;
    cout << *s4 << endl;
    S *s5 = new(buf+10) S{1};
    cout << *s5 << endl;
    
    cout << s7 << endl;
    cout << s8 << endl;

    S s9 = S();
    cout << s9 << endl;
}