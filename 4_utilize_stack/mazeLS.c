#include "mazeLS.h"

int		direction[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
  // by adding each values, You can move yours to that according position. in order of cardinal point bellow.
char	cardinal_point[4] = {'S', 'W', 'N', 'E'}; 
  // write the direction you stepped in, into a MapPosition struct.

LinkedStack*  createLinkedStack()
{
  	LinkedStack* pStack = NULL;
    pStack = (LinkedStack*)malloc(sizeof(LinkedStack));
    if (pStack == NULL)
    {
        printf("[error] malloc failure : pStack\n");
        return (NULL);
    }
    memset(pStack, 0, sizeof(LinkedStack));
    return (pStack);
}

int           isLinkedStackEmpty(LinkedStack* pStack)
{
    if (pStack == NULL)
    {
        printf("[error] Null parameter : pStack\n");
        return (FALSE);
    }
    if (pStack->currentElementCount == 0)
    {
        return (TRUE);
    }
    return (FALSE);
}

int             pushLSMapPosition(LinkedStack* pStack, MapPosition data)
{
  	MapPosition *ps = NULL;
  	if (pStack == NULL)
    {
      	printf("[error] Null parameter : pStack\n");
      	return (FALSE);
    }
  	ps = (MapPosition*)malloc(sizeof(MapPosition));
  	if (ps == NULL)
    {
      	printf("[error] malloc failure : ps\n");
        return (FALSE);
    }
  	*ps = data;
  	ps->pLink = pStack->pTopElement;
  	pStack->pTopElement = ps;
  	pStack->currentElementCount++;
    return (TRUE);
}

MapPosition*  popLSMapPosition(LinkedStack* pStack)
{
  	MapPosition *delNode = NULL;
		if (pStack == NULL)
    {
      	printf("[error] Null parameter : pStack\n");
      	return (FALSE);
    }
  	if (isLinkedStackEmpty(pStack) == TRUE)
    {
      	printf("[error] Stack Underflow\n");
      	return (FALSE);
    }
  	delNode = pStack->pTopElement;
  	pStack->pTopElement = delNode->pLink;
  	delNode->pLink = NULL; // anyway we'll return this node. so we put pLink as NULL.
  	pStack->currentElementCount--;
  	return (delNode);
}

void        deleteLinkedStack(LinkedStack* pStack)
{
  	if (pStack == NULL)
    {
      	printf("[error] Null parameter : pStack\n");
    }
  	int index = pStack->currentElementCount;
  	for (int i = 0; i < index; i++)
    {
      	MapPosition *pNode = popLSMapPosition(pStack);
      	free(pNode);
    } // pop each node and free the memory of that everytime.
  	free(pStack);
}

static void printLS_rev(MapPosition *head)
{
  if (head == 0)
    return ;
  printLS_rev(head->pLink);
  printf("(%d, %d) %c\n", head->dx ,head->dy, head->direction);
} // print the history of step (= path) in reversed order. so it can be started from the start point.

void	      showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH])
{
  	MapPosition	*p; 

	  printf("This is a path of the Maze\n\n");
  	p = pStack->pTopElement;
    printf("\nSTART ->\n\n");
    printLS_rev(p);
    printf("\nEND <-\n\n");
    printf("\n\n>> The way which has 2 printed, is the path to go through the maze.\n\n");
    for (int i = 0; i < HEIGHT; i++)
    {
      for (int j = 0; j < WIDTH; j++)
      {
        printf("%d ", mazeArray[i][j]);
      }
      printf("\n");
    }
    printf("\n\n** 1 is the wall which you cannot go through, while 0 is the available way.\n");
}

void	      findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack)
{
  if (pStack->pTopElement->dx == endPos.dx && pStack->pTopElement->dy == endPos.dy)
  {
    showPath(pStack, mazeArray);
    return ;
  } // if you succeed to find a path, then print that path and return.
	for(int i = 0; i < 4; i++)
  {
    int px = pStack->pTopElement->dx + direction[i][1];
    int py = pStack->pTopElement->dy + direction[i][0];
    //add direction[i][0] to py. and direction[i][1] to px.
    if (HEIGHT > py && py >= 0 && WIDTH > px && px >= 0)
    { // check if the value is in the range of the given map.
      if (mazeArray[py][px] == 0)
      { // check if the next position is on available path.
          MapPosition current; // the next position that you'll step in.
          memset(&current, 0, sizeof(MapPosition));
          current.dx = px;
          current.dy = py;
          current.direction = 0;
          pStack->pTopElement->direction = cardinal_point[i]; // these two code lines enable us to write the first direction we went from the start point.
          pushLSMapPosition(pStack, current); // write your next position on the stack, before stepping into it.
          mazeArray[py][px] = 2; // write your next position on the map, before stepping into it.
          findPath(mazeArray, startPos, endPos, pStack); // call the fuction recursively (step into the next position)
          mazeArray[py][px] = 0; // erase that bad path from the map.
          MapPosition *delNode = NULL;
          delNode = popLSMapPosition(pStack); // erase that bad path from the stack.
          free(delNode);
      }
    }
  }
}  // recursive function that finds a path of the maze, using DFS algorithm

void	      printMaze(int mazeArray[HEIGHT][WIDTH])
{
  printf("This is a Map of the Maze\n\n");
	for (int i = 0; i < HEIGHT; i++)
  {
    for (int j = 0; j < WIDTH; j++)
    {
      printf("%d ", mazeArray[i][j]);
    }
    printf("\n");
  }
}