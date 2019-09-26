/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (43.56%)
 * Likes:    1220
 * Dislikes: 179
 * Total Accepted:    322K
 * Total Submissions: 738.8K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * 
 * Find the minimum element.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,4,5,1,2] 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,5,6,7,0,1,2]
 * Output: 0
 * 
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
