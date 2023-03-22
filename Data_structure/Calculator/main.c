#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node *next;
} Node;

Node *head;

void InsertHeadBehind(int data)
{
    Node *tmp = malloc(sizeof(Node));
    tmp->data = data;
    head = tmp;
}

int main()
{

    return 0;
}