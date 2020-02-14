/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *a = l1;
        ListNode *b = l2;
        ListNode *c = new ListNode(0);
        ListNode *head = c;
        while (a != NULL && b != NULL)
        {
            /* code */
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
        if (a != NULL)
            c->next = a;
        return head->next;
    }
};
// @lc code=end
