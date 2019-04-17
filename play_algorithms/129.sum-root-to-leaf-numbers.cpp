/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
 *
 * https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
 *
 * algorithms
 * Medium (41.87%)
 * Total Accepted:    179.7K
 * Total Submissions: 427.5K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path
 * could represent a number.
 * 
 * An example is the root-to-leaf path 1->2->3 which represents the number
 * 123.
 * 
 * Find the total sum of all root-to-leaf numbers.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * Output: 25
 * Explanation:
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 * Therefore, sum = 12 + 13 = 25.
 * 
 * Example 2:
 * 
 * 
 * Input: [4,9,0,5,1]
 * ⁠   4
 * ⁠  / \
 * ⁠ 9   0
 * / \
 * 5   1
 * Output: 1026
 * Explanation:
 * The root-to-leaf path 4->9->5 represents the number 495.
 * The root-to-leaf path 4->9->1 represents the number 491.
 * The root-to-leaf path 4->0 represents the number 40.
 * Therefore, sum = 495 + 491 + 40 = 1026.
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
 * 从根节点到叶节点的遍历方法是深度优先搜索(DFS)。 解决本题只需在遍历过程中记录路径中的
数字， 在到达叶节点的时候把记录下来的数字转换成数值， 加到和里面即可。
 */
class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        vector<int> arr;
        int sum = 0;
        dfs(root, arr, sum);
        return sum;
    }
    int vec2num(vector<int> &vec)
    {
        int num = 0;
        for (int i = 0; i < vec.size(); i++)
            num = num * 10 + vec[i];
        return num;
    }
    void dfs(TreeNode *node, vector<int> &arr, int &sum)
    {
        if (node == NULL)
            return;
        arr.push_back(node->val);
        if (node->left == NULL && node->right == NULL)
            sum += vec2num(arr);
        else
        {
            if (node->left != NULL)
                dfs(node->left, arr, sum);
            if (node->right != NULL)
                dfs(node->right, arr, sum);
        }
        arr.pop_back();
    }
};
