// 面试题43：从1到n整数中1出现的次数
// 题目：输入一个整数n，求从1到n这n个整数的十进制表示中1出现的次数。例如
// 输入12，从1到12这些整数中包含1 的数字有1，10，11和12，1一共出现了5次。

/* 
同leetcode 233 数字 1 的个数

*/

#include<vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> digit;
    vector<vector<int>> memo;
    int countDigitOne(int n) {
        return solve(n);
    }

    int solve(int n)
    {
        int len = 0;
        digit.assign(64,0);
        while (n)
        {
            digit[++len] = n % 10;
            n /= 10;
            cout << n << endl;
        }
        cout << len <<endl;
        memo.assign(len,vector<int>(len+1,-1));
        
        return dfs(len,0,1,1);
    }
    // 从高位往低位处理
    int dfs(int pos,int sm,bool lead /*前导零*/,bool limit /*数位上界变量*/)
    {
        if (pos == 0)
        {
           return sm;
        }
        if (!lead && !limit && memo[pos][sm] != -1)
        {
            return memo[pos][sm];
        }
        int up = limit ? digit[pos] : 9; //如果当前位的上一位是有限制的,比如54321,万位是5,当前位千位的范围只能是4~0,不能是9~0;
        int ret = 0;
        //开始计数
        for (int i = 0; i <= up; ++i) //枚举，然后把不同情况的个数加到ret就可以了
        {
            ret += dfs(pos - 1,/*状态转移*/ sm + (i == 1),lead && (i==0),limit && (i == up));
            // 大概就是说，我当前数位枚举的数是i，然后根据题目的约束条件分类讨论去计算不同情况下的个数，还有要根据state变量来保证i的合法性，
        }
        if (! limit && !lead) //计算完，记录状态
        {
           memo[pos][sm] = ret;
        }
        return ret;
        
    }
};


int main(int argc, char const *argv[])
{
    int n  = -13;

    Solution  solution;

    cout << solution.countDigitOne(n);

    // cout << 99 / 10 << endl;
    return 0;
}
