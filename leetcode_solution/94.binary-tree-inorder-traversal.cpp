/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (58.42%)
 * Likes:    1983
 * Dislikes: 89
 * Total Accepted:    535.6K
 * Total Submissions: 913K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,3,2]
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> vals;
        if (root == NULL)
            return vals;
        vector<TreeNode *> nodes;
        TreeNode *p = root;
        while (p || !nodes.empty())
        {
            while (p)
            {
                nodes.push_back(p);
                p = p->left;
            }
            if (!nodes.empty())
            {
                p = nodes.back();
                vals.push_back(p->val);
                nodes.pop_back();
                p = p->right;
            }
        }
        return vals;
    }
};
// @lc code=end
