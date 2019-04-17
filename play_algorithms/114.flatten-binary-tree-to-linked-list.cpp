/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 *
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (41.65%)
 * Total Accepted:    229.6K
 * Total Submissions: 549.2K
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    //使用栈
    void flatten(TreeNode *root)
    {
        stack<TreeNode *> myStack;

        myStack.push(root);

        while (!myStack.empty())
        {
            TreeNode *temp = myStack.top();
            myStack.pop();

            if (temp == NULL) //循环结束条件
                return;

            if (temp->right != NULL) //右边进
                myStack.push(temp->right);
            if (temp->left != NULL) //左边进
                myStack.push(temp->left);

            if (!myStack.empty()) //取出下一个结点
                temp->right = myStack.top();

            temp->left = NULL;
        }
    }
};
