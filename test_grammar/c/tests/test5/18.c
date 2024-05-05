#include<stdio.h>

int main(void) {
	int i = (1<<30)+1;
	printf("%d\n", i);
	float f = (float)i;
	printf("%f\n", f);
	int ii = (int)f;
	printf("%d\n", ii);
	return 0;
}
