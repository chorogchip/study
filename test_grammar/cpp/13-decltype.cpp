#include<iostream>
using namespace std;
#include<string>
#include<type_traits>

int main() {
    string str = "hello";
    for (auto &o : str) o = static_cast<remove_reference<decltype(o)>::type>('x');
    cout << str << endl;
}