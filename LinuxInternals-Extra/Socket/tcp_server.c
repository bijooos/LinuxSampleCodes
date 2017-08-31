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
	int result;
	char ch = 'a';

	//unlink("server_socket");
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(server_sockfd == -1)
	{
		perror("socket:\n");
		exit (EXIT_FAILURE);
	}

	server_address.sin_family = AF_INET; // address family
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(9374);
	//server_address.sin_port = 9374;
	server_len = sizeof(server_address);
	printf("testing\n");

	if (bind(server_sockfd, (struct sockaddr *)&server_address, server_len) == -1)
	{
		perror("bind:\n");
		exit (EXIT_FAILURE);
	}

	if (listen(server_sockfd, 1) == -1)
	{
		perror("listen:\n");
		exit (EXIT_FAILURE);
	}
	client_len = sizeof(client_address);
	client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len); 
	if (client_sockfd == -1)
	{
		perror("accept:\n");
		exit (EXIT_FAILURE);
	}
//      ch = getchar();
	printf("Server waiting\n");
	while(ch != 'y')
	{
		read(client_sockfd, &ch, 1);
		perror("read");
		write(2, &ch, 1);
		perror("write");
		ch++;
		write(client_sockfd, &ch, 1);
		perror("write");
	}
	close(client_sockfd);
	exit(0);
}
