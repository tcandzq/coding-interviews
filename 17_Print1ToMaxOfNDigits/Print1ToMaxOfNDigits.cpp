// 面试题17：打印1到最大的n位数
// 题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则
// 打印出1、2、3一直到最大的3位数即999。

/*
全排列问题
*/


#include <cstdio>
#include <memory>
#include <string.h>


void Print1ToMaxOfNDigits(int n)
{
    if(n < 0)
        return;
    
    char* number = new char[n +1];
    number[n] = '\n';

    for (int i = 0; i < 10; ++i)
    {
        number[0] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number,n,0);
    }

    delete[] number;
    
}


void Print1ToMaxOfNDigitsRecursively(char* number,int length,int index)
{
    if(index == length -1)  // 递归的结束条件
        PrintNumber(number);
        return;
    for (int i = 0; i < 10; ++i)
    {
        number[index + 1] = i + '0';
        Print1ToMaxOfNDigitsRecursively(number,length,index+1);
    }
    
}


// 字符串number表示一个数字，数字有若干个0开头
// 打印出这个数字，并忽略开头的0
void PrintNumber(char* number)
{
    bool isBeginning0 = true;

    int nLength = strlen(number);

    for (int i = 0; i < nLength; ++i)
    {
        if(isBeginning0 && number[i] != '0')
            isBeginning0 = false;
        
        if(!isBeginning0)
            printf("%c",number[i]);
    }
    printf("\t");
}