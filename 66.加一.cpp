/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 *
 * https://leetcode-cn.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (37.65%)
 * Total Accepted:    41.2K
 * Total Submissions: 109K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 * 
 * 最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。
 * 
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 输出: [1,2,4]
 * 解释: 输入数组表示数字 123。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,3,2,1]
 * 输出: [4,3,2,2]
 * 解释: 输入数组表示数字 4321。
 * 
 * 
 */
class Solution
{
  public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> res(digits.size(), 0);
        int sum = 0;
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            sum = carry + digits[i];
            carry = sum / 10;
            res[i] = sum % 10;
        }
        if (carry > 0)
            res.insert(res.begin(), carry);
        return res;
    }
};
