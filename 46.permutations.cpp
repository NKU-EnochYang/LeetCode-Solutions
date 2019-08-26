/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (56.81%)
 * Likes:    2327
 * Dislikes: 72
 * Total Accepted:    421.8K
 * Total Submissions: 741.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
class Solution
{
public:
    void perm(vector<int> nums, int pos, vector<vector<int>> &res)
    {
        res.push_back(nums);
        while (pos < nums.size() - 1)
        {
            int size = res.size();
            for (int i = 0; i < size; i++)
            {
                for (int j = pos + 1; j < nums.size(); j++)
                {
                    vector<int> temp = res[i];
                    swap(temp[pos], temp[j]);
                    res.push_back(temp);
                }
            }
            pos++;
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        int pos = 0;
        perm(nums, 0, res);
        sort(res.begin(), res.end());
        return res;
    }
};
