#include <malloc.h>
#include <pthread.h>
#include <stdlib.h>
#include<stdio.h>
#include<semaphore.h>

struct job {
	int Mydata;
	struct job* next;
};

struct job* job_queue;

pthread_mutex_t job_queue_mutex = PTHREAD_MUTEX_INITIALIZER;
//sem_t mysem;

void process_job(struct job* next_job)
{
	        int i,j,id;
		id=(int)pthread_self();
	        printf("\nThe data from the thread %u is %d\n",id,next_job->Mydata);
	        j=(1+(int) (10.0*rand()/(RAND_MAX+1.0)))/2;
	        sleep(j);
}
                                                                                

void* thread_function (void* arg)
{
	while (1) {
		struct job* next_job;
		//sem_wait(&mysem);
		pthread_mutex_lock (&job_queue_mutex);
		if (job_queue == NULL)
			next_job = NULL;
		else
		{
			next_job = job_queue;
			job_queue = job_queue->next;
		}
		pthread_mutex_unlock (&job_queue_mutex);
		if (next_job == NULL)
			break;
		process_job (next_job);
		free (next_job);
	}
	return NULL;
}

                                                                                
void enqueue_job (struct job* new_job)
{
	        static int i=0;
	        pthread_mutex_lock (&job_queue_mutex);
	        new_job->next = job_queue;
	        job_queue = new_job;
	        job_queue->Mydata=i++;
	        pthread_mutex_unlock (&job_queue_mutex);
                printf("\n Job no %d is added.\n",i-1);
		//sem_post(&mysem);
}

void* producer(void* arg)
{
	struct job *new_job;
	int i,j;
	while(1)
	{
		new_job=(struct job*)malloc(sizeof(struct job));
		enqueue_job(new_job);
		j=1+(int) (10.0*rand()/(RAND_MAX+1.0));
		sleep(j);
                //sem_post(&mysem);
	}
}
		
int main()
{
	int i;
	pthread_t th_id1,th_id2,th_prod;
      //  sem_init(&mysem,0,0);
        struct job *new_job;
        for(i=0;i<6;i++)
	{
		new_job=(struct job*)malloc(sizeof(struct job));
		enqueue_job(new_job);
	}
	pthread_create (&th_id1, NULL, &thread_function, NULL);
	pthread_create (&th_id2, NULL, &thread_function, NULL);
	pthread_create (&th_prod, NULL, &producer, NULL);
	//while(1);
	pthread_join(th_prod,NULL);
return 0;
}

	
