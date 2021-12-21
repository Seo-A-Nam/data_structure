#include "arraygraph.h"


// malloc 실패 시 기존의 메모리들을 free() 해주는 함수.
static void free_all(ArrayGraph *arraygraph)
{
	for (int j = 0; j < arraygraph->maxVertexCount; j++)
	{
		if (arraygraph->ppAdjEdge[j]) // 있는 것 까지만 free()
		{
			free(arraygraph->ppAdjEdge[j]);
			arraygraph->ppAdjEdge[j] = 0;
		}
	}
	if (arraygraph->ppAdjEdge)
	{
		free(arraygraph->ppAdjEdge);
		arraygraph->ppAdjEdge = 0;
	}
	if (arraygraph->pVertex)
	{
		free(arraygraph->pVertex);
		arraygraph->pVertex = 0;
	}
	if (arraygraph)
	{
		free(arraygraph);
		arraygraph = 0;
	}
} 

ArrayGraph *createArrayGraph(int maxVertexCount)
{
	ArrayGraph *arraygraph;

	if (maxVertexCount <= 0)
	{
		printf("[error] invalid value : maxVertexCount\n");
		return (NULL);
	}
	arraygraph = (ArrayGraph *)malloc(sizeof(ArrayGraph));
	if (!arraygraph)
	{
		printf("[error] malloc failure : arraygraph\n");
		return (NULL);
	}
	arraygraph->maxVertexCount = maxVertexCount;
	arraygraph->currentVertexCount = 0;
	arraygraph->graphType = GRAPH_UNDIRECTED;
	arraygraph->ppAdjEdge = (int **)calloc(maxVertexCount, sizeof(int *));
	if (!arraygraph->ppAdjEdge)
	{
		printf("[error] malloc failure : ppAdjEdge\n");
		return (NULL);
	}
	for (int i = 0; i < maxVertexCount; i++)
	{
		arraygraph->ppAdjEdge[i] = (int *)calloc(maxVertexCount, sizeof(int));
		if (!arraygraph->ppAdjEdge[i])
		{
			printf("[error] malloc failure : ppAdjEdge[%d]\n", i);
			free_all(arraygraph);
			return (NULL);
		}
	}
	arraygraph->pVertex = (int *)calloc(maxVertexCount, sizeof(int));
	if (!arraygraph->pVertex)
	{
		printf("[error] malloc failure : pVertex\n");
		free_all(arraygraph);
		return (NULL);
	}
	return (arraygraph);
}

ArrayGraph *createArrayDirectedGraph(int maxVertexCount)
{
	ArrayGraph *arraydgraph;

	if (maxVertexCount <= 0)
	{
		printf("[error] invalid value : maxVertexCount\n");
		return (NULL);
	}
	arraydgraph = (ArrayGraph *)malloc(sizeof(ArrayGraph));
	if (!arraydgraph)
	{
		printf("[error] malloc failure : arraydgraph\n");
		return (NULL);
	}
	arraydgraph->maxVertexCount = maxVertexCount;
	arraydgraph->currentVertexCount = 0;
	arraydgraph->graphType = GRAPH_DIRECTED;
	arraydgraph->ppAdjEdge = (int **)calloc(maxVertexCount, sizeof(int *));
	if (!arraydgraph->ppAdjEdge)
	{
		printf("[error] malloc failure : ppAdjEdge\n");
		return (NULL);
	}
	for (int i = 0; i < maxVertexCount; i++)
	{
		arraydgraph->ppAdjEdge[i] = (int *)calloc(maxVertexCount, sizeof(int));
		if (!arraydgraph->ppAdjEdge[i])
		{
			printf("[error] malloc failure : ppAdjEdge[%d]\n", i);
			free_all(arraydgraph);
			return (NULL);
		}
	}
	arraydgraph->pVertex = (int *)calloc(maxVertexCount, sizeof(int));
	if (!arraydgraph->pVertex)
	{
		printf("[error] malloc failure : pVertex\n");
		free_all(arraydgraph);
		return (NULL);
	}
	return (arraydgraph);
}

void deleteArrayGraph(ArrayGraph *pGraph)
{
	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return;
	}
	free_all(pGraph);
}

int isEmptyAG(ArrayGraph *pGraph)
{
	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return (FALSE);
	}
	if (pGraph->currentVertexCount == 0)
		return (TRUE);
	return (FALSE);
}

int addVertexAG(ArrayGraph *pGraph, int vertexID)
{
	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return (FALSE);
	}
	if (vertexID < 0 || vertexID > (pGraph->maxVertexCount - 1))
	{
		printf("[error] Invalid value : VertexID\n");
		return (FALSE);
	}
	if (pGraph->pVertex[vertexID] == NOT_USED)
	{
		pGraph->pVertex[vertexID] = USED;
		pGraph->currentVertexCount++;
	}
	else
		printf("That vertex already exists.\n");
	return (TRUE);
}

int addEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID)
{
	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return (FALSE);
	}
	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FALSE);
	if (pGraph->ppAdjEdge[fromVertexID][toVertexID] == 0)
	{
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = 1;
		if (pGraph->graphType == GRAPH_UNDIRECTED)
			pGraph->ppAdjEdge[toVertexID][fromVertexID] = 1;
	}
	else
		printf("That edge already exists.\n");
	return (TRUE);
}

int addEdgewithWeightAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID, int weight)
{
	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return (FALSE);
	}
	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FALSE);
	if (pGraph->ppAdjEdge[fromVertexID][toVertexID] == 0)
	{
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
		if (pGraph->graphType == GRAPH_UNDIRECTED)
			pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
	}
	else
		printf("That edge already exists.\n");
	return (TRUE);
}

int checkVertexValid(ArrayGraph *pGraph, int vertexID)
{
	if (vertexID < 0 || vertexID > pGraph->maxVertexCount - 1)
	{
		printf("[error] Invalid value : vertexID\n");
		return (FALSE);
	}
	if (pGraph->pVertex[vertexID] == NOT_USED)
	{
		printf("Invalid value : vertexID NOT_USED\n");
		return (FALSE);
	}
	return (TRUE);
}

int removeVertexAG(ArrayGraph *pGraph, int vertexID)
{
	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return (FALSE);
	}
	if (!checkVertexValid(pGraph, vertexID))
		return (FALSE);
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		removeEdgeAG(pGraph, vertexID, i);
	pGraph->pVertex[vertexID] = NOT_USED;
	return (TRUE);
}

int removeEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID)
{
	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return (FALSE);
	}
	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FALSE);
	if (pGraph->ppAdjEdge[fromVertexID][toVertexID] != 0)
	{
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;
		if (pGraph->graphType == GRAPH_UNDIRECTED)
			pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;
	}
	else
		printf("[error] Cannot remove edge that doesn't exist.\n");
	return (TRUE);
}

void displayArrayGraph(ArrayGraph *pGraph)
{
	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return;
	}
	if (isEmptyAG(pGraph))
	{
		printf("This is an Empty graph.\n");
		return;
	}
	printf("----------Weight----------\n");
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		for (int j = 0; j < pGraph->maxVertexCount; j++)
		{
			printf("%d ", pGraph->ppAdjEdge[i][j]);
		}
		printf("\n");
	}
	printf("--------------------------\n");
	printf("------Adjacent Nodes-----\n");
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->pVertex[i] == NOT_USED) // USED 상태인 vertex 노드와 그 인접노드들 출력.
			continue;
		printf("from node %d to: ", i);
		for (int j = 0; j < pGraph->maxVertexCount; j++)
		{
			if (pGraph->ppAdjEdge[i][j] > 0)
				printf("%d ", j);
		}
		printf("\n");
	}
	printf("-------------------------\n");
}