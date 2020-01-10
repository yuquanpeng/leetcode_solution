/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (55.00%)
 * Likes:    2580
 * Dislikes: 62
 * Total Accepted:    447.1K
 * Total Submissions: 792.7K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
/*
这题其实就是列出集合里面的所有子集合， 同时要求子集合元素需要升序排列。
首先我们需要对集合排序， 对于一个n元素的集合， 首先我们取第一个元素， 加入子集合中， 后面的n - 1个
元素可以认为是第一个元素的子节点， 我们依次遍历， 譬如遍历到第二个元素的时候， 后续的n - 2个元素
又是第二个元素的子节点， 再依次遍历处理， 直到最后一个元素， 然后回溯， 继续处理。 处理完第一个元
素之后， 我们按照同样的方式处理第二个元素。
譬如上面的[1, 2, 3]， 首先取出1， 加入子集合， 后面的2和3就是1的子节点， 先取出2， 把[1, 2]加入子集
合， 后面的3就是2的子节点， 取出3， 把[1, 2, 3]加入子集合。 然后回溯， 取出3， 将[1, 3]加入子集合。
1处理完成之后， 我们可以同样方式处理2， 以及3。
*/

// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int> &nums)
    {
        if (nums.empty())
            return res;
        sort(nums.begin(), nums.end());
        res.push_back(vector<int>());
        vector<int> curr;
        generate(0, curr, nums);
        return res;
    }
    void generate(int start, vector<int> &curr, vector<int> &nums)
    {
        if (start == nums.size())
            return;
        for (int i = start; i < nums.size(); i++)
        {
            curr.push_back(nums[i]);
            res.push_back(curr);
            generate(i + 1, curr, nums);
            curr.pop_back();
        }
    }
};
// @lc code=end
