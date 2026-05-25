// Problem: 3Sum
// Platform: NeetCode
// Link: https://neetcode.io/problems/three-integer-sum/question
// time complexity: O(n²); outer loop O(n) × inner Two Pointers O(n)
// space complexity: O(1); Nothing extra space


class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // sort করো — duplicate skip আর Two Pointers এর জন্য দরকার
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            // i এর duplicate skip করো
            // একই value দিয়ে আবার শুরু করলে duplicate triplet আসবে
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            // i fix করে বাকি দুইটা pointer set করো
            int l = i + 1, r = nums.size() - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0)
                {
                    // triplet পাওয়া গেছে → result এ add করো
                    ans.push_back({nums[i], nums[l], nums[r]});

                    // দুইটা pointer ভেতরে আনো
                    l++;
                    r--;

                    // l এর duplicate skip করো
                    // same value এ আবার same triplet আসতে পারে
                    while (l < r && nums[l] == nums[l - 1])
                    {
                        l++;
                    }
                    // r এর duplicate skip করো
                    while (l < r && nums[r] == nums[r + 1])
                    {
                        r--;
                    }
                }
                else if (sum < 0)
                {
                    // sum ছোট → বড় value দরকার → l বাড়াও
                    l++;
                }
                else
                {
                    // sum বড় → ছোট value দরকার → r কমাও
                    r--;
                }
            }
        }
        return ans;
    }
};
