#include <stdio.h>
#include <pthread.h>

void free_all(void *arg)
{
	void *ptr = arg;
	if (ptr)
	{
		free((int *)ptr);
		ptr = NULL;
	}
	printf("freed\n");
}

void *thrd_func(void *args)
{
	int *ptr = NULL;

	pthread_cleanup_push(free_all, ptr);

	ptr = malloc(100);
	sleep(4);

	pthread_cleanup_pop(0);			/* Try with 1 as arg */
	free_all(ptr);

	return NULL;
}

int main()
{
	pthread_t tid1, tid2, tid3;

	pthread_create(&tid1, NULL, thrd_func, NULL);

	sleep(2);
	pthread_cancel(tid1);
	pthread_join(tid1, NULL);

	return 0;
}
