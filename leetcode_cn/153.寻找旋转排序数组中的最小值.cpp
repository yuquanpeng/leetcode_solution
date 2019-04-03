/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 *
 * https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (48.30%)
 * Total Accepted:    6.7K
 * Total Submissions: 13.8K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,1,2,4,5,6,7]  可能变为 [4,5,6,7,0,1,2] )。
 * 
 * 请找出其中最小的元素。
 * 
 * 你可以假设数组中不存在重复元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,4,5,1,2]
 * 输出: 1
 * 
 * 示例 2:
 * 
 * 输入: [4,5,6,7,0,1,2]
 * 输出: 0
 * 
 */
class Solution
{
  public:
    int findMin(vector<int> &nums)
    {
        int size = nums.size();
        if (size == 0)
            return 0;
        else if (size == 1)
            return nums[0];
        else if (size == 2)
            return min(nums[0], nums[1]);

        int left = 0;
        int right = size - 1;
        while (left < right - 1)
        {
            if (nums[left] < nums[right])
                return nums[left];
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[left])
                left = mid;
            else if (nums[mid] < nums[left])
                right = mid;
        }
        return min(nums[left], nums[right]);
    }
};
