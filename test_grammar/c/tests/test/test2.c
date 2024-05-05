#include <stdio.h>

int fn(void)
{
	return 1;
}
int main(void)
{
	int fn = 1;
	printf("%d", fn);
	fn();
	return 0;
}
