/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (52.54%)
 * Likes:    938
 * Dislikes: 45
 * Total Accepted:    380.2K
 * Total Submissions: 721.6K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,2,3]
 * 
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (root == NULL)
            return res;

        vector<TreeNode *> nodes;
        nodes.push_back(root);
        while (!nodes.empty())
        {
            TreeNode *n = nodes.back();
            res.push_back(n->val);
            nodes.pop_back();
            if (n->right)
                nodes.push_back(n->right);
            if (n->left)
                nodes.push_back(n->left);
        }
        return res;
    }
};
// @lc code=end
