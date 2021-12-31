#include "heap.h"

ArrayHeap* createHeap(int maxElementCount)
{
    ArrayHeap* pHeap;
  if (maxElementCount < 0)
  {
    printf("maxElementCount minus\n");
  }
  pHeap = (ArrayHeap *)malloc(sizeof(ArrayHeap));
  if (!pHeap)
  {
    printf("pHeap malloc failure\n");
    return (NULL);
  }
  pHeap->maxElementCount = maxElementCount;
  pHeap->currentElementCount = 0;
  pHeap->pElement = (HeapNode*)malloc(sizeof(HeapNode) * maxElementCount);
  if (!(pHeap->pElement))
  {
    printf("pElement malloc failure\n");
    free(pHeap);
    return (NULL);
  }
  memset(pHeap->pElement, 0, sizeof(HeapNode) * maxElementCount);
  return (pHeap);
}
void deleteArrayHeap(ArrayHeap* pHeap)
{
    if (pHeap == NULL)
  {
    printf("[error] Null Parameter : pHeap\n");
    return ;
  }
  memset(&pHeap, 0, sizeof(ArrayHeap *));
  free(pHeap);
  pHeap = 0;
}
int isArrayHeapFull(ArrayHeap* pHeap)
{
  if (pHeap == NULL)
  {
    printf("[error] Null Parameter : pHeap\n");
    return (FALSE);
  }
  if (pHeap->maxElementCount == pHeap->currentElementCount)
  {
    return (TRUE);
  }
  return (FALSE);
}
int isArrayHeapEmpty(ArrayHeap* pHeap)
{
  if (pHeap == NULL)
  {
    printf("[error] NULL parameter: pHeap\n");
    return (FALSE);
    }
  if (pHeap->currentElementCount == 0)
  {
    return (TRUE);
  }
  return (FALSE);
}
int insertMaxHeapNode(ArrayHeap* pHeap, HeapNode element)
{
  if (isArrayHeapFull(pHeap))
  {
    printf("[error] Heap is full\n");
    return (FALSE);
  }
  //트리의 마지막 자리에 임시 저장
  pHeap->currentElementCount++;
  int i = pHeap->currentElementCount; // 1부터 처음 인덱스 시작되니까.
  while(i != 1 && (element.key > pHeap->pElement[i/2].key))
  {
    pHeap->pElement[i] = pHeap->pElement[i/2];
    i = i/2;
  }
  pHeap->pElement[i] = element;
  return (TRUE);
}
HeapNode *deleteMaxHeapNode(ArrayHeap* pHeap)
{
  HeapNode *pReturn;
    if (pHeap == NULL)
  {
    printf("[error] NULL parameter: pHeap\n");
    return (FALSE);
  }
  if (isArrayHeapEmpty(pHeap))
  {
    printf("[error] Heap is empty: pHeap\n");
    return (FALSE);
  }
  pReturn = (HeapNode *)malloc(sizeof(HeapNode));
  if (pReturn == NULL)
  {
    printf("[error] malloc failure : pReturn\n");
    return (FALSE);
  }
  //step1
  *pReturn = (pHeap->pElement[1]);
  //step2
  int i = pHeap->currentElementCount;
  HeapNode *temp = &(pHeap->pElement[i]);
  pHeap->currentElementCount--;
  //step3
  int parent = 1;
    int child = 2;
  while (child <= pHeap->currentElementCount)
  {
    if ((child < pHeap->currentElementCount)
        && pHeap->pElement[child].key < pHeap->pElement[child + 1].key)
      child++;
    if (temp->key >= pHeap->pElement[child].key)
      break;
    pHeap->pElement[parent] = pHeap->pElement[child];
    parent = child;
    child *= 2;
  }
  pHeap->pElement[parent] = *temp;
    return (pReturn);
}
int insertMinHeapNode(ArrayHeap* pHeap, HeapNode element)
{
  if (isArrayHeapFull(pHeap))
  {
    printf("[error] Heap is full\n");
    return (FALSE);
  }
  //트리의 마지막 자리에 임시 저장
  pHeap->currentElementCount++;
  int i = pHeap->currentElementCount; // 1부터 처음 인덱스 시작되니까.
  while(i != 1 && (element.key < pHeap->pElement[i/2].key))
  {
    pHeap->pElement[i] = pHeap->pElement[i/2];
    i = i/2;
  }
  pHeap->pElement[i] = element;
  return (TRUE);
}
HeapNode *deleteMinHeapNode(ArrayHeap* pHeap)
{
  HeapNode *pReturn;
    if (pHeap == NULL)
  {
    printf("[error] NULL parameter: pHeap\n");
    return (FALSE);
  }
  if (isArrayHeapEmpty(pHeap))
  {
    printf("[error] Heap is empty: pHeap\n");
    return (FALSE);
  }
  pReturn = (HeapNode *)malloc(sizeof(HeapNode));
  if (pReturn == NULL)
  {
    printf("[error] malloc failure : pReturn\n");
    return (FALSE);
  }
  //step1
  *pReturn = (pHeap->pElement[1]);
  //step2
  int i = pHeap->currentElementCount;
  HeapNode *temp = (&pHeap->pElement[i]);
  pHeap->currentElementCount--;
  //step3
  int parent = 1;
    int child = 2;
  while (child <= pHeap->currentElementCount)
  {
    if ((child < pHeap->currentElementCount)
        && pHeap->pElement[child].key > pHeap->pElement[child + 1].key)
      child++;
    if (temp->key <= pHeap->pElement[child].key)
      break;
    pHeap->pElement[parent] = pHeap->pElement[child];
    parent = child;
    child *= 2;
  }
  pHeap->pElement[parent] = *temp;
  return (pReturn);
}
HeapNode* getHeapNode(ArrayHeap* pHeap, int position)
{
    HeapNode *pReturn;
    if (pHeap == NULL)
  {
    printf("[error] NULL parameter: pHeap\n");
    return (FALSE);
  }
  return (&pHeap->pElement[position]);
}
void displayArrayHeap(ArrayHeap* pHeap)
{
  if (pHeap == NULL)
  {
    printf("[error] NULL parameter: pHeap\n");
    return ;
  }
  int i = 1;
  while (i <= pHeap->currentElementCount)
  {
    printf("key [%d] value : %c\n", pHeap->pElement[i].key, pHeap->pElement[i].value);
    i++;
  }
}
void clearArrayHeap(ArrayHeap* pHeap)
{
  if (pHeap == NULL)
  {
    printf("[error] NULL parameter: pHeap\n");
    return ;
  }
  memset(pHeap->pElement, 0, sizeof(HeapNode) * pHeap->maxElementCount);
  free(pHeap->pElement);
  pHeap->currentElementCount = 0;
  free(pHeap);
  pHeap = 0;
}
int getArrayHeapLength(ArrayHeap* pHeap)
{
  if (pHeap == NULL)
  {
    printf("[error] NULL parameter: pHeap\n");
    return (FALSE);
  }
  return (pHeap->currentElementCount);
}