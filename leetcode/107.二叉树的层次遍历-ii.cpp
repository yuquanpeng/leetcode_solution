/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (59.11%)
 * Total Accepted:    12.2K
 * Total Submissions: 20.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其自底向上的层次遍历为：
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        int depth = getHeight(root);
        vector<vector<int>> ret(depth);
        if (depth == 0)
            return ret;
        getRet(ret, root, depth - 1);
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
        getRet(ret, root->left, level - 1); //从上往下遍历树 但是填表时从下往上填写
        getRet(ret, root->right, level - 1);
    }
};
