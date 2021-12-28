#include "quick_sort.h"

void    swap_Nodes(DoublyListNode *pnode1, DoublyListNode *pnode2)
{
    int temp = 0;

    temp = pnode1->data;
    pnode1->data = pnode2->data;
    pnode2->data = temp;
} // pRLink, PLLink 같은 포인터 관계 바꿀 필요없이 그냥 노드 값만 바꿔주는 것으로 충분. 

void    find_left(DoublyListNode **pLeft, DoublyListNode *pivot)
{
    while ((*pLeft)->data < pivot->data)
    {
        (*pLeft) = (*pLeft)->pRLink;
    }
} // 기존의 pLeft 위치로부터 뒤로 쭉 살펴보며 처음 만나는 pivot 보다 큰 값을 찾는다.

void    find_right(DoublyListNode **pLeft, DoublyListNode **pRight, DoublyListNode *pivot)
{
    while ((*pRight)->data > pivot->data)
    {
        if ((*pRight) == (*pLeft))
            break ;
        (*pRight) = (*pRight)->pLLink;
    }
} // 기존의 pRight 위치로부터 앞쪽으로 쭉 살펴보며 처음 만나는 pivot 보다 큰 값을 찾는다.

void    quick_sort(DoublyList *pList, DoublyListNode *left, DoublyListNode *pivot)
{
    DoublyListNode *pLeft = left;
    DoublyListNode *pRight = pivot;

    if (left == pivot)
        return ;
    while (1)
    {
        find_left(&pLeft, pivot); // pLeft의 포인터 주소가 이동하는 것이므로 주솟값을 넘겨준다.
        find_right(&pLeft, &pRight, pivot); // pRight의 포인터 주소가 이동하는 것이므로 주솟값을 넘겨준다.
        if (pRight == pLeft)
            break ;
        swap_Nodes(pLeft, pRight); // left랑 right랑 바꿔줌
        pLeft = pLeft->pRLink; // left 한칸 이동
        pRight = pivot; // right는 다시 pivot부터 시작할 수 있도록 돌려줌.
    }
    swap_Nodes(pLeft, pivot); 
    /* 
    * left랑 right가 같아져서 나온 시점에서, pivot과 left 값을 바꿔준다. 이때 이 바꿔준 pivot의 위치는 이 배열이 완전히 정렬됬을 때 해당 원소의 위치와 같다.
    * 그러니 위치를 잘 찾아가게된 해당 원소를 내버려두고, 재귀를 호출해서 pivot 앞 뒤의 두 블럭을 마저 정렬해준다. 
    */
    if (pLeft != left)
        quick_sort(pList, left, pLeft->pLLink); 
    if (pLeft != pivot)
        quick_sort(pList, pLeft->pRLink, pivot);
}
/* 
* left : 앞단부터 살펴봤을 때 처음 만나는 pivot보다 큰 값
* right : pivot(현재 보고있는 블럭의 뒷단)부터 앞쪽 방향으로 살폈을 때, 처음 만나게되는 pivot보다 작은 값
*/

// pdf에 나온 예시 : 80 50 70 10 60 20 40 30

/*
* 첫날 디버깅 실패 : 
* 이유 - 계속 노드 값이 서로 바뀌는데 pRight라는 위치를 고정시켜놓고 그 앞쪽으로 새로운 pRight를 탐색하려했음
*       계속 노드 값이 바뀌는 상황에서는 매번 find_right()를 호출하여 조건에 맞는 새로운 pRight 위치를 찾아주는 것이 중요함.
        pLeft와 find_left() 관해서도 마찬가지.
*/