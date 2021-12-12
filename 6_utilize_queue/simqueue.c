#include "linkedqueue.h"
#include "simutil.h"

/*
typedef enum SimStatusType { arrival, start, end } SimStatus;

typedef struct SimCustomerType
{
	SimStatus status;
	int arrivalTime;	// 도착 시간
	int serviceTime;	// 서비스 시간
	int startTime;		// 시작 시간
	int endTime;		// 종료 시각 : 시작 시각 + 서비스 시간.
} SimCustomer;
typedef struct QequeNodeType
{
	SimCustomer data;
	struct QueueNodeType* pRLink;
	struct QueueNodeType* pLLink;
} QueueNode;

typedef struct LinkedQueueType
{
	int currentElementCount;	// ���� ������ ����
	QueueNode* pFrontNode;		// Front ����� ������
	QueueNode* pRearNode;		// Rear ����� ������
} LinkedQueue;
*/

/*고객 도착 큐 -> 고객 대기 큐 -> 서비스 -> 메모리 해제(완료)*/

// 고객 도착 큐에 고객 추가.
void insertCustomer(int arrivalTime, int processTime, LinkedQueue *pArrivalQueue)
{
	QueueNode ele;

	if (arrivalTime < 0 || processTime < 0)
	{
		printf("[error] invalid value : arrivalTime or processTime\n");
		return ;
	}
	if (pArrivalQueue == NULL)
	{
		printf("[error] NULL parameter : pArrivalQueue\n");
		return ;
	}
	memset(&ele, 0, sizeof(QueueNode));
	ele.data.arrivalTime = arrivalTime;
	ele.data.serviceTime = processTime;
	ele.data.status = arrival;
	insertRearLD(pArrivalQueue, ele);
}

// 고객 도착 처리.
void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue)
{
	QueueNode *Node;

	if (currentTime < 0)
	{
		printf("[error] invalid value : currentTime\n");
		return ;
	}
	if (pArrivalQueue == NULL)
	{
		printf("[error] NULL parameter : pArrivalQueue\n");
		return ;
	}
	if (pWaitQueue == NULL)
	{
		printf("[error] NULL parameter : pWaitQueue\n");
		return ;
	}
	if (isLinkedQueueEmpty(pArrivalQueue))
		return ;
	Node = peekFrontLD(pArrivalQueue); //도착한 손님들중 젤 위를 peek
	if (Node->data.arrivalTime <= currentTime)//손님이 도착한 시간에
	{
		Node = deleteFrontLD(pArrivalQueue); //도착한손님큐에서 빼고 (dequeue)
        QueueNode ele;
		ele.data.arrivalTime = Node->data.arrivalTime;
		ele.data.endTime = Node->data.endTime;
		ele.data.serviceTime = Node->data.serviceTime;
		insertRearLD(pWaitQueue, ele); //대기큐에 넣기 (enqueue)
		free(Node);
		Node = 0;
	}
	return ;
}

// 서비스 시작 처리.
QueueNode* processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue)
{
	QueueNode *pServiceNode;

	//if (currentTime < 0)
	//{
	//	printf("[error] invalid value : currentTime\n");
	//	return ;
	//}
	//if (pWaitQueue == NULL)
	//
	//	printf("[error] NULL parameter : pWaitQueue\n");
	//	return ;
	//}
	//if (isLinkedDequeEmpty(pWaitQueue))
	//{
	//	printf("대기중인 손님이 없음\n");
	//	return ;
	//}
	
	pServiceNode = (QueueNode *)malloc(sizeof(QueueNode *));
	if (isLinkedQueueEmpty(pWaitQueue))
	{
		printf("!!!대기 큐 비어있음!!!\n");
		//processArrival(0, )
	}
	if (!(isLinkedQueueEmpty(pWaitQueue)))
	{
		pServiceNode = deleteFrontLD(pWaitQueue); //대기중인손님큐에서 빼고 옮기기 (dequeue)
		pServiceNode->data.status = start;
		pServiceNode->data.startTime = currentTime;
		pServiceNode->data.endTime = pServiceNode->data.startTime + pServiceNode->data.serviceTime;
		printf("data->startTime : %d\tdata.arrivalTime : %d\n", pServiceNode->data.startTime, pServiceNode->data.arrivalTime);
	}
	return (pServiceNode); //서비스중인 상태의 서비스 노드 반환
}

// 서비스 종료 처리.
QueueNode* processServiceNodeEnd(int currentTime, QueueNode *pServiceNode,
						int *pServiceUserCount, int *pTotalWaitTime)
{
	//if (currentTime < 0)
	//{
	//	printf("[error] invalid value : currentTime\n");
	//	return (FALSE);
	//}
	//if (pServiceNode == NULL)
	//{
	//	printf("[error] NULL parameter : pServiceNode\n");
	//	return (FALSE);
	//}
	if (pServiceNode->data.endTime == currentTime)
	{
		
		//printf("data->startTime : %d\tdata.arrivalTime : %d\n", pServiceNode->data.startTime, pServiceNode->data.arrivalTime);
		(*pTotalWaitTime) += (pServiceNode->data.startTime - pServiceNode->data.arrivalTime);
		(*pServiceUserCount)++;
		printf("check!!!");
		printf("pTotalWaitTime : %d\tpServiceUserCount : %d\n", *pTotalWaitTime, *pServiceUserCount);
		//pServiceNode = (QueueNode *)(pServiceNode->pRLink);
		pServiceNode->data.status = end;
		//free(pServiceNode);
		//pServiceNode = 0;
		return (0);
	}//else처리안함
	return (pServiceNode);//서비스 끝난 상태의 서비스 노드 반환
}

// 고객의 상태를 출력
void printSimCustomer(int currentTime, SimCustomer customer)
{
	if (currentTime < 0)
	{
		printf("[error] invalid value : currentTime\n");
		return ;
	}
	printf("customer status : ");
	switch (customer.status)
	{
	case arrival :
		printf("arrival\n"); 
		break;
	case start : 
		printf("start\n");
		break;
	case end :
		printf("end\n");
		break;
	default:
		printf("none\n");
		break;
	}
}

// 대기열의 상태를 출력
void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue)
{
	if (currentTime < 0)
	{
		printf("[error] invalid value : currentTime\n");
		return ;
	}
	if (pWaitQueue == NULL)
	{
		printf("[error] NULL parameter : pWaitQueue\n");
		return ;
	}
	printf("현재 시각 : %d\n", currentTime);
	printf("대기중인 고객 : %d\n", pWaitQueue->currentElementCount);
}

// 최종 시뮬레이션 결과(통게치) 출력.
void printReport(LinkedQueue *pWaitQueue,
				 int ServiceUserCount,
				 int ptotalWaitTime)
{
	if (ptotalWaitTime < 0 || ServiceUserCount < 0)
	{
		printf("[error] invalid value : totalWaitTime or ServiceUserCount\n");
		return ;
	}
	if (pWaitQueue == NULL)
	{
		printf("[error] NULL parameter : pWaitQueue\n");
		return ;
	}
	printf("처리한 고객 수 : %d\n", ServiceUserCount);
	printf("총 대기 시간 : %d\n", ptotalWaitTime);
    deleteLinkedQueue(pWaitQueue);
}