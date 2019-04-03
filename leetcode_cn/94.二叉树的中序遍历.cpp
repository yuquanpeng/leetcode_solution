/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (64.38%)
 * Total Accepted:    25.3K
 * Total Submissions: 39.1K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的中序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 输出: [1,3,2]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> vals;
        if (root == NULL)
            return vals;
        vector<TreeNode *> nodes;
        TreeNode *p = root;
        while (p || !nodes.empty())
        {
            while (p)
            {
                nodes.push_back(p);
                p = p->left;
            }
            if (!nodes.empty())
            {
                p = nodes.back();
                vals.push_back(p->val);
                nodes.pop_back();
                p = p->right;
            }
        }
        return vals;
    }
};
