#include "linkedlist.h"
#include <string.h> //NULL
#include <stdlib.h> //malloc

LinkedList* createLinkedList()
{
	LinkedList	*list;

	if (!(list = (LinkedList *)malloc(sizeof(LinkedList))))
		return (NULL);
	list->headerNode.to = 0;
	list->headerNode.weight = 0;
	list->headerNode.pLink = 0;
	list->currentElementCount = 0;
	return (list);
}

int addLLElement(LinkedList* pList, int position, ListNode element)
{
	ListNode *prev;
	ListNode *newE;

	if(!pList)
		return (FALSE);
	if (position < 0 || position > pList->currentElementCount)
		return (FALSE);
	if (!(newE = (ListNode *)malloc(sizeof(ListNode))))
		return (FALSE);
	*newE = element;
	newE->pLink = NULL;
	prev = &(pList->headerNode);
	while(position--)
		prev = prev->pLink;
	newE->pLink = prev->pLink;
	prev->pLink = newE;
	pList->currentElementCount++;
	return (TRUE);
}

int removeLLElement(LinkedList* pList, int position)
{
	ListNode *prev;
	ListNode *delnode;

	if(!pList)
		return (FALSE);
	if (position < 0 || position >= pList->currentElementCount)
		return (FALSE);
	prev = &(pList->headerNode);
	while(position--)
		prev = prev->pLink;
	delnode = prev->pLink;
	prev->pLink = delnode->pLink;
	free(delnode);
	pList->currentElementCount--;
	return (TRUE);
}

ListNode* getLLElement(LinkedList* pList, int position)
{
	ListNode *prev;

	if(!pList)
		return (NULL);
	if (position < 0 || position >= pList->currentElementCount)
		return (NULL);
	prev = &(pList->headerNode);
	position++;
	while(position--)
		prev = prev->pLink;
	return (prev);
}

void clearLinkedList(LinkedList* pList)
{
	if(!pList)
		return;
	while(pList->currentElementCount > 0)
		removeLLElement(pList, 0);
}

int getLinkedListLength(LinkedList* pList)
{
	if(!pList)
		return (FALSE);
	return (pList->currentElementCount);
}

void deleteLinkedList(LinkedList* pList)
{
	if(!pList)
		return;
	clearLinkedList(pList);
	free(pList);
}