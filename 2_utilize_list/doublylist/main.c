/*
This is a program to check if the functions that we have made are working right
*/

#include "doublylist.h"

static void printDoublyList(DoublyList *ls)
{
    DoublyListNode  *tmp;
    int             i;

    i = 0;
    printf("currentElementCount : %d\n", ls->currentElementCount);
    tmp = ls->headerNode.pRLink;
    while (1)
    {
        if (&ls->headerNode == tmp)
            break;
        printf("index [%d] : %d\n", i, tmp->data);
        tmp = tmp->pRLink;
        i++;
    }
} // Print all of the Nodes of the DoublyList, which is given as a parameter.

void    createDoublyList_test()
{
    DoublyList  *ls;

    printf("\nThis is the Test for Doublylist creation\n\n");
    ls = createDoublyList();
    printf("DoublyList : [%p]\ncurrentElementCount : %d\n", ls, ls->currentElementCount);
    printf("pRLink : [%p]\npLLink : [%p]\n\n\n", ls->headerNode.pRLink, ls->headerNode.pLLink);
}

static DoublyList *makeEXDoublyList(DoublyList *ls, int index)
{
    ls = createDoublyList();
    for (int i = 0; i < index; i++)
    {
        DoublyListNode  ele;
        ele.data = i;
        ele.pRLink = NULL;
        ele.pLLink = NULL;
        addDLElement(ls, i, ele);
    }
    return (ls);
} // Make examplary DoublyList, which has value range from 0 to (index - 1).

void    deleteDoublyList_test()
{
    DoublyList  *ls = NULL;

    printf("\nThis is the Test for DoublyList deletion\n\n");
    ls = makeEXDoublyList(ls, 5);
    printf("DoublyList : [%p]\n", ls);
    printDoublyList(ls);
    deleteDoublyList(ls);

    printf("\nAfter Delete, You should get 0 leaks as a result of system('leaks a.out')");
    printf("\n");
}

void    addDLElement_test()
{
    DoublyList      *ls = NULL;
    
    printf("\nThis is the Test for DoublyListNode insert in particular position\n\n");
	ls = makeEXDoublyList(ls, 5); // this function have addDLElement() inside.
    printDoublyList(ls);
}

void    removeDLElement_test()
{
    DoublyList      *ls = NULL;
    int             index;

    printf("\nThis is the Test for DoublyList Node elimination at particular position\n\n");
    ls = makeEXDoublyList(ls, 5);
    printDoublyList(ls);
    printf("\n\n");
    index = 0; // the position of the Node you want to remove.
    removeDLElement(ls, index);
    printf("After removing the Node in index (%d)\n", index);
    printDoublyList(ls);
    printf("\n");
}

void    clearDoublyList_test()
{
    DoublyList  *ls = NULL;

    printf("\nThis is the Test for DoublyList clearing\n\n");
    ls = makeEXDoublyList(ls, 5);
    printDoublyList(ls);
    printf("\n\n");
    clearDoublyList(ls);
    printf("After clearing the DoublyList\n");
    printDoublyList(ls);
    printf("\n");
}

void    getDoublyListLength_test()
{
    DoublyList  *ls = NULL;

    printf("\nThis is the Test for getting DoublyList length\n\n");
    ls = makeEXDoublyList(ls, 5);
    printDoublyList(ls);
    printf("\n\n");

    printf("length of the Doublylist\n");
    printf("%d\n", getDoublyListLength(ls));
    printf("\n");
}

void    getDLElement_test()
{
    DoublyList      *ls = NULL;
    DoublyListNode  *ele;
    int             index;

    printf("\nThis is the Test for getting DoublyList element(= Node)\n\n");
    ls = makeEXDoublyList(ls, 5);
    printDoublyList(ls);
    printf("\n\n");

    index = 2; // the position of the Node you want to get.
    printf("Element at index (%d)\n", index);
    ele = getDLElement(ls, index);
    printf("index [%d] : %d\n", index, ele->data);
    printf("\n");
}

void    displayDoublyList_test()
{
    DoublyList *ls = 0;

    printf("\nThis is the Test for displaying DoublyList\n\n");
    ls = makeEXDoublyList(ls, 5);
    displayDoublyList(ls);
}

void    reverseDoublyLinkedList_test()
{
    DoublyList *ls = NULL;
    //printf("\nThis is the Test for reversing DoublyList\n\n");
    ls = makeEXDoublyList(ls, 5);
    //printDoublyList(ls);
    //printf("\n\n");

    //printf("Reversed DoublyList\n");
    reverseDoublyLinkedList(ls);
    //printDoublyList(ls);
    //printf("\n");
}

int     main()
{
    // createDoublyList_test();
    // deleteDoublyList_test();
    // // system("leaks a.out"); // check if the delete function worked well (you should get '0 leaks' as a result).
    // addDLElement_test();
    // removeDLElement_test();
    // clearDoublyList_test();
    // getDoublyListLength_test();
    // getDLElement_test();
    // displayDoublyList_test();
     reverseDoublyLinkedList_test();
    return (0);
}