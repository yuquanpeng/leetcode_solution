/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (30.75%)
 * Total Accepted:    265.5K
 * Total Submissions: 862.7K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 */
// class Solution
// {
//   public:
//     bool exist(vector<vector<char>> &board, string word)
//     {
//         for (int row = 0; row < board.size(); ++row)
//             for (int col = 0; col < board[0].size(); ++col)
//                 if (dfs(word.c_str(), row, col, board))
//                     return true;
//         return false;
//     }

//     bool dfs(const char *str, int row, int col, vector<vector<char>> &board)
//     {
//         char c = board[row][col];
//         if (*str++ != c)
//             return false;
//         if (*str == '\0')
//             return true;
//         board[row][col] = '#'; // mark as used
//         bool found = (row + 1 < board.size() && dfs(str, row + 1, col, board)) ||
//                      (col + 1 < board[0].size() && dfs(str, row, col + 1, board)) ||
//                      (row - 1 >= 0 && dfs(str, row - 1, col, board)) ||
//                      (col - 1 >= 0 && dfs(str, row, col - 1, board));
//         board[row][col] = c; // no longer used
//         return found;
//     }
// };
class Solution
{
  private:
    int shift[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int m, n;
    vector<vector<bool>> visited;
    bool inArea(int x, int y)
    {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    //从board[startx][starty]开始，寻找word[index...word.size()]
    bool searchWord(const vector<vector<char>> &board,
                    const string &word, int index, int startx, int starty)
    {
        if (index == word.size() - 1)
            return board[startx][starty] == word[index];
        if (board[startx][starty] == word[index])
        {
            visited[startx][starty] = true;
            //从x y出发向四个方向寻找
            for (int i = 0; i < 4; i++)
            {
                int newx = startx + shift[i][0];
                int newy = starty + shift[i][1];
                if (inArea(newx, newy) && !visited[newx][newy] &&
                    searchWord(board, word, index + 1, newx, newy))
                    return true;
            }
            visited[startx][starty] = false;
        }
        return false;
    }

  public:
    bool exist(vector<vector<char>> &board, string word)
    {
        m = board.size();
        assert(m > 0);
        n = board[0].size();

        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                if (searchWord(board, word, 0, i, j))
                    return true;

        return false;
    }
};
