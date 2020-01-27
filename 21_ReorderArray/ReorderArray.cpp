// 面试题21：dam
// 题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
// 奇数位于数组的前半部分，所有偶数位于数组的后半部分。

#include<vector>

using namespace std;


class Solution {
public:
    void reOrderArray(vector<int> &array) {
        auto begin = array.begin();

        auto end = array.end();

        while (begin < end)
        {   
            // 向后移动begin，直到它指向偶数
            while (begin < end && (*begin & 0x1) != 0)
                begin ++;
            
            // 向前移动end，直到它指向奇数
            while (begin < end && (*end & 0x1) == 0)
                end --;
            
            if(begin < end)
            {
                int temp = *begin;
                *begin = *end;
                *end = temp;
            }                
        }        
    }
};