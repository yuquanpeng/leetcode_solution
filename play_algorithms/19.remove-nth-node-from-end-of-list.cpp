/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (34.11%)
 * Total Accepted:    371.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
 * 
 * Example:
 * 
 * 
 * Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * Note:
 * 
 * Given n will always be valid.
 * 
 * Follow up:
 * 
 * Could you do this in one pass?
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        assert(n >= 0);
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;

        ListNode *p = dummyNode;
        ListNode *q = dummyNode;
        for (int i = 0; i < n + 1; i++)
        {
            assert(q);
            q = q->next;
        }

        while (q != NULL)
        {
            p = p->next;
            q = q->next;
        }

        ListNode *delNode = p->next;
        p->next = delNode->next;
        delete delNode;

        ListNode *retNode = dummyNode->next;
        delete dummyNode;

        return retNode;
    }
};
