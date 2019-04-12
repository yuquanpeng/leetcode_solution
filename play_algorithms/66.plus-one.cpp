/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (40.91%)
 * Total Accepted:    372.8K
 * Total Submissions: 910.5K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty array of digits representing a non-negative integer, plus
 * one to the integer.
 * 
 * The digits are stored such that the most significant digit is at the head of
 * the list, and each element in the array contain a single digit.
 * 
 * You may assume the integer does not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * 
 */
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> res(digits.size(), 0);
        int sum = 0;
        int carry = 1; //进位
        //从地位向高位计算
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            sum = carry + digits[i]; //计算和
            carry = sum / 10;        //进位
            res[i] = sum % 10;       //当前位余数
        }
        if (carry > 0) //还有进位
            res.insert(res.begin(), carry);
        return res;
    }
};
