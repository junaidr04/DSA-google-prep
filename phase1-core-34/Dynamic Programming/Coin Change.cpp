// Problem: Coin Change
// Platform: LeetCode
// Link: https://leetcode.com/problems/coin-change/
// time complexity: O(n*m) - where n is the amount and m is the number of coins. We need to fill a dp array of size n for each of the m coins.
// space complexity: O(n) - we need to store the minimum number of coins needed for each amount from 0 to n in a dp array.

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int inf = 1e9;
        vector<int> dp(amount + 1, inf);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int c : coins)
            {
                if (i - c >= 0)
                {
                    dp[i] = min(dp[i], 1 + dp[i - c]);
                }
            }
        }
        if (dp[amount] == inf)
        {
            return -1;
        }
        else
        {
            return dp[amount];
        }
    }
};