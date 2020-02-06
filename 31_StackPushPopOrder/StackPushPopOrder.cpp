// 面试题31：栈的压入、弹出序列
// 题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是
// 否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1、2、3、4、
// 5是某栈的压栈序列，序列4、5、3、2、1是该压栈序列对应的一个弹出序列，但
// 4、3、5、1、2就不可能是该压栈序列的弹出序列。



#include<stack>
#include<vector>

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        bool IsPopOrder = false;

        stack<int> stackData;
        // 入栈序列
        vector<int>::iterator push_it = pushV.begin();
        // 出栈序列
        vector<int>::iterator pop_it = popV.begin();

        while (pop_it != popV.end())
        {   
            // 当辅助栈的栈顶元素不是要弹出的元素
            // 先压入一些数字入栈
            while (stackData.empty() || stackData.top() != *pop_it)
            {
                // 如果所有数字都压入辅助栈了，退出循环
                if (push_it == pushV.end())
                    break;
                                 
                stackData.push(*push_it);

                push_it ++;
            }
            // 当要弹出元素不是辅助栈的栈顶元素，且要弹出元素已经在辅助栈了。参考[1,2,3,4,5],[4,3,5,1,2]这个例子
            if(stackData.top() != *pop_it)
                break;
            stackData.pop();
            pop_it ++;
        }
        if (stackData.empty() && pop_it == popV.end())
            IsPopOrder = true;
        
        return IsPopOrder;
    }    
};


