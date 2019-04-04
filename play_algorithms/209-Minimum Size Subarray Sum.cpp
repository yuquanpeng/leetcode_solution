#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
class Solution
{
  public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        //On  O1
        int l = 0, r = -1; //nums[l..r]滑动窗口
        int sum = 0;
        int res = nums.size() + 1;

        while (l < nums.size())
        {
            if (sum < s && r + 1 < nums.size())
            {
                r++;
                sum += nums[r];
            }
            else
            {
                sum -= nums[l];
                l++;
            }
            if (sum >= s)
                res = min(res, r - l + 1);
        }
        if (res == nums.size() + 1)
            return 0;
        return res;
    }
};
int main()
{
    return 0;
}