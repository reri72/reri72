#include "common.h"

int _init_clntsock();

int client_sock;

int main(int argc, char **argv)
{
    if (!_init_clntsock())
    {
        exit(0);
    }
    client_process();

    return 0;
}

int _init_clntsock()
{
    struct sockaddr_in clnt_addr = {0,};
 
    client_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sock < 0)
    {
        perror("socket");
        return -1;
    }

    clnt_addr.sin_family = AF_INET;
    clnt_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &clnt_addr.sin_addr) < 0)
    {
        perror("inet_pton");
        close(client_sock);
        return -1;
    }

    if (connect(client_sock, (struct sockaddr *)&clnt_addr, sizeof(clnt_addr)) < 0)
    {
        printf("connect failed.. \n");
        return -1;
    }

    return 1;
}

void client_process()
{
    char recv_buf[BUF_SIZE] = {0,};

    const char *msg = "hello server?";
    ssize_t write_byte = write(client_sock, msg, strlen(msg)+1);

    ssize_t read_byte = read(client_sock, recv_buf, BUF_SIZE);
    recv_buf[read_byte] = '\0';
    
    printf("%d bytes read : %s \n", read_byte, recv_buf);

    return;
}
