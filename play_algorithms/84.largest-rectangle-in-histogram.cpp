/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (30.61%)
 * Total Accepted:    166K
 * Total Submissions: 541.1K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * 
 * 
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * 
 * 
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [2,1,5,6,2,3]
 * Output: 10
 * 
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
