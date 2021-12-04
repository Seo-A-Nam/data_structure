#include "linkedstack.h"
#include "unistd.h"

static void displayLS(LinkedStack* pStack)
{
    StackNode   *pNode = pStack->pTopElement;

    for(int i = 0; i < pStack->currentElementCount; i++)
    {
        printf("%c\n", pNode->data);
        pNode = pNode->pLink;
    }
}

int     main()
{
    LinkedStack  *pStack;
    int input = 0;

    pStack = createLinkedStack();
    while (1)
    {
        
        int err_flag = 1;

        printf("\n=========================================================================\n");
        printf("Stack Status :\n");
        displayLS(pStack);
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
                StackNode ele;
                char    c;
                printf("type any charactor to push on the stack : \n");
                scanf(" %c", &c);
                ele.data = c;
                err_flag = pushLS(pStack, ele);
                break;
            }
            case 2 :
            {
                StackNode *ele2;
                ele2 = popLS(pStack);
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
                StackNode *ele3;
                ele3 = peekLS(pStack);
                if (ele3 == 0)
                    err_flag = 0;
                else
                    printf("peeked node : %c\n\n", ele3->data);
                break;
            }
            default:
                break;
        }
        if (err_flag == 0)
        {
            printf("[error] Terminate the Test Program\n");
            break;
        }
    }
    printf("\n");
    deleteLinkedStack(pStack);  
    return (0);
}