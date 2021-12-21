#include "linkedgraph.h"

void    drawback_visitedStatus(LinkedGraph *pGraph) 
{
    for (int i = 0; i < pGraph->maxVertexCount; i++)
    {
        if (pGraph->pVertex[i] == VISITED)
            pGraph->pVertex[i] = USED;
    }
} /* 프로그램 실행 중 traverse가 돌아가고 나면 used가 visited로 다 바뀜. 그럼 다음에 traverse 호출했을 때 돌지 않는다. 
(그 이외의 다른 함수들에서도 USED를 확인하는 조건문들이 때문에 오동작 발생 가능) 이를 위해 그 전으로 전부 복구시켜줌. */

int     traverse_test(LinkedGraph *pGraph)
{
    int option;
	int err_flag =1;
	
    printf("Choose Traversal option    1 (DFS traversal)   2 (BFS traversal) : \n");
    scanf(" %d", &option);
    printf("\n");
    if (option != 1 && option != 2)
    {
        printf("[error] Undefined traversal option\n");
        err_flag = 0;
		return (err_flag);
    }
    if (pGraph->currentVertexCount == 0)
    {
        printf("[error] Cannot traverse an empty graph\n");
        err_flag = 0;
        return (err_flag);
    }
    if (option == 1)
        traversal_DFS(pGraph);
    else
        traversal_BFS(pGraph);
    drawback_visitedStatus(pGraph);
	return (err_flag);
}

int     addVertex_test(LinkedGraph *pGraph)
{
    int err_flag = 1;
    int d;

    printf("Type any number to add Vertex: \n");
    scanf(" %d", &d);
	err_flag = addVertexLG(pGraph, d);
    return (err_flag);
}

int     addEdge_test(LinkedGraph *pGraph, int op)
{
    int from, to, weight;
    int err_flag = 1;

    printf("Type two number to add edge between them: \n");
	printf("from, to: ");
    scanf(" %d %d", &from, &to);
	if (op == 1 || op == 2)
		err_flag = addEdgeLG(pGraph, from, to);
	else
	{
		printf("This is Directed graph, so type weight: ");
		scanf(" %d", &weight);
		err_flag = addEdgewithWeightLG(pGraph, from, to, weight);
	}
    return (err_flag);
}

int     removeVertex_test(LinkedGraph *pGraph)
{
    int err_flag = 1;
    int c;

	printf("Vertex ID to remove: ");
	scanf(" %d", &c);
	err_flag = removeVertexLG(pGraph, c);
    return (err_flag);
}

int     removeEdge_test(LinkedGraph *pGraph)
{
    int err_flag = 1;
    int from, to;

    printf("Two number to remove edge between them: \n");
    printf("from, to: ");
    scanf(" %d %d", &from, &to);
    err_flag = removeEdgeLG(pGraph, from, to);
    return (err_flag);
}

int     test_LinkedGraph(int op)
{
    LinkedGraph  *pGraph;
	int input = 0;
    int maxcount = 0;
	printf("maxcount: ");
	scanf(" %d", &maxcount);
	if (op == 1 || op == 3)
		pGraph = createLinkedGraph(maxcount);
	else
		pGraph = createLinkedDirectedGraph(maxcount);
    while (1)
    {
        int err_flag = 1;
        printf("\nEdge Status : ======================================================================\n");
        displayLinkedGraph(pGraph);
        printf("====================================================================================\n");
        printf("\n    1 (add Vertex)   2 (add Edge)   3 (remove Vertex)\n    4 (remove Edge)   5 (Traversal)   6 (exit)\n\nType your command number : ");
        scanf(" %d", &input);
        if (input == 6)
        {
            printf("\n__________________________Terminate the Test Program___________________________\n");
            break;
        }
        switch (input)
        {
            case 1 :  //add vertex
            {
				err_flag = addVertex_test(pGraph);
                break;
            }
            case 2 :  //add edge
            {
                err_flag = addEdge_test(pGraph, op);
                break;
            }
            case 3 :  // remove vertex
            {
                err_flag = removeVertex_test(pGraph);
                break;
            }
            case 4 :  //remove edge
            {
				err_flag = removeEdge_test(pGraph);
                break;
            }
			case 5 :  //traversal : 간선 없는 그래프들까지 모두 탐색되도록 test 함수 구현함.
            {
				err_flag = traverse_test(pGraph);
				break;
            }
			default :  //exit
            {
				printf("[error] undefined command number.\n");
                break;
            }
        }
        if (err_flag == 0)
        {
            printf("[error] Terminate the Test Program\n");
            break;
        }
    }
    printf("\n");
    deleteLinkedGraph(pGraph);
    return (0);
}

int     main()
{
    int option = 0;
    printf("Choose your Graph\n    1 Undirected Unweighted    2 Directed Unweighted\n");
	printf("    3 Undirected Weighted      4 Directed Weighted\n");
    scanf(" %d", &option);
    if (!(option >= 1 && option <= 4))
    {
        printf("[error] undefined command number.\n");
        printf("[error] Terminate the Test Program\n");
        return (0);
    }
    test_LinkedGraph(option);
    system("leaks a.out");
    return (0);
}