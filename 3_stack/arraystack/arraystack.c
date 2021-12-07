#include "arraystack.h"

ArrayStack* createArrayStack(int maxElementCount)
{
    ArrayStack* pStack = NULL;

    if (maxElementCount < 0)
    {
        printf("[error] invalid value : maxElementCount\n");
        return (FALSE);
    }
    pStack = (ArrayStack*)malloc(sizeof(ArrayStack));
    if (pStack == NULL)
    {
        printf("[error] malloc failure : pStack\n");
      	return (FALSE);
    }
    memset(pStack, 0, sizeof(ArrayStack)); // initialize ArrayStack
  	pStack->maxElementCount = maxElementCount;
  	pStack->pElement = (ArrayStackNode*)malloc(sizeof(ArrayStackNode));
  	if (pStack->pElement == NULL)
    {
      	printf("[error] malloc failure : pElement\n");
      	free(pStack);
      	return (FALSE);
    }
  	memset(pStack->pElement, 0, sizeof(ArrayStackNode) * maxElementCount); // initialize pElements
  	return (pStack);
}

int pushAS(ArrayStack* pStack, ArrayStackNode element)
{
    if (pStack == NULL)
    {
      	return (FALSE);
    }
  	if (isArrayStackFull(pStack) == 0)
    {
      	pStack->pElement[pStack->currentElementCount].data = element.data;
      	pStack->currentElementCount++;
      	return (TRUE);
    }
    printf("[error] Stack Overflow\n");
		return (FALSE);
}

ArrayStackNode* popAS(ArrayStack* pStack)
{
  	ArrayStackNode *pNode = NULL;
  	
		if (pStack == NULL) 
  	{
   		printf("[error] Null parameter : pStack\n");
      return (FALSE);
    }
  	if (isArrayStackEmpty(pStack) == 0)
    {
      pNode = (ArrayStackNode*)malloc(sizeof(ArrayStackNode));
      if (pNode == NULL)
      {
        printf("[error] malloc failure : pNode\n");
        return (FALSE);
      }
      *pNode = pStack->pElement[pStack->currentElementCount - 1];
      pStack->pElement[pStack->currentElementCount - 1].data = 0;
      pStack->currentElementCount--;
    }
  	else
    {
      printf("[error] Stack Underflow\n");
    }
  	return (pNode);
}

ArrayStackNode* peekAS(ArrayStack* pStack)
{
		if (pStack == NULL) 
  	{
  		printf("[error] Null parameter : pStack\n");
      return (FALSE);
  	}
  	if (isArrayStackEmpty(pStack) == 0)
	  {
  		return (&(pStack->pElement[pStack->currentElementCount - 1]));
  	}
  	else
  	{
    	printf("[error] undefined behavior : Cannot try peek() on a Empty stack\n");
  	}
  	return (FALSE);
}

void deleteArrayStack(ArrayStack* pStack)
{
		
  	if (pStack == NULL)
    {
      printf("[error] Null parameter : pStack\n");
      return ;
    }
  	if (pStack->pElement != NULL)
    {
      free(pStack->pElement);
    }
		free(pStack);
}

int isArrayStackFull(ArrayStack* pStack)
{
    if (pStack == NULL)
    {
        return (FALSE);
    }
  	if (pStack->currentElementCount == pStack->maxElementCount)
    {
      return (TRUE);
    }
  	return (FALSE);
}

int isArrayStackEmpty(ArrayStack* pStack)
{
  	if (pStack == NULL)
    {
        return (FALSE);
    }
  	if (pStack->currentElementCount == 0)
    {
    	return (TRUE);
    }
    return (FALSE);
}
