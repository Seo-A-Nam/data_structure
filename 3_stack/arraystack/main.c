#include "arraystack.h"

static void displayAS(ArrayStack* pStack)
{
    for (int i = 0; i < pStack->currentElementCount; i++)
    {
        printf("index (%d) : %c\n", i, pStack->pElement[i].data);
    }
}

int     main()
{
    ArrayStack  *pStack;
    int input = 0;

    pStack = createArrayStack(5);
    while (1)
    {
        
        int err_flag = 1;

        printf("\n=========================================================================\n");
        printf("Stack Status :\n");
        displayAS(pStack);
        printf("\n=========================================================================\n");
        printf("\n1 (push)   2 (pop)   3 (peek)   4 (exit)\n\nType your command number : ");
        scanf(" %d", &input);
        if (input == 4)
        {
            printf("\n_______________________Terminate the Test Program_________________________\n");
            break;
        }
        switch (input)
        {
            case 1 :
            {
                ArrayStackNode ele;
                char    c;
                printf("type any charactor to push on the stack : \n");
                scanf(" %c", &c);
                ele.data = c;
                err_flag = pushAS(pStack, ele);
                break;
            }
            case 2 :
            {
                ArrayStackNode *ele2;
                ele2 = popAS(pStack);
                if (ele2 == 0)
                    err_flag = 0;
                else
                {
                    printf("popped node : %c\n\n", ele2->data);
                    free(ele2);
                }
                break;
            }
            case 3 :
            {
                ArrayStackNode *ele3;
                ele3 = peekAS(pStack);
                if (ele3 == 0)
                    err_flag = 0;
                else
                    printf("peeked node : %c\n\n", ele3->data);
                break;
            }
            default :
            {
                printf("[error] Wrong command\n");
                err_flag = 0;
                break;
            }
        }
        if (err_flag == 0)
        {
            printf("[error] Terminate the Test Program\n");
            break;
        }
    }
    printf("\n");
    deleteArrayStack(pStack);  
    return (0);
} // 왜 앞에 sleep() 함수를 붙이지 않으면 scanf()문이 작동하지 않고 넘어가나?