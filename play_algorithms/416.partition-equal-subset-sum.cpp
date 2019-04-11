/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (40.16%)
 * Total Accepted:    80.3K
 * Total Submissions: 199.7K
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given a non-empty array containing only positive integers, find if the array
 * can be partitioned into two subsets such that the sum of elements in both
 * subsets is equal.
 * 
 * Note:
 * 
 * 
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1, 5, 11, 5]
 * 
 * Output: true
 * 
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1, 2, 3, 5]
 * 
 * Output: false
 * 
 * Explanation: The array cannot be partitioned into equal sum subsets.
 * 
 * 
 * 
 * 
 */
class Solution
{
  private:
    //memo[i][c] 表示使用索引为[0..i]的这些元素，是否可以完全填充一个容量为c的背包
    //-1 表示未被计算 0表示不可以  1表示可以
    vector<vector<int>> memo;
    bool tryPartition(const vector<int> &nums, int index, int sum)
    {
        if (sum == 0)
            return true;
        if (sum <= 0 || index < 0)
            return false;
        if (memo[index][sum] != -1)
            return memo[index][sum];

        memo[index][sum] = (tryPartition(nums, index - 1, sum) || tryPartition(nums, index - 1, sum - nums[index]));
        return memo[index][sum];
    }

  public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum % 2 != 0)
            return false;
        // memo = vector<vector<int>>(nums.size(), vector<int>(sum / 2 + 1, -1));
        // return tryPartition(nums, nums.size() - 1, sum / 2);
        int n = nums.size();
        int c = sum / 2;
        vector<bool> memo2(c + 1, false);
        for (int i = 0; i <= c; i++)
            memo2[i] = (nums[0] == i);

        for (int i = 1; i < n; i++)
            for (int j = c; j >= nums[i]; j--)
                memo2[j] = memo2[j] || memo2[j - nums[i]];
        return memo2[c];
    }
};
