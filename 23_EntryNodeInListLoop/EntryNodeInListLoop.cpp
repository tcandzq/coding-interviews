// 面试题23：链表中环的入口结点
// 题目：一个链表中包含环，如何找出环的入口结点？例如，在图3.8的链表中，
// 环的入口结点是结点3。

/* 
同leetcode 142 环形链表 II
参考:https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/linked-list-cycle-ii-kuai-man-zhi-zhen-shuang-zhi-/
 */

#include "..\Utilities\List.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head,*fast = head;
        while (true)
        {
            if (fast == nullptr || fast->next == nullptr) return nullptr;           
            fast = fast ->next ->next;
            slow = slow -> next;
            if (slow == fast) break;          
        }
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;

    }
};