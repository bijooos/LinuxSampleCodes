#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;

void fun(int a)
{
	pthread_mutex_lock(&mutex);
	printf("taking lock %lu\n", pthread_self());
	while (a > 0)
	{
		fun(--a);
	}
	printf("releasing lock %lu\n", pthread_self());
	pthread_mutex_unlock(&mutex);
}

void *thrd_func(void *args)
{
	fun(2);
}

int main()
{
	pthread_t tid1, tid2, tid3;
	pthread_mutexattr_t attr;

	pthread_mutexattr_init(&attr);
	pthread_mutexattr_setkind_np(&attr, PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&mutex, &attr);

	pthread_create(&tid1, NULL, thrd_func, NULL);
	pthread_create(&tid3, NULL, thrd_func, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid3, NULL);

	return 0;
}
