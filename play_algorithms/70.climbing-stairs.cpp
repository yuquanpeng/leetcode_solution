/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 *
 * https://leetcode.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (43.80%)
 * Total Accepted:    379.7K
 * Total Submissions: 866.3K
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
class Solution
{
  private:
    // vector<int> memo;
    // int calcWay(int n)
    // {
    //     if (n == 0)
    //         return 1;
    //     if (n == 1)
    //         return 1;
    //     // if (n == 2)
    //     //     return 2;
    //     if (memo[n] == -1)
    //         memo[n] = calcWay(n - 1) + calcWay(n - 2);
    //     return memo[n];
    // }

  public:
    int climbStairs(int n)
    {
        vector<int> memo;
        memo = vector<int>(n + 1, -1);
        memo[0] = 1;
        memo[1] = 1;
        for (int i = 2; i <= n; i++)
            memo[i] = memo[i - 1] + memo[i - 2];
        return memo[n];
    }
};