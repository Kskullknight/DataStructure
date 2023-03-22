#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// 계산기 시작()
void InitCalculator()
{
    // 링크드 리스트를 만들다

    // 첫 숫자를 받는다. 처음 받는 노드는 연사자가 없다.
}

// 연산할 노드를 만든다
void Operation(LinkedList *pcal, int num, int operation)
{
    NodeInsert(pcal, num, operation);
}

int EndCalculator(LinkedList *pcal)
{
    Node *now = pcal->head;
    int total = 0;

    while (now->operation != 0)
    {
        switch (now->operation)
        {
        case 1:
            now->next->num += now->num;
            break;
        case 2:
            now->next->num -= now->num;
            break;

        default:
            break;
        }
    }
}