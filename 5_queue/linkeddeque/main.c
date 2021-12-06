#include "linkeddeque.h"
#include "unistd.h"

static void displayDQ(LinkedDeque* pDeque)
{
    int         index = 0;
    DequeNode   *node;
    index = pDeque->currentElementCount;
    node = pDeque->pFrontNode;
    for (int i = 0; i < index; i++)
    {
        printf("index (%d) : %c\n", i, node->data);
        node = node->pRLink;
    }
}

int     test()
{
    LinkedDeque *pDeque;
    int input = 0;

    pDeque = createLinkedDeque();
    while (1)
    {
        
        int err_flag = 1;
        printf("\n=========================================================================\n");
        printf("Deque Status :\n");
        displayDQ(pDeque);
        printf("\n==========================================================================\n");
        printf("\n1 (insertFront)   2 (insertRear)   3 (deleteFront)   \n4 (deleteRear)   5 (peekFront)   6 (peekRear)   7 (exit)\n\n");
        printf("Type your command number : ");
        scanf(" %d", &input);
        if (input == 7)
        {
            printf("\n_______________________Terminate the Test Program_________________________\n");
            break;
        }
        switch (input)
        {
            case 1 : //insertFront
            {
                DequeNode ele;
                char    c;
                printf("type any charactor to insert(front) on the Deque : \n");
                scanf(" %c", &c);
                ele.data = c;
                err_flag = insertFrontLD(pDeque, ele);
                break;
            }
            case 2 : //insertRear
            {
                DequeNode ele2;
                char    c;
                printf("type any charactor to insert(rear) on the Deque : \n");
                scanf(" %c", &c);
                ele2.data = c;
                err_flag = insertRearLD(pDeque, ele2);
                break;
            }
            case 3 : //deleteFront
            {
                DequeNode *ele3;
                ele3 = deleteFrontLD(pDeque);
                if (ele3 == 0)
                    err_flag = 0;
                else
                {
                    printf("deleted node from front : %c\n\n", ele3->data);
                    free(ele3);
                }
                break;
            }
            case 4 : //deleteRear
            {
                DequeNode *ele4;
                ele4 = deleteRearLD(pDeque);
                if (ele4 == 0)
                    err_flag = 0;
                else
                {
                    printf("deleted node from rear : %c\n\n", ele4->data);
                    free(ele4);
                }
                break;
            }
            case 5 : //peekFront
            {
                DequeNode *ele5;
                ele5 = peekFrontLD(pDeque);
                if (ele5 == 0)
                    err_flag = 0;
                else
                    printf("peeked node from front : %c\n\n", ele5->data);
                break;
            }
            case 6 : //peekRear
            {
                DequeNode *ele6;
                ele6 = peekRearLD(pDeque);
                if (ele6 == 0)
                    err_flag = 0;
                else
                    printf("peeked node from rear : %c\n\n", ele6->data);
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
    deleteLinkedDeque(pDeque);  
    return (0);
} // 왜 앞에 sleep() 함수를 붙이지 않으면 scanf()문이 작동하지 않고 넘어가나?
 // scanf 앞에 ' '를 넣으면 sleep을 안넣어도 먹는다. 입력이 안먹는 건 입력 시 엔터가 들어가기 때문

int     main()
{
    test();
    system("leaks a.out");
    return (0);
}