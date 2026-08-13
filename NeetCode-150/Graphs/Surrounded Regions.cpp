// Problem: Surrounded Regions
// Platform: NeetCode
// Link: https://neetcode.io/problems/surrounded-regions
// time complexity: O(m*n) where m is the number of rows and n is the number of columns in the grid, as we need to visit each cell once in the worst case
// space complexity: O(m*n) in the worst case, as we might need to store all cells in the recursion stack


class Solution
{
    // DFS use kore boundary-r sathe connected
    // shob 'O' cell khuje ber korbo
    void dfs(vector<vector<char>> &board, vector<vector<int>> &visited, int i, int j)
    {
        int r = board.size(), c = board[0].size();
        // Grid-er baire chole gele return
        if (i < 0 || i >= r || j < 0 || j >= c)
            return;
        // Current cell 'O' na hole ekhane DFS korar dorkar nei
        // X hole return
        if (board[i][j] != 'O')
            return;
        // Ei cell agei visit kora hole abar visit korbo na
        if (visited[i][j])
            return;
        // Current 'O' cell-ta boundary theke reachable
        // tai etake safe hisebe mark korlam
        visited[i][j] = true;

        // 4 direction-e DFS chalao
        dfs(board, visited, i + 1, j); // Down
        dfs(board, visited, i - 1, j); // Up
        dfs(board, visited, i, j + 1); // Right
        dfs(board, visited, i, j - 1); // Left
    }

public:
    void solve(vector<vector<char>> &board)
    {
        int r = board.size(), c = board[0].size();
        // visited[i][j] = true.. mane oi 'O' cell-ta boundary theke reachable/safe
        vector<vector<int>> visited(r, vector<int>(c, false));

        // STEP 1: LEFT BOUNDARY
        // Left boundary-er column always 0..Tai board[i][0] check korbo
        for (int i = 0; i < r; i++)
        {
            if (board[i][0] == 'O')
            {
                // Ei boundary O theke DFS start..Er sathe connected shob O safe hobe
                dfs(board, visited, i, 0);
            }
        }

        // STEP 2: RIGHT BOUNDARY
        // Right boundary-er column always c-1..Row change hobe: 0 -> r-1
        for (int j = 0; j < r; j++)
        {
            if (board[j][c - 1] == 'O')
            {
                // Right boundary-r O theke DFS
                dfs(board, visited, j, c - 1);
            }
        }

        // STEP 3: TOP BOUNDARY
        // Top boundary-er row always 0..Column change hobe: 0 -> c-1
        for (int i = 0; i < c; i++)
        {
            if (board[0][i] == 'O')
            {
                // Top boundary-r O theke DFS
                dfs(board, visited, 0, i);
            }
        }

        // STEP 4: BOTTOM BOUNDARY
        // Bottom boundary-er row always r-1..Column change hobe: 0 -> c-1  
        for (int j = 0; j < c; j++)
        {
            if (board[r - 1][j] == 'O')
            {
                // Bottom boundary-r O theke DFS
                dfs(board, visited, r - 1, j);
            }
        }

        // STEP 5: CAPTURE SURROUNDED 'O'
        // Ekhon pura board traverse korbo
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                // Jodi cell 'O' hoy..AND boundary theke reachable na hoy..tahole eta surrounded
                if (board[i][j] == 'O' && visited[i][j] == false)
                {
                    // Surrounded O ke X baniye dao
                    board[i][j] = 'X';
                }
            }
        }
    }
};