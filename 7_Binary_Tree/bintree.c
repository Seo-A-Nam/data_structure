#include "bintree.h"

BinTree* makeBinTree(BinTreeNode rootNode)
{
    BinTree *bt;

    bt = (BinTree *)malloc(sizeof(BinTree));
    if (bt)
    {
        bt->pRootNode = (BinTreeNode *)malloc(sizeof(BinTreeNode));
        if (bt->pRootNode)
        {
          *(bt->pRootNode) = rootNode;
          bt->pRootNode->pLeftChild = 0;
          bt->pRootNode->pRightChild = 0;
        }
        else
        {
            printf("makeBinTree: Malloc NODE Failed\n");
            return (NULL);
        }
    }
    else
    {
        printf("makeBinTree: Malloc TREE Failed\n");
        return (NULL);
    }
    return (bt);
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
    if (pBinTree)
    {
        if (pBinTree->pRootNode)
        {
            return (pBinTree->pRootNode);
        }
        else
        {
            printf("getRootNode: pRootNode is NUll\n");
            return (NULL);
        }
    }
    else
    {
        printf("getRootNode: pBinTree is NUll\n");
        return (NULL);
    }
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
    BinTreeNode *tmpbtn;

    tmpbtn = 0;
    if (pParentNode)
    { 
        if (!(pParentNode->pLeftChild))
        {
            tmpbtn = (BinTreeNode *)malloc(sizeof(BinTreeNode));
            if (tmpbtn)
            {
                *tmpbtn = element;
                tmpbtn->pLeftChild = 0;
                tmpbtn->pRightChild = 0;
                pParentNode->pLeftChild = tmpbtn;
                return (tmpbtn);
            }
            else
            {
                printf("insert left: Malloc Error\n");
                return (NULL);
            }
        }
        else
        {
            printf("insert left: Already Exist\n");
            return (NULL);
        }
    }
    else
    {
        printf("insert left: pParentNode is NULL\n");
        return (NULL);
    }
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
    BinTreeNode *tmpbtn;

    tmpbtn = 0;
    if (pParentNode)
    { 
        if (!(pParentNode->pRightChild))
        {
            tmpbtn = (BinTreeNode *)malloc(sizeof(BinTreeNode));
            if (tmpbtn)
            {
                *tmpbtn = element;
                tmpbtn->pRightChild = 0;
                tmpbtn->pRightChild = 0;
                pParentNode->pRightChild = tmpbtn;
                return (tmpbtn);
            }
            else
            {
                printf("insert right: Malloc Error\n");
                return (NULL);
            }
        }
        else
        {
            printf("insert right: Already Exist\n");
            return (NULL);
        }
    }
    else
    {
        printf("insert right: pParentNode is NULL\n");
        return (NULL);
    }
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
    if (pNode)
    {
        if (pNode->pLeftChild)
        {
            return (pNode->pLeftChild);
        }
        else
        {
            printf("getLeftChildNodeBt : pNode->pLeftChild is NULL\n");
            return (NULL);
        }
    }
    else
    {
        printf("getLeftChildNodeBt : pNode is NULL\n");
        return (NULL);
    }
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
    if (pNode)
    {
        if (pNode->pRightChild)
        {
            return (pNode->pRightChild);
        }
        else
        {
            printf("getRightChildNodeBT : pNode->pRightChild is NULL\n");
            return (NULL);
        }
    }
    else
    {
        printf("getRightChildNodeBT : pNode is NULL\n");
        return (NULL);
    }
}
void deleteBinTree(BinTree* pBinTree)
{
    if (pBinTree)
    {
        deleteBinTreeNode(pBinTree->pRootNode);
        free(pBinTree);
        pBinTree = 0;
    }
}

void deleteBinTreeNode(BinTreeNode* pNode)
{
    if (pNode)
    {
        deleteBinTreeNode(pNode->pLeftChild);
        deleteBinTreeNode(pNode->pRightChild);
        free(pNode);
        pNode = 0;
    }
}

/*
========================================================================

                                PREORDER

========================================================================
*/

void preorderTraversalBinTree(BinTree *binTree)
{
    if (binTree)
    {
        preorderTraversalBinTreeNode(binTree->pRootNode);
        printf("\n");
    }
}

void preorderTraversalBinTreeNode(BinTreeNode *binTreeNode)
{
    if (binTreeNode)
    {
        printf("binTreeNode->data: %c\n", binTreeNode->data);
        preorderTraversalBinTreeNode(binTreeNode->pLeftChild);
        preorderTraversalBinTreeNode(binTreeNode->pRightChild);
    }
    
}

/*
========================================================================

                                INORDER

========================================================================
*/

void inorderTraversalBinTree(BinTree *binTree)
{
    if (binTree)
    {
        inorderTraversalBinTreeNode(binTree->pRootNode);
        printf("\n");
    }
}

void inorderTraversalBinTreeNode(BinTreeNode *binTreeNode)
{
    if (binTreeNode)
    {
        inorderTraversalBinTreeNode(binTreeNode->pLeftChild);
        printf("binTreeNode->data: %c\n", binTreeNode->data);
        inorderTraversalBinTreeNode(binTreeNode->pRightChild);

    }
}

/*
========================================================================

                                POSTORDER

========================================================================
*/

void postorderTraversalBinTree(BinTree *binTree)
{
    if (binTree)
    {
        postorderTraversalBinTreeNode(binTree->pRootNode);
        printf("\n");
    }
}

void postorderTraversalBinTreeNode(BinTreeNode *binTreeNode)
{
    if (binTreeNode)
    {
        postorderTraversalBinTreeNode(binTreeNode->pLeftChild);
        postorderTraversalBinTreeNode(binTreeNode->pRightChild);
        printf("binTreeNode->data: %c\n", binTreeNode->data);
    }
}

/*
========================================================================

                                LEVEL

========================================================================
*/
/*
void levelOrderTraversalBinTree(BinTree *binTree)
{
    LinkedQueue *pQueue;
    QueueNode tmpQueueNode;

    pQueue = 0;
    if (binTree)
    {
        pQueue = createLinkedQueue();
        tmpQueueNode.node = binTree->pRootNode; 
        tmpQueueNode.pLink = 0;
        enqueueLinkedQueue(pQueue, tmpQueueNode);
        while (isLinkedQueueEmpty(pQueue) != 1)
        {
            QueueNode *temp;
            QueueNode tempQueueNode;

            temp = peekLinkedQueue(pQueue);
            if (temp->node->pLeftChild != NULL)
            {
                tempQueueNode.node = temp->node->pLeftChild;
                tempQueueNode.pLink = 0;
                enqueueLinkedQueue(pQueue, tempQueueNode);
            }
            if (temp->node->pRightChild != NULL)
            {
                tempQueueNode.node = temp->node->pRightChild;
                tempQueueNode.pLink = 0;
                enqueueLinkedQueue(pQueue, tempQueueNode);
            }
            temp = temp->pLink;
            dequeLinkedQueue(pQueue);
        }
    }
    else
    {
        printf("binTree is NULL");
    }
}*/