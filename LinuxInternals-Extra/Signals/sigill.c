#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

typedef void(*FUN)(void);

int main(void)
{
	const static unsigned char arr[4] = { 0xff, 0xff, 0xff, 0xff };
	FUN ptr = (FUN)arr;
	printf("This will not print\n");
  	ptr();
	printf("This will not print\n");
}
