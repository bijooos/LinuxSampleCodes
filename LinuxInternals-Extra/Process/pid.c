#include <stdio.h>
#include <unistd.h>

//Invoke this program several times & observe the Process Id and Parent Process ID
//Invoke from different shell & observe the Parent Process ID

int main()
{

 	printf ("The process ID is %d \n ",(int)getpid ());
 	printf ("The parent process ID is %d \n", (int)getppid ());
	return 0;
}
