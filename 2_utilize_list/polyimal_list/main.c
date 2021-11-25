#include "poly.h"

static void	putLLElement(LinkedList *ls, int coef, int degree, int position)
{
	ListNode	ele;

	ele.coef = coef;
	ele.degree = degree;
	addLLElement(ls, position, ele);
} // addLLElement()와 element(노드) 값 할당을 동시에

void lsAB_NULL()
{
	/*
	lsA == NULL
	lsB == NULL
	*/
	LinkedList *lsA = NULL;
	LinkedList *lsB = NULL;
	LinkedList *lsC;

	lsC = addPoly(lsA, lsB);
	displayLinkedList(lsC);
}
/*
lsA가 NULL일때 다항식 계산
*/
void lsA_NULL()
{
	/*
	lsA == NULL
	lsB == x^{5} + 3x^{3}
	*/
	LinkedList *lsA = NULL;
	LinkedList *lsB = NULL;
	LinkedList *lsC;
	
	lsB = createLinkedList();
	putLLElement(lsB, 3, 3, 0);
	putLLElement(lsB, 1, 5, 0);
	lsC = addPoly(lsA, lsB);
	displayLinkedList(lsC);
	deleteLinkedList(lsB);
	deleteLinkedList(lsC);
}

void lsB_NULL()
{
	/*
	lsA == 3x^{3} + 8x^{2}
	lsB == NULL
	*/
	LinkedList *lsA = NULL;
	LinkedList *lsB = NULL;
	LinkedList *lsC;

	lsA = createLinkedList();
	putLLElement(lsA, 3, 3, 0);
	putLLElement(lsA, 8, 2, 1);
	lsC = addPoly(lsA, lsB);
	displayLinkedList(lsC);
	deleteLinkedList(lsA);
	deleteLinkedList(lsC);
}

/*
같은 degree일 때 coef를 연산하는지 확인
*/
void poly_test1()
{
	/*
	lsA == 3x^{3} + 8x^{2}
	lsB == 5x^{3} + 13x^{2}
	*/
	LinkedList *lsA = NULL;
	LinkedList *lsB = NULL;
	LinkedList *lsC;

	lsA = createLinkedList();
	putLLElement(lsA, 3, 3, 0);
	putLLElement(lsA, 8, 2, 1);
	lsB = createLinkedList();
	putLLElement(lsB, 5, 3, 0);
	putLLElement(lsB, 13, 2, 1);
	lsC = addPoly(lsA, lsB);
	displayLinkedList(lsC);
	deleteLinkedList(lsA);
	deleteLinkedList(lsB);
	deleteLinkedList(lsC);
}

/*
서로다른 degree일때 순서대로 저장되는지
*/
void poly_test2()
{
	/*
	lsA == 3x^{3}+ 8x^{2}
	lsB == 5x + 13
	*/
	LinkedList *lsA = NULL;
	LinkedList *lsB = NULL;
	LinkedList *lsC;

	lsA = createLinkedList();
	putLLElement(lsA, 3, 3, 0);
	putLLElement(lsA, 8, 2, 1);
	lsB = createLinkedList();
	putLLElement(lsB, 5, 1, 0);
	putLLElement(lsB, 13, 0, 1);
	lsC = addPoly(lsA, lsB);
	printf("%p\n", lsC->headerNode.pLink);
	displayLinkedList(lsC);
	deleteLinkedList(lsA);
	deleteLinkedList(lsB);
	deleteLinkedList(lsC);
}

/*
lsA가 먼저 식이 끝난 경우
*/
void poly_test3()
{
	/*
	lsA == 3x
	lsB == 5x + 13
	*/
	LinkedList *lsA = NULL;
	LinkedList *lsB = NULL;
	LinkedList *lsC;

	lsA = createLinkedList();
	putLLElement(lsA, 3, 1, 0);
	lsB = createLinkedList();
	putLLElement(lsB, 5, 1, 0);
	putLLElement(lsB, 13, 0, 1);
	lsC = addPoly(lsA, lsB);
	displayLinkedList(lsC);
	deleteLinkedList(lsA);
	deleteLinkedList(lsB);
	deleteLinkedList(lsC);
}

/*
lsB가 먼저 식이 끝난 경우
*/
void poly_test4()
{
	LinkedList *lsA = NULL;
	LinkedList *lsB = NULL;
	LinkedList *lsC;
	/*
	lsA == 3x^{4} + 3x^{3} + 3x^{2} + 3x^{1}
	lsB == 5x^{8} + 13x^{5}
	*/
	lsA = createLinkedList();
	putLLElement(lsA, 3, 1, 0);
	putLLElement(lsA, 3, 2, 0);
	putLLElement(lsA, 3, 3, 0);
	putLLElement(lsA, 3, 4, 0);
	lsB = createLinkedList();
	//ele.coef = 5;
	//ele.degree = 8;
	//addLLElement(lsB, 0, ele);
	putLLElement(lsB, 5, 8, 0);
	putLLElement(lsB, 13, 5, 1);
	lsC = addPoly(lsA, lsB);
	displayLinkedList(lsC);
	deleteLinkedList(lsA);
	deleteLinkedList(lsB);
	deleteLinkedList(lsC);
}

int main() {
	//lsAB_NULL();
	//lsA_NULL();
	//lsB_NULL();
	//poly_test1();
	//poly_test2();
	//poly_test3();
	poly_test4();
	printf("-------------------------------------\n");
	system("leaks a.out");
}