/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 *
 * https://leetcode.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (47.50%)
 * Total Accepted:    76.4K
 * Total Submissions: 160.7K
 * Testcase Example:  '2'
 *
 * Given a positive integer n, break it into the sum of at least two positive
 * integers and maximize the product of those integers. Return the maximum
 * product you can get.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: 2
 * Output: 1
 * Explanation: 2 = 1 + 1, 1 × 1 = 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 10
 * Output: 36
 * Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 * 
 * Note: You may assume that n is not less than 2 and not larger than 58.
 * 
 * 
 */
// class Solution
// {
//   private:
//     vector<int> memo;
//     int max3(int a, int b, int c)
//     {
//         return max(a, max(b, c));
//     }
//     int breakInt(int n)
//     {
//         if (n == 1)
//             return 1;
//         if (memo[n] != -1)
//             return memo[n];

//         int res = -1;
//         for (int i = 1; i <= n - 1; i++)
//             res = max3(i * breakInt(n - 1), res, i * (n - i));
//         memo[n] = res;

//         return res;
//     }

//   public:
//     int integerBreak(int n)
//     {
//         assert(n >= 2);
//         memo = vector<int>(n + 1, -1);
//         return breakInt(n);
//     }
// };
class Solution
{
  private:
    int max3(int a, int b, int c)
    {
        return max(a, max(b, c));
    }

  public:
    int integerBreak(int n)
    {
        assert(n >= 2);
        vector<int> memo;

        memo = vector<int>(n + 1, -1);
        memo[1] = 1;
        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= i - 1; j++)
                memo[i] = max3(j * (i - j), j * memo[i - j], memo[i]);
        return memo[n];
    }
};
