#ifndef _MAZE_LS_
#define _MAZE_LS_

/*
* include
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEIGHT      8 // height of a maze
#define WIDTH       8 // width of a maze

typedef	struct	StackNodeType
{
    int	dx;
    int dy;
    char direction;
    struct StackNodeType *pLink;
}	MapPosition;

typedef struct LinkedStackType
{
	int currentElementCount;
	MapPosition* pTopElement;
} LinkedStack;
/* 
* pTopElement(header node) is the first element node of the stack. 
* (it not only works as a pointer but also works as a element node itself. 
*  so when we check data, we have to do it from header node.)
*/


/*
* STACK
*/
LinkedStack*    createLinkedStack();  // create a Stack with LinkedList
int		        pushLSMapPosition(LinkedStack* pStack, MapPosition data);  // push the history of your step (= path) into a stack.
MapPosition*    popLSMapPosition(LinkedStack* pStack);  // pop the history of your step (= path) from a stack.
void            deleteLinkedStack(LinkedStack* pStack);
int             isLinkedStackEmpty(LinkedStack* pStack); // check if the stack is empty

/*
 * MAZE 
 */
void	        showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH]);
 // print the path(= history of step to the end point) sequentially. and Print a map which has 2 printed on the path.
void	        findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack);
 // recursive function that finds a path of the maze, using DFS algorithm
void	        printMaze(int mazeArray[HEIGHT][WIDTH]);  // print a map of the maze


#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0


#endif
