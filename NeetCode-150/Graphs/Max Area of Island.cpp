// Problem: Max Area of Island
// Platform: NeetCode
// Link: https://neetcode.io/problems/max-area-of-island/question
// time complexity: O(m*n) where m is the number of rows and n is the number of columns in the grid, as we need to visit each cell once in the worst case
// space complexity: O(m*n) in the worst case, where m is the number of rows and n is the number of columns in the grid, as the recursive call stack can go as deep as the number of cells in the grid


class Solution {
    // DFS kore connected land er area return kore, ar cell gula visited (0) mark kore dei
    int dfs(vector<vector<int>>& grid, int i, int j)
    {
        int r=grid.size(), c=grid[0].size();
        // base case: bounds er baire gele area contribute korবে না
        if(i < 0 || i >= r || j < 0 || j >= c)
        return 0;
        // base case: water othoba already visited hole area contribute korবে না
        if(grid[i][j] == 0)
        return 0;
        grid[i][j] = 0; // visited mark (water banaia dilam)
        // current cell (1) + 4 direction er area sum kore return
        return (1+dfs(grid, i+1, j)+dfs(grid, i-1, j)+dfs(grid, i, j+1)+dfs(grid, i, j-1));
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r=grid.size(), c=grid[0].size();
        int maxArea=0; // sobcheye boro island er area track korbe
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(grid[i][j] == 1) // unvisited land pele
                {
                    int area=dfs(grid, i, j); // ei island er total area
                    maxArea=max(maxArea, area); // boro hole update
                }
            }
        }
        return maxArea;
    }
};