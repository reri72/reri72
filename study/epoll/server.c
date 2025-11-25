#include "common.h"
#include <sys/epoll.h>

#define MAX_EVENTS 10

int sock = -1;
int epfd = -1;
struct epoll_event *ep_events = NULL;

void close_process()
{
    if (sock >= 0)
        close(sock);
    if (epfd >= 0)
        close(epfd);
    if (ep_events != NULL)
        free(ep_events);
}

int main(int argc, char **argv)
{
    struct sockaddr_in serv_addr = {0,};
    struct sockaddr_in cli_addr = {0,};

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
        ERROR_HANDLE("socket create error");
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        close(sock);
        ERROR_HANDLE("bind");
    }

    if (listen(sock, 5))
    {
        close(sock);
        ERROR_HANDLE("listen");
    }

    int epfd = epoll_create(MAX_EVENTS);
    if (epfd < 0)
    {
        close(sock);
        ERROR_HANDLE("epoll_create");
    }

    ep_events = calloc(MAX_EVENTS, sizeof(struct epoll_event));
    if (ep_events == NULL)
    {
        close_process();
        ERROR_HANDLE("calloc");
    }

    struct epoll_event event = {EPOLLIN, 0}; // 읽기만 설정
    event.data.fd = sock;
    if (epoll_ctl(epfd, EPOLL_CTL_ADD, sock, &event) < 0)
    {
        close_process();
        ERROR_HANDLE("epoll_ctl");
    }

    while (1)
    {
        int event_cnt = epoll_wait(epfd, ep_events, MAX_EVENTS, 2000);
        if (event_cnt == -1)
        {
            close_process();
            ERROR_HANDLE("epoll_wait");
        }

        int i = 0;
        for (i = 0; i < event_cnt; i++)
        {
            int fd = ep_events[i].data.fd;
            if (fd == sock)
            {
                struct sockaddr_in clnt_addr;
                socklen_t addr_size = sizeof(clnt_addr);

                int client_sock = accept(sock, (struct sockaddr *)&cli_addr, &addr_size);
                if (client_sock < 0)
                {
                    perror("accept");
                    continue;
                }

                event.events = EPOLLIN;
                event.data.fd = client_sock;
                // 신규 클라이언트 등록
                if (epoll_ctl(epfd, EPOLL_CTL_ADD, client_sock, &event) == -1)
                {
                    close(client_sock);
                    close_process();
                    ERROR_HANDLE("epoll_ctl");
                }
            }
            else
            {
                char buf[BUFSIZE] = {0,};
                ssize_t readlen = read(fd, buf, BUFSIZE);

                if (readlen == 0)
                {
                    // 클라이언트 연결이 끊어졌으니 제거
                    epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL);
                    close(fd);
                    printf("client disconnected (fd : %d)\n", fd);
                }
                else if (readlen < 0)
                {
                    perror("read()");
                    epoll_ctl(epfd, EPOLL_CTL_DEL, fd, NULL);
                    close(fd);
                    printf("client disconnected due to read error (fd : %d)\n", fd);
                }
                else
                {
                    buf[readlen] = '\0';
                    fprintf(stdout, "received : %s \n", buf);

                    const char *msg = "hello client \n";
                    write(fd, msg, (strlen(msg)+1));
                }
            }
        }
        
        sleep(1);
    }

    close_process();

    return 0;
}
