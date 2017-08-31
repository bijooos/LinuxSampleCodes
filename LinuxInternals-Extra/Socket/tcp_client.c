#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int server_sockfd, client_sockfd;
	int server_len, client_len;
	struct sockaddr_in server_address, client_address;
	struct in_addr addr;
	int result;
	char ch = 'a';

	if (inet_aton("192.168.32.8", &addr) == 0)
	{
		perror("inet_aton");
		exit(EXIT_FAILURE);
	}

	//unlink("server_socket");
	client_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(client_sockfd == -1)
	{
		perror("socket");
		exit(EXIT_FAILURE);
	}

	server_address.sin_family = AF_INET; // address family
	server_address.sin_addr.s_addr = inet_ntoa(addr);
	server_address.sin_port = htons(9374);
	//server_address.sin_port = 9374;
	server_len = sizeof(server_address);

	if(connect(client_sockfd, (struct sockaddr *)&server_address, server_len) == -1)
	{
		perror("connect");
		exit (EXIT_FAILURE);
	}
	printf("Connected and client can send message\n");

	do
	{
		printf("Enter any character. Enter 'x' to exit\n");
		ch = getchar();
		getchar();
		write(client_sockfd, &ch, 1);
		read(client_sockfd, &ch, 1);
		printf("char from server = %c\n", ch);
		if (ch == 'y')
			break;
	} while(1);
#if 0	
	while(ch  != 'y')
	{
		ch = getchar();
		write(client_sockfd, &ch, 1);
		read(client_sockfd, &ch, 1);
		write(1, &ch, 1);
	}
#endif 
	close(client_sockfd);
	exit(0);
}
