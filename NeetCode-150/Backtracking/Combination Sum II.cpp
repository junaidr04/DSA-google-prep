// Problem: Combination Sum II
// Platform: NeetCode
// Link: https://neetcode.io/problems/combination-sum-ii
// time complexity: O(2^N); worst case e shob element select kora jay, tai 2^N combination possible. N = number of candidates
// space complexity: O(N); recursion stack e shob element store korte hobe.


class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target)
    {
        vector<vector<int>> ans;
        vector<int> curr;

        // ⚠️ SORT kora MUST — jate same-value element gulo pashapashi thake
        // eta na korle duplicate-skip condition (nums[i]==nums[i-1]) kaj korbe na
        sort(nums.begin(), nums.end());
        backtrack(0, nums, target, curr, ans);
        return ans;
    }

    void backtrack(int start, vector<int>& nums, int target, vector<int>& curr, vector<vector<int>>& ans)
    {
        // ---- BASE CASE 1: SUCCESS ----
        // target 0 mane curr-er shob element-er sum exactly target-er shoman
        if (target == 0)
        {
            ans.push_back(curr);
            return;
        }
        // ---- BASE CASE 2: PRUNE ----
        // target negative mane overshoot hoye geche, ei path ar kaje lagbe na
        // (array sorted thakay, egiye gele target aro negative-i hobe, tai safe prune)
        if (target < 0)
        {
            return;
        }
        for (int i = start; i < nums.size(); i++)
        {
            // ---- DUPLICATE SKIP ----
            // i > start mane: ei loop-e eta first choice na (age already ekta try kora hoyeche)
            // nums[i] == nums[i-1] mane: age-r element-er shoman value
            // Duitai true hole mane — "ei SAME LEVEL-e, same value abar try korchi"
            // jeta already ager iteration-e (i-1 diye) fully explore kora hoye geche
            // tai eta skip na korle same combination duibar toiri hobe
            //
            // i > start na likhle ki hobe? — jokhon i==start (loop-er first element),
            // tokhon nums[i-1] hocche PREVIOUS RECURSION LEVEL-er element,
            // shei value diye already ekta valid branch explore kora hoyeche (etar
            // "child" hisebe), tai eta skip kora UCHIT NA — nahole shob combination
            // miss hoye jabe (jemon [1,1,6] — dutoi 1 kintu duitai dorkar)
            if (i > start && nums[i] == nums[i - 1])
            {
                continue;
            }
            // ---- CHOOSE ----
            curr.push_back(nums[i]);
            // ---- EXPLORE ----
            // i+1 pathacchi (i na) — karon ei problem-e protyek element EKBAR-i
            // use kora jay (index unique), repeat kora jabe na
            backtrack(i + 1, nums, target - nums[i], curr, ans);
            // ---- UN-CHOOSE (backtrack) ----
            curr.pop_back();
        }
        return;
    }
};