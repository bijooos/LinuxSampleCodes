#include <stdio.h>
#include <pthread.h>

 int done = 0;

 pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
 pthread_cond_t c = PTHREAD_COND_INITIALIZER;

 void thr_exit() 
{
	 pthread_mutex_lock(&m);
	 printf("thread %lu got the lock\n", pthread_self());
//	 sleep(3);
	 done = 1;
	 pthread_cond_signal(&c);
	 pthread_mutex_unlock(&m);
	 printf("thread %lu  unlocking\n", pthread_self());
 }

void *child(void *arg) 
{
	sleep(1);
	printf("child\n");
	thr_exit();
	return NULL;
}

void thr_join() 
{
	pthread_mutex_lock(&m);
	printf("main thread %lu got the lock\n", pthread_self());
	while (done == 0)
	{
		sleep(5);
		pthread_cond_wait(&c, &m);
	}
	pthread_mutex_unlock(&m);
	printf("main thread %lu  unlocking\n", pthread_self());
}

int main() 
{
	printf("parent: begin\n");
	pthread_t p1;
	pthread_create(&p1, NULL, child, NULL);
	thr_join();
	printf("parent: end\n");

	return 0;
}
