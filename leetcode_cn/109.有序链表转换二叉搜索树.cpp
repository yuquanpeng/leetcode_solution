/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (62.46%)
 * Total Accepted:    4.7K
 * Total Submissions: 7.4K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定的有序链表： [-10, -3, 0, 5, 9],
 * 
 * 一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 *  所以我们需要找到链表的中间节点， 这个就是根节点， 链表的左半部分就是
左子树， 而右半部分则是右子树， 我们继续递归处理相应的左右部分， 就能够构造出对应的二叉树了。
这题的难点在于如何找到链表的中间节点， 我们可以通过fast， slow指针来解决， fast每次走两步， slow每次走一步， fast走到结尾， 那么slow就是中间节点了
 * */
class Solution
{
  public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        return build(head, NULL);
    }
    TreeNode *build(ListNode *start, ListNode *end)
    {
        if (start == end)
            return NULL;
        ListNode *fast = start;
        ListNode *slow = start;
        while (fast != end && fast->next != end)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *node = new TreeNode(slow->val);
        node->left = build(start, slow);
        node->right = build(slow->next, end);
        return node;
    }
};
