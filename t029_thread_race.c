/*------------------------------------------------------------------------------ 
 *
 *   Author         : Emertxe (http://www.emertxe.com) 
 *   Date           : Thu 12 May 2016 15:59:19 IST
 *   File           : t029.c
 *   Title          : POSIX threads (pThread) - Race conditions 
 *   Description    : Threads are prone to race conditions due to shared data 
 *                    problem. Here is an example of global variable being the
 *                    reason for race condition. 
 *
 *----------------------------------------------------------------------------*/
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t thread_1;
pthread_t thread_2;
int counter;

void* thread_function(void *arg)
{
    counter += 1;
    printf("\nJob %d started\n", counter);
	sleep(2);
    printf("\nJob %d finished\n", counter);
    return NULL;
}

int main(void)
{

   pthread_create(&thread_1,NULL,thread_function,NULL);
   pthread_create(&thread_2,NULL,thread_function,NULL);

   pthread_join(thread_1,NULL);
   pthread_join(thread_2,NULL);

   return 0;
}
