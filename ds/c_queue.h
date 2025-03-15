#ifndef _C_QUEUE_H_
#define _C_QUEUE_H_

// circular queue 는 큐의 앞과 뒤가 연결되어 있는 구조로, 일반 queue와 달리 공간을 재사용한다.
// 따라서 rear가 배열의 마지막 인덱스를 넘어가면 처음 front로 돌아가서 배열을 재사용한다.

#define SIZE 5

typedef struct c_queue
{
    int data[SIZE];
    int front;
    int rear;
} c_queue_t;

int is_full(c_queue_t *cq);
int is_empty(c_queue_t *cq);
void enqueue(c_queue_t *cq, int value);
int dequeue(c_queue_t *cq);
void display(c_queue_t *cq);

#endif
