#ifndef __Queue_H__
#define __Queue_H__
typedef struct _LLNode
{
    int data;
    _Node *next;
} LLNode;

typedef struct _Queue
{
    LLNode *head;
    LLNode *tail;
} Queue;

void QueueInit(Queue queue);
int IsEmpty(Queue queue);
void Enqueue(Queue queue, int data);
void Dequeue(Queue queue);
int Front(Queue queue);
LLNode *GenerateNewNode(int data);
#endif