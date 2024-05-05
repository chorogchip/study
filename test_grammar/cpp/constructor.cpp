#include <iostream>
#include <string>
using namespace std;
struct S1 { int a, b; };
struct S2 { int a, b; S2() = default; };
struct S3 { int a, b; S3(){} };
ostream &operator<<(ostream &o, S1 &s) { o << s.a << ' ' << s.b << ' '; return o; }
ostream &operator<<(ostream &o, S2 &s) { o << s.a << ' ' << s.b << ' '; return o; }
ostream &operator<<(ostream &o, S3 &s) { o << s.a << ' ' << s.b << ' '; return o; }
int main() {
    S1 t1_1; S2 t1_2; S3 t1_3;
    cout << t1_1 << t1_2 << t1_3 << endl;
    S1 t2_1{}; S2 t2_2{}; S3 t2_3{};
    cout << t2_1 << t2_2 << t2_3 << endl;
    S1 t3_1{1};
    cout << t3_1 << endl;
}