// 面试题58（二）：左旋转字符串
// 题目：字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
// 请定义一个函数实现字符串左旋转操作的功能。比如输入字符串"abcdefg"和数
// 字2，该函数将返回左旋转2位得到的结果"cdefgab"。


/*
同leetcode541 反转字符串 II

参考:https://leetcode-cn.com/problems/reverse-string-ii/solution/li-jie-cheng-mei-ge-kge-fan-zhuan-by-debonairli/
*/

# include<string>
#include <iostream>

using namespace std;


class Solution {
public:
    string reverseStr(string s, int k) {
        for (size_t i = 0; i < s.size(); i ++)
        { 
            int t_end=i+k<=s.length()?i+k-1:s.length()-1; 
            reverse(s,i,t_end);
            i=t_end+k;
        }
        return s;
    }

    void reverse(string& s,int left,int right)
    {
        while (left < right)
        {
            swap(s[left],s[right]);
            left ++ ;
            right --;
        }
        
    }
};

int main(int argc, char const *argv[])
{
    string s = "a";
    Solution solution = Solution();
    auto res = solution.reverseStr(s,2);
    cout << res << endl;
    return 0;
}
