/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (32.76%)
 * Total Accepted:    116.4K
 * Total Submissions: 354.6K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * Output: 6
 * 
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
