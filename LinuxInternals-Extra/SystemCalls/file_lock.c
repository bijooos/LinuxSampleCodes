#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, char* argv[])
{
	char* file = argv[1];
	int fd;
	struct flock lock;

	printf ("opening %s\n", file);
	/* Open a file descriptor to the file. */
	fd = open (file, O_RDWR);
	printf ("locking\n");
	/* Initialize the flock structure. */
	memset (&lock, 0, sizeof(lock));

	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start= 0;
	lock.l_len = 0;
	lock.l_pid= getpid();
	/* Place a write lock on the file. */

	if (fcntl (fd, F_SETLKW, &lock) == -1)
	{
		perror("fcntl");
		exit(1);
	}
	printf ("locked; hit Enter to unlock... ");

	/* Wait for the user to hit Enter. */
	getchar ();
	printf ("unlocking\n");

	/* Release the lock. */
	lock.l_type = F_UNLCK;
	fcntl (fd, F_SETLKW, &lock);
	close (fd);

	return 0;
}
