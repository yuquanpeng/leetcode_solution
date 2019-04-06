#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_set>
using namespace std;
class Solution
{
  public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        //On
        //Ok
        unordered_set<int> record;
        for (int i = 0; i < nums.size(); i++)
        {
            if (record.find(nums[i]) != record.end())
                return true;
            record.insert(nums[i]);
            //保持record中最多只有k个元素
            if (record.size() == k + 1)
                record.erase(nums[i - k]);
        }
        return false;
    }
};
int main()
{
    return 0;
}