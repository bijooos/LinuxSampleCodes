/*------------------------------------------------------------------------------ 
 *
 *   Author         : Emertxe (http://www.emertxe.com) 
 *   Date           : Tue 01 Mar 2016 16:18:10 IST
 *   File           : t017.c
 *   Title          : IPC mechanism - Usage of signals - Alarms usage 
 *   Description    : IPC mechanisms provide various ways and means to share 
 *                    information between multiple processes. Signals can be 
 *                    sent to the process itself, alarm() is one of them. This
 *                    example demonstrates alarm() usage and how it works. 
 *
 *----------------------------------------------------------------------------*/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

int main()
{

	/* Raise the ALARM, after 5 seconds */
	printf("Calling ALARM for 5 seconds, YOUR handler\n");
	alarm(5);

	/* This loop is required for me to handle when the alarm happens */
	while(1);

	/* After alarm the process will terminate */
	printf("ALARM over...let me wake up now\n");

	return 0;
}
