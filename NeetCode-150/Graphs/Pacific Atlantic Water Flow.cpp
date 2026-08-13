// Problem: Pacific Atlantic Water Flow
// Platform: NeetCode
// Link: https://neetcode.io/problems/pacific-atlantic-water-flow/question
// time complexity: O(m*n) where m is the number of rows and n is the number of columns in the grid, as we need to visit each cell once in the worst case
// space complexity: O(m*n) for the two boolean matrices to track reachable cells from each ocean


class Solution
{
    // ei DFS "উল্টো দিকে" hাঁটে — ocean theke shুরু kore উঁচুর দিকে যায়
    // (normal e pani উঁচু theke নিচুতে বহে, kিন্তু amরা উল্টো দিক থেকে ভাবছি:
    //  "ocean theke কোথায় কোথায় পৌঁছানো যায়" — তাই condition ta উল্টো)
    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, int i, int j, int prevHeight)
    {
        int r = heights.size(), c = heights[0].size();
        // bounds বাইরে গেলে return
        if (i < 0 || i >= r || j < 0 || j >= c)
            return;
        // already visited hole return (আবার visit korার দরকার নাই)
        if (visited[i][j])
            return;
        // height condition: current cell আগের cell এর থেকে খাটো (কম উচ্চতা) হলে যাওয়া যাবে না
        // (কারণ উল্টো দিকে হাঁটছি, শুধু সমান বা বেশি উচ্চতায় যেতে পারবো)
        if (heights[i][j] < prevHeight)
            return;
        visited[i][j] = true; // ei cell theke ocean e pani পৌঁছাতে পারে, mark kore dilam
        // 4 direction e dfs call koro, current height ta porer call er prevHeight hবে
        dfs(heights, visited, i + 1, j, heights[i][j]);
        dfs(heights, visited, i - 1, j, heights[i][j]);
        dfs(heights, visited, i, j + 1, heights[i][j]);
        dfs(heights, visited, i, j - 1, heights[i][j]);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int r = heights.size(), c = heights[0].size();
        vector<vector<bool>> paci(r, vector<bool>(c, false)); // pacific e কারা কারা পৌঁছাতে পারে
        vector<vector<bool>> atla(r, vector<bool>(c, false)); // atlantic e কারা কারা পৌঁছাতে পারে
        // top row + bottom row theke dfs shুরু (multi-source)
        // INT_MIN diye shuru korছি — jাতে প্রথম cell টা কখনোই "height কম" বলে বাদ না যায়
        for (int j = 0; j < c; j++)
        {
            dfs(heights, paci, 0, j, INT_MIN);     // top row -> pacific
            dfs(heights, atla, r - 1, j, INT_MIN); // bottom row -> atlantic
        }
        // left column + right column theke dfs shুরু
        for (int i = 0; i < r; i++)
        {
            dfs(heights, paci, i, 0, INT_MIN);     // left column -> pacific
            dfs(heights, atla, i, c - 1, INT_MIN); // right column -> atlantic
        }
        // jekhane duটা ocean e-i pani পৌঁছাতে পারে (mane duটা visited grid e-i true),
        // shei cell ta answer e push kori
        vector<vector<int>> ans;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (paci[i][j] && atla[i][j])
                {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};