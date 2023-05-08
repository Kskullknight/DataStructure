#include "Liststack.h"
#include <stdio.h>
#include <stdlib.h>

/*
리스트를 이용한 스택 구현
필요한 함수 정의
*/

void push(Node **pStack, int x)
{
    Node *tmp = (Node *)malloc(sizeof(Node));

    tmp->next = *pStack;
    tmp->data = x;

    *pStack = tmp;
}

void pop(Node **pStack)
{
    Node *tmp = *pStack;

    *pStack = tmp->next;
    free(tmp);
}

int top(Node *stackHead)
{
    return stackHead->data;
}

int isEmpty(Node *stackHead)
{
    if ((stackHead) == NULL)
        return 1;
    return 0;
}

void printStack(Node *stackHead)
{
    Node *cur = stackHead;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");

    return;
}