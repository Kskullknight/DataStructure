#include "Queue.h"
void QueueInit(Queue queue)
{
    queue->head = NULL;
    queue->tail = NULL;
}

int IsEmpty(Queue queue)
{
    if (queue->head != NULL)
        return 1;
    return 0;
}

void Enqueue(Queue queue, int data)
{
    if (queue->head == NULL)
        return;

    queue->tail->next = GenerateNewNode(data);
}

void Dequeue(Queue queue)
{
    if (queue->head == NULL)
        return;

    LLNode *del_node = queue->head;
    queue->head = del_node->next;
    free(del_node);
}

int Front(Queue queue)
{
    return queue->head->data;
}

LLNode *GenerateNewNode(int data)
{
    LLNode *node = (LLNode *)malloc(sizeof(LLNode));
    node->data = data;
    return node;
}
