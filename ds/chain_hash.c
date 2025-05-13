/*
 배열에 새로운 값을 삽입하거나 삭제하려면 필요한 복잡도는 O(n) 이다.
 이것은 적은 비용이 아니다.
 따라서 데이터를 저장할 위치(해시값)를 간단한 연산으로 구하는 방법인 
 해시법을 정의하여 사용한다.

 하지만 해시 값이 고유할 수는 없어 버킷이 비어있지 않을 수 있다.
 이를 충돌이라 한다.
 충돌에 대한 대처로는 체인법과 오픈 주소법을 사용한다.
 * 체인법(오픈 해시법) : 같은 해시값을 갖는 요소를 연결 리스트로 관리하는 것
 * 오픈 주소법 : 빈 버킷을 찾을 때 까지 해시를 반복하는 것
 
 충돌을 피하기 위해서는 해시 테이블의 크기를 소수로 정하는 것이 좋다 알려져 있다.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef enum {
    TERMINATE = 0,
    ADD,
    DELETE,
    SEARCH,
    CLEAR,
    PRINT
} Menu;

#define DATA_NO     1
#define DATA_NAME   2

typedef struct
{
    int no;
    char name[16];
} data_t;

// 버킷을 나타내는 노드
typedef struct _node
{
    data_t  data;
    struct _node *next;
} Node;

// 해시 테이블
typedef struct
{
    int size;
    Node **table;   // 해시 테이블의 첫 번째 요소에 대한 포인터
} ChainHash;

Menu select_menu();
int initialize(ChainHash *h, int size);
Node *search_by_no(const ChainHash *h, const data_t *x);
int add_data(ChainHash *h, const data_t *x);
int delete_by_no(ChainHash *h, const data_t *x);
void print_chainhash(const ChainHash *h);
void clear_hash(ChainHash *h);
void terminate(ChainHash *h);

Menu select_menu()
{
    int m = 0;
    do {
        printf("0. terminate \n");
        printf("1. add \n");
        printf("2. delete \n");
        printf("3. search \n");
        printf("4. clear all \n");
        printf("5. print data \n");
        scanf("%d", &m);
    } while(m < TERMINATE || m > PRINT);

    return (Menu)m;
}

static int hash_by_no(int key, int size)
{
    return key % size;    
}

/*
 - djb2 해시
 1. 초기 해시값은 보통 5381으로 시작한다.
 2. 문자열의 각 문자를 순회하면서 현재 해시 값에 특정 숫자(일반적으로 33)를 곱한다.
 3. 그 결과에 현재 문자의 ASCII 값을 더한다.
 위 과정을 문자열의 모든 문자에 대해 반복하면 최종 해시 값이 얻어진다.
*/
static int hash_by_name(const char *name, int size)
{
    unsigned long hash = 5381;
    uint8_t c = 0;

    while ((c = *name++))
        hash = (hash << 5) + hash + c;  // hash * 33 + c

    return (int)(hash % size);
}

static int hash_by_struct(const data_t *data, int size)
{
    unsigned long hash_value = 5381;
    int c = 0;

    hash_value = ((hash_value << 5) + hash_value) + data->no;

    char *name = data->name;
    while ((c = *name++))
        hash_value = ((hash_value << 5) + hash_value) + c;

    return (int)(hash_value % size);
}

static void init_node(Node *n, const data_t *x, Node *next)
{
    n->data = *x;
    n->next = next;
}

int initialize(ChainHash *h, int size)
{
    int i = 0;

    if ( (h->table = calloc(size, sizeof(Node *))) == NULL )
    {
        h->size = 0;
        return -1;
    }
    
    h->size = size;
    for (i = 0; i < size; i++)
        h->table[i] = NULL;
    return 0;
}

Node *search_by_no(const ChainHash *h, const data_t *x)
{
    int key = hash_by_no(x->no, h->size);
    Node *p = h->table[key];

    while (p != NULL)
    {
        if (p->data.no == x->no)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

Node *search_by_name(const ChainHash *h, const char *name)
{
    int key = hash_by_name(name, h->size);
    Node *p = h->table[key];

    while (p != NULL)
    {
        if (strcmp(p->data.name, name) == 0)
        {
            return p;
        }
        p = p->next;
    }

    return NULL;
}

int add_data(ChainHash *h, const data_t *x)
{
    int key = hash_by_no(x->no, h->size);
    Node *p = h->table[key];
    Node *tmp = NULL;

    while (p != NULL)
    {
        // 이미 같은 키가 있음
        if (p->data.no == x->no)
            return 1;
        p = p->next;
    }

    if ( (tmp = calloc(1, sizeof(Node))) == NULL )
        return 2;
    
    init_node(tmp, x, h->table[key]);
    h->table[key] = tmp;

    return 0;
}

int delete_by_no(ChainHash *h, const data_t *x)
{
    int key = hash_by_no(x->no, h->size);
    Node *p = h->table[key];
    Node **pp = &h->table[key];

    while (p != NULL)
    {
        if (p->data.no == x->no)
        {
            *pp = p->next;
            free(p);
            return 0;
        }
        pp = &p->next;
        p = p->next;
    }

    return -1;
}

int delete_by_name(ChainHash *h, const char *name)
{
    int key = hash_by_name(name, h->size);
    Node *p = h->table[key];
    Node **pp = &h->table[key];

    while (p != NULL)
    {
        if (strcmp(p->data.name, name) == 0)
        {
            *pp = p->next;
            free(p);
            return 0;
        }
        pp = &p->next;
        p = p->next;
    }

    return -1;
}

void print_chainhash(const ChainHash *h)
{
    int i = 0;
    for (i = 0; i < h->size; i++)
    {
        Node *p = h->table[i];
        printf("[slot %d] ", i);
        while (p != NULL)
        {
            printf(" %d (%s),", p->data.no, p->data.name);
            p = p->next;
        }
        printf("\n");        
    }
}

void clear_hash(ChainHash *h)
{
    int i = 0;
    for (i = 0; i < h->size; i++)
    {
        Node *p = h->table[i];
        while (p != NULL)
        {
            Node *next = p->next;
            free(p);
            p = next;
        }
        h->table[i] = NULL;        
    }
}

void terminate(ChainHash *h)
{
    clear_hash(h);
    free(h->table);
    h->size = 0;
}

int name_compare(const data_t *x, const data_t *y)
{
    return strcmp(x->name, y->name);
}

void print_data(const data_t *x)
{
    printf("no : %d\n", x->no);
    printf("name : %s \n", x->name);
    printf("=========================\n\n");
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
        // DATA_NAME
        printf("name : \n");
        scanf("%15s", tmp.name);
        // fgets(tmp.name, sizeof(tmp.name), stdin);
    }
    
    return tmp;
}

int main(int argc, char **argv)
{
    Menu menu;
    ChainHash hash;
    initialize(&hash, 17);
    do
    {
        int ret = 0;
        data_t x;
        Node *tmp = NULL;
        
        menu = select_menu();
        switch (menu)
        {
            case ADD:
            {
                x = scan_data("ADD", DATA_NO | DATA_NAME);
                ret = add_data(&hash, &x);
                if (ret != 0)
                {
                    printf("\aERROR: add failed (%s).\n", 
                            (ret == 1) ? "alreay exist" : "memory error");
                    }
            } break;
            case DELETE:
            {
                x = scan_data("DELETE", DATA_NO);
                ret = delete_by_no(&hash, &x);
                if (ret != 0)
                    printf("\aERROR: not exist data (%d) \n", x.no);
            } break;
            case SEARCH:
            {
                x = scan_data("SEARCH", DATA_NO);
                tmp = search_by_no(&hash, &x);
                if (tmp == NULL)
                {
                    printf("\asearch failed \n");
                }
                else
                {
                    printf("search success \n");
                    print_data(&tmp->data);
                }
            } break;
            case CLEAR:
            {
                clear_hash(&hash);
            } break;
            case PRINT:
            {
                print_chainhash(&hash);
            } break;
            default:
                break;
        }

    } while (menu != TERMINATE);

    terminate(&hash);

    return 0;
}