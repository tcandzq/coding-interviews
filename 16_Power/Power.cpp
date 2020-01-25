// 面试题16：数值的整数次方
// 题目：实现函数double Power(double base, int exponent)，求base的exponent
// 次方。不得使用库函数，同时不需要考虑大数问题。


/*
同leetcode 50. Pow(x, n) :https://leetcode-cn.com/problems/powx-n/submissions/

代码参考：https://leetcode-cn.com/problems/powx-n/solution/qing-xi-jian-dan-de-dan-han-shu-di-gui-wu-lei-xing/

*/

#include<cmath>


bool g_InvalidInput  = false;


class Solution {
public:

    double Power(double base,int exponent)
    {
        if (exponent == 0) { return 1; }
        if (exponent == 1) { return base; }
        if (exponent == -1) { return 1 / base; }
        double half = Power(base, exponent / 2);
        double rest = Power(base, exponent % 2);
        return rest * half * half;
    }
};


