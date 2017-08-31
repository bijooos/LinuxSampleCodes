/*------------------------------------------------------------------------------ 
 *
 *   Author         : Emertxe (http://www.emertxe.com) 
 *   Date           : Thu 12 May 2016 15:59:19 IST
 *   File           : t025.c
 *   Title          : POSIX threads (pThread) - Creating new thread 
 *   Description    : Threads offer efficient way to achieve multi-tasking 
 *                    compared to processes. In this example POSIX thread 
 *                    library calls are used to create a new thread. 
 *
 *----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>


void *thread_entry_function(void * arg)
{
	printf("Inside thread function\n");
	return NULL;
}

int main()
{

	pthread_t threadID;

	pthread_create(&threadID, NULL, thread_entry_function,NULL);
	pthread_join(threadID, NULL);

	/* TODO:
     * 1. Pass a thread into a thread via argument 4
	 * 2. Return a value from thread via pthread_join
	 * 3. Implement a meaningful logic by calculating factorial
	 */

	printf("Back in main thread, thread value %d\n", threadvalue);
}
