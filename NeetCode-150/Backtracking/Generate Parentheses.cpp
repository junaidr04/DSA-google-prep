// Problem: Generate Parentheses
// Platform: NeetCode
// Link: https://neetcode.io/problems/generate-parentheses
// time complexity: O(4^N / sqrt(N)); valid parentheses combination er count e eta asymptotic bound. N = number of pairs of parentheses
// space complexity: O(N); recursion stack e shob element store korte hobe (maximum depth = 2N, but only N '(' and N ')' are added, so effective depth is O(N))


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;         // final answer — shob valid combination
        string curr = "";           // current string — ekhon porjonto build kora parentheses
        // openBra=0, closeBra=0 diye shuru — kono bracket abhi add hoy nai
        backtrack(n, 0, 0, curr, ans);
        return ans;
    }

    void backtrack(int n, int openBra, int closeBra, string& curr, vector<string>& ans)
    {
        // ---- BASE CASE ----
        // total character = n-ta '(' + n-ta ')' = 2*n
        // curr-er length 2n hole mane shob bracket add hoye geche, complete string
        if (curr.size() == 2 * n)
        {
            ans.push_back(curr);
            return;
        }

        // ---- CHOICE 1: '(' add koro ----
        // shudhu tokhon-i add korte parbo jodi ekhono n-ta '(' add kora na hoye thake
        // (openBra < n mane aro '(' add korার shujog ache)
        if (openBra < n)
        {
            curr.push_back('(');                         // choose
            backtrack(n, openBra + 1, closeBra, curr, ans); // explore
            curr.pop_back();                              // un-choose (backtrack)
        }

        // ---- CHOICE 2: ')' add koro ----
        // shudhu tokhon-i add korte parbo jodi closeBra < openBra hoy
        // (mane already kichu '(' open ache jeta close kora baki, 
        //  tai ')' add korle valid matching hobe, e.g. "())" er moto invalid hobe na)
        if (closeBra < openBra)
        {
            curr.push_back(')');                          // choose
            backtrack(n, openBra, closeBra + 1, curr, ans); // explore
            curr.pop_back();                               // un-choose (backtrack)
        }

        return;
    }
};