/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
 *
 * https://leetcode.com/problems/path-sum-iii/description/
 *
 * algorithms
 * Easy (42.28%)
 * Total Accepted:    98.5K
 * Total Submissions: 232.8K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * You are given a binary tree in which each node contains an integer value.
 * 
 * Find the number of paths that sum to a given value.
 * 
 * The path does not need to start or end at the root or a leaf, but it must go
 * downwards
 * (traveling only from parent nodes to child nodes).
 * 
 * The tree has no more than 1,000 nodes and the values are in the range
 * -1,000,000 to 1,000,000.
 * 
 * Example:
 * 
 * root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 * 
 * ⁠     10
 * ⁠    /  \
 * ⁠   5   -3
 * ⁠  / \    \
 * ⁠ 3   2   11
 * ⁠/ \   \
 * 3  -2   1
 * 
 * Return 3. The paths that sum to 8 are:
 * 
 * 1.  5 -> 3
 * 2.  5 -> 2 -> 1
 * 3. -3 -> 11
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
    //在以root为根节点的二叉树中，寻找和为sum的 路径，返回这样的路径个数
    int pathSum(TreeNode *root, int sum)
    {
        if (root == NULL)
            return 0;
        int res = findPath(root, sum);
        res += pathSum(root->left, sum);
        res += pathSum(root->right, sum);
        return res;
    }

  private:
    //在以node为根节点的二叉树中，寻找包含node的路径和为sum
    int findPath(TreeNode *node, int num)
    {
        if (node == NULL)
            return 0;
        int res = 0;
        if (node->val == num)
            res += 1;
        res += findPath(node->left, num - node->val);
        res += findPath(node->right, num - node->val);
        return res;
    }
};
