/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int i = 0;
        int j = 0;
        for (i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val)
                continue;
            nums[j] = nums[i];
            j++;
        }
        return j;
    }
};
