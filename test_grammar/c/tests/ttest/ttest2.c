#include<stdio.h>

int main(void) {
	int a = 1;
	a = a++ + a++;
	printf("%d\n", a);
	return 0;
}
