/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (34.25%)
 * Total Accepted:    13.9K
 * Total Submissions: 40.1K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 
 * 注意：
 * 
 * 答案中不可以包含重复的四元组。
 * 
 * 示例：
 * 
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 * 
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
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
        for (int i = 0; i < nums.size() - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                if (j > i + 1 & nums[j] == nums[j - 1])
                    continue;
                int k = j + 1;
                int l = nums.size() - 1;
                while (k < l)
                {
                    int sum_temp = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum_temp == target)
                    {
                        vector<int> cur;
                        cur.push_back(nums[i]);
                        cur.push_back(nums[j]);
                        cur.push_back(nums[k]);
                        cur.push_back(nums[l]);
                        res.push_back(cur);
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                    else if (sum_temp < target)
                        k++;
                    else
                        l--;
                }
            }
        }
        return res;
    }
};
