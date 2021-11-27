#include "linkedlist.h"

void    createLinkedList_test()
{
    LinkedList *lst;
    
    lst = createLinkedList();
    printf("LinkedList : %p\ncurrentElementCount : %d\n", lst, lst->currentElementCount);
}

void addLLElement_test()
{
	LinkedList *pList;
    ListNode    ele;
	int stat;

	ele.data = 10;
	pList = createLinkedList();

	for (int i = 0; i < 5; i++) {
		ele.data = i+1;
	    addLLElement(pList, i, ele);
	}

    while (pList->headerNode.pLink)
    {
		printf("%p %d\n", pList->headerNode.pLink, pList->headerNode.data);
		pList->headerNode = *pList->headerNode.pLink;
    }
	printf("%p %d\n", pList->headerNode.pLink, pList->headerNode.data);

    printf("\n");
}

void    printLinkedList(LinkedList *pList)
{
    ListNode    *tmp;

    tmp = pList->headerNode.pLink;
    while (tmp)
    {
        printf("[%p]\t%d\n", tmp, tmp->data);
        tmp = tmp->pLink;
    }
}

void    removeLLElement_test()
{
    LinkedList  *ls;
    //ListNode    ele;

    ls = createLinkedList();
    for (int i = 0; i < 5; i++)
    {
        ListNode ele;
        ele.data = i;
        ele.pLink = NULL;
        addLLElement(ls, i,ele);
    }
    printLinkedList(ls);
    printf("\n\n");
    removeLLElement(ls, 4);
    printLinkedList(ls);
}

void    getLLElement_test()
{
    LinkedList  *ls;
    ListNode    *ele;

    ls = createLinkedList();
    for (int i = 0; i < 5; i++)
    {
        ListNode ele2;
        ele2.data = i;
        ele2.pLink = NULL;
        addLLElement(ls, i, ele2);
    }
    printLinkedList(ls);
    printf("\n\n");
    for (int i = 0; i < 5; i++)
    {
        ele = getLLElement(ls, i);
        printf("[%p]\t%d\n", ele, ele->data);
    }
}

void    clearLinkedList_test()
{
    LinkedList  *ls;
    ListNode    *ele;

    ls = createLinkedList();
    for (int i = 0; i < 5; i++)
    {
        ListNode ele2;
        ele2.data = i;
        ele2.pLink = NULL;
        addLLElement(ls, i, ele2);
    }
    printLinkedList(ls);
    printf("\n\n");
    clearLinkedList(ls);
    printLinkedList(ls);
}

void    getLinkedListLength_test()
{
    LinkedList  *ls;
    ListNode    *ele;

    ls = createLinkedList();
    for (int i = 0; i < 5; i++)
    {
        ListNode ele2;
        ele2.data = i;
        ele2.pLink = NULL;
        addLLElement(ls, i, ele2);
    }
    printLinkedList(ls);
    printf("\n\n");
    printf("%d\n", getLinkedListLength(ls));
}

void    deleteLinkedList_test()
{
    LinkedList  *ls;
    ListNode    ele;

    ls = createLinkedList();
    for (int i = 0; i < 5; i++)
    {
        ListNode ele2;
        ele2.data = i;
        ele2.pLink = NULL;
        addLLElement(ls, i, ele2);
    }
    printLinkedList(ls);
    printf("\n\n");
    deleteLinkedList(ls);
}

int main() {
    return (1);
}