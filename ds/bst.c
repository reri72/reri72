#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

Node *createNode(int data)
{
    Node *new = (Node*)calloc(1, sizeof(Node));
    if (new == NULL)
        return NULL;

    new->data = data;

    return new;
}

// 오름차순 출력
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->data);
        inorder(root->right);
    }
}

int getSize(Node *root)
{
    if (root == NULL) return 0;

    return (getSize(root->left) +getSize(root->right) + 1);
}

int getHeight(Node *root)
{
    if (root == NULL) return 0;
    int left = getHeight(root->left);
    int right = getHeight(root->right);

    return ((left > right ? left : right) + 1);
}

void deleteTree(Node *root)
{
    if (root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

Node *findBST(Node *root, int data)
{
    if (root == NULL || root->data == data) return root;

    // 찾는 값이 현재 노드보다 작으면 왼쪽으로만 가기
    if (root->data > data)
        return findBST(root->left, data);

    // 찾는 값이 현재 노드보다 크면 오른쪽으로만 가기
    return findBST(root->right, data);
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
        return createNode(data);
    
    if (root->data > data)
    {
        // 현재 노드보다 작으면 왼쪽 자식으로 이동
        root->left = insert(root->left, data);
    }
    else if (root->data < data)
    {
        // 현재 노드보다 크면 오른쪽 자식으로 이동
        root->right = insert(root->right, data);
    }

    // 현재 노드 포인터 반환
    return root;
}

Node *findMax(Node *root)
{
    Node *cur = root;

    while (cur && cur->right != NULL)
        cur = cur->right;
    return cur;
}

Node *findMin(Node *root)
{
    Node *cur = root;
    while (cur && cur->left != NULL)
        cur = cur->left;
    return cur;
}

Node *deleteNode(Node *root, int data)
{
    if (root == NULL) return NULL;

    // 삭제할 노드 찾아 내려가기
    if (root->data < data)
    {
        root->right = deleteNode(root->right, data);
    }
    else if (root->data > data)
    {
        root->left = deleteNode(root->left, data);
    }
    else
    {
        // 자식이 없거나 하나인 경우
        if (root->left == NULL)
        {
            // 오른쪽이 있을 수 있으니 챙기기
            Node *tmp = root->right;
            free(root);
            return tmp;
        }
        else if (root->right == NULL)
        {
            // 왼쪽이 있을 수 있으니 챙기기
            Node *tmp = root->left;
            free(root);
            return tmp;
        }

        // 자식이 둘인 경우
        // 관습적으로 오른쪽에서 가장 작은 것을 가져옴
        Node *tmp = findMin(root->right);
        root->data = tmp->data;

        root->right = deleteNode(root->right, tmp->data);
    }

    return root;
}

int main(int argc, char *argv[])
{
    Node *root = createNode(10);

    if (root == NULL)
        return -1;

    insert(root, 5);
    insert(root, 11);
    insert(root, 12);
    insert(root, 13);
    insert(root, 9);

    inorder(root);

    Node *found = findBST(root, 11);
    if (found)
        printf("found [%p]\n", found);
    else
        printf("not found!!\n");

    printf("size : %d \n", getSize(root));
    printf("height : %d \n", getHeight(root));

    deleteTree(root);

    return 0;
}