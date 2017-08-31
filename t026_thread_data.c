/*------------------------------------------------------------------------------ 
 *
 *   Author         : Emertxe (http://www.emertxe.com) 
 *   Date           : Thu 12 May 2016 15:59:19 IST
 *   File           : t026.c
 *   Title          : POSIX threads (pThread) - Returning value from thread 
 *   Description    : Threads offer efficient way to achieve multi-tasking 
 *                    compared to processes. In this example POSIX thread 
 *                    library calls are used to create a new thread and various
 *                    mechanisms to return values from thread for a sample 
 *                    functionality of factorial. 
 *
 *----------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

typedef struct fact_calc
{
	int num;
	int result;
}factcalc;

int fact_calculate(int num)
{
	int fact=1;
	int i;

	for(i=1;i<=num;i++)
		fact = fact*i;
	
	printf("The factorial value is:%d\n",fact);

	return fact;
}

void* fact_method1 (void *input)
{
	int num = *(int*) input;
	int *result;


	/* Do a dynamic memory allocation, better way */
	result = (int*)malloc(4);
	*result = fact_calculate(num);
	return(result);
}

void* fact_method2 (void *input)
{
	int num = *(int*) input;
	int result;

	result = fact_calculate(num);

	/* This is a Hack way, sending value as a pointer */
	return((void *)(long)result);
}

void* fact_method3 (void *input)
{
	factcalc *ptr = (factcalc *)input;

	/* Still a better way, use the variable allocated in main */
	ptr->result = fact_calculate(ptr->num);
	return NULL;
}

main()
{
	int value = 6;
	int *result;
	int output;
	pthread_t thread_1,thread_2,thread_3;
	factcalc input;

	/* Method - 1 -- Dynamic memory allocation */
	pthread_create(&thread_1,NULL,fact_method1,(void*)&value);
	pthread_join(thread_1,(void **)&result);
	printf("The result-1 is: %d\n",*result);

	/* Method - 2 -- Hack way */
	pthread_create(&thread_2,NULL,fact_method2,(void*)&value);
	pthread_join(thread_1,(void **)&output);
	printf("The result-2 is: %d\n",output);

	/* Method -3 -- Allocate locally */
	input.num = 6;
	pthread_create(&thread_3,NULL,fact_method3,(void*)&input);
	pthread_join(thread_1,NULL);
	printf("The result-3 is: %d\n",input.result);
	
}
