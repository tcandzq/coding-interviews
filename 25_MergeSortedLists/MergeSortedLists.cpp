// 面试题25：合并两个排序的链表
// 题目：输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按
// 照递增排序的。例如输入图3.11中的链表1和链表2，则合并之后的升序链表如链
// 表3所示。

/* 
leetcode 21 合并两个有序链表

参考1.https://leetcode-cn.com/problems/merge-two-sorted-lists/solution/he-bing-liang-ge-you-xu-lian-biao-by-leetcode/
参考2.https://leetcode-cn.com/problems/merge-two-sorted-lists/solution/he-bing-liang-ge-you-xu-lian-biao-guan-fang-cban-b/
 */

#include "..\Utilities\List.h"


// 迭代版本
class Solution {
public:
    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *prev = dummy;
        while (l1 && l2)
        {
           if (l1->val > l2->val)
           {
               prev->next = l1;
               l1 = l1->next ;
           }
           else
           {
               prev ->next = l2;
               l2 = l2 ->next;
           }
           prev = prev -> next;
        }
        prev ->next = l1 ? l1:l2;
        delete prev; // 手动释放内存
        return dummy->next;
    }

    ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2)
    {
        if(l1 == nullptr)
        {
            return l2;
        }
        else if(l2 == nullptr)
        {
            return l1;
        }
        else if (l1->val > l2->val)
        {
            l2->next = mergeTwoLists2(l1,l2->next);
            return l2;
        }
        else
        {
            l1->next = mergeTwoLists2(l1->next,l2);
            return l1;
        }
    }
};

// 递归版本
