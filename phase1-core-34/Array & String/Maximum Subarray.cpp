// Problem: Maximum Subarray
// Platform: LeetCode
// Link: https://leetcode.com/problems/maximum-subarray/
// time complexity: O(n) for Kadane's algorithm, O(n log n) for divide and conquer approach
// space complexity: O(n) for divide and conquer approach, O(1) for Kadane's algorithm

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        int ans = dp[0];
        for (int i = 1; i < n; i++)
        {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};