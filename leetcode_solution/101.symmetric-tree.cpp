/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (44.37%)
 * Likes:    2665
 * Dislikes: 59
 * Total Accepted:    466.7K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3] is not:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
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
    bool isSymmetric(TreeNode *root)
    {
        // if (root == NULL)
        //     return true;
        // return Helper(root->left, root->right);
        if (root == NULL)
            return true;
        TreeNode *n1 = root->left;
        TreeNode *n2 = root->right;
        if (n1 == NULL && n2 == NULL)
            return true;
        if ((n1 == NULL && n2 != NULL) || (n1 != NULL && n2 == NULL))
            return false;
        queue<TreeNode *> Q1;
        queue<TreeNode *> Q2;
        Q1.push(n1);
        Q2.push(n2);
        while (!Q1.empty() && !Q2.empty())
        {
            TreeNode *tmp1 = Q1.front();
            TreeNode *tmp2 = Q2.front();
            Q1.pop();
            Q2.pop();
            if ((!tmp1 && tmp2) || (tmp1 && !tmp2))
                return false;
            if (tmp1 && tmp2)
            {
                if (tmp1->val != tmp2->val)
                    return false;
                Q1.push(tmp1->left);
                Q1.push(tmp1->right); //note: this line we should put the mirror sequence in two queu
                Q2.push(tmp2->right);
                Q2.push(tmp2->left);
            }
        }
        return true;
    }
    // bool Helper(TreeNode *left, TreeNode *right)
    // {
    //     if (left == NULL && right == NULL)
    //         return true;
    //     else if (left == NULL || right == NULL)
    //         return false;
    //     bool cond1 = left->val == right->val;
    //     bool cond2 = Helper(left->left, right->right);
    //     bool cond3 = Helper(left->right, right->left);
    //     return cond1 && cond2 && cond3;
    // }
};
