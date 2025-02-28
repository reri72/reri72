#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int init_list(List **list, int max)
{
    *list = (List *)malloc(sizeof(List));
    if (*list == NULL)
    {
        printf("allocation failed. \n");
        return -1;
    }

    (*list)->max = max;
    (*list)->size = 0;

    (*list)->head = NULL;
    (*list)->tail = NULL;

    return 0;
}

Node *create_node(int key)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
        return NULL;
    
    node->key = key;
    node->next = NULL;

    return node;
}

void free_node(Node *node)
{
    if (node)
    {
        node->key = 0;
        node->next = NULL;
        free(node);
    }
}

void insert_node(List *list, Node *newnode)
{
    if (list->size >= list->max)
    {
        printf("insert failed. list is FULL. \n");
        return;
    }

    if (newnode == NULL)
    {
        printf("insert failed. newnode is NULL. \n");
        return;
    }

    if (list->tail == NULL)
    {
        // 리스트가 비어있는 경우
        list->head = newnode;
        list->tail = newnode;
    }
    else
    {
        list->tail->next = newnode; // 기존 tail의 next를 새 노드로 변경
        list->tail = newnode;       // tail을 새로운 노드로 변경
    }

    list->size++;
}

void delete_node(List *list, int key)
{
    if (list == NULL || list->head == NULL)
    {
        printf("delete failed. list is NULL. \n");
        return;
    }

    Node *tmp = list->head;     // 현재 탐색 노드
    Node *prev = NULL;          // 이전 노드를 저장할 포인터

    while (tmp != NULL)
    {
        if (tmp->key == key)
        {
            if (prev == NULL)   // 삭제 노드가 첫 번째인 경우
            {
                // head를 다음 노드로 변경
                list->head = tmp->next;
                if (list->head == NULL)
                    list->tail = NULL;
            }
            else
            {
                // 삭제 노드가 중간 또는 마지막인 경우
                prev->next = tmp->next;
                if (tmp == list->tail)
                    list->tail = prev;
            }

            free_node(tmp);
            list->size--;
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    
    printf("delete failed. not found target (%d) \n", key);
}

void print_list(List *list)
{
    if (list == NULL)
    {
        printf("list is null \n");
        return;
    }

    int i = 0;
    Node *tmp = list->head;

    printf("list node size : %d \n", list->size);

    while (tmp != NULL)
    {
        printf("[%d] %d \n", i, tmp->key);
        i++;
        tmp = tmp->next;
    }
}

void destroy_list(List **list)
{
    if (*list == NULL)
    {
        printf("list is already empty. \n");
        return;
    }
    
    Node *tmp = (*list)->head;
    while (tmp != NULL)
    {
        Node *next = tmp->next;
        free_node(tmp);
        tmp = next;
    }
    
    (*list)->head = NULL;
    (*list)->tail = NULL;
    (*list)->size = 0;
    (*list)->max = 0;

    free(*list);
    (*list) = NULL;
}

int main(int argc, char **argv)
{
    List *list = NULL;
    int max = 3;

    Node *node1, *node2, *node3;

    if (init_list(&list, max) != 0)
        return 0;

    node1 = create_node(1);
    node2 = create_node(2);
    node3 = create_node(3);

    insert_node(list, node1);
    insert_node(list, node2);
    insert_node(list, node3);

    print_list(list);

    delete_node(list, 1);
    delete_node(list, 1);
    print_list(list);

    destroy_list(&list);

    return 0;
}