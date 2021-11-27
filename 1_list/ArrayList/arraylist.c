 #include "arraylist.h"

ArrayList* createArrayList(int maxElementCount)
{
    ArrayList *arr;

	if (maxElementCount <= 0)
		return (NULL); // parameter exception handling
    arr = (ArrayList *)malloc(sizeof(ArrayList));
    if (arr == NULL)
        return (NULL); // memory allocation failure handling
    arr->maxElementCount = maxElementCount;
    arr->currentElementCount = 0;
    arr->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount);
    if (arr->pElement == NULL)
	{
		free(arr);
		arr = 0;
		return (NULL);
	} // memory allocation failure handling
	return (arr);
} 
/* 
* Note that stack memeory disappears when the function ends! so we should not take local variable to return it's memory address.
* instead, we should use malloc() and return it's pointer as a heap memory address.
*/

void		deleteArrayList(ArrayList* pList)
{
	if (pList->pElement == NULL)
		printf("pElement is null parameter\n"); // parameter exception handling
	else
		free(pList->pElement);
	pList->pElement = 0;
	if (pList == NULL)
		printf("pElement is null parameter\n"); // parameter exception handling
	else
		free(pList);
	pList = 0;
}
/*
* Additionally, we could also add clearArrayList() at the top of the line in this function. (to delete data of the elements)
*/

int		isArrayListFull(ArrayList* pList)
{
	if (pList == NULL)
	{
		printf("pList is null parameter\n");
		return (FALSE);
	} // parameter exception handling
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
	} // parameter exception handling
	if (position < 0 || position >= pList->maxElementCount)
	{
		printf("Invalid position value.\n");
		return (FALSE);
	} /// parameter exception handling
	if (!pList->pElement[position].data)
	{
		pList->pElement[position].data = element.data;
		pList->currentElementCount++;
	} // when the ArrayList is empty (0 Node in there)
	else if (pList->maxElementCount > pList->currentElementCount)
	{
		memmove(&pList->pElement[position + 1], &pList->pElement[position], sizeof(*pList) * (pList->maxElementCount - position - 1));
		pList->pElement[position].data = element.data;
		pList->currentElementCount++;
	} // push out the memory behind the given position, and put the element on that the position
	else if (pList->currentElementCount == pList->maxElementCount)
	{
		ArrayList *tmp = (ArrayList *)realloc(pList, sizeof(ArrayList));
		if (!tmp)
			return (FALSE); // memory allocation failure handling
		deleteArrayList(pList);
		memmove(&tmp->pElement[position + 1], &tmp->pElement[position], sizeof(*pList) * (tmp->maxElementCount - position - 1));
		tmp->pElement[position].data = element.data;
		tmp->currentElementCount++;
		pList = tmp;
	} // when the ArrayList is full, it allocates more memeory behind to add new node. (we made it work like the one of java library)
	return (TRUE);
} 

int 	removeALElement(ArrayList* pList, int position)
{
	if (pList == NULL)
	{
		printf("pList is null parameter\n");
		return (FALSE);
	} // parameter exception handling
	if (position < 0 || position >= pList->maxElementCount || position >= pList->currentElementCount)
	{
		printf("Invalid position value.\n");
		return (FALSE);
	} // parameter exception handling
	if (pList->currentElementCount == 0)
		return (TRUE);
	memmove(&pList->pElement[position], &pList->pElement[position + 1], sizeof(*pList) * (pList->maxElementCount - position - 1));
	pList->currentElementCount--;
	return (TRUE);	
}

ArrayListNode* getALElement(ArrayList* pList, int position)
{
	if (pList == NULL)
		return (NULL); // parameter exception handling
	if (position >= 0 && position < pList->currentElementCount && position < pList->maxElementCount)
		return (NULL); // parameter exception handling
	return (&pList->pElement[position]);
}


void displayArrayList(ArrayList* pList)
{
	int i;

	i = 0;
	if (pList == NULL)
		return ; // parameter exception handling
	while (i < pList->currentElementCount)
	{
		printf("[%d] : %d\n", i, pList->pElement[i].data);
		i++;
	}
}

void clearArrayList(ArrayList* pList)
{
	int i;

	i = 0;
	if (pList == NULL)
		return ; // parameter exception handling
	while (i < pList->maxElementCount)
	{
		pList->pElement[i].data = 0;
		i++;
	}
}

int getArrayListLength(ArrayList* pList)
{
	if (pList == NULL)
		return (0); // parameter exception handling
	return (pList->currentElementCount);
}