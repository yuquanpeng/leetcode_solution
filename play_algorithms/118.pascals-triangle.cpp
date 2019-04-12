/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (45.15%)
 * Total Accepted:    240.2K
 * Total Submissions: 530.9K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer numRows, generate the first numRows of Pascal's
 * triangle.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 5
 * Output:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 * 
 */
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res(numRows, vector<int>(numRows)); //二维数组
        for (int i = 0; i < numRows; i++)
        {
            res[i][0] = 1;
            res[i][i] = 1;

            for (int j = 1; j < i; j++)
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j]; //利用前一行填写下一行

            res[i].erase(res[i].begin() + i + 1, res[i].end()); //去掉每一行元素为空的位置，只留下一个三角形
        }
        return res;
    }
};
