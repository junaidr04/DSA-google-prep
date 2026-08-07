// Problem: Permutations
// Platform: NeetCode
// Link: https://neetcode.io/problems/permutations/question
// time complexity: O(N × N!); worst case e shob element select kora jay, tai N! permutations possible. N = number of candidates
// space complexity: O(N); recursion stack e shob element store korte hobe


class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;                  
        vector<int> curr;                         // current path — ekhon porjonto build kora permutation
        vector<bool> visited(nums.size(), false); // track kore kon index already use hoyeche
        backtrack(nums, curr, visited, ans);
        return ans;
    }

    void backtrack(vector<int> &nums, vector<int> &curr, vector<bool> &visited, vector<vector<int>> &ans)
    {
        // ---- BASE CASE ----
        // curr-er size nums-er size-er shoman mane shob element use hoye geche
        // eta ekta COMPLETE permutation — tai ans-e push koro
        if (curr.size() == nums.size())
        {
            ans.push_back(curr);
            return; // ar notun element add korar dorkar nai, ei branch shesh
        }

        // ---- KEY DIFFERENCE from Subsets/CombSum ----
        // loop ekhane 0 theke shuru hocche (start index na), karon
        // ORDER MATTERS — protibar PURO array theke choice korar shujog thakte hobe
        for (int i = 0; i < nums.size(); i++)
        {
            // jodi ei index already curr-e ache (use hoye geche), skip koro
            // (nahole [1,1,1] type invalid permutation toiri hoye jabe)
            if (visited[i])
            {
                continue;
            }

            // ---- CHOOSE ----
            curr.push_back(nums[i]); // nums[i] ke path-e add korlam
            visited[i] = true;       // mark korlam eta ekhon "in use"

            // ---- EXPLORE ----
            backtrack(nums, curr, visited, ans);

            // ---- UN-CHOOSE (backtrack) ----
            curr.pop_back();    // path theke remove korlam
            visited[i] = false; // mark korlam eta abar "available"
                                // (jate onno branch e eta abar use kora jay)
        }
        return;
    }
};