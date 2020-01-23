// 面试题8：二叉树的下一个结点
// 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
// 树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。

/*
1.如果一个节点有右子树，那么它的下一个节点就是它的右子树重的最左节点；
2.如果一个节点没有右子树且该节点是它父节点的左子节点，那么它的下一个节点就是它的父节点。
3.如果一个节点没有右子树且它还是它父节点的右子节点，那么我们就沿着指向父节点的指针一直向上遍历，直到找到这样一个节点满足：
“该节点是它父节点的左子节点”那么该节点的父节点就是我们要找的节点的下一个节点。


代码参考：https://github.com/zhedahht/CodingInterviewChinese2/blob/master/08_NextNodeInBinaryTrees/NextNodeInBinaryTrees.cpp

*/


struct BinaryTreeNode
{
    int  m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
    BinaryTreeNode* m_pParent;
};


#include <stdio.h>

BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
    if (pNode == nullptr)
    {
        return nullptr;
    }
    
    BinaryTreeNode* pNext = nullptr;

    if (pNode->m_pRight != nullptr)
    {
        BinaryTreeNode* pRight =  pNode->m_pRight;
        while (pRight->m_pLeft != nullptr)
        {
            pRight = pRight->m_pLeft;
        }
        pNext = pRight;        
    }
    else if (pNode->m_pParent != nullptr)
    {
        BinaryTreeNode* pCurrent = pNode;
        BinaryTreeNode* pParent = pNode->m_pParent;
        while (pParent != nullptr && pCurrent == pParent->m_pRight)
        {
            pCurrent = pParent;
            pParent = pParent->m_pParent;
        }
        pNext = pParent;
    }
    return pNext;


}