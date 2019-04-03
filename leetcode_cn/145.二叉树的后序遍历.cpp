/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (64.04%)
 * Total Accepted:    13.2K
 * Total Submissions: 20.5K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
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
 * 输出: [3,2,1]
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> vals;
        if (root == NULL)
            return vals;
        vector<TreeNode *> nodes;
        TreeNode *pre = NULL;
        nodes.push_back(root);
        while (!nodes.empty())
        {
            TreeNode *p = nodes.back();
            //如果不判断pre， 我们就没法正确地出栈了
            if ((p->left == NULL && p->right == NULL) ||
                (pre != NULL && (pre == p->left || pre == p->right)))
            {
                vals.push_back(p->val);
                nodes.pop_back();
                pre = p;
            }
            else
            {
                //右子树压栈
                if (p->right != NULL)
                    nodes.push_back(p->right);
                // 左子树压栈
                if (p->left != NULL)
                    nodes.push_back(p->left);
            }
        }
        return vals;
    }
};
