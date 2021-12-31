#ifndef _HEAP_H_
# define _HEAP_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TRUE        1
#define FALSE       0
typedef struct HeapElementType
{
    int key;
  char value;
} HeapNode;
typedef struct ArrayHeapType
{
    int maxElementCount;        // 최대 원소 개수
    int currentElementCount;    // 현재 원소의 개수
    HeapNode *pElement; // 원소 저장을 위한 1차원 배열
} ArrayHeap;


ArrayHeap* createHeap(int maxElementCount);
void deleteArrayHeap(ArrayHeap* pHeap);
int isArrayHeapFull(ArrayHeap* pHeap);
int isArrayHeapEmpty(ArrayHeap* pHeap);
int insertMaxHeapNode(ArrayHeap* pHeap, HeapNode element);
HeapNode *deleteMaxHeapNode(ArrayHeap* pHeap);
int insertMinHeapNode(ArrayHeap* pHeap, HeapNode element);
HeapNode *deleteMinHeapNode(ArrayHeap* pHeap);
HeapNode* getHeapNode(ArrayHeap* pHeap, int position);
void displayArrayHeap(ArrayHeap* pHeap);
void clearArrayHeap(ArrayHeap* pHeap);
int getArrayHeapLength(ArrayHeap* pHeap);

#endif