/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (22.72%)
 * Likes:    1605
 * Dislikes: 1847
 * Total Accepted:    285.5K
 * Total Submissions: 1.3M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 * 
 * Example 1:
 * 
 * 
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 * 
 */
class Solution
{
public:
    int getNum(string &s, int idx)
    {
        if (s[idx] == '0')
        {
            if (idx < 1)
                return 0;
            else
            {
                int comb = s[idx] - '0' + 10 * (s[idx - 1] - '0');
                if (idx == 1)
                    return (comb == 10 || comb == 20) ? 1 : 0;
                if (comb == 10 || comb == 20)
                    return getNum(s, idx - 2);
                return 0;
            }
        }
        if (idx == 0)
            return 1;
        if (idx == 1)
        {
            int comb = s[idx] - '0' + 10 * (s[idx - 1] - '0');
            if (comb <= 26 && comb >= 10)
                return 2;
            else if (comb < 10)
                return 0;
            else
                return 1;
        }
        int comb = s[idx] - '0' + 10 * (s[idx - 1] - '0');
        return getNum(s, idx - 1) + ((comb <= 26 && comb >= 10) ? getNum(s, idx - 2) : 0);
    }
    int numDecodings(string s)
    {
        return getNum(s, s.length() - 1);
    }
};
