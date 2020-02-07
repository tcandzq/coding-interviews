// 面试题33：二叉搜索树的后序遍历序列
// 题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则返回true，否则返回false。假设输入的数组的任意两个数字都互不相同。

#include<vector>

using namespace std;


class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
                
    }

    bool VerifySquenceOfBSTCore(vector<int> sequence,int length)
    {
        if(sequence.empty())
            return true;

        int root = sequence[-1];

        // 在二叉搜索树中左子树的结点小于根结点
        int i = 0;
        for (;  i < sequence.size()-1; ++i)
        {
            if(sequence[i] > root)
                break;
        }

        // 在二叉搜索树中右子树的结点大于根结点
        int j = i;
        for (; i < sequence.size()-1; ++j)
        {
            if(sequence[j] < root)
                return false;
        }
        
        //判断左子树是不是二叉搜索树
        bool left = true;
        if(i > 0)
            left = VerifySquenceOfBSTCore(sequence,i);
        
        // 判断右子树是不是二叉搜索树
        bool right = true;
        if(i < sequence.size() -1)
            right = VerifySquenceOfBST(sequence.push_back(i), length - i - 1);
        return (left && right);
    }
};