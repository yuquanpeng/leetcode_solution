/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (23.69%)
 * Total Accepted:    518K
 * Total Submissions: 2.2M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        if (nums.size() <= 2)
            return res;
        sort(nums.begin(), nums.end());           //首先对数组从小到大排序
        for (int i = 0; i < nums.size() - 2; i++) //i不动 kj动
        {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) //直到前指针大于等于后指针。
            {
                vector<int> cur;
                if (nums[i] + nums[j] + nums[k] == 0) //定义两个指针一前一后，若找到两数之和满足条件则加入到解集中
                {
                    cur.push_back(nums[i]);
                    cur.push_back(nums[j]);
                    cur.push_back(nums[k]);
                    res.push_back(cur);
                    j++;
                    k--;
                    //kj去重
                    while (j < k && nums[j - 1] == nums[j])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                } //若大于和则后指针向前移动，反之则前指针向后移动，
                else if (nums[i] + nums[j] + nums[k] < 0)
                    j++;
                else
                    k--;
            }
            //i去重
            while (i < nums.size() - 1 && nums[i] == nums[i + 1])
            {
                i++;
            }
        }
        return res;
    }
};
