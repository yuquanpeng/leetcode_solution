/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */
class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &num)
    {
        vector<vector<int>> permutations;
        if (num.size() == 0)
            return permutations;
        vector<int> curr;
        vector<bool> isVisited(num.size(), false);
        /* we need to sort the input array here because of this array
contains the duplication value, then we need to skip the duplication
value for the final result */
        sort(num.begin(), num.end());
        DFS(permutations, curr, num, isVisited);
        return permutations;
    }
    void DFS(vector<vector<int>> &ret, vector<int> curr, vector<int> num, vector<bool> isVisited)
    {
        if (curr.size() == num.size())
        {
            ret.push_back(curr);
            return;
        }
        for (int i = 0; i < num.size(); ++i)
        {
            if (isVisited[i] == false)
            {
                isVisited[i] = true;
                curr.push_back(num[i]);
                DFS(ret, curr, num, isVisited);
                isVisited[i] = false;
                curr.pop_back();
                while (i < num.size() - 1 && num[i] == num[i + 1]) //we use this while loop to skip the duplication value in the input array.
                    ++i;
            }
        }
    }
};
