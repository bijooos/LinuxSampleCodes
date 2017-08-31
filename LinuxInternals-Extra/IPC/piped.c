#include<stdio.h>

int main()
{
	int n;
	FILE *fd;
	char line[200];
	fd = popen("ls -l", "r");

	while((fgets(line, 200, fd)) != NULL)
		printf("%s", line);
	return 0;
}
