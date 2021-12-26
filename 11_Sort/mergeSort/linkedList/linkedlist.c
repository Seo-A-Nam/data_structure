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
} // 첫 노드를 0번째로 하는가? 헤더 노드를 0번쨰로 하는 가?
// (우리는 전자를 택함. 실제로 헤더는 스택이고...어디 영역에 저장되는 지 모르니까)

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
   tmp->pLink = curr->pLink;  // getALElement()를 통해 직전 노드의 주소를 받아와서 하는 방법도 있더라. (발표자 코드 참고)
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
    
    // 메모리 free() 과정 전에, clearLinkedList()를 쓴 사람들이 있었음. 우리도 그걸 추가하는 게 더 바람직할지도 모름.
    if (!pList)
        return ;
    if (&(pList->headerNode) == NULL)
    {
        free(pList);
        return ;
    } // 새롭게 추가된 부분.
    curr = pList->headerNode.pLink;
 	if (pList == NULL)
    {
	 	printf("there is no LinkedList existing\n");
        return ;
    }
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
