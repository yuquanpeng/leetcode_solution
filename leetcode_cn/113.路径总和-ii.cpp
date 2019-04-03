/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 *
 * https://leetcode-cn.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (52.41%)
 * Total Accepted:    7.1K
 * Total Submissions: 13.3K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 * 
 * 
 * 返回:
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
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
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector<int>> ret;
        if (root == NULL)
            return ret;
        vector<int> cur;
        DFS(ret, cur, sum, 0, root);
        return ret;
    }
    void DFS(vector<vector<int>> &ret, vector<int> cur, int sum, int tmpsum, TreeNode *root)
    {
        if (root == NULL)
            return;
        tmpsum += root->val;
        cur.push_back(root->val);
        if (tmpsum == sum)
            if (root->left == NULL && root->right == NULL)
            {
                ret.push_back(cur);
                return;
            }

        DFS(ret, cur, sum, tmpsum, root->left);
        DFS(ret, cur, sum, tmpsum, root->right);
    }
};
