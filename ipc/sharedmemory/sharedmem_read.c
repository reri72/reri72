#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

#define SHM_KEY     777
#define SHM_SIZE    1024

int main(int argc, char **argv)
{
    // 공유메모리 세그먼트 접근
    int shmid = shmget(SHM_KEY, SHM_SIZE, 0666);
    if (shmid == -1)
    {
        perror("shmget failed");
        return 1;
    }

    // 공유메모리 영역을 프로세스에 첨부
    char *shm_ptr = (char *)shmat(shmid, NULL, 0);
    if (shm_ptr == (char *)-1)
    {
        perror("shmat failed");
        return 1;
    }

    printf("data read to shared memory : %s \n", shm_ptr);

    // 공유메모리 분리
    if (shmdt(shm_ptr) == -1)
    {
        perror("shmdt failed");
        return 1;
    }

    return 0;
}