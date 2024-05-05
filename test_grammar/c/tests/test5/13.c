#include<stdio.h>

int aa(int a, int b) {
	return a + b;
}

int main(void) {
	int i = 1;
	int arr[aa(i,-2)];
	arr[0] = 1;
	printf("%d\n", arr[0]);
}
	
