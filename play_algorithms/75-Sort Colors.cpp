#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
class Solution
{
  public:
    void sortColors(vector<int> &nums)
    {
        //时间复杂度：O(n)
        //空间复杂度：O(k)
        // int count[3] = {0};
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     assert(nums[i] >= 0 && nums[i] <= 2); //谨防数组越界
        //     count[nums[i]]++;
        // }
        // int index = 0;
        // for (int i = 0; i < count[0]; i++)
        //     nums[index++] = 0;
        // for (int i = 0; i < count[1]; i++)
        //     nums[index++] = 1;
        // for (int i = 0; i < count[2]; i++)
        //     nums[index++] = 2;

        // for (int i = 0; i < count.size(); i++)
        //     for (int j = 0; j < count[i]; j++)
        //         nums[j] = i;
        //三路快排
        //时间复杂度：O(n)
        //空间复杂度：O(1)
        int zero = -1;         //nums[0..zero] == 0
        int two = nums.size(); //nums[two...n-1] == 2
        for (int i = 0; i < two;)
        {
            if (nums[i] == 1)
                i++;
            else if (nums[i] == 2)
            {
                two--;
                swap(nums[i], nums[two]);
            }
            else
            {
                assert(nums[i] == 0);
                zero++;
                swap(nums[zero], nums[i]);
                i++;
            }
        }
    }
};
int main()
{
    return 0;
}