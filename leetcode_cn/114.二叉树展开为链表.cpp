/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 *
 * https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (57.87%)
 * Total Accepted:    5.4K
 * Total Submissions: 9.2K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * 给定一个二叉树，原地将它展开为链表。
 * 
 * 例如，给定二叉树
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 将其展开为：
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
