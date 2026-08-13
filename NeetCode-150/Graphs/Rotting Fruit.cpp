// Problem: Rotting Fruit
// Platform: NeetCode
// Link: https://neetcode.io/problems/rotting-fruits/question
// time complexity: O(m*n) where m is the number of rows and n is the number of columns in the grid, as we need to visit each cell once in the worst case
// space complexity: O(m*n) in the worst case, where all cells are rotten at the same time and added to the queue


class Solution
{
    void bfs(vector<vector<int>> &grid, queue<pair<int, int>> &q, int &count, int &minute)
    {
        int r = grid.size(), c = grid[0].size();
        vector<int> dr = {-1, 1, 0, 0};
        vector<int> dc = {0, 0, -1, 1};
        while (!q.empty())
        {
            int s = q.size(); // ei মুহূর্তে queue তে koyta orange ache (এই "layer" এ koyta rotten orange process korতে হবে)
            for (int k = 0; k < s; k++) // shুধু ei layer এর orange গুলাই process korbo
            {
                auto [row, col] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) // 4 direction check kori
                {
                    int nr = row + dr[d], nc = col + dc[d];
                    if (nr < 0 || nr >= r || nc < 0 || nc >= c)
                        continue;
                    if (grid[nr][nc] == 1) // fresh orange pele
                    {
                        grid[nr][nc] = 2; // rotten kore dilam
                        q.push({nr, nc}); // eiটাও porer layer e neighbor rotten korবে
                        count--;          // ekটা fresh kমে গেলো
                    }
                }
            }
            minute++; // ei layer shesh — ekটা "minute" pass hoye গেলো (কেন এইটা সঠিক, নিচে বিস্তারিত)
        }
    }

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        int count = 0;
        int minute = -1; // minute=-1 deowa হয়েছে কারণ প্রথম BFS level-এর oranges আগে থেকেই rotten, তাই প্রথম level-টাকে actual 1 minute হিসেবে count করতে চাই না। আর তোমার code-এর শেষে একটা extra processing level হয়, যেখানে নতুন orange আর rotten হয় না। সেই কারণে -1 দিয়ে শুরু করে সেই extra level-টাও compensate করা হচ্ছে।
        int r = grid.size(), c = grid[0].size();
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j}); // shob rotten orange queue e push (multi-source BFS)
                }
                else if (grid[i][j] == 1)
                {
                    count++; // koyta fresh orange ache, gunlam
                }
            }
        }
        // kono fresh orange na thakle, rotten korar dorkar e nai
        if (count == 0)
            return 0;
        bfs(grid, q, count, minute);
        if (count != 0)
            return -1; // kichu fresh orange kokhono rotten hote pare nai (unreachable)
        return minute;
    }
};