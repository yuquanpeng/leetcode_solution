/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (50.75%)
 * Total Accepted:    319.9K
 * Total Submissions: 630.3K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the preorder traversal of its nodes' values.
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
 * Output: [1,2,3]
 * 
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
    vector<int> preorderTraversal(TreeNode *root)
    {
        // vector<int> ret;
        // preorderTraversal(root, ret);
        // return ret;
        //非递归
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
                if (commond.node->left)
                    stack.push(Commond("go", commond.node->left));
                stack.push(Commond("print", commond.node));
            }
        }
        return res;
    }
    // void preorderTraversal(TreeNode *root, vector<int> &ret)
    // {
    //     if (root)
    //     {
    //         ret.push_back(root->val);
    //         preorderTraversal(root->left, ret);
    //         preorderTraversal(root->right, ret);
    //     }
    // }
};
