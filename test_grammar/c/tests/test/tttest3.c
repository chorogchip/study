#include<stdio.h>
int main(int i){scanf("%d",&i);i<<=24;for(i|=1;i^256;i*=2)putchar('0'|i<0);}
