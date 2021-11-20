#ifndef _ARRAYLIST_
#define _ARRAYLIST_

typedef struct ArrayListNodeType
{
	int data;
} ArrayListNode;

typedef struct ArrayListType
{
	int maxElementCount;		// the number of maximum element
	int currentElementCount;	// the number of current element existing
	ArrayListNode *pElement;	// the 1-dimensional array to store element in
} ArrayList;

/*
maxElementCount 만큼 pElement를 동적할당하는 함수
*/
ArrayList* createArrayList(int maxElementCount);

/*
PList를 전부 free하는 함수
*/
void deleteArrayList(ArrayList* pList);

/*
currentElementCount가 maxElementCount와 같은지 비교하는 함수
*/
int isArrayListFull(ArrayList* pList);

/*
원하는 위치(position, 인덱스)에 element를 삽입하기 위한 함수
*/
int addALElement(ArrayList* pList, int position, ArrayListNode element);

/*
원하는 위치(position, 인덱스)에서 pList를 제거하기 위한 함수
*/
int removeALElement(ArrayList* pList, int position);

/*
Plist에 해당하는 위치(position, 인덱스)의 값을 가져오는 함수
*/
ArrayListNode* getALElement(ArrayList* pList, int position);
/*
전체 pList를 가져오는 함수
*/
void displayArrayList(ArrayList* pList);
/*
안에 content 값을 0으로 초기화시키는 함수
*/
void clearArrayList(ArrayList* pList);

/*
pList의 길이를 구하는 함수
*/
int getArrayListLength(ArrayList* pList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif