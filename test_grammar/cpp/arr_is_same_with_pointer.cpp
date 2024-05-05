#include<iostream>
#include<type_traits>

int f(const char arr[]) {
    static_assert(std::is_same_v<const char*, decltype(arr)>);
    return 1;
}

int main() {
    char arr[1];
    std::cout << f("arr") << std::endl;
}