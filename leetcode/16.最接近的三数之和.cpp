/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (39.04%)
 * Total Accepted:    18.9K
 * Total Submissions: 48K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 * 
 * 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
 * 
 * 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */
class Solution
{
  public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        if (nums.size() <= 2)
            return -1;
        int res;
        int dis = 123123123;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                int temp_sum = nums[i] + nums[j] + nums[k];
                if (temp_sum < target)
                {
                    if (target - temp_sum < dis)
                    {
                        dis = target - temp_sum;
                        res = temp_sum;
                    }
                    j++;
                }
                else if (temp_sum > target)
                {
                    if (temp_sum - target < dis)
                    {
                        dis = temp_sum - target;
                        res = temp_sum;
                    }
                    k--;
                }
                else
                {
                    return temp_sum;
                }
            }
        }
        return res;
    }
};
