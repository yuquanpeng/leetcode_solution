/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (44.54%)
 * Likes:    5317
 * Dislikes: 215
 * Total Accepted:    662.3K
 * Total Submissions: 1.5M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;
        int m = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            m = max(m, sum);
            //如果sum小于0了， 将sum重置为0， 从i + 1再次开始计算
            if (sum < 0)
                sum = 0;
        }
        return m;
    }
};
// @lc code=end
