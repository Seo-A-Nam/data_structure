#ifndef _LINKEDLIST_
#define _LINKEDLIST_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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


/*
링크드리스트를 생성하여 그 포인터를 반환하는 함수
*/
LinkedList* createLinkedList();

/*
pList의 원하는 위치(position)에 노드(element)를 삽입하는 함수
*/
int addLLElement(LinkedList* pList, int position, ListNode element);

/*
pList의 원하는 위치(position)에 있는 노드(element)를 제거하는 함수
*/
int removeLLElement(LinkedList* pList, int position);

/*
pList의 원하는 위치(position)에 있는 노드(element)를 가져오는 함수
*/
ListNode* getLLElement(LinkedList* pList, int position);

/*
pList의 data값을 0으로 초기화하는 함수
*/
void clearLinkedList(LinkedList* pList);

/*
pList의 길이를 구해서 반환하는 함수
*/
int getLinkedListLength(LinkedList* pList);

/*
pList를 free()해서 링크드리스트를 삭제하는 함수
*/
void deleteLinkedList(LinkedList* pList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif