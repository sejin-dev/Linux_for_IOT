#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

void main(){
	pid_t pid;
	int i=0;
	i++;
	printf("before calling fork(%d)\n", i); // i=1 

	pid = fork();

	if(pid ==0){ 
		//baby process 
		for( int j=0;j<10;j++){	
		printf("child process(%d)\n",++i);
		usleep(1000000);	
		}	
	}
	else if(pid>0)
		//parents process
		for(int k=0;k<10;k++){
		printf("parent process (%d)\n", i+=2);
		usleep(1000000);
		}
	else
		
		//if fail to call
	printf("fail to fork\n");
}

