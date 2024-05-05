#include<stdio.h>
void main(void) {
	int a = 3;
	int b = 5;
	int c = 7;
	int *d = &c;
	int f = a = *d = b;
	printf("%d %d %d %d %d\n", a, b, c, d, f);
}
