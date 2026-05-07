// Problem: Decode Ways
// Platform: LeetCode
// Link: https://leetcode.com/problems/decode-ways/
// time complexity: O(n) - where n is the length of the input string s. We need to fill a dp table of size (n+1), and each cell takes O(1) time to compute.
// space complexity: O(n) - for the dp table.

class Solution
{
public:
    int solve(int i, string &s, int n, vector<int> &dp)
    {
        if (dp[i] != -1)
            return dp[i];
        // full string sesh and deccode hoi gese
        if (i == n)
            return 1;
        // 1st a 0 thkle decode kora possible na..
        if (s[i] == '0')
            return 0;
        // Single digit নিলাম — শুধু s[i] নিলাম। তাহলে পরের কাজ শুরু হবে i+1 থেকে। i+1 কারণ — একটা character  er kaaj sesh, পরেরটায় যাও।
        int first = solve(i + 1, s, n, dp);
        // duita digit nicchi and valid kina chk kortesi..
        if (i + 1 < n)
        {
            // duita character theke ekta number bananor formula..
            int twoDigit = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (twoDigit >= 10 && twoDigit <= 26)
            {
                // Two digit নিলাম — s[i] আর s[i+1] একসাথে নিলাম, valid হলে। তাহলে পরের কাজ শুরু হবে i+2 থেকে।
                first += solve(i + 2, s, n, dp);
            }
        }
        return dp[i] = first;
    }
    int numDecodings(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return solve(0, s, n, dp);
    }
};