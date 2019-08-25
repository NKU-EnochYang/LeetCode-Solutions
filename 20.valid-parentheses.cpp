/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (37.07%)
 * Likes:    3245
 * Dislikes: 153
 * Total Accepted:    667.8K
 * Total Submissions: 1.8M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
class Solution {
public:
    bool isValid(string s) {
        vector<char> stk;
        for(int i = 0;i<s.length();i++)
        {
            if(stk.size() == 0)
            {
                stk.push_back(s[i]);
                continue;
            }
            switch (s[i])
            {
            case '(':
                stk.push_back(s[i]);
                break;
            case ')':
                if(stk.back() == '(')
                    stk.pop_back();
                else
                    return false;
                break;
            case '[':
                stk.push_back(s[i]);
                break;
            case ']':
                if(stk.back() == '[')
                    stk.pop_back();
                else
                    return false;
                break;
            case '{':
                stk.push_back(s[i]);
                break;
            case '}':
                if(stk.back() == '{')
                    stk.pop_back();
                else
                    return false;
                break;
            default:
                break;
            }
        }
        if(stk.size() == 0)
            return true;
        return false;
    }
};

