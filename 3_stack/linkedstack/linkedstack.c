#include "linkedstack.h"

LinkedStack* createLinkedStack()
{
  	LinkedStack* pStack = NULL;
    pStack = (LinkedStack*)malloc(sizeof(LinkedStack));
    if (pStack == NULL)
    {
        printf("[error] malloc failure : pStack\n");
        return (FALSE);
    }
    memset(pStack, 0, sizeof(LinkedStack));
    return (pStack);
}

int		pushLS(LinkedStack* pStack, StackNode element)
{
  	StackNode *pNode = NULL;
  	if (pStack == NULL)
    {
      	printf("[error] Null parameter : pStack\n");
      	return (FALSE);
    }
  	pNode = (StackNode*)malloc(sizeof(StackNode));
  	if (pNode == NULL)
    {
      	printf("[error] malloc failure : pNode\n");
        return (FALSE);
      //malloc실패
    }
  	*pNode = element;
  	pNode->pLink = pStack->pTopElement;
  	pStack->pTopElement = pNode;
  	pStack->currentElementCount++;
	return (TRUE);
} // maxElementCount가 없다는 점이 인상적임
// pTopElement(헤더노드) 자체가 0번째 element (?)

StackNode* popLS(LinkedStack* pStack)
{
  	StackNode *delNode = NULL;
		if (pStack == NULL)
    {
      	printf("[error] Null parameter : pStack\n");
      	return (FALSE);
    }
  	if (isLinkedStackEmpty(pStack) == TRUE)
    {
      	printf("[error] Stack Underflow\n");
      	return (FALSE);
    }
  	delNode = pStack->pTopElement;
  	pStack->pTopElement = delNode->pLink;
  	delNode->pLink = NULL; //어차피 반환할 노드니까 pLink를 널로.
  	pStack->currentElementCount--;
  	return (delNode);
}

StackNode* peekLS(LinkedStack* pStack)
{
  	if (pStack == NULL)
    {
      	printf("[error] Null parameter : pStack\n");
      	return (FALSE);
    }
  	if (isLinkedStackEmpty(pStack) == TRUE)
    {
      	printf("[error] Stack is empty\n");
      	return (FALSE);
    }
  	return (pStack->pTopElement);
}

void deleteLinkedStack(LinkedStack* pStack)
{
  	if (pStack == NULL)
    {
      	printf("[error] Null parameter : pStack\n");
      	return ;
    }
  	int index = pStack->currentElementCount;
  	for (int i = 0; i < index; i++)
    {
      	StackNode *pNode = popLS(pStack);
      	free(pNode);
    } // 상당히 괜찮은 아이디어. 하나씩 노드 pop() 해오고 그걸 매번 free() 해준다.
  	free(pStack);
}

/* for문을 while문으로 바꿔보자 ----
    while (pStack->currentElementCount) // currElement는 pop()할때마다 하나씩 줄음
    {
      	StackNode *pNode = popLS(pStack);
      	free(pNode);
    } // 상당히 괜찮은 아이디어. 하나씩 노드 pop() 해오고 그걸 매번 free() 해준다.
  	free(pStack);
*/

int isLinkedStackEmpty(LinkedStack* pStack)
{
    if (pStack == NULL)
    {
        printf("[error] Null parameter : pStack\n");
        return (FALSE);
    }
    if (pStack->currentElementCount == 0)
    {
        return (TRUE);
    }
    return (FALSE);
}

int isLinkedStackFull(LinkedStack* pStack)
{
	(void)pStack; // unused parameter
  	return (FALSE);
} // LinkedStack cannot be full (nodes can be added infinitely)
/* 무조건 False 인 이유 -> maxElementCount도 없는데다가 링크드리스트 구조이므로
 가득 찰 리가 없다. */