/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (50.17%)
 * Likes:    1124
 * Dislikes: 58
 * Total Accepted:    292.2K
 * Total Submissions: 580K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the postorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [3,2,1]
 * 
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 * 
 */

// @lc code=start
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
对于后序遍历， 首先遍历左子树， 然后是右子树， 最后才是根节点。 当遍历到一个节点的时候， 首先我们
将右子树压栈， 然后将左子树压栈。 这里需要注意一下出栈的规则， 对于叶子节点来说， 直接可以出栈，
但是对于根节点来说， 我们需要一个变量记录上一次出栈的节点， 如果上一次出栈的节点是该根节点的左
子树或者右子树， 那么该根节点可以出栈， 否则这个根节点是新访问的节点， 将右和左子树分别压栈。
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
// @lc code=end
