/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (42.52%)
 * Total Accepted:    315.6K
 * Total Submissions: 731.1K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        if (nums.size() <= 2)
            return -1;
        int res;
        int dis = 123123123;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                int temp_sum = nums[i] + nums[j] + nums[k];
                if (temp_sum < target)
                {
                    if (target - temp_sum < dis)
                    {
                        dis = target - temp_sum;
                        res = temp_sum;
                    }
                    j++;
                }
                else if (temp_sum > target)
                {
                    if (temp_sum - target < dis)
                    {
                        dis = temp_sum - target;
                        res = temp_sum;
                    }
                    k--;
                }
                else
                {
                    return temp_sum;
                }
            }
        }
        return res;
    }
};
