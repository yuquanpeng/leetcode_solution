/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (35.22%)
 * Likes:    1020
 * Dislikes: 119
 * Total Accepted:    249.2K
 * Total Submissions: 706.8K
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
/*
题目解析: 对于这个给定的矩阵， 我们如果用brute force解法， 用两个嵌套循环， O(n2)便可以得到答案.但
是我们需要注意的是这道题已经给定了这个矩阵的两个特性， 这两个特性对于提高我们算法的时间复杂度
有很大帮助， 首先我们给出一个O(n)的解法， 也就是说我们可以固定住右上角的元素， 根据递增或者递减
的规律， 我们可以判断这个给定的数值是否存在于这个矩阵当中
*/
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() == 0)
            return false;
        if (matrix[0].size() == 0)
            return false;
        int row = 0;
        int col = matrix[0].size() - 1;
        while (row < matrix.size() && col >= 0)
        {
            if (target < matrix[row][col])
                --col;
            else if (target > matrix[row][col])
                ++row;
            else
                return true;
        }
        return false;
    }
};
