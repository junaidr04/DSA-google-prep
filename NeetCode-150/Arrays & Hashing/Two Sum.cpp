// Problem: Two Sum
// Platform: NeetCode
// Link: https://neetcode.io/problems/two-integer-sum/question
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


// Time Complexity: O(n)
// Space Complexity: O(n) 


class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // value -> index store korbe
        unordered_map<int, int> freq;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            // current element
            int num = nums[i];
            // complement — ei ta map e thakle answer pawa gese
            int need = target - num;
            // complement ki age dekha gese?
            if (freq.find(need) != freq.end())
            {
                // freq[need] = complement er index
                // i = current element er index
                return {freq[need], i};
            }
            // na thakle current element ta map e rakho
            // porer element er jonno kaje ashbe
            freq[num] = i;
        }
        // problem guaranteed e solution ache
        // tai ei line e asar kotha na
        return {-1, -1};
    }
};