#include "common.h"

int _init_servsock();
void _init_fd();

int sock = -1;
struct pollfd poll_fds[FDNUM];

int main(int argc, char **argv)
{
    if(!_init_servsock())
    {
        printf("server socket setting failed.. \n");
        exit(0);
    }
    _init_fd();
    server_process();

    return 0;
}

int _init_servsock()
{
    struct sockaddr_in sockaddr = {0,};

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("socket");
        return -1;
    }

    sockaddr.sin_family = AF_INET;
    sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    sockaddr.sin_port = htons(PORT);

    if (bind(sock, (struct sockaddr *) &sockaddr, sizeof(sockaddr)) < 0)
    {
        perror("bind");
        return -1;
    }

    if (listen(sock, 5) < 0)
    {
        perror("listen");
        return -1;
    }

    return 1;
}

void _init_fd()
{
    int i;

    poll_fds[0].fd = sock;
    poll_fds[0].events = POLLIN;
    poll_fds[0].revents = 0;

    for (i = 1; i < FDNUM; i++)
    {
        poll_fds[i].fd = -1;
    }
}

void server_process()
{
    while (1)
    {
        int i = 0;
        
        int result = poll(poll_fds, FDNUM, TIMEOUT);
        if (result > 0)
        {
            if (poll_fds[0].revents == POLLIN)
            {
                struct sockaddr_in client_addr = {0,};
                socklen_t addr_size = sizeof(client_addr);

                int aceept_fd = accept(sock, (struct sockaddr*)&client_addr, &addr_size);
                if (aceept_fd < 0)
                {
                    perror("accept");
                    continue;
                }

                for (i = 1; i < FDNUM; i++)
                {
                    if (poll_fds[i].fd == -1)
                    {
                        poll_fds[i].fd = aceept_fd;
                        poll_fds[i].events = POLLIN;
                        poll_fds[i].revents = 0;
                        break;
                    }
                }
            }

            for (i = 1; i < FDNUM; i++)
            {
                switch(poll_fds[i].revents)
                {
                    /* no data */
                    case 0:
                        continue;

                    /* data is ready */
                    case POLLIN:
                    case POLLRDNORM:
                    case POLLRDBAND:
                    case POLLPRI:
                    {
                        char recv_buf[BUF_SIZE] = {0,};

                        ssize_t recvlen = recv(poll_fds[i].fd, recv_buf, BUF_SIZE, 0);
                        if (recvlen > 0)
                        {
                            recv_buf[recvlen] = '\0';
                            printf("%d bytes read : %s \n", recvlen, recv_buf);

                            const char *msg = "hello client?";
                            ssize_t sendlen = send(poll_fds[i].fd, msg, strlen(msg)+1, 0);

                            break;
                        }
                        printf("connection closed or error (fd : %d) \n", poll_fds[i].fd);
                    }

                    /* reset */
                    case POLLHUP:
                    case POLLERR:
                    case POLLNVAL:
                    default:
                    {
                        close(poll_fds[i].fd);
                        poll_fds[i].fd = -1;
                        poll_fds[i].revents = 0;
                    } break;
                }
            }
        }
        else
        {
            printf("timeout..\n");
            //break;
            continue;
        }
    }
}
