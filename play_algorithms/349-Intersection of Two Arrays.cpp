#include <iostream>
#include <vector>
#include <cassert>
#include <set>
#include <unordered_set>

using namespace std;
class Solution
{
  public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        //O nlogn
        // set<int> record(nums1.begin(), nums1.end());
        // set<int> resultSet;
        // for (int i = 0; i < nums2.size(); i++)
        //     if (record.find(nums2[i]) != record.end())
        //         resultSet.insert(nums2.[i]);
        // return vector<int>(resultSet.begin(), resultSet.end());

        //On
        unordered_set<int> record(nums1.begin(), nums1.end());
        unordered_set<int> resultSet;
        for (int i = 0; i < nums2.size(); i++)
            if (record.find(nums2[i]) != record.end())
                resultSet.insert(nums2.[i]);
        return vector<int>(resultSet.begin(), resultSet.end());
    }
};
int main()
{
    return 0;
}