/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (32.08%)
 * Likes:    2093
 * Dislikes: 107
 * Total Accepted:    317.2K
 * Total Submissions: 986.8K
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
class Solution
{
public:
    bool dfsSearch(vector<vector<char>> &board, string &word, int k, int i, int j)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || word[k] != board[i][j])
            return false;
        if (k == word.length() - 1)
            return true;
        char cur = board[i][j];
        board[i][j] = '*';
        bool search_next = dfsSearch(board, word, k + 1, i - 1, j) ||
                           dfsSearch(board, word, k + 1, i + 1, j) ||
                           dfsSearch(board, word, k + 1, i, j - 1) ||
                           dfsSearch(board, word, k + 1, i, j + 1);
        board[i][j] = cur;
        return search_next;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        if (word.empty())
            return true;
        if (board.empty() || board[0].empty())
            return false;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (dfsSearch(board, word, 0, i, j))
                    return true;
        return false;
    }
};
