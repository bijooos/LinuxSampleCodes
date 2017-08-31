#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

sig_atomic_t sigint_count = 0;

void handler (int signal_number)
{
	printf("Segmentation fault ...!!!!!\n");
}

int main ()
{
	struct sigaction sa;
	memset (&sa, 0, sizeof (sa));
	sa.sa_handler = &handler;
	sigaction (SIGSEGV, &sa, NULL);
	printf("%d", *(int *)0);
	return 0;
}
