#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define MUTEX_ENABLE 0

pthread_t tid[2];
int jobIndex = 0; //순차적으로 증가
pthread_mutex_t lock;

void* doSomeThing(void *arg)
{
 #if MUTEX_ENABLE // è mutex을 사용했을 경우
 pthread_mutex_lock(&lock); // è lock으로 다른 스레드의 동시 수행 차단
 #endif
 unsigned long i = 0;
 jobIndex += 1;
 printf("\n Job %d started\n", jobIndex);
 for(i=0; i<(0xFFFFF);i++); // delay
 printf("\n Job %d finished\n", jobIndex);
 #if MUTEX_ENABLE
 pthread_mutex_unlock(&lock); // 다른 스레드가 수행할수 있도록 lock 해제
 #endif
 return NULL;
}

int main(void)
{
 int i=0;
 int err;
 if (pthread_mutex_init(&lock, NULL) != 0)
 {
  printf ("\n Mutex Init Failed!!\n");
  return 1;
 }
 while (i<2)
 {
  err = pthread_create(&(tid[i]), NULL, &doSomeThing, NULL);
  if (err != 0)
  printf ("Thread Create Error: [%d]\n", err);
  i++;
 }


 pthread_join (tid[0], NULL);
 pthread_join (tid[1], NULL);
 return 0;
}


