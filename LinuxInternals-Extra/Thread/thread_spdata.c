#include <pthread.h>
#include <stdio.h>

pthread_key_t data_key;
void *thread1(void *arg)
{
	int setdata = 10;

	pthread_setspecific(data_key, &setdata);
	int *get_value = (int *)pthread_getspecific(data_key);
	printf("Thread1 value = %d\n", *get_value);
}
void *thread2(void *arg)
{
	int get_value = (int )pthread_getspecific(data_key);
	printf("Thread2 value = %d\n", get_value);
}

int main()
{

	pthread_t th1, th2;

	pthread_key_create(&data_key, NULL);

	pthread_create(&th1, NULL, thread1, NULL);
	pthread_create(&th2, NULL, thread2, NULL);

	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
}


