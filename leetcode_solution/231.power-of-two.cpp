/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 *
 * https://leetcode.com/problems/power-of-two/description/
 *
 * algorithms
 * Easy (42.34%)
 * Likes:    508
 * Dislikes: 139
 * Total Accepted:    248.5K
 * Total Submissions: 586.5K
 * Testcase Example:  '1'
 *
 * Given an integer, write a function to determine if it is a power of two.
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: true 
 * Explanation: 2^0 = 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 16
 * Output: true
 * Explanation: 2^4 = 16
 * 
 * Example 3:
 * 
 * 
 * Input: 218
 * Output: false
 * 
 */
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n < 0)
            return false;
        bool hasOne = false;
        while (n > 0)
        {
            if (n & 1)
            {
                if (hasOne)
                    return false;
                else
                    hasOne = true;
            }
            n >>= 1;
        }
        return hasOne;
    }
};
