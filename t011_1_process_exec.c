/*------------------------------------------------------------------------------ 
 *
 *   Author         : Emertxe (http://www.emertxe.com) 
 *   Date           : Tue 01 Mar 2016 16:18:10 IST
 *   File           : t011.c
 *   Title          : Creating new process - exec() system call 
 *   Description    : Along with fork() and system(), the exec() system call is
 *                    another way to create a new process. Unlike the previous 
 *                    exec() works differently by replacing existing process. 
 *----------------------------------------------------------------------------*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main()
{
	int num;
	char strng[10];

	printf("Before exec my ID is %d\n", getpid());
	printf("My Parent process's id is %d\n", getppid());

	printf("Enter a number\n");
	scanf("%d", &num);
	/* Converting integer to string */
	sprintf(strng, "%d", num);
	printf("exec starts\n");
   	/*Replace <PATH> by current Path in which ex2 is there*/
	execl("<path>/ex2","ex2", strng, (char *)0);
	printf("this won't print\n");
	return 0;
}
