#include "linkedgraph.h"

// 재귀적으로 노드를 탐색하는 함수. 해당 노드의 인접리스트를 확인하여 그에 연결된 노드들을 찾아가며 탐색한다. 
void traversal_DFS_recur(LinkedGraph *pGraph, int from)
{
	printf("%d ", from);
	pGraph->pVertex[from] = VISITED;
	ListNode *now = pGraph->ppAdjEdge[from]->headerNode.pLink;
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (now == NULL)
			break;
		if (pGraph->pVertex[now->to] == USED) // 내가 앞으로 들어갈 방향이 i
		{
			traversal_DFS_recur(pGraph, now->to);
		}
		now = now->pLink;
	}
}

/* 모든 노드를 탐색하는 함수. 노드를 찾으면 재귀함수인 traversal_DFS_recur()을 호출한다. 
* 이때 해당 노드에 연결된 다른 노드들이 출력되며 해당 노드의 상태는 visited로 바뀜 - 원상복구시켜주는 건 나중에 main 함수에서 할 예정
* 이때 반복문을 돌며 아직 방문하지 않은 노드들을 마저 찾아 출력하고, 그에 연결된 노드가 있다면 재귀로 들어가 그것들을 쭉 출력해주는 것을 반복한다. 
*/
void traversal_DFS(LinkedGraph *pGraph)
{
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->pVertex[i] == USED)
		{
			traversal_DFS_recur(pGraph, i); // 간선으로 연결된 노드들 싹 돌고 나옴.
			printf("\n");
		}
	}
}

/* 모든 노드들을 탐색하는 함수. for문을 돌며 노드를 찾아 먼저 큐에 넣어준다. 
* 그리고 그 while문을 돌며 그 큐가 빌 때까지 현재 노드에 연결된 노드 모두 추가 -> 나중에 그 노드 다시 빼주어 출력하고 그에 연결된 노드 또 모두 추가 이 과정 반복 
* 이때 노드들이 출력되며 해당 노드의 상태는 visited로 바뀜 - 원상복구시켜주는 건 나중에 main 함수에서 할 예정
* 내가 찾은 노드의 연결된 노드들까지 출력해주는 게 전부 완료되었다면, 가장 바깥쪽의 for() 반복문을 돌며 아직 방문하지 않은 노드들을 마저 찾아 그에 연결된 노드들을 쭉 출력해주는 것을 반복한다. 
*/
void traversal_BFS(LinkedGraph *pGraph)
{
	ArrayQueue *queue = createArrayQueue(pGraph->maxVertexCount);
	ArrayQueueNode tmp;

	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->pVertex[i] == USED) // 내가 앞으로 들어갈 방향이 i
		{
			tmp.data = i;
			enqueueAQ(queue, tmp);
			pGraph->pVertex[i] = VISITED;
			while (!isArrayQueueEmpty(queue))
			{
				ArrayQueueNode *now;
				now = dequeueAQ(queue);
				printf("%d ", now->data);
				ListNode *next = pGraph->ppAdjEdge[now->data]->headerNode.pLink;
				for (int j = 0; j < pGraph->ppAdjEdge[now->data]->currentElementCount; j++)
				{
					if (next == NULL)
						break;
					if (pGraph->pVertex[next->to] == USED)
					{
						tmp.data = next->to;
						enqueueAQ(queue, tmp);
						pGraph->pVertex[tmp.data] = VISITED;
					}
					next = next->pLink;
				}
				free(now);
			}
			printf("\n");
		}
	}
	deleteArrayQueue(queue);
}