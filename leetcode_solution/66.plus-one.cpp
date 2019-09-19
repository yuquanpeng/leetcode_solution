/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 *
 * https://leetcode.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (41.65%)
 * Likes:    985
 * Dislikes: 1746
 * Total Accepted:    442.9K
 * Total Submissions: 1.1M
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
        int one = 1;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            sum = one + digits[i];
            one = sum / 10;
            res[i] = sum % 10;
        }
        if (one > 0)
            res.insert(res.begin(), one);
        return res;
    }
};
