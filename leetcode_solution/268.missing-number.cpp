/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (49.23%)
 * Likes:    1102
 * Dislikes: 1503
 * Total Accepted:    320.1K
 * Total Submissions: 649.7K
 * Testcase Example:  '[3,0,1]'
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,0,1]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * 
 * 
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant extra space complexity?
 */
/*
异或运算的一个重要性质是， 相同的数异或得0， 不同的数异或不为0， 且此性质可以推广到多个数异或的
情形。 本题的解法如下， 首先将0到n这些数进行异或运算， 然后对输入的数组进行异或运算， 最后将两个
结果进行异或运算， 结果便是漏掉的数字， 因为其他数字在两个数组中都是成对出现的， 异或运算会得到
0。
*/
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int x = 0;
        for (int i = 0; i <= nums.size(); i++)
            x ^= i;
        for (auto n : nums)
            x ^= n;
        return x;
    }
};
