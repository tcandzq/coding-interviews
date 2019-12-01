// 面试题7：重建二叉树
// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
// 入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,
// 2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出
// 图2.6所示的二叉树并输出它的头结点。

#include<vector>
#include "..\Utilities\Tree.h"

using namespace std;

/* 
同leetcode 105 从前序与中序遍历序列构造二叉树

如今我们已经遇到了好几个类似的从数组重建二叉树的题目了。先来几个关键词：递归、区间分治。

很早之前我们说过，这种区间分治的题目，使用左闭右闭区间更加方便，如果坚持使用左闭右开区间，容易导致人懵逼。在这个题目中也是类似的，我们使用左闭右闭区间。

重建二叉树的基本思路就是先构造根节点，再构造**左子树**，接下来构造**右子树**，其中，构造**左子树**和**右子树**是一个子问题，递归处理即可。因此我们只关心如何构造根节点，以及如何递归构造左子树和右子树。

递归函数的设计上，仍旧采用**左闭右闭**对数组局部进行描述。即一个数组，使用 3 个变量描述：

数组本身 arr
数组的起始位置 lo
数组的结束位置 hi
因此，数组实际元素就是 arr[lo..hi] 这个范围（注意这是一个左闭右闭的区间，如果你喜欢左闭右开区间，那你可能重新考虑一下 lo、hi 的值如何计算）。在有些语言里，使用切片的方式表示，会更加方便，但是奈何 c/c++ 不支持切片语法。

接下来，很自然的就是写出递归函数原型 TreeNode* buildTree(vector<int>& preorder, int lo1, int hi1, vector<int>& inorder, int lo2, int hi2)，它的主要参数相比原来题目中的原型多了数组范围描述变量，这是我们所期望的，因为我们要做区间分治嘛。

后面的故事就很简单了，三元组 (preorder, lo1, hi1) 描述的前序遍历数组，以及三元组 (inorder, lo2, hi2) 描述的中序遍历数组，如何从它们重建二叉树？递归的说法就是：

创建根节点
递归创建左子树
递归创建右子树
你会发现，递归创建左子树，无非就是再构造一个新的前序遍历的三元组 (preorder, lo1+1, lo1+mid-lo2) 以及 (inorder, lo2, mid-1)，其中 mid 是当前 inorder 中 root 的位置。
 
 */

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // preorder: [root, [left], [right]]
        // inorder:  [[left], root, [right]]
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    // 三元组 (preorder, lo1, hi1) 描述的前序遍历数组，以及三元组 (inorder, lo2, hi2) 描述的中序遍历数组
    TreeNode* buildTree(vector<int>& preorder, int lo1, int hi1, vector<int>& inorder, int lo2, int hi2) {
        if (lo1 > hi1 || lo2 > hi2) return nullptr;
        int root = preorder[lo1];
        int mid = lo2;
        // 在 inorder 中查找 root 位置
        for (int i = lo2; i <= hi2; ++i) {
            if (inorder[i] == root) {
                mid = i;
                break;
            }
        }
        
        auto s = new TreeNode(root);
        // 下面的数组表示分割长度
        // preorder:[root, mid-lo2, hi2-mid],mid - lo2 表示左子树的长度
        // inorder: [mid-lo2, mid, hi2-mid]     
        s->left = buildTree(preorder, lo1+1, lo1+mid-lo2, inorder, lo2, mid-1);
        s->right = buildTree(preorder, lo1+mid-lo2+1, hi1, inorder, mid+1, hi2);
        return s;
    }
};