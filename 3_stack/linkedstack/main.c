#include "linkedstack.h"

static void displayLS(LinkedStack* pStack)
{
    StackNode *pNode = pStack->pTopElement;
    for(int i = 0; i < pStack->currentElementCount; i++)
    {
        printf("%c\n", pNode->data);
        pNode = pNode->pLink;
    }
}

int     main()
{

    return (0);
}