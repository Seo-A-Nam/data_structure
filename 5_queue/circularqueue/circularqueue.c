#include "circularqueue.h"
// 선형큐는 메모리 낭비가 심해서 원형큐를 쓴다.
// 배열큐 그대로 가져다가, 인큐, 디큐만 수정 

//배열큐를 생성
CircularQueue* createCircularQueue(int maxElementCount)
{
    CircularQueue *CQ;
    
    if (!(CQ = (CircularQueue *)calloc(1, sizeof(CircularQueue))))
    {
        printf("[error] malloc failure : CQ\n");
        return (FALSE);
    }
    CQ->pElement = (CircularQueueNode *)calloc(maxElementCount, sizeof(CircularQueueNode));
    if (!CQ->pElement)
    {
        printf("[error] malloc failure : CQ\n");
        free(CQ);
        return (FALSE);
    }
    CQ->maxElementCount = maxElementCount;
    return (CQ);
}

//배열 큐를 인큐(원소 추가) - 원소 추가 가능 여부 판단
int enqueueCQ(CircularQueue* pQueue, CircularQueueNode element)
{
    if (pQueue == NULL)
    {
        printf("[error] Null parameter : pQueue\n");
        return (FALSE);
    }
    if (isCircularQueueFull(pQueue))
    {
        printf("[error] Queue Overflow\n");
        return (FALSE);
    }
    pQueue->currentElementCount++;
    pQueue->pElement[pQueue->rear].data = element.data;
    pQueue->rear = (pQueue->rear + 1) % (pQueue->maxElementCount); // 기존 배열 큐에서의 rear++ 코드 지우고 이걸 넣음
    return (TRUE);
}

//배열큐를 디큐(원소 삭제)
CircularQueueNode *dequeueCQ(CircularQueue* pQueue)
{
    CircularQueueNode  *pNode;

    if (pQueue == NULL)
    {
        printf("[error] Null parameter : pQueue\n");
        return (FALSE);
    }
    if (isCircularQueueEmpty(pQueue))
    {
        printf("[error] Queue Underflow\n");
        return (FALSE);
    }
    pNode = (CircularQueueNode *)malloc(sizeof(CircularQueueNode));
    if (pNode == NULL)
    {
        printf("[error] malloc failure : pNode\n");
        return (FALSE);
    }
    *pNode = pQueue->pElement[pQueue->front];
    pQueue->pElement[pQueue->front].data = 0;
    pQueue->front = (pQueue->front + 1) % (pQueue->maxElementCount); // 기존 배열 큐에서의 rear++ 코드 지우고 이걸 넣음
    pQueue->currentElementCount--;
    return (pNode);
}

//배열큐를 피크(원소 확인)
CircularQueueNode *peekCQ(CircularQueue* pQueue)
{
    if (pQueue == NULL)
    {
        printf("[error] Null parameter : pQueue\n");
        return (FALSE);
    }
    if (isCircularQueueEmpty(pQueue))
    {
        printf("[error] undefined behavior : Cannot try peek() on a Empty Queue\n");
        return (FALSE);
    }
    return (&(pQueue->pElement[pQueue->front]));
}

//배열큐 삭제
void deleteCircularQueue(CircularQueue* pQueue)
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
int isCircularQueueFull(CircularQueue* pQueue)
{
    if (pQueue == NULL)
    {
        printf("[error] Null parameter : pQueue\n");
        return (FALSE);
    }
    if (pQueue->currentElementCount == pQueue->maxElementCount)
        return (TRUE);
    return (FALSE);
} // if (pQueue->rear == pQueue->maxElementCount - 1) return (TRUE);로 하려했더니 5개째 스택오버플로우 터져야하는게 4개째에서 터졌음

//배열큐가 비어있는지 확인
int isCircularQueueEmpty(CircularQueue* pQueue)
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