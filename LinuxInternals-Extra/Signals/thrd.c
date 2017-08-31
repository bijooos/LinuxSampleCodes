#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <signal.h>

void sig_func(int sig)
{
	printf("Caught signal: %d\n",sig);
	printf("My thread id is %d\n", (int)pthread_self());
}

void *func(void *p)
{
	alarm(5);
	printf("This is from thread function %d\n", (int)pthread_self());
	signal(SIGALRM,sig_func); // Register signal handler inside thread
	while(1); // Sleep to catch the signal
}

int main()
{
	pthread_t tid;
	pthread_attr_t attr;

	printf("Parent thread id is %d\n", (int)pthread_self());
	pthread_attr_init(&attr);
	pthread_create(&tid,&attr,func, NULL);
	sleep(1);
	pthread_join(tid, NULL);
}
