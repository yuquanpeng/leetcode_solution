/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (54.17%)
 * Total Accepted:    357.8K
 * Total Submissions: 659.7K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
class Solution
{

  private:
    vector<vector<int>> res;
    vector<bool> used;
    void generatePermute(const vector<int> &nums, int index, vector<int> &p)
    {
        if (index == nums.size())
        {
            res.push_back(p);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (!used[i])
            {
                p.push_back(nums[i]);
                used[i] = true;
                generatePermute(nums, index + 1, p);
                p.pop_back();
                used[i] = false;
            }
        }
        return;
    }

  public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        res.clear();
        if (nums.size() == 0)
            return res;
        used = vector<bool>(nums.size(), false);
        vector<int> p;
        generatePermute(nums, 0, p);
        return res;
    }
};
