#ifndef _LINKED_QUEUE_
#define _LINKED_QUEUE_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simdef.h"

typedef struct QequeNode
{
	SimCustomer data;
	struct QueueNode* pRLink;
	struct QueueNode* pLLink;
} QueueNode;

typedef struct LinkedQueueType
{
	int currentElementCount;	// ���� ������ ����
	QueueNode* pFrontNode;		// Front ����� ������
	QueueNode* pRearNode;		// Rear ����� ������
} LinkedQueue;

LinkedQueue* 	createLinkedQueue();
int 			insertFrontLD(LinkedQueue* pDeque, QueueNode element);
int 			insertRearLD(LinkedQueue* pDeque, QueueNode element);
QueueNode* 		deleteFrontLD(LinkedQueue* pDeque);
QueueNode* 		deleteRearLD(LinkedQueue* pDeque);
QueueNode* 		peekFrontLD(LinkedQueue* pDeque);
QueueNode* 		peekRearLD(LinkedQueue* pDeque);
void 			deleteLinkedQueue(LinkedQueue* pDeque);
int 			isLinkedQueueFull(LinkedQueue* pDeque);
int 			isLinkedQueueEmpty(LinkedQueue* pDeque);

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0

#endif