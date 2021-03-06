/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber/description/
 *
 * algorithms
 * Easy (40.88%)
 * Total Accepted:    304.9K
 * Total Submissions: 746K
 * Testcase Example:  '[1,2,3,1]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security system
 * connected and it will automatically contact the police if two adjacent
 * houses were broken into on the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money =
 * 3).
 * Total amount you can rob = 1 + 3 = 4.
 * 
 * Example 2:
 * 
 * 
 * Input: [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house
 * 5 (money = 1).
 * Total amount you can rob = 2 + 9 + 1 = 12.
 * 
 * 
 */
// class Solution
// {
//   private:
//     vector<int> memo;
//     int tryRob(vector<int> &nums, int index)
//     {
//         if (index >= nums.size())
//             return 0;
//         if (memo[index] != -1)
//             return memo[index];
//         int res = 0;
//         for (int i = index; i < nums.size(); i++)
//             nums[i] = max(tryRob(nums, i + 2), res);
//         memo[index] = res;
//         return res;
//     }

//   public:
//     int rob(vector<int> &nums)
//     {
//         memo = vector<int>(nums.size() + 1, -1);
//         return tryRob(nums, 0);
//     }
// };
class Solution
{
  public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> memo;
        memo = vector<int>(n, -1);
        memo[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--)
            for (int j = i; j < n; j++)
                memo[i] = max(memo[i],
                              nums[j] + (j + 2 < n ? memo[j + 2] : 0));
        return memo[0];
    }
};
