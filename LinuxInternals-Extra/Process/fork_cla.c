#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		printf("Usage: %s <cmd>\n", argv[0]);
		return -1;
	}
	if (!fork())
		system(argv[1]);
	return 0;
}
