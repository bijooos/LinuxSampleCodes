#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
	int fd;
	mkfifo("/tmp/my_fifo", S_IFIFO | 0644);
	fd = open("/tmp/my_fifo", O_WRONLY);
	write(fd, "HI", 3);	
	close(fd);
	return 0;
}
	
