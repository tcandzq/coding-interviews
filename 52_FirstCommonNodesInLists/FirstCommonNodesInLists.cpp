// 面试题52：两个链表的第一个公共结点
// 题目：输入两个链表，找出它们的第一个公共结点。

/* 
同leetcode 160 相交链表
参考:https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/tu-jie-xiang-jiao-lian-biao-by-user7208t/
 */


#include "..\Utilities\List.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;

        }
        ListNode *pA = headA;
        ListNode *pB = headB;

        while (pA != pB)
        {
            pA = pA ? pA -> next : headB;
            pB = pB ? pB -> next : headA;
        }
        return pA;
    }
};