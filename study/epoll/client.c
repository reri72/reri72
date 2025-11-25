#include "common.h"

int sock = -1;

int main(int argc, char **argv)
{
    struct sockaddr_in client_addr = {0,};

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
        ERROR_HANDLE("socket");
    
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, SERVER_IP, &client_addr.sin_addr.s_addr) < 0)
    {
        close(sock);
        ERROR_HANDLE("inet_pton");
    }

    if (connect(sock, (struct sockaddr *)&client_addr, sizeof(client_addr)) == -1)
    {
        close(sock);
        ERROR_HANDLE("connect");
    }

    while (1)
    {
        const char *msg = "hello server \n";
        if (write(sock, msg, (strlen(msg)+1)) < 0)
        {
            close(sock);
            ERROR_HANDLE("write");
        }

        char readbuf[BUFSIZE] = {0,};
        int readlen = read(sock, readbuf, sizeof(readbuf)-1);

        if (readlen > 0)
        {
            readbuf[readlen] = '\0';
            fprintf(stdout, "received : %s \n", readbuf);
        }
        else if (readlen <= 0)
        {
            break;
        }

        sleep(1);
    }
    
    close(sock);
    fprintf(stdout, "close sock \n");

    return 0;
}