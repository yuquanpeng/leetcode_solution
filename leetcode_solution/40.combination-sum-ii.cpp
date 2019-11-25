/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (43.41%)
 * Likes:    1189
 * Dislikes: 51
 * Total Accepted:    265.5K
 * Total Submissions: 598.1K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sums to target.
 * 
 * Each number in candidates may only be used once in the combination.
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
 * Input: candidates = [10,1,2,7,6,1,5], target = 8,
 * A solution set is:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: candidates = [2,5,2,1,2], target = 5,
 * A solution set is:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
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
            BackTracking(res, curr, candidates, target, i + 1);
            curr.pop_back();
            target += candidates[i];
            while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1])
                ++i;
        }
    }
};
// @lc code=end
