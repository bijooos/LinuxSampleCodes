#include <stdio.h>
#include <pthread.h>
#include <errno.h>

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

void *thrd_func(void *arg)
{
	if (pthread_mutex_trylock(&mut) == EBUSY)
	{
		printf("%lu: Mutex already Locked\n", pthread_self());
	}
	else
	{
		printf("Mutex was free.. So I (%lu) taken\n", pthread_self());
		sleep(5);

		pthread_mutex_unlock(&mut);	
	}
}

int main()
{
	pthread_t tid1, tid2;

	pthread_create(&tid1, NULL, thrd_func, NULL);
	pthread_create(&tid2, NULL, thrd_func, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	return 0;
}
