#include "linkedlist.h"


LinkedList* createLinkedList()
{
    LinkedList *lst;

    lst = (LinkedList *)malloc(sizeof(LinkedList));
	if (lst == NULL)
		return (NULL);
	lst->currentElementCount = 0;
	lst->headerNode.pLink = NULL;
	return lst;
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
    ListNode    *prev;
    ListNode    *node;
    int         i;

    i = 0;
    if (pList == NULL)
        return (FALSE);
    if (pList->currentElementCount + 1 < position || position < 0)
        return (FALSE);
    node = (ListNode *)malloc(sizeof(ListNode));
    if (node == NULL)
        return (FALSE);
    node->data = element.data;
    prev = &pList->headerNode;
    while(i < position && prev->pLink)
    {
        prev = prev->pLink;
        i++;
    }
    node->pLink = prev->pLink;
    prev->pLink = node;
    pList->currentElementCount++;
    return (TRUE);
}

int removeLLElement(LinkedList* pList, int position)
{
   ListNode    *curr;
   ListNode    *tmp;
   int          i;

   if (position >= pList->currentElementCount || position < 0)
   {
       printf("Invalid Position value\n");
       return (FALSE);
   }
   // 현재 존재하는 개수 이상인 인덱스에서 노드를 삭제할 수 없다. 따라서 FALSE 반환.
   if (pList == NULL)
   {
       printf("There is no LinkedList existing\n");
       return (FALSE);
   }
   tmp = pList->headerNode.pLink;
   if (position == 0)
   {
       pList->headerNode.pLink = tmp->pLink;
       free(tmp);
       tmp = 0;
       pList->currentElementCount--;
       return (TRUE);
   }
   i = 0;
   while (++i < position && tmp->pLink)  
       tmp = tmp->pLink;
   //해당 position의 직전 노드까지 이동. (tmp)
   curr = tmp->pLink; // curr - 해당 포지션의 노드
   tmp->pLink = curr->pLink;
   free(curr);
   curr = 0;
   pList->currentElementCount--;
   // 중간에 노드를 삭제하는 경우 (해당 position노드의 연결을 끊어주고 free()한 뒤, 그 뒤에 있던 노드를 현재 노드의 pLink에 연결)
   return (TRUE);
}

ListNode* getLLElement(LinkedList* pList, int position)
{
   ListNode    *node;

   if (position > pList->currentElementCount)
   {
       printf("Invalid Position value\n");
       return (FALSE);
   }
   if (pList == NULL)
   {
       printf("There is no LinkedList existing\n");
       return (FALSE);
   }
   node = pList->headerNode.pLink;
   while (position--)
       node = node->pLink;
   return (node);
}

void clearLinkedList(LinkedList* pList)
{
    ListNode    *ls;
    int     index;

    if (pList == NULL)
        return ;
    index = pList->currentElementCount;
    ls = pList->headerNode.pLink;
    while (index--)
    {
        ls->data = 0;
        ls = ls->pLink;
    }
}

int getLinkedListLength(LinkedList* pList)
{
    if (pList == NULL)
        return (0);
    return (pList->currentElementCount);
}

 void deleteLinkedList(LinkedList* pList)
 {
    ListNode  *curr;
    ListNode  *tmp;
    
    curr = pList->headerNode.pLink;
 	if (pList == NULL)
	 	printf("there is no LinkedList existing\n");
	 else
     {
        while(curr) 
        {
            tmp = curr;
            curr = curr->pLink;
            free(tmp);
            tmp = 0;
        }
        free(pList);
        pList = 0;
    }
 }
