/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (40.92%)
 * Total Accepted:    366.8K
 * Total Submissions: 895.7K
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
class Solution
{
  public:
    vector<string> letterCombinations(string digits)
    {
        res.clear();
        if (digits == "")
            return res;
        findCombination(digits, 0, "");
        return res;
    }

  private:
    const string letterMaps[10] = {
        " ",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"};
    vector<string> res;

    void
    findCombination(const string &digits, int index, const string &s)
    {
        if (index == digits.size())
        {
            res.push_back(s);
            return;
        }
        char c = digits[index];
        assert(c >= '0' && c <= '9' && c != '1');
        string letters = letterMaps[c - '0'];
        for (int i = 0; i < letters.size(); i++)
            findCombination(digits, index + 1, s + letters[i]);
        return;
    }
};
