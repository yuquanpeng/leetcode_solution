/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        const int int_max = 0x7fffffff;
        const int int_min = 0x80000000;
        long long result = 0;
        while (x != 0)
        {
            result = result * 10 + x % 10;
            x /= 10;
        }
        if (result > int_max || result < int_min)
            return 0;
        return result;
    }
};
// @lc code=end
