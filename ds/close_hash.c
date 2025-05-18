#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 연결 탐사법 (linear probing)

#define DATA_NO     1
#define DATA_NAME   2

typedef enum {
    TERMINATE = 0, 
    ADD, 
    DELETE, 
    SEARCH, 
    CLEAR, 
    PRINT
} MENU;

typedef enum {
    OCCUPIED = 0,
    EMPTY,
    DELETED
} STATUS;

typedef struct
{
    int no;
    char name[16];
} data_t;

typedef struct
{
    data_t data;
    STATUS stat;
} bucket_t;

typedef struct
{
    int size;
    bucket_t *table;
} closehash_t;

MENU select_menu();
data_t scan_data(const char *msg, int sw);

int initialize(closehash_t *h, int size);
bucket_t *search(const closehash_t *h, const data_t *x);
int add(closehash_t *h, const data_t *x);
int delete(closehash_t *h, const data_t *x);
void print_hashtable(const closehash_t *h);
void clear_hashtable(closehash_t *h);
void terminate(closehash_t *h);

static int hash(int key, int size)
{
    return (key % size);
}

static int rehash(int key, int size)
{
    return ((key+1) % size);
}

static void set_bucket(bucket_t *n, const data_t *x, STATUS stat)
{
    n->data = *x;
    n->stat = stat;
}

MENU select_menu()
{
    int m = 0;
    do {
        printf("0. terminate \n");
        printf("1. add \n");
        printf("2. delete \n");
        printf("3. search \n");
        printf("4. clear all \n");
        printf("5. print all \n");
        scanf("%d", &m);
    } while(m < TERMINATE || m > PRINT);
    
    return (MENU)m;
}

data_t scan_data(const char *msg, int sw)
{
    data_t tmp;
    memset(&tmp, 0, sizeof(tmp));

    printf("[%s] scan data \n", msg);
    if (sw & DATA_NO)
    {
        printf("no : \n");
        scanf("%d", &tmp.no);
    }

    if (sw & DATA_NAME)
    {
        printf("name : \n");
        scanf("%15s", tmp.name);
    }
    
    return tmp;
}

int initialize(closehash_t *h, int size)
{
    h->table = calloc(size, sizeof(bucket_t));

    if ( h->table == NULL )
    {
        h->size = 0;
        return -1;
    }
    h->size = size;

    int i = 0;
    for (i = 0; i < size; i++)
    {
        h->table[i].stat = EMPTY;
    }
        return 0;
}

bucket_t *search(const closehash_t *h, const data_t *x)
{
    int key = hash(x->no, h->size);
    bucket_t *p = &h->table[key];

    int i = 0;
    for (i = 0; (p->stat != EMPTY) && (i < h->size); i++)
    {
        if (p->stat == OCCUPIED && p->data.no == x->no)
            return p;
        key = rehash(key, h->size);
        p = &h->table[key];
    }
    return NULL;
}

int add(closehash_t *h, const data_t *x)
{
    int key = hash(x->no, h->size);
    bucket_t *p = &h->table[key];

    if (search(h,x) != NULL)
        return 1;
    
    int i = 0;
    for (i = 0; i <h->size; i++)
    {
        if (p->stat == EMPTY || p->stat == DELETED)
        {
            set_bucket(p, x, OCCUPIED);
            return 0;
        }
        key = rehash(key, h->size);
        p = &h->table[key];
    }
    return 2;
}

int delete(closehash_t *h, const data_t *x)
{
    bucket_t *p = search(h, x);
    if (p == NULL)
        return 1;

    p->stat = DELETED;
    return 0;
}

void print_hashtable(const closehash_t *h)
{
    int i = 0;
    for (i = 0; i < h->size; i++)
    {
        printf("%02d : ", i);
        switch (h->table[i].stat)
        {
            case OCCUPIED:
            {
                printf("%d (%s) \n", 
                        h->table[i].data.no, 
                        h->table[i].data.name);
            } break;
            case EMPTY:
            {
                printf("empty \n");
            } break;
            case DELETED:
            {
                printf("deleted \n");
            } break;
        }
    }
}

void clear_hashtable(closehash_t *h)
{
    int i = 0;
    for (i = 0; i < h->size; i++)
        h->table[i].stat = EMPTY;
}

void terminate(closehash_t *h)
{
    clear_hashtable(h);
    free(h->table);
    h->size = 0;
}

int main(int argc, char **argv)
{
    MENU menu;
    closehash_t hash;
    
    initialize(&hash, 17);

    do
    {
        int res = -1;
        data_t x;
        bucket_t *tmp;

        menu = select_menu();
        switch (menu)
        {
            case ADD:
            {
                x = scan_data("add", DATA_NO | DATA_NAME);
                res = add(&hash, &x);
                if (res == 0)
                    printf("add success \n");
                else
                    printf("error : %s \n", 
                            (res == 1) ? "already exist" : "invaild memory");
            } break;
            case DELETE:
            {
                x = scan_data("delete", DATA_NO);
                res = delete(&hash, &x);
                if (res == 1)
                    printf("not exist data \n");
            } break;
            case SEARCH:
            {
                x = scan_data("search", DATA_NO);
                tmp = search(&hash, &x);
                if (tmp == NULL)
                    printf("search failed \n");
                else
                    printf("%d(%s)\n", tmp->data.no, tmp->data.name);
            } break;
            case CLEAR:
            {
                clear_hashtable(&hash);
            } break;
            case PRINT:
            {
                print_hashtable(&hash);
            } break;
        }
    } while (menu != TERMINATE);
    
    terminate(&hash);

    return 0;
}