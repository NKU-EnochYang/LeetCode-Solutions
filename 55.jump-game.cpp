/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (32.44%)
 * Likes:    2279
 * Dislikes: 222
 * Total Accepted:    295.9K
 * Total Submissions: 911.2K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Determine if you are able to reach the last index.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its
 * maximum
 * jump length is 0, which makes it impossible to reach the last index.
 * 
 * 
 */
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        vector<int> possible(nums.size());
        possible[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (possible[i] == 1)
            {
                for (int j = i + 1; j <= nums[i] + i && j < nums.size(); j++)
                    possible[j] = 1;
            }
            if (possible[nums.size() - 1] == 1)
                return true;
        }
        return false;
    }
};
