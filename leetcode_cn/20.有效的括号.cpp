/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (36.67%)
 * Total Accepted:    53.2K
 * Total Submissions: 144.7K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */
class Solution
{
  public:
    bool isValid(string s)
    {
        stack<char> stack;
        char temp;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                stack.push(s[i]);
            if (s[i] == ')')
                if (!stack.empty() && stack.top() == '(')
                    stack.pop();
                else
                    stack.push(s[i]);

            if (s[i] == ']')
                if (!stack.empty() && stack.top() == '[')
                    stack.pop();
                else
                    stack.push(s[i]);
            if (s[i] == '}')
                if (!stack.empty() && stack.top() == '{')
                    stack.pop();
                else
                    stack.push(s[i]);
        }
        if (stack.empty())
            return true;
        else
            return false;
    }
};
