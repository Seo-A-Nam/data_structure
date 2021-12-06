#include "arrayqueue.h"

static void displayAQ(ArrayQueue* pQueue)
{
    printf("front : %d   rear : %d\n", pQueue->front, pQueue->rear);
    for (int i = 0; i < pQueue->maxElementCount; i++)
    {
        printf("index (%d) : %c\n", i, pQueue->pElement[i].data);
    }
}

int     test()
{
    ArrayQueue  *pQueue;
    int input = 0;

    pQueue = createArrayQueue(5);
    while (1)
    {
        
        int err_flag = 1;
        printf("\n=========================================================================\n");
        printf("Queue Status :\n");
        displayAQ(pQueue);
        printf("\n=========================================================================\n");
        printf("\n1 (Enqueue)   2 (Dequeue)   3 (peek)   4 (exit)\n\nType your command number : ");
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
                ArrayQueueNode ele;
                char    c;
                printf("type any charactor to Enqueue on the Queue : \n");
                scanf(" %c", &c); // scanf 앞에 ' '를 넣으면 sleep을 안넣어도 먹는다. 입력이 안먹는 건 입력 시 엔터가 들어가기 때문
                ele.data = c;
                err_flag = enqueueAQ(pQueue, ele);
                break;
            }
            case 2 :
            {
                ArrayQueueNode *ele2;
                ele2 = dequeueAQ(pQueue);
                if (ele2 == 0)
                    err_flag = 0;
                else
                {
                    printf("dequeued node : %c\n\n", ele2->data);
                    free(ele2);
                }
                break;
            }
            case 3 :
            {
                ArrayQueueNode *ele3;
                ele3 = peekAQ(pQueue);
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
    deleteArrayQueue(pQueue);  
    return (0);
}

int     main()
{
    test();
    system("leaks a.out");
    return (0);
}