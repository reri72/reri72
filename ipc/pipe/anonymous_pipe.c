#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/*
 * 익명 파이프로 생성된 파이프는 생성한 프로세스의 메모리 내부에서만 유지된다.
 * 부모-자식 관계에 있는 프로세스 간에만 사용 가능하다.
 * 데이터는 한 방향으로만 흐른다.
 * pipe() 함수 사용
 */
int main(int argc, char **argv)
{
    // pipefd[0] 은 읽기용, pipefd[1] 은 쓰기용이다.
    int pipefd[2];
    pid_t pid = -1;
    char buffer[64] = {0,};

    if ( pipe(pipefd) == -1 )
    {
        perror("pipe");
        exit(0);
    }

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        close(pipefd[0]);
        close(pipefd[1]);
        exit(0);
    }

    // pid 가 0 이면 자식 프로세스이다.
    if (pid == 0)
    {
        close(pipefd[0]);
        strcpy(buffer, "hi there");
        write(pipefd[1], buffer, sizeof(buffer));
        printf("Sent to parent: %s\n", buffer);
        close(pipefd[1]);   
    }
    else
    {
        close(pipefd[1]);
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Received from child: %s\n", buffer);
        close(pipefd[0]);
    }

    return 0;
}