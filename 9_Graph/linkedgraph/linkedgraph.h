#ifndef _GRAPH_ADJLIST_
#define _GRAPH_ADJLIST_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist/linkedlist.h"
#include "arrayqueue/arrayqueue.h"

typedef struct LinkedGraphType
{
	int maxVertexCount;		// vertex(노드)의 최대 개수
	int currentVertexCount;	// 현재 vertex(노드)의 개수
	int currentEdgeCount;	// 현재 edge(노드 간 간선)의 개수
	int graphType;			// 그래프의 타입 (무방향, 유방향) : 1-Undirected, 2-Directed
	LinkedList** ppAdjEdge;	// 노드 간의 간선과 그 weight를 표시할 수 있는 인접 리스트
	int *pVertex;			// vertex(노드)들의 상태를 표시하는 1차원 배열 (visited, not-used, used)
} LinkedGraph;

/*
 * 인접 리스트의 사용 법 : ppAdjEdge[노드번호] 는 (LinkedList *) 타입을 가진다. 
 * 여기에 이 노드에 연결된 노드 정보를(LinkedNode) 새끼 노드처럼 줄줄줄 매달아주는 것이다.
 * 
 * arraygraph의 인접행렬과 비교 - arraygraph에는 노드개수^2 칸만큼 동적할당 된 칸이 생기는데, 여기는 원하는 노드에만 각각 인접노드(LinkedNode)를 할당해 줄 수 있다.
 * 이 경우, 노드의 개수가 아주 많아지고, 노드간 연결이 적은 경우에는 linkedgraph가 메모리 공간 측면에서 유리해질 수 있다. 
 * arraygraph에서는 간선을 사용하지 않는 노드에도 모두 maxVertexCount(모든 노드의 개수)만큼 메모리가 할당되기 때문이다. 
 * 
 * 보완할 내용 : checkVertexValid(LinkedGraph* pGraph, int vertexID)에서 자기 자신을 가르키지 않도록 해야한다!!! 발표 시 피드백 받은 내용 
 */

// 링크드그래프를 생성하는 함수
LinkedGraph* createLinkedGraph(int maxVertexCount);
LinkedGraph* createLinkedDirectedGraph(int maxVertexCount);

// 링크드그래프를 삭제하는 함수
void deleteLinkedGraph(LinkedGraph* pGraph);

// 링크드그래프가 비었는 지 확인하는 함수
int isEmptyLG(LinkedGraph* pGraph);

// 링크드그래프에 Vertex(노드)를 추가하는 함수
int addVertexLG(LinkedGraph* pGraph, int vertexID);

// 링크드그래프에 Edge(간선)을 추가하는 함수
int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight);

// 주어진 vertexID를 확인하여 그게 링크드그래프에서 유효한지 확인 (노드 범위 안에 있는 지, 사용되고 있는 노드인지)
int checkVertexValid(LinkedGraph* pGraph, int vertexID);

// 주어진 vertexID의 노드(vertex)를 링크드그래프에서 제거한다 
int removeVertexLG(LinkedGraph* pGraph, int vertexID);

// fromVertexID 노드에서 toVertexID 노드로의 간선을 삭제하는 함수
int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
// 주어진 인접노드 링크드리스트에서 delVertexID를 가진 노드를 삭제하는 함수
void deleteGraphNode(LinkedList* pList, int delVertexID);
// 주어진 vertexID를 가진 노드의 인덱스 + 1을 반환하는 함수
int findGraphNodePosition(LinkedList* pList, int vertexID);

// 주어진 링크드그래프의 Edge(간선)의 개수를 반환하는 함수
int getEdgeCountLG(LinkedGraph* pGraph);

// 주어진 링크드그래프의 현재 Vertex(노드)의 개수를 반환하는 함수
int getVertexCountLG(LinkedGraph* pGraph);

// 주어진 링크드그래프의 MaxVertexCount(노드의 최대 개수)를 반환하는 함수
int getMaxVertexCountLG(LinkedGraph* pGraph);

// 주어진 링크드그래프가 어떤 유형인지 (무방향, 유방향) 반환해주는 함수
int getGraphTypeLG(LinkedGraph* pGraph);

// 주어진 링크드그래프에 대한 정보를 출력하는 함수 (노드와 그 인접노드들에 대한 정보 출력)
void displayLinkedGraph(LinkedGraph* pGraph);
// 주어진 vertex에 연결된 노드 정보를 linkedList를 따라 이동해가며 전부 출력해주는 함수
void print_list(ListNode *curr);

/*
 * 그래프 탐색(그래프 순회) 관련 함수.(BFS, DFS)
 * traversal DFS에서 재귀를 호출하는 부분은 traversal_DFS_recur로 따로 함수로 뺏다. (이유는 추후 설명 예정)
 */
void traversal_DFS_recur(LinkedGraph *pGraph, int from);
void traversal_DFS(LinkedGraph *pGraph);
void traversal_BFS(LinkedGraph *pGraph);

#endif

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define TRUE				1
#define FALSE				0
#define ERROR				-1

#define VISITED				2
#define USED				1
#define NOT_USED			0

#define SUCCESS				1
#define FAIL				0

#define GRAPH_UNDIRECTED	1
#define GRAPH_DIRECTED		2

#endif