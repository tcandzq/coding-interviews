// 面试题41：数据流中的中位数
// 题目：如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么
// 中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，
// 那么中位数就是所有数值排序之后中间两个数的平均值。

/* 
leetcode 295 数据流的中位数
本题有两种写法
1.《剑指Offer》里的模板写法，自己实现了堆;
2.leetcode里的题解写法，引入了priority_queue
参考 https://leetcode-cn.com/problems/find-median-from-data-stream/solution/shu-ju-liu-de-zhong-wei-shu-by-leetcode/

 */
#include <cstdlib>
#include <cstdio>
# include<queue>
# include<vector>
#include <functional>
#include <stdexcept>

using namespace std;

class MedianFinder {
    priority_queue<int> small;  //默认是大顶堆
    priority_queue<int,vector<int>,greater<int>> large;  // 构造小顶堆

public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        small.push(num);  // 先插入大顶堆
        large.push(small.top());  // 在大顶堆排序完以后再插入小顶堆
        small.pop();
        if (small.size() < large.size()) 
        {
            small.push(large.top());
            large.pop();
        }
        
    }
    
    double findMedian() {
        return small.size() > large.size() ? (double) small.top() : (small.top() + large.top()) * 0.5;
    }
};

template<typename T>class DynamicArray
{   
    private:
        vector<T> min;
    private:
        vector<T> max;

    public:
        void Insert(T num)
        {
            if (((min.size() + max.size()) & 1) == 0)  //  如果数据流的数量是偶数时插入小顶堆
            {
                if (max.size() >0 && max[0] > num ) // 如果num 小于大顶堆的最大值就插入大顶堆
                {
                    max.push_back(num); 
                    push_heap(max.begin(),max.end(),less<T>()); // (默认为大顶堆) 向堆中插入一个元素，并且使堆的规则依然成立
                    
                    num = max[0];

                    pop_heap(max.begin(),max.end(),less<T>());
                    max.pop_back();
                }
                min.push_back(num); 
                push_heap(min.begin(), min.end(), greater<T>());   // 小顶堆 向堆中插入元素    
            }
            else  // 如果数据流的数量是奇数时插入大顶堆
            { 
                if (min.size() > 0 && min[0] < num)  // 如果num 大于 小顶堆的最小值就插入小顶堆
                {
                    min.push_back(num);
                    push_heap(min.begin(), min.end(), greater<T>());

                    num = min[0];

                    pop_heap(min.begin(), min.end(), greater<T>());
                    min.pop_back();
                }
                max.push_back(num); 
                push_heap(max.begin(), max.end(), less<T>()); // 向大顶堆中插入元素

            }            
        }

    T GetMedian()
    {
        int size = max.size() + min.size();
        if (size == 0)
            // logic_error e("No numbers are available"); // 这块的异常处理一直搞不定
            // throw exception(e);
            return -1;
        T media = 0;

        if (size & 1 == 0)
            media =  (min[0] + max[0]) / 2;
        else
            return min[0];
        return media;
    }

};

void Test(char const* testName, DynamicArray<double>& numbers, double expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(abs(numbers.GetMedian() - expected) < 0.0000001)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[])
{
    DynamicArray<double> numbers;

    printf("Test1 begins: ");
    try
    {
        numbers.GetMedian();
        printf("FAILED.\n");
    }
    catch(const exception&)
    {
        printf("Passed.\n");
    }

    numbers.Insert(5);
    Test("Test2", numbers, 5);

    numbers.Insert(2);
    Test("Test3", numbers, 3.5);

    numbers.Insert(3);
    Test("Test4", numbers, 3);

    numbers.Insert(4);
    Test("Test6", numbers, 3.5);

    numbers.Insert(1);
    Test("Test5", numbers, 3);

    numbers.Insert(6);
    Test("Test7", numbers, 3.5);

    numbers.Insert(7);
    Test("Test8", numbers, 4);

    numbers.Insert(0);
    Test("Test9", numbers, 3.5);

    numbers.Insert(8);
    Test("Test10", numbers, 4);

    return 0;
}