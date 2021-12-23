#include "mst.h"

ArrayGraph    *fill_newArrayGraph_floyd(ArrayGraph *pGraph, int maxCount)
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
			else if (pGraph->ppAdjEdge[i][j] == 0)
				ret_graph->ppAdjEdge[i][j] = INF;
			else
				ret_graph->ppAdjEdge[i][j] = pGraph->ppAdjEdge[i][j];
        }
    } // ret_graph의 인접행렬 만든다. 자기자신을 제외하고, 해당 노드에 연결되지 않은 쪽 열에는 인접행렬에 무한값 넣어줌.
	return (ret_graph);
}

ArrayGraph  *floyd(ArrayGraph *pGraph)
{
	int maxCount = pGraph->maxVertexCount;

    if (!error_nullparameter(pGraph, "pGraph"))
        return (NULL); // FALSE (= 0)
	ArrayGraph *ret_graph = fill_newArrayGraph_floyd(pGraph, maxCount);
	for (int i = 0; i < maxCount; i++) // 출발 노드
		for (int j = 0; j < maxCount; j++) // 도착 노드
			for (int k = 0; k < maxCount; k++) // 거쳐가는 노드
				if (i != j)
					ret_graph->ppAdjEdge[i][j] = ft_min(ret_graph->ppAdjEdge[i][j], (long long)ret_graph->ppAdjEdge[i][k] + ret_graph->ppAdjEdge[k][j]);
    return (ret_graph);
}
// floyd를 실행했을 때 만들어지는 인접행렬 행 : 노드 i, 열 : 이번 노드 i에서 j번째 노드로 가는데 드는 최소 비용
