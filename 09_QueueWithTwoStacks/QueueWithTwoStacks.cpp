// 面试题9：用两个栈实现队列
// 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
// 和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。


/*
代码参考：https://github.com/zhedahht/CodingInterviewChinese2/blob/master/09_QueueWithTwoStacks/Queue.h
*/


#pragma once
#include <stack>
#include<exception>

using namespace std;

template<typename T> class CQueue
{
    public:
        CQueue(void);
        ~CQueue(void);

        void appendTail(const T& node);

        T deleteHead();

    private:
        stack<T> stack1;
        stack<T> stack2;

};

template <typename T> CQueue<T>::CQueue(void)
{

}
    template <typename T> CQueue<T>::~CQueue(void)
{

}

template<typename T> void CQueue<T>::appendTail(const T& element)
{
    stack1.push(element);
}

template<typename T> T CQueue<T>::deleteHead()
{
    if(stack2.size() <= 0)
    {
        while (stack1.size() > 0)
        {
            T& data = stack1.top();
            stack1.pop()
            stack2.push(data);
        }    
    }

    if(stack2.size() == 0)
        throw new exception("queuw is empty");

    
    T head = stack2.top();
    stack2.pop();

    return head;
} 