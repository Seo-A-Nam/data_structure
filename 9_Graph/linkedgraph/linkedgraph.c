#include "linkedgraph.h"

// 중간에 malloc() 실패 오류가 날 경우, 이 함수를 호춣하여 남아있는 메모리를 모두 free() 한 뒤 종료하도록 함.
static void free_all(LinkedGraph *linkedgraph)
{
	for (int j = 0; j < linkedgraph->maxVertexCount; j++)
	{
		if (linkedgraph->ppAdjEdge[j])
		{
			free(linkedgraph->ppAdjEdge[j]);
			linkedgraph->ppAdjEdge[j] = 0;
		}
	}
	if (linkedgraph->ppAdjEdge)
	{
		free(linkedgraph->ppAdjEdge);
		linkedgraph->ppAdjEdge = 0;
	}
	if (linkedgraph->pVertex)
	{
		free(linkedgraph->pVertex);
		linkedgraph->pVertex = 0;
	}
	if (linkedgraph)
	{
		free(linkedgraph);
		linkedgraph = 0;
	}
} // 무조건 free()를 시도하는 것이 아닌, if 조건문을 통해 할당된 메모리가 존재하는 지 확인한 후 free()를 시도한다.

// 무방향 링크드그래프를 생성하는 함수
LinkedGraph* createLinkedGraph(int maxVertexCount)
{
	LinkedGraph *pGraph;

	pGraph = (LinkedGraph *)calloc(1, sizeof(LinkedGraph));
	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return (FALSE);
	}
	pGraph->maxVertexCount = maxVertexCount;
	pGraph->graphType = 1;
	pGraph->ppAdjEdge = (LinkedList **)calloc(pGraph->maxVertexCount, sizeof(LinkedList *));
	if (!pGraph->ppAdjEdge)
	{
		printf("[error] malloc failure : ppAdjEdge\n");
		free_all(pGraph);
		return (NULL);
	}
	pGraph->pVertex = (int *)calloc(maxVertexCount,sizeof(int));
	if (!pGraph->pVertex)
	{
		printf("[error] malloc failure : pVertex\n");
		free_all(pGraph);
		return (NULL);
	}
	return (pGraph);
}

// 유방향 링크드그래프를 생성하는 함수
LinkedGraph* createLinkedDirectedGraph(int maxVertexCount)
{
	LinkedGraph *pGraph;

	pGraph = (LinkedGraph *)calloc(1, sizeof(LinkedGraph));
	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return (FALSE);
	}
	pGraph->maxVertexCount = maxVertexCount;
	pGraph->graphType = 2;
	pGraph->ppAdjEdge = (LinkedList **)calloc(pGraph->maxVertexCount, sizeof(LinkedList *));
	if (!pGraph->ppAdjEdge)
	{
		printf("[error] malloc failure : ppAdjEdge\n");
		free_all(pGraph);
		return (NULL);
	}
	pGraph->pVertex = (int *)calloc(maxVertexCount,sizeof(int));
	if (!pGraph->pVertex)
	{
		printf("[error] malloc failure : pVertex\n");
		free_all(pGraph);
		return (NULL);
	}
	return (pGraph);
}

// 링크드그래프가 비었는 지 확인하는 함수 : 아래 displayGraphLG()에서 사용됨.
int isEmptyLG(LinkedGraph* pGraph)
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

// 링크드그래프에서 해당 VertexID를 가진 Vertex(노드)를 추가하는 함수
int addVertexLG(LinkedGraph* pGraph, int vertexID)
{
	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return (FALSE);
	}
	if (vertexID < 0 || vertexID > pGraph-> maxVertexCount - 1)
	{
		printf("[error] Invalid value : VertexID\n");
		return (FALSE);
	}
	if (pGraph->pVertex[vertexID] == NOT_USED)
	{
		pGraph->pVertex[vertexID] = USED;
		pGraph->currentVertexCount++;
		pGraph->ppAdjEdge[vertexID] = createLinkedList();
	}
	else
		printf("That vertex already exists.\n");
	return (TRUE);
}

// 무가중치 링크드그래프에 Edge(간선)을 추가하는 함수 (fromVertexID 노드로부터 toVertexID 노드로의 간선)
int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	LinkedList *ptr;
	ListNode new_edge;
	int index;
	
	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return (FALSE);
	}
	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FALSE);
	ptr = pGraph->ppAdjEdge[fromVertexID];
	new_edge.to = toVertexID;
	new_edge.weight = 1;
	new_edge.pLink = NULL;
	index = findGraphNodePosition(ptr, toVertexID);
	if (index < 0)
		return (FALSE);
	if (index == 0) // 해당 노드가 없다.
	{
		addLLElement(ptr, ptr->currentElementCount, new_edge);
		if (pGraph->graphType == GRAPH_UNDIRECTED)
		{
			ptr = pGraph->ppAdjEdge[toVertexID];
			new_edge.to = fromVertexID;
			addLLElement(ptr, ptr->currentElementCount, new_edge);
		}
	}
	else
		printf("That edge already exists.\n");
	return (TRUE);
}

// 가중치 링크드그래프에 Edge(간선)을 추가하는 함수 (fromVertexID 노드로부터 toVertexID 노드로의 간선. weight만큼의 가중치를 가짐)
int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	LinkedList *ptr;
	ListNode new_edge;
	int index;
	
	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return (FALSE);
	}
	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FALSE);
	ptr = pGraph->ppAdjEdge[fromVertexID];
	new_edge.to = toVertexID;
	new_edge.weight = weight;
	new_edge.pLink = NULL;
	index = findGraphNodePosition(ptr, toVertexID);
	if (index < 0)
		return (FALSE);
	if (index == 0) // 해당 노드가 없다.
	{
		addLLElement(ptr, ptr->currentElementCount, new_edge);
		if (pGraph->graphType == GRAPH_UNDIRECTED)
		{
			ptr = pGraph->ppAdjEdge[toVertexID];
			new_edge.to = fromVertexID;
			addLLElement(ptr, ptr->currentElementCount, new_edge);
		}
	}
	else
		printf("That edge already exists.\n");
	return (TRUE);
}

// 주어진 vertexID를 확인하여 그게 링크드그래프에서 유효한지 확인(노드 범위 안에 있는 지, 사용되고 있는 노드인지)
int checkVertexValid(LinkedGraph* pGraph, int vertexID)
{
	if (vertexID < 0 || vertexID > pGraph->maxVertexCount - 1)
	{
		printf("[error] Invalid value : vertexID\n");
		return (FALSE);
	}
	if (pGraph->pVertex[vertexID] == NOT_USED)
	{
		printf("[error] Invalid value : vertexID NOT_USED\n");
		return (FALSE);
	}
	return (TRUE);
}


// 주어진 vertexID의 노드(vertex)를 링크드그래프에서 제거한다 
int removeVertexLG(LinkedGraph* pGraph, int vertexID)
{
	LinkedList *ptr;

	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return (FALSE);
	}
	if (!checkVertexValid(pGraph, vertexID))
		return (FALSE);
	ptr = pGraph->ppAdjEdge[vertexID];
	deleteLinkedList(ptr);
	pGraph->pVertex[vertexID] = NOT_USED;
	return (TRUE);
}

// fromVertexID 노드에서 toVertexID 노드로의 간선을 삭제하는 함수
int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	LinkedList *ptr;
	int index = 0;

	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return (FALSE);
	}
	if (!checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FALSE);
	ptr = pGraph->ppAdjEdge[fromVertexID];
	index = findGraphNodePosition(ptr, toVertexID);
	if (index < 0)
		return (FALSE);
	if (index > 0)
	{
		deleteGraphNode(ptr, toVertexID);
		if (pGraph->graphType == GRAPH_UNDIRECTED)
			deleteGraphNode(pGraph->ppAdjEdge[toVertexID], fromVertexID);
	}
	else
		printf("[error] Cannot remove edge that doesn't exist.\n");
	return (TRUE);
}

// 링크드그래프를 삭제하는 함수
void deleteLinkedGraph(LinkedGraph* pGraph)
{
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		removeVertexLG(pGraph, i);
	}
	free(pGraph->ppAdjEdge);
	pGraph->ppAdjEdge = 0;
	free(pGraph->pVertex);
	pGraph->pVertex = 0;
	free(pGraph);
	pGraph = 0;
}

/* 주어진 인접노드 링크드리스트에서 delVertexID를 가진 노드를 삭제하는 함수. removeEdgeLG()에서 호출되는 함수이다.
* 예를 들면, 0 - 1, 2, 3 이런 식으로 노드0에 1, 2, 3노드가 연결되어있다. 이 떄 0번노드에서 1번노드로의 연결을 삭제하고 싶다면 이 함수를 사용.
* 사실 함수 명이 그닥 이 용도에 명시적으로 들어맞진 않는 것 같다. 
*/
void deleteGraphNode(LinkedList* pList, int delVertexID)
{
	int index = 0;

	if (!pList)
	{
		printf("[error] Null Parameter : plist\n");
		return;
	}
	if ((index = findGraphNodePosition(pList, delVertexID)) > 0)
		removeLLElement(pList, index - 1);
}

// 주어진 LinkedList에서 vertexID를 데이터로 가진 노드가 있는 지 찾는다. 에러시 -1, 찾지 못할 시 0, 찾을 시 해당 인덱스 + 1 을 반환
int findGraphNodePosition(LinkedList* pList, int vertexID)
{
	ListNode *now;

	if (!pList)
	{
		printf("[error] Null Parameter : plist\n");
		return (ERROR); // FALSE(=0) 을 반환해버리면 0번째 인덱스를 찾았는 지랑 구분이 안됨. 따라서 -1 반환.
	}
	now = pList->headerNode.pLink;
	for (int i = 0; i < pList->currentElementCount; i++)
	{
		if (now->to == vertexID)
			return (i + 1); // 참고 : remove시나 다른 쪽에서 i - 1 로 인덱스 넘길 것이므로 ㄱㅊ.
		now = now->pLink;
	}
	return (FALSE);
}

/*
* GET
*/

// 주어진 링크드그래프의 Edge(간선)의 개수를 반환하는 함수
int getEdgeCountLG(LinkedGraph* pGraph)
{
	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return (FALSE);
	}
	return (pGraph->currentEdgeCount);
}

// 주어진 링크드그래프의 현재 Vertex(노드)의 개수를 반환하는 함수
int getVertexCountLG(LinkedGraph* pGraph)
{
	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return (FALSE);
	}
	return (pGraph->currentVertexCount);
}

// 주어진 링크드그래프의 MaxVertexCount(노드의 최대 개수)를 반환하는 함수
int getMaxVertexCountLG(LinkedGraph* pGraph)
{
	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return (FALSE);
	}
	return (pGraph->maxVertexCount);
}

// 주어진 링크드그래프가 어떤 유형인지 (무방향, 유방향) 반환해주는 함수
int getGraphTypeLG(LinkedGraph* pGraph)
{
	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return (FALSE);
	}
	return (pGraph->graphType);
}

// 주어진 링크드그래프에 대한 정보를 출력하는 함수 (노드와 그 인접노드들에 대한 정보 출력)
void displayLinkedGraph(LinkedGraph* pGraph)
{
	if (!pGraph)
	{
		printf("[error] Null Parameter : pGraph\n");
		return ;
	}
	if (isEmptyLG(pGraph))
	{
		printf("This is an Empty graph.\n");
		return ;
	}
	printf("-----------Adjacent Nodes----------\n");
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		if (pGraph->pVertex[i] == NOT_USED)
			continue;
		printf("from node %d:\n", i);
		print_list(&pGraph->ppAdjEdge[i]->headerNode);
		printf("\n");
	}
	printf("-----------------------------------\n");
}

// 주어진 vertex에 연결된 노드 정보를 linkedList를 따라 이동해가며 전부 출력해주는 함수
void print_list(ListNode *curr)
{
	curr = curr->pLink; // 헤더노드의 다음 노드(이 노드에 연결된 노드들)부터 출력
	while(curr)
	{
		printf("           to: %d, weight: %d\n", curr->to, curr->weight);
		curr = curr->pLink;
	}
}