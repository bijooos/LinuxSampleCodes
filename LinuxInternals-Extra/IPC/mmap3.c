#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<unistd.h>
#define FILE_LENGTH 10

int main(int argc, char *const argv[])
{
	int s_fd, t_fd, count;
	char *file_src, *file_trgt;

	if((s_fd = open(argv[1], O_RDONLY)) == -1)
	{
		perror("Open");
		exit(1);
	}
	if((t_fd = open(argv[2], O_CREAT | O_RDWR | O_TRUNC, 0644)) == -1)
	{
		perror("Open");
		exit(1);
	}
	lseek(t_fd, 9, SEEK_SET);
	if (write(t_fd, "", 1) == -1)
	{
		perror("write");
		exit(1);
	}

	if ((file_src = mmap(0, FILE_LENGTH, PROT_READ, MAP_SHARED, s_fd, 0)) == MAP_FAILED)
	{
		perror("Src mmap");
		exit(1);
	}
	if ((file_trgt = mmap(0, FILE_LENGTH, PROT_WRITE ,MAP_SHARED, t_fd, 0)) == MAP_FAILED)
	{
		perror("trgt mmap");
		exit(1);
	}
	close(t_fd);
	close(s_fd);


	memcpy(file_trgt, file_src, FILE_LENGTH);
	for (count = 0; count < 10; count++)
		*(file_trgt) = *(file_trgt++) - 32;
	munmap((char *)file_src, FILE_LENGTH);
	munmap((char *)file_trgt, FILE_LENGTH);

	return 0;
}	
