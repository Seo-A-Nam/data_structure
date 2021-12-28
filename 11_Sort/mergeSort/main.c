#include "merge_sort.h"
/*
* 참고 : 헤더노드는 무조건 값이 0 (값을 사용하지 않는다). 데이터 노드는 헤더노드의 다음부터 시작한다.
*/

LinkedList *lst_cpy(LinkedList *pList)
{
    LinkedList  *ret = createLinkedList();
    ListNode    *node = pList->headerNode.pLink;
    int count = pList->currentElementCount;
    
    for (int i = 0; i < count; i++)
    {
        addLLElement(ret, i, *node);
        node = node->pLink;
    }
    return (ret);
}

void    displayLl(LinkedList *pList)
{
    ListNode *ptr;
    
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
    ptr = pList->headerNode.pLink;
    printf("\n");
    for (int i = 0; i < pList->currentElementCount; i++)
    {
        printf("%d ", ptr->data);
        ptr = ptr->pLink;
    }
    printf("\n\n");
}

void    test()
{
	LinkedList	*pList;
	ListNode	node;
	int			input = 0;
    int         err_flag = 1;
	int			pos = 0;

	pList = createLinkedList();
    while (1)
	{
        printf("\nLIST STATUS ============================================\n");
        displayLl(pList);
        printf("========================================================\n");
		printf("List option :   1 (Add)   2 (Remove)   3 (Merge sort)\n    4 (Exit)\n");
		scanf(" %d", &input);
        if (input == 4)
        {
            printf("----------------- TERMINATE THE PROGRAM ----------------\n");
            break;
        }
		switch (input)
		{
			case 1:
				printf("Type the number to insert in a Linkedlist : ");
				scanf(" %d", &node.data);
				err_flag = addLLElement(pList, pList->currentElementCount, node);
				break ;
			case 2:
				printf("Type the position to delete : ");
				scanf(" %d", &pos);
				err_flag = removeLLElement(pList, pos);
				break ;
			case 3:
				printf("====================  MERGED LIST  =====================\n");
				LinkedList *mergedList = mergeSort(lst_cpy(pList));
				 // mergeSort 매개인자로 들어간 리스트는 안에서 free()되기 때문에 pList를 카피해서 넣어줌.
				displayLl(mergedList);
				deleteLinkedList(mergedList);
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
    deleteLinkedList(pList);
    return ;
}

int main(void)
{
    test();
    system("leaks a.out");
    return (0);
}
