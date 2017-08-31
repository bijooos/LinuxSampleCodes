/*------------------------------------------------------------------------------ 
 *
 *   Author         : Emertxe (http://www.emertxe.com) 
 *   Date           : Tue 01 Mar 2016 16:18:10 IST
 *   File           : t013.c
 *   Title          : IPC mechanism - Usage of pipe 
 *   Description    : IPC mechanisms provide various ways and means to share 
 *                    information between multiple processes.Creating pipe is
 *                    the simplest way to communicate between parent and child
 *                    in a uni-directional way. 
 *
 *----------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int fds[2];
	pid_t pid;
	int num;

	/* Create a pipe here, its important to do before fork */
	pipe(fds);

	pid = fork();

	if(pid == 0)
	{
		printf("Inside child process...\n");
		printf("Enter the integer you want to share with parent\n");
		scanf("%d",&num);

		/* Write into the pipe for the parent to read */
		write(fds[1],&num,sizeof(num));

		/*
		 * TODO: Try out the following 
		 *       1. The value of 'num' is different in parent & child -- understand 
		 *       2. Exchange a string between parent & child by sending the length first
		 */
	}
	else
	{
		printf("Inslide parent process...\n");

		/* Read from the pipe and print the output */
		read(fds[0],&num,sizeof(num));
		printf("Integer received from parent: %d\n",num);
	}
	return(0);
}
