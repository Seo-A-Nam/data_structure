#include "merge_sort.h"

void    splitHeads(LinkedList *pList, LinkedList *pList_a, LinkedList *pList_b)
{
    if (pList == NULL || pList_a == NULL || pList_b == NULL)
    {
        printf("[error] Null parameter.\n");
        return ;
    }
	int len = pList->currentElementCount;
    ListNode *node = pList->headerNode.pLink;

    for (int i = 0; i < (len / 2); i++)
    {
        addLLElement(pList_a, i, *node);
        node = node->pLink;
    }
    for (int i = 0; i < len - (len / 2); i++)
    {
        addLLElement(pList_b, i, *node);
        node = node->pLink;
    }
    deleteLinkedList(pList);
}

LinkedList  *sort_Merge(LinkedList *merge_a, LinkedList *merge_b)
{
    LinkedList  *list = createLinkedList();
    ListNode  *ptr_a = merge_a->headerNode.pLink;
    ListNode  *ptr_b = merge_b->headerNode.pLink;
    int count = merge_a->currentElementCount + merge_b->currentElementCount;
    int i = 0;

    while (i < count)
    {
        if (ptr_a == NULL) // 아래 elif 문과 합치지 말 것. segfault 남. 
        {
            addLLElement(list, i, *ptr_b);
            ptr_b = ptr_b->pLink;
        }
        else if (ptr_b == NULL) // 아래 elif 문과 합치지 말 것. segfault 남.
        {
            addLLElement(list, i, *ptr_a);
            ptr_a = ptr_a->pLink;
        }
        else if (ptr_a->data > ptr_b->data)
        {
            addLLElement(list, i, *ptr_b);
            ptr_b = ptr_b->pLink;
        }
        else
		{
            addLLElement(list, i, *ptr_a);
			ptr_a = ptr_a->pLink;
		}
        i++;
    }
    deleteLinkedList(merge_a);
    deleteLinkedList(merge_b);
	return (list);
}

LinkedList  *mergeSort(LinkedList *pList)
{
    if (pList->currentElementCount == 1)
        return (pList); // 리턴 조건

    LinkedList *pList_a = createLinkedList();
	LinkedList *pList_b = createLinkedList();
    LinkedList *merge_a;
    LinkedList *merge_b;
    LinkedList *list;

    splitHeads(pList, pList_a, pList_b);
    merge_a = mergeSort(pList_a);
    merge_b = mergeSort(pList_b);
    list = sort_Merge(merge_a, merge_b);
    return (list);
}
