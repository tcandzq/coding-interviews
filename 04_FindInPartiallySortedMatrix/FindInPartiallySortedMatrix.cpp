// 面试题4：二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
// 照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
// 整数，判断数组中是否含有该整数。

/* 
leetcode74 搜索二维矩阵
1.使用二分查找
2.从右上角或者左下交开始搜索
参考:https://leetcode-cn.com/problems/search-a-2d-matrix-ii/solution/er-fen-fa-pai-chu-fa-python-dai-ma-java-dai-ma-by-/
 */
#include <iostream>
#include<vector>
using namespace std;

// 从右上角开始搜索
bool searchMatrix(vector<vector<int>>& matrix, int target)
{

    if (matrix.size() == 0 || matrix[0].size() == 0)
    {
        return false;
    }
    
    int rows = matrix.size();
    int cols = matrix[0].size();

    int x = 0;
    int y = cols - 1;


    while (x <= rows - 1 && y >= 0)
    {
        if (matrix[x][y] > target )      
            --y;       
        else if (matrix[x][y] < target)
        
            ++x;
        else
            return true;
        
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int a1[] = { 1, 2, 8, 9, };
    int a2[] = { 2, 4, 9, 12, };
    int a3[] = { 4, 7, 10, 13, };
    int a4[] = { 6, 8, 11, 15, };
    vector<vector<int>> array;
    array.push_back(vector<int>(a1, a1 + 4));
    array.push_back(vector<int>(a2, a2 + 4));
    array.push_back(vector<int>(a3, a3 + 4));
    array.push_back(vector<int>(a4, a4 + 4));
    
    cout << searchMatrix(array,10) << endl;

    return 0;
}
