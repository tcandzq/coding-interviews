// 面试题15：二进制中1的个数
// 题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如
// 把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。

/*
同leetcode191. 位1的个数 https://leetcode-cn.com/problems/number-of-1-bits/

注意C++中0为false，非0为true。
*/
class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         while (n)
         {
             n &= (n - 1);
             count += 1;
         }
         return count;
     }
};