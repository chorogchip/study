#include<stdio.h>

void sum_nums(int num1, int num2);

int main()
{
    int (*sumltr)(int, int) = (int(*)(int, int))sum_nums;
    int result = (*sumltr)(2, 3);
    printf("%d\n", result);
    return 0;
}

void sum_nums(int num1, int num2) {
    return (num1 + num2);
}