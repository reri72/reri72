#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8989
#define BUFFER_SIZE 1024

#define handle_error(en, msg) do { \
	errno = en; \
	perror(msg); \
	exit(EXIT_FAILURE); \
} while (0)

#define sock_error(msg, fd1, fd2) do { \
	perror(msg); \
	if(fd1 >= 0) close(fd1); \
	if(fd2 >= 0) close(fd2); \
	exit(EXIT_FAILURE); \
} while (0)

void *thread_server(void *arg)
{
	int server_sock = -1;
	struct sockaddr_in svraddr = {0,};

	int client_sock = -1;
	struct sockaddr_in cliaddr = {0,};
	socklen_t addrlen = sizeof(cliaddr);

	server_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (server_sock < 0)
		sock_error("socket", server_sock, client_sock);

	svraddr.sin_family = AF_INET;
	svraddr.sin_port = htons(SERVER_PORT);

	if (inet_pton(AF_INET, SERVER_IP, &svraddr.sin_addr) != 1)
		sock_error("inet_pton", server_sock, client_sock);

	if (bind(server_sock,(struct sockaddr *)&svraddr, sizeof(svraddr)) != 0)
		sock_error("bind", server_sock, client_sock);

	if (listen(server_sock, 1) != 0)
		sock_error("listen", server_sock, client_sock);
	
	client_sock = accept(server_sock, (struct sockaddr *)&cliaddr, &addrlen);
	if (client_sock == -1)
		sock_error("accept", server_sock, client_sock);
	
	ssize_t sendlen = send(client_sock, "hello", strlen("hello"), MSG_NOSIGNAL);

	if (sendlen == -1)
		sock_error("send", server_sock, client_sock);

	fprintf(stdout, "send : hello (%d bytes) \n", (int)sendlen);
	close(server_sock);
	close(client_sock);

	return NULL;
}

void *thread_client(void *arg)
{
	int sock = -1;
	struct sockaddr_in svraddr = {0,};

	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock < 0)
		sock_error("socket", sock, -1);

	svraddr.sin_port = htons(SERVER_PORT);;
	svraddr.sin_family = AF_INET;

	if (inet_pton(AF_INET, SERVER_IP, &svraddr.sin_addr) != 1)
		sock_error("inet_pton", sock, -1);
	
	if (connect(sock, (struct sockaddr *)&svraddr, sizeof(svraddr)) == -1)
		sock_error("connect", sock, -1);
	
	char buffer[16] = {0,};
	ssize_t recvlen = recv(sock, buffer, sizeof(buffer), 0);

	if (recvlen == -1)
		sock_error("recv", sock, -1);

	// buffer 변수를 처음부터 초기화 했기 때문에 마지막에 null 안넣어줌.
	fprintf(stdout, "recv : %s (%d bytes) \n", buffer, (int)recvlen);

	close(sock);
	
	return NULL;
}

int main(int argc, char **argv)
{
	pthread_t pid;
	int s = -1;
	void *res = NULL;

	if (argc != 2)
		return 1;

	if (strcmp(argv[1], "server") == 0)
	{
		s = pthread_create(&pid, NULL, thread_server, NULL);
		if (s != 0)
			handle_error(s, "pthread_create");
		
		s = pthread_join(pid, &res);
		if (s != 0)
			handle_error(s, "pthread_join");
	}
	else if (strcmp(argv[1], "client") == 0)
	{
		s = pthread_create(&pid, NULL, thread_client, NULL);
		if (s != 0)
			handle_error(s, "pthread_create");
		
		s = pthread_join(pid, &res);
		if (s != 0)
			handle_error(s, "pthread_join");
	}
	
	return 0;
}
