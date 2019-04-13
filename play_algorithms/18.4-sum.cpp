/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (30.06%)
 * Total Accepted:    223.1K
 * Total Submissions: 740.7K
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
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        if (nums.size() <= 3)
            return res;
        sort(nums.begin(), nums.end()); //排序
        for (int i = 0; i < nums.size() - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) //i去重
                continue;
            for (int j = i + 1; j < nums.size() - 2; j++) //j 从i的后面开始找
            {
                if (j > i + 1 & nums[j] == nums[j - 1]) //j去重
                    continue;
                int k = j + 1;           //k在左边
                int l = nums.size() - 1; //l在右边
                while (k < l)
                {
                    int sum_temp = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum_temp == target) //找到了
                    {
                        vector<int> cur;
                        cur.push_back(nums[i]);
                        cur.push_back(nums[j]);
                        cur.push_back(nums[k]);
                        cur.push_back(nums[l]);
                        res.push_back(cur);
                        k++;
                        l--;
                        //k l去重
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
