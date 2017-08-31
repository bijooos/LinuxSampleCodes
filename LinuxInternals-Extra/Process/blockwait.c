#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{

	pid_t child_pid = fork();
	int status;

	switch(child_pid)
	{
		case 0:
			printf("This is child with pid %d\n", getpid());
			sleep(20);
			exit(0);

		default :
			printf("Parent is waiting for child to exit\n");
//			waitid(P_PID, child_pid, NULL, WNOWAIT | WEXITED);
			waitpid(child_pid,&status, WEXITED | WNOWAIT);
//			wait(&status);
			printf("This is parent with pid %d\n", getpid());
			if (WIFEXITED(status))
				printf("Child exited with status %d\n", WEXITSTATUS(status));
			exit(0);

	}
}


