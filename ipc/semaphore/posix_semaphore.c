#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

void *thread_func(void *arg);
sem_t sem;

void *thread_func(void *arg)
{
    // 세마포어 감소 (임계 영역 접근)
    sem_wait(&sem);

    printf("thread %d 번 실행 중\n", (long)arg);
    {
        sleep(1);
    }
    printf("Thread %d 번 실행 완료\n", (long)arg);

    // 세마포어 증가 (해제)
    sem_post(&sem); 

    return NULL;
}

int main(int argc, char **argv)
{
    pthread_t threads[3] = {0,};
    long i = 0;

    // 세마포어 초기화 (스레드 간 사용)
    sem_init(&sem, 0, 1);

    for (i = 0; i < 3; i++)
    {
        pthread_create(&threads[i], NULL, thread_func, (void*)i);
    }

    for (i = 0; i < 3; i++)
    {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&sem);
    
    return 0;
}
