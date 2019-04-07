/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (36.17%)
 * Total Accepted:    551.5K
 * Total Submissions: 1.5M
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
class Solution
{
  public:
    bool isValid(string s)
    {
        if (s.length() == 0)
            return true;
        if (s.length() == 1 || s.length() % 2 == 1 || s[0] == ')' || s[0] == ']' || s[0] == '}')
            return false;
        stack<char> v;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                v.push(s[i]);

            if (s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
                char temp = v.top();
                v.pop();
                if ((s[i] == ')' && temp == '(') || (s[i] == ']' && temp == '[') || (s[i] == '}' && temp == '{'))
                    continue;
                else
                    return false;
            }
        }
        return v.empty();
    }
};
