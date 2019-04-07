/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (47.59%)
 * Total Accepted:    246.8K
 * Total Submissions: 518.5K
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
    vector<int> postorderTraversal(TreeNode *root)
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
                stack.push(Commond("print", commond.node));

                if (commond.node->right)
                    stack.push(Commond("go", commond.node->right));
                if (commond.node->left)
                    stack.push(Commond("go", commond.node->left));
            }
        }
        return res;
    }
};
