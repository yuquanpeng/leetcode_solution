/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (43.19%)
 * Likes:    1203
 * Dislikes: 72
 * Total Accepted:    255.6K
 * Total Submissions: 589.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
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
    vector<vector<int>> vals;
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        build(root, 1);
        for (int i = 1; i < vals.size(); i += 2)
            reverse(vals[i].begin(), vals[i].end());
        return vals;
    }
    void build(TreeNode *node, int level)
    {
        if (node == NULL)
            return;
        if (vals.size() <= level - 1)
            vals.push_back(vector<int>());

        vals[level - 1].push_back(node->val);
        
        if (node->left)
            build(node->left, level + 1);
        if (node->right)
            build(node->right, level + 1);
    }
};
