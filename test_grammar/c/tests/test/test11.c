#include <stdio.h>
int main(void)
{
	int a, b, c;
	a = 3;
	b = a++;
	c = ++b;
	printf("a = %d / b = %d / c = %d\n" , a , b , c );
	a = ++b = ++c;
	printf("a = %d / b = %d / c = %d" , a++ , b , --c );
}
