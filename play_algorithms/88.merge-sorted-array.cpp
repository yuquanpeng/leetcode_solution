/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 *
 * https://leetcode.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (35.23%)
 * Total Accepted:    347.4K
 * Total Submissions: 984.4K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
 * one sorted array.
 * 
 * Note:
 * 
 * 
 * The number of elements initialized in nums1 and nums2 are m and n
 * respectively.
 * You may assume that nums1 has enough space (size that is greater or equal to
 * m + n) to hold additional elements from nums2.
 * 
 * 
 * Example:
 * 
 * 
 * Input:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * Output: [1,2,2,3,5,6]
 * 
 * 
 */
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int j = m - 1; //nums1
        int k = n - 1; //nums2
        //i指向合并后数组的位置，为了保证不对nums1的正常部分产生影响，从后向前比较
        for (int i = nums1.size() - 1; i >= 0; i--)
        {
            if (j >= 0 && k >= 0)
            {
                if (nums1[j] > nums2[k])
                {
                    nums1[i] = nums1[j];
                    j--;
                }
                else
                {
                    nums1[i] = nums2[k];
                    k--;
                }
            }
            else if (j >= 0)
            {
                nums1[i] = nums1[j];
                j--;
            }
            else if (k >= 0)
            {
                nums1[i] = nums2[k];
                k--;
            }
        }
    }
};
