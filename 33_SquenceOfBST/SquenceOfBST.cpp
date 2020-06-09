// 面试题33：二叉搜索树的后序遍历序列
// 题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则返回true，否则返回false。假设输入的数组的任意两个数字都互不相同。

/*
代码参考:https://www.cnblogs.com/wanglei5205/p/8684408.html
*/


#include<vector>

using namespace std;


class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
            return VerifySquenceOfBSTCore(sequence,0,sequence.size()-1);
    }

    bool VerifySquenceOfBSTCore(vector<int> sequence,int begin,int end)
    {
        // 边界条件
        if(sequence.empty() || begin > end)
            return false;

        int root = sequence[end];

        // 在二叉搜索树中左子树的结点小于根结点
        int i = 0;
        for (;  i < end; ++i)
        {
            if(sequence[i] > root)
                break;
        }

        // 在二叉搜索树中右子树的结点大于根结点
        int j = i;
        for (; j < end; ++j)
        {
            if(sequence[j] < root)
                return false;
        }
        
        //判断左子树是不是二叉搜索树
        bool left = true;
        if(i > begin)
            left = VerifySquenceOfBSTCore(sequence,begin,i-1);
        
        // 判断右子树是不是二叉搜索树
        bool right = true;
        if(i < end -1)
            right = VerifySquenceOfBSTCore(sequence, i,end -1);
        return (left && right);
    }
};