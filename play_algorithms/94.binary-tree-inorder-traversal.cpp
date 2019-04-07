/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (55.76%)
 * Total Accepted:    433K
 * Total Submissions: 776.2K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,3,2]
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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
struct Commond
{
    string s;
    TreeNode *node;
    Commond(string s, TreeNode *node) : s(s), node(node) {}
};
class Solution
{
  public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (root == NULL)
            return res;

        stack<Commond> stack;
        stack.push(Commond("go", root));
        while (!stack.empty())
        {
            Commond commond = stack.top();
            stack.pop();

            if (commond.s == "print")
                res.push_back(commond.node->val);
            else
            {
                assert(commond.s == "go");
                if (commond.node->right)
                    stack.push(Commond("go", commond.node->right));
                stack.push(Commond("print", commond.node));
                if (commond.node->left)
                    stack.push(Commond("go", commond.node->left));
            }
        }
        return res;
    }
};
