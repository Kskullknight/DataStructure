#ifndef __DATA__STRUCTURE_H__
#define __DATA__STRUCTURE_H__

typedef struct _node
{
    int data;
    struct _node *next;
} Node;

/* ver.1: head를 글로벌로 선언하고 헤드의 뒤에 넣기 */
void insertGHeadBehind(int data);
void printUseGhead();

/* ver.2 : head를 main함수선언 하고 인수로 받아서 뒤에 넣고 새로운 head값을 반환*/
Node *insertWithoutGHead(Node *head, int data);
void printWithoutGHead(Node *head);

/*ver.3: head포인트를 받아서 함수에서 head변경*/
void insertWithoutReturn(Node **head, int data);
void printWithoutReturn(Node *head);

/*reverce*/
// 포인터 3개를 이용하여 구현 (반복문 이용)
void reverceUsePointersGhead();
// 파라미터를 이용(전역번수 삭제)
Node *reverceUsePointersHead(Node *head);
// 재귀함수로 구현
Node *recursiveReverce(Node *pnode);

// insertAtTail
void insertAtTail(Node *head, int inputNum);

// revercePrint
void revertPrint(Node *head);

// insertBehind

#endif