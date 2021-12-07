#include "linkeddeque.h"

LinkedDeque* createLinkedDeque()
{
    LinkedDeque *LD;

    if (!(LD = (LinkedDeque *)malloc(sizeof(LinkedDeque))))
    {
        printf("[error] malloc failure : LD\n");
        return (FALSE);
    }
    memset(LD, 0, sizeof(LinkedDeque)); // 메모리 초기화
    return (LD);
}

int isLinkedDequeFull(LinkedDeque* pDeque)
{
    if (pDeque == NULL)
    {
        printf("[error] Null parameter : pDeque\n");
        return (FALSE);
    }
    return (FALSE);
} // 링크드리스트 구조에, maxElementCount가 없으므로 배열이 가득 찰 수 없음. 무한히 확장될 수 있다.

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
    if (pDeque == NULL)
    {
        printf("[error] Null parameter : pDeque\n");
        return (FALSE);
    }
    if (pDeque->currentElementCount == 0)
        return (TRUE);
    return (FALSE);
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
    DequeNode *newNode;
    
    newNode = (DequeNode *)malloc(sizeof(DequeNode));
    if (newNode == NULL)
    {
        printf("[error] malloc failure : LD\n");
        return (FALSE);
    }
    newNode->data = element.data;
    newNode->pRLink = NULL;
    newNode->pLLink = NULL;
    if (isLinkedDequeEmpty(pDeque))
    {
        pDeque->pFrontNode = newNode;
        pDeque->pRearNode = newNode;
    }
    else if (!(isLinkedDequeEmpty(pDeque)))
    {
        pDeque->pFrontNode->pLLink = newNode;
        newNode->pRLink = pDeque->pFrontNode;
        pDeque->pFrontNode = newNode;
    }
    pDeque->currentElementCount++;
    return (TRUE);
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
    DequeNode *newNode;
    
    newNode = (DequeNode *)malloc(sizeof(DequeNode));
    if (newNode == NULL)
    {
        printf("[error] malloc failure : LD\n");
        return (FALSE);
    }
    newNode->data = element.data;
    newNode->pRLink = NULL;
    newNode->pLLink = NULL;
    if (isLinkedDequeEmpty(pDeque))
    {
        pDeque->pFrontNode = newNode;
        pDeque->pRearNode = newNode;
    }
    else
    {
        pDeque->pRearNode->pRLink = newNode;
        newNode->pLLink = pDeque->pRearNode;
        pDeque->pRearNode = newNode;
    }
    pDeque->currentElementCount++;
    return (TRUE);
}

DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
    DequeNode *delNode = NULL;

    if (pDeque == NULL)
    {
        printf("[error] Null parameter : pDeque\n");
        return (FALSE);
    }
    if (isLinkedDequeEmpty(pDeque))
    { // 비어있는 덱에서는 노드 삭제가 안되므로 에러메시지 (덱 언더플로우) 출력
        printf("[error] Deque Underflow\n");
        return (FALSE);
    }
    delNode = pDeque->pFrontNode;
    pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
    delNode->pRLink = NULL;
    delNode->pLLink = NULL; // 어차피 반환할 노드니까 다음노드링크를 전부 0으로 해서 연결을 끊는다.
    if (pDeque->currentElementCount == 1) // 노드가 1개인 덱
        pDeque->pRearNode = NULL;
    else // 노드가 2개 이상인 덱 (일반적인 경우)
        pDeque->pFrontNode->pLLink = NULL;  
    pDeque->currentElementCount--;
    return (delNode);
}

DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
    DequeNode   *delNode = NULL;

    if (pDeque == NULL)
    {
        printf("[error] Null parameter : pDeque\n");
        return (FALSE);
    }
    if (isLinkedDequeEmpty(pDeque))
    { // 비어있는 덱에서는 노드 삭제가 안되므로 에러메시지 (덱 언더플로우) 출력
        printf("[error] Deque Underflow\n");
        return (FALSE);
    }
    delNode = pDeque->pRearNode;
    pDeque->pRearNode = pDeque->pRearNode->pLLink;
    delNode->pLLink = NULL;
    delNode->pRLink = NULL; // 어차피 반환할 노드니까 다음노드링크를 전부 0으로 해서 연결을 끊는다.
    if (pDeque->currentElementCount == 1) // 노드가 1개인 덱
        pDeque->pFrontNode = NULL;
    else // 노드가 2개 이상인 덱 (일반적인 경우)
        pDeque->pRearNode->pRLink = NULL;
    pDeque->currentElementCount--;
    return (delNode);
}

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
    if (pDeque == NULL)
    {
        printf("[error] Null parameter : pDeque\n");
        return (FALSE);
    }
    if (isLinkedDequeEmpty(pDeque))
    {
        printf("[error] undefined behavior : Cannot try peek() on a Empty Deque.\n");
        return (FALSE);
    }
    return (pDeque->pFrontNode);
}

DequeNode* peekRearLD(LinkedDeque* pDeque)
{
    if (pDeque == NULL)
    {
        printf("[error] Null parameter : pDeque\n");
        return (FALSE);
    }
    if (isLinkedDequeEmpty(pDeque))
    {
        printf("[error] undefined behavior : Cannot try peek() on a Empty Deque.\n");
        return (FALSE);
    }
    return (pDeque->pRearNode);
}

void deleteLinkedDeque(LinkedDeque* pDeque)
{
    int index = 0;

    if (pDeque == NULL)
    {
        printf("[error] Null parameter : pDeque\n");
        return ;
    }
    index = pDeque->currentElementCount;
    for (int i = 0; i < index; i++)
    {
        DequeNode *node;
        node = deleteFrontLD(pDeque);
        //node->data = 0; // makes it more safer? 더 안전하다? -- 잘 모르겠으니까 빼자
        free(node);
        node = 0;
    }
    free(pDeque);
}

