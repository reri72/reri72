#include <stdio.h>
#include "c_queue.h"

int is_full(c_queue_t *cq)
{
    // rear가 front의 바로 앞에 위치하는 상황인지
    return ((cq->rear + 1) % SIZE == cq->front);
}

int is_empty(c_queue_t *cq)
{
    return (cq->front == -1);
}

void enqueue(c_queue_t *cq, int value)
{
    if (is_full(cq))
    {
        printf("queue is full!\n");
        return;
    }
    
    if (cq->front == -1)
        cq->front = 0;

    cq->rear = (cq->rear + 1) % SIZE;   // rear를 다음 위치로 갱신
    cq->data[cq->rear] = value;

    printf("enqueued: %d\n", value);
}

int dequeue(c_queue_t *cq)
{
    if (is_empty(cq))
    {
        printf("queue is empty \n");
        return -1;
    }

    int value = cq->data[cq->front];    // 삭제할 데이터

    // front가 rear와 같으면 큐에 데이터가 하나만 남았다는 뜻
    if (cq->front == cq->rear)
    {
        cq->front = cq->rear = -1;
    }
    else
    {
        // front 위치 갱신
        cq->front = (cq->front + 1) % SIZE;
    }

    printf("dequeued: %d \n", value);

    return value;
}

void display(c_queue_t *cq)
{
    if (is_empty(cq))
    {
        printf("queue is empty \n");
        return;
    }

    printf("queue elements: ");
    int i = cq->front;
    while (1)
    {
        printf("%d ", cq->data[i]);
        if (i == cq->rear)
            break;
        i = (i + 1) % SIZE;
    }

    printf("\n");
}

int main()
{
    c_queue_t cq = {{0,}, -1, -1};

    enqueue(&cq, 10);
    enqueue(&cq, 20);
    enqueue(&cq, 30);
    enqueue(&cq, 40);
    enqueue(&cq, 50);

    display(&cq);

    dequeue(&cq);

    display(&cq);

    enqueue(&cq, 60);

    display(&cq);

    dequeue(&cq);
    dequeue(&cq);

    display(&cq);

    return 0;
}
