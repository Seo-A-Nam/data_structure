#include "linkedqueue.h"
#include "simutil.h"

int		put_customerData(LinkedQueue *pArrivalQueue)
{
	int n = 0, arrivalTime = 0, serviceTime = 0, prev = -1;

	printf("\n--------------------------------------------------------------\n");
	printf("How many customers? : ");
	scanf(" %d", &n); // 고객 수
	if (n <= 0)
	{
		printf("[error] Invalid value : n\n");
		return (FALSE);
	}
	printf("\n");
	printf("Put each customer's arrival time and service time in order\n\n");
	for (int i = 0; i < n; i++)
	{
		printf("customer [%d]\n", i + 1);
		printf("arrival : ");
		scanf(" %d", &arrivalTime);
		if (prev > arrivalTime)
		{
			printf("[error] Out of Order : Typed custumer data\n");
			return (FALSE);
		}
		printf("service : ");
		scanf(" %d", &serviceTime);
		printf("\n");
		if (serviceTime <= 0)
		{
			printf("[error] Invalid value : serviceTime\n");
			return (FALSE);
		}
		insertCustomer(arrivalTime, serviceTime, pArrivalQueue);
		prev = arrivalTime;
	}
	return (TRUE);
}

void	statusCheck(LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue, int currentTime)
{
	printf("===============================================================\n");
	printf("Status Check :\n\n");
	printf("<Arrrival Queue>\n");	
	printWaitQueueStatus(currentTime, pArrivalQueue); //기다리는 고객 출력
	printf("\n<Wait Queue>\n");
	printWaitQueueStatus(currentTime, pWaitQueue);
	printf("\n");
}

int		check_error(int err_flag)
{
	if (err_flag == 0)
	{
		printf("[error] Terminate the Test Program.\n");
		return (TRUE);
	}
	return (FALSE);
}

void	processQueue(LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue, int currentTime)
{
	if ((!isLinkedQueueEmpty(pArrivalQueue)) && pArrivalQueue->pFrontNode->data.arrivalTime == currentTime)
	{
		processArrival(currentTime, pArrivalQueue, pWaitQueue);
		if (!isLinkedQueueEmpty(pWaitQueue))
			printSimCustomer(currentTime, pWaitQueue->pFrontNode->data);
	}
}

int		processServiceNode(LinkedQueue *pWaitQueue, QueueNode **pServiceNode, int *ServiceUserCount, int *pTotalWaitTime, int currentTime)
{
	printf("===============================================================\n");
	printf("Process >>>\n");
	if (!(*pServiceNode))
	{
		(*pServiceNode) = processServiceNodeStart(currentTime, pWaitQueue);
		if (!(*pServiceNode))
			return (FALSE);
		printSimCustomer(currentTime, (*pServiceNode)->data);
	}
	else if (*pServiceNode)
	{
		QueueNode *node;
		node = processServiceNodeEnd(currentTime, (*pServiceNode), ServiceUserCount, pTotalWaitTime);
		if (!node)
			return (FALSE);
		if (node->data.status == end)
		{
			printSimCustomer(currentTime, (*pServiceNode)->data);
			free(*pServiceNode);
			*pServiceNode = 0;
			if (!isLinkedQueueEmpty(pWaitQueue))
			{
				(*pServiceNode) = processServiceNodeStart(currentTime, pWaitQueue);
				if (!(*pServiceNode))
					return (FALSE);
				printSimCustomer(currentTime, (*pServiceNode)->data);
			}
		}
	}
	return (TRUE);
}

void	test()
{
	/*고객 도착 큐 -> 고객 대기 큐 -> 서비스 -> 메모리 해제(완료)*/
	LinkedQueue *pArrivalQueue = createLinkedQueue();
	LinkedQueue *pWaitQueue = createLinkedQueue();
	QueueNode *pServiceNode = NULL;
	int currentTime = 0;
	int ServiceUserCount = 0;
	int pTotalWaitTime = 0;
	int err_flag = 1;

	err_flag = put_customerData(pArrivalQueue);
	if (check_error(err_flag))
		return ;
	while (1)
	{
		if (isLinkedQueueEmpty(pArrivalQueue) && isLinkedQueueEmpty(pWaitQueue))
		{
			if (!pServiceNode)
				break;
		}
		processQueue(pArrivalQueue, pWaitQueue, currentTime);
		statusCheck(pArrivalQueue, pWaitQueue, currentTime);
		err_flag = processServiceNode(pWaitQueue, &pServiceNode, &ServiceUserCount, &pTotalWaitTime, currentTime);
		if (check_error(err_flag))
			return ;
		currentTime++;	
	}
	printf("\n============================ DONE =============================\n");
	printReport(pWaitQueue, ServiceUserCount, pTotalWaitTime);
	printf("\n\n");
	deleteLinkedQueue(pArrivalQueue);
	deleteLinkedQueue(pWaitQueue);
}

int		main()
{
	test();
	system("leaks a.out");
	return (0);
}