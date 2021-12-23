#include "mst.h"

void		put_firstHeapNode(ArrayGraph *pGraph, int *visited, ArrayHeap *heap)
{
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->ppAdjEdge[0][i] != 0)
		{
			ArrayHeapNode element;
			element.weight = pGraph->ppAdjEdge[0][i];
			element.x = i;
			element.y = 0;
			insertHeapAH(heap, element);
		}
	} // 힙에 첫번째 노드를 넣음
	visited[0] = 1;
}

ArrayGraph *prim(ArrayGraph *pGraph)
{
	if (!error_nullparameter(pGraph, "pGraph"))
		return (NULL); // null parameter일 경우
	int *visited = (int *)calloc(pGraph->maxVertexCount, sizeof(int));
	if (!error_mallocfailure(visited, "visited"))
		return (NULL);
	ArrayGraph *ret_graph = createArrayGraph(pGraph->maxVertexCount);
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		addVertexAG(ret_graph, i);
	ArrayHeap *heap = createArrayHeap(pGraph->maxVertexCount);
	put_firstHeapNode(pGraph, visited, heap); // 힙에 첫 노드를 넣어줌
	while (!isArrayHeapEmpty(heap))
	{
		ArrayHeapNode *pop = deleteHeapAH(heap);
		if (visited[pop->x] == 0) // cycle 여부는 visited로 검사.
		{
			addEdgewithWeightAG(ret_graph, pop->y, pop->x, pop->weight);
			visited[pop->x] = 1;
			for (int i = 0; i < pGraph->maxVertexCount; i++)
			{
				if (pGraph->ppAdjEdge[pop->x][i] != 0)
				{
					ArrayHeapNode element;
					element.y = pop->x;
					element.x = i;
					element.weight = pGraph->ppAdjEdge[pop->x][i];
					insertHeapAH(heap, element);
				}
			}
		}
		free(pop);
		pop = 0;
	} // bfs 처럼 ;  힙에 넣은 노드를 하나 뺴고 그와 연결된 노드를 다 힙에 넣어주고를 반복
	free(visited);
	visited = 0;
	deleteArrayHeap(heap);
	heap = 0;
	return (ret_graph);
}
// 0 부터 시작


// 0이랑 연결된 간선들 전부 힙에 넣기
// 하나 뽑아서 0이랑 연결하고
// 거기서 이어진 노드랑 연결된 간선들 또 넣기