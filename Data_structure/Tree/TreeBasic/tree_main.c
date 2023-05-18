#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

int main()
{

    BSTNode *root = NULL;

    // RecursionInserter(root, ((rand() % 100)));
    // for (int i = 0; i < 10; i++)
    // {
    //     RecursionInserter(root, ((rand() % 100)));
    // }

    RecursionInserter(&root, 4);
    RecursionInserter(&root, 2);
    RecursionInserter(&root, 3);
    RecursionInserter(&root, 8);
    RecursionInserter(&root, 1);
    RecursionInserter(&root, 7);

    // LevelorderPrintTree(root);

    DeleteBST(root, 2);

    LevelorderPrintTree(root);

    // printf("%d", FindSmallestChild(root));
    return 0;
}