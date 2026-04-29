// Problem: Number of Islands
// Platform: LeetCode
// Link: https://leetcode.com/problems/number-of-islands/description/
// time complexity: O(m*n) where m is the number of rows and n is the number of columns in the grid, as we need to visit each cell once in the worst case
// space complexity: O(m*n) in the worst case when the grid is filled with land, as we need to store the visited cells in a queue for BFS

class Solution
{
public:
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '0';
        while (!q.empty())
        {
            auto [row, col] = q.front();
            q.pop();
            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};
            for (int d = 0; d < 4; d++)
            {
                int nr = row + dr[d];
                int nc = col + dc[d];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1')
                {
                    grid[nr][nc] = '0';
                    q.push({nr, nc});
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};

// TC = O(m*n) where m is the number of rows and n is the number of columns in the grid, as we need to visit each cell once in the worst case
//  SC = O(m*n) in the worst case when the grid is filled with land, as we need to store the visited cells in a queue for BFS

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;         // new island found
                    dfs(grid, i, j); // mark all connected land
                }
            }
        }
        return count;
    }
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();
        // base case (out of bound or water)
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0')
            return;
        grid[i][j] = '0';    // visited mark
        dfs(grid, i + 1, j); // down
        dfs(grid, i - 1, j); // up
        dfs(grid, i, j + 1); // right
        dfs(grid, i, j - 1); // left
    }
};