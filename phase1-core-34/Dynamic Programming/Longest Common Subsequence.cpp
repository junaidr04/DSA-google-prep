// Problem: Longest Common Subsequence
// Platform: LeetCode
// Link: https://leetcode.com/problems/longest-common-subsequence/
// time complexity: O(n*m) - where n is the length of text1 and m is the length of text2. We need to fill a dp array of size n*m.
// space complexity: O(n*m) - for the dp array.

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};