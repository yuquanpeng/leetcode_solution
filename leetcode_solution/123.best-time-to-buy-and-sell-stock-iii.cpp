/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */
/*
前两道都是Easy题，第三道开始变成Hard。题目要求是可以进行两次交易，需要使用动态规划。我们维护两种量，一个是当前到达第i天可以最多进行j次交易，最好的利润是多少（global[i][j]），另一个是当前到达第i天，最多可进行j次交易，并且最后一次交易在当天卖出的最好的利润是多少（local[i][j]）。两个数组的递推公式如下：

local[i+1][j+1]=max(local[i][j+1]+diff,global[i][j]+max(diff,0))

global[i+1][j+1]=max(global[i][j+1],local[i+1][j+1])

https://blog.csdn.net/linhuanmars/article/details/23236995
 */
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;
        int local[3] = {0};
        int global[3] = {0};

        //say there are 5 days, i iterates to 3(not 4). After every iteration of i, global[] return the profit up to (i+1)th days.
        for (int i = 0; i < prices.size() - 1; i++)
        {
            int diff = prices[i + 1] - prices[i];
            for (int j = 2; j >= 1; j--)
            {
                local[j] = max(global[j - 1] + (diff > 0 ? diff : 0), local[j] + diff);
                global[j] = max(local[j], global[j]);
            }
        }
        return global[2];
    }
};
