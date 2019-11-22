/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (30.00%)
 * Likes:    2633
 * Dislikes: 115
 * Total Accepted:    251.5K
 * Total Submissions: 831.9K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 * 
 */
/*
这题是求数组中子区间的最大乘积， 对于乘法， 我们需要注意， 负数乘以负数， 会变成正数， 所以解这题
的时候我们需要维护两个变量， 当前的最大值， 以及最小值， 最小值可能为负数， 但没准下一步乘以一个
负数， 当前的最大值就变成最小值， 而最小值则变成最大值了。
maxDP[i + 1] = max(maxDP[i] * A[i + 1], A[i + 1], minDP[i] * A[i + 1])
minDP[i + 1] = min(minDP[i] * A[i + 1], A[i + 1], maxDP[i] * A[i + 1]
dp[i + 1] = max(dp[i], maxDP[i + 1])
这里， 我们还需要注意元素为0的情况， 如果A[i]为0， 那么maxDP和minDP都为0， 我们需要从A[i + 1]重新
开始。
*/
// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int m = nums.size();
        if (m == 0)
            return 0;
        else if (m == 1)
            return nums[0];

        int p = nums[0];
        int maxP = nums[0];
        int minP = nums[0];
        for (int i = 1; i < m; i++)
        {
            int premaxP = maxP;                                          //保存上一个maxP
            maxP = max(max(maxP * nums[i], nums[i]), minP * nums[i]);    //如果变大
            minP = min(min(premaxP * nums[i], nums[i]), minP * nums[i]); //如果变小
            p = max(maxP, p);
        }

        return p;
    }
};
// @lc code=end
