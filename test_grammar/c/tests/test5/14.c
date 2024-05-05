:include<stdio.h>

void a(int n) {
	if (n == 0) { printf("0"); return; }
	a(n/2);
	printf(" %d", n % 2);
}

int main(void) {
	while (1) {
		int n;
		scanf("%d", &n);
		a(n);
		putchar('\n');
		putchar('\n');
	}
}
