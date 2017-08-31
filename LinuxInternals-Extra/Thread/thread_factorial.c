#include<pthread.h>
#include<stdio.h>

struct fact_params
{
	int count;
};

void* fact(void* parameters)
{
	struct fact_params* p = (struct fact_params*)parameters;
	int value, i, factorial = 1;
	int *pp;
	if(p->count == 0)
		value = 1;
	else
	{
		for(i = 1; i <= p->count; i++)
			factorial = factorial * i;
		value = factorial;
	}
	pp = (int *)value;
	return ((void*)value);
}

int main()
{
	int n, out;
	void *p;
	pthread_t thread1_id;
	struct fact_params thread1_args;
	
	printf("\n Enter the number: ");
	scanf("%d", &n);
	thread1_args.count = n;

	pthread_create(&thread1_id, NULL, &fact, &thread1_args);
	
	pthread_join(thread1_id, &out);
//	out = (int*)p;
	printf("\nFactorial = %d\n", out);
	return 0;
}
