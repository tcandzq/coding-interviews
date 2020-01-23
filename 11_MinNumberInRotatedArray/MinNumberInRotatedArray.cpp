// 面试题11：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
// {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。


/*
同leetcode153 寻找旋转排序数组中的最小值

代码参考1：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/solution/c-er-fen-mo-ban-by-codave/
代码参考2：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/solution/er-fen-by-powcai-2/
*/


#include<vector>


using namespace std;

class Solution{
    public:
    //======================解法一=====================
        int findMin(vector<int>& nums)
        {
            if (nums.empty())
                return 0;
            int left = 0;
            int right = nums.size() - 1;
            
            while (left < right)
            {
                int mid = left + right>> 1;
                if(nums[mid] < nums[right])
                    right = mid;
                else
                {
                    left = mid + 1;
                }
                
            }
            return nums[right];
        }
};
