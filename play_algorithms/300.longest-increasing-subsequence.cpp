/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (40.43%)
 * Total Accepted:    208.7K
 * Total Submissions: 515.4K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 * 
 * Example:
 * 
 * 
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4 
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4. 
 * 
 * Note: 
 * 
 * 
 * There may be more than one LIS combination, it is only necessary for you to
 * return the length.
 * Your algorithm should run in O(n^2) complexity.
 * 
 * 
 * Follow up: Could you improve it to O(n log n) time complexity?
 * 
 */
class Solution
{
  public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        vector<int> memo(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++)
            for (int j = 0; j < i; j++)
                if (nums[j] < nums[i])
                    memo[i] = max(memo[i], 1 + memo[j]);
        int res = 1;
        for (int i = 0; i < nums.size(); i++)
            res = max(res, memo[i]);
        return res;
    }
};
