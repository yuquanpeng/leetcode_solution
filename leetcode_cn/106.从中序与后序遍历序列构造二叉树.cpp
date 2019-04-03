/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (58.28%)
 * Total Accepted:    5.9K
 * Total Submissions: 10K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 * 
 * 返回如下的二叉树：
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
