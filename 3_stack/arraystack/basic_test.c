#include "arraystack.h"

static void displayAS(ArrayStack* pStack)
{
    for (int i = 0; i < pStack->currentElementCount; i++)
    {
        printf("index (%d) : %c\n", i, pStack->pElement[i].data);
    }
}

static void fillStack(ArrayStack *pStack, int n)
{
    char    c;

    c = 'a';
    for (int i = 0; i < n; i++)
    {
        ArrayStackNode ele;
        ele.data = c++;
        pushAS(pStack, ele);
    }
}

void    createArrayStack_test()
{
    ArrayStack *pStack = NULL;

    printf("\n============================================\n");
    printf("\nThis is the Test for ArrayStack creation\n\n");
    pStack = createArrayStack(5);
    printf("ArrayStack : [%p]\ncurrentElementCount : %d\nmaxElementCount : %d\n", 
        pStack, pStack->currentElementCount, pStack->maxElementCount);
    deleteArrayStack(pStack);
}

void    pushAS_test()
{
    ArrayStack *pStack = NULL;
    char        c;

    c = 'a';
    printf("\n============================================\n");
    printf("\nThis is the Test for push() on ArrayStack\n\n");
    printf("_______________________\n");
    pStack = createArrayStack(5);
    for (char i = 0; i < 5; i++)
    {
        ArrayStackNode ele;
        ele.data = c++;
        pushAS(pStack, ele);
        printf("%dst push\n\n", i + 1);
        displayAS(pStack);
        printf("_______________________\n");
    }
    deleteArrayStack(pStack);
    printf("\n");
    
}

void    popAS_test()
{
    ArrayStack *pStack = NULL;

    printf("\n============================================\n");
    printf("\nThis is the Test for pop() on ArrayStack\n\n");
    pStack = createArrayStack(5);
    printf("Before pop()\n\n");
    fillStack(pStack, 5);
    displayAS(pStack);
    printf("\n\n");
    printf("_______________________\n");
    for (int i = 0; i < 5; i++)
    {
        ArrayStackNode *ele2;
        ele2 = popAS(pStack);
        printf("%dst pop() : %c\n\n", i + 1, ele2->data);
        free(ele2);
        displayAS(pStack);
        printf("_______________________\n");
    }
    deleteArrayStack(pStack);
}

void    peekAS_test()
{
    ArrayStack *pStack = NULL;

    printf("\n============================================\n");
    printf("\nThis is the Test for peek() on ArrayStack\n\n");
    pStack = createArrayStack(5);
    fillStack(pStack, 5);
    displayAS(pStack);
    printf("\n");
    printf("peek() : %c\n\n", peekAS(pStack)->data);
    deleteArrayStack(pStack);
}

void    isArrayStackFull_test()
{
    ArrayStack  *pStack = NULL;

    printf("\n============================================\n");
    printf("\nThis is the Test for isArrayStackFull() on ArrayStack\n\n");
    pStack = createArrayStack(5);
    printf("ArrayStack : [%p]\n\n", pStack);
    fillStack(pStack, 5);
    displayAS(pStack);
    printf("\n");
    printf("'It must be true because this stack is already full'\n");
    printf("isArrayStackFull() : %d\n\n(TRUE when it's 1, FALSE when it's 0, ERROR when it's -1)\n\n", isArrayStackFull(pStack));
    deleteArrayStack(pStack);
}

void    isArrayStackEmpty_test()
{
    ArrayStack  *pStack = NULL;

    printf("\n============================================\n");
    printf("\nThis is the Test for isArrayStackFull() on ArrayStack\n\n");
    pStack = createArrayStack(5);
    printf("ArrayStack : [%p]\n\n", pStack);
    displayAS(pStack);
    printf("\n");
    printf("'It must be true because this stack is already empty'\n");
    printf("isArrayStackEmpty() : %d\n\n(TRUE when it's 1, FALSE when it's 0, ERROR when it's -1)\n\n", isArrayStackEmpty(pStack));
    deleteArrayStack(pStack);
}

int main()
{
    createArrayStack_test();
    pushAS_test();
    popAS_test();
    peekAS_test();
    isArrayStackFull_test();
    isArrayStackEmpty_test();
    printf("\n============================================\n");
    system("leaks a.out"); 
    /* this code is the test of deleteArraytest(). 
    if that delete function didn't work properly, this program must have made leaks while testing other functions */
}