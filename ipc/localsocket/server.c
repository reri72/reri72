#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
        exit(0);

    printf("path : %s \n", argv[1]);

    struct sockaddr_un addr;
    int server_fd = -1, client_fd = -1;
    
    server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (server_fd < 0)
    {
        perror("socket");
        exit(0);
    }

    memset(&addr, 0, sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, argv[1], strlen(argv[1]));

    unlink(argv[1]);

    if ( bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) == -1 )
    {
        perror("bind");
        unlink(argv[1]);
        close(server_fd);
        exit(0);
    }

    if ( listen(server_fd, 5) == -1 )
    {
        perror("listen");
        unlink(argv[1]);
        close(server_fd);
        exit(0);
    }

    // 파일시스템 경로를 사용하기 때문에 두세번째 인자에 NULL 입력
    client_fd = accept(server_fd, NULL, NULL);  
    if ( client_fd == -1 )
    {
        unlink(argv[1]);
        perror("accept");
        close(server_fd);
        exit(0);
    }

    char buffer[128] = {0,};
    read(client_fd, buffer, sizeof(buffer) - 1);
    printf("Received: %s\n", buffer);
    
    close(server_fd);
    close(client_fd);
    unlink(argv[1]);

    return 0;
}