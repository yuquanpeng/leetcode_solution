/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (36.95%)
 * Likes:    1524
 * Dislikes: 128
 * Total Accepted:    156.6K
 * Total Submissions: 419.7K
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
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
class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    {
        vector<TreeNode *> vs;
        if (n == 0)
            return vs;
        return generate(1, n);
    }

    vector<TreeNode *> generate(int start, int stop)
    {
        vector<TreeNode *> vs;
        if (start > stop)
        {
            vs.push_back(NULL);
            return vs;
        }
        for (int i = start; i <= stop; i++)
        {
            auto l = generate(start, i - 1);
            auto r = generate(i + 1, stop);

            //获取左子树和右子树所有排列后 放到root为i的节点下面
            for (int j = 0; j < l.size(); j++)
                for (int k = 0; k < r.size(); k++)
                {
                    TreeNode *n = new TreeNode(i);
                    n->left = l[j];
                    n->right = r[k];
                    vs.push_back(n);
                }
        }
        return vs;
    }
};
// @lc code=end
