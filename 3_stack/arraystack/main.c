#include "arraylist.h"

// ArrayStack* createArrayStack(int maxElementCount);
// int pushAS(ArrayStack* pStack, ArrayStackNode element);
// ArrayStackNode* popAS(ArrayStack* pStack);
// ArrayStackNode* peekAS(ArrayStack* pStack);
// void deleteArrayStack(ArrayStack* pStack);
// int isArrayStackFull(ArrayStack* pStack);
// int isArrayStackEmpty(ArrayStack* pStack);

void    createArrayStack_test()
{
    ArrayList *pstack;

    printf("\nThis is the Test for ArrayStack creation\n\n");
    pstack = createArrayStack(5);
    printf("ArrayStack : [%p]\ncurrentElementCount : %d\nmaxElementCount : %d\n", 
        pstack, pstack->currentElementCount, pstack->maxElementCount);
}

void    pushAS_test()
{

}

void    popAS_test()
{

}

void    peekAS_test()
{

}

void    deleteArrayStack_test()
{

}

void    isArrayStackFull_test()
{

}

void    isArrayStackEmpty_test()
{

}

int     main()
{
    // createArrayStack_test();
    // pushAS_test();
    // popAS_test();
    // peekAS_test();
    // deleteArrayStack_test();
    // isArrayStackFull_test();
    // isArrayStackEmpty_test();
    total test
    return (0);
}