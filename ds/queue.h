#ifndef _QUEUE_H_
#define _QUEUE_H_

#define SIZE 5

typedef struct queue
{
    int data[SIZE];
    int front; // 가장 먼저 나갈 데이터의 위치
    int rear;  // 마지막으로 삽입된 데이터의 위치
} queue_t;

int is_full(queue_t *q);
int is_empty(queue_t *q);
void enqueue(queue_t *q, int value);
int dequeue(queue_t *q);
void display(queue_t *q);

#endif