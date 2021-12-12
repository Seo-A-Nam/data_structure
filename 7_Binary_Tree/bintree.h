#ifndef _BIN_TREE_
# define _BIN_TREE_
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

/*
========================================================================

                            	BIN_TREE

========================================================================
*/

typedef struct BinTreeNodeType
{
	char data;
	int visited;
	struct BinTreeNodeType* pLeftChild;
	struct BinTreeNodeType* pRightChild;
} BinTreeNode;

typedef struct BinTreeType
{
	struct BinTreeNodeType* pRootNode;
} BinTree;

BinTree* makeBinTree(BinTreeNode rootNode);
BinTreeNode* getRootNodeBT(BinTree* pBinTree);
BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element);
BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element);
BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode);
BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode);
void deleteBinTree(BinTree* pBinTree);
void deleteBinTreeNode(BinTreeNode* pNode);


/*
========================================================================

                            	LINKEDQUEUE

========================================================================
*/

typedef struct QueueNodeType
{
	BinTreeNode             *node;
	struct QueueNodeType*   pLink;
} QueueNode;

typedef struct LinkedQueueType
{
	int                     currentElementCount;
	QueueNode*              tail;
} LinkedQueue;

LinkedQueue *createLinkedQueue(void);
int enqueueLinkedQueue(LinkedQueue *pQueue, QueueNode element);
QueueNode *dequeLinkedQueue(LinkedQueue *pQueue);
QueueNode *peekLinkedQueue(LinkedQueue *pQueue);
void deleteLinkedQueue(LinkedQueue *pQueue);
int isLinkedQueueEmpty(LinkedQueue *Queue);
void displayLinkedQueue(LinkedQueue *pQueue);

/*
========================================================================

                            	TRAVERSAL

========================================================================
*/

void preorderTraversalBinTree(BinTree *binTree);
void preorderTraversalBinTreeNode(BinTreeNode *binTreeNode);
void inorderTraversalBinTree(BinTree *binTree);
void inorderTraversalBinTreeNode(BinTreeNode *binTreeNode);
void postorderTraversalBinTree(BinTree *binTree);
void postorderTraversalBinTreeNode(BinTreeNode *binTreeNode);
//void levelOrderTraversalBinTree(BinTree *binTree);

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif