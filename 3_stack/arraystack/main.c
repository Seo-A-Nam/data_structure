#include "arraystack.h"

static void displayAS(ArrayStack* pStack)
{
    for (int i = 0; i < pStack->currentElementCount; i++)
    {
        printf("index (%d) : %c\n", i, pStack->pElement[i].data);
    }
}

void    createArrayStack_test()
{
    ArrayStack *pStack = NULL;

    printf("\nThis is the Test for ArrayStack creation\n\n");
    pStack = createArrayStack(5);
    printf("ArrayStack : [%p]\ncurrentElementCount : %d\nmaxElementCount : %d\n", 
        pStack, pStack->currentElementCount, pStack->maxElementCount);
}

void    pushAS_test()
{
    ArrayStack *pStack = NULL;

    printf("\nThis is the Test for push() on ArrayStack\n\n");
    pStack = createArrayStack(5);
    for (int i = 0; i < 5; i++)
    {
        ArrayStackNode ele;
        ele.data = i;
        pushAS(pStack, ele);
        printf("%dst push() :\n", i + 1);
        displayAS(pStack);
        printf("\n");
    }
    printf("\n\n\n");
}

void    popAS_test()
{
    ArrayStack *pStack = NULL;

    printf("\nThis is the Test for pop() on ArrayStack\n\n");
    pStack = createArrayStack(5);
    printf("Before pop() : \n");
    for (int i = 0; i < 5; i++)
    {
        ArrayStackNode ele;
        ele.data = i;
        pushAS(pStack, ele);
    }
    displayAS(pStack);
    printf("\n\n");
    for (int i = 0; i < 5; i++)
    {
        ArrayStackNode *ele2;
        ele2 = popAS(pStack);
        printf("%dst pop() : %c\n\n", i + 1, ele2->data);
        displayAS(pStack);
        printf("\n");
    }
}

void    peekAS_test()
{
    ArrayStack *pStack = NULL;

    printf("\nThis is the Test for peek() on ArrayStack\n\n");
    pStack = createArrayStack(5);
    for (int i = 0; i < 5; i++)
    {
        ArrayStackNode ele;
        ele.data = i;
        pushAS(pStack, ele);
    }
    displayAS(pStack);
    printf("\n");
    printf("peek() : %c\n", peekAS(pStack)->data);
    printf("\n\n");
}

void    deleteArrayStack_test()
{
    ArrayStack *pStack = NULL;

    printf("\nThis is the Test for ArrayStack deletion\n\n");
    pStack = createArrayStack(5);
    printf("ArrayStack : [%p]\n", pStack);
    printf("Before deletion : \n");
    for (int i = 0; i < 5; i++)
    {
        ArrayStackNode ele;
        ele.data = i;
        pushAS(pStack, ele);
    }
    displayAS(pStack);
    printf("\n");
    deleteArrayStack(pStack);
    printf("\nAfter Delete, You should get 0 leaks as a result of system('leaks a.out')\n");
    printf("\n");
}

void    isArrayStackFull_test()
{
    ArrayStack  *pStack = NULL;

    printf("\nThis is the Test for isArrayStackFull() on ArrayStack\n\n");
    pStack = createArrayStack(5);
    printf("ArrayStack : [%p]\nc", pStack);
    for (int i = 0; i < 5; i++)
    {
        ArrayStackNode ele;
        ele.data = i;
        pushAS(pStack, ele);
    }
    displayAS(pStack);
    printf("\n");
    printf("It must be true because this stack is already full\n\n");
    printf("isArrayStackFull() : %d\nTRUE when it's 1, FALSE when it's 0, ERROR when it's -1\n", isArrayStackFull(pStack));
}

void    isArrayStackEmpty_test()
{
    ArrayStack  *pStack = NULL;

    printf("\nThis is the Test for isArrayStackFull() on ArrayStack\n\n");
    pStack = createArrayStack(5);
    printf("ArrayStack : [%p]\nc", pStack);
    displayAS(pStack);
    printf("\n");
    printf("It must be true because this stack is already empty\n\n");
    printf("isArrayStackEmpty() : %d\nTRUE when it's 1, FALSE when it's 0, ERROR when it's -1\n", isArrayStackEmpty(pStack));
}

int     main()
{
    // createArrayStack_test();
    // pushAS_test();
    // popAS_test();
    // peekAS_test();
    // deleteArrayStack_test();
    // system("leaks a.out");
    // isArrayStackFull_test();
    // isArrayStackEmpty_test();
    return (0);
}