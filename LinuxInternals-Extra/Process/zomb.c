#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	if(fork() > 0)
	{
		printf("\nParent\n");
		sleep(50);
	}
	else
	{
		printf("\nI am child, my id is %d\n", (int)getpid());
		exit(0);
	}
	return 0;
}

