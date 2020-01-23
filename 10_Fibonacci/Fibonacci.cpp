// 面试题10：斐波那契数列
// 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。


/*
代码参考：https://github.com/zhedahht/CodingInterviewChinese2/blob/master/10_Fibonacci/Fibonacci.cpp
*/


#include<cstdio>

// ====================方法1：递归====================
long long Fibonacci_Solution1(unsigned int n)
{
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;

    return Fibonacci_Solution1(n-1) + Fibonacci_Solution1(n-1);
}

// ==================方法2：循环=========================

long long Fibonacci_Solution2(unsigned int n)
{
    int result[2] = {0,1};
    if(n < 2)
        return result[n];

    long long fibNMinousOne = 1;
    long long fibNMinousTwo = 0;

    long long fibN = 0;

    for (unsigned i = 2; i <= n; ++i)
    {
        fibN = fibNMinousOne + fibNMinousTwo;
        fibNMinousTwo = fibNMinousOne;
        fibNMinousOne = fibN;
    }
    return fibN;
}
