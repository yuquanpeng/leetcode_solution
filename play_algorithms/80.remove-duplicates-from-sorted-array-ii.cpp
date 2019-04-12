/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
 *
 * algorithms
 * Medium (39.83%)
 * Total Accepted:    194.4K
 * Total Submissions: 487.2K
 * Testcase Example:  '[1,1,1,2,2,3]'
 *
 * Given a sorted array nums, remove the duplicates in-place such that
 * duplicates appeared at most twice and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this by modifying
 * the input array in-place with O(1) extra memory.
 * 
 * Example 1:
 * 
 * 
 * Given nums = [1,1,1,2,2,3],
 * 
 * Your function should return length = 5, with the first five elements of nums
 * being 1, 1, 2, 2 and 3 respectively.
 * 
 * It doesn't matter what you leave beyond the returned length.
 * 
 * Example 2:
 * 
 * 
 * Given nums = [0,0,1,1,1,1,2,3,3],
 * 
 * Your function should return length = 7, with the first seven elements of
 * nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.
 * 
 * It doesn't matter what values are set beyond the returned length.
 * 
 * 
 * Clarification:
 * 
 * Confused why the returned value is an integer but your answer is an array?
 * 
 * Note that the input array is passed in by reference, which means
 * modification to the input array will be known to the caller as well.
 * 
 * Internally you can think of this:
 * 
 * 
 * // nums is passed in by reference. (i.e., without making a copy)
 * int len = removeDuplicates(nums);
 * 
 * // any modification to nums in your function would be known by the caller.
 * // using the length returned by your function, it prints the first len
 * elements.
 * for (int i = 0; i < len; i++) {
 * print(nums[i]);
 * }
 * 
 * 
 */
class Solution
{
    /**对于一个排好序的数组来说， A[N + 1] >= A[N] ， 我们仍然使用两个游标i和j来处
     * 理， 假设现在j = i + 1， 如果A[i] == A[j]， 那么我们递增j， 
     * 直到A[i] != A[j]，
     *  这时候我们再设置A[i + 1] =A[j]， 同时递增i和j， 重复上述过程直到遍历结束。
     * 
     * */
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        int j = 0;
        int num = 0;
        for (int i = 1; i < n; i++)
        {
            if (nums[j] == nums[i]) //连续相等，num记录相等次数
            {
                num++;
                if (num < 2) //只移动相同数字两次，多余的相等数字会被后面的步骤覆盖掉
                    nums[++j] = nums[i];
            }
            else //遇到新的数字，后移，重新开始计数
            {
                nums[++j] = nums[i];
                num = 0;
            }
        }

        return j + 1;
    }
};
