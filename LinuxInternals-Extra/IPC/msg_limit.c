#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	int qid, len, i;

	struct
	{
		long mtype;
		char mtext[15];
	}message;

	qid = msgget((key_t)10, IPC_CREAT | 0666);
	if(qid == -1)
	{
		perror("msgget Failed");
		exit(1);
	}
	
	strncpy(message.mtext, "Hello World\n", 15);
	message.mtype = 1;
	len = strlen(message.mtext);

	for(i = 0; i < 10000; i++)
	{
		printf("I is %d\n", i);
		if(msgsnd(qid, &message, len, 0) == -1)
		{
			perror("msgsnd failed");
			exit(1);
		}
	}
	return 0;
}
