#include<stdio.h>
#include<string.h>

int main(void) {
	char arr[10];
	arr[3] = '\n';
	arr[0] = 'a';
	strcat(arr, "as");
	printf(arr);
}
