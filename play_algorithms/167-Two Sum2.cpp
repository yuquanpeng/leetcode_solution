#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        //On O1
        assert(nums.size() >= 2);
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            if (nums[l] + nums[r] == target)
            {
                int res[2] = {l + 1, r + 1};
                return vector<int>(res, res + 2);
            }
            else if (nums[l] + nums[r] > target)
                r--;
            else if (nums[l] + nums[r] < target)
                l++;
        }
        throw invalid_argument("not fount.");
    }
};
int main()
{
    return 0;
}