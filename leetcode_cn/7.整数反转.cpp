/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 *
 * https://leetcode-cn.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (31.81%)
 * Total Accepted:    90.3K
 * Total Submissions: 284K
 * Testcase Example:  '123'
 *
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 * 
 * 示例 1:
 * 
 * 输入: 123
 * 输出: 321
 * 
 * 
 * 示例 2:
 * 
 * 输入: -123
 * 输出: -321
 * 
 * 
 * 示例 3:
 * 
 * 输入: 120
 * 输出: 21
 * 
 * 
 * 注意:
 * 
 * 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回
 * 0。
 * 
 */
class Solution
{
  public:
    int reverse(int x)
    {
        int reverse[34];
        int index = 1;
        bool flag = false;
        while (x != 0)
        {
            if (x % 10 == 0 && flag == false)
                x /= 10;
            else
            {
                reverse[index] = x % 10;
                flag = true;
                x /= 10;
                index++;
            }
        }
        long sum = 0;
        long a = 1;
        for (int i = 1; i < index - 1; i++)
            a *= 10;
        for (int i = 1; i < index; i++)
        {
            sum += reverse[i] * a;
            a = a / 10;
        }
        if (sum > 0x7fffffff || sum < (signed int)0x80000000)
            return 0;
        else
            return sum;
    }
};
