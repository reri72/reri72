#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main(int argc, char **argv)
{
    key_t key = ftok("sem_file", 'A');
    if (key == -1)
    {
        perror("ftok failed");
        return 1;
    }
    
    int semid = semget(key, 1, 0666|IPC_CREAT);
    if (semid == -1)
    {
        perror("semget failed");
        semctl(semid, 0, IPC_RMID);
        return 1;
    }

    // 세마포어 초기값을 1로 설정
    if (semctl(semid, 0, SETVAL, 1) == -1)
    {
        perror("semctl failed (SETVAL)");
        semctl(semid, 0, IPC_RMID);
        return 1;
    }

    struct sembuf sem_op;
    memset(&sem_op, 0, sizeof(sem_op));

    sem_op.sem_num = 0;
    sem_op.sem_op = -1; // 세마포어 감소
    sem_op.sem_flg = 0;
    if (semop(semid, &sem_op, 1) == -1)
    {
        perror("semop failed (0)");
        semctl(semid, 0, IPC_RMID);
        return 1;
    }

    printf("임계영역 사용 중\n");
    {
        sleep(1);
    }
    printf("임계영역 사용 완료\n");

    sem_op.sem_op = 1;  // 세마포어 증가
    if (semop(semid, &sem_op, 1) == -1)
    {
        perror("semop failed (1)");
        semctl(semid, 0, IPC_RMID);
    }

    // 세마포어 제거
    if (semctl(semid, 0, IPC_RMID) == -1)
    {
        perror("semctl failed (1)");
        return 1;
    }

    return 0;
}
