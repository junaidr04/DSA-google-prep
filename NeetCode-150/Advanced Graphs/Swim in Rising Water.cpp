// Problem: Swim in Rising Water
// Platform: NeetCode
// Link: https://neetcode.io/problems/swim-in-rising-water
// time complexity: O(n^2 log n) where n is the size of the grid, as we are using a priority queue to explore the grid.Grid e total n² ta cell ache. প্রতিটা cell max 4 বার queue te push hote pare (4 ta neighbor theke asha shomvob).Tai total push/pop operation: worst case O(n²) (constant factor shoho).. Priority queue er push/pop প্রতিটা O(log(queue size)) — queue size max O(n²) hote pare, tai O(log n²) = O(2 log n) = O(log n)
// space complexity: O(n^2); dist 2D array — O(n²) space. Priority queue — worst case shob cell (4 বার kore) thakte pare — O(n²)


class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {

        // grid er size (n x n)
        int n = grid.size();

        // min-heap: {path_er_max_elevation_ekhon_porjonto, row, col}
        // greater<> use kore SHOBCHEYE KOM max-elevation wala cell age process hobe
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

        // dist[r][c] = (0,0) theke (r,c) te pouchate MINIMUM koto "t" (max elevation) lagbe
        // shuru te sob INT_MAX (jani na)
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // starting cell (0,0) er path-max = nijer elevation e (karon path e ei ekta cell e ache)
        dist[0][0] = grid[0][0];

        // starting cell queue te push kori
        pq.push({grid[0][0], 0, 0});

        // direction arrays — 4 dike move korar jonno (up, down, left, right)
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // Dijkstra-style main loop
        while (!pq.empty())
        {
            // queue theke shobcheye kom "path max" wala cell ber kori
            auto [d, row, col] = pq.top();
            pq.pop();

            // STALE CHECK: ei entry ta ki purono/outdated?
            // jodi already 'row,col' er jonno choto max peye gie thaki, ignore kori
            if (d > dist[row][col])
                continue;
            // 4 ta direction e neighbor dekhi
            for (int i = 0; i < 4; i++)
            {
                int nr = row + dr[i];
                int nc = col + dc[i];
                // boundary check — grid er baire gele skip
                if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                    continue;

                // *** KEY DIFFERENCE FROM NORMAL DIJKSTRA ***
                // amra "add" na kore "max" nichi —
                // karon amader dorkar PATH er BOTTLENECK (shobcheye beshi elevation)
                // "add" hole eita hoto normal shortest-path cost, kintu amader
                // dorkar path e "chaltey hole minimum koto 't' lagbe"
                int newMax = max(d, grid[nr][nc]);

                // jodi ei notun path-max, age jana dist theke choto hoy,
                // tahole eita e amader BETTER path
                if (newMax < dist[nr][nc])
                {
                    dist[nr][nc] = newMax;
                    // notun update kora value push kori, aro explore korar jonno
                    pq.push({newMax, nr, nc});
                }
            }
        }
        // destination (n-1, n-1) e pouchate minimum je 't' lage, seta amader answer
        return dist[n - 1][n - 1];
    }
};