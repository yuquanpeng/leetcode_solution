/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Hard (39.12%)
 * Total Accepted:    125.6K
 * Total Submissions: 320.9K
 * Testcase Example:  '[1,3,5]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * 
 * Find the minimum element.
 * 
 * The array may contain duplicates.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,5]
 * Output: 1
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,2,0,1]
 * Output: 0
 * 
 * Note:
 * 
 * 
 * This is a follow up problem to Find Minimum in Rotated Sorted Array.
 * Would allow duplicates affect the run-time complexity? How and why?
 * 
 * 
 */
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        else if (n == 1)
            return nums[0];
        else if (n == 2)
            return min(nums[0], nums[1]);

        int left = 0;
        int right = n - 1;
        while (left < right - 1)
        {
            if (nums[left] < nums[right])
                return nums[left];

            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[left])
                left = mid;
            else if (nums[mid] < nums[left])
                right = mid;
            else //mid == start
                left++;
        }
        return min(nums[left], nums[right]);
    }
};
