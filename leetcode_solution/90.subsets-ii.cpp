/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (43.66%)
 * Likes:    1187
 * Dislikes: 55
 * Total Accepted:    235.7K
 * Total Submissions: 530.5K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        if (nums.empty())
            return res;
        sort(nums.begin(), nums.end());
        res.push_back(vector<int>());
        vector<int> curr;
        generate(0, curr, nums);
        return res;
    }
    void generate(int start, vector<int> &curr, vector<int> &nums)
    {
        if (start == nums.size())
            return;
        for (int i = start; i < nums.size(); i++)
        {
            curr.push_back(nums[i]);
            res.push_back(curr);
            generate(i + 1, curr, nums);
            curr.pop_back();
            while (i < nums.size() - 1 && nums[i] == nums[i + 1])
                i++;
        }
    }
};
// @lc code=end
