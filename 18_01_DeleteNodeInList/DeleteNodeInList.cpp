// 面试题18（一）：在O(1)时间删除链表结点
// 题目：给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该
// 结点。

/* 
同leetcode 237 删除链表中的节点
 */


#include "..\Utilities\List.h"

void DeleteDuplication(ListNode* pListHead,ListNode* pToBeDeleted)
{
    if(pListHead == nullptr || pToBeDeleted == nullptr) return;

     // 要删除的结点不是尾结点
    if (pToBeDeleted->next != nullptr)
    {
        pToBeDeleted->val = pToBeDeleted->next->val;
        pToBeDeleted->next = pToBeDeleted->next->next;
    }
    // 链表只有一个结点，删除头结点（也是尾结点）
    else if(pListHead == pToBeDeleted)
    {
        delete pToBeDeleted; // 手动释放内存
        pToBeDeleted = nullptr;
        pListHead = nullptr;
    }
     // 链表中有多个结点，要删除的结点是尾结点
    else
    {
        ListNode* pNode = pListHead;
        while(pNode->next != pToBeDeleted)
        {
            pNode = pNode->next;            
        }
 
        pNode->next = nullptr;
        delete pToBeDeleted; // 手动释放内存
        pToBeDeleted = nullptr;

}