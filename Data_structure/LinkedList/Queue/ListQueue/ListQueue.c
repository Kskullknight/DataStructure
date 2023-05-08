#include <stdio.h>
#include <stdlib.h>
#include "ListQueue.h"

// 테일에서 넣고
// 헤드에서 뺀다다
void enqueue(Node **ptail, int data)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = data;
    tmp->next = NULL;

    if (isEmpty())
    {
        // 헤드와 테일의 초기화
    }
    *ptail->next = tmp;
    *ptail = tmp;
}

void dequeue(Node **phead)
{
    Node *delNode = *phead;
    *phead = delNode->next;
    free(delNode);
}

int isEmpty(Node *head)
{
    if (head == NULL)
        return 1;
    return 0;
}