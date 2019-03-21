/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 *
 * https://leetcode-cn.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (36.98%)
 * Total Accepted:    4.7K
 * Total Submissions: 12.4K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 * 
 * 
 * 
 * 
 * 
 * 以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
 * 
 * 
 * 
 * 
 * 
 * 图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: [2,1,5,6,2,3]
 * 输出: 10
 * 
 */
class Solution
{
  public:
    int largestRectangleArea(vector<int> &heights)
    {
        vector<int> s;
        heights.push_back(0);
        int sum = 0;
        int i = 0;
        while (i < heights.size())
        {
            if (s.empty() || heights[i] > heights[s.back()])
            {
                s.push_back(i);
                i++;
            }
            else
            {
                int t = s.back();
                s.pop_back();
                //空 ？ 就是i
                sum = max(sum, heights[t] * (s.empty() ? i : i - s.back() - 1));
            }
        }
        return sum;
    }
};
