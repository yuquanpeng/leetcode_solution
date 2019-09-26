/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (43.10%)
 * Likes:    2093
 * Dislikes: 58
 * Total Accepted:    257.6K
 * Total Submissions: 595K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    unordered_map<int, int> m;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.empty())
            return NULL;
        for (int i = 0; i < inorder.size(); i++)
            m[inorder[i]] = i;
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode *build(vector<int> &preorder, int s0, int e0,
                    vector<int> &inorder, int s1, int e1)
    {
        if (s0 > e0 || s1 > e1)
            return NULL;
        int mid = m[preorder[s0]];
        TreeNode *root = new TreeNode(preorder[s0]);
        int num = mid - s1;
        root->left = build(preorder, s0 + 1, s0 + num, inorder, s1, mid - 1);
        root->right = build(preorder, s0 + num + 1, e0, inorder, mid + 1, e1);
        return root;
    }
};
