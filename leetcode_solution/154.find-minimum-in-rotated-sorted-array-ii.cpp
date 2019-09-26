/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Hard (39.77%)
 * Likes:    549
 * Dislikes: 156
 * Total Accepted:    143.4K
 * Total Submissions: 360.3K
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
/*
A[mid] > A[start]， 右半区间查找。
A[mid] < A[start]， 左半区间查找。
A[mid] = A[start]， 出现这种情况， 我们跳过start， 重新查找， 譬如[2,2,2,1]， A[mid] = A[start]都为2，
这时候我们跳过start， 使用[2,2,1]继续查找。
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
            else
                left++;
        }
        return min(nums[left], nums[right]);
    }
};
