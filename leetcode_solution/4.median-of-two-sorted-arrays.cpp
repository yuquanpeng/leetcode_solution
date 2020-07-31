/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (28.11%)
 * Likes:    5963
 * Dislikes: 906
 * Total Accepted:    596.3K
 * Total Submissions: 2.1M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 *  
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        const int m = nums1.size();
        const int n = nums2.size();
        int total = m + n;
        if (total & 0x1)
            return findMedian(nums1.begin(), m, nums2.begin(), n, total / 2 + 1);
        else
            return (findMedian(nums1.begin(), m, nums2.begin(), n, total / 2) +
                    findMedian(nums1.begin(), m, nums2.begin(), n, total / 2 + 1)) /
                   2.0;
    }

private:
    static int findMedian(std::vector<int>::const_iterator A, int m,
                          std::vector<int>::const_iterator B, int n, int k)
    {
        if (m > n)
            return findMedian(B, n, A, m, k);
        if (m == n)
            return *(B + k - 1);
        if (k == 1)
            return min(*A, *B);
        //divide k into two parts
        int ia = min(k / 2, m), ib = k - ia;
        if (*(A + ia - 1) < *(B + ib - 1))
            return findMedian(A + ia, m - ia, B, n, k - ia);
        else if (*(A + ia - 1) > *(B + ib - 1))
            return findMedian(A, m, B + ib, n - ib, k - ib);
        else
            return A[ia - 1];
    }
};
// @lc code=end
