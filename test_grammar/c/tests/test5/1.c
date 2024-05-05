#include<stdio.h>
int main(void) {
	int sum;
	for (sum = 0, int i = 0; i <= 5; ++i)
		sum += i, printf("%d\n", sum);
	return 0;
}
