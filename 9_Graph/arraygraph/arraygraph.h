#ifndef _GRAPH_ADJMATRIX_
#define _GRAPH_ADJMATRIX_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayqueue/arrayqueue.h"

typedef struct ArrayGraphType
{
	int maxVertexCount;		// vertex(노드)의 최대 개수
	int currentVertexCount;	// 현재 vertex(노드)의 개수
	int graphType;			// 그래프의 타입 (무방향, 유방향) : 1-Undirected, 2-Directed
	int **ppAdjEdge;		// 노드 간의 간선과 그 weight를 표시할 수 있는 2차원 인접행렬
	int *pVertex;			// vertex(노드)들의 상태를 표시하는 1차원 배열 (visited, not-used, used)
} ArrayGraph;
/* 
* 인접 행렬의 사용 법 : 
* 예를 들자면, 0번 노드에 1번 2번 3번 노드가 연결되어있다고 해보자.
* 그러면 세로축에서 0번째 있는 줄을 찾는다. 그리고 거기 1번째, 2번째, 3번째 인덱스에 숫자(1 또는 가중치(weight; 음수 가능))를 넣어준다.
* 그러면 0번째 노드에 연결된 인접노드를 찾고 싶을 경우에, 0번째 줄을 찾아 거기에서 숫자가 존재하는 인덱스를 인접노드로 생각하면 된다. 
* 
* 인접 행렬에서 그래프의 타입 (무방향, 유방향)이 갖는 영향
* 무방향일 경우 서로가 서로의 인접 노드가 된다. 이 경우 서로의 인접행렬에 모두 숫자를 적어줘 서로 연결 표시를 해줘야한다.
* 그런데 만약 유방향일 경우, 현재 인접 노드의 행렬에만 여기에서 향하는 인접노드의 번호를 적어줘야한다. 상대쪽 노드는 현재노드를 향하고 있지 않으므로 그쪽에는 적어주지 않는다.
* 따라서 한쪽 인접노드 열에만 숫자가 채워진다는 것이다.
*
* LinkedGraph 구조체와의 차이점 : 여기에는 int currentEdgeCount 변수가 없다. (현재 edge(노드 간 간선)의 개수)...왜지?
* LinkedGraph에는 인접행렬이 (int **)이 아닌 (LinkedList **)자료형으로 되어있으며 인접노드가 있는 노드에만 인접노드 리스트가 연결되어있다. 
*/

// ????? ????
ArrayGraph* createArrayGraph(int maxVertexCount);

ArrayGraph* createArrayDirectedGraph(int maxVertexCount);

// ????? ????
void deleteArrayGraph(ArrayGraph* pGraph);

// ???? ????? ???? ???
int isEmptyAG(ArrayGraph* pGraph);

// ??? ???
int addVertexAG(ArrayGraph* pGraph, int vertexID);

// ???? ???
int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight);

// ????? ????? ????.
int checkVertexValid(ArrayGraph* pGraph, int vertexID);

// ??? ????
int removeVertexAG(ArrayGraph* pGraph, int vertexID);

// ???? ????
int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID);

// ????? ???? ???
void displayArrayGraph(ArrayGraph* pGraph);

void traversal_DFS_recur(ArrayGraph *pGraph, int from);
void traversal_DFS(ArrayGraph *pGraph);
void traversal_BFS(ArrayGraph *pGraph);

#endif

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define VISITED				2
#define USED				1
#define NOT_USED			0

#define SUCCESS				1
#define FAIL				0

#define TRUE				1
#define FALSE				0

#define GRAPH_UNDIRECTED	1
#define GRAPH_DIRECTED		2
#endif
