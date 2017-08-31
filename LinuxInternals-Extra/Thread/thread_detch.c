#include <stdio.h>
#include <pthread.h>

void* thread_function (void* thread_arg)
{
	int i = 100000;
	while(i--)	/* Do work here... */
	{
		fputc('A', stderr);
	}
}

int main ()
{
	pthread_attr_t attr;
	pthread_t thread;
	pthread_attr_init (&attr);
	pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_DETACHED);
	pthread_create (&thread, &attr, &thread_function, NULL);
//	sleep(1);
	//pthread_attr_destroy (&attr);
	/* Do work here... */
	/* No need to join the second thread. */
	return 0;
}
