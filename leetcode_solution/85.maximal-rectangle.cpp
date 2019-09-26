/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (34.51%)
 * Likes:    1726
 * Dislikes: 54
 * Total Accepted:    135.5K
 * Total Submissions: 391.9K
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
/*
对于上面哪一题， 我们先去掉最下面的一行， 然后就可以发现， 它可以转化成一个直方图， 数据为[2, 2, 2,
0]， 我们认为1就是高度， 如果碰到0， 譬如上面最右列， 则高度为0， 而计算这个直方图最大矩形面积就很
容易了， 我们已经在Largest Rectangle in Histogram处理了。
所以我们可以首先得到每一行的直方图， 分别求出改直方图的最大区域， 最后就能得到结果了
*/
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> height(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '0')
                    height[i][j] = 0;
                else
                    height[i][j] = (i == 0) ? 1 : height[i - 1][j] + 1;
            }
        }
        int maxArea = 0;
        for (int i = 0; i < m; i++)
        {
            maxArea = max(maxArea, largestRectangleArea(height[i]));
        }
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
