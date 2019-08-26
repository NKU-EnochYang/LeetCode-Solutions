/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (31.13%)
 * Likes:    1299
 * Dislikes: 445
 * Total Accepted:    258.1K
 * Total Submissions: 827.8K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 */
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        if (matrix.size() == 0)
            return res;
        // top left x, top left y, bottom right x, bottom right y
        int tlx = 0, tly = 0, brx = matrix.size() - 1, bry = matrix[0].size() - 1;
        while (tlx <= brx && tly <= bry)
        {
            for (int j = tly; j <= bry; j++)
                res.push_back(matrix[tlx][j]);
            for (int i = tlx + 1; i <= brx; i++)
                res.push_back(matrix[i][bry]);
            if (tlx < brx && tly < bry)
            {
                for (int j = bry - 1; j > tly; j--)
                    res.push_back(matrix[brx][j]);
                for (int i = brx; i > tlx; i--)
                    res.push_back(matrix[i][tly]);
            }
            tlx++;
            tly++;
            brx--;
            bry--;
        }
        return res;
    }
};
