#include "mazeLS.h"

int     mazeArray[HEIGHT][WIDTH] = 
{
    {0, 0, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 0}
}; // a Map of the Maze

int main(void)
{
    LinkedStack *p = createLinkedStack();
    MapPosition startPos = {0, };
    MapPosition endPos = {7, 7, 0, 0};
    printf("\n=================================\n\n");
    printMaze(mazeArray);
    printf("\n=================================\n\n");
    if (mazeArray[startPos.dy][startPos.dx] != 0 || mazeArray[endPos.dy][endPos.dx] != 0)
    {
        printf("[error] Invalid value : Start position or End position\n");
        return (0);
    } // exception handling
    mazeArray[startPos.dy][startPos.dx] = 2; // write your first position as a path on the map, before stepping into it.
    pushLSMapPosition(p, startPos); // since p is null rn, let's first put startPos in the stack.
    findPath(mazeArray, startPos, endPos, p);
    mazeArray[startPos.dy][startPos.dx] = 0;
    printf("\n=================================\n\n");
    deleteLinkedStack(p);
    return (0);
}