// Problem: Combination Sum
// Platform: NeetCode
// Link: https://neetcode.io/problems/combination-sum
// time complexity: O(N^(T/M)); যেখানে N = number of candidates, T = target sum, M = minimum value among candidates
// space complexity: O(T/M); recursion stack e shob element store korte hobe


class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans; // final answer — shob valid combination ekhane thakbe
        vector<int> curr;        // current path — ekhon porjonto selected element gulo
        // backtrack shuru kortesi start=0 (nums[0] theke), full target diye
        backtrack(0, nums, target, curr, ans);
        return ans;
    }

    void backtrack(int start, vector<int> &nums, int target, vector<int> &curr, vector<vector<int>> &ans)
    {
        // ---- BASE CASE 1: SUCCESS ----
        // target exactly 0 mane curr-e ja select kora hoyeche, oigulor SUM
        // exactly original target er shoman hoye geche
        // tai eta ekta VALID combination — ans e push kore dao
        if (target == 0)
        {
            ans.push_back(curr);
            return; // ei path e ar element add korar dorkar nai, tai return
        }

        // ---- BASE CASE 2: PRUNING (invalid path) ----
        // target negative mane amra last element add kore target ke
        // cross kore fellam (overshoot) — ei path ar kaje lagbe na
        // tai age-i thamiye dao, aro explore korar dorkar nai
        if (target < 0)
        {
            return;
        }

        // start theke shuru — age-e select kora element gulo abar
        // consider korbo na (eta [2,3] and [3,2] duplicate atkay)
        for (int i = start; i < nums.size(); i++)
        {
            // ---- CHOOSE ----
            // nums[i] ke current path e add kortesi
            curr.push_back(nums[i]);

            // ---- EXPLORE ----
            // KEY DIFFERENCE from Subsets: ekhane "i+1" na diye "i" ditesi
            // karon element REPEAT use kora jay (unlimited supply)
            // tai porerbar abar nums[i] consider korar shujog rakhtesi
            // target theke nums[i] bad diye pathacchi — remaining koto baki bolar jonno
            backtrack(i, nums, target - nums[i], curr, ans);

            // ---- UN-CHOOSE (backtrack step) ----
            // ei branch shesh, tai nums[i] ke curr theke remove kore dicchi
            // jate next iteration (i+1, i+2...) e current path clean thake
            curr.pop_back();
        }
        return;
    }
};