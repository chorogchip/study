#include<iostream>
#include<any>
using namespace std;
typedef any let;
struct CC {
    template<typename T>
    void log(const T& t) {
        cout << t << endl;
    }
    void log(any a) {
        try {
            int i = std::any_cast<int>(a);
            cout << i << endl;
        } catch (const bad_any_cast& e) {
        try {
            float i = std::any_cast<float>(a);
            cout << i << endl;
        } catch (const bad_any_cast& e) {
        try {
            long long i = std::any_cast<long long>(a);
            cout << i << endl;
        } catch (const bad_any_cast& e) {
        try {
            double i = std::any_cast<double>(a);
            cout << i << endl;
        } catch (const bad_any_cast& e) {
        }}}}
    }
} console;
int operator+(const any& a, int b) {
    return std::any_cast<int>(a) + b;
}

int main() {
    let a = 1;
    a.type();
    console.log(a);
    a = 2;
    console.log(a + 3);
    a = 2.3;
    console.log(a);
}