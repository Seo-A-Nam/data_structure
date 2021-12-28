#ifndef _MERGE_SORT_
#define _MERGE_SORT_

#include "linkedList/linkedlist.h"

// =====================  MAIN ============================
void    displayLl(LinkedList *pList);
LinkedList *lst_cpy(LinkedList *pList);

// ====================== MERGE SORT ======================

void    	splitHeads(LinkedList *pList, LinkedList *pList_a, LinkedList *pList_b);
LinkedList  *sort_Merge(LinkedList *merge_a, LinkedList *merge_b);
LinkedList  *mergeSort(LinkedList *pList);

#endif