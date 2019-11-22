/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (45.05%)
 * Likes:    2783
 * Dislikes: 98
 * Total Accepted:    493.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '2'
 *
 * You are climbing a stair case. It takes n steps to reach to the top.
 * 
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can
 * you climb to the top?
 * 
 * Note: Given n will be a positive integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: 2
 * Explanation: There are two ways to climb to the top.
 * 1. 1 step + 1 step
 * 2. 2 steps
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 3
 * Output: 3
 * Explanation: There are three ways to climb to the top.
 * 1. 1 step + 1 step + 1 step
 * 2. 1 step + 2 steps
 * 3. 2 steps + 1 step
 * 
 * 
 */
/*
这道题目其实就是斐波那契数列问题， 题目比较简单， 我们很容易就能列出dp方程
dp[n] = dp[n-1]+dp[n-2]
*/
// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        int n1 = 1;
        int n2 = 2;
        if (n == 1)
            return n1;
        else if (n == 2)
            return n2;
        int n_n;
        for (int i = 3; i <= n; i++)
        {
            n_n = n1 + n2;
            n1 = n2;
            n2 = n_n;
        }
        return n_n;
    }
};
// @lc code=end
