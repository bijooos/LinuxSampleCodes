#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;

void *thrd_func(void *args)
{
	while (1)
	{
		sem_wait(&sem);
		/* Do something */
		printf("Taken semaphore by %lu\n", pthread_self());
	}
}

void *producer_func(void *args)
{
	while (1)
	{
		sleep(3);
		printf("Semaphore adding by %lu\n", pthread_self());
		sem_post(&sem);
	}
}

int main()
{
	pthread_t tid0, tid1, tid2;

	sem_init(&sem, 0, 1);

	pthread_create(&tid0, NULL, thrd_func, NULL);
	pthread_create(&tid1, NULL, producer_func, NULL);
	pthread_create(&tid2, NULL, thrd_func, NULL);

	pthread_join(tid0, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	return 0;
}
