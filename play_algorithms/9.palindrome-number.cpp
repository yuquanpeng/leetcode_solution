/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (42.60%)
 * Total Accepted:    549.6K
 * Total Submissions: 1.3M
 * Testcase Example:  '121'
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome
 * when it reads the same backward as forward.
 * 
 * Example 1:
 * 
 * 
 * Input: 121
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * Follow up:
 * 
 * Coud you solve it without converting the integer to a string?
 * 
 */
class Solution
{
public:
    bool isPalindrome(int x)
    {
        int number[20] = {0};
        int index = 0;
        if (x < 0)
            return false;
        else
        {
            while (x != 0)
            {
                number[index++] = x % 10;
                x /= 10;
            }
            for (int i = 0, j = index - 1; i <= index / 2 && j >= index / 2; i++, j--)
            {
                if (number[i] != number[j])
                    return false;
            }
            return true;
        }
    }
};
