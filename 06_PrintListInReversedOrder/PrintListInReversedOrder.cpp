// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。

#include "..\Utilities\List.h"
#include<vector>


/* 
leetcode 206 反转链表

本题可用两种方法：
1.迭代;
2.递归;

针对迭代:
参考1：https://leetcode-cn.com/problems/reverse-linked-list/solution/cyu-yan-fan-zhuan-lian-biao-fang-fa-zong-jie-by-sh/
参考2:https://leetcode-cn.com/problems/reverse-linked-list/solution/dong-hua-yan-shi-206-fan-zhuan-lian-biao-by-user74/


针对递归：
解释1:
不妨假设链表为1，2，3，4，5。
按照递归，当执行reverseList（5）的时候返回了5这个节点，reverseList(4)中的p就是5这个节点，
我们看看reverseList（4）接下来执行完之后，5->next = 4, 4->next = null。
这时候返回了p这个节点，也就是链表5->4->null，接下来执行reverseList（3），
代码解析为4->next = 3,3->next = null，这个时候p就变成了，5->4->3->null, reverseList(2), reverseList(1)
依次类推，p就是:5->4->3->2->1->null

解释2:
假设链表是[1, 2, 3, 4, 5]从最底层最后一个reverseList(5)来看
1.返回了5这个节点
2.reverseList(4)中
3.p为5
4.head.next.next = head 相当于 5 -> 4
5.现在节点情况为 4 -> 5 -> 4
1.head.next = null,切断4 -> 5 这一条，现在只有 5 -> 4 -> null
1.返回（return）p为5，5 -> 4
1.返回上一层reverseList(3)
1.处理完后返回的是4 -> 3
1.依次向上

head->next->next = head 目的是将head指向的结点指向自身,例如将4->5 转化为5->4;
head.next = null, 切断 4->5 且将5->4—>5 转化为5->4->null;
p 一开始就指向了反转后链表的头结点，在本例中是5，所以后面的操作和p无关。


参考1:https://leetcode-cn.com/problems/reverse-linked-list/solution/fan-zhuan-lian-biao-by-leetcode/

 */

// 迭代解法
ListNode* reverseList_Iteratively(ListNode* head)
{   
    ListNode *prev = nullptr;
    ListNode *cur = head;
    while (cur)
    {
        ListNode *tmp = cur->next; //备份当前结点的下一结点
        cur->next = prev; //当前遍历的结点指向pre
        prev = cur; //pre指向当前结点,当前结点成为新表的首结点
        cur = tmp; // 指向当前结点下一结点，所以tmp的作用在于辅助遍历，防止断链
    }
    return prev;
    
}

// 递归解法
ListNode* reverseList_Recursively(ListNode* head)
{
    if(head == nullptr || head->next == nullptr)
        return head;   
    ListNode *p = reverseList_Recursively(head->next);
    head->next->next= head;
    head->next = nullptr;
    return p;
    
}