#include <stdio.h>

extern void print(char *);
extern char* input();


void main(void){
	char* str = input();
	print(str);
	
}

