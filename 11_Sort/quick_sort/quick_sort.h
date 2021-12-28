#ifndef _SORT_
#define _SORT_

#include "doublylist/doublylist.h"

// =====================  MAIN ============================
void    displayDl(DoublyList *pList);
DoublyList *lst_cpy(DoublyList *pList);

// ====================== QUICK SORT ======================
void    quick_sort(DoublyList *pList, DoublyListNode *left, DoublyListNode *pivot);
void    find_left(DoublyListNode **pLeft, DoublyListNode *pivot);
void    find_right(DoublyListNode **pLeft, DoublyListNode **pRight, DoublyListNode *pivot);
void    swap_Nodes(DoublyListNode *pnode1, DoublyListNode *pnode2);

#endif