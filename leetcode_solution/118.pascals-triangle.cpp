/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 *
 * https://leetcode.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (47.87%)
 * Likes:    844
 * Dislikes: 84
 * Total Accepted:    286.9K
 * Total Submissions: 598.9K
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
        /*
        第k层有k个元素；每层第一个和最后一个元素为1；
        对于第k（k>2）层，第n层（n>1&&n<k）个元素A[k][n] =  A[k-1][n-1] + A[k-1][n]
        当前这个=左上角那个+左上角那个的下一个
        */
        vector<vector<int>> res;
        res.resize(numRows);
        for (int i = 0; i < numRows; i++)
        {
            res[i].resize(i + 1);
            res[i][0] = 1;
            res[i][res[i].size() - 1] = 1;
            for (int j = 1; j < res[i].size() - 1; j++)
            {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }
        return res;
    }
};
