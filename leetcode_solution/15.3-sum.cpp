/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.74%)
 * Likes:    4506
 * Dislikes: 516
 * Total Accepted:    645.5K
 * Total Submissions: 2.6M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        if (nums.size() <= 2)
            return res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                vector<int> curr;
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    curr.push_back(nums[i]);
                    curr.push_back(nums[j]);
                    curr.push_back(nums[k]);
                    res.push_back(curr);
                    ++j;
                    --k;
                    while (j < k && nums[j - 1] == nums[j])
                        ++j;
                    while (j < k && nums[k] == nums[k + 1])
                        --k;
                }
                else if (nums[i] + nums[j] + nums[k] < 0)
                    ++j;
                else
                    --k;
            }
            while (i < nums.size() - 1 && nums[i] == nums[i + 1])
                ++i;
        }
        return res;
    }
};
