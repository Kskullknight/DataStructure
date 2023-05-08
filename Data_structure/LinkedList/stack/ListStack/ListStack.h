#ifndef __STACK_H__
#define __STACK_H__

typedef struct _node
{
    int data;
    struct _node *next;
} Node;

void push(Node **pStack, int x);

void pop(Node **pStack);

int top(Node *stackHead);

int isEmpty(Node *stackHead);

void printStack(Node *stackHead);

#endif