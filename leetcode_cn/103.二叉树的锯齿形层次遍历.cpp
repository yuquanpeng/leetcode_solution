/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (47.12%)
 * Total Accepted:    8.4K
 * Total Submissions: 17.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回锯齿形层次遍历如下：
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

        for (int i = 1; i <= depth - 1; i += 2)
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
