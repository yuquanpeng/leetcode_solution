/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (44.52%)
 * Likes:    11870
 * Dislikes: 410
 * Total Accepted:    2.1M
 * Total Submissions: 4.8M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 */
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        //边角问题
        vector<int> res;
        if (nums.size() <= 1)
            return res;

        //新建一个map<key, value> 模式的来存储nums里面的元素和index
        unordered_map<int, int> myMap;
        for (int i = 0; i < nums.size(); ++i)
            myMap[nums[i]] = i;

        for (int i = 0; i < nums.size(); ++i)
        {
            int rest_val = target - nums[i];
            if (myMap.find(rest_val) != myMap.end())
            {
                int index = myMap[rest_val];
                if (index == i)
                    continue; //如果是同一个数字， 我们就pass， 是不会取这个值的
                if (index < i)
                {
                    res.push_back(index); //这里+1是因为题目说明白了要non-zero based index
                    res.push_back(i);
                    return res;
                }
                else
                {
                    res.push_back(i);
                    res.push_back(index);
                    return res;
                }
            }
        }
        return res;
    }
};
