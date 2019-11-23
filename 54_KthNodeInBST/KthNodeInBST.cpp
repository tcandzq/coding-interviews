// 面试题54：二叉搜索树的第k个结点
// 题目：给定一棵二叉搜索树，请找出其中的第k大的结点。

/* 
同leetcode 230 二叉搜索树中第K小的元素

指定中序遍历k次就可以了
注意:传参通过引用来起到全局变量的作用
 */
#include "..\Utilities\Tree.h"

class Solution {
private:
    int InOrder(TreeNode* root,int &cnt,int &ans)
    {
        if(root == nullptr) return;
        InOrder(root->left,cnt,ans);
        --cnt;
        if(cnt == 0)
        {
            ans = root->val;
            return;
        }
        InOrder(root->right,cnt,ans);
    }


public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = k,ans = 0;
        InOrder(root,cnt,ans);
        return ans;
    }
};


