/*------------------------------------------------------------------------------ 
 *
 *   Author         : Emertxe (http://www.emertxe.com) 
 *   Date           : Tue 01 Mar 2016 16:18:10 IST
 *   File           : t018.c
 *   Title          : IPC mechanism - Usage of Signals - Advanced handling 
 *   Description    : Apart from handling signals after they occur, the default
 *                    handling mechanism can be changed by using sigaction(). 
 *                    This example demonstrates the same for alarm() signal.
 *
 *----------------------------------------------------------------------------*/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

struct sigaction new_act, old_act;

void alarm_handler(int not_using)
{
	printf("Alarm occured, inside my handler\n");

	/* TODO: Now capture old_act information and restore here */
	/* After restoring the control will go back to default action */

}

int main()
{

	/* Whenever ALARM comes call my handler, callback function */
	new_act.sa_sigaction = alarm_handler;
	sigaction(SIGALRM, &new_act,NULL);

	/* Raise the ALARM, after 5 seconds */
	printf("Calling ALARM for 5 seconds, YOUR handler\n");
	alarm(5);

	while(1);

	printf("ALARM over...let me wake up now\n");

	return 0;
}
