#include <stdio.h>
int main(void){
	int m, n;
	printf("n^m 계산 프로그램\n");
	printf("n : ");
	scanf("%d", &n);
	printf("m : ");
	scanf("%d", &m);
	printf("%d^%d = %.3lf\n", n, m, power_r(n, m));
	return 0;
}
int power_r(float n, int m){
	int i;
	double pow = 1.0;
	for (i = 0; i < m; ++i)
		pow *= n;
	return pow;
}
