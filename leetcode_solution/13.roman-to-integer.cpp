/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start
class Solution
{
public:
    int romanToInt(string s)
    {
        int res = 0;
        unordered_map<char, int> bp = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int s_size = s.size();
        for (int i = 0; i < s_size; i++)
        {
            int temp = bp[s[i]];
            if (i == s_size - 1 || bp[s[i]] >= bp[s[i + 1]])
                res += temp;
            else
                res -= temp;
        }
        return res;
    }
};
// @lc code=end
