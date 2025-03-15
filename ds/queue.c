#include <stdio.h>
#include <string.h>
#include "queue.h"

int is_full(queue_t *q)
{
    return (q->rear == SIZE - 1);
}

int is_empty(queue_t *q)
{
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(queue_t *q, int value)
{
    if (is_full(q))
    {
        printf("queue is full \n");
        return;
    }

    if (q->front == -1)
        q->front = 0;

    q->data[++q->rear] = value;
    printf("Enqueued: %d\n", value);
}

int dequeue(queue_t *q)
{
    if (is_empty(q))
    {
        printf("queue is empty \n");
        return -1;
    }

    int value = q->data[q->front++];
    if (q->front > q->rear)
        q->front = q->rear = -1;
        
    printf("dequeued: %d\n", value);

    return value;
}

void display(queue_t *q)
{
    if (is_empty(q))
    {
        printf("queue is empty \n");
        return;
    }

    printf("queue elements: ");
    int i = 0;
    for (i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main()
{
    queue_t q = {{0,}, -1, -1};

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    dequeue(&q);

    display(&q);

    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);

    display(&q);

    dequeue(&q);
    dequeue(&q);

    display(&q);

    return 0;
}
