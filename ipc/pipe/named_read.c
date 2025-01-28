#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char **argv) 
{
    if (argc < 2)
        return 0;
        
    int fd = -1;

    fd = open(argv[1], O_RDONLY);  // 읽기 전용으로 파이프를 연다
    if (fd == -1)
    {
        perror("open");
        exit(0);
    }

    char message[32] = {0,};
    read(fd, message, sizeof(message));
    printf("Received from the pipe: %s\n", message);
    close(fd);

    return 0;
}
