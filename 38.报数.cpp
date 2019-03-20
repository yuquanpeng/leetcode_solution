/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 报数
 *
 * https://leetcode-cn.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (48.35%)
 * Total Accepted:    23.4K
 * Total Submissions: 48.3K
 * Testcase Example:  '1'
 *
 * 报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 被读作  "one 1"  ("一个一") , 即 11。
 * 11 被读作 "two 1s" ("两个一"）, 即 21。
 * 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
 * 
 * 给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
 * 
 * 注意：整数顺序将表示为一个字符串。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "1"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 4
 * 输出: "1211"
 * 
 * 
 */
class Solution
{
  public:
    string countAndSay(int n)
    {
        string res = "1";
        string tmp;
        for (int i = 2; i <= n; i++)
        {
            tmp = res;
            res = "";
            int length = tmp.length();
            int j = 1;
            int count = 1;
            while (j < length) //循环统计 分类计数
            {
                if (tmp[j] == tmp[j - 1])
                    count += 1; //记录连续数字的个数
                else
                {
                    res += to_string(count); //翻译个数 几个
                    res += tmp[j - 1];       //苹果
                    count = 1;
                }
                j++;
            }
            res += to_string(count); //处理最后一个数字
            res += tmp[length - 1];
        }
        return res;
    }
};
