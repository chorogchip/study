#include<iostream>
#include<vector>
using namespace std;

constexpr char c1 = 'A', c2 = 'B';
typedef vector<char> vec;
int main() {
    vec v1(c1);
    cout << v1.size() << v1[0] << endl;  // 65
    vec v2{c1};
    cout << v2.size() << v2[0] << endl;  // 1A
    vec v3(c1, c2);
    cout << v3.size() << v3[0] << endl;  // 65B
    vec v4{c1, c2};
    cout << v4.size() << v4[0] << endl;  // 2A
    vec v5({c1, c2});
    cout << v5.size() << v5[0] << endl;  // 2A
    vec v6{{c1, c2}};
    cout << v6.size() << v6[0] << endl;  // 2A
    vec v7({{c1, c2}});
    cout << v7.size() << v7[0] << endl;  // 2A
    //vec v8{{{c1, c2}}};
    //cout << v8.size() << v8[0] << endl;  // compile error
}