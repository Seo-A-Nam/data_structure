#include "mazeLS.h"

int		direction[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
  // by adding each values, You can move yours to that according position. in order of cardinal point bellow.
char	cardinal_point[4] = {'S', 'W', 'N', 'E'}; 
  // write the direction you stepped in, into a MapPosition struct.

char  course_map[HEIGHT][WIDTH + 1] = {
  "00000000",
  "00000000",
  "00000000",
  "00000000",
  "00000000",
  "00000000",
  "00000000",
  "00000000"
}; // a map to check the course (including direction)

int     mazeArray[HEIGHT][WIDTH] = 
{
    {0, 0, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 0, 0, 1, 1, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 0}
}; // a Map of the Maze
// 1 is the wall which you cannot go through, while 0 is the available way.

int     path_count = 0;

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

    (void)mazeArray;
    printf("\n==================================================================\n\n");
    path_count++;
	  printf("This is a path of the Maze %d\n\n", path_count);
    printf("(S : South   N : North   W : West   E : East)\n");
  	p = pStack->pTopElement;
    printf("\nSTART ->\n\n");
    printLS_rev(p);
    printf("\nEND <-\n\n");
    for (int i = 0; i < HEIGHT; i++)
    {
      for (int j = 0; j < WIDTH; j++)
      {
        switch (course_map[i][j])
        {
          case 'S' :
            printf("▼ ");
            break;
          case 'W' :
            printf("◀ ");
            break;
          case 'N' :
            printf("▲ ");
            break;
          case 'E' :
            printf("▶ ");
            break;
          default :
            printf(". ");
            break;
        }
      }
      printf("\n");
    }
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
    int x = pStack->pTopElement->dx;
    int y = pStack->pTopElement->dy;
    int px = x + direction[i][1];
    int py = y + direction[i][0];
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
          course_map[y][x] = cardinal_point[i]; // write the direction of path on a course map
          mazeArray[py][px] = 2; // write your next position on the map, before stepping into it.
          findPath(mazeArray, startPos, endPos, pStack);
          // call the fuction recursively (step into the next position)
          course_map[y][x] = '0'; // erase the direction of path from a course map
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

int main(void)
{
    LinkedStack *p = createLinkedStack();
    MapPosition startPos = {0, };
    MapPosition endPos = {7, 7, 0, 0};
  
    printf("\n==================================================================\n\n");
    printMaze(mazeArray);
    printf("\n==================================================================\n\n");
    if (mazeArray[startPos.dy][startPos.dx] != 0 || mazeArray[endPos.dy][endPos.dx] != 0)
    {
        printf("[error] Invalid value : Start position or End position\n\n");
        return (0);
    } // exception handling
    mazeArray[startPos.dy][startPos.dx] = 2; // write your first position as a path on the map, before stepping into it.
    pushLSMapPosition(p, startPos); // since p is null rn, let's first put startPos in the stack.
    findPath(mazeArray, startPos, endPos, p);
    mazeArray[startPos.dy][startPos.dx] = 0;
    if (path_count == 0)
        printf("Cannot find any path of the maze\n");
    printf("\n==================================================================\n\n");
    deleteLinkedStack(p);
    return (0);
}