#include "arrayqueue.h"

ArrayQueue* createArrayQueue(int maxElementCount)
{
	ArrayQueue *queue;
	
	if (!(queue = (ArrayQueue *)malloc(sizeof(ArrayQueue))))
		return (NULL);
	queue->maxElementCount = maxElementCount;
	queue->currentElementCount = 0;
	queue->front = 0;
	queue->rear = -1;
	queue->pElement = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode) * maxElementCount);
	if (!queue->pElement)
		return (NULL);
	return (queue);
}

int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
	if (!pQueue)
		return (FALSE);
	if (isArrayQueueFull(pQueue))
		return (FALSE);
	pQueue->rear = (pQueue->rear + 1) % pQueue->maxElementCount;
    pQueue->pElement[pQueue->rear] = element;
    pQueue->currentElementCount++;
    return (TRUE);
}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
	ArrayQueueNode *ret_node;

	if (!pQueue)
		return (FALSE);
	if (isArrayQueueEmpty(pQueue))
		return (FALSE);
	ret_node = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode));
	if (!ret_node)
		return (FALSE);
	*ret_node = pQueue->pElement[pQueue->front];
	pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
	pQueue->currentElementCount--;
	return (ret_node);
}

ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{
    ArrayQueueNode *ret_node;

	if (!pQueue)
		return (FALSE);
    if (isArrayQueueEmpty(pQueue))
        return (FALSE);
	ret_node = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode));
	if (!ret_node)
		return (FALSE);
    *ret_node = pQueue->pElement[pQueue->front];
    return (ret_node);
}

void deleteArrayQueue(ArrayQueue* pQueue)
{
	if (!pQueue)
		return ;
	while (!isArrayQueueEmpty(pQueue))
		free(dequeueAQ(pQueue));
	free(pQueue->pElement);
	free(pQueue);
}

int isArrayQueueFull(ArrayQueue* pQueue)
{
	return (pQueue->maxElementCount == pQueue->currentElementCount ? TRUE : FALSE);
}

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
	return (pQueue->currentElementCount == 0 ? TRUE : FALSE);
}

void displayArrayQueue(ArrayQueue* pQueue)
{
	int idx = pQueue->front;
    if (!pQueue)
        return;
        
    printf("The max size of stack : %d\n", pQueue->maxElementCount);
    printf("The current size of stack : %d\n", pQueue->currentElementCount);
    for (int i = 0; i < pQueue->currentElementCount; i++)
    {
        printf("{index: %d, data: %c}\n", idx, pQueue->pElement[idx].data);
		idx = (idx + 1) % pQueue->maxElementCount;
	}
}