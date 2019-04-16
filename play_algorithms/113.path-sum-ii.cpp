/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
 *
 * https://leetcode.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (39.93%)
 * Total Accepted:    223K
 * Total Submissions: 556.4K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's
 * sum equals the given sum.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given the below binary tree and sum = 22,
 * 
 * 
 * ⁠     5
 * ⁠    / \
 * ⁠   4   8
 * ⁠  /   / \
 * ⁠ 11  13  4
 * ⁠/  \    / \
 * 7    2  5   1
 * 
 * 
 * Return:
 * 
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

