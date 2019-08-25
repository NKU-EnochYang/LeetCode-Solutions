/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.56%)
 * Likes:    4313
 * Dislikes: 495
 * Total Accepted:    618.3K
 * Total Submissions: 2.5M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n - 2; i++)
        {
            if(i == 0 || nums[i] > nums[i - 1])
            {
                int start = i + 1;
                int end = n - 1;
                while(start < end)
                {
                    int sum = nums[i] + nums[start] + nums[end];
                    if(sum == 0)
                    {
                        res.push_back({nums[i], nums[start], nums[end]});
                    }
                    if(sum < 0)
                    {
                        int cur = start;
                        while(nums[start] == nums[cur] && start < end)
                            start++;
                    }
                    else
                    {
                        int cur = end;
                        while(nums[end] == nums[cur] && start < end)
                            end--;
                    }
                }
            }
        }
        return res;
    }
};

