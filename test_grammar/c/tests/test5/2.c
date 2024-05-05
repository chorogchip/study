#include<stdio.h>

int asd;

int asd(void) {
	printf("asd\n");
	return 2;
}

int main(void) {
	asd = asd();
	printf("%dn", asd);
	printf("%dn", asd());
	return 0;
}
