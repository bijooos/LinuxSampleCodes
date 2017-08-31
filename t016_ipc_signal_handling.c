/*------------------------------------------------------------------------------ 
 *
 *   Author         : Emertxe (http://www.emertxe.com) 
 *   Date           : Tue 01 Mar 2016 16:18:10 IST
 *   File           : t016.c
 *   Title          : IPC mechanism - Usage of Signals - Simple usage 
 *   Description    : IPC mechanisms provide various ways and means to share 
 *                    information between multiple processes. Signals are used 
 *                    mainly intimate about events in the system and handle them
 *                    appropriately. This is a simple usage of signal() system
 *                    call for capturing signals via call-back function.
 *
 *----------------------------------------------------------------------------*/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void my_signal_handler1(int signo); 
void my_signal_handler2(int signo); 

int main() 
{
	int mypid;

	/* Registering for SIGUSR1 & SIGUSR2 */

	/* Here my_signal_handler1 & my_signal_handler2 are callback functions */
	if(signal(SIGUSR1,my_signal_handler1) == SIG_ERR)
		printf("Cannot catch this signal-1\n");
	if(signal(SIGUSR2,my_signal_handler2) == SIG_ERR)
		printf("Cannot catch this signal-2\n");

	
	/* Now wait in a synchronous loop for the signals to arrive */
	while(1)
	{
		printf("Awaiting for signals. My PID is: %d\n",getpid());
		sleep(2);
	}

	/*
	 * TODO: 1. Replace the synchronous while(1) loop with pause() 
	 *		 2. Use of raise() and creating self signals
	 */

	printf("Signal handled, I am exiting\n");
}
	
/* Signal handler - Asynchronous handling & callback function */
void my_signal_handler1(int signo)
{
	/* These functions are called in the context of the Kernel. So minimal handling */
	if (signo == SIGUSR1)  
		printf("Received SIGUSR1\n");
	else	    	
		printf("Error:Sorry, wrong signal\n");
}

void my_signal_handler2(int signo)
{
	/* These functions are called in the context of the Kernel. So minimal handling */
	if (signo == SIGUSR2)  
		printf("Received SIGUSR1\n");
	else	    	
		printf("Error:Sorry, wrong signal\n");
}
