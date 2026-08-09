// Problem: N-Queens
// Platform: NeetCode
// Link: https://neetcode.io/problems/n-queens
// time complexity: O(N!); N = number of queens
// space complexity: O(N); recursion stack e shob element store korte hobe (maximum depth = N)


class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;              // final answer — shob valid board configuration
        unordered_set<int> col, dia1, dia2;      // constraint tracker:
                                                 // col = kon column-e queen ache
                                                 // dia1 = kon "\" diagonal-e queen ache (row-col constant)
                                                 // dia2 = kon "/" diagonal-e queen ache (row+col constant)
        vector<string> board(n, string(n, '.')); // n x n board, shuru-te shob '.'
        backtrack(0, n, board, col, dia1, dia2, ans);
        return ans;
    }

    void backtrack(int row, int n, vector<string> &board, unordered_set<int> &col,
                   unordered_set<int> &dia1, unordered_set<int> &dia2, vector<vector<string>> &ans)
    {
        // ---- BASE CASE ----
        // row == n mane shob row-e (0 theke n-1) queen বসানো শেষ
        // ei board-tা ekটা VALID complete solution — ans-e push koro
        if (row == n)
        {
            ans.push_back(board);
            return;
        }

        // current row-e kon column-e queen বসাবো, shob try koro
        for (int c = 0; c < n; c++)
        {
            // ---- PRUNE (validity check) ----
            // 3-তা constraint eksathe check kortesi:
            // 1. col.count(c) → ei column-e age kono queen ache?
            // 2. dia1.count(row-c) → ei "\" diagonal-e age kono queen ache?
            //    (same "\" diagonal-e row-col value shomoy thake, tai eta compare kore)
            // 3. dia2.count(row+c) → ei "/" diagonal-e age kono queen ache?
            //    (same "/" diagonal-e row+col value shomoy thake)
            // je konoটা true hole, ei column-e queen বসানো যাবে না — skip
            if (col.count(c) || dia1.count(row - c) || dia2.count(row + c))
            {
                continue;
            }

            // ---- CHOOSE ----
            board[row][c] = 'Q'; // board-e queen boshaলাম
            col.insert(c);       // 3-তা constraint set update korলাম
            dia1.insert(row - c);
            dia2.insert(row + c);

            // ---- EXPLORE ----
            // row+1 — porবর্তী row-e jaচ্ছি (protyekটা row-e ekটাই queen bosাবো)
            backtrack(row + 1, n, board, col, dia1, dia2, ans);

            // ---- UN-CHOOSE (backtrack) ----
            // board revert korলাম, ar 3-তা set theke exact same value remove korলাম
            // jeta insert korার shomoy দিয়েছিলাম (nahole porবর্তী 'c' try korার shomoy
            // wrong constraint state thakবে)
            board[row][c] = '.';
            col.erase(c);
            dia1.erase(row - c);
            dia2.erase(row + c);
        }
        return;
    }
};