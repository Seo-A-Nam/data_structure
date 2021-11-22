#include "linkedlist.h"
/*
typedef struct ListNodeType
{
	int data;
	struct ListNodeType* pLink;
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;	// 현재 인덱스의 위치
	ListNode headerNode;		// data와 다음 주소를 가르키는 포인터
} LinkedList;
*/

void    createLinkedList_test()
{
    LinkedList *lst;
    
    lst = createLinkedList();
    printf("LinkedList : %p\ncurrentElementCount : %d\n", lst, lst->currentElementCount);
}

void addLLElement_test()
{
	LinkedList *pList;
    //ListNode    tmp;
    ListNode    ele;
	int stat;

	ele.data = 10;
	pList = createLinkedList();
	//printf("%p\n", &pList->headerNode);
	//printf("%p %p %d\n", &pList->headerNode, pList->headerNode.pLink, pList->headerNode.data);

	for (int i = 0; i < 5; i++) {
		ele.data = i+1;
	    addLLElement(pList, i, ele);
	}
	//printf("%p %p %d\n", &pList->headerNode, pList->headerNode.pLink, pList->headerNode.data);

	//stat = addLLElement(pList, 1, ele);
	//stat = addLLElement(pList, 1, ele);

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
    ListNode    ele;

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
	//createLinkedList_test();
	//addLLElement_test();
    //deleteLinkedList_test();
    //removeLLElement_test();
    //getLLElement_test();
    //clearLinkedList_test();
    //getLinkedListLength_test();
    //deleteLinkedList_test();
    //system("leaks a.out");
    return (1);
}