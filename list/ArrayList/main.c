#include "arraylist.h"

void func() {
    int i;

    i = 0;
	ArrayList *arr;
    printf("Create Arraylist : ");
    arr = createArrayList(3);
	free(arr);
	//printf("%d", arr->pElement[11].data);
	//printf("%lu\n", sizeof(arr->pElement));
}

int     main(void)
{

    //while (TRUE)
	//{
        //printf("%d : %d\n", i, arr->pElement[i].data);
		//free((void *)(arr));
       // i++;
	//}
	func();
	system("leaks a.out");
    //displayArrayList(arr);
        /**
    typedef struct ArrayListType
{
	int maxElementCount;		// the number of maximum element
	int currentElementCount;	// the number of current element existing
	ArrayListNode *pElement;	// the 1-dimensional array to store element in
} ArrayList; **/
    return (0);
}