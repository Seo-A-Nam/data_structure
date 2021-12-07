#include "arrayqueue.h"

//배열큐를 생성
ArrayQueue* createArrayQueue(int maxElementCount)
{
    ArrayQueue *AQ;

    if (maxElementCount < 0)
    {
        printf("[error] invalid value : maxElementCount\n");
        return (FALSE);
    }
    if (!(AQ = (ArrayQueue *)calloc(1, sizeof(ArrayQueue)))) // 메모리 할당과 함께 메모리 초기화
    {
        printf("[error] malloc failure : AQ\n");
        return (FALSE);
    }
    AQ->pElement = (ArrayQueueNode *)calloc(maxElementCount, sizeof(ArrayQueueNode));
    if (!AQ->pElement)
    {
        printf("[error] malloc failure : AQ\n");
        free(AQ);
        return (FALSE);
    }
    AQ->maxElementCount = maxElementCount;
    return (AQ);
}

//배열 큐를 인큐(원소 추가) - 원소 추가 가능 여부 판단
int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
    if (pQueue == NULL)
    {
        printf("[error] Null parameter : pQueue\n");
        return (FALSE);
    }
    if (isArrayQueueFull(pQueue))
    {
        printf("[error] Queue Overflow\n");
        return (FALSE);
    }
    pQueue->pElement[pQueue->rear].data = element.data;
    pQueue->currentElementCount++;
    pQueue->rear++;
    return (TRUE);
}

//배열큐를 디큐(원소 삭제)
ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
    ArrayQueueNode  *pNode;

    if (pQueue == NULL)
    {
        printf("[error] Null parameter : pQueue\n");
        return (FALSE);
    }
    if (isArrayQueueEmpty(pQueue))
    {
        printf("[error] Queue Underflow\n");
        return (FALSE);
    }
    pNode = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode));
    if (pNode == NULL)
    {
        printf("[error] malloc failure : pNode\n");
        return (FALSE);
    }
    *pNode = pQueue->pElement[pQueue->front];
    pQueue->pElement[pQueue->front].data = 0;
    pQueue->currentElementCount--;
    pQueue->front++;
    return (pNode);
}

//배열큐를 피크(원소 확인)
ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{
    if (pQueue == NULL)
    {
        printf("[error] Null parameter : pQueue\n");
        return (FALSE);
    }
    if (isArrayQueueEmpty(pQueue))
    {
        printf("[error] undefined behavior : Cannot try peek() on a Empty Queue.\n");
        return (FALSE);
    }
    return (&(pQueue->pElement[pQueue->front]));
}

//배열큐 삭제
void deleteArrayQueue(ArrayQueue* pQueue)
{
    if (pQueue == NULL)
    {
        printf("[error] Null parameter : pQueue\n");
        return ;
    }
    if (pQueue->pElement != 0)
        free(pQueue->pElement);
    free(pQueue);
}

//배열큐가 가득 차있는지 확인
int isArrayQueueFull(ArrayQueue* pQueue)
{
    if (pQueue == NULL)
    {
        printf("[error] Null parameter : pQueue\n");
        return (FALSE);
    }
    if (pQueue->rear == pQueue->maxElementCount)
        return (TRUE);
    return (FALSE);
} // if (pQueue->rear == pQueue->maxElementCount - 1) return (TRUE);로 하려했더니 5개째 스택오버플로우 터져야하는게 4개째에서 터졌음

//배열큐가 비어있는지 확인
int isArrayQueueEmpty(ArrayQueue* pQueue)
{
    if (pQueue == NULL)
    {
        printf("[error] Null parameter : pQueue\n");
        return (FALSE);
    }
    if (pQueue->currentElementCount == 0)
        return (TRUE);
    return (FALSE);
}