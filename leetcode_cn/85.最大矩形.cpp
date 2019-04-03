/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 *
 * https://leetcode-cn.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (41.12%)
 * Total Accepted:    2.8K
 * Total Submissions: 6.7K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * 输出: 6
 * 
 */
class Solution
{
  public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int m = matrix.size(); //
        int n = matrix[0].size();
        vector<vector<int>> height(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == '0')
                    height[i][j] = 0;
                else
                    height[i][j] = (i == 0) ? 1 : height[i - 1][j] + 1;

        int maxArea = 0;
        for (int i = 0; i < m; i++)
            maxArea = max(maxArea, largestRectangleArea(height[i]));

        return maxArea;
    }
    int largestRectangleArea(vector<int> &height)
    {
        vector<int> s;
        height.push_back(0);

        int sum = 0;
        int i = 0;
        while (i < height.size())
        {
            if (s.empty() || height[i] > height[s.back()])
            {
                s.push_back(i);
                i++;
            }
            else
            {
                int t = s.back();
                s.pop_back();
                sum = max(sum, height[t] * (s.empty() ? i : i - s.back() - 1));
            }
        }
        return sum;
    }
};
