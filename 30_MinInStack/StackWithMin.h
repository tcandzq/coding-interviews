// 面试题30：包含min函数的栈
// 题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min
// 函数。在该栈中，调用min、push及pop的时间复杂度都是O(1)。


#pragma once;

#include<stack>
#include<assert.h>

template<typename T> class StackWithMin
{
    public:
        StackWithMin() {};
        virtual ~StackWithMin() {};

        T& top();
        const T& top() const;

        void push(const T& value);
        void pop();

        const T& min() const;

        bool empty() const;
        size_t size() const;

    private:
        std::stack<T> m_data;  // 数据栈，存放栈的所有元素
        std::stack<T> m_min;   // 辅助栈，存放栈的最小元素
};

template<typename T> void 