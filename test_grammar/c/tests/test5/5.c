#include<stdio.h>

int main(void) {
	int a = 3;
	int b = 5;
	int c = add(a, b);
	printf("%d\n", c);
	return 0;
}

int add(float a, int b) {
	return a - b;
}
