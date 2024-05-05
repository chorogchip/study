#include<stdio.h>
int main(){int i;printf("-128부터 127까지의 십진수 정수 하나를 입력하세요 :");scanf("%d",&i);printf("%d의 이진수는 ",i);i<<=24;i|=1;while(putchar('0'+(i<0)),i&8&&printf(" "),(i<<=1)^256);puts(" 입니다.");}
