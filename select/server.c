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
    int serv_sock, clnt_sock, fd_max, recv_len, bytes, res;
    int sockopt = 1;
    fd_set reads, read_copy;

    char buf[4096];

    struct timeval timeout;
    struct sockaddr_in serv_adr, clnt_adr;
    
    socklen_t socklen;    
   
    serv_sock = socket(AF_INET, SOCK_STREAM, 0);
    if(serv_sock < 0)
    {
        printf("socket error.. \n");
        return 0;
    }

    memset(&serv_adr, 0, sizeof(serv_adr));
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(702);                         //port
    
    setsockopt(serv_sock, SOL_SOCKET, SO_REUSEADDR, &sockopt, sizeof(sockopt));
    res = bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr));
    if(res == -1)
    {
        printf("bind error ..\n");
        return 0;
    }

    res = listen(serv_sock, 5);
    if(res == -1)
    {
        printf("listen error ..\n");
        return 0;
    }

    socklen = sizeof(clnt_adr);
    clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &socklen);
    if(clnt_sock == -1)
    {
        printf("accept error.. \n");
        return 0;
    }

    fd_max = clnt_sock + 1;

    memset(buf, 0, sizeof(buf));
    memcpy(buf, "hi client \n", sizeof("hi client \n"));
    send(clnt_sock, buf, sizeof(buf), 0);

    while(1)
    {
        FD_ZERO(&reads);
        FD_SET(clnt_sock, &reads);
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
        else if(bytes == 0)
        {
            continue;
        }
        else
        {
            if(FD_ISSET(clnt_sock, &read_copy))
            {
                recv_len = recv(clnt_sock, buf, sizeof(buf), 0);

                if(recv_len < 0)
                {
                    break;
                }
                else if(recv_len == 0)
                {
                    continue;
                }
                else
                {
                    printf("from client message : %s \n", buf);

                    memset(buf, 0, sizeof(buf));
                    memcpy(buf, "hi client\n", sizeof("hi client\n"));

                    ssize_t res = send(clnt_sock, buf, sizeof(buf), 0);
                    if(res < 0)
                    {
                        break;
                    }
                }
            }
        }
        sleep(1);
    }
    
    close(serv_sock);
    shutdown(serv_sock, SHUT_RDWR);

    close(clnt_sock);
    shutdown(clnt_sock, SHUT_RDWR);

    return 0;
}
