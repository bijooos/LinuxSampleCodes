/*------------------------------------------------------------------------------ 
 *
 *   Author         : Emertxe (http://www.emertxe.com) 
 *   Date           : Tue 01 Mar 2016 16:18:10 IST
 *   File           : t012.c
 *   Title          : Creating new process - exec() system call 
 *   Description    : Along with fork() and system(), the exec() system call is
 *                    another way to create a new process. Unlike the previous 
 *                    exec() works differently by replacing existing process. 
 *
 *----------------------------------------------------------------------------*/

#include<stdio.h>
#include<sys/types.h>

int main(int argc, char **argv)
{
	int num;

	printf("After the exec my process id is %d\n", getpid());
	printf("My parent process's id is %d\n", getppid());

	num = atoi(argv[1]);
	printf("Number recieved %d\n", num);
	printf("\nexec ends\n");
	return 0;
}



