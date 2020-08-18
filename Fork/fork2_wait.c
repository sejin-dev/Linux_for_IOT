#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>

#include <sys/wait.h>


#define WAIT_FOR_CHILD

void main(){
	pid_t pid;
	int i=0;
	int status;
	i++;
	printf("before calling fork(%d)\n", i); // i=1 

	pid = fork();

	if(pid ==0){ 
		//baby process 
		for( int j=0;j<10;j++){	
		printf("child process(%d)\n",i++);
		usleep(1000000);	
		}	
		exit(1234);
	}
	else if(pid>0)
	{
		//parents process
		printf("parents process is waiting........\n");
		
		#ifdef WAIT_FOR_CHILD
		wait(&status);
		#endif
		
		for(int k=0;k<10;k++){
		printf("parent process (%d)\n", i+=2);
		usleep(1000000);
		}
	}
	else
	{
		//if fail to call
	printf("fail to fork\n");
	}
}

