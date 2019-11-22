/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (43.04%)
 * Likes:    1788
 * Dislikes: 154
 * Total Accepted:    216.7K
 * Total Submissions: 500.3K
 * Testcase Example:  '12'
 *
 * Given a positive integer n, find the least number of perfect square numbers
 * (for example, 1, 4, 9, 16, ...) which sum to n.
 * 
 * Example 1:
 * 
 * 
 * Input: n = 12
 * Output: 3 
 * Explanation: 12 = 4 + 4 + 4.
 * 
 * Example 2:
 * 
 * 
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 */
/*
从另一个角度来想， 用穷举法来求解就是把不大于n的所有可能的完全平方数的组合都算出来， 然后找出和
为n的组合中数量最少的那种组合。 如果不大于n的完全平方数有m个的话， 这个方法的时间复杂度是
O(m^m)。 显然穷举法时间复杂度过大， 不是可行的方法。 观察到， 在枚举的过程中， 有一些组合显然不是
最优的， 比如把12拆成12个1相加。 另外， 如果我们能够记录已经找到的最小组合， 那么稍大一些的数只需
要在此基础上添加若干个完全平方数即可。 这里面就包含了动态规划的思想。
具体来说， 我们用一个数组来记录已有的结果， 初始化为正无穷( INT_MAX )。 外层循环变量 i 从 0 到 n ，
内层循环变量 j 在 i 的基础上依次加上每个整数的完全平方， 超过 n 的不算。 那么 i + j*j 这个数需要
的最少的完全平方数的数量， 就是数组中当前的数值， 和 i 位置的数值加上一， 这两者之间较小的数字。
如果当前的值较小， 说明我们已经找到过它需要的完全平方数的个数（最初都是正无穷） 。 否则的话， 说
明在 i 的基础上加上 j 的平方符合条件， 所需的完全平方数的个数就是 i 需要的个数加上一。
*/
// @lc code=start
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;

        for (int i = 0; i <= n; i++)
            for (int j = 1; i + j * j <= n; j++)
                dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
                
        return dp[n];
    }
};
// @lc code=end
