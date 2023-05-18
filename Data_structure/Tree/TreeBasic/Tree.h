#ifndef __Tree_H__
#define __Tree_H__

typedef int BTSdata;

typedef struct _BinarySerchTreeNode
{
    BTSdata data;
    struct _BinarySerchTreeNode *left;
    struct _BinarySerchTreeNode *right;
} BSTNode;

typedef BSTNode *QueueData;

typedef struct _LLNode
{
    QueueData data;
    struct _LLNode *next;
} LLNode;

typedef struct _Queue
{
    LLNode *head;
    LLNode *tail;
} Queue;

BSTNode *GenerateBSTNewNode(BTSdata data);
int RecursionInserter(BSTNode **root, BTSdata data);
BSTNode *LoopInsert(BSTNode *root);

void LevelorderPrintTree(BSTNode *root);

// 구현 X
void PreoderPrintTree(BSTNode *root);
void InoderPrintTree(BSTNode *root);
void PostfixPrintTree(BSTNode *root);

BSTNode *FindSmallestChild(BSTNode *root);

int IsBSTRecursion(BSTNode *root);
int IsLesser(BSTNode *root);
int IsGreater(BSTNode *root);

void DeleteBST(BSTNode *root, int data);

/*queue 관련*/

void QueueInit(Queue *queue);
int IsEmpty(Queue queue);
void Enqueue(Queue *queue, QueueData data);
void Dequeue(Queue *queue);
QueueData Front(Queue queue);
LLNode *GenerateLLNewNode(QueueData data);

#endif