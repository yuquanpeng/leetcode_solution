/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 *
 * https://leetcode.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (50.66%)
 * Likes:    2581
 * Dislikes: 78
 * Total Accepted:    412.1K
 * Total Submissions: 801.8K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * Given a set of candidate numbers (candidates) (without duplicates) and a
 * target number (target), find all unique combinations in candidates where the
 * candidate numbers sums to target.
 * 
 * The same repeated number may be chosen from candidates unlimited number of
 * times.
 * 
 * Note:
 * 
 * 
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: candidates = [2,3,6,7], target = 7,
 * A solution set is:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 */
/*
题目翻译: 给一个数组C和一个目标值T, 找出所有的满足条件的组合： 使得组合里面的数字之和等于T,并且
一些数字可以从C中午先选择。
注意:
1. 所有给定的数字均为正整数.(这意味着我们加corner case invalid check的时候要加一条， 如果给定T不
是正整数， 我们就没必要在往下进行了)
2. 所有的答案组中要满足升序排列.
3. 最后的答案数组不能包含重复答案.
题目分析: 这道题的大体思路和combination是相同的， 不同的地方在于一个数字可以使用多次， 这也造成
了我们进行实现function的时候要注意的问题， 也就是说， 传入递归的参数不同于combination.
*/

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        if (candidates.size() == 0 || target < 0)
            return res;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        BackTracking(res, curr, candidates, target, 0);
        return res;
    }
    void BackTracking(vector<vector<int>> &res, vector<int> curr, vector<int> candidates, int target, int level)
    {
        if (target == 0)
        {
            res.push_back(curr);
            return;
        }
        else if (target < 0)
            return;

        for (int i = level; i < candidates.size(); ++i)
        {
            target -= candidates[i];
            curr.push_back(candidates[i]);
            BackTracking(res, curr, candidates, target, i);
            curr.pop_back();
            target += candidates[i];
        }
    }
};
// @lc code=end
