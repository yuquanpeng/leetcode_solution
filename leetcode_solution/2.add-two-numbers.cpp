/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l2;
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        int carry = 0;
        while (l1 || l2 || carry)
        {
            if (l1)
                carry += l1->val, l1 = l1->next;
            if (l2)
                carry += l2->val, l2 = l2->next;
            ListNode *newnode = new ListNode(carry % 10);
            carry /= 10;
            p->next = newnode, p = p->next;
        }
        return head->next;
    }
};
// @lc code=end
