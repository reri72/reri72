#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "linked.h"

int main(void)
{
    test1();        //맨 앞에 항목 추가하기
    test2();        //맨 뒤에 항목 추가하기
    test3();        //특정 위치에 항목 추가하기
    test4();        //배열을 리스트로 변환, 버블 정렬, 값 존재 확인
    test5();        //복권번호 생성, 버블 정렬

    return 0;
}

Item* get_init_item()
{
    Item *newitem = malloc(sizeof(Item));

    newitem->data = 0;
    newitem->next = NULL;

    return newitem;
}

void test1()
{
    int count = 0, length = 0;

    Item *list = malloc(sizeof(Item));
    list->next = NULL;
 
    count = 20;
    for(int i = 1; i <= count; i++)
    {
        if(i % 2 == 0)
        {
            add_list_front(list, i);                //짝수 추가
        }
    }

    show_list(list);

    length = get_list_length(list);
    printf("list item count : %d \n", length);

    printf("list item pos(memory) check : \n");
    show_list_mem(list);

    delete_list(list);

    return;
}

void test2()
{
    int count = 0, length =0;

    Item *list = malloc(sizeof(Item));
    list->next = NULL;

    count = 20;
    for (int i = 1; i <= count; i++)
    {
        if(i % 2 == 1)
        {
            _append(list, i);           //홀수 추가
        }
    }
    show_list(list);

    length = get_list_length(list);
    printf("list item count : %d \n", length);

    delete_list(list);

    return;
}

void test3()
{
    int count = 0, length = 0; 

    Item *list = malloc(sizeof(Item));
    list->next = NULL;

    count = 10;
    for (int i = 1; i <= count; i++)
    {
        _append(list, i);
    }

    printf("orginal data : ");
    show_list(list);
    length = get_list_length(list);
    printf("list item count : %d \n\n", length);


    printf("100 and 700 values insert at pos 0 : \n");
    _insert(list, 0, 100);
    _insert(list, 0, 700);

    show_list(list);
    length = get_list_length(list);
    printf("list item count : %d\n\n", length);


    printf("77 and 77 values insert at pos 1 and The end : \n");
    _insert(list, 1, 77);
    _insert(list, get_list_length(list) + 1, 77);           //get_list_length(list) = 13

    show_list(list);
    length = get_list_length(list);
    printf("list item count : %d\n", length);

    delete_list(list);
    
    return;
}

void test4()
{
    int array[] = {100, 900, 200, 800, 300, 700, 400, 600, 500, 1000, 1};
    bool check1 = false, check2 = false;

    Item *list = malloc(sizeof(Item));
    list->next = NULL;

    int array_size = sizeof(array) / sizeof(int);           // : 44 / 4

    array_to_list(list, array, array_size);
    show_list(list);

    check1 = search_list(list, 100);
    check2 = search_list(list, 0);
    printf("check1 : %d , check2 : %d \n", check1, check2);

    bubble_sort_list(list, get_list_length(list));
    show_list(list);

    delete_list(list);

    return;
}

void test5()
{
    Item *list = get_init_item();
    
    get_lotto_list(list);

    bubble_sort_list(list, get_list_length(list));
    printf("sorting lotto num : ");
    show_list(list);

    delete_list(list);

    return;
}

int get_list_length(Item *list)
{
    int count = -1;
    Item *cur = list;

    while(cur != NULL)
    {
        count++;
        cur = cur->next;
    }

    return count;    
}

bool search_list(Item *list, int number)
{
    Item *cur = list;
    int count = 0;
    
    while (cur != NULL)
    {
        if(cur->data == number)
        {
            return true;
        }

        cur = cur->next;
        count++;
    }
    
    return false;
}

void add_list_front(Item *list, int newdata)
{
    struct Item *newitem = malloc(sizeof(Item));
    
    newitem->next = list->next;
    newitem->data = newdata;

    list->next = newitem;
    
    return;
}

void _append(Item *list, int newdata)
{
    if(list->next == NULL)
    {
        Item *newitem = malloc(sizeof(Item));

        newitem->data = newdata;
        newitem->next = NULL;
        
        list->next = newitem;
    }
    else
    {
        Item *cur = list;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }

        Item *newitem = malloc(sizeof(Item));

        newitem->data = newdata;
        newitem->next = NULL;

        cur->next = newitem;
    }

    return;
}

void show_list(Item *list)
{
    Item *cur = list->next;

    printf("[ ");

    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }

    printf("]\n");

    return;
}

void delete_list(Item *list)
{
    Item *cur = list;
    Item *next = NULL;

    while(cur != NULL)
    {
        next = cur->next;
        free(cur);
        cur = next;
    }

    return;
}

void _insert(Item *list, int pos, int data)
{
    Item *cur = list;
    Item *newitem = malloc(sizeof(Item));
    int count = 0;

    newitem->data = data;
    newitem->next = NULL;

    if(pos == 0)
    {
        newitem->next = list->next;
        list->next = newitem;
    }
    else
    {
        while (count != pos)
        {
            if(count == (pos - 1))
            {
                newitem->next = cur->next;
                cur->next = newitem;
            }
            cur = cur->next;
            count++;
        }
    }

    return;
}

void item_data_swap(Item *item1, Item *item2)
{
    int tmp;
    tmp = item1->data;

    item1->data = item2->data;
    item2->data = tmp;

    return;
}

void bubble_sort_list(Item *list, int size)
{
    int i, j;
    Item *cur;
    cur = list;

    cur->data = 0;
    cur = cur->next;

    for(i = 0 ; i < size ; i++)
    {
#ifdef PREVIEW
        printf("%d %d %d %d %d %d \n", \
                cur->data, cur->next->data, cur->next->next->data, cur->next->next->next->data, cur->next->next->next->next->data, cur->next->next->next->next->next->data);
#endif
        if(cur->next == NULL)
        {
            break;
        }

        for(j = 0; j < size - 1 - i; j++)
        {
            if(cur->data > cur->next->data)
            {
                item_data_swap(cur, cur->next);
            }
            cur = cur->next;
        }
        cur = list->next;
    }

    return;
}

void show_list_mem(Item *list)
{
    Item *cur = list->next;
    int i;
    int size = get_list_length(list);

    for(i = 0; i < size; i++)
    {
        printf("[ list pos[%d] = %d (addr : %d) ] \n", i, cur->data, &cur->data);
        cur = cur->next;
    }

    return;
}

void array_to_list(Item *list, int array[], int size)
{
    int i;
    for(int i = 0; i < size; i++)
    {
        _append(list, array[i]);
    }

    return;
}

void get_lotto_list(Item *list)
{
    int i, j;
    int random[6];
    srand( time(NULL) );
 
    for (i = 0; i < 6; i++)
    {
        random[i] = rand() % 45 + 1;

        for(j = 0; j < i; j++)
        {
            if (random[i] == random[j])
            {
                i--;
                break;
            }
        }
    }

    int array_size = sizeof(random) / sizeof(int);      // : 24 / 4
    array_to_list(list, random, array_size);
    
    printf("lotto num : ");
    show_list(list);

    return;
}
