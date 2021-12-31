#include "heap.h"

void test()
{
  ArrayHeap *heap = createHeap(7);
  HeapNode h1 = {20, 'a'};
  HeapNode h2 = {6, 'b'};
  HeapNode h3 = {12, 'c'};
  HeapNode h4 = {2, 'd'};
  HeapNode h5 = {4, 'e'};
  HeapNode h6 = {30, 'f'};
  insertMaxHeapNode(heap, h1);
  insertMaxHeapNode(heap, h2);
  insertMaxHeapNode(heap, h3);
  insertMaxHeapNode(heap, h4);
  insertMaxHeapNode(heap, h5);
  insertMaxHeapNode(heap, h6);
  HeapNode *root = deleteMaxHeapNode(heap);
  printf("%d %c\n", root->key, root->value);
  displayArrayHeap(heap);
  free(root);
  root = 0;
  clearArrayHeap(heap);
}

int main()
{
    test();
    system("leaks a.out");
    return 0;
}