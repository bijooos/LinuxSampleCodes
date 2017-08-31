/*------------------------------------------------------------------------------ 
 *
 *   Author         : Emertxe (http://www.emertxe.com) 
 *   Date           : Thu 12 May 2016 15:59:19 IST
 *   File           : t031.c
 *   Title          : POSIX threads (pThread) - Semaphore usage
 *   Description    : Threads are prone to race conditions due to shared data 
 *                    problem. One of the way race conditions can be avoided 
 *                    by using semaphores by protecting shared data, as shown
 *                    below.
 *
 *----------------------------------------------------------------------------*/
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>


sem_t count;

void* fun (void * parm)
{
	int k = 5;
	int value;

	sem_wait(&count);
	/* Entering critical section */
	sem_getvalue(&count,&value);
	printf("The semaphore count before loop: %d\n",value);
	while(k)
	{
		printf("Inside loop, Value of K=%d",k);
		k--;
		sleep(1);
	}
	sem_post(&count);
	/* Exiting critical section */
	sem_getvalue(&count,&value);
	printf("The semaphore count after loop: %d\n",value);
		 
}

int main()
{
	int i;
	pthread_t tid[5];

	sem_init(&count, 0, 3);

	for(i=0; i<3; i++)
		pthread_create (&tid[i], NULL, &fun, NULL);

	for(i=0; i<3; i++)
		pthread_join(tid[i], NULL);

	/*
	 * TODO:  1. Change the value of loop index (i) to 5 and see change in print pattern
	 *        2. Change the semaphore initial value to 5 and see change in print pattern
	 *        3. Change the semaphore initial value to 2 and see change in print pattern
	 *        4. Change the semaphore initial value to 1 (Binary Mutex) and see change in print pattern
	 */

	return 0;
}
