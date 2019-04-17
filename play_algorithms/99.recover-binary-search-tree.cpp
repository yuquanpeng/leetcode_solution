/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
 *
 * https://leetcode.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Hard (34.18%)
 * Total Accepted:    114.6K
 * Total Submissions: 334.5K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * Two elements of a binary search tree (BST) are swapped by mistake.
 * 
 * Recover the tree without changing its structure.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,null,null,2]
 * 
 * 1
 * /
 * 3
 * \
 * 2
 * 
 * Output: [3,1,null,null,2]
 * 
 * 3
 * /
 * 1
 * \
 * 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,1,4,null,null,2]
 * 
 * ⁠ 3
 * ⁠/ \
 * 1   4
 * /
 * 2
 * 
 * Output: [2,1,4,null,null,3]
 * 
 * ⁠ 2
 * ⁠/ \
 * 1   4
 * /
 * ⁠ 3
 * 
 * 
 * Follow up:
 * 
 * 
 * A solution using O(n) space is pretty straight forward.
 * Could you devise a constant space solution?
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
 * 这题需要修复一颗二叉搜索树的两个交换节点数据， 我们知道对于一颗二叉搜索树来说， 如果按照中序遍
历， 那么它输出的值是递增有序的， 所以我们只需要按照中序遍历输出， 在输出结果里面找到两个异常数
据（比它后面输出结果大） ， 交换这两个节点的数据就可以了。

但是这题要求使用O(1)的空间， 如果采用通常的中序遍历（递归或者栈） 的方式， 都需要O(N)的空间， 所
以这里我们用Morris Traversal的方式来进行树的中序遍历。
Morris Traversal中序遍历的原理比较简单：


重复上述过程， 直到当前节点为空， 递归的时候我们同时需要记录错误的节点。 那么我们如何知道一个节
点的数据是不是有问题呢？ 对于中序遍历来说， 假设当前节点为cur， 它的前驱节点为pre， 如果cur的值小
于pre的值， 那么cur和pre里面的数据就是交换的了
 */
// class Solution
// {
// public:
//     void recoverTree(TreeNode *root)
//     {
//         TreeNode *cur = NULL;
//         TreeNode *pre = NULL;
//         TreeNode *p1 = NULL;
//         TreeNode *p2 = NULL;
//         TreeNode *preCur = NULL;
//         bool found = false;
//         if (root == NULL)
//             return;

//         cur = root;
//         while (cur)
//         {
//             //如果当前节点的左孩子为空， 则输出当前节点并将其有孩子作为当前节点。
//             if (cur->left == NULL)
//             {
//                 //记录p1 和 p2
//                 if (preCur && preCur->val > cur->val)
//                 {
//                     if (!found)
//                     {
//                         p1 = preCur;
//                         found = true;
//                     }
//                     p2 = cur;
//                 }
//                 preCur = cur;
//                 cur = cur->right;
//             } //如果当前节点的左孩子不为空， 在当前节点的左子树中找到当前节点在中序遍历下的前驱节点， 也就
//             //是当前节点左子树的最右边的那个节点。
//             else
//             {
//                 pre = cur->left;
//                 while (pre->right && pre->right != cur)
//                 {
//                     pre = pre->right;
//                 }
//                 //如果前驱节点的右孩子为空， 则将它的右孩子设置为当前节点， 当前节点更新为其左孩子。
//                 if (pre->right == NULL)
//                 {
//                     pre->right = cur;
//                     cur = pre->left;
//                 }
//                 // 如果前驱节点的右孩子为当前节点， 则将前驱节点的右孩子设为空， 输出当前节点， 当前节点更
//                 // 新为其右孩子。
//                 else
//                 {
//                     if (preCur->val > cur->val)
//                     {
//                         if (!found)
//                         {
//                             p1 = preCur;
//                             found = true;
//                         }
//                         p2 = cur;
//                     }
//                     preCur = cur;
//                     pre->right = NULL;
//                     cur = cur->right;
//                 }
//             }
//         }
//         if (p1 && p2)
//         {
//             int t = p1->val;
//             p1->val = p2->val;
//             p2->val = t;
//         }
//     }
// };
class Solution
{
public:
    void recoverTree(TreeNode *root)
    {
        TreeNode *first = NULL, *second = NULL, *parent = NULL;
        TreeNode *cur, *pre;
        cur = root;
        while (cur)
        {
            if (!cur->left)
            {
                if (parent && parent->val > cur->val)
                {
                    if (!first)
                        first = parent;
                    second = cur;
                }
                parent = cur;
                cur = cur->right;
            }
            else
            {
                pre = cur->left;
                while (pre->right && pre->right != cur)
                    pre = pre->right;
                if (!pre->right)
                {
                    pre->right = cur;
                    cur = cur->left;
                }
                else
                {
                    pre->right = NULL;
                    if (parent->val > cur->val)
                    {
                        if (!first)
                            first = parent;
                        second = cur;
                    }
                    parent = cur;
                    cur = cur->right;
                }
            }
        }
        swap(first->val, second->val);
    }
};
