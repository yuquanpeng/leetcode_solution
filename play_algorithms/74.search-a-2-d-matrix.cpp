/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (34.74%)
 * Total Accepted:    215.4K
 * Total Submissions: 619.8K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 13
 * Output: false
 * 
 */
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        /* we set the corner case as below:
        1, if the row number of input matrix is 0, we set it false
        2, if the colomun number of input matrix is 0, we set it false
        */
        if (matrix.size() == 0)
            return false;
        if (matrix[0].size() == 0)
            return false;
        int rowNumber = 0;
        int colNumber = matrix[0].size() - 1;
        while (rowNumber < matrix.size() && colNumber >= 0)
        {
            if (target < matrix[rowNumber][colNumber])
                --colNumber;
            else if (target > matrix[rowNumber][colNumber])
                ++rowNumber;
            else
                return true;
        }
        return false;
    }
};
