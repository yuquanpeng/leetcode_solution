/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.75%)
 * Likes:    1337
 * Dislikes: 97
 * Total Accepted:    381.7K
 * Total Submissions: 834.5K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */
/**
 * 题目分析：
1. 最短距离： 两个整数的最短距离是0.这点对于这道题比较重要， 别忽略。
2. 这道题和3Sum几乎同出一辙， 所以方便于解题， 我们还是在开头要对数组进行排序， 要么没法定位指
针移动。
3. 另外， 这道题中用到了INT_MAX这个值， 这个值和 INT_MIN是相对应的， 在很多比较求最大值最小值
的情况， 经常用这两个变量。
解题思路：
这道题的解题方法和3Sum几乎相同， 设定三个指针， 固定两个， 根据和的大小移动另外一个。 属于这道题
目自己的东西就是distance比较这块儿， 建立一个tmp distance和min distance比较。
 **/
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        if (nums.size() <= 2)
            return 0;
        int res = 0;
        int distance = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k)
            {
                int tmp_val = nums[i] + nums[j] + nums[k];
                int tmp_dis = 0;
                if (tmp_val < target)
                {
                    tmp_dis = target - tmp_val;
                    if (tmp_dis < distance)
                    {
                        distance = tmp_dis;
                        res = nums[i] + nums[j] + nums[k];
                    }
                    ++j;
                }
                else if (tmp_val > target)
                {
                    tmp_dis = tmp_val - target;
                    if (tmp_dis < distance)
                    {
                        distance = tmp_dis;
                        res = nums[i] + nums[j] + nums[k];
                    }
                    --k;
                }
                else
                {
                    res = nums[i] + nums[j] + nums[k];
                    return res;
                }
            }
        }
        return res;
    }
};
