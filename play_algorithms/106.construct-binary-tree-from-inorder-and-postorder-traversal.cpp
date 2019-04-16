/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (38.52%)
 * Total Accepted:    147.4K
 * Total Submissions: 381.1K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
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
    unordered_map<int, int> map;
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.empty() || postorder.empty())
            return NULL;
        for (int i = 0; i < inorder.size(); i++)
            map[inorder[i]] = i;

        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    TreeNode *build(vector<int> &in, int ins, int ine, vector<int> &post, int posts, int poste)
    {
        if (ins > ine || posts > poste)
            return NULL;

        TreeNode *root = new TreeNode(post[poste]);

        int root_index = map[post[poste]];
        int left_num = root_index - ins;

        root->left = build(in, ins, root_index - 1, post, posts, posts + left_num - 1);
        root->right = build(in, root_index + 1, ine, post, posts + left_num, poste - 1);
        return root;
    }
};
