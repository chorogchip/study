#include<stdio.h>

int fib(int n) {
	if (n <= 1) return n;
	else return fib(n-1) + fib(n-2);
}

int main(void) {
	printf("%d", fib(5));
	return 0;
}
