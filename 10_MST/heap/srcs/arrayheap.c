#include "../includes/arrayheap.h"

ArrayHeap* createArrayHeap(int maxElementCount)
{
	ArrayHeap *Heap;
	
	if (!(Heap = (ArrayHeap *)malloc(sizeof(ArrayHeap))))
		return (NULL);
	Heap->maxElementCount = maxElementCount;
	Heap->currentElementCount = 0;
	Heap->pElement = (ArrayHeapNode *)malloc(sizeof(ArrayHeapNode) * (maxElementCount + 1));
	if (!Heap->pElement)
	{
		free(Heap);
		return (NULL);
	}
	return (Heap);
}

int insertHeapAH(ArrayHeap* pHeap, ArrayHeapNode element)
{
	if (!pHeap)
		return (FALSE);
	if (isArrayHeapFull(pHeap))
		return (FALSE);
	pHeap->currentElementCount++;
	pHeap->pElement[pHeap->currentElementCount] = element;
	// Sorting
	int nowi = pHeap->currentElementCount;
	while (nowi > 1)
	{
		if (pHeap->pElement[nowi].weight < pHeap->pElement[nowi / 2].weight)
		{
			ArrayHeapNode tmp = pHeap->pElement[nowi];
			pHeap->pElement[nowi] = pHeap->pElement[nowi / 2];
			pHeap->pElement[nowi / 2] = tmp;
			nowi /= 2;
		}
		else
			break;
	}
	return (TRUE);
}

void min_heapify(ArrayHeap* pHeap, int idx)
{
	int tmp = idx;
	ArrayHeapNode *tmparr = pHeap->pElement;

	// child node가 없는 경우!
	if (pHeap->currentElementCount < idx * 2)
		return ;
	// child node가 왼쪽에만 있는 경우
	if (pHeap->currentElementCount == idx * 2)
	{
		if (tmparr[idx].weight > tmparr[idx * 2].weight)
			tmp = idx * 2;
	}
	// child node가 둘 다 있는 경우
	else
	{
		// left가 작은 경우
		if (tmparr[idx * 2].weight < tmparr[idx * 2 + 1].weight)
		{
			if (tmparr[idx].weight > tmparr[idx * 2].weight)
				tmp = idx * 2;
		}
		// right가 큰 경우
		else
		{
			if (tmparr[idx].weight > tmparr[idx * 2 + 1].weight)
				tmp = idx * 2 + 1;
		}
	}

	if (tmp != idx)
	{
		ArrayHeapNode tempNode;

		tempNode = tmparr[idx];
		tmparr[idx] = tmparr[tmp];
		tmparr[tmp] = tempNode;
		min_heapify(pHeap, tmp);
	}
}

ArrayHeapNode *deleteHeapAH(ArrayHeap* pHeap)
{
	ArrayHeapNode *ret_node;

	if (!pHeap)
		return (FALSE);
	if (isArrayHeapEmpty(pHeap))
		return (FALSE);
	ret_node = (ArrayHeapNode *)malloc(sizeof(ArrayHeapNode));
	if (!ret_node)
		return (FALSE);
	*ret_node = pHeap->pElement[1];
	pHeap->pElement[1].weight = pHeap->pElement[pHeap->currentElementCount].weight;
	pHeap->pElement[1].x = pHeap->pElement[pHeap->currentElementCount].x;
	pHeap->pElement[1].y = pHeap->pElement[pHeap->currentElementCount].y;
	pHeap->currentElementCount--;
	min_heapify(pHeap, 1);
	return (ret_node);
}

ArrayHeapNode *peekAH(ArrayHeap* pHeap)
{
    ArrayHeapNode *ret_node;

	if (!pHeap)
		return (FALSE);
    if (isArrayHeapEmpty(pHeap))
        return (FALSE);
	ret_node = (ArrayHeapNode *)malloc(sizeof(ArrayHeapNode));
	if (!ret_node)
		return (FALSE);
    *ret_node = pHeap->pElement[1];
    return (ret_node);
}

void deleteArrayHeap(ArrayHeap* pHeap)
{
	if (!pHeap)
		return ;
	while (!isArrayHeapEmpty(pHeap))
		free(deleteHeapAH(pHeap));
	free(pHeap->pElement);
	free(pHeap);
}

int isArrayHeapFull(ArrayHeap* pHeap)
{
	if (!pHeap)
		return (FALSE);
	return (pHeap->maxElementCount == pHeap->currentElementCount ? TRUE : FALSE);
}

int isArrayHeapEmpty(ArrayHeap* pHeap)
{
	if (!pHeap)
		return (FALSE);
	return (pHeap->currentElementCount == 0 ? TRUE : FALSE);
}

void displayArrayHeap(ArrayHeap* pHeap)
{
	int idx = 1;
	if (!pHeap)
			return;
        
	printf("The max size of stack : %d\n", pHeap->maxElementCount);
	printf("The current size of stack : %d\n", pHeap->currentElementCount);
	for (int i = 0; i < pHeap->currentElementCount; i++)
	{
			printf("{index: %d, x: %d, y: %d, weight: %d}\n", idx, pHeap->pElement[idx].x, pHeap->pElement[idx].y, pHeap->pElement[idx].weight);
	idx++;
	}
}

