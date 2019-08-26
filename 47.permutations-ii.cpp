/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (41.73%)
 * Likes:    1165
 * Dislikes: 46
 * Total Accepted:    265.8K
 * Total Submissions: 635.8K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
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
                sort(res[i].begin() + pos, res[i].end());
                for (int j = pos + 1; j < nums.size(); j++)
                {
                    vector<int> temp = res[i];
                    if (temp[j] == temp[j - 1])
                        continue;
                    swap(temp[j], temp[pos]);
                    res.push_back(temp);
                }
            }
            pos++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> res;
        int pos = 0;
        perm(nums, pos, res);
        sort(res.begin(), res.end());
        return res;
    }
};
