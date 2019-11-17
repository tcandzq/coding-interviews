// 面试题3（二）：不修改数组找出重复的数字
// 题目：在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至
// 少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
// 数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
// 输出是重复的数字2或者3。


/*
leetcode287题-寻找重复数 
利用二分查找的思想
参考:https://leetcode-cn.com/problems/find-the-duplicate-number/solution/er-fen-fa-si-lu-ji-dai-ma-python-by-liweiwei1419/
*/

# include<vector>
using namespace std;

int getDuplication(vector<int>& nums)
{
    int len= nums.size();
    int left = 0;
    int right = len - 1;
       
   
    while (left < right)
    {   
        int mid  = left + ((right - left) >> 1);
         int counter = 0;
        for(int num:nums){
            if (num <= mid)
            {
                ++counter;
            }
            
        }
        if (counter > mid)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
        
    }
    return left;
}




