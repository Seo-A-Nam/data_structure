#include "mst.h"

ArrayGraph  *fill_newArrayGraph_Dijkstra(int maxCount)
{
	ArrayGraph *ret_graph = createArrayGraph(maxCount);

	for (int i = 0; i < maxCount; i++)
		addVertexAG(ret_graph, i);
	for (int i = 0; i < maxCount; i++)
	{
		for (int j = 0; j < maxCount; j++)
		{
			if (i == j)
				ret_graph->ppAdjEdge[i][j] = 0;
			else
				ret_graph->ppAdjEdge[i][j] = INF;
		}
	} // ret_graph의 인접행렬 만든다. 자기자신을 제외하고, 모든 인접행렬의 열 값에 무한 값을 넣어준다.
	return (ret_graph);
}

ArrayHeapNode *make_element(int x, int y, int weight)
{
	ArrayHeapNode *element;

	element = (ArrayHeapNode *)malloc(sizeof(ArrayHeapNode));
	element->x = x;
	element->y = y;
	element->weight = weight;
	return (element);
}

void find_Dijkstra(int i, ArrayGraph *ret_graph, ArrayGraph *pGraph)
{
	ArrayHeap *heap = createArrayHeap(pGraph->currentEdgeCount);
	ArrayHeapNode *element = make_element(i, i, 0);
	int **Edge = ret_graph->ppAdjEdge;

	insertHeapAH(heap, *element); 
	free(element); // 첫번째 노드를 삽입한다. 자기 노드에 대해 스스로의 거리는 0.
	while (!isArrayHeapEmpty(heap))
	{
		ArrayHeapNode *curr = deleteHeapAH(heap);
		if (Edge[i][curr->x] != curr->weight)
		{
			free(curr);
			curr = 0;
			continue;
		}
		for (int j = 0; j < pGraph->maxVertexCount; j++)
		{
			if (pGraph->ppAdjEdge[curr->x][j] != 0)
			{
				if (Edge[i][j] > Edge[i][curr->x] + pGraph->ppAdjEdge[curr->x][j])
				{	
					Edge[i][j] = Edge[i][curr->x] + pGraph->ppAdjEdge[curr->x][j]; // 나(curr->x)까지 오는 거와 여기서 쟤(j)까지 가는 걸 더함. 그게 i~j까지 보다 더 가까우면 바꿈.
					element = make_element(j, curr->x, Edge[i][j]);
					insertHeapAH(heap, *element);
					free(element);
				}
			}
		}
		free(curr);
		curr = 0;
	}
    deleteArrayHeap(heap);
    heap = 0;
}

ArrayGraph *Dijkstra(ArrayGraph *pGraph)
{
	if (!(error_nullparameter(pGraph, "pGraph")))
		return (NULL);
	int vc = pGraph->maxVertexCount; // vertex count
	ArrayGraph *ret_graph = fill_newArrayGraph_Dijkstra(vc);

	for (int i = 0; i < vc; i++)
		find_Dijkstra(i, ret_graph, pGraph);
	return (ret_graph);
} // 0번 노드에서 어떻게 가장 짧게 가느냐?