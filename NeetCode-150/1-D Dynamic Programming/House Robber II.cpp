// Problem: House Robber II
// Platform: NeetCode
// Link: https://neetcode.io/problems/house-robber-ii
// time complexity: O(n) Karon loop ekbar i=2 theke i=n-1 porjonto chole, mane total n-2 ≈ n iterations. Protita iteration e O(1) kaj hocche (shudhu addition and max), tai overall time complexity linear, O(n).
// space complexity: O(n) Karon dp vector er size n — mane tumi n ta extra space use korcho store korar jonno. Tai space complexity O(n).


/*
[2,3,2]

n = 3

Case A: robRange(nums, 0, 1)
  s=0, e=1, s != e
  dp[0] = 2
  dp[1] = max(2,3) = 3
  loop chalবে na (s+2=2 > e=1)
  return dp[1] = 3

Case B: robRange(nums, 1, 2)
  s=1, e=2, s != e
  dp[1] = 3
  dp[2] = max(3,2) = 3
  loop chalবে na (s+2=3 > e=2)
  return dp[2] = 3

Final: max(3, 3) = 3 ✅ (matches expected output)

 and

[1,2,3,1] diye:
n = 4

Case A: robRange(nums, 0, 2)
  dp[0] = 1
  dp[1] = max(1,2) = 2
  i=2: dp[2] = max(dp[1], dp[0]+nums[2]) = max(2, 1+3) = 4
  return dp[2] = 4

Case B: robRange(nums, 1, 3)
  dp[1] = 2
  dp[2] = max(2,3) = 3
  i=3: dp[3] = max(dp[2], dp[1]+nums[3]) = max(3, 2+1) = 3
  return dp[3] = 3

Final: max(4, 3) = 4 ✅ (matches expected output)
*/

class Solution
{
public:
    // Helper function: normal House Robber logic, kintu shudhu..'s' (start) theke 'e' (end) porjonto range e kaj kore
    int robRange(vector<int> &nums, int s, int e)
    {
        // Edge case: jodi range e shudhu 1 ta bari thake (s==e).. tahole seta chara option nai, direct oitai return koro
        if (s == e)
            return nums[s];
        int n = nums.size();

        // dp[i] = index s theke i porjonto dekhle maximum koto taka churi kora jay
        // pura array er size (n) diye banaলাম, jate index s theke e porjonto shob
        // valid thake (amra shudhu s theke e porjonto use korবো, baki part use hবে na)
        vector<int> dp(n, 0);

        // Base case 1: range er প্রথম bari (index s) e pouchale max money
        // shudhu oi barir taka, karon age kono bari nai ei range e
        dp[s] = nums[s];

        // Base case 2: range er 2nd bari (index s+1) porjonto dekhle max money
        // duitা bari (s, s+1) adjacent, tai duitao churi kora jabe na
        // tai jeta beshi taka ache shetai nibo
        dp[s + 1] = max(nums[s], nums[s + 1]);

        // Loop 's+2' theke 'e' porjonto - protita bari e maximum money calculate korchi
        for (int i = s + 2; i <= e; i++)
        {
            // Duita choice:
            //   1) i-th bari CHURI NA KORA -> dp[i-1] jotoi silo totoi thakবে
            //   2) i-th bari CHURI KORA -> i-1 bari churi korte parba na (adjacent)
            //      tai dp[i-2] (i-2 porjonto max money) + nums[i] (ei barir taka)
            // Duitার modhe MAXIMUM ta nিবো
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        // dp[e] e thakবে 's' theke 'e' porjonto shob bari dekhar por maximum money
        return dp[e];
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        // Edge case: shudhu 1 ta bari thakle, circular constraint apply hবে na
        // (nijer sathe nijer adjacent hওয়ার প্রশ্ন ওঠে না), direct oitai churi koro
        if (n == 1)
            return nums[0];

        // Circular constraint: house 0 ar house (n-1) eksathe churi kora jabe na
        // Tai duitা আলাদা case বিবেচনা kori:
        //
        // Case A: robRange(nums, 0, n-2)
        //   -> house 0 ke RAKHO, house (n-1) ke BAAD dao
        //      (range: index 0 theke n-2 porjonto)
        //
        // Case B: robRange(nums, 1, n-1)
        //   -> house 0 ke BAAD dao, house (n-1) ke RAKHO
        //      (range: index 1 theke n-1 porjonto)
        //
        // Duitার modhe jeta MAXIMUM shetai final answer,
        // karon duitা case e kokhono house 0 ar house n-1 eksathe thakবে na
        return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
    }
};