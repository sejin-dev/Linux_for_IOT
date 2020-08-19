#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

void cleanupaction(void);

void main(void)
{
	pid_t pid;
	int i;

	for(i=0;i<3;i++)
	{
		printf("before fork[%d] \n",i);
		sleep(1);
	}					
	// now, i= 3
	pid = fork();

	if(pid > 0 ) // parent process
	{
		for( ; i<7; i++) // i=3~6
		{
			printf("parent [%d] \n",i);
			sleep(1);
		}
		atexit(cleanupaction);
	}

	else if(pid ==0) // child process 
	{
		for( ; i<6; i++)  // i= 3~4.  action 2times 
		{
			printf("child %d \n", i);
			sleep(1);
			execl("/bin/ls", "ls", "-l", (char *)0); // exit existing process and start new process 
		}
	}
	else{
	       	printf("fail to fork child process \n"); 
	}
	
	exit(0); // END main process
}

void cleanupaction(void){
	printf("clean up action\n");
}
