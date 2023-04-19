#ifndef __LIST_QUEUE_H__
#define __LIST_QUEUE_H__

typedef struct _queue_node
{
    int data;
    _queue_node *next;
} Node;

void enqueue(Node *phead, int data);

void dequeue();

int isEmpty();

#endif