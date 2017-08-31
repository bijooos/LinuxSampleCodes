/*------------------------------------------------------------------------------ 
 *
 *   Author         : Emertxe (http://www.emertxe.com) 
 *   Date           : Thu 12 May 2016 15:59:19 IST
 *   File           : t027.c
 *   Title          : POSIX threads (pThread) - Joint & Disjoint threads
 *   Description    : Threads offer multiple options to set attributes, using 
 *                    which multi-tasking can be achieved more effectively. One 
 *                    of them being joint & disjoint threads,demonstrated here. 
 *
 *----------------------------------------------------------------------------*/
#include <stdio.h>
#include <pthread.h>


void *thread_entry_function(void * arg)
{
	int loop;
	 
	thread_number = (int *)arg;

	/* 
	 * TODO: Calculate factorial here 
	 */

	return NULL;
}

int main()
{

	pthread_t threadID;
	pthread_attr_t attr;

	/* Initialize the attribute */
	pthread_attr_init (&attr);

	/* Set the attribute for a detached thread */
	pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_DETACHED);

	/* Now create a thread with this attribute */ 
	pthread_create(&threadID, &attr, thread_entry_function, &threadvalue);

	/* No need to call pthread_join here, as we are not going to wait */

	/* TODO:
	 *      1. Why should we put the sleep below? Remove and check
	 *      2. Create another thread with default (ATTACHED) state and compare
	 */
	sleep(2);
	printf("Back in main thread\n");
	pthread_attr_destroy (&attr);
}
