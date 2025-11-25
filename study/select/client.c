#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/select.h>

#define BUFFSIZE 1024

int main(int argc, char *argv[])
{
    struct sockaddr_in s_addr = {0,};
    
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(702);
    if (inet_pton(AF_INET, "127.0.0.1", &s_addr.sin_addr) <= 0)
    {
        perror("inet_pton");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("socket");
        return 1;
    }
    
    int res = connect(sock, (struct sockaddr *)&s_addr, sizeof(s_addr));
    if (res == -1)
    {
        perror("connect");
        close(sock);
        return 1;
    }

    while(1)
    {
        char buf[BUFFSIZE] = {0,};
        struct timeval timeout = {1,0};
        fd_set reads, read_copy;

        FD_ZERO(&reads);
        FD_SET(sock, &reads);

        read_copy = reads;

        // select 는 read_copy를 변경하므로 원본 reads 사용하지 않음
        int bytes = select((sock + 1), &read_copy, 0, 0, &timeout);
        if (bytes < 0)
        {
            perror("select");
            break;
        }
        else if (bytes == 0)
        {
            continue; // 타임아웃
        }
        else
        {
            if (FD_ISSET(sock, &read_copy))
            {
                ssize_t recv_len = recv(sock, buf, sizeof(buf)-1, 0);
                if (recv_len < 0)
                {
                    perror("recv");
                    break;
                }
                else if (recv_len == 0)
                {
                    printf("closed connection \n");
                    break;
                }
                else
                {
                    buf[recv_len] = '\0';
                    printf("from server message : %s \n", buf);

                    const char *responsemsg = "hi server \n";
                    ssize_t send_res = send(sock, responsemsg, strlen(responsemsg), 0);
                    if (send_res < 0)
                    {
                        perror("send error");
                        break;
                    }
                }
            }
        }
        sleep(1);
    }

    close(sock);

    return 0;
}
