/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (40.71%)
 * Likes:    1370
 * Dislikes: 158
 * Total Accepted:    205K
 * Total Submissions: 498.6K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle, find the minimum path sum from top to bottom. Each step
 * you may move to adjacent numbers on the row below.
 * 
 * For example, given the following triangle
 * 
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 * 
 * Note:
 * 
 * Bonus point if you are able to do this using only O(n) extra space, where n
 * is the total number of rows in the triangle.
 * 
 */
/*
dp[m + 1][n] = min(dp[m][n], dp[m][n - 1]) + triangle[m + 1][n] if n > 0
dp[m + 1][0] = dp[m][0] + triangle[m + 1][0]
*/

// @lc code=start
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int m = triangle.size();
        if (m == 0)
            return 0;
        //一维数组存储
        vector<int> total(m, INT_MAX);
        total[0] = triangle[0][0];
        //从上到下 从右到左
        for (int i = 1; i < m; i++)
            for (int j = i; j >= 0; j--)
                if (j == 0)                               //碰到左边缘
                    total[j] = total[j] + triangle[i][j]; //最左边的
                else
                    total[j] = min(total[j - 1], total[j]) + triangle[i][j];
        int minTotal = INT_MAX;
        for (int i = 0; i < m; i++)
            minTotal = min(minTotal, total[i]);
        return minTotal;
    }

    // int minimumTotal(vector<vector<int>> &triangle)
    // {
    //     if (triangle.empty())
    //         return 0;
    //     int row = triangle.size();
    //     vector<int> dp;
    //     dp.resize(row);
    //     //用最底层的数据初始化
    //     for (int i = 0; i < dp.size(); i++)
    //         dp[i] = triangle[row - 1][i];
    // //从底向上选择最小的
    //     for (int i = row - 2; i >= 0; i--)
    //         for (int j = 0; j <= i; j++)
    //             dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);

    //     return dp[0];
    // }
};
// @lc code=end
