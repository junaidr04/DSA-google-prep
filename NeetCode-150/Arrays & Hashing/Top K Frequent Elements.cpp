// Problem: Top K Frequent Elements
// Platform: Neetcode
// Link: https://neetcode.io/problems/top-k-elements-in-list/question
// time complexity: O(n)
// space complexity: O(n)


class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // Step 1: frequency count
        unordered_map<int, int> freq;
        for (int n : nums)
        {
            freq[n]++;
        }
        // Step 2: bucket বানাও
        vector<vector<int>> bucket(nums.size() + 1);
        // frequency count এর element টা bucket[count] এ রাখো।
        for (auto &[num, count] : freq)
        {
            bucket[count].push_back(num);
        }
        // Step 3: শেষ থেকে k টা নাও
        vector<int> result;
        for (int i = bucket.size() - 1; i >= 0; i--)
        {
            for (int num : bucket[i])
            {
                result.push_back(num);
                if (result.size() == k)
                    return result;
            }
        }
        return result;
    }
};