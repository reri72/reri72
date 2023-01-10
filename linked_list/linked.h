#ifndef _LINKED_
#define _LINKED_

//#define PREVIEW

typedef struct Item{
    struct Item *next;
    int data;    
}Item;

Item* get_init_item();
bool search_list(Item *list, int number);

int get_list_length(Item *list);

void _append(Item *list, int newdata);
void _insert(Item *list, int pos, int data);

void add_list_front(Item *list, int newdata);
void show_list(Item *list);
void delete_list(Item *list);

void item_data_swap(Item *item1, Item *item2);
void bubble_sort_list(Item *list, int size);
void show_list_mem(Item *list);
void array_to_list(Item *list, int array[], int size);
void get_lotto_list(Item *list);

void test1();
void test2();
void test3();
void test4();
void test5();

#endif  //end _LINKED_