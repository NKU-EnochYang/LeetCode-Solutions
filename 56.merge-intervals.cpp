/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (36.36%)
 * Likes:    2440
 * Dislikes: 188
 * Total Accepted:    392.9K
 * Total Submissions: 1.1M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0 || intervals.size() == 1)
            return intervals;
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        int pre = intervals[0][1];
        for(int i = 1;i<intervals.size();i++)
        {
            if(intervals[i][1] <= pre)
                continue;
            if(intervals[i][0] <= pre)
            {
                vector<int> temp = res.back();
                res.pop_back();
                res.push_back({temp[0], intervals[i][1]});
            }
            else
            {
                res.push_back(intervals[i]);
            }
            pre = intervals[i][1];
        }
        return res;
    }
};
