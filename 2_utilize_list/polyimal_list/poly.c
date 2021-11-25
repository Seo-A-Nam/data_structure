#include "polynomial_list.h"

static int	handle_remaining_term(LinkedList *poly, ListNode *node, int index)
{
	int		stat;

	while (node)
	{
		stat = addLLElement(poly, index, *node);
		if (stat == FALSE)
		{
			deleteLinkedList(poly);
			return (FALSE);
		}
		index++;
		node = node->pLink;
	}
	return (TRUE);
} 
// AND 연산으로 앞서 연산을 했기 때문에, 한포인터가 끝나고 나머지 포인터가 남아있는 경우, 
// 나머지 남아있는 항들을 링크드리스트에 넣어준다.

LinkedList	*addPoly(LinkedList *lsA, LinkedList *lsB)
{
	LinkedList	*poly;
	ListNode	*IterA;
	ListNode	*IterB;
	ListNode	calc;
	int			stat;
	int			i;
	
	i = 0;
	if (lsA == NULL && lsB == NULL)
		return (NULL); // parameter exception handling
	else if (lsA == NULL)
		return (copyLinkedList(lsB)); // lsA는 값이 없으나, lsB는 값이 있을 때. lsB랑 값은 같은데 주소는 다른 새 링크드리스트 생성 (1대 1 복사)
	else if (lsB == NULL)
		return (copyLinkedList(lsA)); // lsB는 값이 없으나, lsA는 값이 있을 때. lsA랑 값은 같은데 주소는 다른 새 링크드리스트 생성 (1대 1 복사)
	poly = createLinkedList(); // poly는 다항식 계산
	if (poly == NULL)
		return (NULL);
	IterA = lsA->headerNode.pLink; // lsA를 가르키는 포인터
	IterB = lsB->headerNode.pLink; // lsB를 가르키는 포인터
	while(IterA && IterB) // lsA와 lsB의 값을 가르키는 헤더노드가 존재할 경우에
	{ // 다항식은 같은 차수끼리 계산
		if (IterA->degree > IterB->degree)
		{
			stat = addLLElement(poly, i, *IterA);
			if (stat == FALSE)
			{
				deleteLinkedList(poly);
				return (NULL);
			}
			IterA = IterA->pLink;
		}
		else if (IterA->degree < IterB->degree)
		{
			stat = addLLElement(poly, i, *IterB);
			if (stat == FALSE)
			{
				deleteLinkedList(poly);
				return (NULL);
			}
			IterB = IterB->pLink;
		}
		else // IterA->degree == IterB->degree 
		{
			// 다항식 차수가 같은 경우에만 같은 차수끼리 계산
			calc.coef = IterA->coef + IterB->coef;
			calc.degree = IterA->degree;
			stat = addLLElement(poly, i, calc); // addLLElement가 실패했는 지를 감지하기 위한 변수
			if (stat == FALSE)
			{ // addLLElement가 실패했을 경우의 예외처리
				deleteLinkedList(poly);
				return (NULL);
			}
			IterA = IterA->pLink;
			IterB = IterB->pLink; // Iter 포인터를 다음 차수로 한칸씩 옮긴다.
		}
		i++;
	}
	stat = handle_remaining_term(poly, IterA, i);
	if (stat == FALSE)
		return (NULL);
	// AND 연산으로 앞서 연산을 했기 때문에, 한포인터가 끝나고 나머지 포인터가 남아있는 경우,
	// 나머지 남아있는 항들을 링크드리스트에 넣어준다.
	stat = handle_remaining_term(poly, IterB, i);
	if (stat == FALSE)
		return (NULL);
	return (poly);
}