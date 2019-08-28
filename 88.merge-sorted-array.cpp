/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (36.55%)
 * Likes:    1254
 * Dislikes: 3012
 * Total Accepted:    404.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 * 
 * Note:
 * 
 * 
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2.
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * Output: [1,2,2,3,5,6]
 * 
 * 
 */
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (nums2.size() == 0)
            return;
        for (int i = m + n - 1; i >= n; i--)
            nums1[i] = nums1[i - n];
        int i = n, j = 0, cur = 0;
        while (cur < m + n)
        {
            if (j == n)
            {
                nums1[cur++] = nums1[i++];
                continue;
            }
            if (i == n + m)
            {
                nums1[cur++] = nums2[j++];
                continue;
            }
            if (nums1[i] < nums2[j])
                nums1[cur++] = nums1[i++];
            else
                nums1[cur++] = nums2[j++];
        }
    }
};
