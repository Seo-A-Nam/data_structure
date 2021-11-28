#include "arraystack.h"

ArrayStack* createArrayStack(int maxElementCount)
{
    ArrayStack* pStack = NULL;

    if (maxElementCount < 0)
    {
        printf("[error] invalid value : maxElementCount\n");//invalid maxElementCount value
        return (pStack);
    }
    pStack = (ArrayStack*)malloc(sizeof(ArrayStack));//스택을 동적할당
    if (pStack == NULL)
    {
        printf("[error] malloc failure : pStack\n");
      	return (pStack);
    } // malloc failure handling
    memset(pStack, 0, sizeof(ArrayStack));//ArrayStack만큼 0으로 초기화
  	pStack->maxElementCount = maxElementCount;//maxElementCount만 값 넣기
  	pStack->pElement = (ArrayStackNode*)malloc(sizeof(ArrayStackNode));
  	if (pStack->pElement == NULL)//pElement 동적할당 실패
    {
      	printf("[error] malloc failure : pElement\n");
      	free(pStack);
      	return (NULL);
    }
  	memset(pStack->pElement, 0, sizeof(ArrayStackNode) * maxElementCount);
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
      	pStack->pElement[pStack->currentElementCount] = element;
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
      return (pNode);
    }
  	if (isArrayStackEmpty(pStack) == 0)
    {
      pNode = (ArrayStackNode*)malloc(sizeof(ArrayStackNode));
      if (pNode == NULL)
      {
        printf("[error] malloc failure : pNode\n");
        return (pNode);
      }
      *pNode = pStack->pElement[pStack->currentElementCount - 1];
      pStack->pElement[pStack->currentElementCount - 1] = 0;
      pStack->currentElementCount--;
    }
  	else
    {
      printf("[error] undefined behavior : Cannot try pop() on a Empty stack\n")
    }
  	return (pNode);
}

ArrayStackNode* peekAS(ArrayStack* pStack)
{
		if (pStack == NULL) 
  	{
  		printf("[error] Null parameter : pStack\n");
  	}
  	if (isArrayStackEmpty(pStack) == 0)
	  {
  		return (&(pStack->pElement[pStack->currentElementCount - 1]));
  	}
  	else
  	{
    	printf("[error] undefined behavior : Cannot try peek() on a Empty stack\n")
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
  	int ret = FALSE;
  
  	if (pStack != NULL)
    {
      if (pStack->currentElementCount == pStack->maxElementCount)
      {
        ret = TRUE;
      }
    }
  	else
    {
      return (ERROR);
    }
  	return (ret);
}

int isArrayStackEmpty(ArrayStack* pStack)
{
  	if (pStack == NULL)
    {
        return (ERROR);
    }
  	if (pStack->currentElementCount == 0)
    {
    	return (TRUE);
    }
    return (FALSE);
}
