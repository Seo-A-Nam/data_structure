#include "arraylist.h"

void func() {
    int i;

    i = 0;
	ArrayList *arr;
    printf("Create Arraylist : ");
    arr = createArrayList(1);
	//free(arr);
	arr->pElement[0].data = 1;
	arr->pElement[1].data = 2;
	arr->pElement[2].data = 3;
	arr->pElement[3].data = 4;
	arr->pElement[4].data = 5;
	while (i < 5)
	{
		printf("[%d] : %d\n", i, arr->pElement[i].data);
		i++;
	}
	deleteArrayList(arr);
	printf("\nDelete Arraylist : ");
	i = 0;
	while (i < 5)
	{
		printf("[%d] : %d\n", i, arr->pElement[i].data);
		i++;
	}
	//printf("%d", arr->pElement[11].data);
	//printf("%lu\n", sizeof(arr->pElement));
}

void add_test()
{
	ArrayList *arr;
	ArrayListNode ele;
	int	i;

	i = 0;
	ele.data = 10;
	arr = createArrayList(5);
	arr->pElement[0].data = 1;
	arr->pElement[1].data = 2;
	arr->pElement[2].data = 3;
	arr->pElement[3].data = 4;
	arr->pElement[4].data = 5;
	while (i < 5)
	{
		printf("[%d] : %d\n", i, arr->pElement[i].data);
		i++;
	}
	printf("\n\n");
	
	printf("Add Element: \n");
	addALElement(arr, 2, ele);
	i = 0;
	while (i < 5)
	{
		printf("[%d] : %d\n", i, arr->pElement[i].data);
		i++;
	}
	
}

void add_test2() // 비어있는 array에 element 추가
{
	ArrayList *arr;
	ArrayListNode ele;
	int	i;

	i = 0;
	ele.data = 10;
	arr = createArrayList(5);
	// arr->pElement[0].data = 1;
	// arr->pElement[1].data = 2;
	// arr->pElement[2].data = 3;
	// arr->pElement[3].data = 4;
	// arr->pElement[4].data = 5;
	// while (i < 5)
	// {
	// 	printf("[%d] : %d\n", i, arr->pElement[i].data);
	// 	i++;
	// }
	printf("\n\n");

	printf("Add Element: \n");
	addALElement(arr, 0, ele);
	i = 0;
	while (i < 5)
	{
		printf("[%d] : %d\n", i, arr->pElement[i].data);
		i++;
	}
	
}

void add_test3() // 1 x x 3 x x 일 때, 1번 인덱스에 값을 넣었을 때 값이 밀리는 지 
{
	ArrayList *arr;
	ArrayListNode ele;
	int	i;

	i = 0;
	ele.data = 10;
	arr = createArrayList(5);
	arr->pElement[0].data = 1;
	// arr->pElement[1].data = 2;
	arr->pElement[3].data = 3;
	// arr->pElement[3].data = 4;
	// arr->pElement[4].data = 5;
	 while (i < 5)
	 {
	 	printf("[%d] : %d\n", i, arr->pElement[i].data);
	 	i++;
	 }
	printf("\n\n");

	printf("Add Element: \n");
	addALElement(arr, 1, ele);
	i = 0;
	while (i < 5)
	{
		printf("[%d] : %d\n", i, arr->pElement[i].data);
		i++;
	}
	
}

void add_test4() // 0번째 인덱스에 값이 있는 상황에서, 0번째 인덱스에 값을 넣었을 때, 기존의 값이 뒤로 밀려나는 지
{
	ArrayList *arr;
	ArrayListNode ele;
	int	i;

	i = 0;
	ele.data = 10;
	arr = createArrayList(5);
	arr->pElement[0].data = 1;
	// arr->pElement[1].data = 2;
	//arr->pElement[3].data = 3;
	// arr->pElement[3].data = 4;
	// arr->pElement[4].data = 5;
	 while (i < 5)
	 {
	 	printf("[%d] : %d\n", i, arr->pElement[i].data);
	 	i++;
	 }
	printf("\n\n");

	printf("Add Element: \n");
	addALElement(arr, 0, ele);
	i = 0;
	while (i < 5)
	{
		printf("[%d] : %d\n", i, arr->pElement[i].data);
		i++;
	}
	
}

void add_test5() // 배열이 꽉 차있는 상태에서 값을 넣었을 경우, 배열이 확장되면서 값이 전체가 잘 나오는 지
{
	ArrayList *arr;
	ArrayListNode ele;
	int	i;

	i = 0;
	ele.data = 10;
	arr = createArrayList(5);
	arr->pElement[0].data = 1;
	arr->pElement[1].data = 2;
	arr->pElement[3].data = 3;
	arr->pElement[3].data = 4;
	arr->pElement[4].data = 5;
	 while (i < 5)
	 {
	 	printf("[%d] : %d\n", i, arr->pElement[i].data);
	 	i++;
	 }
	printf("\n\n");

	printf("Add Element: \n");
	addALElement(arr, 1, ele);
	i = 0;
	while (i < 6)
	{
		printf("[%d] : %d\n", i, arr->pElement[i].data);
		i++;
	}
	printf("Max Element number : %d\n", arr->maxElementCount);
}

void remove_test1()
{
	ArrayList *arr;
	int	i;
	ArrayListNode ele;

	i = 0;
	arr = createArrayList(5);
	for (int i = 0; i < 5; i++) {
		ele.data = i + 1;
		addALElement(arr, i, ele);
	}
	 while (i < 5)
	 {
	 	printf("[%d] : %d\n", i, arr->pElement[i].data);
	 	i++;
	 }
	printf("Current Element number : %d\n", arr->currentElementCount);
	printf("\n\n");

	printf("Remove Element: \n");
	removeALElement(arr, 3);
	i = 0;
	while (i < 5)
	{
		printf("[%d] : %d\n", i, arr->pElement[i].data);
		i++;
	}
	//printf("Max Element number : %d\n", arr->maxElementCount);
	printf("Current Element number : %d\n", arr->currentElementCount);
	
}

int malloc_test() {
	char *a;

	a = (char *)malloc(sizeof(char) * 5);
	if (!a)
		return (0);
	a[0] = 'a';
	a[1] = 'b';
	a[2] = 'c';
	a[3] = 'd';
	a[4] = 'e';
	a[5] = 'f';
	a[6] = 'g';
	for (int i = 0; a[i]; i++) {
		printf("%c\n", a[i]);
	}
	return (0);
}

void getALElement_test() {
	ArrayList* pList; 
	int position;
	ArrayListNode ele;
	ArrayListNode *get_ele;

	pList = createArrayList(5);
	if (!pList)
		return ;
	get_ele = (ArrayListNode *)malloc(sizeof(ArrayListNode));
	if (!get_ele)
		return ;
	for (int i = 0; i < 5; i++) {
		ele.data = i + 1;
		addALElement(pList, i, ele);
	}
	for (int i = 0; i < 5; i++) {
		get_ele = getALElement(pList, i);
		printf("%d\n", get_ele->data);
	}
	//ArrayListNode* getALElement(ArrayList* pList, int position);

}

void	clearArray_test()
{
	ArrayList* arr; 

	arr = createArrayList(5);
	arr->pElement[0].data = 1;
	arr->pElement[1].data = 2;
	arr->pElement[2].data = 3;
	arr->pElement[3].data = 4;
	arr->pElement[4].data = 5;
	arr->currentElementCount = 5;
	displayArrayList(arr);
	printf("\n\n");
	clearArrayList(arr);
	displayArrayList(arr);
}

void getArrayListLength_test()
{
	ArrayList* arr; 
	ArrayListNode ele;
	int position;


	arr = createArrayList(5);
	if (!arr)
		return ;
	for (int i = 0; i < 5; i++) {
		ele.data = i + 1;
		addALElement(arr, i, ele);
	}
	printf("%d\n", getArrayListLength(arr));
}


int		main(void)
{
	//getALElement_test();
	//clearArray_test();	
	getArrayListLength_test();
	return (0);
}
/*
int     main(void)
{

	.
    //while (TRUE)
	//{
        //printf("%d : %d\n", i, arr->pElement[i].data);
		//free((void *)(arr));
       // i++;
	//}
	//func();
	//malloc_test();
	// remove_test1();
	getArrayListLength_test();
	//system("leaks a.out");
    //displayArrayList(arr);

    typedef struct ArrayListType
{
	int maxElementCount;		// the number of maximum element
	int currentElementCount;	// the number of current element existing
	ArrayListNode *pElement;	// the 1-dimensional array to store element in
} ArrayList; **/
//    return (0);

