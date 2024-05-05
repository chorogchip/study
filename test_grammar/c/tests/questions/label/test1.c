#include<stdio.h>

int main(void) {
	int i;
    for (i = 0; i < 5; ++i) {
		if (i == 3) goto L;
		printf("%d ", i);
	}
	return 0;
}
