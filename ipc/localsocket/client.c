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
    int client_fd = -1;
    
    client_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (client_fd < 0)
    {
        perror("socket");
        exit(0);
    }

    memset(&addr, 0, sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, argv[1], strlen(argv[1]));

    if ( connect(client_fd, (struct sockaddr *)&addr, sizeof(addr)) == -1 )
    {
        perror("connect");
        close(client_fd);
        exit(0);
    }

    char buffer[128] = "hi there";
    write(client_fd, buffer, sizeof(buffer) - 1);
    printf("Sent: %s\n", buffer);
    
    close(client_fd);

    return 0;
}