// Problem: Islands and Treasure
// Platform: NeetCode
// Link: https://neetcode.io/problems/islands-and-treasure/question
// time complexity: O(m*n) where m is the number of rows and n is the number of columns in the grid, as we need to visit each cell once in the worst case
// space complexity: O(m*n) in the worst case, as we might need to store all cells in the queue for a BFS traversal


class Solution {
    // BFS চালায় — queue এ shob treasure (0) cell আগে থেকেই আছে
    // layer by layer (ঢেউ এর মতো) distance ছড়িয়ে দেয়
    void bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q)
    {
        int r=grid.size(), c=grid[0].size();
        vector<int>dr={-1,1,0,0};   // up, down
        vector<int>dc={0,0,-1,1};   // left, right
        while(!q.empty())
        {
            auto[row,col]=q.front();
            q.pop();
            // 4 direction check kori
            for(int i=0; i<4; i++)
            {
                int nr=row+dr[i];
                int nc=col+dc[i];
                // bounds er বাইরে গেলে skip
                if(nr < 0 || nr >= r || nc < 0 || nc >= c)
                continue; 
                // shudhু tokhoni update korবো jokhon eiটা ekhono INF (unvisited empty land)
                // -1 (water) hলে eiটা INT_MAX na, tাi automatically skip hবে
                // already visited (choto distance দিয়ে update হয়ে গেলে) hলেও automatically skip
                if(grid[nr][nc] != -1 && grid[nr][nc] == INT_MAX)
                {
                    grid[nr][nc] = grid[row][col] + 1;   // current থেকে ১ step দূরে
                    q.push({nr, nc});   // পরে এর neighbor ও process korte হবে
                }
            }
        }
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>>q;
        int r=grid.size(), c=grid[0].size();
        // step 1: shob treasure (0) cell খুঁজে queue e push kori
        // eiটাই "multi-source" — ekটা na, shob source একসাথে shuru
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(grid[i][j] == 0)
                {
                    q.push({i,j});
                }
            }
        }
        // step 2: BFS চালাই — grid নিজেই update হয়ে যাবে (in-place)
        bfs(grid,q);
    }
};


/*  
Example Grid:
Column:     0     1     2
Row 0:    INF   -1     0
Row 1:    INF   INF   INF
Row 2:     0    -1    INF

INF = 2147483647 (empty land), -1 = water, 0 = treasure

Step 1: Treasure khুঁজে queue e push
Grid loop kore dekhi kothায় 0 আছে:
(0,2) = 0 → push
(2,0) = 0 → push
Queue: [(0,2), (2,0)]
Eiটাই multi-source — dুiটা treasure একসাথে queue এ, দুজনের থেকেই "ঢেউ" ছড়াবে।

Step 2: BFS while loop shuru
Iteration 1: (0,2) pop হলো
Queue: [(2,0)]   (pop হয়ে গেছে, এখন খালি হয়ে গেছে এই entry)
(0,2) এর 4 neighbor check kori:
up (-1,2) → bounds baire → skip
down (1,2) → grid value INF → update! grid[1][2] = grid[0][2]+1 = 0+1 = 1, push
left (0,1) → grid value -1 (water) → INT_MAX er sাথে match hবে না → automatically skip
right (0,3) → bounds baire → skip
Queue: [(2,0), (1,2)]
Grid এখন:
INF   -1    0
INF   INF   1
 0    -1   INF
Iteration 2: (2,0) pop হলো
Queue: [(1,2)]

(2,0) এর 4 neighbor check kori:

up (1,0) → grid value INF → update! grid[1][0] = grid[2][0]+1 = 0+1 = 1, push
down (3,0) → bounds baire → skip
left (2,-1) → bounds baire → skip
right (2,1) → grid value -1 (water) → skip
Queue: [(1,2), (1,0)]
Grid এখন:
INF   -1    0
 1    INF   1
 0    -1   INF
Iteration 3: (1,2) pop হলো
Queue: [(1,0)]

(1,2) এর 4 neighbor check kori:

up (0,2) → grid value 0 → INT_MAX na → skip (এটা treasure, already 0)
down (2,2) → grid value INF → update! grid[2][2] = grid[1][2]+1 = 1+1 = 2, push
left (1,1) → grid value INF → update! grid[1][1] = grid[1][2]+1 = 1+1 = 2, push
right (1,3) → bounds baire → skip
Queue: [(1,0), (2,2), (1,1)]
Grid এখন:
INF   -1    0
 1     2    1
 0    -1    2
Iteration 4: (1,0) pop হলো

(1,0) এর 4 neighbor:

up (0,0) → grid value INF → update! grid[0][0] = grid[1][0]+1 = 1+1 = 2, push
down (2,0) → grid value 0 → skip (treasure)
left bounds baire → skip
right (1,1) → grid value ekhon 2 (আগেই update হয়ে গেছে iteration 3 তে) → INT_MAX na → skip
Queue: [(2,2), (1,1), (0,0)]
Grid এখন:
 2    -1    0
 1     2    1
 0    -1    2
Baki iterations ((2,2), (1,1), (0,0)) — এদের neighbor গুলা সব হয় already updated, নয়তো water/bounds baire — tাi kono notun update hবে না, queue empty hবে।
Final Grid:
2    -1    0
1     2    1
0    -1    2
Lokkho koro — এই জিনিসটা most important:
(1,1) cell এর মান 2 হলো, কারণ eiটা dুই treasure থেকেই সমান দূরত্বে ((0,2) theke ও 2 step, (2,0) theke ও 2 step)। BFS layer-by-layer explore korার কারণে, jেই treasure আগে পৌঁছায় (mane kаছের treasure), তার distance দিয়েই update হয় — ar dুiটা treasure একসাথে queue e থাকার কারণে automatically সবচেয়ে ছোট distance পাওয়া যায়, alada kore compare korতে হয় না!
Eiটাই BFS er beauty — layer by layer explore করার কারণে shortest distance guaranteed pাওয়া যায়, DFS দিয়ে করলে eiটা এত সহজ হতো না (সব path check kore তারপর minimum বের করতে হতো)।
*/