#include <stdio.h>
#include "power.h"

void main(void){
	int a,b;
	printf("Enter two numbers for power:");
	scanf("%d %d", &a,&b);
	
	printf(" resulf:%d\n", power(a,b));
}
