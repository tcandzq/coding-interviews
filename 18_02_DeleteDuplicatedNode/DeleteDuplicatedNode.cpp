// 面试题18（二）：删除链表中重复的结点
// 题目：在一个排序的链表中，如何删除重复的结点？例如，在图3.4（a）中重复
// 结点被删除之后，链表如图3.4（b）所示。

#include "..\Utilities\List.h"

/* 
同leetcode 82 删除排序链表中的重复元素II
参考1:https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/discuss/28334/Is-this-the-best-C%2B%2B-solution
参考2:https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/solution/kuai-man-zhi-zhen-by-powcai-2/
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      ListNode fakeHead(0);
      fakeHead.next = head;  // 虚结点
      ListNode *pre = &fakeHead;
      ListNode *cur = pre->next;

        while (cur)
        {
            while (cur->next && pre->next->val == cur->next->val)
            {
                cur = cur ->next;
            }
            if(pre->next == cur) pre = cur;
            else pre->next = cur->next;
            cur = cur->next;
        }
        return fakeHead.next;
    }
};