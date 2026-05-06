// Problem: Edit Distance
// Platform: LeetCode
// Link: https://leetcode.com/problems/edit-distance/
// time complexity: O(m*n) - where m and n are the lengths of the two input strings word1 and word2. We need to fill a dp table of size (m+1) x (n+1), and each cell takes O(1) time to compute.
// space complexity: O(m*n) - for the dp table.

class Solution
{
public:
    int solve(int i, int j, string word1, string word2, int n, int m,
              vector<vector<int>> &dp)
    {
        if (dp[i][j] != -1)
            return dp[i][j];
        // word1 শেষ, word2 এর বাকিটা insert
        if (i == n)
        {
            return m - j;
        }
        // word2 শেষ, word1 এর বাকিটা delete
        else if (j == m)
        {
            return n - i;
        }
        if (word1[i] == word2[j])
        {
            return dp[i][j] = solve(i + 1, j + 1, word1, word2, n, m, dp);
        }
        else
        {
            return dp[i][j] = min({
                                  // replace
                                  solve(i + 1, j + 1, word1, word2, n, m, dp),
                                  // delete
                                  solve(i + 1, j, word1, word2, n, m, dp),
                                  // insert
                                  solve(i, j + 1, word1, word2, n, m, dp),
                              }) +
                              1;
        }
    }
    int minDistance(string word1, string word2)
    {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(0, 0, word1, word2, n, m, dp);
    }
};