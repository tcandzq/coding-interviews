// 面试题30：包含min函数的栈
// 题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min
// 函数。在该栈中，调用min、push及pop的时间复杂度都是O(1)。

/*
同leetcode 155 最小栈 https://leetcode-cn.com/problems/min-stack/
*/

#include<cstdio>
#include "StackWithMin.h"

void Test(const char* testName,const StackWithMin<int>& stack,int expected)
{
    if(testName != nullptr)
        printf("%s,beigin:",testName);

    if(stack.min() == expected)
        printf("Passed.\n");
    else
    {
        printf("Failed.\n");
    }
}

int main(int argc, char const *argv[])
{
    StackWithMin<int> stack;
    
    stack.push(3);
    Test("Test1", stack, 3);

    stack.push(4);
    Test("Test2", stack, 3);

    stack.push(2);
    Test("Test3", stack, 2);

    stack.push(3);
    Test("Test4", stack, 2);

    stack.pop();
    Test("Test5", stack, 2);

    stack.pop();
    Test("Test6", stack, 3);

    stack.pop();
    Test("Test7", stack, 3);

    stack.push(0);
    Test("Test8", stack, 0);
    
    return 0;
}
