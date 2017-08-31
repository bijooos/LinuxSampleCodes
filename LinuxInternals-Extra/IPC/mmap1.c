#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<time.h>
#include<unistd.h>
#define FILE_LENGTH 0x100

int random_range(unsigned const low, unsigned const high)
{
	unsigned const range = high - low + 1;

	return low + (int)(((double)range) * rand() / (RAND_MAX + 1.0));
}

int main(int argc, char *const argv[])
{
	int fd;
	void *file_memory;
	int integer;

	srand(time(NULL));

	if((fd = open(argv[1], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR)) == -1)
		perror("Open");
//	lseek(fd, FILE_LENGTH + 1, SEEK_SET);

//	write(fd, "", 1);
//	lseek(fd, 0, SEEK_SET);

	if((file_memory = mmap(0, FILE_LENGTH, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0)) == MAP_FAILED)
		printf("\nMapping Failed\n");
	close(fd);

	sprintf((char *)file_memory, "%d\n", random_range(-100, 100));
	sscanf(file_memory, "%d", &integer);

	munmap(file_memory, FILE_LENGTH);
	printf("\n%d\n", integer);
	

	return 0;
}
