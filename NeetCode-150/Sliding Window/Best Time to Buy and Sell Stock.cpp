// Problem: Best Time to Buy and Sell Stock
// Platform: NeetCode
// Link: https://neetcode.io/problems/best-time-to-buy-and-sell-stock
// time complexity: O(n); single pass through the array
// space complexity: O(1); Nothing extra space


class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for (int p : prices)
        {
            minPrice = min(minPrice, p);
            int profit = p - minPrice;
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};
