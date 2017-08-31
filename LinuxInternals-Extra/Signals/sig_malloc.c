#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
int *ptr;
void handler (int signal_number)
{
	(*ptr)++;
}

int main ()
{
	struct sigaction sa;
	memset (&sa, 0, sizeof (sa));
	sa.sa_handler = &handler;
	sigaction (SIGINT, &sa, NULL);

	ptr = malloc(4);
	while(1)
	{
		printf ("SIGINT was raised %d times\n", *ptr);
	}
	return 0;
}
