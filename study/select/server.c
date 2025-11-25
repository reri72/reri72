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
    struct sockaddr_in serv_adr = {0,};
    int serv_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (serv_sock < 0)
    {
        perror("socket");
        return 0;
    }
    
    serv_adr.sin_family = AF_INET;
    serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_adr.sin_port = htons(702);
    
    int sockopt = 1;
    setsockopt(serv_sock, SOL_SOCKET, SO_REUSEADDR, &sockopt, sizeof(sockopt));

    int res = bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr));
    if (res == -1)
    {
        perror("bind");
        close(serv_sock);
        return 0;
    }

    res = listen(serv_sock, 5);
    if (res == -1)
    {
        perror("listen");
        close(serv_sock);
        return 0;
    }

    fd_set reads, read_copy;
    FD_ZERO(&reads);
    FD_SET(serv_sock, &reads);

    int fdmax = serv_sock;
    while (1)
    {
        struct timeval timeout = {1,0};

        read_copy = reads; // select 호출 시 변경되므로 복사본 사용
 
        int bytes = select((fdmax+1), &read_copy, 0, 0, &timeout);
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
            int i = 0;
            for (i = 0; i <= fdmax; i++)
            {
                if (FD_ISSET(i, &read_copy))
                {
                    const char *msg = "hi client \n";

                    if (i == serv_sock)
                    {
                        struct sockaddr_in clnt_adr = {0,};
                        socklen_t socklen = sizeof(clnt_adr);

                        int clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &socklen);
                        if (clnt_sock < 0)
                        {
                            perror("accept");
                            continue;
                        }

                        // 새로운 클라이언트 소켓을 모니터링 집합에 추가
                        FD_SET(clnt_sock, &reads);
                        if (clnt_sock > fdmax)
                            fdmax = clnt_sock;
                        send(clnt_sock, msg, strlen(msg), 0);
                    }
                    else
                    {
                        char buf[BUFFSIZE] = {0,};
                        ssize_t recvlen = recv(i, buf, sizeof(buf)-1, 0);

                        if (recvlen < 0)
                        {
                            perror("recv");
                            break;
                        }
                        else if (recvlen == 0)
                        {
                            printf("client disconnected (fd: %d)\n", i);
                            close(i); // 클라이언트 소켓 닫고
                            FD_CLR(i, &reads); // 모니터링 목록에서 제거
                        }
                        else
                        {
                            buf[recvlen] = '\0';
                            printf("recv message : %s \n", buf);

                            send(i, msg, strlen(msg), 0);
                        }
                    }
                }
            }
        }
        sleep(1);
    }
    
    close(serv_sock);

    return 0;
}
