/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (50.09%)
 * Likes:    1795
 * Dislikes: 47
 * Total Accepted:    437K
 * Total Submissions: 869.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
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
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
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
/*
对于一棵树， 如果我们要求每一层的节点， 并且存在一个二维数组里， 首先我们要建一个二维数组，
但是这个二维数组建多大的合适呢？ 我们就要求出这颗树的深度， 根据深度来建立二维数组.
2. 题目要求为从左往右添加,所以我们也就是要先放左边的节点， 再放右边的节点.
3. 对于这道题， 我们首先就是要用DFS来求出这颗树的高度， 之后再用DFS对于每一层遍历， 这样节省
了空间复杂度
*/
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        int depth = getHeight(root);
        
        vector<vector<int>> ret(depth);
        if (depth == 0) //invalid check
            return ret;
        getSolution(ret, root, 0);
        return ret;
    }
    int getHeight(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        return (left > right ? left : right) + 1;
    }
    void getSolution(vector<vector<int>> &ret, TreeNode *root, int level)
    {
        if (root == NULL)
            return;
        ret[level].push_back(root->val);
        getSolution(ret, root->left, level + 1);
        getSolution(ret, root->right, level + 1);
    }
};
