/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */
/*
我们只需要遍历一次数组， 通过一个变量记录当前最低价格， 同时算出此
次交易利润， 并与当前最大值比较就可以了
 */
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() <= 1)
            return 0;
        int minP = prices[0];
        int profit = prices[1] - prices[0];
        for (int i = 2; i < prices.size(); i++)
        {
            minP = min(prices[i - 1], minP);
            profit = max(profit, prices[i] - minP);
        }
        if (profit < 0)
            return 0;
        return profit;
    }
};
