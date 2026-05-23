// Problem: Valid Sudoku
// Platform: Neetcode
// Link: https://neetcode.io/problems/valid-sudoku/question
// time complexity: O(1)
// space complexity: O(1)


class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // প্রতিটা row, column, 3x3 box এর জন্য আলাদা set
        // duplicate track করবে
        vector<unordered_set<int>> rows(9);
        vector<unordered_set<int>> cols(9);
        vector<unordered_set<int>> boxes(9);
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                // empty cell হলে skip
                if (board[i][j] == '.')
                {
                    continue;
                }
                else
                {
                    // char কে int এ convert করো
                    // '5' - '0' = 5
                    int val = board[i][j] - '0';
                    // 3x3 box এর index বের করো
                    // (0,0)-(2,2) → box 0
                    // (0,3)-(2,5) → box 1 ... ইত্যাদি
                    int boxIndex = (i / 3) * 3 + (j / 3);
                    // এই value কি already এই row/col/box এ আছে?
                    // থাকলে invalid sudoku
                    if (rows[i].count(val) || cols[j].count(val) || boxes[boxIndex].count(val))
                    {
                        return false;
                    }
                    // না থাকলে তিনটা set এ insert করো
                    rows[i].insert(val);
                    cols[j].insert(val);
                    boxes[boxIndex].insert(val);
                }
            }
        }
        // কোনো duplicate পাওয়া যায়নি → valid sudoku
        return true;
    }
};
