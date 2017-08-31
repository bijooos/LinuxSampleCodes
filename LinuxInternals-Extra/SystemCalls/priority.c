#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main()
{
	printf("My pririty is %d\n", getpriority(PRIO_PROCESS,0));
	setpriority(PRIO_PROCESS, 0, -30);
	printf("My pririty is %d\n", getpriority(PRIO_PROCESS,0));

	return 0;
}
