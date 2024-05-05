#include<iostream>
#include<cstring>
using namespace std;

class CharArr10 {
private:
    char arr[10];
public:
    CharArr10() {
        memset(arr, 0, sizeof(arr));
    }
    CharArr10(const CharArr10& a) {
        memcpy(arr, a.arr, sizeof(arr));
    }
    const char& operator[](size_t index) const {
        return arr[index];
    }
    char& operator[](size_t index) {
        return const_cast<char&>(
            static_cast<const CharArr10&>(*this)[index]
        );
    }
    friend std::ostream& operator<<(std::ostream& out, const CharArr10& arr);
};
std::ostream& operator<<(std::ostream& out, const CharArr10& arr) {
    out << arr.arr << std::endl;
    return out;
}
int main() {
    CharArr10 a = {};
    a[0] = 'A';
    a[1] = a[0];
    CharArr10 b = {a};
    b[0] = 'B';
    const CharArr10 c = {a};
    //c[0] = 'C';  // error
    std::cout << a;
    std::cout << b;
    std::cout << c;
}