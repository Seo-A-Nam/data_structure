#include "arraylist.h"

ArrayList* createArrayList(int maxElementCount)
{
    ArrayList *arr;
	if (maxElementCount <= 0)
	{
		return NULL;
	}
    arr = (ArrayList *)malloc(sizeof(ArrayList));
    if (!(arr))
        return NULL;
    arr->maxElementCount = maxElementCount;
    arr->currentElementCount = 0;
    arr->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount);
    if (!arr->pElement)
	{
		free(arr);
		return NULL;
	}
	return (arr);
}