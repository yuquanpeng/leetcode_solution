/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (41.02%)
 * Total Accepted:    208.1K
 * Total Submissions: 505.5K
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        int depth = getHeight(root);
        vector<vector<int>> ret(depth);
        if (depth == 0)
            return ret;
        getRet(ret, root, 0);

        for (int i = 1; i <= depth - 1; i += 2) //对固定层转换方向
            reverse(ret[i].begin(), ret[i].end());

        return ret;
    }
    int getHeight(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        int height = (left > right ? left : right) + 1;
        return height;
    }
    void getRet(vector<vector<int>> &ret, TreeNode *root, int level)
    {
        if (root == NULL)
            return;
        ret[level].push_back(root->val);
        getRet(ret, root->left, level + 1);
        getRet(ret, root->right, level + 1);
    }
};
