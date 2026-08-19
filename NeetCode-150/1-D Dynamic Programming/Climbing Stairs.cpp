// Problem: Climbing Stairs
// Platform: NeetCode
// Link: https://neetcode.io/problems/climbing-stairs
// time complexity: O(n) Karon loop ekbar i=2 theke i=n porjonto chole, mane total n-1 ≈ n iterations. Protita iteration e O(1) kaj hocche (shudhu addition), tai overall time complexity linear, O(n).
// space complexity: O(n) Karon dp vector er size n+1 — mane tumi n+1 ta extra space use korcho store korar jonno. Tai space complexity O(n).


class Solution {
public:
    int climbStairs(int n) {
        // dp[i] = i number step porjonto pouchanor total number of ways
        // size n+1 rakhlam karon amra index 0 theke n porjonto use korbo
        vector<int> dp(n+1, 0);
        
        // Base case 1: dp[0] = 1
        // eta ekta "trick" base case - mane dhoro tumi already 0-th step e (ground e) acho
        // seikhane pouchanor "1 ta way" ache - mane kichu na kora (empty path)
        // eta শুধু recurrence relation ke thikmoto kaj korar jonno lagbe
        dp[0] = 1;
        
        // Base case 2: dp[1] = 1
        // 1 step e pouchanor shudhu 1 ta way ache - ekbar e 1 step uthe
        // (tumi 2 step uthte parba na karon tahole tumi 1 step overshoot kore felba)
        dp[1] = 1;
        
        // Loop shuru hocche i=2 theke, karon dp[0] ar dp[1] already set kora ache
        // i <= n porjonto jabe, karon amader dp[n] porjonto lagbe (final answer)
        for(int i = 2; i <= n; i++)
        {
            // Recurrence relation:
            // i step e pouchanor way = (i-1 step theke 1 step uthle) + (i-2 step theke 2 step uthle)
            // eta duita mutually exclusive way, tai add korlam (sum rule of counting)
            dp[i] = dp[i-1] + dp[i-2];
        }
        
        // dp[n] e amader final answer thakbe - n step e pouchanor total ways
        return dp[n];
    }
};

