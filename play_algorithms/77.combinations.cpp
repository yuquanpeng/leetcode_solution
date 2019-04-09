/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (46.71%)
 * Total Accepted:    193.2K
 * Total Submissions: 413.1K
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
class Solution
{
  private:
    vector<vector<int>> res;

    void generateCombine(int n, int k, int start, vector<int> &c)
    {
        if (c.size() == k)
        {
            res.push_back(c);
            return;
        }
        //尝试剪枝
        //还有k-c.size()个空位，所以[i...n]中至少要有k-c.size()个元素
        //i最多为n-(k-c.size())+1
        for (int i = start; i <= n - (k - c.size()) + 1; i++)
        {
            c.push_back(i);
            generateCombine(n, k, i + 1, c);
            c.pop_back();
        }
        return;
    }

  public:
    vector<vector<int>> combine(int n, int k)
    {
        res.clear();
        if (n <= 0 || k <= 0)
            return res;
        vector<int> c;
        generateCombine(n, k, 1, c);
        return res;
    }
};
