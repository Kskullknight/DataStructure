#include "DataStructure.c"
#include <stdio.h>
#include <stdlib.h>

/* ver.1 */
// Node *Ghead;

int main()
{

    // Ghead = NULL;
    Node *head = NULL;

    int count = 0, i, inputData;
    printf("입력하라 데이터의 갯수");
    scanf("%d", &count);

    for (i = 0; i < count; i++)
    {
        scanf("%d", &inputData);
        head = insertWithoutGHead(head, inputData);
    }

    printWithoutGHead(head);
    head = recursiveReverce(head);

    printf("입력하라 데이터의 갯수");
    scanf("%d", &count);
    for (i = 0; i < count; i++)
    {
        scanf("%d", &inputData);
        insertAtTail(head, inputData);
    }
    printWithoutGHead(head);
    head = revertAndPrint(head);
    printf("\n");
    printWithoutGHead(head);

    return 0;
}