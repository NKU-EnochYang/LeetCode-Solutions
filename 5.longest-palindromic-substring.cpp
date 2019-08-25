/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (27.76%)
 * Likes:    4130
 * Dislikes: 382
 * Total Accepted:    627.8K
 * Total Submissions: 2.3M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */
class Solution {
public:
    int prim[1001];
    int unprim[1001];
    void judgePalindrome(string s, int len)
    {
        for(int i = 0;i<s.length() - len + 1;i++)
        {
            if(s[i] != s[i + len - 1]) continue;
            else
            {
                if(len % 2 != 0)
                {
                    if(prim[i+1] == len - 2)
                        prim[i] = len;
                }
                else
                {
                    if(unprim[i+1] == len - 2)
                        unprim[i] = len;
                }
            }
        }
    }
    string longestPalindrome(string s) {
        for(int i = 0;i<s.length();i++)
        {
            prim[i] = 1;
            unprim[i] = 0;
        }
        for(int i = 1;i<=s.length();i++)
            judgePalindrome(s, i);
        int max_loc = 0;
        int max = 0;
        for(int i = 0;i<s.length();i++)
        {
            if(prim[i] > max)
            {
                max = prim[i];
                max_loc = i;
            }
            if(unprim[i] > max)
            {
                max = unprim[i];
                max_loc = i;
            }
        }
        return s.substr(max_loc, max);
    }
};
