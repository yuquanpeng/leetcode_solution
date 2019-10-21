/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (42.43%)
 * Likes:    1266
 * Dislikes: 74
 * Total Accepted:    196.3K
 * Total Submissions: 458K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given a singly linked list where elements are sorted in ascending order,
 * convert it to a height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted linked list: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 * 
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
这题需要将一个排好序的链表转成一个平衡二叉树， 我们知道， 对于一个二叉树来说， 左子树一定小于根
节点， 而右子树大于根节点。 所以我们需要找到链表的中间节点， 这个就是根节点， 链表的左半部分就是
左子树， 而右半部分则是右子树， 我们继续递归处理相应的左右部分， 就能够构造出对应的二叉树了。
这题的难点在于如何找到链表的中间节点， 我们可以通过fast， slow指针来解决， fast每次走两步， slow每
次走一步， fast走到结尾， 那么slow就是中间节点了。
*/
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
// @lc code=end
