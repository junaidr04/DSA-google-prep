// Problem: Palindrome Partitioning
// Platform: NeetCode
// Link: https://neetcode.io/problems/palindrome-partitioning
// time complexity: O(N * 2^N); N = length of the string
// space complexity: O(N); recursion stack e shob element store korte hobe (maximum depth = N)

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;     
        vector<string> curr;            
        backtrack(0, s, curr, ans);     // start=0 theke shuru, puro string cover korতে hobe
        return ans;
    }

    void backtrack(int start, string& s, vector<string>& curr, vector<vector<string>>& ans)
    {
        // ---- BASE CASE ----
        // start == s.size() mane puro string already choto choto palindrome
        // substring diye cover hoye geche, kono অংশ বাকি নেই
        // tai curr-e ja ache seta ekটা VALID partitioning — ans-e push koro
        if (start == s.size())
        {
            ans.push_back(curr);
            return;
        }

        // start theke shuru kore, sob shombhabya "end" position try koro
        // (mane different length-er substring try kortesi: s[start..start], 
        //  s[start..start+1], s[start..start+2], etc.)
        for (int end = start; end < s.size(); end++)
        {
            // start theke end porjonto substring ber koro (length = end-start+1)
            string sub = s.substr(start, end - start + 1);

            // ---- PRUNE ----
            // shudhu tokhon-i proceed korবো jodi ei substring PALINDROME hoy
            // na hole ei branch invalid, skip kore porer 'end' try koro
            if (isPalindrome(sub))
            {
                // ---- CHOOSE ----
                curr.push_back(sub);

                // ---- EXPLORE ----
                // end+1 theke porer substring khoja shuru hobe (ei substring 
                // already "consume" kora hoye geche, tai porerbar tার pore theke)
                backtrack(end + 1, s, curr, ans);

                // ---- UN-CHOOSE (backtrack) ----
                curr.pop_back();
            }
        }
    }
    bool isPalindrome(string& sub)
    {
        // two-pointer technique — left theke shuru, right theke shesh
        int l = 0, r = sub.size() - 1;
        while (l < r)
        {
            // jodi kono position-e character match na kore, palindrome na
            if (sub[l] != sub[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;   // shob pair match korle palindrome
    }
};