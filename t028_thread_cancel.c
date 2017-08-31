/*------------------------------------------------------------------------------ 
 *
 *   Author         : Emertxe (http://www.emertxe.com) 
 *   Date           : Thu 12 May 2016 15:59:19 IST
 *   File           : t028.c
 *   Title          : POSIX threads (pThread) - Thread cancellation 
 *   Description    : Threads offer multiple options to set attributes, using 
 *                    which multi-tasking can be achieved more effectively. One 
 *                    of them being thread cancellation,demonstrated here. 
 *
 *----------------------------------------------------------------------------*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

void *thread_function(void *arg);

int main()
{
	int res;
	pthread_t a_thread;
	void *thread_result;

	res = pthread_create(&a_thread, NULL, &thread_function, NULL);
	if(res != 0)
	{
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}

	sleep(3);
	printf("Cancelling thread...\n");
	res = pthread_cancel(a_thread);
	if(res != 0)
	{
		perror("Thread Cancellation failed");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

void *thread_function(void *arg)
{
	int i, res; 
	res = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	if(res != 0)
	{
		perror("Thread pthread_setcancelstate failed");
		exit(EXIT_FAILURE);
	}
	printf("Thread_fuction is still running\n");
	for(i = 0; i < 10; i++)
	{
		printf("\nThread function is running (%d)...\n", i);
		sleep(1);
	}
	pthread_exit(0);
}
