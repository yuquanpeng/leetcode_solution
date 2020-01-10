/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (57.35%)
 * Likes:    2699
 * Dislikes: 87
 * Total Accepted:    471.8K
 * Total Submissions: 803.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
/*
题目分析: 这道题很直接， 几乎算是没有坑， 相信大家都可以理解题目的要求. Permutation的解题方法和
Combination几乎是相同的， 唯一需要注意的是， Permutation需要加一个bool类型的数组来进行记录哪个
元素访问了， 哪个没有， 这样才不会导致重复出现， 并且不同于Combination的一点是， Permutation不需
要排序.
解题思路: 遇到这种问题， 很显然， 第一个想法我们首先回去想到DFS,递归求解， 对于数组中的每一个元
素， 找到以他为首节点的Permutations,这就要求在递归中， 每次都要从数组的第一个元素开始遍历， 这
样， ， 就引入了另外一个问题， 我们会对于同一元素访问多次， 这就不是我们想要的答案了， 所以我们引
入了一个bool类型的数组， 用来记录哪个元素被遍历了(通过下标找出对应).在对于每一个Permutation进行
求解中， 如果访问了这个元素,我们将它对应下表的bool数组中的值置为true,访问结束后， 我们再置为false.
时间复杂度分析: 这道题同Combination,所以对于这道题的解答， 时间复杂度同样是O(n!)
*/

// @lc code=start
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> permutations;
        if (nums.size() == 0)
            return permutations;
        vector<int> curr;
        vector<bool> isVisited(nums.size(), false);
        backTracking(permutations, curr, isVisited, nums);
        return permutations;
    }

    void backTracking(vector<vector<int>> &res, vector<int> curr, vector<bool> isVisited, vector<int> nums)
    {
        if (curr.size() == nums.size())
        {
            res.push_back(curr);
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (isVisited[i] == false)
            {
                isVisited[i] = true;
                curr.push_back(nums[i]);
                backTracking(res, curr, isVisited, nums);
                isVisited[i] = false;
                curr.pop_back();
            }
        }
    }
};
// @lc code=end
