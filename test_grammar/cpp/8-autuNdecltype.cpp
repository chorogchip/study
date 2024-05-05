#include<iostream>
using namespace std;

template<typename T1, typename T2>
auto max1(T1 t1, T2 t2) {
    return t1 > t2 ? t1 : t2;
}
template<typename T1, typename T2>
auto max2(T1 t1, T2 t2) -> decltype(t1 > t2 ? t1 : t2) {
    return t1 > t2 ? t1 : t2;
}

int main() {
    int i = 2;

    auto i2 = i;  // int
    decltype(i) i3 = i;  // int
    auto i4 = (i);  // int
    decltype((i)) i5 = i; // int&
    auto i6 = 1?i:i;  // int
    decltype(1?i:i) i7 = 1?i:i;  // int&
    
    int a = 1;
    int b = 2;
    int c = 3;
    (c == 3 ? a : b) = 4;
    cout << a << b << endl;

    // 삼항 연산자의 결과값이 lvalue가 될수도 있다.
}