// 面试题24：反转链表
// 题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的
// 头结点。


/*
同leetcode 206 反转链表https://leetcode-cn.com/problems/reverse-linked-list/

*/

#include "..\Utilities\List.h"

//=====================递归=====================
ListNode* ReverseList(ListNode* pHead)
{
    if(pHead == nullptr || pHead->next == nullptr)
        return pHead;
    
    ListNode* p = ReverseList(pHead->next);

    pHead->next->next = pHead;

    pHead->next = nullptr;

    return p;
}   


//=====================迭代=====================
ListNode* ReverseList(ListNode* pHead)
{
    ListNode* pCur =  pHead;

    ListNode* pPrev =  nullptr;

    ListNode* pNext =  pHead;

    while (pCur)
    {
        pNext = pCur->next;

        pCur->next = pPrev;

        pPrev = pCur;
        
        pCur = pNext;
    }
    return pPrev;
    
}   