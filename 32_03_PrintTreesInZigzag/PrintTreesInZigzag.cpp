// 面试题32（三）：之字形打印二叉树
// 题目：请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺
// 序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，
// 其他行以此类推。
/* 
同 leetcode 103 二叉树的锯齿形层次遍历
双栈解法,参考:https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/solution/cshi-yong-liang-ge-stack-by-crossing-2/
 */

#include "..\Utilities\Tree.h"
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr) return  result;

        stack<TreeNode*> left,right;
        left.push(root);
        while (!left.empty() || !right.empty())
        {
            if(!left.empty())
            {
                result.push_back(vector<int>());
                while (!left.empty())
                {
                    TreeNode *curr = left.top();
                    left.pop();
                    result.back().push_back(curr->val);
                    if(curr ->left) right.push(curr->left);
                    if(curr ->right) right.push(curr->right);
                }
                
            }
            if(!right.empty())
            {
                result.push_back(vector<int>());
                while (!right.empty())
                {
                    TreeNode *curr = right.top();
                    right.pop();
                    result.back().push_back(curr->val);
                    if (curr->right) left.push(curr->right);
                    if (curr->left) left.push(curr->left);                 
                }
                
            }
        }
        return result;
    }
};