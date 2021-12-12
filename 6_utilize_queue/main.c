#include "linkedqueue.h"
#include "simutil.h"

void	put_customerData(int n, LinkedQueue *pArrivalQueue)
{
	int arrivalTime = 0, serviceTime = 0;

	for (int i = 0; i < n; i++)
	{
		printf("customer [%d]\n", i + 1);
		printf("arrival : ");
		scanf(" %d", &arrivalTime);
		printf("service : ");
		scanf(" %d", &serviceTime);
		printf("\n");
		insertCustomer(arrivalTime, serviceTime, pArrivalQueue);
	}
}

int		test()
{
	/*고객 도착 큐 -> 고객 대기 큐 -> 서비스 -> 메모리 해제(완료)*/
	LinkedQueue *pArrivalQueue = createLinkedQueue();
	LinkedQueue *pWaitQueue = createLinkedQueue();
	QueueNode *pServiceNode = NULL;
	int n = 0; // 고객 수
	int currentTime = 0;
	int ServiceUserCount = 0;
	int pTotalWaitTime = 0;


	printf("---------------------------------------------------------------\n");
	printf("How many customers? : ");
	scanf(" %d", &n);
	printf("\n");
	printf("Put each customer's arrival time and service time in order\n\n");
	put_customerData(n, pArrivalQueue);
	while (1)
	{
		if (isLinkedQueueEmpty(pArrivalQueue) && isLinkedQueueEmpty(pWaitQueue))
		{
			if (!pServiceNode)
				break;
		}
		printf("===============================================================\n");
		printf("Status Check :\n");
		
		if ((!isLinkedQueueEmpty(pArrivalQueue)) && pArrivalQueue->pFrontNode->data.arrivalTime == currentTime)
			processArrival(currentTime, pArrivalQueue, pWaitQueue);
		printf("도착 큐 >>\n");
		printWaitQueueStatus(currentTime, pArrivalQueue); //기다리는 고객 출력
		printf("\n대기 큐 >>\n");
		printWaitQueueStatus(currentTime, pWaitQueue);
		//printSimCustomer(currentTime, pArrivalQueue->pFrontNode->data); //customer가 선언되지 않음
		
		printf("Process :\n");
		
		if (!pServiceNode)
		{
			pServiceNode = processServiceNodeStart(currentTime, pWaitQueue);
			printSimCustomer(currentTime, pServiceNode->data);
			//printf("check1\n");
		}
		if (pServiceNode)
		{
			QueueNode *node;
			node = processServiceNodeEnd(currentTime, pServiceNode, &ServiceUserCount, &pTotalWaitTime);
			if (!node)
			{
				printSimCustomer(currentTime, pServiceNode->data);
				free(pServiceNode);
				pServiceNode = 0;
				if (!isLinkedQueueEmpty(pWaitQueue))
				{
					pServiceNode = processServiceNodeStart(currentTime, pWaitQueue);
					printSimCustomer(currentTime, pServiceNode->data);
				}
			}
			//free(pServiceNode);
			//pServiceNode = 0;
			//	printf("check3\n");
		}
		
		//}
		currentTime++;	
	}
	printf("\nDONE =============================================================\n");
	printReport(pWaitQueue, ServiceUserCount, pTotalWaitTime);
	pArrivalQueue = 0;
	pWaitQueue = 0;
	//deleteLinkedQueue(pArrivalQueue);
	//deleteLinkedQueue(pWaitQueue);
	//free(pArrivalQueue);
	//free(pWaitQueue);
	//printf("%d\t%d\n", pArrivalQueue->currentElementCount, pWaitQueue->currentElementCount);
	return (0);
}

int		main()
{
	test();
	system("leaks a.out");
	return (0);
}