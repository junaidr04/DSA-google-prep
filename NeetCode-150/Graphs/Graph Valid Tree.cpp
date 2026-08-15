// Problem: Graph Valid Tree
// Platform: NeetCode
// Link: https://neetcode.io/problems/graph-valid-tree
// time complexity: O(V + E) where V is the number of nodes and E is the number of edges
// space complexity: O(V+ E) for the adjacency list and visited array


class Solution
{
    // dfs function: "ei node theke shuru kore cycle ache kina" check kore
    bool dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited)
    {
        // current node visited mark korlam
        visited[node] = true;
        for (int neigh : adj[node])
        {
            // neighbor age theke visited, ebong parent na -> actual cycle
            if (visited[neigh] && neigh != parent)
            {
                return true;
            }
            // neighbor visited na -> normal DFS, current node ke parent hisebe pass
            if (!visited[neigh])
            {
                if (dfs(neigh, node, adj, visited))
                {
                    return true;
                }
            }
            // neighbor visited ebong == parent -> shudhu jekhan theke eshechi shei
            // edge, eta normal, cycle na, tai kono action lagbe na
        }
        return false;
    }

public:
    bool validTree(int n, vector<vector<int>> &edges)
    {
        // ------ Step 1: Edge count check ------
        // Tree hote hole exactly n-1 edge lagbei, na hole shathe shathei false
        if (n - 1 != (int)edges.size())
            return false;
        // ------ Step 2: Adjacency list build ------
        vector<vector<int>> adj(n);
        for (auto &e : edges)
        {
            int a = e[0], b = e[1];
            adj[a].push_back(b);
            adj[b].push_back(a); // undirected, tai dui dikei push
        }
        // ------ Step 3: DFS diye cycle check ------
        vector<bool> visited(n, false);
        // node 0 theke DFS shuru, parent = -1 (root er kono parent nai)
        if (dfs(0, -1, adj, visited))
        {
            return false; // cycle paওয়া গেছে -> invalid tree
        }
        // ------ Step 4: Connectivity check (EITA MISSING SILO AGE) ------
        // DFS shudhu ekটা component theke shuru hoyeche, tai jodi graph
        // disconnected hoy (mane multiple alada component ache), tahole
        // DFS shudhu ekটা component e ghure ashবে, baki component gulo
        // visited-ই hobe na -- oi component e cycle thakleo dhora porবে না!
        //
        // Tai DFS shesh hওয়ার পরে explicitly check korte hobe -- shob
        // n টা node ki visited = true হয়েছে? Jodi kono ekটা o false thake,
        // mane graph disconnected -> invalid tree.
        for (bool v : visited)
        {
            if (!v)
                return false;
        }
        // cycle o nai, shob node connected o -> valid tree
        return true;
    }
};