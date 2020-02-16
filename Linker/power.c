#include "power.h"

int power(int a,int b){
	int i;
	int multiply=1;
	for (i=0;i< b;i++){
		multiply *= a;
	}
	
	return multiply;
}

