/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (54.03%)
 * Total Accepted:    188.7K
 * Total Submissions: 349.2K
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given a non-empty array of integers, return the k most frequent elements.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * Note: 
 * 
 * 
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is
 * the array's size.
 * 
 * 
 */
class Solution
{
  public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        assert(k > 0);
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
            freq[nums[i]]++;

        assert(k <= freq.size());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (unordered_map<int, int>::iterator iter = freq.begin();
             iter != freq.end(); iter++)
        {
            if (pq.size() == k)
            {
                if (iter->second > pq.top().first)
                {
                    pq.pop();
                    pq.push(make_pair(iter->second, iter->first));
                }
            }
            else
                pq.push(make_pair(iter->second, iter->first));
        }
        vector<int> res;
        while (!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
