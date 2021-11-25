#include "doublylist.h"

DoublyList* createDoublyList()
{
	DoublyList *dl;

	dl = (DoublyList *)malloc(sizeof(DoublyList));
	if (dl == NULL)
		return (NULL);
	dl->currentElementCount = 0;
	dl->headerNode.data = 0;
	dl->headerNode.pLLink = NULL;
	dl->headerNode.pRLink = NULL;
	return (dl);
}

void deleteDoublyList(DoublyList* pList)
{
	DoublyListNode *node;
	DoublyListNode *release;

	if (pList == NULL)
		return ;
	node = pList->headerNode.pRLink;
	while (node && node != &pList->headerNode) {
		release = node;
		node = node->pRLink;
		free(release);
		release->pLLink = 0;
		release->pRLink = 0;
		release->data = 0;
	}
	free(pList);
	pList->currentElementCount = 0;
	pList->headerNode.pLLink = 0;
	pList->headerNode.pRLink = 0;
}

int addDLElement(DoublyList* pList, int position, DoublyListNode element)
{
	DoublyListNode *node;
	DoublyListNode *prev;
	int				i;

	i = 0;
	if (pList == NULL || (position < 0 || pList->currentElementCount < position))
		return (FALSE);
	node = (DoublyListNode *)malloc(sizeof(DoublyListNode));
	if (node == NULL)
		return (FALSE);
	node->data = element.data;
	prev = &pList->headerNode;
	while (i++ < position && prev->pRLink)
		prev = prev->pRLink;
	node->pRLink = prev->pRLink;
	node->pLLink = prev;
	prev->pRLink = node;
	if (node->pRLink == NULL || node->pRLink == &pList->headerNode)
	{
		node->pRLink = &pList->headerNode;
		pList->headerNode.pLLink = node;
	}
	pList->currentElementCount++;
	return (TRUE);
}

int removeDLElement(DoublyList* pList, int position)
{
	DoublyListNode *node;
	DoublyListNode *prev;
	DoublyListNode *next;
	int				i;

	i = 0;
	if (pList == NULL)
		return (FALSE);
	if (position >= pList->currentElementCount || position < 0)
		return (FALSE);
	prev = &pList->headerNode;
	while (i++ < position && prev->pRLink)
		prev = prev->pRLink;
	node = prev->pRLink;
	next = node->pRLink;
	next->pLLink = prev;
	prev->pRLink = next;
	free(node);
	pList->currentElementCount--;
	return (TRUE);
}

void clearDoublyList(DoublyList* pList)
{
	DoublyListNode *node;
	int				i;

	if (pList == NULL)
		return ;
	i = pList->currentElementCount;
	node = pList->headerNode.pRLink;
	while (i--)
	{
		node->data = 0;
		pList->currentElementCount--;
		node = node->pRLink;
	}
}

int getDoublyListLength(DoublyList* pList)
{
	if (pList == NULL)
		return (FALSE);
	return (pList->currentElementCount);
}

DoublyListNode* getDLElement(DoublyList* pList, int position)
{
	DoublyListNode *node;
	
	if (pList == NULL)
		return (FALSE);
	if (position >= pList->currentElementCount || position < 0)
		return (FALSE);
	if (pList->currentElementCount / 2 <= position)
	{
		node = pList->headerNode.pLLink;
		while (position--)
			node = node->pLLink;
	}
	else
	{
		node = pList->headerNode.pRLink;
		while (position--)
			node = node->pRLink;
	}
	return (node);
}

void displayDoublyList(DoublyList* pList)
{
	DoublyListNode *node;
	int i = 0;
	if (pList == NULL)
		return ;
	node = pList->headerNode.pRLink;
	while (node && node != &pList->headerNode)
	{
		if (i == 5)
			break;
		printf("prev : %p, node : %p, node->data : %d, next : %p\n", 
				node->pLLink, node, node->data, node->pRLink);
		node = node->pRLink;
		i++;
	}
}

void reverseDoublyLinkedList(DoublyList *pList) {
	DoublyListNode *st;
	DoublyListNode *ed;
	DoublyListNode *node_st;
	DoublyListNode *node_ed;

	if (pList == NULL)
		return ;

	node_st = &pList->headerNode;
	node_ed = &pList->headerNode;
	st = node_st->pRLink;
	ed = node_ed->pLLink;

	//st->pRLink = node->pLLink;
	//node->pLLink = node-
	//node->pLLink = tmp->pRLink;
	//st = node->pRLink;
	//ed = node->pLLink;

	for (int i = 0; i < 5; i++)
	{
		node_st->pRLink = ed->pRLink;
		node_st->pLLink = ed->pLLink;
		node_ed->pLLink = st->pLLink;
		node_ed->pRLink = st->pRLink;
		node_st = node_st->pRLink;
		node_ed = node_ed->pLLink;
		st = st->pRLink;
		ed = ed->pLLink;
	}
	displayDoublyList(pList);
}