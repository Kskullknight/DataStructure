#include "ListStack.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Node *stackHead = NULL;

    int count = 0, i, inputData;
    printf("입력하라 데이터의 갯수");
    scanf("%d", &count);

    for (i = 0; i < count; i++)
    {
        scanf("%d", &inputData);
        push(&stackHead, inputData);
    }

    printStack(stackHead);

    for (i = 0; i < count; i++)
    {
        pop(&stackHead);
        printStack(stackHead);
    }

    return 1;
}