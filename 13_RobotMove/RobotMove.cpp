// 面试题13：机器人的运动范围
// 题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它
// 每一次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和
// 大于k的格子。例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。
// 但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？


#include<string.h>

int movingCounter(int threshold,int rows,int cols)
{
    if(rows <= 0 || cols <= 0 || threshold < 0)
        return 0;
    bool* visited = new bool[rows*cols];
    memset(visited, false, rows * cols);

    int count =  movingCounterCore(threshold,rows,cols,0,0,visited);

    delete[] visited;

    return count;
}


int movingCounterCore(int threshold,int rows,int cols,int row,int col,bool* visited)
{
    int count = 0;
    if(check(threshold,rows,cols,row,col,visited))
    {
        visited[row*cols+col] = true;

        count =  1 + movingCounterCore(threshold,rows,cols,row+1,col,visited)
                    + movingCounterCore(threshold,rows,cols,row-1,col,visited)
                    + movingCounterCore(threshold,rows,cols,row,col+1,visited)
                    + movingCounterCore(threshold,rows,cols,row,col-1,visited);      
    }
    return count;
}



bool check(int threshold,int rows,int cols,int row,int col,bool* visited)
{   

    int row_sum = getDigitSum(row);
    int col_sum = getDigitSum(col);

    if (row >= 0 && row < rows && col >= 0 && col < cols && row_sum +  col_sum <= threshold && !visited[row*cols+col])
        return true;

    return false;
}

int getDigitSum(int number)
{
    int sum = 0;
    while (number > 0)
    {
        sum += number % 10;
        number /=10;
    }
    return sum;
}