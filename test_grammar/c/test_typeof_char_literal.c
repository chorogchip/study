#include<stdio.h>
/*void f(int i) {
    printf("int\n");
}
void f(char i) {
    printf("char\n");
}*/  // error
int main(void) {
    printf("%d\n", sizeof('a'));  // 4
}