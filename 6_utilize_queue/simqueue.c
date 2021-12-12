#include "linkedqueue.h"
#include "simutil.h"

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
		QueueNode *node;
		node = deleteFrontLD(pArrivalQueue); //도착한손님큐에서 빼고 (dequeue)
        QueueNode ele;
		ele.data = node->data;
		insertRearLD(pWaitQueue, ele); //대기큐에 넣기 (enqueue)
		free(node);
		node = 0;
	}
	return ;
}

// 서비스 시작 처리.
QueueNode* processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue)
{
	QueueNode *pServiceNode;

	if (currentTime < 0)
	{
		printf("[error] invalid value : currentTime\n");
		return (FALSE);
	}
	if (pWaitQueue == NULL)
	{
		printf("[error] NULL parameter : pWaitQueue\n");
		return (FALSE);
	}
	if (isLinkedQueueEmpty(pWaitQueue))
	{
		printf("There is no customer waiting\n"); // 대기중인 손님이 없음
		return (FALSE);
	}
	pServiceNode = deleteFrontLD(pWaitQueue); //대기중인손님큐에서 빼고 옮기기 (dequeue)
	pServiceNode->data.status = start;
	pServiceNode->data.startTime = currentTime;
	pServiceNode->data.endTime = pServiceNode->data.startTime + pServiceNode->data.serviceTime;
	return (pServiceNode); //서비스 중인 상태의 서비스 노드 반환
}

// 서비스 종료 처리.
QueueNode* processServiceNodeEnd(int currentTime, QueueNode *pServiceNode,
						int *pServiceUserCount, int *pTotalWaitTime)
{
	if (currentTime < 0)
	{
		printf("[error] invalid value : currentTime\n");
		return (FALSE);
	}
	if (pServiceNode == NULL)
	{
		printf("[error] NULL parameter : pServiceNode\n");
		return (FALSE);
	}
	if (pServiceNode->data.endTime == currentTime)
	{
		(*pTotalWaitTime) += (pServiceNode->data.startTime - pServiceNode->data.arrivalTime);
		(*pServiceUserCount)++;
		pServiceNode->data.status = end;
	} //else처리안함
	return (pServiceNode); //서비스 끝난 상태의 서비스 노드 반환
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
	printf("Current time : %d\n", currentTime); // 현재 시각
	printf("Number of customers waiting : %d\n", pWaitQueue->currentElementCount); // 대기 중인 고객
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
	printf("Number of served customers : %d\n", ServiceUserCount); // 처리한 고객 수
	printf("Total wait time : %d\n", ptotalWaitTime); // 총 대기 시간
}