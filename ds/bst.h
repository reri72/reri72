#ifndef _BST_H_
#define _BST_H_

// 시간복잡도 O(log n)
// 공간복잡도 O(n)

/*
- 왼쪽 자식 노드 규칙 : 왼쪽 서브트리에 있는 모든 노드의 값은 현재 부모의 값보다 작아야 함
- 오른쪽 자식 노드 규칙 : 오른쪽 서브트리에 있는 모든 노드의 값은 현재 부모의 값보다 커야 함
- 중복 불가 규칙 : 일반적으로 BST 내에서 모든 노드의 값은 유일해야 함
*/

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data);
void inorder(Node *root);
int getSize(Node *root);
int getHeight(Node *root);
void deleteTree(Node *root);
Node *findBST(Node *root, int data);
Node *insert(Node *root, int data);
Node *findMax(Node *root);
Node *findMin(Node *root);
Node *deleteNode(Node *root, int data);

#endif