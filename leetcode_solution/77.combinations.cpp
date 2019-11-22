/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (49.71%)
 * Likes:    981
 * Dislikes: 57
 * Total Accepted:    234.6K
 * Total Submissions: 465.8K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 */

/*
题目分析: 我觉得应该还有不少读者困惑什么是combination， 这里我们先给一个例子比如n=3， k=2的条件
下， 所有可能的combination如下： [1,2], [1,3], [2,3]. 注意： [2,3]和[3,2]是相同的， 我们只要求有其中一个
就可以了. 所以解题的时候， 我们要避免相同的组合出现.
解题思路: 看到这道题， 首先第一想法应该是用递归来求解.如果要是用循环来求解， 这个时间复杂度应该
是比较恐怖了.并且， 这个递归是一层一层往深处去走的， 打个比方， 我们一个循环， 首先求得以1开始的
看个数的combination， 之后再求以2开始的， 以此类推， 所以开始是对n个数做DFS, n-1个数做DFS...所以
应该是对n(n-1)...*1做DFS. 在程序中， 我们可以加一些剪枝条件来减少程序时间
*/
// @lc code=start
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ret;
        if (n <= 0)
            return ret;
        vector<int> curr;
        DFS(ret, curr, n, k, 1);
        return ret;
    }
    void DFS(vector<vector<int>> &ret, vector<int> curr, int n, int k, int level)
    {
        if (curr.size() == k)
        {
            ret.push_back(curr);
            return;
        }
        if (curr.size() > k)
            return;
        for (int i = level; i <= n; ++i)
        {
            curr.push_back(i);
            DFS(ret, curr, n, k, i + 1);
            curr.pop_back();
        }
    }
};
// @lc code=end
