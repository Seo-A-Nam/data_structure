#ifndef _CIRCULAR_QUEUE_
#define _CIRCULAR_QUEUE_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Copy + Modified previous arrayqueue files 
// 기존의 arrayqueue 파일을 가져와서 함수 몇 개만(인큐, 디큐) 고쳤음

// rear = (rear + 1) % maxElementCount <- 이게 제일 중요.

typedef struct CircularQueueNodeType
{
	char data;
} CircularQueueNode;

typedef struct CircularQueueType
{
	int maxElementCount;
	int currentElementCount;
	int front;
	int rear;
	CircularQueueNode *pElement;
} CircularQueue;

CircularQueue* 		createCircularQueue(int maxElementCount);
int 				enqueueCQ(CircularQueue* pQueue, CircularQueueNode element);
CircularQueueNode 	*dequeueCQ(CircularQueue* pQueue);
CircularQueueNode 	*peekCQ(CircularQueue* pQueue);
void 				deleteCircularQueue(CircularQueue* pQueue);
int 				isCircularQueueFull(CircularQueue* pQueue);
int 				isCircularQueueEmpty(CircularQueue* pQueue);

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0

#endif