#include "linkedqueue.h"
#include "simutil.h"

int		test()
{
	/*고객 도착 큐 -> 고객 대기 큐 -> 서비스 -> 메모리 해제(완료)*/
	LinkedQueue *pArrivalQueue = createLinkedQueue();
	LinkedQueue *pWaitQueue = createLinkedQueue();
	LinkedQueue *phead1 = pArrivalQueue;
	LinkedQueue *phead2 = pWaitQueue;
	QueueNode *pServiceNode = NULL;
	int currentTime = 0;
	int n = 0; // 고객 수
	int ServiceUserCount = 0;
	int pTotalWaitTime = 0;

	printf("---------------------------------------------------------------\n");
	printf("How many customers? : ");
	scanf(" %d", &n);
	printf("\n");
	printf("Put each customer's arrival time and service time in order\n\n");
	for (int i = 0; i < n; i++)
	{
		printf("custemer [%d]\n", i + 1);
		int arrivalTime = 0, serviceTime = 0;
		printf("arrival : ");
		scanf(" %d", &arrivalTime);
		printf("service : ");
		scanf(" %d", &serviceTime);
		printf("\n");
		insertCustomer(arrivalTime, serviceTime, pArrivalQueue);
	}
	while (currentTime < 15)
	{
		printf("===============================================================\n");
		printf("Status Check :\n");
		printWaitQueueStatus(currentTime, pArrivalQueue); //기다리는 고객 출력
		//printSimCustomer(currentTime, pArrivalQueue->pFrontNode->data); //customer가 선언되지 않음
		
		printf("Process :\n");
		if (!isLinkedQueueEmpty(pArrivalQueue))
			processArrival(currentTime, pArrivalQueue, pWaitQueue);
		if (pServiceNode)
		{
			pServiceNode = processServiceNodeEnd(currentTime, pServiceNode, &ServiceUserCount, &pTotalWaitTime);
			if (pServiceNode)
				printSimCustomer(currentTime, pServiceNode->data);
			//	printf("check3\n");
		}
		if (!pServiceNode)
		{
			//printf("check0\n");
		//printSimCustomer(currentTime, pServiceNode->data);
			pServiceNode = processServiceNodeStart(currentTime, pWaitQueue);
			//printf("check1\n");
		}
		//}
		currentTime++;	
	}
	printf("\nDONE =============================================================\n");
	printReport(pWaitQueue, ServiceUserCount, pTotalWaitTime);
    //eleteLinkedQueue(phead1);
    //deleteLinkedQueue(phead2);
	return (0);
}

int		main()
{
	test();
	//system("leaks a.out");
	return (0);
}