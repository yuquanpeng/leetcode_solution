/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (45.39%)
 * Total Accepted:    217.1K
 * Total Submissions: 478K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * Output: ["1->2->5", "1->3"]
 * 
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> res;
        if (root == NULL)
            return res;

        if (root->left == NULL && root->right == NULL)
        {
            res.push_back(to_string(root->val));
            return res;
        }
        vector<string> left = binaryTreePaths(root->left);
        for (int i = 0; i < left.size(); i++)
            res.push_back(to_string(root->val) + "->" + left[i]);

        vector<string> right = binaryTreePaths(root->right);
        for (int i = 0; i < right.size(); i++)
            res.push_back(to_string(root->val) + "->" + right[i]);
        return res;
    }
};
