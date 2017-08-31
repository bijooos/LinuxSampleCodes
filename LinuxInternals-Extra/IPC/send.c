#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msgbuf {
	long mtype;
	char mtext[8184];
};

int main(void)
{
	struct my_msgbuf buf;
	int msqid;
	key_t key;
	int i;

	if ((key = ftok("temp", 'B')) == -1) 
	{
		perror("ftok");
		exit(1);
	}
//	printf("----%d", key);

	if ((msqid = msgget(key, 0644 | IPC_CREAT)) == -1) 
	{
		perror("msgget");
		exit(1);
	}

	printf("Enter lines of text :\n");

	for(i =0 ; i < 10; i++){
//	scanf("%[^\n]", buf.mtext);// !feof(stdin)) {
	memset(&buf, 'A', sizeof(buf));
	buf.mtype = 1; /* we don't really care in this case */
	if (msgsnd(msqid, (struct msgbuf *)&buf, sizeof(buf), 0) == -1)
		perror("msgsnd");
	printf("%d msg send\n", i);
	}
        	


	return 0;
}
