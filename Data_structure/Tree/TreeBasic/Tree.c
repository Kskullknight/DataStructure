#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

#define NEW_LEVLE -1
#define NULL_DATA -2

BSTNode *GenerateBSTNewNode(int data)
{
    BSTNode *new_node = (BSTNode *)malloc(sizeof(BSTNode));
    new_node->data = data;
    new_node->right = NULL;
    new_node->left = NULL;
    return new_node;
}

// BSTNode *RecursionInserter(BSTNode *root, BTSdata data)
// {
//     if (root == NULL)
//     {
//         BSTNode *new_node = GenerateBSTNewNode(data);
//         root = new_node;
//     }
//     else if (root->data < data)
//         root->right = RecursionInserter(root->right, data);
//     else
//         root->left = RecursionInserter(root->left, data);
//     return root;
// }

void RecursionInserter(BSTNode **root, BTSdata data)
{
    if (*root == NULL)
    {
        BSTNode *new_node = GenerateBSTNewNode(data);
        *root = new_node;
    }
    else if ((*root)->data < data)
        RecursionInserter(&((*root)->right), data);
    else
        RecursionInserter(&((*root)->left), data);
}

BSTNode *LoopInsert(BSTNode *root);

void LevelorderPrintTree(BSTNode *root)
{
    // 루트를 큐에 넣기
    Queue queue;
    QueueInit(&queue);

    Enqueue(&queue, root);

    // 레벨이 넘어갈때마다 개행
    BSTNode *new_line_checker = GenerateBSTNewNode(NEW_LEVLE);
    Enqueue(&queue, new_line_checker);

    // BFS시작
    BSTNode *cur;
    while (!IsEmpty(queue))
    {
        // 큐의 원소 뺴기
        cur = Front(queue);
        Dequeue(&queue);

        // 개행용 노드 처리
        if (cur == new_line_checker)
        {
            printf("\n");
            if (IsEmpty(queue))
                break;
            Enqueue(&queue, new_line_checker);
            continue;
        }

        // 더미 노드 처리
        if (cur->data == NULL_DATA)
        {
            printf("--\t", cur->data);
            continue;
        }
        else
            printf("%d\t", cur->data);

        if (cur->left != NULL)
            Enqueue(&queue, cur->left);
        else
            Enqueue(&queue, GenerateBSTNewNode(NULL_DATA));

        if (cur->right != NULL)
            Enqueue(&queue, cur->right);
        else
            Enqueue(&queue, GenerateBSTNewNode(NULL_DATA));
    }
}

int CountTreeHight(BSTNode *root)
{
}

int IsBSTRecursion(BSTNode *root)
{
    if (root == NULL)
        return 1;
    if (IsBSTRecursion(root->left) && IsBSTRecursion(root->right) && IsLesser(root) && IsGreater(root))
        return 1;
    return 0;
}

int IsLesser(BSTNode *root)
{
    if (root->left == NULL)
    {
        return 1;
    }
    else
    {
        return root->left->data <= root->data;
    }
}
int IsGreater(BSTNode *root)
{
    if (root->right == NULL)
    {
        return 1;
    }
    else
    {
        return root->right->data > root->data;
    }
}

BSTNode *FindSmallestChild(BSTNode *root)
{
    if (root->left == NULL)
    {
        return root;
    }
    return FindSmallestChild(root->left);
}

void DeleteBST(BSTNode *root, int data)
{
    if (root == NULL)
        return;

    if (root->data > data)
    {
        DeleteBST(root->left, data);
    }
    else if (root->data < data)
    {
        DeleteBST(root->right, data);
    }
    else
    {
        // child 0
        if ((root->left == NULL) && (root->right == NULL))
        {
            free(root);
        }
        // child 1
        else if (root->left == NULL)
        {
            root->data = root->right->data;
            root->left = root->right->left;
            root->right = root->right->right;
            free(root->right);
        }
        else if (root->right == NULL)
        {
            root->data = root->left->data;
            root->right = root->left->right;
            root->left = root->left->left;
            free(root->left);
        }
        // child 2
        else
        {
            BSTNode *successor = FindSmallestChild(root->right);
            root->data = successor->data;
            DeleteBST(successor, successor->data);
        }
    }
}

// queue 관련

void QueueInit(Queue *queue)
{
    queue->head = NULL;
    queue->tail = NULL;
}

int IsEmpty(Queue queue)
{
    if (queue.head == NULL)
        return 1;
    return 0;
}

void Enqueue(Queue *queue, QueueData data)
{
    if (IsEmpty(*queue))
    {
        queue->tail = GenerateLLNewNode(data);
        queue->head = queue->tail;
        return;
    }
    LLNode *new_node = GenerateLLNewNode(data);
    queue->tail->next = new_node;
    queue->tail = new_node;
}

void Dequeue(Queue *queue)
{
    if (IsEmpty(*queue))
        return;

    LLNode *del_node = queue->head;
    if (del_node->next == NULL)
    {
        queue->tail = NULL;
    }
    queue->head = del_node->next;
    free(del_node);
}

QueueData Front(Queue queue)
{
    if (IsEmpty(queue))
        return NULL;
    return queue.head->data;
}

LLNode *GenerateLLNewNode(QueueData data)
{
    LLNode *node = (LLNode *)malloc(sizeof(LLNode));
    node->data = data;
    node->next = NULL;
    return node;
}
