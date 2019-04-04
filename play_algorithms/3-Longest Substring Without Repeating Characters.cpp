#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
class Solution
{
  public:
    int lengthOfLongestSubstring(string s)
    {
        int freq[256] = {0};
        int l = 0, r = -1; //滑动窗口
        int res = 0;
        while (l < s.size())
        {
            if (freq[s[r + 1]] == 0 && r + 1 < s.size())
            {
                r++;
                freq[s[r]]++;
            }
            else
            {
                freq[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
        }
        return res;
    }
};
int main()
{
    return 0;
}