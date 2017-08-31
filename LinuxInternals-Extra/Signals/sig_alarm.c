#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

struct sigaction new_act, old_act;

void alarm_handler(int not_using)
{
	printf("Alarm occured\n");
	alarm(10);
	sigaction(SIGALRM, &old_act, NULL);
//	exit(0);
}
int main()
{
	memset(&new_act, 0, sizeof(new_act));
	new_act.sa_sigaction = alarm_handler;
	sigaction(SIGALRM, &new_act, &old_act);

	printf("Return value first time caling alarm is %d\n", alarm(5));
	printf("Return value first time caling alarm is %d\n", alarm(20));

	while(1);

	return 0;
}
