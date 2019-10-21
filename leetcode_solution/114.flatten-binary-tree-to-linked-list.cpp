/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 *
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (44.09%)
 * Likes:    1821
 * Dislikes: 240
 * Total Accepted:    270.6K
 * Total Submissions: 607.1K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * Given a binary tree, flatten it to a linked list in-place.
 * 
 * For example, given the following tree:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 
 * The flattened tree should look like:
 * 
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//前序遍历原二叉树
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        stack<TreeNode *> myStack;
        myStack.push(root);
        while (!myStack.empty())
        {
            TreeNode *temp = myStack.top();
            myStack.pop();
            if (temp == NULL)
                return;
            if (temp->right != NULL)
                myStack.push(temp->right);
            if (temp->left != NULL)
                myStack.push(temp->left);
            if (!myStack.empty())
                temp->right = myStack.top();
            temp->left = NULL;
        }
    }
};
// @lc code=end
