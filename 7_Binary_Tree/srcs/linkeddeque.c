#ifndef _LINKED_DEQUE_
#define _LINKED_DEQUE_

#include <stdio.h>
#include <stdlib.h>
#include "../includes/bintree.h"

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0

#endif

LinkedDeque* createLinkedDeque()
{
  LinkedDeque *pReturn;
  pReturn = (LinkedDeque *)calloc(1, sizeof(LinkedDeque));
  if (pReturn == NULL)
  {
    printf("malloc failure\n");
    return (NULL);
  }
  return (pReturn);
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
  DequeNode *pNode;
  
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
    return (FALSE);
  }
  pNode = (DequeNode*)calloc(1, sizeof(DequeNode));
  if (pNode == NULL)
  {
    printf("pNode malloc failure\n");
    return (FALSE);
  }
  pNode->data = element.data;
  if (isLinkedDequeEmpty(pDeque) == TRUE)
  {
    pDeque->pFrontNode = pNode;
    pDeque->pRearNode = pNode;
  }
  else
  {
    pDeque->pFrontNode->pLLink = pNode;
    pNode->pRLink = pDeque->pFrontNode;
    pDeque->pFrontNode = pNode;
  }
  (pDeque->currentElementCount)++;
  return (TRUE);
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
  DequeNode *pNode;
  
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
    return (FALSE);
  }
  pNode = (DequeNode*)calloc(1, sizeof(DequeNode));
  if (pNode == NULL)
  {
    printf("pNode malloc failure\n");
    return (FALSE);
  }
  pNode->data = element.data;
  if (isLinkedDequeEmpty(pDeque) == TRUE)
  {
    pDeque->pFrontNode = pNode;
    pDeque->pRearNode = pNode;
  }
  else
  {
    pDeque->pRearNode->pRLink = pNode;
    pNode->pLLink = pDeque->pRearNode;
    pDeque->pRearNode = pNode;
  }
  (pDeque->currentElementCount)++;
  return (TRUE);
}

DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
  DequeNode *pReturn;
  
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
    return (NULL);
  }
  if (isLinkedDequeEmpty(pDeque) == TRUE)
  {
    printf("pDeque is Empty\n");
    return (NULL);
  }
  else
  {
    pReturn = pDeque->pFrontNode;
	pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
    pReturn->pRLink = NULL;
    if (pDeque->currentElementCount == 1)
    {
      pDeque->pRearNode = NULL;
    }
    else
    {
      pDeque->pFrontNode->pLLink = NULL;
    }
  }
  (pDeque->currentElementCount)--;
  return (pReturn);
}

DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
  DequeNode *pReturn;
  
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
    return (NULL);
  }
  if (isLinkedDequeEmpty(pDeque) == TRUE)
  {
    printf("pDeque is Empty\n");
    return (NULL);
  }
  else
  {
    pReturn = pDeque->pRearNode;
		pDeque->pRearNode = pDeque->pRearNode->pLLink;
    pReturn->pLLink = NULL;
    if (pDeque->currentElementCount == 1)
    {
      pDeque->pFrontNode = NULL;
    }
    else
    {
      pDeque->pRearNode->pRLink = NULL;
    }
  }
  (pDeque->currentElementCount)--;
  return (pReturn);
}

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
    return (NULL);
  }
  if (isLinkedDequeEmpty(pDeque) == TRUE)
  {
    printf("pDeque is Empty\n");
    return (NULL);
  }
  return (pDeque->pFrontNode);
}

DequeNode* peekRearLD(LinkedDeque* pDeque)
{
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
    return (NULL);
  }
  if (isLinkedDequeEmpty(pDeque) == TRUE)
  {
    printf("pDeque is Empty\n");
    return (NULL);
  }
  return (pDeque->pRearNode);
}

void deleteLinkedDeque(LinkedDeque* pDeque)
{
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
    return ;
  }
  while (isLinkedDequeEmpty(pDeque) == FALSE)
  {
    DequeNode *pNode = deleteFrontLD(pDeque);
    memset(pNode, 0, sizeof(DequeNode));
    free(pNode);
    pNode = 0;
  }
  free(pDeque);
  pDeque = 0;
}

int isLinkedDequeFull(LinkedDeque* pDeque)
{
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
  }
  return (FALSE);
}

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
  if (pDeque == NULL)
  {
    printf("pDeque is NULL\n");
  }
  if (pDeque->currentElementCount == 0 && pDeque->pFrontNode == NULL && pDeque->pRearNode == NULL)
  {
    return (TRUE);
  }
  return (FALSE);
}