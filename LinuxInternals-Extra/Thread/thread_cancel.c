#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

void *thread_function(void *arg);
int glob;
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
	pthread_join(a_thread, NULL);
	printf("glob = %d\n", glob);
	exit(EXIT_SUCCESS);
}

void *thread_function(void *arg)
{
	int i, res; 
	glob = 111;
	res = pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
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
