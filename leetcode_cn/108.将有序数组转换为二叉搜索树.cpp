/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/description/
 *
 * algorithms
 * Easy (61.19%)
 * Total Accepted:    15.6K
 * Total Submissions: 25.2K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定有序数组: [-10,-3,0,5,9],
 * 
 * 一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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
    TreeNode *sortedArrayToBST(vector<int> &num)
    {
        return build(num, 0, num.size());
    }
    TreeNode *build(vector<int> &num, int start, int end)
    {
        if (start >= end)
            return NULL;

        int mid = start + (end - start) / 2;     //找到根节点
        TreeNode *node = new TreeNode(num[mid]); //建立根节点
        node->left = build(num, start, mid);     //递归建立左子树
        node->right = build(num, mid + 1, end);  //递归建立右子
        return node;
    }
};
