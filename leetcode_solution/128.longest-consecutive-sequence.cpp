/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (43.53%)
 * Likes:    2618
 * Dislikes: 150
 * Total Accepted:    263.2K
 * Total Submissions: 600.7K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers, find the length of the longest
 * consecutive elements sequence.
 * 
 * Your algorithm should run in O(n) complexity.
 * 
 * Example:
 * 
 * 
 * Input: [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, bool> used;
        for (auto i : nums)
            used[i] = false;
        int longest = 0;
        for (auto i : nums)
        {
            if (used[i])
                continue;
            int length = 1;
            used[i] = true;

            for (int j = i + 1; used.find(j) != used.end(); ++j)
            {
                used[j] = true;
                length++;
            }
            for (int j = i - 1; used.find(j) != used.end(); --j)
            {
                used[j] = true;
                length++;
            }
            longest = max(length, longest);
        }
        return longest;
    }
};
// @lc code=end
