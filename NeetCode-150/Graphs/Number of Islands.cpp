// Problem: Number of Islands
// Platform: NeetCode
// Link: https://neetcode.io/problems/count-number-of-islands/question
// time complexity: O(m*n) where m is the number of rows and n is the number of columns in the grid, as we need to visit each cell once in the worst case
// space complexity: O(m*n) in the worst case, where m is the number of rows and n is the number of columns in the grid, as the recursive call stack can go as deep as the number of cells in the grid


class Solution {
    // DFS diye connected land ('1') gula visit kore '0' banaia dei (visited mark)
    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        int row=grid.size(), col=grid[0].size();
        // base case 1: bounds er baire gele return (invalid position)
        if(i < 0 || i >= row || j < 0 || j >= col)
        return;
        // base case 2: water hole othoba already visited hole return
        if(grid[i][j] == '0')
        return ;
        grid[i][j] = '0'; // current land ke visited mark kore dilam (water banaia)
        // 4 direction e recursive call — up, down, left, right
        dfs(grid, i-1, j); // up
        dfs(grid, i+1, j); // down
        dfs(grid, i, j-1); // left
        dfs(grid, i, j+1); // right
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int row=grid.size(), col=grid[0].size();
        // protita cell check kori
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                // notun unvisited land pele — notun island shuru
                if(grid[i][j] == '1')
                {
                    count++;         // island count barailam
                    dfs(grid, i, j); // eita island er shob connected land visited mark kore dibe
                }
            }
        }
        return count;
    }
};