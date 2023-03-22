// #include <stdio.h>
// #include <stdlib.h>
// #include "LinkedList.h"

// void InitLinkedList(LinkedList *plist)
// {
//     // 헤드노드 생성
//     plist->head = (Node *)malloc(sizeof(Node));
//     plist->cur = plist->head;
//     plist->next = NULL;
//     plist->Lcount = 0;
// }

// void NodeInsert(LinkedList *plist, int num, int operation)
// {
//     Node *newNode = (Node *)malloc(sizeof(Node));
//     newNode->num = num;
//     newNode->operation = operation;

//     newNode->next = plist->cur->next;
//     plist->cur->next = newNode;
//     (plist->Lcount)++;
// }

// void NodeRemove(LinkedList *plist)
// {
//     Node *removeNode = plist->cur->next;
//     plist->cur->next = removeNode->next;
//     (plist->Lcount)--;

//     free(removeNode);
// }

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
