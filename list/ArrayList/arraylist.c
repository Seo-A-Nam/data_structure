#include "arraylist.h"

ArrayList* createArrayList(int maxElementCount)
{
    ArrayList *arr;

	if (maxElementCount <= 0)
		return (NULL);
    arr = (ArrayList *)malloc(sizeof(ArrayList));
    if (arr == NULL)
        return (NULL);
    arr->maxElementCount = maxElementCount;
    arr->currentElementCount = 0;
    arr->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount);
    if (arr->pElement == NULL)
	{
		free(arr);
		arr = 0;
		return (NULL);
	}
	return (arr);
}

void		deleteArrayList(ArrayList* pList)
{
	if (pList->pElement == NULL)
		printf("pElement is null parameter\n");
	else
		free(pList->pElement);
	pList->pElement = 0;
	if (pList == NULL)
		printf("pElement is null parameter\n");
	else
		free(pList);
	pList = 0;
}

int		isArrayListFull(ArrayList* pList)
{
	if (pList == NULL)
	{
		printf("pList is null parameter\n");
		return (FALSE);
	}
	if (pList->maxElementCount == pList->currentElementCount)
		return (TRUE);
	return (FALSE);
}

int 	addALElement(ArrayList* pList, int position, ArrayListNode element)
{	
	if (pList == NULL)
	{
		printf("pList is null parameter\n");
		return (FALSE);
	} // 널 파라미터일 경우
	if (position < 0 || position >= pList->maxElementCount)
	{
		printf("Invalid position value.\n");
		return (FALSE);
	} // position도 예외처리 할 것 : 할당되지 않은 영역에서 접근하지 않게끔
	if (!pList->pElement[position].data)
	{
		pList->pElement[position].data = element.data;
		pList->currentElementCount++;
	}
	else if (pList->maxElementCount > pList->currentElementCount)
	{
		memmove(&pList->pElement[position + 1], &pList->pElement[position], sizeof(*pList) * (pList->maxElementCount - position - 1));
		pList->pElement[position].data = element.data;
		pList->currentElementCount++;
	}
	else if (pList->currentElementCount == pList->maxElementCount)
	{
		ArrayList *tmp = (ArrayList *)realloc(pList, sizeof(ArrayList));
		if (!tmp)
			return (FALSE);
		deleteArrayList(pList);
		memmove(&tmp->pElement[position + 1], &tmp->pElement[position], sizeof(*pList) * (tmp->maxElementCount - position - 1));
		tmp->pElement[position].data = element.data;
		tmp->currentElementCount++;
		pList = tmp;
	}
	return (TRUE);
}

int 	removeALElement(ArrayList* pList, int position)
{
	if (pList == NULL)
	{
		printf("pList is null parameter\n");
		return (FALSE);
	}
	if (position < 0 || position >= pList->maxElementCount)
	{
		printf("Invalid position value.\n");
		return (FALSE);
	}
	if (pList->currentElementCount == 0)
		return (TRUE);
	memmove(&pList->pElement[position], &pList->pElement[position + 1], sizeof(*pList) * (pList->maxElementCount - position - 1));
	pList->currentElementCount--;
	return (TRUE);	
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{
	if (pList == NULL)
		return (NULL);
	if (position >= 0 && position < pList->maxElementCount)
		return (NULL);
	return (&pList->pElement[position]);
}

void displayArrayList(ArrayList* pList)
{
	int i;

	i = 0;
	if (pList == NULL)
	while (i < pList->currentElementCount)
	{
		printf("[%d] : %d\n", i, pList->pElement[i].data);
		i++;
	}
} // 중간에 값이 비어있을 때 어떻게 할 것인가? 그대로 뽑아낼 것인가? -> yes

void clearArrayList(ArrayList* pList)
{
	int i;

	i = 0;
	if (pList == NULL)
		return ;
	while (i < pList->maxElementCount)
	{
		pList->pElement[i].data = 0;
		i++;
	}
}

int getArrayListLength(ArrayList* pList)
{
	// 배열에 들어있는 원소의 개수인가? 아니면 원소 최대 크기의 개수인가?
	if (pList == NULL)
		return (0);
	return (pList->currentElementCount);
}