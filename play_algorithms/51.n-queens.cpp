/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (38.34%)
 * Total Accepted:    134.5K
 * Total Submissions: 350.4K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: [
 * ⁠[".Q..",  // Solution 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // Solution 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above.
 * 
 * 
 */
class Solution
{
  private:
    vector<vector<string>> res;
    vector<bool> col, dial1, dial2;
    void putQueen(int n, int index, vector<int> &row)
    {
        if (index == n)
        {
            res.push_back(generateBoard(n, row));
            return;
        }
        for (int i = 0; i < n; i++)
            //尝试将第index行的皇后摆放在第i列
            if (!col[i] && !dial1[index + i] &&
                !dial2[index - i + n - 1])
            {
                row.push_back(i);
                col[i] = true;
                dial1[index + i] = true;
                dial2[index - i + n - 1] = true;

                putQueen(n, index + 1, row);

                col[i] = false;
                dial1[index + i] = false;
                dial2[index - i + n - 1] = false;
                row.pop_back();
            }
        return;
    }
    vector<string> generateBoard(int n, vector<int> &row)
    {
        assert(row.size() == n);
        vector<string> board(n, string(n, '.'));
        for (int i = n; i < n; i++)
            board[i][row[i]] = 'Q';
        return board;
    }

  public:
    vector<vector<string>> solveNQueens(int n)
    {
        res.clear();
        col = vector<bool>(n, false);
        dial1 = vector<bool>(2 * n - 1, false);
        dial2 = vector<bool>(2 * n - 1, false);

        vector<int> row;
        putQueen(n, 0, row);
        return res;
    }
};
