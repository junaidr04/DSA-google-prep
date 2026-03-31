// Problem: Two Sum
// Platform: LeetCode
// Link: https://leetcode.com/problems/two-sum/
// time complexity: O(n^2) for brute-force approach, O(n) for hash map approach
// space complexity: O(1) for brute-force approach, O(n) for hash map approach

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

// Time Complexity: O(n log n) for sorting and O(n) for two-pointer approach, overall O(n log n)
// Space Complexity: O(n) for sorting and O(1) for two-pointer approach, overall O(n)

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> freq;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            int need = target - num;
            if (freq.find(need) != freq.end())
            {
                return {freq[need], i};
            }
            freq[num] = i;
        }
        return {-1, -1};
    }
};