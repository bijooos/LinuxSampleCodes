#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

sig_atomic_t sigint_count = 0;

void handler (int signal_number)
{
	++sigint_count;
}

int main ()
{
	struct sigaction sa;
	memset (&sa, 0, sizeof (sa));
	sa.sa_handler = &handler;
	sigaction (SIGINT, &sa, NULL);
	while(1)
	{
		printf ("SIGINT was raised %d times\n", sigint_count);
	}
	return 0;
}
