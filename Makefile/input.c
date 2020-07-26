#include<stdio.h>

char *input(){
	static char *str, a[32];
	str = a;
	printf("Plz Enter input value:");
	scanf("%s",a);

	return str;
}

