//Using exec function
//This program call ex2.c program using exec function

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main()
{
	printf("Before exec my ID is %d\n", getpid());
	printf("My Parent process's id is %d\n", getppid());

	printf("exec starts\n");
   	/*Replace <PATH> by current Path in which ex2 is there*/
	execl("/home/biju/Documents/ECEP/LI/Reference/LinuxInternals/Process/ex2","ex2", (char *)0);
	return 0;
}
