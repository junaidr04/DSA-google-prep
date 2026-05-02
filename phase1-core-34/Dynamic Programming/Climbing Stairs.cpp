// Problem: Climbing Stairs
// Platform: LeetCode
// Link: https://leetcode.com/problems/climbing-stairs/
// time complexity: O(n)
// space complexity: O(n)

class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, 0);
        if (n == 1)
            return 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// TC: O(n) - we need to calculate the number of ways to climb n stairs, which requires us to fill the dp array up to n.
// SC: O(1) - we can optimize the space complexity to O(1) by only keeping track of the last two values instead of the entire dp array.

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        int prev2 = 1;
        int prev1 = 2;
        for (int i = 3; i <= n; i++)
        {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
