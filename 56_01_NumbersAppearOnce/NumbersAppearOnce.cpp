// 面试题56（一）：数组中只出现一次的两个数字
// 题目：一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序
// 找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

#include<vector>

using namespace std;

/* 

同leetcode2 60 只出现一次的数字III
参考1:https://leetcode-cn.com/problems/single-number-iii/solution/zhi-chu-xian-yi-ci-de-shu-zi-iiixiang-jie-pai-xu-h/
参考2:https://leetcode-cn.com/problems/single-number-iii/solution/cai-yong-fen-zhi-de-si-xiang-jiang-wen-ti-jiang-we/
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sign = 0;
        for(auto num :nums)  //取得数组中两个唯一数的按位异或结果
        {
            sign ^= num;
        }
        sign &= -sign;  //获取区分两个唯一数的比特位所代表的值
        int n1 = 0, n2 = 0;;
        for(auto num:nums)
        {
            if((num & sign) == sign) //通过标识，区分两个数组;num & sign要加括号
            {
                n1 ^= num;
            }
            else{
                n2 ^= num;
            }
        }
        return {n1,n2};
    }
};