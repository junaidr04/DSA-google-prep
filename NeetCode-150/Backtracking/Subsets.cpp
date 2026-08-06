// Problem: Subsets
// Platform: NeetCode
// Link: https://neetcode.io/problems/subsets
// time complexity: O(n * 2^n); প্রতিটা element er jonno 2-bar operation (include or exclude). rotyekta subset ans.push_back(curr) korar shomoy, curr vector ta copy hoy ans e — ei copy operation e average O(N) time lage (subset er average length ~N/2, kintu Big-O te amra N dhori worst case er jonno) Tai total: 2^N (total subsets) × N (copy cost) = O(N × 2^N)
// space complexity: O(n); recursion stack e shob element store korte hobe


class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans; // final answer — shob subset ekhane store hobe
        vector<int> curr;        // current path — ekhon porjonto ja select kora hoyeche
        // backtrack function ke shurute call kora hocche
        // start = 0 mane amra nums[0] theke consider kora shuru korbo
        backtrack(0, nums, curr, ans);
        return ans; // shob subset shoho ans return kora hocche
    }

    void backtrack(int start, vector<int> &nums, vector<int> &curr, vector<vector<int>> &ans)
    {
        // ---- KEY POINT ----
        // Subsets problem e PROTYEKTA node (function call) ekta VALID subset.
        // Tai kono condition chara-i curr ke ans e push kore dicchi.
        // Eta empty subset [] theke shuru kore, shob intermediate subset-o capture kore.
        ans.push_back(curr);
        // start theke shuru kore nums er shesh porjonto loop
        // start use kora hocche jate age select kora element gulo abar consider na hoy
        // (eta duplicate subset [1,2] and [2,1] toiri howa theke atkay)
        for (int i = start; i < nums.size(); i++)
        {
            // ---- CHOOSE ----
            // nums[i] ke current path e add kortesi (ei element ke "select" korlam)
            curr.push_back(nums[i]);
            // ---- EXPLORE ----
            // recursive call — porer bar i+1 theke shuru hobe
            // (i+1 dewa hocche jate nums[i] abar consider na hoy —
            //  eta amader "start index" trick, duplicate prevent kore)
            backtrack(i + 1, nums, curr, ans);
            // ---- UN-CHOOSE (backtrack step) ----
            // recursive call theke fere asar por, nums[i] ke remove kore dicchi
            // jate next iteration e (i+1, i+2...) current path clean thake
            // Eta na korle purono element gulo state e reye jabe, wrong subset toiri hobe
            curr.pop_back();
        }
        return;
    }
};