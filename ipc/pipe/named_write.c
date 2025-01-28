#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

/*
 * 부모-자식 관계에 있지 않은 프로세스 간에도 사용이 가능하다.
 */

int main(int argc, char **argv) 
{
    if (argc < 2)
        return 0;
        
    int fd = -1;
    char message[32] = "hi there";

    // 네임드 파이프를 생성한다.
    if ( mkfifo(argv[1], 0666) == -1)
    {
        perror("mkfifo");
        exit(0);
    }

    fd = open(argv[1], O_WRONLY);  // 쓰기 전용으로 파이프를 연다
    if (fd == -1)
    {
        perror("open");
        exit(0);
    }

    write(fd, message, strlen(message));
    printf("Sent to the pipe: %s\n", message);
    close(fd);

    return 0;
}
