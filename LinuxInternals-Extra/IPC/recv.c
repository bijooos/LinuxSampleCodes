#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msgbuf {
	long mtype;
	char mtext[200];
};

int main(void)
{
	struct my_msgbuf buf;
	int msqid;
	key_t key;

	if ((key = ftok("temp", 'B')) == -1) {  /* same key as send.c */
		perror("ftok");
		exit(1);
	}
//		printf("%d-----\n", key);

	if ((msqid = msgget(key, IPC_CREAT)) == -1) { /* connect to the queue */
		perror("msgget");
		exit(1);
	}

	printf("Ready to receive messages\n");

	 /* it  never quits! */
		if (msgrcv(msqid, (struct msgbuf *)&buf, sizeof(buf), 0, 0) == -1) {
			perror("msgrcv");
			exit(1);
		}
		printf("spock: \"%s\"\n", buf.mtext);
		if (msgrcv(msqid, (struct msgbuf *)&buf, sizeof(buf), 0, 0) == -1) {
			perror("msgrcv");
			exit(1);
		}
		printf("spock: \"%s\"\n", buf.mtext);
	

	return 0;
}
