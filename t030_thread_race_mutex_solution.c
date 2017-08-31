/*------------------------------------------------------------------------------ 
 *
 *   Author         : Emertxe (http://www.emertxe.com) 
 *   Date           : Thu 12 May 2016 15:59:19 IST
 *   File           : t030.c
 *   Title          : POSIX threads (pThread) - Mutex usage for race conditions 
 *   Description    : Threads are prone to race conditions due to shared data 
 *                    problem. One of the way race conditions can be avoided 
 *                    by using mutex by protecting shared data, as shown below.
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
pthread_mutex_t lock;

void* thread_function(void *arg)
{
    pthread_mutex_lock(&lock);
    counter += 1;
    printf("\nJob %d started\n", counter);
	sleep (2);
    printf("\nJob %d finished\n", counter);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(void)
{

    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\nPthread: mutex init failed\n");
        return 1;
    }

   pthread_create(&thread_1,NULL,thread_function,NULL);
   pthread_create(&thread_2,NULL,thread_function,NULL);

   pthread_join(thread_1,NULL);
   pthread_join(thread_2,NULL);
   pthread_mutex_destroy(&lock);
   return 0;
}
