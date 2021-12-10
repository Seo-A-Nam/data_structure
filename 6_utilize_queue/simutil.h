#ifndef _SIM_UTIL_
#define _SIM_UTIL_

// 고객 도착 큐에 고객 추가.1
void insertCustomer(int arrivalTime, int processTime, LinkedQueue *pQueue);

// 고객 도착 처리.2
void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue);

// 서비스 시작 처리.3
QueueNode* processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue);

// 서비스 종료 처리.4
QueueNode* processServiceNodeEnd(int currentTime, QueueNode *pServiceNode,
					  int *pServiceUserCount, int *pTotalWaitTime);

// 고객의 상태를 출력
void printSimCustomer(int currentTime, SimCustomer customer);

// 대기열의 상태를 출력
void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue);

// 최종 시뮬레이션 결과(통게치) 출력.
void printReport(LinkedQueue *pWaitQueue,
				 int serviceUserCount,
				 int totalWaitTime);

#endif