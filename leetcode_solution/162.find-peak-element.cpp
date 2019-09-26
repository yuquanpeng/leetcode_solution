/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 *
 * https://leetcode.com/problems/find-peak-element/description/
 *
 * algorithms
 * Medium (41.80%)
 * Likes:    1015
 * Dislikes: 1513
 * Total Accepted:    268.1K
 * Total Submissions: 640.6K
 * Testcase Example:  '[1,2,3,1]'
 *
 * A peak element is an element that is greater than its neighbors.
 * 
 * Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element
 * and return its index.
 * 
 * The array may contain multiple peaks, in that case return the index to any
 * one of the peaks is fine.
 * 
 * You may imagine that nums[-1] = nums[n] = -∞.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,1]
 * Output: 2
 * Explanation: 3 is a peak element and your function should return the index
 * number 2.
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,1,3,5,6,4]
 * Output: 1 or 5 
 * Explanation: Your function can return either index number 1 where the peak
 * element is 2, 
 * or index number 5 where the peak element is 6.
 * 
 * 
 * Note:
 * 
 * Your solution should be in logarithmic complexity.
 * 
 */
/*
对于这题， 最简单地解法就是遍历数组， 只要找到第一个元素， 大于两边就可以了， 复杂度为O(N)。 但这
题还可以通过二分来做。
首先我们找到中间节点mid， 如果大于两边返回当前index就可以了， 如果左边的节点比mid大， 那么我们可
以继续在左半区间查找， 这里面一定存在一个peak， 为什么这么说呢？ 假设此时的区间范围为[0, mid -
1]， 因为num[mid - 1]一定大于num[mid]了， 如果num[mid - 2] <= num[mid - 1]， 那么num[mid - 1]就是一
个peak。 如果num[mid - 2] > num[mid - 1]， 那么我们就继续在[0, mid - 2]区间查找， 因为num[-1]为负无
穷， 所以最终我们绝对能在左半区间找到一个peak。 同理右半区间一样。
*/
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;

        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            int mid = (right + left) / 2;
            if (nums[mid] > nums[mid + 1])
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
