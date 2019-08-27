/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 *
 * https://leetcode.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (42.96%)
 * Likes:    1883
 * Dislikes: 168
 * Total Accepted:    347.7K
 * Total Submissions: 808.1K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * Given an array with n objects colored red, white or blue, sort them in-place
 * so that objects of the same color are adjacent, with the colors in the order
 * red, white and blue.
 * 
 * Here, we will use the integers 0, 1, and 2 to represent the color red,
 * white, and blue respectively.
 * 
 * Note: You are not suppose to use the library's sort function for this
 * problem.
 * 
 * Example:
 * 
 * 
 * Input: [2,0,2,1,1,0]
 * Output: [0,0,1,1,2,2]
 * 
 * Follow up:
 * 
 * 
 * A rather straight forward solution is a two-pass algorithm using counting
 * sort.
 * First, iterate the array counting number of 0's, 1's, and 2's, then
 * overwrite array with total number of 0's, then 1's and followed by 2's.
 * Could you come up with a one-pass algorithm using only constant space?
 * 
 * 
 */
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        int i = 0;
        while (i <= high && low < high)
        {
            if (i == low && nums[low] == 0)
            {
                i++;
                continue;
            }
            if (nums[i] == 0)
            {
                swap(nums[low], nums[i]);
                low++;
            }
            else if (nums[i] == 2)
            {
                swap(nums[high], nums[i]);
                high--;
            }
            else
            {
                i++;
            }
        }
    }
};
