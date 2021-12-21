#include "../includes/bintree.h"

/*
========================================================================

                                PREORDER

========================================================================
*/
//전위 순회
void preorderTraversalBinTree(BinTree *binTree)
{
    if (binTree != NULL)
    {
        preorderTraversalBinTreeNode(binTree->pRootNode);
        printf("\n");
    }
}

void preorderTraversalBinTreeNode(BinTreeNode *binTreeNode)
{
    if (binTreeNode != NULL)
    {
        printf("%c", binTreeNode->data);
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
    if (binTree != NULL)
    {
        inorderTraversalBinTreeNode(binTree->pRootNode);
        printf("\n");
    }
}

void inorderTraversalBinTreeNode(BinTreeNode *binTreeNode)
{
    if (binTreeNode != NULL)
    {
        inorderTraversalBinTreeNode(binTreeNode->pLeftChild);
        printf("%c", binTreeNode->data);
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
    if (binTree != NULL)
    {
        postorderTraversalBinTreeNode(binTree->pRootNode);
        printf("\n");
    }
}

void postorderTraversalBinTreeNode(BinTreeNode *binTreeNode)
{
    if (binTreeNode != NULL)
    {
        postorderTraversalBinTreeNode(binTreeNode->pLeftChild);
        postorderTraversalBinTreeNode(binTreeNode->pRightChild);
        printf("%c", binTreeNode->data);
    }
}

/*
========================================================================

                                LEVEL

========================================================================
*/

void levelOrderTraversalBinTree(BinTree *binTree)
{
    LinkedDeque *pQueue;//이진 노드 저장할 큐(덱)
    DequeNode tmpQueueNode;//루트 노드를 저장할 큐노드. 큐노드 안에는 이진노드 들어감.
    // element에 이진 노드 포인터 있음.

    pQueue = 0;
    if (binTree != NULL)
    {
        pQueue = createLinkedDeque();
        tmpQueueNode.data = binTree->pRootNode; 
        tmpQueueNode.pLLink = 0;
        tmpQueueNode.pRLink = 0;
        insertRearLD(pQueue, tmpQueueNode);
        while (isLinkedDequeEmpty(pQueue) == FALSE)
        {
            DequeNode *temp;//큐의 front 노드 주소가 들어갈 포인터
            DequeNode tempQueueNode;//temp에 저장된 이진 노드의 왼쪽 오른쪽 자식의 값이 들어갈 변수

            temp = peekFrontLD(pQueue);
            printf("%c", temp->data->data);
            if (temp->data->pLeftChild != NULL)
            {
                tempQueueNode.data = temp->data->pLeftChild;
                tempQueueNode.pRLink = 0;
                tempQueueNode.pLLink = 0;
                insertRearLD(pQueue, tempQueueNode);
            }
            if (temp->data->pRightChild != NULL)
            {
                tempQueueNode.data= temp->data->pRightChild;
                tempQueueNode.pRLink = 0;
                tempQueueNode.pLLink = 0;
                insertRearLD(pQueue, tempQueueNode);
            }
            free(deleteFrontLD(pQueue));//
        }
    }
    else
    {
        printf("binTree is NULL");
    }
    deleteLinkedDeque(pQueue);//없으면 오류남
    printf("\n");
}