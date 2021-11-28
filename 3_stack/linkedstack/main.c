#include "linkedstack.h"

/*
typedef struct StackNodeType
{
	char data;
	struct StackNodeType* pLink;
} StackNode;

typedef struct LinkedStackType
{
	int currentElementCount;	// ���� ������ ����
	StackNode* pTopElement;		// Top ����� ������
} LinkedStack;
*/

static void displayLS(LinkedStack* pStack)
{
    StackNode   *pNode = pStack->pTopElement;

    for(int i = 0; i < pStack->currentElementCount; i++)
    {
        printf("%c\n", pNode->data);
        pNode = pNode->pLink;
    }
}

void    createLinkedStack_test()
{
    LinkedStack *pStack = NULL;

    printf("\nThis is the Test for LinkedStack creation\n\n");
    pStack = createLinkedStack();
    printf("LinkedStack : [%p]\ncurrentElementCount : %d\n", pStack, pStack->currentElementCount);
}

void    pushLS_test()
{
    LinkedStack *pStack = NULL;

    printf("\nThis is the Test for push() on LinkedStack\n\n");
    pStack = createLinkedStack();
    for (int i = 0; i < 5; i++)
    {
        StackNode ele;
        ele.data = i;
        pushLS(pStack, ele);
        printf("%dst push() :\n", i + 1);
        displayLS(pStack);
        printf("\n\n");
    }
    printf("\n");
}

void    popLS_test()
{
    StackNode   *pStack = NULL;

    printf("\nThis is the Test for pop() on LinkedStack\n\n");
    pStack = createLinkedStack();
    printf("Before pop() : \n");
    for (int i = 0; i < 5; i++)
    {
        StackNode ele;
        ele.data = i;
        pushLS(pStack, ele);
    }
    displayLS(pStack);
    printf("\n\n");
    for (int i = 0; i < 5; i++)
    {
        StackNode *ele2;
        ele2 = popLS(pStack);
        printf("%dst pop() : %c\n\n", i + 1, ele2->data);
        displayLS(pStack);
        printf("\n\n");
    }
    printf("\n\n");
}

void    peekLS_test()
{
    StackNode   *pStack = NULL;

    printf("\nThis is the Test for pop() on LinkedStack\n\n");
    pStack = createLinkedStack();
    for (int i = 0; i < 5; i++)
    {
        StackNode ele;
        ele.data = i;
        pushLS(pStack, ele);
    }
    displayLS(pStack);
    printf("\n");
    printf("peek() : %c\n", peekLS(pStack)->data);
    printf("\n\n");
    printf("\n\n");
}

void    deleteLinkedStack_test()
{
    LinkedStack *pStack = NULL;

    printf("\nThis is the Test for LinkedStack deletion\n\n");
    pStack = createLinkedStack();
    printf("LinkedStack : [%p]\n", pStack);
    for (int i = 0; i < 5; i++)
    {
        StackNode ele;
        ele.data = i;
        pushLS(pStack, ele);
    }
    printf("Before deletion : \n");
    displayLS(pStack);
    printf("\n\n");
    deleteLinkedStack(pStack);
    printf("\nAfter Delete, You should get 0 leaks as a result of system('leaks a.out')\n");
    printf("\n");
}

void    isLinkedStackFull_test()
{
    LinkedStack  *pStack = NULL;

    printf("\nThis is the Test for isLinkedStackFull() on LinkedStack\n\n");
    pStack = createLinkedStack();
    printf("LinkedStack : [%p]\n", pStack);
    for (int i = 0; i < 5; i++)
    {
        StackNode ele;
        ele.data = i;
        pushLS(pStack, ele);
    }
    displayLS(pStack);
    printf("\n");
    printf("It must be false because Linkedstack cannot be full.\n\n");
    printf("isLinkedStackFull() : %d\nTRUE when it's 1, FALSE when it's 0\n", isLinkedStackFull(pStack));
}

void    isLinkedStackEmpty_test()
{
    LinkedStack  *pStack = NULL;

    printf("\nThis is the Test for isLinkedStackEmpty() on LinkedStack\n\n");
    pStack = createLinkedStack();
    printf("LinkedStack : [%p]\n", pStack);
    printf("\n");
    printf("It must be true because this stack is already empty\n\n");
    printf("isLinkedStackFull() : %d\nTRUE when it's 1, FALSE when it's 0\n", isLinkedStackFull(pStack));
}

int     main()
{
    // createLinkedStack_test();
    // pushLS_test();
    // popLS_test();
    // peekLS_test();
    // deleteLinkedStack_test();
    // system("leaks a.out");
    // isLinkedStackFull_test();
    // isLinkedStackEmpty_test();
    
    return (0);
}