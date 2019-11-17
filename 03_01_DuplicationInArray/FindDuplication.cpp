// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。


class Solution{
    public:
        bool duplicate(int numbers[],int length,int* duplication)
        {
            
            if (numbers == nullptr || length <= 0)
            {
                return false;
            }
            
            for (int i = 0; i < length; i++)
            {
                if (numbers[i] <= 0 || numbers[i] > length -1)
                {
                    return false;
                }
                
            }
            
            for (int i = 0; i < length; i++)
            {
                while (numbers[i] != i)
                {
                    // 因为前i个位置已经按照对应的索引都排列好了即numbers[i] == i，所以当i位置的数值已经在前面出现过了，说明是重复值
                    if (numbers[i] == numbers[numbers[i]]) 
                    {
                        *duplication = numbers[i];
                        return true;
                    }
                    int tmp = numbers[i];
                    numbers[i] = numbers[tmp];
                    numbers[tmp] = tmp;                 
                }               
            }
            return false;          
        }
};

