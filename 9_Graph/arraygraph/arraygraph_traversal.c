#include "arraygraph.h"

void traversal_DFS_recur(ArrayGraph *pGraph, int from)
{
	printf("%d ", from);
	pGraph->pVertex[from] = VISITED;
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->ppAdjEdge[from][i] > 0 && pGraph->pVertex[i] == USED) // 내가 앞으로 들어갈 방향이 i
		{
			traversal_DFS_recur(pGraph, i);
		}
	}
}

void traversal_DFS(ArrayGraph *pGraph)
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

void traversal_BFS(ArrayGraph *pGraph)
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
				for (int j = 0; j < pGraph->maxVertexCount; j++)
				{
					if (pGraph->ppAdjEdge[now->data][j] != 0 && pGraph->pVertex[j] == USED)
					{
						tmp.data = j;
						enqueueAQ(queue, tmp);
						pGraph->pVertex[j] = VISITED;
					}
				}
				free(now);
			}
			printf("\n");
		}
	}
	deleteArrayQueue(queue);
}