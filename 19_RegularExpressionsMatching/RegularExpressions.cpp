// 面试题19：正则表达式匹配
// 题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。模式中的字符'.'
// 表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题
// 中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"
// 和"ab*ac*a"匹配，但与"aa.a"及"ab*a"均不匹配。


/*
同leetcode https://leetcode-cn.com/problems/regular-expression-matching/ 10. 正则表达式匹配

分情况讨论：
//如果模式串当前字符的下一位是 *：
    如果当前字符匹配成功：
        1.
            str + 1;
            pattern + 2; 利用* 可以匹配前面字符出现1次
        2.
            str + 1;
            pattern;     利用 * 可以匹配前面字符多次(大于1) ,防止当前字符重复出现多次，这样继续留在模式串的当前位置可以匹配重复的那部分，跳过的话就失去了*的这个功能。
                         比如 str = "aaaaaab" pattern = .*b。
        
        3.  str;
            pattern + 2; 考虑 str = aaab  pattern = aaabb*。此时aaab就可以匹配了，那多了的 b* 也无所谓，因为 b* 可以是匹配0次 b，相当于b*可以直接去掉了。

    如果当前字符没有匹配成功

否则：
    如果 字符串和模式串的当前字符偶读匹配成功
    字符串和模式串均向后移动一位
    str + 1;
    pattern + 1;
匹配失败

*/

#include<fstream>

bool match(char* str,char* pattern)
{
    if(str == nullptr || pattern == nullptr)
        return false;
    return matchCore(str, pattern);           
}


bool matchCore(const char* str,const char* pattern)
{
    if(*str == '\0' && *pattern == '\0')
        return true;

    if(*str != '\0' && *pattern == '\0')
        return false;
    if (*(pattern+1) == '*') 
    {
        if(*pattern == *str || (*pattern == '.' && *str != '\0'))
            // 进入有限状态机的下一个状态
            return matchCore(str+1,pattern+2) 
            // 继续留在有限状态机的当前状态 
            || matchCore(str+1,pattern) // 
            // 略过一个'*' 
            || matchCore(str,pattern+2);           

        else
            // 略过一个'*'
            return matchCore(str,pattern+2);
            
    }
     if(*str == *pattern || (*pattern == '.' && *str != '\0'))
        return matchCore(str + 1, pattern + 1);
    
    return false;
}