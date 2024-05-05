#include<stdio.h>
int main(void) {
	int i = 3;
	for (int i = (printf("%d\n", i), 10); printf("%d\n", i);) {
		printf("%d\n", i);
		int j = ++i;
		printf("%d\n", i);
		int i = ++i;
		printf("%d\n", i);
		break;
	}
	printf("%d\n", i);
}
