#include "DataStructure.h"
#include <stdio.h>
#include <stdlib.h>

/* ver.1 */
Node *Ghead;

void insertGHeadBehind(int data)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = data;
    tmp->next = Ghead;
    Ghead = tmp;
}

void printUseGhead()
{
    Node *cur = Ghead;
    if (cur == NULL)
        return;
    while (cur->next != NULL)
    {
        printf("%d ->", cur->data);
        cur = cur->next;
    }
    printf("%d", cur->data);

    return;
}

/* ver.2 */
Node *insertWithoutGHead(Node *head, int data)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = data;
    tmp->next = head;
    head = tmp;

    return head;
}

void printWithoutGHead(Node *head)
{
    Node *cur = head;
    if (head == NULL)
        return;

    while (cur->next != NULL)
    {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("%d\n", cur->data);

    return;
}

/*ver.3*/
void insertWithoutReturn(Node **head, int data)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = data;
    tmp->next = *head;
    *head = tmp;

    return;
}

void printWithoutReturn(Node *head)
{
    Node *cur = head;
    while (cur->next != NULL)
    {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("%d", cur->data);

    return;
}

/*reverce*/
void reverceUsePointersGhead()
{
    Node *prev = NULL;
    Node *cur = Ghead;
    Node *next = NULL;
    if (cur == NULL)
        return;
    printf("리버스 시작\n");

    while (cur != NULL)
    {
        next = cur->next;

        // next변경
        cur->next = prev;

        // 다음 노드로
        prev = cur;
        cur = next;
    }

    Ghead = prev;

    printf("리버스 완료\n");
    printUseGhead();
}

Node *reverceUsePointersHead(Node *head)
{
    Node *prev = NULL;
    Node *cur = head;
    Node *next = NULL;
    if (cur == NULL)
        return NULL;
    printf("리버스 시작\n");

    while (cur != NULL)
    {
        next = cur->next;

        // next변경
        cur->next = prev;

        // 다음 노드로
        prev = cur;
        cur = next;
    }

    printf("리버스 완료\n");
    return prev;
}

Node *recursiveReverce(Node *pnode)
{
    if (pnode == NULL)
        return NULL;
    if (pnode->next == NULL)
        return pnode;
    Node *beHeadNode = recursiveReverce(pnode->next);
    pnode->next->next = pnode;
    pnode->next = NULL;

    return beHeadNode;
}

void insertAtTail(Node *head, int inputNum)
{
    if (head == NULL)
        return;
    Node *temp = (Node *)malloc(sizeof(Node));
    Node *cur = head;
    while (cur->next != NULL)
        cur = cur->next;

    temp->next = NULL;
    temp->data = inputNum;
    cur->next = temp;
}

void revertPrint(Node *pNode)
{
    if (pNode == NULL)
        return;
    if (pNode->next == NULL)
    {
        printf("%d ", pNode->data);
        return;
    }
    revertPrint(pNode->next);
    printf("%d ", pNode->data);
    return;
}

Node *revertAndPrint(Node *pNode)
{
    if (pNode == NULL)
        return NULL;
    if (pNode->next == NULL)
    {
        printf("%d ", pNode->data);
        return pNode;
    }
    Node *beHeadNode = revertAndPrint(pNode->next);
    printf("%d ", pNode->data);
    Node *p = pNode->next;
    p->next = pNode;
    pNode->next = NULL;

    return beHeadNode;
}
