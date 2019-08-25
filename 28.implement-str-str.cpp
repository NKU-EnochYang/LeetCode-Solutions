/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (32.69%)
 * Likes:    998
 * Dislikes: 1444
 * Total Accepted:    476.1K
 * Total Submissions: 1.5M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.length() == 0)
            return 0;
        int i = 0;
        for (int j = 0; j < haystack.length(); j++)
        {
            if (haystack[j] == needle[i])
            {
                i++;
                if (i == needle.length())
                    return j - i + 1;
            }
            else
            {
                j = j - i;
                i = 0;
            }
        }
        return -1;
    }
};
