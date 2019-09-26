/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (31.48%)
 * Likes:    1258
 * Dislikes: 253
 * Total Accepted:    262.7K
 * Total Submissions: 833.8K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */
/*
这道题和3Sum几乎同出一辙， 只不过是要求四个数字的和， 在时间复杂度上要比3Sum高一个数量级。 对
于两点要求的处理：
1. 首先要对整个数组进行排序， 这样得到的答案自然是排序好的.
2. 对于重复答案的处理和3Sum是一摸一样的。
*/
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        if (nums.size() <= 3)
            return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size() - 2; ++j)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int k = j + 1;
                int m = nums.size() - 1;
                while (k < m)
                {
                    int sum = nums[i] + nums[j] + nums[k] + nums[m];
                    if (sum == target)
                    {
                        vector<int> curr;
                        curr.push_back(nums[i]);
                        curr.push_back(nums[j]);
                        curr.push_back(nums[k]);
                        curr.push_back(nums[m]);
                        res.push_back(curr);
                        do
                        {
                            ++k;
                        } while (k < m && nums[k] == nums[k - 1]);
                        do
                        {
                            --m;
                        } while (k < m && nums[m] == nums[m + 1]);
                    }
                    else if (sum < target)
                        ++k;
                    else
                        --m;
                }
            }
        }
        return res;
    }
};
