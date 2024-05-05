#include<stdio.h>

int asd() {
	int a = 3;
	return;
}

int main(void) {
	int asdf = 6;
	asdf = asd();
	printf("%d\n", asdf);
	return 0;
}
