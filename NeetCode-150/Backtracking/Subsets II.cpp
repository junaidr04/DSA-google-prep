// Problem: Subsets II
// Platform: NeetCode
// Link: https://neetcode.io/problems/subsets-ii
// time complexity: O(N × 2^N); worst case e shob element select kora jay, tai 2^N subsets possible. N = number of candidates
// space complexity: O(N); recursion stack e shob element store korte hobe

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> ans; 
        vector<int> curr;        
        // ⚠️ SORT kora MUST — jate duplicate value gulo pashapashi thake
        // eta na korle "nums[i]==nums[i-1]" duplicate-skip condition kaj korbe na
        sort(nums.begin(), nums.end());
        backtrack(0, nums, curr, ans);
        return ans;
    }

    void backtrack(int start, vector<int> &nums, vector<int> &curr, vector<vector<int>> &ans)
    {
        // ---- UNCONDITIONAL PUSH ----
        // Subsets-er moto ekhane-o PROTYEKTA node (function call) ekta valid subset
        // kono target/condition nai, tai kono if chara-i push kore dicchi
        ans.push_back(curr);

        // start theke shuru — "forward-only" movement, jate [1,2] and [2,1]
        // duplicate hishebe na ashe (order matter kore na subset-e)
        for (int i = start; i < nums.size(); i++)
        {
            // ---- DUPLICATE SKIP ----
            // i > start mane: ei loop-e eta first choice na
            // nums[i] == nums[i-1] mane: age-r element-er shoman value
            // Duitai true hole — "ei SAME LEVEL-e same value abar try korchi"
            // jeta age-e (i-1 diye) fully explore kora hoye geche
            // Skip na korle same subset (jemon [2]) duibar toiri hobe
            if (i > start && nums[i] == nums[i - 1])
            {
                continue;
            }

            // ---- CHOOSE ----
            curr.push_back(nums[i]);

            // ---- EXPLORE ----
            // i+1 pathacchi — karon Subsets-e protyek element EKBAR-i use hoy
            // (array-er ekই index abar consider kora jabe na)
            backtrack(i + 1, nums, curr, ans);

            // ---- UN-CHOOSE (backtrack) ----
            curr.pop_back();
        }
        return;
    }
};