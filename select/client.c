#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/select.h>

int main(int argc, char *argv[])
{
    int sock, fd_max, bytes, recv_len, res;
    char buf[4096];
    struct sockaddr_in s_addr;
    struct timeval timeout;
    fd_set reads, read_copy;

    memset(&s_addr, 0, sizeof(s_addr));
    s_addr.sin_family = AF_INET;
    s_addr.sin_addr.s_addr=inet_addr("192.168.???.???");        //server ip (IPv4)
    s_addr.sin_port=htons(702);                                 //port
 
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        printf("socket error.. \n");
        return 0;
    }
    
    res = connect(sock, (struct sockaddr*)&s_addr, sizeof(s_addr));
    if(res == -1)
    {
        printf("connect error.. \n");
        return 0;
    }

    fd_max = sock + 1;

    while(1)
    {
        FD_ZERO(&reads);
        FD_SET(sock, &reads);
        memset(buf, 0, sizeof(buf));

        read_copy = reads;

        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        bytes = select(fd_max, &read_copy, 0, 0, &timeout);
        if(bytes < 0)
        {
            printf("select error.. \n");
            break;
        }
        else if (bytes == 0)
        {
            continue;
        }
        else
        {
            if(FD_ISSET(sock, &read_copy))
            {
                recv_len = recv(sock, buf, sizeof(buf), 0);

                if(recv_len < 0)
                {
                    break;
                }
                if(recv_len == 0)
                {
                    continue;
                }
                else
                {
                    printf("from server message : %s \n", buf);

                    memset(buf, 0, sizeof(buf));
                    memcpy(buf, "hi server \n", sizeof("hi server \n"));
                    
                    ssize_t res = send(sock, buf, sizeof(buf), 0);
                    if(res < 0)
                    {
                        break;
                    }
                }
            }
        }
        sleep(1);
    }

    close(sock);
    shutdown(sock, SHUT_RDWR);

    return 0;
}
