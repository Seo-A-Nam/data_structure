#include "sort.h"

void    swap_Nodes(DoublyListNode *pnode1, DoublyListNode *pnode2)
{
    int temp = 0;

    temp = pnode1->data;
    pnode1->data = pnode2->data;
    pnode2->data = temp;
}

void    quick_sort(DoublyList *pList, int left, int right)
{
    int pivot = right;

    while (1)
    {

    }
}