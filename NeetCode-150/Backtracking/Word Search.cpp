// Problem: Word Search
// Platform: NeetCode
// Link: https://neetcode.io/problems/word-search
// time complexity: O(M × N × 4^L); M = rows, N = columns, L = length of the word
// space complexity: O(L); recursion stack e shob element store korte hobe (maximum depth = L)

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int row = board.size(), col = board[0].size();
        // puro grid scan koro — word-er FIRST letter je je cell-e match
        // korte pare, shei shob jaygা theke try korte hobe
        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {
                // (r,c) theke shuru kore backtrack try koro, index=0 (word-er shuru)
                if (backtrack(board, word, r, c, 0))
                {
                    return true; // ekbar found hole ar khujar dorkar nai
                }
            }
        }
        return false; // kono starting point theke word paoya gelo na
    }

    bool backtrack(vector<vector<char>> &board, string &word, int r, int c, int index)
    {
        // ---- BASE CASE: SUCCESS ----
        // index word-er total length-er shoman hoye gele mane
        // shob character eksathe already match kore ferse — word FOUND
        if (index == word.size())
        {
            return true;
        }

        // ---- PRUNE CONDITIONS (fail cases) ----
        // 1. row/col grid-er boundary-er baire chole gele (out of bounds)
        // 2. current cell-er character, word-er expected character-er shathe match na korle
        // 3. (implicitly) already-visited cell hole board[r][c] hobe '#',
        //    jeta kono normal letter-er shathe match korবে na, tai automatically
        //    ei condition-e already handle hoye jacche — আলাদা visited check lagse na
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[index])
        {
            return false;
        }

        // ---- CHOOSE (mark as visited) ----
        // original character temp-e save kore rakhলাম (পরে ফিরিয়ে দেওয়ার জন্য)
        char temp = board[r][c];
        board[r][c] = '#'; // '#' kono word-e thakবে না বলে dhore newa hoy,
                           // tai eta ekটা "used" marker hishebe kaj kore

        // ---- EXPLORE (4 direction) ----
        // down, up, right, left — je kono ekটা direction-e match paile true
        // '||' operator SHORT-CIRCUIT kore — prothom true pele baki
        // direction gulo r check korবে না (efficiency)
        bool found = backtrack(board, word, r + 1, c, index + 1) ||
                     backtrack(board, word, r - 1, c, index + 1) ||
                     backtrack(board, word, r, c + 1, index + 1) ||
                     backtrack(board, word, r, c - 1, index + 1);

        // ---- UN-CHOOSE (backtrack) ----
        // original character ফিরিয়ে দিলাম — এটা CRITICAL:
        // ei path fail hole (found=false), onno starting point/direction theke
        // abar try kora hote pare, tokhon grid-a original obosthায় thaka lagবে
        board[r][c] = temp;
        return found;
    }
};