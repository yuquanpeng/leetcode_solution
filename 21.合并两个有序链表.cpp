/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (52.90%)
 * Total Accepted:    50.1K
 * Total Submissions: 94.4K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *a = l1;
        ListNode *b = l2;
        ListNode *c = new ListNode(0);
        ListNode *head = c;
        while (a != NULL && b != NULL)
        {
            if (a->val <= b->val)
            {
                c->next = a;
                c = c->next;
                a = a->next;
            }
            else
            {
                c->next = b;
                c = c->next;
                b = b->next;
            }
        }
        if (b != NULL)
            c->next = b;
        else
            c->next = a;
        return head->next;
    }
};
