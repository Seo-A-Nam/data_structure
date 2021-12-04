#include "linkedstack.h"

static void displayLS(LinkedStack* pStack)
{
    StackNode   *pNode = pStack->pTopElement;

    for(int i = 0; i < pStack->currentElementCount; i++)
    {
        printf("%c\n", pNode->data);
        pNode = pNode->pLink;
    }
}

static void fillStack(LinkedStack *pStack, int n)
{
    char    c;

    c = 'a';
    for (int i = 0; i < n; i++)
    {
        StackNode ele;
        ele.data = c++;
        pushLS(pStack, ele);
    }
}


void    createLinkedStack_test()
{
    LinkedStack *pStack = NULL;

    printf("\n============================================\n");
    printf("\nThis is the Test for LinkedStack creation\n\n");
    pStack = createLinkedStack();
    printf("LinkedStack : [%p]\ncurrentElementCount : %d\n\n", pStack, pStack->currentElementCount);
    deleteLinkedStack(pStack);
}

void    pushLS_test()
{
    LinkedStack *pStack = NULL;
    char        c = 'a';

    printf("\n============================================\n");
    printf("\nThis is the Test for push() on LinkedStack\n\n");
    printf("_______________________\n");
    pStack = createLinkedStack();
    for (int i = 0; i < 5; i++)
    {
        StackNode ele;
        ele.data = c++;
        pushLS(pStack, ele);
        printf("%dst push() :\n", i + 1);
        displayLS(pStack);
        printf("_______________________\n");
    }
    deleteLinkedStack(pStack);
    printf("\n\n");
}

void    popLS_test()
{
    LinkedStack *pStack = NULL;

    printf("\n============================================\n");
    printf("\nThis is the Test for pop() on LinkedStack\n\n");
    pStack = createLinkedStack();
    printf("Before pop() : \n");
    fillStack(pStack, 5);
    displayLS(pStack);
    printf("\n\n");
    printf("_______________________\n");
    for (int i = 0; i < 5; i++)
    {
        StackNode *ele2;
        ele2 = popLS(pStack);
        printf("%dst pop() : %c\n\n", i + 1, ele2->data);
        free(ele2);
        displayLS(pStack);
        printf("_______________________\n");
    }
    deleteLinkedStack(pStack);
    printf("\n\n");
}

void    peekLS_test()
{
    LinkedStack *pStack = NULL;

    printf("\n============================================\n");
    printf("\nThis is the Test for pop() on LinkedStack\n\n");
    pStack = createLinkedStack();
    fillStack(pStack, 5);
    displayLS(pStack);
    printf("\n");
    printf("peek() : %c\n\n", peekLS(pStack)->data);
    deleteLinkedStack(pStack);
}

void    isLinkedStackFull_test()
{
    LinkedStack  *pStack = NULL;

    printf("\n============================================\n");
    printf("\nThis is the Test for isLinkedStackFull() on LinkedStack\n\n");
    pStack = createLinkedStack();
    printf("LinkedStack : [%p]\n", pStack);
    fillStack(pStack, 5);
    displayLS(pStack);
    printf("\n");
    printf("'It must be false because Linkedstack cannot be full.'\n\n");
    printf("isLinkedStackFull() : %d\n\n(TRUE when it's 1, FALSE when it's 0)\n", isLinkedStackFull(pStack));
    deleteLinkedStack(pStack);
}

void    isLinkedStackEmpty_test()
{
    LinkedStack  *pStack = NULL;

    printf("\n============================================\n");
    printf("\nThis is the Test for isLinkedStackEmpty() on LinkedStack\n\n");
    pStack = createLinkedStack();
    printf("LinkedStack : [%p]\n", pStack);
    printf("\n");
    printf("'It must be true because this stack is already empty.'\n");
    printf("isLinkedStackFull() : %d\n\n(TRUE when it's 1, FALSE when it's 0)\n", isLinkedStackFull(pStack));
    deleteLinkedStack(pStack);
}

int     main()
{
    createLinkedStack_test();
    pushLS_test();
    popLS_test();
    peekLS_test();
    isLinkedStackFull_test();
    isLinkedStackEmpty_test();
    printf("\n============================================\n");
    system("leaks a.out");
    /* this code is the test of deleteLinkedtest(). 
    if that delete function didn't work properly, this program must have made leaks while testing other functions */
    return (0);
}