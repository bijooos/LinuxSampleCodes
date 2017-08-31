#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<sys/un.h>
#include<unistd.h>

int main()
{
	int sockfd;
	int len;
	struct sockaddr_un address;
	int result;
	char ch = 'A';
	/* Create a sockete */
	sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
	/* Name the socket */
	address.sun_family = AF_UNIX;
	strcpy(address.sun_path, "server_socket");
	len = sizeof(address);
	/* Connect the socket to the server's socket */
	result = connect(sockfd, (struct sockaddr *)&address, len);
	if(result == -1) 
	{
		perror("oops: client1");
		exit(1);
	}
	/* You can now read and write via sockfd.*/
	do
	{
		printf("Enter any character. Enter 'x' to exit\n");
		ch = getchar();
		getchar();
		write(sockfd, &ch, 1);
		read(sockfd, &ch, 1);
		printf("char from server = %c\n", ch);
		if (ch == 'y')
			break;
	} while(1);

	close(sockfd);
	exit(0);
}



