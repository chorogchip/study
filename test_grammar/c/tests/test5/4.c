#include<stdio.h>

void asd() {
	return 1;
}

int main(void) {
	int a = 3;
	a = asd();
	printf("%d\n", a);
	return 0;
}
