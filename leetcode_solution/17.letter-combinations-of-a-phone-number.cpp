/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (42.96%)
 * Likes:    2804
 * Dislikes: 350
 * Total Accepted:    480.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */
/*
题目翻译: 给定一个字符串数字， 返回这个字符串数字在电话表上可能的combination， 一个map的电话键
盘在上图已经给出.
题目分析: 这道题目的给出， 具体的解题思路是和combination是相同的， 不同的地方是我们要先建一个
dictionary,以方便查找.之后用combination的相同方法， 对于每一个数字， 在dictionary中查找它所对应的说
有的数字.
解题思路: 我是用字符串数组来构建这个dictionary的， 用于下标代表数字， 例如， 下标为2， 我的字典就会
有这种对应的关系:dic[2] = "abc".只要把给定数字字符串的每一个数字转换为int类型， 就可以根据字典查找
出这个数字所对应的所有字母.当然， 再构建字典的时候， 我们需要注意dic[0] = "", dic[1] = "".这两个特殊的
case， 因为电话键盘并没有这两个数字相对应的字符串
*/

// @lc code=start
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if (digits == "")
            return res;
        vector<string> dic;
        string tmp;
        dic.push_back(" ");
        dic.push_back(" ");
        dic.push_back("abc");
        dic.push_back("def");
        dic.push_back("ghi");
        dic.push_back("jkl");
        dic.push_back("mno");
        dic.push_back("pqrs");
        dic.push_back("tuv");
        dic.push_back("wxyz");
        combinations(res, tmp, digits, dic, 0);
        return res;
    }
    void combinations(vector<string> &res, string tmp, string digits, vector<string> dic, int level)
    {
        if (level == digits.size())
        {

            res.push_back(tmp);
            return;
        }
        int index = digits[level] - '0';
        for (int i = 0; i < dic[index].size(); ++i)
        {
            tmp.push_back(dic[index][i]);
            combinations(res, tmp, digits, dic, level + 1);
            tmp.pop_back();
        }
    }
};
// @lc code=end
