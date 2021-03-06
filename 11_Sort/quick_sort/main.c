#include "quick_sort.h"
/*
* 참고 : 헤더노드는 무조건 값이 0 (값을 사용하지 않는다). 데이터 노드는 헤더노드의 다음부터 시작한다.
*/

DoublyList *lst_cpy(DoublyList *pList)
{
    DoublyList  	*ret = createDoublyList();
    DoublyListNode	*node = pList->headerNode.pRLink;
    int count = pList->currentElementCount;
    
    for (int i = 0; i < count; i++)
    {
        addDLElement(ret, ret->currentElementCount, *node);
        node = node->pRLink;
    }
    return (ret);
}

void    displayDl(DoublyList *pList)
{
    DoublyListNode *ptr;
    
	if (pList == NULL)
	{
		printf("[error] Null parameter : pList\n");
		return ;
	}
	if (pList->currentElementCount == 0)
	{
		printf("\n               This is an Empty List\n\n");
		return ;
	}
    ptr = pList->headerNode.pRLink;
    printf("\n");
    for (int i = 0; i < pList->currentElementCount; i++)
    {
        printf("%d ", ptr->data);
        ptr = ptr->pRLink;
    }
    printf("\n\n");
}

void    test()
{
	DoublyList		*pList;
	DoublyListNode	node;
	int			input = 0;
    int         err_flag = 1;
	int			pos = 0;

	pList = createDoublyList();
    while (1)
	{
        printf("\nLIST STATUS ============================================\n");
        displayDl(pList);
        printf("========================================================\n");
		printf("List option :   1 (Add)   2 (Remove)\n   3 (Quick sort)    4 (Exit)\n");
		scanf(" %d", &input);
        if (input == 4)
        {
            printf("\n----------------- TERMINATE THE PROGRAM ----------------\n");
            break;
        }
		switch (input)
		{
			case 1:
				printf("Type the number to insert in a Linkedlist : ");
				scanf(" %d", &node.data);
				err_flag = addDLElement(pList, pList->currentElementCount, node);
				break ;
			case 2:
				printf("Type the position to delete : ");
				scanf(" %d", &pos);
				err_flag = removeDLElement(pList, pos);
				break ;
			case 3:
				printf("\n=================== QUICK SORT LIST ====================\n");
				DoublyList *sortedList = lst_cpy(pList);
				quick_sort(sortedList, sortedList->headerNode.pRLink, sortedList->headerNode.pLLink);
				// quicksort의 2번째 인자 pLeft : 일단 리스트의 첫번째 원소부터 시작, 3번째 인자 pivot : 일단 리스트의 맨 마지막 원소부터 시작. 
				displayDl(sortedList);
				deleteDoublyList(sortedList);
				break ;
			default:
				printf("[error] Wrong command number! please try again.\n");
				break;
		}
        if (err_flag == 0)
        {
            printf("[error] Terminate the program.\n");
            break;
        }
	}
    deleteDoublyList(pList);
    return ;
}

int main(void)
{
    test();
    system("leaks a.out");
    return (0);
}
