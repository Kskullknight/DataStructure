// #ifndef __LINKED_LIST_H__
// #define __LINKED_LIST_H__

// // 노드
// typedef struct node
// {
//     int num;
//     // 1은 +, 2는 -, 3은 *, 4는 /
//     int operation;
//     struct node *next;
// } Node;

// typedef struct linkedList
// {
//     Node *head; // 헤드를 가르키는 포인터
//     Node *cur;  // 현재 가르키는 노드
//     Node *next;
//     int Lcount;
// } LinkedList;

// void InitLinkedList(LinkedList *listp);

// // 현재 커서뒤에 노드 생성
// void NodeInsert(LinkedList *listp, int num, int operation);
// // 현재 커서가 가르키는 노드 뒤에 있는 노드 삭제
// void NodeRemove(LinkedList *listp);
// // 다음 노드 조회
// int NextNode(LinkedList *listp);

// #endif

#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

typedef struct _node
{
    int data;
    struct _node *next;
} Node;

void Insert(int data);

#endif