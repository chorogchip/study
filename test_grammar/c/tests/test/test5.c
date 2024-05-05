#include<stdio.h>
int main(void)
{
	int grade=150;
	if(0<=grade&&grade<=100)
		if(grade<60)
			printf("f .\n");
		else
			printf("wr .\n");
	return 0;
}
