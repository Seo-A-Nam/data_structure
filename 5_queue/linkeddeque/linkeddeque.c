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
    LD->currentElementCount = 0;
    LD->pRearNode = 0;
    LD->pFrontNode = 0;
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
    *newNode = element;
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
    *newNode = element;
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
    DequeNode *pNode = NULL;
    
    if (pDeque == NULL)
    {
        printf("[error] Null parameter : pDeque\n");
        return (FALSE);
    }
    if (!(isLinkedDequeEmpty(pDeque)))
    {
        pNode = pDeque->pFrontNode;
        pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
        pNode->pRLink = NULL;
        pDeque->currentElementCount--;
        if (isLinkedDequeEmpty(pDeque))
        {
            pDeque->pRearNode = NULL;
        }
        else if (!(isLinkedDequeEmpty(pDeque)))
        {
            pDeque->pFrontNode->pLLink = NULL;
        }
    }
    return (pNode);
}

DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
    DequeNode   *pNode = NULL;

    if (pDeque == NULL)
    {
        printf("[error] Null parameter : pDeque\n");
        return (FALSE);
    }
    if (!(isLinkedDequeEmpty(pDeque)))
    {
        pNode = pDeque->pRearNode;
        pDeque->pRearNode = pDeque->pRearNode->pLLink;
        pNode->pRLink = NULL;
        pDeque->currentElementCount--;
    }
    if (isLinkedDequeEmpty(pDeque))
    {
        pDeque->pFrontNode = NULL;
    }
    else
        pDeque->pRearNode->pRLink = NULL;
    return (pNode);
}

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
    if (pDeque == NULL)
    {
        printf("[error] Null parameter : pDeque\n");
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
        free(node);
        node = 0;
    }
    free(pDeque);
}

