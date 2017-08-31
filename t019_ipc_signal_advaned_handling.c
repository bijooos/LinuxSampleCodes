/*------------------------------------------------------------------------------ 
 *
 *   Author         : Emertxe (http://www.emertxe.com) 
 *   Date           : Tue 01 Mar 2016 16:18:10 IST
 *   File           : t019.c
 *   Title          : IPC mechanism - Usage of Signals - Advanced handling 
 *   Description    : Apart from handling signals after they occur, the default
 *                    handling mechanism can be changed by using sigaction(). 
 *                    This example demonstrates the same for SEGV signal.
 *
 *----------------------------------------------------------------------------*/
#include <stdio.h>
#include <unistd.h>
#include <sys/signal.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>

void handler(int signum, siginfo_t *info, void *dummy)
{
	printf("Signal recieved with %d\n", signum);
	printf("Signal send from %d\n", info->si_pid);
}


int main()
{
	struct sigaction act, oldact;

	memset(&act, 0, sizeof(act));
	act.sa_sigaction = handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGSEGV, &act, &oldact);

	pause();
	return 0;
}

