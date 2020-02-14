/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.size() == 0)
            return 0;
        if (needle.size() > haystack.size())
            return -1;
        for (int i = 0; i <= haystack.size() - needle.size(); ++i)
        {
            bool flag = true;
            for (int j = 0; j < needle.size(); ++j)
                if (needle[j] != haystack[i + j])
                    flag = false;
            if (flag)
                return i;
        }

        return -1;
    }
};
// @lc code=end
