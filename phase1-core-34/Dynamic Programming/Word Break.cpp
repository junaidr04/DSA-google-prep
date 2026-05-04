// Problem: Word Break
// Platform: LeetCode
// Link: https://leetcode.com/problems/word-break/
// time complexity: O(n^3) - where n is the length of the input string s. We need to check all possible substrings of s, which takes O(n^2) time, and for each substring, we need to check if it is in the dictionary, which takes O(n) time in the worst case.
// space complexity: O(n + m) - for the dp array and the dictionary.

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        // word Set বানাও
        unordered_set<string> word(wordDict.begin(), wordDict.end());
        // dp array বানাও. shuru dp[0] = true, baki false
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        // dp fill karo
        for (int i = 0; i <= n; i++)
        {
            for (int j = i; j < n; j++)
            {
                // j - i + 1 length er substring check karo, jodi dp[i] true hoy and oi substring word set e thake, tahole dp[j + 1] ke true koro
                if (dp[i] == true && word.count(s.substr(i, j - i + 1)))
                {
                    // dp[j + 1] ke true koro
                    dp[j + 1] = true;
                }
            }
        }
        return dp[n];
    }
};