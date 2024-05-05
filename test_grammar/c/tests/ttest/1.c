#include <stdio.h>
#include <string.h>

int main(void) {
	char lastname[20], name[6];
	strcpy(name, "James");
	printf("1. %s\n", name);

	strcpy(lastname, "abcdefghijklmn");
	strcpy(name, lastname);
	printf("2. %s\n", name);
	printf("3. %s\n", lastname);
	return 0;
}
