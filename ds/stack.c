#include "stack.h"

#include "stdio.h"

void push(stack_t *st, int val)
{
    if (isFull(st))
    {
        fprintf(stdout, "stack is full. \n");
        return;
    }

    st->data[++st->top] = val;
    st->size++;
}

void pop(stack_t *st)
{
    if (isEmpty(st))
    {
        fprintf(stdout, "stack is empty. \n");
        return;
    }

    st->data[st->top--] = 0;
    st->size--;
}

void peek(stack_t *st)
{
    if (isEmpty(st))
    {
        fprintf(stdout, "stack is empty. \n");
        return;
    }

    printf("index %d, value : %d \n", (st->size-1), st->data[st->size-1] );
}

void display(stack_t *st)
{
    if (isEmpty(st))
    {
        fprintf(stdout, "stack is empty. \n");
        return;
    }

    printf("-------------------------- \n");
    for (int i = st->top; i >=0; i--)
    {
        printf("[%d] value : %d \n", i, st->data[i]);
    }
    printf("-------------------------- \n");
}

bool isEmpty(stack_t *st)
{
    return (st->size == 0);
}

bool isFull(stack_t *st)
{
    return (st->size >= SIZE);
}

int main(int argc, char *argv[])
{
    stack_t stack = {-1,0,{0,}};

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    push(&stack, 60);

    display(&stack);

    pop(&stack);
    pop(&stack);
    pop(&stack);

    display(&stack);

    return 0;
}