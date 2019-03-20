/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (21.13%)
 * Total Accepted:    41.5K
 * Total Submissions: 193.5K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
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
        sort(nums.begin(), nums.end()); //首先对数组从小到大排序
        for (int i = 0; i < nums.size() - 2; i++)
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
                    k--; //去重
                    while (j < k && nums[j - 1] == nums[j])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                } //若大于和则后指针向前移动，反之则前指针向后移动，
                else if (nums[i] + nums[j] + nums[k] < 0)
                    j++;
                else
                    k--;
            } //去重
            while (i < nums.size() - 1 && nums[i] == nums[i + 1])
            {
                i++;
            }
        }
        return res;
    }
};
