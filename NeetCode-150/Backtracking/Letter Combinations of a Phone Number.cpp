// Problem: Letter Combinations of a Phone Number
// Platform: NeetCode
// Link: https://neetcode.io/problems/letter-combinations-of-a-phone-number
// time complexity: O(N * 4^N); N = length of the string
// space complexity: O(N); recursion stack e shob element store korte hobe (maximum depth = N)


class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans; // final answer — shob combination (string) ekhane
        // edge case: kono digit na thakle, kono combination-i toiri hবে না
        if (digits.empty())
        {
            return ans;
        }
        // phone keypad mapping — digit theke possible letters
        unordered_map<char, string> mapp = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        string curr = ""; // current combination — build hocche step by step
        backtrack(0, digits, mapp, curr, ans);
        return ans;
    }

    void backtrack(int index, string &digits, unordered_map<char, string> &mapp, string &curr, vector<string> &ans)
    {
        // ---- BASE CASE ----
        // curr-er length digits-er length-er shoman mane protyekTA digit-er
        // jonno EKTA kore letter already select hoye geche — complete combination
        if (curr.size() == digits.size())
        {
            ans.push_back(curr);
            return;
        }

        // current digit-ke ki ki letter-e map kore, seta ber koro
        // (jemন digits[index]='2' hole letter = "abc")
        string letter = mapp[digits[index]];
        // ei digit-er shob possible letter try koro
        for (int i = 0; i < letter.size(); i++)
        {
            // ---- CHOOSE ----
            curr.push_back(letter[i]);

            // ---- EXPLORE ----
            // index+1 — mane PORER DIGIT-e jacchi (i+1 na, karon i shudhu
            // current digit-er letters-er modhye loop variable, digit-tracker na)
            backtrack(index + 1, digits, mapp, curr, ans);

            // ---- UN-CHOOSE (backtrack) ----
            curr.pop_back();
        }
        return;
    }
};