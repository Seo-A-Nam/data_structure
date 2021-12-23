#include "mst.h"

bool chk;

int find(int dot, int *parent) // find : 가장 윗대가리 부모를 찾는다.
{
    if (dot == parent[dot])
        return dot;
    return parent[dot] = find(parent[dot], parent);
}

void merge(int start, int end, int *parent) // union : 같은 그룹인지
{
	chk = false;
	start = find(start, parent);
	end = find(end, parent);
	
	if (start == end)
		return ;
	parent[start] = end; // 무조건 어느 하나는 누구의 부모가 된다.
	chk = true;
}

void	move_Graph2Heap(ArrayGraph *pGraph, ArrayHeap *heap)
{
    if (!error_nullparameter(pGraph, "pGraph") || !error_nullparameter(heap, "heap"))
        return ;
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		for (int j = 0; j < pGraph->maxVertexCount; j++)
		{
			if (pGraph->ppAdjEdge[i][j] != 0)
			{
                // arrayheap 구조체에서 x(열), y(행)을\ 데이터로 받을 수 있도록 구조체를 수정함.
				ArrayHeapNode element;
				element.y = i;
				element.x = j;
				element.weight = pGraph->ppAdjEdge[i][j];
                insertHeapAH(heap, element);
			}
		}
	}
}

ArrayGraph *kruskal(ArrayGraph *pGraph)
{
    if (!error_nullparameter(pGraph, "pGraph"))
        return (NULL); // FALSE (= 0)
	ArrayGraph *ret_graph = createArrayDirectedGraph(pGraph->maxVertexCount);
    for (int i = 0; i < pGraph->maxVertexCount; i++)
		addVertexAG(ret_graph, i); // 새 그래프에 기존 그래프만큼 노드를 만들어줌. 
	ArrayHeap *heap = createArrayHeap(pGraph->currentEdgeCount);
	move_Graph2Heap(pGraph, heap);
	int *parent = (int *)malloc(sizeof(int) * (pGraph->maxVertexCount));
    if (!error_mallocfailure(parent, "parent"))
        return (NULL);
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		parent[i] = i; // parent 배열을 채워줌 : 초기값 - 자신이 자기자신의 parent
    while (!isArrayHeapEmpty(heap))
	{
		ArrayHeapNode *pop = deleteHeapAH(heap);
		merge(pop->y, pop->x, parent);
		if (chk) // cycle이 생기지 않는다면
		{
			addEdgewithWeightAG(ret_graph, pop->y, pop->x, pop->weight);
			addEdgewithWeightAG(ret_graph, pop->x, pop->y, pop->weight);
		} // 무방향 그래프.
        free(pop);
        pop = 0;
	}
	free(parent);
	parent = 0;
	deleteArrayHeap(heap);
	heap = 0;
	return (ret_graph);
}
/* 
* 원래의 그래프를 min_heap에 담아 정렬한다 -> 힙에서 노드-간선 정보를 하나씩 빼면서, 그게 사이클을 형성하지 않는다면 새 그래프에 하나씩 넣어준다.  
* cycle 없이 탐색할 때 간선의 개수를 n - 1로 맞출 것이기 때문에, 노드^2만큼 인접행렬을 할당하는 arraygraph는 비효율적 
* 따라서 경우에 따라 linkedgraph가 더 효율적이 될 수도 있다.
*/