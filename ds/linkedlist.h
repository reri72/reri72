#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

typedef struct Node
{
    int key;
    struct Node *next;
} Node;

typedef struct List
{
    int max;
    int size;

    struct Node *head;
    struct Node *tail;
} List;

int init_list(List **list, int max);
Node *create_node(int key);
void insert_node(List *list, Node *newnode);
void delete_node(List *list, int key);
void print_list(List *list);
void destroy_list(List **list);

#endif