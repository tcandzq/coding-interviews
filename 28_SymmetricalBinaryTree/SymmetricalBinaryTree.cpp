// 面试题28：对称的二叉树
// 题目：请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和
// 它的镜像一样，那么它是对称的。


#include "../Utilities/Tree.h"



/*
同 leetcode 101 对称二叉树 https://leetcode-cn.com/problems/symmetric-tree/
*/

bool isSymmetrical(TreeNode* pRoot)
{
    return isSymmetrical(pRoot, pRoot);
}

bool isSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2)
{
    if(pRoot1 == nullptr && pRoot2 == nullptr)
        return true;

    if(pRoot1 == nullptr || pRoot2 == nullptr)
        return false;

    if(pRoot1->left != pRoot2->right)
        return false;

    return isSymmetrical(pRoot1->left, pRoot2->right)
        && isSymmetrical(pRoot1->right, pRoot2->left);
}