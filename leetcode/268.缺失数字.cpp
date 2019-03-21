/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 缺失数字
 *
 * https://leetcode-cn.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (48.48%)
 * Total Accepted:    15.5K
 * Total Submissions: 31.8K
 * Testcase Example:  '[3,0,1]'
 *
 * 给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
 * 
 * 示例 1:
 * 
 * 输入: [3,0,1]
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [9,6,4,2,3,5,7,0,1]
 * 输出: 8
 * 
 * 
 * 说明:
 * 你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?
 * 
 * 相同的数异或得0， 不同的数异或不为0， 且此性质可以推广到多个数异或
 * 的情形。 本题的解法如下， 首先将0到n这些数进行异或运算， 然后对输
 * 入的数组进行异或运算， 最后将两个结果进行异或运算， 结果便是漏掉的
 * 数字， 因为其他数字在两个数组中都是成对出现的， 异或运算会得到0。
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
