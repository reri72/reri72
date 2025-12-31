#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>

#define SIZE 5

typedef struct stack
{
    int top;
    unsigned int size;
    unsigned int data[SIZE];
} stack_t;

void push(stack_t *st, int val);
void pop(stack_t *st);
void peek(stack_t *st);
void display(stack_t *st);
bool isEmpty(stack_t *st);
bool isFull(stack_t *st);

#endif