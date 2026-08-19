// Problem: Min Cost Climbing Stairs
// Platform: NeetCode
// Link:  https://neetcode.io/problems/min-cost-climbing-stairs
// time complexity: O(n) Karon loop ekbar i=2 theke i=n porjonto chole, mane total n-1 ≈ n iterations. Protita iteration e O(1) kaj hocche (shudhu addition), tai overall time complexity linear, O(n).
// space complexity: O(n) Karon dp vector er size n+1 — mane tumi n+1 ta extra space use korcho store korar jonno. Tai space complexity O(n).


/*  
cost = [1, 2, 3]

Initially:

dp = [0, 0, 0, 0]


i = 2:

dp[2] = min(dp[1] + cost[1],
            dp[0] + cost[0])

      = min(0 + 2,
            0 + 1)

      = 1


i = 3:

dp[3] = min(dp[2] + cost[2],
            dp[1] + cost[1])

      = min(1 + 3,
            0 + 2)

      = 2

      dp = [0, 0, 1, 2]
      return dp[3];
      ans=2
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // dp[i] = index i te pouchate minimum koto cost lagbe
        // size n+1 rakhlam karon "top" (index n) porjonto amader lagbe,jeta cost array er baire (array er last valid index n-1)
        vector<int> dp(n+1, 0);
        
        // Base case 1: dp[0] = 0
        // Index 0 e pouchate kono cost lage na, karon tumi FREE e
        // index 0 othoba index 1 theke shuru korte paro (problem statement onujayi)
        dp[0] = 0;
        
        // Base case 2: dp[1] = 0
        // Same reason - index 1 eo tumi free e shuru hisebe ashte paro,
        // tai "pouchate" kono extra cost lage na
        dp[1] = 0;
        
        // Loop i=2 theke i=n porjonto - protita step e minimum cost calculate korchi
        for(int i = 2; i <= n; i++)
        {
            // dp[i] = i te pouchanor minimum cost
            // Duita way ache i te pouchanor:
            //   1) i-1 theke 1 step uthle -> cost hobe dp[i-1] + cost[i-1]
            //      (age i-1 e pouchanor cost + i-1 e pa rakhar cost)
            //   2) i-2 theke 2 step uthle -> cost hobe dp[i-2] + cost[i-2]
            //      (age i-2 e pouchanor cost + i-2 e pa rakhar cost)
            // Amra MINIMUM cost chai, tai min() use korchi
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        
        // dp[n] e thakbe "top" e (array er baire, index n) pouchanor
        // minimum total cost - eitai amader final answer
        return dp[n];
    }
};