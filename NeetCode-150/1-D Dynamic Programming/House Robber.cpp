// Problem: House Robber
// Platform: NeetCode
// Link: https://neetcode.io/problems/house-robber
// time complexity: O(n) Karon loop ekbar i=2 theke i=n-1 porjonto chole, mane total n-2 ≈ n iterations. Protita iteration e O(1) kaj hocche (shudhu addition and max), tai overall time complexity linear, O(n).
// space complexity: O(n) Karon dp vector er size n — mane tumi n ta extra space use korcho store korar jonno. Tai space complexity O(n).

class Solution {
public:
    int rob(vector<int>& nums) {
        // n = koto ta bari ache
        int n = nums.size();
        
        // Edge case: jodi shudhu 1 ta bari thake, tahole seta chara kono option nai - direct oitai churi korte hobe
        if(n == 1)
            return nums[0];
        
        // dp[i] = 0 theke i porjonto bari dekhle maximum koto taka churi kora jay
        // size n rakhlam karon valid index 0 theke n-1 porjonto lagbe
        vector<int> dp(n, 0);
        
        // Base case 1: dp[0] = nums[0], Shudhu 1 ta bari (index 0) thakle, maximum shetai churi kora - option nai
        dp[0] = nums[0];
        
        // Base case 2: dp[1] = max(nums[0], nums[1])
        // Duita bari thakle (adjacent), duitao churi kora jabe na, tai jeta beshi taka ache shetai nibo
        dp[1] = max(nums[0], nums[1]);
        // Loop i=2 theke n-1 porjonto - protita bari e maximum money calculate korchi
        for(int i = 2; i <= n-1; i++)
        {
            // dp[i] = i-th bari porjonto dekhle maximum money
            // Duita choice ache:
            //   1) i-th bari CHURI NA KORA -> tahole dp[i-1] jotoi silo totoi thakbe
            //   2) i-th bari CHURI KORA -> tahole i-1 bari churi korte parba na (adjacent restriction)
            //      tai dp[i-2] (i-2 porjonto max money) + nums[i] (ei barir taka)
            // Duitar modhe MAXIMUM ta nibo, karon amra shobcheye beshi taka chai
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        // dp[n-1] e thakbe shob bari dekhar por maximum money - eitai final answer
        return dp[n-1];
    }
};


// Time Complexity: O(n) (same as before, loop ekbar chole)
// Space Complexity: O(1) (age silo O(n), ekhon shudhu 2 ta variable — eta হলো real optimization)


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // prev2 = dp[i-2] represent kore, prev1 = dp[i-1] represent kore
        // shuru te dp[0] ar dp[1] er base case emনভাবে boshai:
        // prev2 = "dp[-1]" hisebe dhori (kono bari nai age), tai 0
        int prev2 = 0;
        // prev1 = dp[0] = nums[0] (prothom barir maximum)
        int prev1 = 0;
        // Loop protita bari (index 0 theke n-1) niye
        for(int i = 0; i < n; i++)
        {
            // curr = dp[i] = max(dp[i-1], dp[i-2] + nums[i])
            // prev1 -> dp[i-1], prev2 -> dp[i-2]
            int curr = max(prev1, prev2 + nums[i]);
            // Slide window: age er prev1 ekhon prev2 hবে
            prev2 = prev1;
            // curr ekhon prev1 hবে (porer iteration er jonno)
            prev1 = curr;
        }
        // Loop shesh hবার por prev1 e thakবে shob bari dekhার por maximum money
        return prev1;
    }
};
